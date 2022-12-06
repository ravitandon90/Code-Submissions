class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++) children[i]=NULL;
        isTerminal=false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root=new TrieNode('\0');
    }
    
    //Insertion---------------------------------------------
    void insertHelper(TrieNode* root, string word)
    {
        if(word.length()==0)
        {
            root->isTerminal=true;
            return;
        }
        char c=word[0];
        
        if(root->children[c-'a'])
            insertHelper(root->children[c-'a'],word.substr(1));
        else
        {
            TrieNode *child=new TrieNode(c);
            root->children[c-'a']=child;
            insertHelper(child,word.substr(1));
        }
        
    }
    
    void insert(string word) {
        insertHelper(root,word);
    }
    
    //Searching---------------------------------------------
    bool searchHelper(TrieNode* root, string word)
    {
        if(word.length()==0)
            return root->isTerminal;
        
        char c=word[0];
        
        if(root->children[c-'a']==NULL)
            return false;
        else{
            return searchHelper(root->children[c-'a'],word.substr(1));
        }
    }
    
    bool search(string word) {
        return searchHelper(root,word);
        
    }
    
    
    //Prefix----------------------------
    bool startsWithHelper(TrieNode* root, string prefix)
    {
        if(prefix.length()==0)
            return true;
        
        char c=prefix[0];
        if(root->children[c-'a']==NULL)
            return false;
        else{
            return startsWithHelper(root->children[c-'a'],prefix.substr(1));
        }
    }
    
    bool startsWith(string prefix) {
        return startsWithHelper(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
