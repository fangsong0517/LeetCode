/*************************************************************************
	> File Name: leetcode226.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月01日 星期日 15时50分58秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)return NULL;
        struct TreeNode *s;
        s = root->left;
        root->left = root ->right;
        root->right = s;
        invertTree(root->left);
        invertTree(root->right);
    return root;
}
