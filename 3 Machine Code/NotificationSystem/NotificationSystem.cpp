#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;


class INotification {
public:
    virtual string getContent() const = 0;
    virtual ~INotification() {}
};

class SimpleNotification : public INotification {
    string text;
public:
    SimpleNotification(const string &msg) {
        text = msg;
    }
    string getContent() const override {
        return text;
    }
};


class INotificationDecorator : public INotification {
protected:
    std::shared_ptr<INotification> notification;
public:
    INotificationDecorator(const std::shared_ptr<INotification> &notification)
    : notification(notification) {}

};


class TimestampDecorator : public INotificationDecorator {
public:
    TimestampDecorator(const std::shared_ptr<INotification> &notification)
    : INotificationDecorator(notification) {}

    string getContent() const override {
        return "[time]" + notification->getContent();
    }
};


class SignatureDecorator : public INotificationDecorator {
    std::string signature;
public:
    SignatureDecorator(const std::shared_ptr<INotification> &notification, const std::string &sig)
    : INotificationDecorator(notification), signature(sig) {}

    string getContent() const override {
        return notification->getContent() + "\n" + signature + '\n';
    }
};

// --------------------------------------------------------------------------------------
class IObserver {
public:
    virtual void update() = 0;

    virtual ~IObserver() {}
};

class IObservable {
public:
    virtual void addObserver(const std::shared_ptr<IObserver> &observer) = 0;
    virtual void removeObserver(const std::shared_ptr<IObserver> &observer) = 0;
    virtual void notifyObserver() = 0;
};

class NotificationObservable : public IObservable {
private:
    std::vector<std::shared_ptr<IObserver>> observers;
    std::shared_ptr<INotification> currentNotofication;
public:
    NotificationObservable() : currentNotofication(nullptr) {}

    void addObserver(const std::shared_ptr<IObserver> &observer) {
        observers.push_back(observer);
    }

    void removeObserver(const std::shared_ptr<IObserver> &observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObserver() {
        for(int i = 0; i < observers.size(); i++) {
            observers[i]->update();
        }
    }

    std::shared_ptr<INotification> getNotification() {
        return currentNotofication;
    }

    string getNotificationContent() {
        return currentNotofication->getContent();
    }

    void setNotification(const std::shared_ptr<INotification> &notification) {
        currentNotofication = notification;
        notifyObserver();
    }
};

// --------------------------------------------------------------


class Logger : public IObserver {
private:
    std::shared_ptr<NotificationObservable> notificationObservable;
public:
    Logger(const std::shared_ptr<NotificationObservable>  notificationObservable)
    : notificationObservable(notificationObservable) {}


    void update() {
        std::cout << "Logging new Notification \n " << notificationObservable->getNotificationContent();
    }
};

// --------------------------------------------------------------

class INotificationStrategy {
public:
    virtual void sendNotification(const string content) = 0;
};

class EmailStrategy : public INotificationStrategy {
private:
    std::string emailId;
public:
    EmailStrategy(const string emailId) : emailId(emailId) {}

    void sendNotification(string content) override {
        std::cout << "Sending email notification to : " << emailId << "\n" << content;
    }
};


class SMSStrategy : public INotificationStrategy {
private:
    std::string mobileNumber;
public:
    SMSStrategy(const string mobileNumber) : mobileNumber(mobileNumber) {}

    void sendNotification(const string content) override {
        std::cout << "Sending mobile notification to : " << mobileNumber << "\n" << content;
    }
};



class PopUpStrategy : public INotificationStrategy {
public:
    PopUpStrategy() {}

    void sendNotification(const string content) override {
        std::cout << "Sending emial notification : " << "\n" << content;
    }
};

// --------------------------------------------------------------


class NotificationEngine : public IObserver {
private:
    std::shared_ptr<NotificationObservable> notificationObservable;
    std::vector<std::shared_ptr<INotificationStrategy>> notificationStrategys;
public:
    NotificationEngine(const std::shared_ptr<NotificationObservable> &notificationObservable)
    : notificationObservable(notificationObservable) {}

    void addNotificationStrategy(const std::shared_ptr<INotificationStrategy> &notificationStrategy) {
        notificationStrategys.push_back(notificationStrategy);
    }

    void update() {
        string notificationContent = notificationObservable->getNotificationContent();

        for(const auto notificationStrategy : notificationStrategys) {
            notificationStrategy->sendNotification(notificationContent);
        }
    }

};

// --------------------------------------------------------------

class NotificationService {
private:
    std::shared_ptr<NotificationObservable> notificationObservable;
    std::vector<std::shared_ptr<INotification>> notifications;

    NotificationService(): notificationObservable(std::make_shared<NotificationObservable>()) {}

public:
    static NotificationService getInstanct() {
        static NotificationService instance;
        return instance;
    }


    void sendNotification(const std::shared_ptr<INotification> &notification) {
        notifications.push_back(notification);
        notificationObservable->setNotification(notification);
    }

    shared_ptr<NotificationObservable> getNotificationObservable() {
        return notificationObservable;
    }


};

// --------------------------------------------------------------

int main() {
    NotificationService notificationService = NotificationService::getInstanct();

    std::shared_ptr<NotificationObservable> notificationObservable = notificationService.getNotificationObservable();


    std::shared_ptr<Logger> logger = std::make_shared<Logger>(notificationObservable);

    std::shared_ptr<NotificationEngine> notificationEngine = std::make_shared<NotificationEngine>(notificationObservable);

    notificationEngine->addNotificationStrategy(std::make_shared<EmailStrategy>("raj@gamil.com"));
    notificationEngine->addNotificationStrategy(std::make_shared<SMSStrategy>("9934536742"));
    notificationEngine->addNotificationStrategy(std::make_shared<PopUpStrategy>());

    notificationObservable->addObserver(logger);
    notificationObservable->addObserver(notificationEngine);

    std::shared_ptr<INotification> notifiaction = std::make_shared<SimpleNotification>("Hi Noti");
    notifiaction = std::make_shared<TimestampDecorator>(notifiaction);
    notifiaction = std::make_shared<SignatureDecorator>(notifiaction, "Raj");


    notificationService.sendNotification(notifiaction);
}