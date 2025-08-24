#include <chrono>
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>

class RecurrenceStrategy {
public:
    virtual std::chrono::system_clock::time_point getNextTrigger(std::chrono::system_clock::time_point alramTime) = 0;
    virtual ~RecurrenceStrategy() = default;

};


class  DailyRecurrenceStrategy :public RecurrenceStrategy {
public:
     std::chrono::system_clock::time_point getNextTrigger(std::chrono::system_clock::time_point alramTime) override {
        return std::chrono::hours(24) + alramTime;
     }

};



class  MonthlyRecurrenceStrategy :public RecurrenceStrategy {
public:
     std::chrono::system_clock::time_point getNextTrigger(std::chrono::system_clock::time_point alramTime) override {
        return std::chrono::hours(24 * 30) + alramTime;
     }

};



class Alram {
public:
    int id;
    std::shared_ptr<RecurrenceStrategy> recurrence;
    std::chrono::system_clock::time_point alramTime;
    std::string title;

    Alram(int id,
    std::shared_ptr<RecurrenceStrategy> recurrence,
    std::chrono::system_clock::time_point alramTime,
    std::string title) : id(id), recurrence(std::move(recurrence)), alramTime(alramTime), title(title) {}

    void resetTime() {
        if(recurrence) {
            alramTime = recurrence->getNextTrigger(alramTime);
        }
    }

};


class IObserver {
public:
    virtual void update(std::string name, std::chrono::system_clock::time_point alramTime) = 0;

    virtual ~IObserver() {}
};


class SMS : public IObserver {
public:
    void update(std::string name, std::chrono::system_clock::time_point alramTime) {
        std:: cout << "[SMS] " << name << " " << alramTime.time_since_epoch().count() << std::endl;
    }

};


class Ring: public IObserver {
public:
void update(std::string name, std::chrono::system_clock::time_point alramTime) {
        std:: cout << "[Ring] " << name << " " << alramTime.time_since_epoch().count() << std::endl;
    }

};

class IObservable {
public:
    virtual void addObserver(const std::shared_ptr<IObserver> &observer) = 0;
    virtual void removeObserver(const std::shared_ptr<IObserver> &observer) = 0;
    virtual void notifyObserver() = 0;
};

class AlramObsrvable : public IObservable {
public:
    std::vector<std::shared_ptr<IObserver>> observers;
    std::shared_ptr<Alram> alram;
    void addObserver(const std::shared_ptr<IObserver> &observer) {
        observers.push_back(observer);
    }

    void removeObserver(const std::shared_ptr<IObserver> &observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObserver() {
        for(auto obs : observers) {
            obs->update(alram->title, alram->alramTime);
        }
    }

    void setObserver(std::shared_ptr<Alram> alram) {
        this->alram = alram;
        notifyObserver();
    }


};


class AlramFactory {


public:
    static AlramFactory &getInstance() {
        static AlramFactory instanct;
        return instanct;
    }

    static std::shared_ptr<Alram> getAlram(std::string type,     
    int id,
    std::chrono::system_clock::time_point alramTime,
    std::string title) {
        if(type == "DAILY") {
            return std::make_shared<Alram>(id, std::make_shared<DailyRecurrenceStrategy>(), alramTime, title);
        } else {
            return std::make_shared<Alram>(id, std::make_shared<MonthlyRecurrenceStrategy>(), alramTime, title);
        }
    }
};




class AlramSheduler {
public:
    std::vector<std::shared_ptr<Alram>> alrams;
    std::shared_ptr<AlramObsrvable> alramObservable;

    std::chrono::system_clock::time_point _now;
    static AlramSheduler &getInstance() {
        static AlramSheduler instanct;
        return instanct;
    }

    void setAlramObsrvable(std::shared_ptr<AlramObsrvable> alramObservable) {
        this->alramObservable = alramObservable;
    }

    void addAlerm(std::shared_ptr<Alram> alram) {
        alrams.push_back(alram);
    }

    void setTempTime(std::chrono::system_clock::time_point now) {
        _now = now;
    }

    void checkAlarm(){
        for(auto alram : alrams) {
            if(alram->alramTime == _now) {
                std::cout << "⏰ Alarm Triggered: " << alram->title << "\n";
                alramObservable->setObserver(alram);
                alram->resetTime();

            }
        }
    }
};



int main() {
    AlramFactory alramFactory = AlramFactory::getInstance();

    auto now = std::chrono::system_clock::now();
    auto DAlram = alramFactory.getAlram("DAILY", 1, now, "D RAJ");
    auto MAlram = alramFactory.getAlram("M", 2, now, "M RAJ");

    auto alramObsrvable = std::make_shared<AlramObsrvable>();

    auto smsOb = std::make_shared<Ring>();
    auto ringOb = std::make_shared<SMS>();
    alramObsrvable->addObserver(smsOb);
    alramObsrvable->addObserver(ringOb);

    AlramSheduler alramSheduler = AlramSheduler::getInstance();
    alramSheduler.addAlerm(DAlram);
    alramSheduler.addAlerm(MAlram);
    alramSheduler.setTempTime(now);

    alramSheduler.setAlramObsrvable(alramObsrvable);

    alramSheduler.checkAlarm();
    // alramSheduler

    




}
