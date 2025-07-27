#pragma once

#include "GroupRepository.hpp"

#include <unordered_map>

class InMemoryGroupRepository : public GroupRepository {

private:
    std::unordered_map<std::string, std::shared_ptr<Group>> groups;

public:
    bool addGroup(const std::shared_ptr<Group>& group) override {
        if(!group || groups.count(group->getId()) > 0){
            return false;
        }
        groups[group->getId()] = group;
        return true;
    }

    std::shared_ptr<Group> getGroupById(const std::string& groupId) const override {
        auto it = groups.find(groupId);

        if(it != groups.end()) {
            return it->second;
        }
        return nullptr;
    }

    std::vector<std::shared_ptr<Group>> getAllGroups() const override {
        std::vector<std::shared_ptr<Group>> result;
        for (const auto& pair : groups){
             result.push_back(pair.second);
        }
        return result;
    }


};