class MinStack {
public:
    stack<int> l1,l2;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
            l1.push(x);
        if(l2.empty())
        {
            l2.push(x);
        }
        else
        {
            if(x<=l2.top())
            l2.push(x);
        }
    }
    
    void pop() {
        if(l1.top()==l2.top())
        l1.pop(),l2.pop();
        else
        l1.pop();
    }
    
    int top() {
        return l1.top();
    }
    
    int getMin() {
        return l2.top();
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