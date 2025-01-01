// Problem: Convert a sorted array into a height-balanced binary search tree (BST).
// Approach: 
//          - Use a divide-and-conquer approach.
//          - Pick the middle element of the array as the root of the BST.
//          - Recursively repeat the process for the left and right halves of the array.
// Time Complexity: O(n), where n is the size of the array, as each element is visited once.
// Space Complexity: O(log n), due to the recursive call stack for a balanced binary tree.

class Solution {
public:   
    TreeNode* buildBST(int left, int right, vector<int>& nums) {
        if (nums.empty()) return nullptr;
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildBST(left, mid - 1, nums);
        node->right = buildBST(mid + 1, right, nums);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = buildBST(0, nums.size() - 1, nums);
        return root;
    }
};
