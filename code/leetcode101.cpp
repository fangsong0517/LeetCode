/*************************************************************************
	> File Name: leetcode101.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月01日 星期日 15时48分50秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool ismirror(struct TreeNode *p, struct TreeNode *q) {
    if(p == NULL &&q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    return  (p->val == q->val) &&ismirror(p->left, q->right) && ismirror(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root){
    if(root == NULL) return true;
    return ismirror(root, root);
}
