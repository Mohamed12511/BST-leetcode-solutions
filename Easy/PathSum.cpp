// Problem: Determine if a binary tree has a root-to-leaf path with a sum equal to a given targetSum.
// Approach:
//          - Use a Breadth-First Search (BFS) approach.
//          - Traverse the tree level by level while maintaining the cumulative sum of the current path.
//          - If a leaf node is reached and its cumulative sum equals the target, return true.
//          - Otherwise, continue traversing until all paths are checked.
// Time Complexity: O(n), where n is the number of nodes in the tree.
//                  Each node is visited once during the BFS traversal.
// Space Complexity: O(n), due to the queues used for BFS traversal.

class Solution {
public:
    bool checkPathSum(TreeNode* root, int targetSum) {
        queue<int> sumQueue;
        queue<TreeNode*> nodeQueue;
        sumQueue.push(root->val);
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int currentSum = sumQueue.front();
            sumQueue.pop();
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (!currentNode->left && !currentNode->right) {
                if (currentSum == targetSum) return true;
            }

            if (currentNode->left) {
                sumQueue.push(currentSum + currentNode->left->val);
                nodeQueue.push(currentNode->left);
            }
            if (currentNode->right) {
                sumQueue.push(currentSum + currentNode->right->val);
                nodeQueue.push(currentNode->right);
            }
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return checkPathSum(root, targetSum);
    }
};
