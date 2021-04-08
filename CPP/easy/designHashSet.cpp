#include<vector>

class MyHashSet {
private:
    std::vector<int> hashSet;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hashSet = std::vector<int>();
    }

    int index(int key){
        for(int i = 0; i < hashSet.size(); i++){
            if(key == hashSet[i]){
                return i;
            }
        }
        return -1;
    }
    
    void add(int key) {
        if(index(key) == -1){
            hashSet.push_back(key);
        }
    }
    
    void remove(int key) {
        int p = index(key);
        if(p != -1){
            hashSet.erase(hashSet.begin() + p);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return index(key) != -1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */