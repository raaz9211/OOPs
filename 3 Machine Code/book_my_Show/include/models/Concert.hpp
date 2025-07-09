#pragma once

#include <vector>

#include "Event.hpp"

class Movie : public Event {
private:
    std::vector<std::string> artists;
    bool isVIPAvailable;
    Movie(int id, const std::string &name, const std::string &description,
          int durationInMinutes, const std::string &language, EventType eventType,
          std::vector<std::string> artists, bool isVIPAvailable) 
          : Event(id, name, description, durationInMinutes, language, eventType),
          artists(artists), isVIPAvailable(isVIPAvailable) {}
    
    const std::vector<std::string>  &getArtists() const {return artists;}
    bool getVIPAvailable() const {return isVIPAvailable;}
};
