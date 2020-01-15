#pragma once

#include <iostream>
#include <queue>
#include <vector>

struct Median {
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    void insert(int data) {
        if (max_heap.empty()) {
            max_heap.push(data);
            return;
        }
        if (max_heap.size() == min_heap.size()) {
            if (data <= get())
                max_heap.push(data);
            else
                min_heap.push(data);
            return;
        }
        if (max_heap.size() < min_heap.size()) {
            if (data > get()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(data);
            } else {
                max_heap.push(data);
            }
        }
        if (data < get()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(data);
        } else {
            min_heap.push(data);
        }
    }

    double get() {
        if (max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top())/2.0;
        if (max_heap.size() < min_heap.size())
            return min_heap.top();
        return max_heap.top();
    }
};
