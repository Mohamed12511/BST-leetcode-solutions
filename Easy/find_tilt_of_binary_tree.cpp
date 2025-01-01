/ Problem: Find Tilt of Binary Tree
// Leetcode Problem: https://leetcode.com/problems/binary-tree-tilt/

// Given a binary tree, you need to find the tilt of the tree. 
// The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values.
// The tilt of the whole tree is the sum of the tilts of all nodes in the tree.

// Approach:
// 1. We define a helper function `calculateTilt` that recursively calculates the tilt of the tree starting from the root node.
// 2. The function works by calculating the sum of left and right subtrees for each node and accumulating the absolute difference (tilt).
// 3. The tilt for the entire tree is returned as the final result.
class Solution {
public:
  
    int calculateSubtreeSum(TreeNode* node, int &totalTilt) {
        if (node == NULL) return 0;
        
        int leftSum = calculateSubtreeSum(node->left, totalTilt);   
        int rightSum = calculateSubtreeSum(node->right, totalTilt);  
        
        totalTilt += abs(leftSum - rightSum); 
        
        return leftSum + rightSum + node->val;  
    }

  
    int findTilt(TreeNode* root) {
        int totalTilt = 0;
        calculateSubtreeSum(root, totalTilt);  
        return totalTilt;  
    }
};
