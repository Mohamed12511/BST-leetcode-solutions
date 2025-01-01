/ Problem: Check if a binary tree is symmetric around its center.
// Approach: 
//          - Use recursion to check if the left and right subtrees are mirrors of each other.
//          - Base Case: If both nodes are null, they are symmetric.
//          - Recursive Case: Check if the current nodes have the same value and 
//            their left and right subtrees are mirrored respectively.
// Time Complexity: O(n), where n is the total number of nodes in the tree, 
//                  since each node is visited once.
// Space Complexity: O(h), where h is the height of the tree, due to the recursive call stack.
class Solution {
public:
    bool isMirrored(TreeNode* leftTree, TreeNode* rightTree) {
        if (!leftTree || !rightTree) {
            return leftTree == rightTree;
        }
        if (leftTree->val == rightTree->val) {
            return isMirrored(leftTree->left, rightTree->right) && isMirrored(leftTree->right, rightTree->left);
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return false;
        bool result = isMirrored(root->left, root->right);
        return result;
    }
};
