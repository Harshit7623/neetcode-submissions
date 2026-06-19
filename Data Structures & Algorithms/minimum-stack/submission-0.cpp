class MinStack {
public:
stack<int>mainstack;
stack<int>minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        mainstack.push(val);
        if( minstack.empty() || val <= minstack.top()){
            minstack.push(val);

        }
    }
    
    void pop() {
        if(mainstack.top() == minstack.top()){
            minstack.pop();
        }
        mainstack.pop();
    }
    
    int top() {
       return  mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
