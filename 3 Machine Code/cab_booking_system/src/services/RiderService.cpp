#include "services/RiderService.hpp"



void RiderService::registerRider(const std::string& riderId,
                    const std::string& name,
                    const Location& initialLocation) {
    auto rider = std::make_shared<Rider>(riderId, name, initialLocation);
    riders[riderId] = rider;
}

std::shared_ptr<Rider> RiderService::getRiderById(const std::string& riderId) const {
    auto it = riders.find(riderId);
    return it != riders.end() ? it->second : nullptr;
}