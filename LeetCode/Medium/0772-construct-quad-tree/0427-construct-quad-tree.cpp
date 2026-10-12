/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int rstart, int rend, int cstart, int cend)
    {
        if(abs(rstart - rend) == 1)
            return new Node(grid[rstart][cstart], true);
            
        Node* node1 = construct(grid, rstart, rstart + (rend - rstart) / 2, cstart, cstart + (cend - cstart) / 2);
        Node* node2 = construct(grid, rstart + (rend - rstart) / 2, rend, cstart, cstart + (cend - cstart) / 2);
        Node* node3 = construct(grid, rstart, rstart + (rend - rstart) / 2, cstart + (cend - cstart) / 2, cend);
        Node* node4 = construct(grid, rstart + (rend - rstart) / 2, rend, cstart + (cend - cstart) / 2, cend);

        if(node1->val == node2->val && node1->val == node3->val && node1->val == node4->val && node1->isLeaf && node2->isLeaf && node3->isLeaf && node4->isLeaf)
        {
            return new Node(node1->val, 1);
        }
        else
        {
            return new Node(1, 0, node1, node3, node2, node4);
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, grid.size(), 0, grid.size());
    }
};