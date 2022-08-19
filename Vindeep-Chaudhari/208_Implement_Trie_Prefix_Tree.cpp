class Node{
public:
    unordered_map<char, Node*> children;
    bool isEnd = false;
    
    Node(){}
};

class Trie {
private:
  Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(node->children.find(ch) == node->children.end()){
                node->children[ch] = new Node();
            }
            
            node = node->children[ch];
        }
        
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(node->children.find(ch) == node->children.end()) return false;
            node = node->children[ch];
        }
        
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            char ch = prefix[i];
            if(node->children.find(ch) == node->children.end()) return false;
            node = node->children[ch];
        }
        
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