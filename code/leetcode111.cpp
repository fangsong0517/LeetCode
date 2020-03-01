/*************************************************************************
	> File Name: leetcode111.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月01日 星期日 15时50分29秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
int minDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    if(root->left == NULL ||root->right == NULL) {
        return minDepth(root->left ? root->left : root->right)  + 1;
    }
    return fmin(minDepth(root->left), minDepth(root->right)) + 1;
}
*/
int minDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right != NULL) {
        return 1 + minDepth(root->right);
    }
    if(root->right == NULL && root->left != NULL) {
        return 1 + minDepth(root->left);
    }
    return fmin(minDepth(root->left), minDepth(root->right)) + 1;
}

