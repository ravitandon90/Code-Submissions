class Trie {
public:
    
    // define - the node end and child node
    bool isEnd;
    Trie *child[26];
    
    Trie() {
        // the child node is initialised to nullptr
        this->isEnd = false;
        for(int i = 0; i < 26; i++) {
            this->child[i] = nullptr;
        }
    }
    
    void insert(string word) {
        // in order to insert the word, we push letter by letter in the respective child letter node
        Trie* head = this;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(head->child[index] == nullptr) {
                head->child[index] = new Trie();
            }
            head = head->child[index];
        }
        // once the last word is reached we mark isEnd as true
        head->isEnd = true;
    }
    
    bool search(string word) {
        // to search, we go over letter by letter, at any point if we encounter a nullptr, we pause the search and return false, otherwise we check if the last letter was a leaf node using isEnd and return result
        Trie* head = this;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            head = head->child[index];
            if(head == nullptr) {
                return false;
            }
        }
        return head->isEnd;
    }
    
    // it is similar to search but whether its a leaf node or not does not matter
    bool startsWith(string prefix) {
        Trie *head = this;
        for(int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            head = head->child[index];
            if(head == nullptr) {
                return false;
            }
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