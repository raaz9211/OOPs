#include "include/UserManager/UserService.hpp"  // Adjust path if needed

#include <iostream>
#include <memory>

int main() {
    // Create the service (uses shared_ptr internally)
    UserService userService;

    // Test 1: Create a user
    auto user = userService.createUser("John Doe", "john@example.com", "1234567890");
    if (user) {
        std::cout << "User created: ID = " << user->getUserId() 
                  << ", Name = " << user->getName() 
                  << ", Email = " << user->getEmail() << std::endl;
    } else {
        std::cout << "Failed to create user" << std::endl;
        return 1;
    }

    // Test 2: Add to group
    if (userService.addUserToGroup(user->getUserId(), "Group1")) {
        std::cout << "Added to Group1. Groups: ";
        for (const auto& group : user->getGroupIds()) {
            std::cout << group << " ";
        }
        std::cout << std::endl;
    }

    // Test 3: Update user
    user->setName("John Updated");
    if (userService.updateUser(user)) {
        std::cout << "User updated: New Name = " << user->getName() << std::endl;
    }

    // Test 4: Get and display all users
    std::cout << "All users:" << std::endl;
    userService.displayAllUsers();

    // Test 5: Delete user
    if (userService.deleteUser(user->getUserId())) {
        std::cout << "User deleted successfully" << std::endl;
    }

    // Test 6: Check if deleted
    if (!userService.userExists(user->getUserId())) {
        std::cout << "User no longer exists" << std::endl;
    }

    return 0;
}
