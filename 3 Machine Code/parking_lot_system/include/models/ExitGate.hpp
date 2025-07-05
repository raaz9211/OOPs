#pragma once

#include <memory>

#include "Gate.hpp"
#include "../models/Ticket.hpp"
#include "../models/Receipt.hpp"
#include "../services/FeeCalculationStrategy.hpp"

class ExitGate : public Gate {
private:
    std::shared_ptr<FeeCalculationStrategy> feeStrategy;
public:
    ExitGate(int id, const std::string &name, std::shared_ptr<FeeCalculationStrategy>  strategy);

    std::shared_ptr<Receipt> processVehicleExit(std::shared_ptr<Ticket> ticket);
};