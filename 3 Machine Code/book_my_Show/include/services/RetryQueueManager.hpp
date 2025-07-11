#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "models/RetryTask.hpp"

class RetryQueueManager {
public:
    std::queue<std::shared_ptr<RetryTask>> retryQueue;
    std::mutex queueMutex;
public:
    void enqueue(const std::shared_ptr<RetryTask> &task);
    std::shared_ptr<RetryTask> dequeue();
    bool isEmpty();
};