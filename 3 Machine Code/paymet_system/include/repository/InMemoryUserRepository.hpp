#include "UserRepository.hpp"

class InMemoryUserRepository : public UserRepository {
    std::unordered_map<int, std::shared_ptr<User>> users;
public:
    void save(const std::shared_ptr<User> &user) override {
        users[user->getId()] = user;
    }

    std::shared_ptr<User> getById(int id) {
        
        auto userIt = users.find(id);
        
        if(userIt != users.end()) {
            return userIt->second;
        }

        return  nullptr;
    }

    std::vector<std::shared_ptr<User>> getAll() {
        std::vector<std::shared_ptr<User>> allUsers;

        for(auto user : users) {
            allUsers.push_back(user.second);
        }
        return allUsers;
    }
};