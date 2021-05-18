import java.util.*;

class Trie {
    private Trie[] children;
    private boolean isEnd;

    /** Initialize your data structure here. */
    public Trie() {
        this.children = new Trie[26];
        this.isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Trie root = this;
        for(int i = 0; i < word.length(); i++){
            int index = word.charAt(i) - 'a';
            if(root.children[index] == null){
                root.children[index] = new Trie();
            }
            root = root.children[index];
        }
        root.isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Trie root = this;
        for(int i = 0; i < word.length(); i++){
            int index = word.charAt(i) - 'a';
            if(root.children[index] != null){
                root = root.children[index];
            }
            else{
                return false;
            }
        }
        return root != null && root.isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Trie root = this;
        for(int i = 0; i < prefix.length(); i++){
            int index = prefix.charAt(i) - 'a';
            if(root.children[index] != null){
                root = root.children[index];
            }
            else{
                return false;
            }
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */



class Test{
    public static void main(String[] args) {
        // Inserted "apple"
        // trie.search("apple") = true
        // trie.search("app") = false
        // trie.startsWith("app") = true
        // Inserted "app"
        // trie.search("app") = true
        Trie trie = new Trie();
        trie.insert("apple");
        System.out.println("Inserted \"apple\"");
        System.out.println("trie.search(\"apple\") = " + trie.search("apple"));   // return True
        System.out.println("trie.search(\"app\") = "+trie.search("app"));     // return False
        System.out.println("trie.startsWith(\"app\") = "+trie.startsWith("app")); // return True
        trie.insert("app");
        System.out.println("Inserted \"app\"");
        System.out.println("trie.search(\"app\") = "+trie.search("app"));     // return True
    }
 }