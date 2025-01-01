// Problem: Given a binary tree, return the inorder traversal of its nodes' values.
// Approach: Use a recursive approach to visit the left subtree, then the node, and then the right subtree.
Time Complexity: O(n)
Space Complexity: O(n) (due to the result vector and recursive call stack)

class Solution {
public:
    // Recursive function to perform in-order traversal
    void inorderTraversalHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;

        inorderTraversalHelper(node->left, result);  // Traverse left subtree
        result.push_back(node->val);  // Visit the current node
        inorderTraversalHelper(node->right, result);  // Traverse right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversalHelper(root, result);  // Start in-order traversal
        return result;
    }
};
