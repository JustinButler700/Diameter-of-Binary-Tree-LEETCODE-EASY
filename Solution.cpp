//Justin Butler 10/11/2021
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max = 0;
    int diameterOfBinaryTree(TreeNode* root) 
    {
        helper(root);
        return max;
    }
    int helper(TreeNode* curr) // Helper method uses recursive calls to return the maximum path length
    {
        if(curr==NULL){return 0;}
        int left = helper(curr->left); // maximum path length left
        int right = helper(curr->right); // max path right
        max = std::max(max, right+left); // add them together and compare to known max to see if the diameter is larger
        return 1+std::max(left,right); // return current maximum diameter
    }
};
