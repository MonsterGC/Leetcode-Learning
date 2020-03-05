/**
 How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? Push, pop and min should all operate in 0(1) time.

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> return -3.
minStack.pop();
minStack.top();      --> return 0.
minStack.getMin();   --> return -2.
 * **/
static const auto io_speed_up=[]{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class MinStack {
private:
    stack<int> main_stk,help_stk;
    int temp;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        main_stk.push(x);
        if(help_stk.empty()) help_stk.push(x);
        else {
            temp = help_stk.top();
            x < temp ? help_stk.push(x) : help_stk.push(temp); 
        }
    }
    
    void pop() {
        main_stk.pop();
        help_stk.pop();
    }
    
    int top() {
        return main_stk.top();
    }
    
    int getMin() {
        return help_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */