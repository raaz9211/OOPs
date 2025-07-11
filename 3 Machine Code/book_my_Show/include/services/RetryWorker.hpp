#pragma once

#include <atomic>
#include <thread>
#include <chrono>
#include <memory>

#include "services/RetryQueueManager.hpp"

class RetryWorker {
private:
    std::shared_ptr<RetryQueueManager> retryQueueManager;
    std::atomic<bool> stopWorker;
    std::thread workerThread;

    void run();  // internal thread loop

public:
    RetryWorker(const std::shared_ptr<RetryQueueManager> &queueManager);
    ~RetryWorker();

    void start();
    void stop();
};