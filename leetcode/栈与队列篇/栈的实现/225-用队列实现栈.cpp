/**
 * @file 225-用队列实现栈.cpp   
 * @author horiki
 * @brief 
 * @version 0.1
 * @date 2024-05-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class MyStack {
public:
    int q1[110], hh1, tt1;
    int q2[110], hh2, tt2;

    MyStack() {
        hh1 = hh2 = 0;
        tt1 = tt2 = -1;
    }
    
    void push(int x) {
        if (hh1 <= tt1)
            while (hh1 <= tt1) q2[++ tt2] = q1[hh1 ++];
        q1[++ tt1] = x;
        while (hh2 <= tt2) q1[++ tt1] = q2[hh2 ++];
    }
    
    int pop() {
        return q1[hh1 ++];
    }
    
    int top() {
        return q1[hh1];
    }
    
    bool empty() {
        return !(hh1 <= tt1);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */