/**
 * Problem: Diameter of Binary Tree
 * 
 * The task is to find the diameter of a binary tree. The diameter is defined as the longest path between 
 * any two nodes in the tree, where the path may or may not pass through the root. The length of the path 
 * is measured in terms of the number of edges.
 * 
 * Approach:
 * 1. A recursive approach is used where we calculate the height of each node and also track the longest 
 *    path (diameter) found.
 * 2. The function `Max()` is used to calculate the height of each node, and during the process, it keeps 
 *    track of the maximum path length encountered between two child nodes.
 * 3. The base case for recursion is when the node is NULL, returning a height of 0.
 * 
 * Time Complexity: O(N), where N is the number of nodes in the tree. We traverse each node once.
 * Space Complexity: O(H), where H is the height of the tree due to recursive call stack.
 */

class Solution {
public: 
    int calculateHeight(TreeNode* root, int &maxDiameter) {
        if (root == NULL) return 0;
        
        int leftHeight = calculateHeight(root->left, maxDiameter);
        int rightHeight = calculateHeight(root->right, maxDiameter);
        
        int currentHeight = max(leftHeight, rightHeight) + 1;
        
      
        if (leftHeight + rightHeight > maxDiameter) maxDiameter = leftHeight + rightHeight;
        
        return currentHeight;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        int maxDiameter = 0;
        calculateHeight(root, maxDiameter);

        return maxDiameter;
    }
};
