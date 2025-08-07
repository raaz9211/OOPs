#pragma once

#include <string>
#include <unordered_set>
#include <vector>
#include <memory>

#include "../user/User.hpp"
#include "../expense/Expense.hpp"

class Group {
private:
    std::string id;
    std::string name;
    std::unordered_set<std::shared_ptr<User>> members;
    std::vector<std::shared_ptr<Expense>> expenses;


public:
    Group(const std::string &_id, const std::string &_name)
    : id(_id), name(_name) {
        if (id.empty()) throw std::invalid_argument("Group ID required");
    } 


    const std::string& getId() const { return id; }
    const std::string& getName() const { return name; }

    void addMember(const std::shared_ptr<User>& user) {
        members.insert(user);
    }

    void removeMember(const std::shared_ptr<User>& user) {
        members.erase(user);
    }

    std::vector<std::shared_ptr<User>> getAllMembers() const {
        return std::vector<std::shared_ptr<User>>(members.begin(), members.end());
    }

    void addExpense(const std::shared_ptr<Expense>& expense) {
        expenses.push_back(expense);
    }
    const std::vector<std::shared_ptr<Expense>>& getExpenses() const {
        return expenses;
    }
};