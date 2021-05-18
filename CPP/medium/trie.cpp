#include <vector>
#include <string>
#include <iostream>

class Trie {
private:
    std::vector<Trie*> children;
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i = 0; i < 26; i++){
            this->children.push_back(nullptr);
        }
        isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        Trie* root = this;

        for(char c : word){
            int index = c - 'a';
            // if the current spot doesn't exist
            // create one
            if(root->children[index] == nullptr){
                root->children[index] = new Trie();
            }
            // go this way
            root = root->children[index];
        }

        root->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        Trie* root = this;

        for(char c : word){
            int index = c - 'a';
            // if exist, go this way
            if(root->children[index] != nullptr){
                root = root->children[index];
            }
            else{
                // if the current char doesn't exist in the trie
                // no need to go further
                return false;
            }
        }
        // the word exists if and only if we reach the end
        return root && root->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        Trie* root = this;

        // it's the same as search()
        for(char c : prefix){
            int index = c - 'a';
            if(root->children[index] != nullptr){
                root = root->children[index];
            }
            else{
                return false;
            }
        }
        // if we haven't return false, it has to be true
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Inserted apple
// trie->search("apple") = True
// trie->search("app") = False
// trie->startsWith("app") = True
// Inserted app
// trie->search("app") = True

int main(){
    Trie* trie = new Trie();
    trie->insert("apple");
    std::cout << "Inserted apple" << std::endl;
    std::cout << "trie->search(\"apple\") = " << (trie->search("apple")? "True": "False") << std::endl;   // return True
    std::cout << "trie->search(\"app\") = " << (trie->search("app")? "True": "False") << std::endl;     // return False
    std::cout << "trie->startsWith(\"app\") = " << (trie->startsWith("app")? "True": "False") << std::endl; // return True
    trie->insert("app");
    std::cout << "Inserted app" << std::endl;
    std::cout << "trie->search(\"app\") = " << (trie->search("app")? "True": "False") << std::endl;   // return True
    return 0;
}