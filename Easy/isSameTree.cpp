/ Problem: Determine if two binary trees are identical.
//          Two trees are identical if they have the same structure and all corresponding nodes have the same value.
// Approach: 
//          - Recursively compare both trees.
//          - Check if both nodes are null (base case, they are identical if both are null).
//          - If only one is null or their values differ, the trees are not identical.
//          - Recursively compare the left and right subtrees of both trees.
// Time Complexity: O(n), where n is the number of nodes in the smaller of the two trees. 
//                  Each node is visited once.
// Space Complexity: O(h), where h is the height of the tree, due to the recursive call stack.
class Solution {
public:
    bool areTreesIdentical(TreeNode* tree1, TreeNode* tree2) {
      
        if (!tree1 && !tree2) return true;
        
       
        if (!tree1 || !tree2) return false;

    
        if (tree1->val != tree2->val) return false;

      
        return areTreesIdentical(tree1->left, tree2->left) && areTreesIdentical(tree1->right, tree2->right);
    }

    bool isSameTree(TreeNode* tree1, TreeNode* tree2) {
        return areTreesIdentical(tree1, tree2);
    }
};
