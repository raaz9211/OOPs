#include <iostream>
#include <random>
#include <memory>

class PaymentRequest {

public:
    std::string sender;
    std::string reciever;
    double amount;
    std::string currency;


    PaymentRequest(std::string sender, std::string reciever, double amount, std::string currency)
    : sender(sender), reciever(reciever), amount(amount), currency(currency) {}

};


class BankingSystem {
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~BankingSystem() {}
};

class PaymentBankingSystem : public BankingSystem {

public:
    PaymentBankingSystem() {}

    bool processPayment(double amount) override {
        int r = rand() % 100;
        return r < 20;
    }
};


class RazorpayBankingSystem : public BankingSystem {

public:
    RazorpayBankingSystem() {}

    bool processPayment(double amount) override {
        int r = rand() % 100;
        return r < 90;
    }
};


class PaymentGateway {
protected:
    std::shared_ptr<BankingSystem> bankingSystem;

public:

    virtual bool validatePayment(std::shared_ptr<PaymentRequest> &paymentRequest) = 0;
    virtual bool initiatePayment(std::shared_ptr<PaymentRequest> &paymentRequest) = 0;
    virtual bool confirmPayment(std::shared_ptr<PaymentRequest> &paymentRequest) = 0;

    virtual bool processPayment(std::shared_ptr<PaymentRequest> &paymentRequest) {
        if(!validatePayment(paymentRequest)) {
            std::cout << "[Payment Gateway] Validate failed for " << paymentRequest->sender << std::endl;
        }

        if(!initiatePayment(paymentRequest)) {
            std::cout << "[Payment Gateway] initaiate failed for " << paymentRequest->sender << std::endl;
        }

        if(!confirmPayment(paymentRequest)) {
            std::cout << "[Payment Gateway] confirm failed for " << paymentRequest->sender << std::endl;
        }
        return true;
    }
};


class PaytmGateway : public PaymentGateway {
public:

    PaytmGateway() {
        bankingSystem = std::make_shared<PaymentBankingSystem>();
    }

    bool validatePayment(std::shared_ptr<PaymentRequest> &paymentRequest) override {

        std::cout << "[Paymet] validate for " << paymentRequest->sender << std::endl;
        if(paymentRequest->amount <= 0 || paymentRequest->currency != "INR") {
            return false;
        }

        return true;
    }

    bool initiatePayment(std::shared_ptr<PaymentRequest> &paymentRequest) override {

        std::cout << "[Paymet] initiate for " << paymentRequest->sender << std::endl;

        return bankingSystem->processPayment(paymentRequest->amount);
    }

    bool confirmPayment(std::shared_ptr<PaymentRequest> &paymentRequest) override {

        std::cout << "[Paymet] confirm for " << paymentRequest->sender << std::endl;
        return true;
    }
};


class RazorpayGateway : public PaymentGateway {
public:

    RazorpayGateway() {
        bankingSystem = std::make_shared<PaymentBankingSystem>();
    }

    bool validatePayment(std::shared_ptr<PaymentRequest> &paymentRequest) override {

        std::cout << "[Razorpay] validate for " << paymentRequest->sender << std::endl;
        if(paymentRequest->amount <= 0 || paymentRequest->currency != "INR") {
            return false;
        }

        return true;
    }

    bool initiatePayment(std::shared_ptr<PaymentRequest> &paymentRequest) override {

        std::cout << "[Razorpay] initiate for " << paymentRequest->sender << std::endl;

        return bankingSystem->processPayment(paymentRequest->amount);
    }

    bool confirmPayment(std::shared_ptr<PaymentRequest> &paymentRequest) override {

        std::cout << "[Razorpay] confirm for " << paymentRequest->sender << std::endl;
        return true;
    }
};


class PaymetGatewayProxy : public PaymentGateway {

    std::shared_ptr<PaymentGateway> realGateway;
    int retries;

public:
    PaymetGatewayProxy(std::shared_ptr<PaymentGateway> &paymentGateway, int maxRetries) {
        realGateway = paymentGateway;
        retries = maxRetries;
    }

