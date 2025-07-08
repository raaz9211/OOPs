enum class PaymentMode
{
    CASH,
    CARD,
    UPI,
    NET_BANKING
};

inline std::string to_string(PaymentMode mode) {
    switch (mode) {
        case PaymentMode::CASH: return "Cash";
        case PaymentMode::CARD: return "Card";
        case PaymentMode::UPI: return "UPI";
        case PaymentMode::NET_BANKING: return "Net Banking";
        default: return "Unknown";
    }
}
