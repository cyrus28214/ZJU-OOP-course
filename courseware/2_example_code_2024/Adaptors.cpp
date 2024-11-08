#include <iostream>
#include <stack>
#include <queue>

int main() {
    // Stack example (LIFO)
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack (LIFO): ";
    while (!s.empty()) {
        std::cout << s.top() << " ";  // Output the top element
        s.pop();  // Remove the top element
    }
    std::cout << std::endl;

    // Queue example (FIFO)
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Queue (FIFO): ";
    while (!q.empty()) {
        std::cout << q.front() << " ";  // Output the front element
        q.pop();  // Remove the front element
    }
    std::cout << std::endl;

    // Priority Queue example (Max-Heap by default)
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);

    std::cout << "Priority Queue (Max-Heap): ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";  // Output the top (largest) element
        pq.pop();  // Remove the top element
    }
    std::cout << std::endl;

    return 0;
}