    bool processPayment(std::shared_ptr<PaymentRequest> &paymentRequest) override {
        bool result = false;

        for(int attempt = 0; attempt < retries; attempt++) {
            if(attempt > 0) {
                std::cout << "[Proxy] Retrying payment " << attempt + 1 << " for " << paymentRequest->sender << std::endl;
            }

            result = realGateway->processPayment(paymentRequest);

            if(result) {
                break;
            }
        }
        if(!result) {
            std::cout << "[Proxy] Payment failed after " << retries << std::endl;
        }
        return result;
    }
    

    bool validatePayment(std::shared_ptr<PaymentRequest> &paymentRequest) override {
        return realGateway->validatePayment(paymentRequest);
    }


    bool initiatePayment(std::shared_ptr<PaymentRequest> &paymentRequest) override {
        return realGateway->initiatePayment(paymentRequest);
    }

    bool confirmPayment(std::shared_ptr<PaymentRequest> &paymentRequest) override {
        return realGateway->confirmPayment(paymentRequest);
    }
};

enum class GatewayType{
    PAYMET,
    RAZORPAY
};


class GatewayFactory {

    static GatewayFactory instance;

    GatewayFactory() {}
    GatewayFactory(const GatewayFactory&) = delete ;
    GatewayFactory& operator=(const GatewayFactory&) = delete;

public:
    static GatewayFactory &getInstance() {
        return instance;
    }

    std::shared_ptr<PaymentGateway> getGateway(GatewayType type) {
        if(type == GatewayType::PAYMET) {
            std::shared_ptr<PaymentGateway> paymentGateway = std::make_shared<PaytmGateway>();
            return std::make_shared<PaymetGatewayProxy>(paymentGateway, 3);
        } else {
            std::shared_ptr<PaymentGateway> paymentGateway = std::make_shared<RazorpayGateway>();
            return std::make_shared<PaymetGatewayProxy>(paymentGateway, 1);
        }
    }

};


GatewayFactory GatewayFactory::instance;

class PaymentService {
private:
    static PaymentService instance;
    std::shared_ptr<PaymentGateway> paymentGateway;
    PaymentService() {}
    PaymentService(const PaymentService&) = delete ;
    PaymentService& operator=(const PaymentService&) = delete;

public:
    static PaymentService &getInstance() {
        return instance;
    }

    void setGateway(std::shared_ptr<PaymentGateway> &paymentGateway) {
        this->paymentGateway = paymentGateway;
    }

    bool processPayment(std::shared_ptr<PaymentRequest> &paymentRequest) {
        
        if(!paymentGateway) {
            std::cout << "[PaymentService] No gateway." << std::endl;
            return false;
        }
        
        return paymentGateway->processPayment(paymentRequest);
    }
};

PaymentService PaymentService::instance;

class PaymentController {
private:
    static PaymentController instance;
    PaymentController() {}
    PaymentController(const PaymentController&) = delete ;
    PaymentController& operator=(const PaymentController&) = delete;
public:
    static PaymentController &getInstance() {
        return instance;
    }

    bool handlePayment(GatewayType type, std::shared_ptr<PaymentRequest> req) {
        std::shared_ptr<PaymentGateway> paymentGateway = GatewayFactory::getInstance().getGateway(type);
        PaymentService::getInstance().setGateway(paymentGateway);
        return PaymentService::getInstance().processPayment(req);
    }
 };


PaymentController PaymentController::instance;

 int main() {
    srand(static_cast<unsigned>(time(nullptr)));


    std::shared_ptr<PaymentRequest> req1 = std::make_shared<PaymentRequest>("Raj", "Raja", 1300, "INR");

    std::cout << "Process via Paymet \n";
    std::cout << "=====================\n";
    bool  res1 = PaymentController::getInstance().handlePayment(GatewayType::PAYMET, req1);
    std::cout << "Result " << (res1 ? "SUCESS" : "FAIL") << "\n";
    std::cout << "=====================\n";


    std::shared_ptr<PaymentRequest> req2 = std::make_shared<PaymentRequest>("Raja", "Raj", 1000, "INR");

    std::cout << "Process via Razorpay \n";
    std::cout << "=====================\n";
    bool  res2 = PaymentController::getInstance().handlePayment(GatewayType::RAZORPAY, req2);
    std::cout << "Result " << (res2 ? "SUCESS" : "FAIL") << "\n";
    std::cout << "=====================\n";
    return 0;

 }