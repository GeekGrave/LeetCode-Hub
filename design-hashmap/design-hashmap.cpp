class MyHashMap {
    int ar[1000006];
public:
    MyHashMap() {
        for(int i=0;i<1000006;i++){
            ar[i] = -1;
        }
    }
    
    void put(int key, int value) {
        ar[key] = value;
    }
    
    int get(int key) {
        return ar[key];
    }
    
    void remove(int key) {
        ar[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */