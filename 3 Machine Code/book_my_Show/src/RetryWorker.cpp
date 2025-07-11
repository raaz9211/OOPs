
#include "services/RetryWorker.hpp"


RetryWorker::RetryWorker(const std::shared_ptr<RetryQueueManager> &queueManager) 
    : retryQueueManager(queueManager), stopWorker(false) {}

RetryWorker::~RetryWorker() {
    stop();
    if (workerThread.joinable()) {
        workerThread.join();
    }
}

void RetryWorker::start() {
    stopWorker = false;
    workerThread = std::thread(&RetryWorker::run, this);
}

void RetryWorker::stop() {
    stopWorker = true;
}

void RetryWorker::run() {
    while ((!stopWorker))
    {
        if(!retryQueueManager->isEmpty()) {
            auto task = retryQueueManager->dequeue();
            if(task) {
                bool success = task->tryBooking();
                if(!success && task->getAttemptCount() < 3) {
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    retryQueueManager->enqueue(task);
                } else if (!success) {
                    std::cerr << "[FAILURE] Retry attempts exhausted for user: "
                              << task->getLastTriedTime().time_since_epoch().count() << "\n";
                }
            }
        } else {
            // If no task, sleep briefly
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    
}

