#pragma once

#include "Group.hpp"

#include <memory>
#include <vector>
#include <string>

class GroupRepository {
public:
    virtual ~GroupRepository() = default;
    virtual bool addGroup(const std::shared_ptr<Group>& group) = 0;
    virtual std::shared_ptr<Group> getGroupById(const std::string& groupId) const = 0;
    virtual std::vector<std::shared_ptr<Group>> getAllGroups() const = 0;
};