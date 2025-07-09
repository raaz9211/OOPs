#pragma once

#include <string>

#include "enums/EventType.hpp"

class Event {
protected:
    int id;
    std::string name;
    std::string description;
    int durationInMinutes;
    std::string language;
    EventType eventType;
public:
    Event(int id, const std::string &name, const std::string &description,
          int durationInMinutes, const std::string &language, EventType eventType) 
          : id(id), name(name), description(description),
            durationInMinutes(durationInMinutes), language(language), eventType(eventType) {}
    
    virtual ~Event() = default;

    int getId() const {return id;}
    const std::string &getName() const {return name;}
    const std::string &getDescription() const {return description;}
    int getDuration() const { return durationInMinutes; }
    const std::string &getLanguage() const { return language; }
    EventType getEventType() const {return eventType;}
};