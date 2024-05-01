/**
 * @file 232-用栈实现队列.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-01
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 使用两个栈模拟队列
 *  1.stk1用来存放入队的数据
 *  2.stk2用于调整元素之间的顺序
 */


class MyQueue {
public:
    int stk1[110], tt1 = 0;
    int stk2[110], tt2 = 0;

    MyQueue() {
        
    }
    
    void push(int x) {
        if (tt1) 
            while (tt1) stk2[++ tt2] = stk1[tt1 --];
        stk1[++ tt1] = x;
        while (tt2) stk1[++ tt1] = stk2[tt2 --];
    }
    
    int pop() {
        return stk1[tt1 --];
    }
    
    int peek() {
        return stk1[tt1];
    }
    
    bool empty() {
        return !tt1;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */