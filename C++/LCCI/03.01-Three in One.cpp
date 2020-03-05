/**
 Describe how you could use a single array to implement three stacks.

Yout should implement push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum) methods. stackNum is the index of the stack. value is the value that pushed to the stack.

The constructor requires a stackSize parameter, which represents the size of each stack.

Example1:

 Input: 
["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
 Output: 
[null, null, null, 1, -1, -1, true]
Explanation: When the stack is empty, `pop, peek` return -1. When the stack is full, `push` does nothing.
Example2:

 Input: 
["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
[[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
 Output: 
[null, null, null, null, 2, 1, -1, -1]
 * **/
static const auto io_speed_up=[]{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class TripleInOne {
public:
    int *arr;
    int top[3],maxSize;
    TripleInOne(int stackSize) {
        arr = new int[stackSize * 3];
        maxSize = stackSize;
        top[0]=top[1]=top[2]=0;
    }
    
    void push(int stackNum, int value) {
        if(top[stackNum] < maxSize)
            arr[maxSize*stackNum + top[stackNum]++] = value;
    }
    
    int pop(int stackNum) {
        return top[stackNum] > 0 ? arr[maxSize*stackNum + --top[stackNum]] : -1;
    }
    
    int peek(int stackNum) {
        return top[stackNum] > 0 ? arr[maxSize * stackNum + top[stackNum] - 1] : -1;
    }
    
    bool isEmpty(int stackNum) {
        return top[stackNum] == 0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */