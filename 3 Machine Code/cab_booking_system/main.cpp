#include <iostream>

#include "models/Location.hpp"
#include "services/CabBookingManager.hpp"

int main() {
 

    // Step 2: Get CabBookingManager Singleton
    auto bookingManager = CabBookingManager::getInstance();
    bookingManager->initialize();

    // Step 3: Create Ride
    Location drop(15.0, 25.0);

    try {
        auto ride = bookingManager->createRide("r1", drop);
        std::cout << "✅ Ride created:\n";
        std::cout << "   Rider: " << ride->getRider()->getName() << "\n";
        std::cout << "   Driver: " << ride->getDriver()->getName() << "\n";

        // Step 4: Start Ride
        bookingManager->startRide("r1");
        std::cout << "🚕 Ride started...\n";

        // Step 5: End Ride
        bookingManager->endRide("r1");
        std::cout << "🏁 Ride completed! Fare: ₹" << ride->getFare() << "\n";

        bookingManager->rateDriver("r1", ride->getDriver()->getId(), 5.0);
        bookingManager->rateRider(ride->getDriver()->getId(), "r1", 4.5);

        std::cout << "\n✅ Rider Rating : "
        << bookingManager->getRating("r1");

        std::cout << "\n✅ Driver Rating : " 
        << bookingManager->getRating(ride->getDriver()->getId());

    } catch (const std::exception& ex) {
        std::cerr << "❌ Error: " << ex.what() << "\n";
    }

// ---------------------------------------------------------------------------------------

    std::cout << std::endl << "Test" << std::endl;

    std::cout << "\n✅ Case 1: Simple Ride Flow\n";
    try {
        auto ride1 = bookingManager->createRide("r1", Location(15, 15));
        bookingManager->startRide("r1");
        bookingManager->endRide("r1");
    } catch (const std::exception &ex) {
        std::cout << "❌ Error: " << ex.what() << "\n";
    }

    std::cout << "\n✅ Case 2: Another Ride After Driver Becomes Available\n";
    try {
        auto ride2 = bookingManager->createRide("r2", Location(18, 18));
        bookingManager->startRide("r2");
        bookingManager->endRide("r2");
    } catch (const std::exception &ex) {
        std::cout << "❌ Error: " << ex.what() << "\n";
    }

    std::cout << "\n✅ Case 3: Cancel Ride\n";
    try {
        auto ride3 = bookingManager->createRide("r3", Location(15, 15));
        bookingManager->cancelRide("r3");
    } catch (const std::exception &ex) {
        std::cout << "❌ Error: " << ex.what() << "\n";
    }



    std::cout << "\n✅ Case 4: No Available Drivers (All Busy)\n";
    try {
        // d1 and d2 are now busy, only d3 is far away (50, 50)
        auto ride4 = bookingManager->createRide("r4", Location(15, 15));
    } catch (const std::exception &ex) {
        std::cout << "❌ Expected: " << ex.what() << "\n";
    }


    return 0;
}
