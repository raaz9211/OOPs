#include "services/RetryQueueManager.hpp"



void RetryQueueManager::enqueue(const std::shared_ptr<RetryTask> &task) {
    std::lock_guard<std::mutex> lock(queueMutex);
    retryQueue.push(task);
}
std::shared_ptr<RetryTask> RetryQueueManager::dequeue() {
    std::lock_guard<std::mutex> lock(queueMutex);

    if(retryQueue.empty()) {
        return nullptr;
    }

    auto task = retryQueue.front();
    retryQueue.pop();
    return task;
}

bool RetryQueueManager::isEmpty() {
    std::lock_guard<std::mutex> lock(queueMutex);
    return retryQueue.empty();
}