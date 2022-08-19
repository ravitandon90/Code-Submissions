class Trie {
    
    Node root; 

    public Trie() {
        root = new Node(); 
    }
    
    public void insert(String word) {
        Node current = root; 
        
        for (int i = 0; i < word.length(); i++) {
            Character c = word.charAt(i); 
            
            Node node = current.children.get(c); 
            
            if (node == null) {
                node = new Node(); 
                
                current.children.put(c, node); 
            }
            
            current = node; 
        }
        
        current.endOfWord = true; 
        
    }
    
    public boolean search(String word) {
        Node current = root; 
        
        for (int i = 0; i < word.length(); i++) {
            Character c = word.charAt(i); 
            
            Node node = current.children.get(c); 
            
            if (node == null) return false; 
            
            current = node; 
        }
        
        return current.endOfWord; 
    }
    
    public boolean startsWith(String prefix) {
        Node current = root; 
        
        for (int i = 0; i < prefix.length(); i++) {
            Character c = prefix.charAt(i); 
            
            Node node = current.children.get(c); 
            
            if (node == null) return false; 
            
            current = node; 
            
        }
        
        return true; 
    }
}

class Node {
    Map<Character, Node> children;
    boolean endOfWord; 
    
    Node() {
        children = new HashMap<>(); 
        endOfWord = false; 
    }
}
