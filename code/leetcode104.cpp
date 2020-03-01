/*************************************************************************
	> File Name: leetcode104.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月01日 星期日 15时49分29秒
 ************************************************************************/
int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    int l = maxDepth(root->left), r= maxDepth(root->right);
    return (l > r ? l : r) + 1;
}
