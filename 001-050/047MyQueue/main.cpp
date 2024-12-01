#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> stackIn;
    stack<int> stackOut;
    MyQueue() {

    }

    void push(int x) {
        stackIn.push(x);
    }

    int pop() {
        if (stackOut.empty())
        {
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int result = stackOut.top();
        stackOut.pop();
        return result;
    }

    int peek() {
        if (stackOut.empty())
        {
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        return stackOut.top();
    }

    bool empty() {
        return stackIn.empty() && stackOut.empty();
    }
};

int main()
{
    MyQueue myQueue = MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    std::cout << myQueue.peek() << std::endl; // return 1
    std::cout << myQueue.pop() << std::endl; // return 1, queue is [2]
    std::cout << myQueue.empty() << std::endl; // return false
    return 0;
}

