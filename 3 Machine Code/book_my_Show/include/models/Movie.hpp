#pragma once

#include <vector>

#include "Event.hpp"

class Movie : public Event {
private:
    std::vector<std::string> cast;
    std::string genre;
    
public:
    Movie(int id, const std::string &name, const std::string &description,
          int durationInMinutes, const std::string &language, EventType eventType,
          std::vector<std::string> cast, std::string genre) 
          : Event(id, name, description, durationInMinutes, language, eventType),
          genre(genre), cast(cast) {}
    
    const std::string &getGenre() const {return genre;}
    const std::vector<std::string>  &getCast() const {return cast;}
};
