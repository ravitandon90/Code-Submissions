class Solution {
    Node[] map= new Node[101]; 
    public Node cloneGraph(Node node) {
        if(node == null) 
            return null;

        Node curr= new Node(node.val);
        
        map[node.val]= curr;
        
        for(Node nbr: node.neighbors) {
            
            if ( map[nbr.val] == null ) {
                
                Node myChild= cloneGraph(nbr);
                curr.neighbors.add(myChild);
                
            }
            else{
                Node myChild= map[nbr.val]; 
                curr.neighbors.add(myChild);
            }
        }
        return curr;
    }
}
