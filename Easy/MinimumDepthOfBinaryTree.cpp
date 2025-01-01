// Problem: Find the minimum depth of a binary tree.
// Approach:
//          - Use a recursive approach to calculate the minimum depth by comparing the left and right subtrees' depths.
//          - Return the smaller depth between the left and right subtrees plus one for the current node.
// Time Complexity: O(n), where n is the number of nodes in the tree.
//                  Each node is visited once during the recursion.
// Space Complexity: O(h), where h is the height of the tree, due to the recursive call stack.

class Solution {
public:
    int findMinDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftDepth = findMinDepth(root->left) + 1;
        int rightDepth = findMinDepth(root->right) + 1;
        return min(leftDepth, rightDepth);
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return findMinDepth(root);
    }
};
