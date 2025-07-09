#include <chrono>
#include <random>

#include "services/PaymentService.hpp"


bool PaymentService::processPayment(int userId, double amount) {
        // Simulate randomness using time-based seed
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 genraator(seed);
        std::uniform_int_distribution<int> distribution(0, 1);

        int outcome = distribution(genraator);

        return outcome == 1;
}