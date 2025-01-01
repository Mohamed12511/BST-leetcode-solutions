// Problem: Diameter of Binary Tree
// Leetcode Problem: https://leetcode.com/problems/diameter-of-binary-tree/

// Given a binary tree, you need to find the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root.

class Solution {
public:
     int calculateTreeHeight(TreeNode*r,int &maxDiameter ){
        if(r==NULL)return 0;

        int leftHeight=calculateTreeHeight(r->left,maxDiameter);
        int rightHeight=calculateTreeHeight(r->right,maxDiameter);

       maxDiameter +=abs(leftHeight-rightHeight);
       
        return leftHeight+rightHeight+r->val;
     }
    int findTilt(TreeNode* root) {
       int maxDiameter = 0;
        calculateTreeHeight(root,maxDiameter );
        return maxDiameter;
    }
};
