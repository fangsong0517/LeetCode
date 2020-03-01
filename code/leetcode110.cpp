/*************************************************************************
	> File Name: leetcode110.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月01日 星期日 15时50分11秒
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
int Depth(struct TreeNode *root) {
    if(root == NULL) return 0;
    int l = Depth(root->left), r = Depth(root->right);
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL) return true;
    int l = Depth(root->left);
    int r = Depth(root->right);
    if(abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
*/
int Balanced(struct TreeNode *root) {
    if(root == NULL) return 0;
    //不平衡的情况有3种：左树不平衡、右树不平衡、左树和右树差的绝对值大于1
    int left = Balanced(root->left);
    if(left == -1) return -1;
    int right = Balanced(root->right);
    if(right == -1) return -1;
    if(abs(left - right) > 1) return -1;
    //不满足上面3种情况，说明平衡了，树的深度为左右俩子树最大深度+1
    return (left > right ? left : right) + 1;

}
bool isBalanced(struct TreeNode* root){
    return Balanced(root) != -1;
}


/*
int Depth(struct TreeNode *root) {
    if(root == NULL) return 0;
    int l = Depth(root->left), r = Depth(root->right);
    if(l == -2 || r == -2 || abs(l - r) > 1) return -2;
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root){
    return Depth(root) >= 0;
}
*/
