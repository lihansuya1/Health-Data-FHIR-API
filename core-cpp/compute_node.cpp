#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 3986
// Optimized logic batch 9395
// Optimized logic batch 2700
// Optimized logic batch 7393
// Optimized logic batch 1880
// Optimized logic batch 8358
// Optimized logic batch 3627
// Optimized logic batch 7463
// Optimized logic batch 5521
// Optimized logic batch 5125
// Optimized logic batch 5247
// Optimized logic batch 5898
// Optimized logic batch 8158
// Optimized logic batch 7225
// Optimized logic batch 2790
// Optimized logic batch 6884
// Optimized logic batch 4231
// Optimized logic batch 7029
// Optimized logic batch 5198
// Optimized logic batch 2027
// Optimized logic batch 7713
// Optimized logic batch 7676