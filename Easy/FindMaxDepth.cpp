// Problem: Find the maximum depth of a binary tree.
// Approach: 
//          - Use recursion to calculate the depth of the left and right subtrees.
//          - Base Case: If the node is null, return 0 as the depth.
//          - Recursive Case: Return the maximum depth between the left and right subtrees plus 1.
// Time Complexity: O(n), where n is the total number of nodes in the tree, 
//                  since each node is visited once.
// Space Complexity: O(h), where h is the height of the tree, due to the recursive call stack.

class Solution {
public:
    int calculateDepth(TreeNode* node) {
        if (node == NULL) return 0;
        if (!node->left && !node->right) return 1;
        return max(calculateDepth(node->left), calculateDepth(node->right)) + 1;
    }

    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return calculateDepth(root);
    }
};
