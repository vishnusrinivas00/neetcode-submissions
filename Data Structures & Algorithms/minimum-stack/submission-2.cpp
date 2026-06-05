class MinStack {
public:
    stack<int>stak;
    stack<int>minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minstack.empty()||val<=minstack.top()){
            minstack.push(val);
        }
        stak.push(val);

    }
    
    void pop() {
        if(stak.top()==minstack.top()){
            minstack.pop();
        }
        stak.pop();
    }
    
    int top() {
        return stak.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
