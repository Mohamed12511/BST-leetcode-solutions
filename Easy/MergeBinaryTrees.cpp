// Problem: Merge two binary trees into a single binary tree.
// Approach: 
//          - If one tree node is null, return the other tree node.
//          - If both nodes are non-null, add the values of the nodes from both trees.
//          - Recursively merge the left and right subtrees.
// Time Complexity: O(n), where n is the total number of nodes in the smaller tree, 
//                  as each node is visited once.
// Space Complexity: O(h), where h is the height of the tree, due to the recursive call stack.

class Solution {
public:
    TreeNode* combineBinaryTrees(TreeNode* tree1, TreeNode* tree2) {
        if (!tree1) return tree2;
        if (!tree2) return tree1;
        tree1->val += tree2->val;
        tree1->left = combineBinaryTrees(tree1->left, tree2->left);
        tree1->right = combineBinaryTrees(tree1->right, tree2->right);
        return tree1;
    }
};
