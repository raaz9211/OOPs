#pragma once

#include <memory>
#include <chrono>

#include "Event.hpp"
#include "Screen.hpp"
#include "Theatre.hpp"

class Show {
private:
    int id;
    std::shared_ptr<Event> event;
    std::shared_ptr<Theatre> theatre;
    std::shared_ptr<Screen> screen;
    std::chrono::system_clock::time_point startTime;

public:
    Show(int id,
         const std::shared_ptr<Event>& event,
         const std::shared_ptr<Theatre> theatre,
         const std::shared_ptr<Screen>& screen,
         const std::chrono::system_clock::time_point& startTime)
         : id(id), event(event), theatre(theatre), screen(screen), startTime(startTime) {}
    
    int getId() const {
        return id;
    }

    const std::shared_ptr<Event> &getEvent() const {
        return event;
    }

     const std::shared_ptr<Screen>& getScreen() const {
        return screen;
    }

    const std::chrono::system_clock::time_point& getStartTime() const {
        return startTime;
    }

    std::shared_ptr<Theatre> getTheatre() const {
        return theatre;
    }
};