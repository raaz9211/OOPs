#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

class Dish {
public:
    int id;
    string name;
    int price;
};

enum class Status {
    PENDDING,
    DONE
};

class Location {
public:
    double leti;
    double longi;
};

class Order {
public:
    int id;
    int userId;
    int resturantId;
    unordered_map<int, shared_ptr<Dish>> dish;
    Status status;
    Location location;
};

class OrderRepo {
public:
    unordered_map<int, shared_ptr<Order>> orders;

    bool addOrder(shared_ptr<Order> order) {
        orders[order->id] = order; 
    }


shared_ptr<Order> getOrder(int orderId) {
        auto it  = orders.find(orderId);

        if(it != orders.end()) {
            return it->second;
        }
        return nullptr;
    }
};

// --------------------------------------------------------

class Resturant {
public:
    int id;
    unordered_map<string,shared_ptr<Dish>> menu;

    void prepareOrder(int orderID, unordered_map<int, shared_ptr<Dish>> &dishs) {
        cout << "Preparing of : \n";
        for(auto dish : dishs) {
            cout << dish.first << " " << dish.second->name << endl;
        }
        cout << "Done for order id : " << orderID;
    }
}; 


class ResturantRepo {
private:
    static ResturantRepo instance;
    unordered_map<int, shared_ptr<Resturant>> resturants;
    ResturantRepo() {}
    // ResturantRepo(const ResturantRepo&) = delete ;
    ResturantRepo& operator=(const ResturantRepo&) = delete;

public:
    static ResturantRepo &getInstance() {
        return instance;
    }


    bool addResturant(shared_ptr<Resturant> resturant) {
        resturants[resturant->id] = resturant; 
    }

    shared_ptr<Resturant> getResturant(int resturantId) {
        auto it  = resturants.find(resturantId);

        if(it != resturants.end()) {
            return it->second;
        }
        return nullptr;
    }
};


ResturantRepo ResturantRepo::instance;


class FoodManager {
public:
    shared_ptr<ResturantRepo> resturantRepo;

    FoodManager(shared_ptr<ResturantRepo> resturantRepo) : resturantRepo(resturantRepo) {}

    void prepareFood(int orderId, int resturantId, unordered_map<int, shared_ptr<Dish>> &dishs) {
        auto resturantRepo = ResturantRepo::getInstance();
        auto res = resturantRepo.getResturant(resturantId);
        res->prepareOrder(orderId, dishs);
    }
};


// ----------------------------------------------------------------------------------------------------------------


class Patner {
public:
    int id;
    int name;
    int rating;
    Location location;
};



class IDevelaryPatnerFind {
public:
    virtual void findPartner() = 0;
    virtual ~IDevelaryPatnerFind() = default;

};


class NearestLocationFind : public IDevelaryPatnerFind {
    void findPartner(){
        
    }
}


class DevelaryPatner : public Patner {

public:
    void performDevelary() {

    }
};


