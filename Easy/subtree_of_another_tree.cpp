// Problem: Subtree of Another Tree
// Given the roots of two binary trees, `root` and `subRoot`, write a function to check 
// if `subRoot` is a subtree of `root`. A subtree of a tree is a tree that consists of a node 
// in the tree and all of its descendants. The function should return true if `subRoot` is a subtree 
// of `root`, and false otherwise.
//
// Approach:
// 1. Create a helper function `IsTheSame` to check if two trees are exactly the same.
// 2. Recursively traverse the main tree (`root`), and for each node, check if its subtree matches `subRoot`
//    using the `IsTheSame` function.
// 3. If a match is found, return true. If the traversal ends without finding any match, return false.

class Solution {
public:
   
    bool IsTheSame(TreeNode* root, TreeNode* sub) {
      
        if (!root && !sub) return true;

       
        if (!root || !sub) return false;

        
        if (root->val != sub->val) return false;

      
        return IsTheSame(root->left, sub->left) && IsTheSame(root->right, sub->right);
    }

    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       
        if (!root) return false;

      
        if (!subRoot) return true;

      
        if (IsTheSame(root, subRoot)) {
            return true;
        }

       
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
