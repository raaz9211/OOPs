#include "group/GroupService.hpp"


GroupService::GroupService(std::shared_ptr<GroupRepository> groupRepo,
                 std::shared_ptr<UserRepository> userRepo)
                 : groupRepo(groupRepo), userRepo(userRepo) {}

std::shared_ptr<Group> GroupService::createGroup(const std::string &groupId, const std::string &name) {
    auto group = std::make_shared<Group>(groupId, name);
    groupRepo->addGroup(group);
    return group;
}

bool GroupService::addMember(const std::string& groupId, const std::string& userId) {
    auto group = groupRepo->getGroupById(groupId);

    auto user = userRepo->getUserById(userId);

    if(!group || !user) {
        return false;
    }

    group->addMember(user);
    return true;
}

bool GroupService::removeMember(const std::string& groupId, const std::string& userId) {
    auto group = groupRepo->getGroupById(groupId);
    auto user = userRepo->getUserById(userId);

    if(!group || !user) {
        return false;
    }
    group->removeMember(user);
    return true;
}

std::shared_ptr<Group> GroupService::getGroupById(const std::string& groupId) {
    return groupRepo->getGroupById(groupId);
}

std::vector<std::shared_ptr<Group>> GroupService::getAllGroup() const {
    return groupRepo->getAllGroups();
}