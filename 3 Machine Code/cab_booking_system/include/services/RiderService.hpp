#pragma once

#include <memory>
#include <unordered_map>
#include <string>

#include "../models/Rider.hpp"

class RiderService {

private:
    std::unordered_map<std::string, std::shared_ptr<Rider>> riders;

public:
    RiderService() = default;

    std::shared_ptr<Rider> getRiderById(const std::string& riderId) const;

    void registerRider(const std::string& riderId,
                       const std::string& name,
                       const Location& initialLocation);
};