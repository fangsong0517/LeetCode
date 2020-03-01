/*************************************************************************
	> File Name: leetcode257.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月01日 星期日 15时51分32秒
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
void dfs(struct TreeNode *root, char **bin_tree_paths, int *path, int *return Size, int depth) {
    int i = 0;
    path[depth++] = root->val;
    if(root->left == NULL && root->right == NULL) {
        bin_tree_path[*returnSize] = (char *)malloc(sizeof(char) * 100);
        bin_tree_path[*returnSize][0] = 0;
        for(i = 0; i < depth - 1; i ++) {
            sprintf(bin_tree_paths[*returnSize], "%s%d", bin_tree_paths[*returnSize], path[i]);
        }
    }
}*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int path[100] = {0}, depth = 0;
    char ** bin_tree_path = (char **)malloc(sizeof(char *) * 100);
    if(root == NULL) return root;
    *returnSize = 0;
    dfs(root, bin_tree_path, path, returnSize, depth);
    return bin_tree_paths;
}*/
int getPathCnt(struct TreeNode *root) {
    if(root == NULL) return 0;
    if(root ->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right);
}

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    if(root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    buff[len] = 0;
    if(root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buff);
        return 1;
    }
    len += sprintf(buff + len, "->");
    int cnt  = getResult(root->left, len, k, ret, buff);
    cnt += getResult(root->right, len,k+cnt,ret,buff );
    return cnt;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt = getPathCnt(root);
    char **ret = (char **)malloc(sizeof(char *) * pathCnt);
    int max_len = 1024;
    char *buff = (char * )malloc(sizeof(char) * max_len);
    getResult(root, 0, 0, ret, buff);
    *returnSize = pathCnt;
    return ret;
}
