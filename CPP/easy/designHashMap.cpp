#include<vector>

class MyHashMap {
private:
    std::vector<std::pair<int, unsigned>> myMap;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        myMap = std::vector<std::pair<int, unsigned>>{};
    }

    int exist(int key){
        for(int i = 0; i < myMap.size(); i++){
            if(myMap[i].first == key){
                return i;
            }
        }
        return -1;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = exist(key);
        if( index == -1){
            myMap.push_back(std::make_pair(key, value));
        }
        else{
            myMap[index].second = value;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = exist(key);
        return index == -1? index : myMap[index].second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = exist(key);
        if(index != -1){
            myMap.erase(myMap.begin()+index);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */