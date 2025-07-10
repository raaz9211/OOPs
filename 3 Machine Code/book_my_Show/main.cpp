// #include <iostream>
// #include <memory>
// #include <vector>
// #include <chrono>

// #include "models/User.hpp"
// #include "models/Seat.hpp"
// #include "models/Screen.hpp"
// #include "models/Show.hpp"
// #include "models/Movie.hpp"
// #include "models/City.hpp"
// #include "models/Theatre.hpp"

// #include "services/SeatLockManager.hpp"
// #include "services/BookingService.hpp"
// #include "services/ShowService.hpp"
// #include "services/PaymentService.hpp"

#include "services/BookMyShowManager.hpp"


int main() {



    // // 1st Phase
    // // 1. Setup screen + seats
    

    // auto screen = std::make_shared<Screen>(1, "Audi 1");
    // auto seat1 = std::make_shared<Seat>(101, "A1", SeatType::REGULAR);
    // auto seat2 = std::make_shared<Seat>(102, "A2", SeatType::REGULAR);
    // auto seat3 = std::make_shared<Seat>(103, "A3", SeatType::REGULAR);

    // screen->addSeat(seat1);
    // screen->addSeat(seat2);
    // screen->addSeat(seat3);

    // auto city = std::make_shared<City>(1, "Deoghar");
    // auto theatre = std::make_shared<Theatre>(1, "PVR Icon", city);
    // theatre->addScreen(screen);

    // // 2. Create a Movie object (as Event)
    // auto movie = std::make_shared<Movie>(
    //     1,
    //     "Inception",
    //     "Mind-bending sci-fi thriller",
    //     148,
    //     "English",
    //     EventType::MOVIE,
    //     std::vector<std::string>{"Leonardo DiCaprio", "Joseph Gordon-Levitt"},
    //     "Sci-Fi"
    // );

    // // 3. Create a Show
    // auto showStartTime = std::chrono::system_clock::now();
    // auto show = std::make_shared<Show>(1, movie, theatre, screen, showStartTime);



    // // 4. Create a User
    // auto user = std::make_shared<User>(1, "Raj");

    // // 5. Create service instances
    // auto seatLockManager = std::make_shared<SeatLockManager>(30); // 30 sec timeout
    // auto bookingService = std::make_shared<BookingService>(seatLockManager);
    // auto showService = std::make_shared<ShowService>(seatLockManager, bookingService);

    // // 6. Show available seats before locking
    // std::cout << "Available seats BEFORE locking:\n";
    // for (auto& seat : showService->getAvailableSeatsForShow(show)) {
    //     std::cout << seat->getSeatNumber() << " ";
    // }
    // std::cout << "\n";


    // auto paymentService = std::make_shared<PaymentService>();

    // // 7. Create booking
    // try {
    //     auto selectedSeats = {seat1};
    //     auto booking = bookingService->createBooking(user, show, selectedSeats);

    //     double amount = selectedSeats.size() * 200.0;  // mock amount
    //     bool paymentSuccess = paymentService->processPayment(user->getId(), amount);
        
    //     std::cout << "[SUCCESS] Booking ID: " << booking->getId()
    //               << ", Seat: " << seat1->getSeatNumber()
    //               << ", Status: " << static_cast<int>(booking->getStatus())
    //               << ", Payment: " << static_cast<int>(paymentSuccess) << "\n";
    // } catch (const std::exception& e) {
    //     std::cerr << "[ERROR] Booking failed: " << e.what() << "\n";
    // }

    // // 8. Show available seats after booking
    // std::cout << "Available seats AFTER booking:\n";
    // for (auto& seat : showService->getAvailableSeatsForShow(show)) {
    //     std::cout << seat->getSeatNumber() << " ";
    // }
    // std::cout << "\n";


    auto manager = BookMyShowManager::getInstance();

    manager->initialize();

    auto user = manager->createUser("Raj");

    auto cityName = "Deoghar";
    auto showsInCity = manager->searchShowsByCity(cityName);
    std::cout << "[INFO] Shows in city: " << cityName << "\n";
    for (const auto& show : showsInCity) {
        std::cout << "  Show ID: " << show->getId()
                  << ", Event: " << show->getEvent()->getName()
                  << ", Theatre: " << show->getTheatre()->getName()
                  << ", Screen: " << show->getScreen()->getName() << "\n";
    }

    // Step 4: Book ticket for the first show
    if (!showsInCity.empty()) {
        int showId = showsInCity.front()->getId();
        std::vector<int> seatIds = {101, 102};  // A1

        try {
            auto booking = manager->bookTickets(user->getId(), showId, seatIds);

 std::cout << "\n✅ Booking Successful!\n";
            std::cout << "  Booking ID: " << booking->getId() << "\n";
            std::cout << "  User: " << booking->getUser()->getName() << "\n";
            std::cout << "  Show: " << booking->getShow()->getEvent()->getName() << "\n";
            std::cout << "  Seats: ";
            for (const auto& seat : booking->getSeats()) {
                std::cout << seat->getSeatNumber() << " ";
            }
            std::cout << "\n  Status: " << static_cast<int>(booking->getStatus()) << "\n";

        } catch (const std::exception& e) {
            std::cerr << "❌ Booking failed: " << e.what() << "\n";
        }
    }
    return 0;
}
