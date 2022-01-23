class MinStack {
public:
    vector<int> v1,v2;
    MinStack() {
        v1.clear();
    }
    
    void push(int val) {
        v1.push_back(val);
        if(v2.empty()){
            v2.push_back(val);
            return;
        }
        if(v2[v2.size()-1]<val){
            v2.push_back(v2[v2.size()-1]);
        }else{
            v2.push_back(val);
        }
        
    }
    
    void pop() {
        v1.pop_back();
        v2.pop_back();
    }
    
    int top() {
        return v1[v1.size()-1];
    }
    
    int getMin() {
        return v2[v2.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */