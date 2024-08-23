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
bool sameValue(vector<vector<int>>& grid, int len, int x, int y) {
	int val = grid[x][y];
	for (int i = x; i < len + x; i++) {
		for (int j = y; j < len + y; j++) {
			if (grid[i][j] != val)
				return false;
		}
	}
	return true;
}
Node* constructQuadTree(vector<vector<int>>& grid, int len, int x, int y) {
	Node* node = new Node();

	if (sameValue(grid, len, x, y)) {
		node->isLeaf = true;
		node->val = grid[x][y];
	}
	else {
		node->isLeaf = false;
		node->val = grid[x][y];

		node->topLeft = constructQuadTree(grid, len / 2, x, y);
		node->topRight = constructQuadTree(grid, len / 2, x, y + (len / 2));
		node->bottomLeft = constructQuadTree(grid, len / 2, x + (len / 2), y);
		node->bottomRight = constructQuadTree(grid, len / 2, x + (len / 2), y + (len / 2));
	}
	return node;
}
public:
    Node* construct(vector<vector<int>>& grid) {
        int len = grid.size();

        return constructQuadTree(grid, len, 0, 0);
    }
};