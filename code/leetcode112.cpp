/*************************************************************************
	> File Name: leetcode112.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月01日 星期日 15时50分40秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum){
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) {
        return sum - root->val == 0;
    }
    return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum -root->val));
}
