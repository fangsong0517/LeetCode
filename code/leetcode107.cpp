/*************************************************************************
	> File Name: leetcode107.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月01日 星期日 15时49分52秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int getDepth(struct TreeNode *root) {
    if(root == NULL) return 0;
    int l = getDepth(root->left);
    int r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}

void getCnt(struct TreeNode *root, int k , int *cnt) {
    if(root == NULL) return;
    cnt[k] += 1;
    getCnt(root->left, k - 1, cnt);
    getCnt(root->right, k - 1, cnt);
    return;
}

void getResult(struct TreeNode *root, int k, int *cnt, int **ret) {
    if(root == NULL) return ;
    ret[k][cnt[k]++] = root->val;
    getResult(root->left, k - 1, cnt, ret);
    getResult(root->right, k - 1, cnt, ret);
    return ;
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int n = getDepth(root);
    int **ret = (int **) malloc(sizeof(int *) * n);
    int *cnt = (int *)calloc(n, sizeof(int));
    getCnt(root, n - 1, cnt);
    for(int i = 0; i < n; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;
    }
    getResult(root, n - 1, cnt, ret);
    *returnSize = n;
    *returnColumnSizes = cnt;
    return ret;
}
