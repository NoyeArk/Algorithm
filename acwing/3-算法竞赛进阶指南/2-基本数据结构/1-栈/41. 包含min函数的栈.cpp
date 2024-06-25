/**
 * @file 41. 包含min函数的栈.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-06-25
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 	leetcode原题
 */

class MinStack {
public:
    /** initialize your data structure here. */
	int tt;
	pair<int, int> stk[110];

    MinStack() {
		tt = 0;
    }
    
    void push(int x) {
        if (!tt) stk[++ tt] = { x, x };
		else 
		{
			stk[tt + 1] = { x, min(x, stk[tt].second )};
			tt ++;
		}
    }
    
    void pop() {
        tt --;
    }
    
    int top() {
        return stk[tt].first;
    }
    
    int getMin() {
        return stk[tt].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */