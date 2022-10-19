class Solution
{
public:
    Node *dfsRecursion(Node *cur, unordered_map<Node *, Node *> &mp)
    {

        vector<Node *> neighbour;

        Node *temp = new Node(cur->val);
        mp[cur] = temp;

        for (auto it : cur->neighbors)
        {

            // already clone and stored in map
            if (mp.find(it) != mp.end())
            {

                // directly push back the clone node from map to neigh
                neighbour.push_back(mp[it]);
            }
            else
            {
                neighbour.push_back(dfsRecursion(it, mp));
            }
        }
        temp->neighbors = neighbour;
        return temp;
    }

    Node *cloneGraph(Node *node)
    {

        unordered_map<Node *, Node *> mp;

        if (node == NULL)
            return NULL;

        // if only one node present no neighbors
        if (node->neighbors.size() == 0)
        {

            Node *temp = new Node(node->val);
            return temp;
        }

        return dfsRecursion(node, mp);
    }
};
