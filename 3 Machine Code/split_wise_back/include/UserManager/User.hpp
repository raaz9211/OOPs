#pragma once

#include <string>
#include <vector>

class User {
private:
    std::string userId;
    std::string name;
    std::string email;
    std::string phoneNumber;
    std::vector<std::string> groupIds;

public:
    User(const std::string &id, const std::string &name, const std::string &email, const std::string &phone = "");
        // Copy constructor and assignment operator
    User(const User& other) = default;
    User& operator=(const User& other) = default;

    // Destructor
    ~User() = default;

    // Getters (const correctness)
    const std::string& getUserId() const;
    const std::string& getName() const;
    const std::string& getEmail() const;
    const std::string& getPhoneNumber() const;
    const std::vector<std::string>& getGroupIds() const;


    // Setters
    void setName(const std::string& newName);
    void setEmail(const std::string& newEmail);
    void setPhoneNumber(const std::string& newPhone);

    // Group management operations
    void addGroup(const std::string& groupId);
    bool removeGroup(const std::string& groupId);
    bool isInGroup(const std::string& groupId) const;
    size_t getGroupCount() const;

    // Validation and utility methods
    bool isValid() const;
    void displayUserInfo() const;


    // Equality operators
    bool operator==(const User& other) const;
    bool operator!=(const User& other) const;

};