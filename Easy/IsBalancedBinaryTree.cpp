// Problem: Determine if a binary tree is height-balanced.
// Approach:
//          - A tree is balanced if the absolute difference between the height of its left and right subtrees is at most 1.
//          - Recursively calculate the balance factor (height difference) for each node and check if the subtree is balanced.
// Time Complexity: O(n^2) in the worst case, as each node's height is recalculated multiple times.
// Space Complexity: O(h), where h is the height of the tree, due to the recursive call stack.

class Solution {
public:
    int calculateRightHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int rightHeight = 1 + max(calculateRightHeight(root->right), calculateRightHeight(root->left));
        return rightHeight;
    }
    
    int calculateLeftHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHeight = 1 + max(calculateLeftHeight(root->left), calculateLeftHeight(root->right));
        return leftHeight;
    }
    
    int balanceFactor(TreeNode* root) {
        return calculateLeftHeight(root->left) - calculateRightHeight(root->right);
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int bf = balanceFactor(root);
        if (bf > 1 || bf < -1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
