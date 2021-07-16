class CustomStack {
public:
    vector<int> ar;
    int top = -1;
    int m=0;
    CustomStack(int maxSize) {
        m = maxSize;
       vector<int> v(maxSize,0);
        ar = v;
    }
    
    void push(int x) {
        if(top>=m-1) return;
        top++;
        ar[top] = x;
    }
    
    int pop() {
        if(top<0) return -1;
        int x = ar[top];
        top--;
        return x;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,top+1);i++){
            ar[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */