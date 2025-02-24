#ifndef DATABASE_h
#define DATABASE_h

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

#include "../entity/user.h"
#include "../entity/vehicle.h"


// class UserHash {
// public:
    
//     // hash values.
//     size_t operator()(const User& user) const
//     {
//         return (std::hash<std::string>()(user.getUsername())) << 1 ;
//     }
// };

class Database {
private:

    Database() { std::cout << "Database  Created.."; }
public:
    std::unordered_map<std::string, std::pair<User*,std::vector<Vehicle*>>> table;
    Database(const Database&) = delete;
    Database &operator= (const Database&) = delete;

    static Database &getDatabase();
    void printTable();

};

#endif // DATABASE_h
