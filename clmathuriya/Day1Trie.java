class Trie {
    
   public StringBuilder trie = new StringBuilder();

    public Trie() {
        
    }
    
    public void insert(String word) {
        this.trie.append(word + ",");
        
    }
    
    public boolean search(String word) {
        if(this.trie.toString().startsWith(word+",") || this.trie.toString().contains(","+word + ",")){
            return true;
      }else {
            return false;
            }
    }
    
    public boolean startsWith(String prefix) {
        if(this.trie.toString().startsWith(prefix) || this.trie.toString().contains("," + prefix)) {
            return true;
            } else {
            return false;
            }
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
