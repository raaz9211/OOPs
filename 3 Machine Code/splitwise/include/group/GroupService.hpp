#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Group.hpp"
#include "GroupRepository.hpp"
#include "../user/UserRepository.hpp"


class GroupService {
private:
    std::shared_ptr<GroupRepository> groupRepo;
    std::shared_ptr<UserRepository> userRepo;

public:
    GroupService(std::shared_ptr<GroupRepository> groupRepo,
                 std::shared_ptr<UserRepository> userRepo);

    std::shared_ptr<Group> createGroup(const std::string &groupId, const std::string &name);
    bool addMember(const std::string& groupId, const std::string& userId);
    bool removeMember(const std::string& groupId, const std::string& userId);
    std::shared_ptr<Group> getGroupById(const std::string& groupId);
    std::vector<std::shared_ptr<Group>> getAllGroup() const;
};