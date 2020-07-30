* [数据结构篇](#数据结构篇)
   * [二叉树](#二叉树)
      * [<a href="https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/" rel="nofollow">maximum-depth-of-binary-tree</a>](#maximum-depth-of-binary-tree)
      * [<a href="https://leetcode-cn.com/problems/balanced-binary-tree/" rel="nofollow">balanced-binary-tree</a>](#balanced-binary-tree)
      * [<a href="https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/" rel="nofollow">binary-tree-maximum-path-sum</a>](#binary-tree-maximum-path-sum)
      * [<a href="https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/" rel="nofollow">lowest-common-ancestor-of-a-binary-tree</a>](#lowest-common-ancestor-of-a-binary-tree)
      * [<a href="https://leetcode-cn.com/problems/binary-tree-level-order-traversal/" rel="nofollow">binary-tree-level-order-traversal</a>](#binary-tree-level-order-traversal)
      * [<a href="https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/" rel="nofollow">binary-tree-level-order-traversal-ii</a>](#binary-tree-level-order-traversal-ii)
      * [<a href="https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/" rel="nofollow">binary-tree-zigzag-level-order-traversal</a>](#binary-tree-zigzag-level-order-traversal)
      * [<a href="https://leetcode-cn.com/problems/validate-binary-search-tree/" rel="nofollow">validate-binary-search-tree</a>](#validate-binary-search-tree)
      * [<a href="https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/" rel="nofollow">insert-into-a-binary-search-tree</a>](#insert-into-a-binary-search-tree)

## 数据结构篇

### 二叉树

#### [maximum-depth-of-binary-tree](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

> 给定一个二叉树，找出其最大深度。

思路：分治法

```cpp
int maxDepth(struct TreeNode* root){
    //返回条件处理
  if(root == NULL)return 0;
    //divide: 左右子树分别计算
  int l = maxDepth(root->left);
  int r = maxDepth(root->right);
    //conquer: 合并左右子树结果
  return (l > r ? l : r) + 1;
}
```

#### [balanced-binary-tree](https://leetcode-cn.com/problems/balanced-binary-tree/)

>给定一个二叉树，判断它是否是高度平衡的二叉树。

思路：分治法，左边平衡&&右边平衡&&左右两边高度<=1。

不平衡的情况有3种：左树不平衡、右树不平衡、左树和右树差的绝对值大于1

```cpp
int Depth(struct TreeNode *root) {//求左右深度
    if(root == NULL) return 0;
    int l = Depth(root->left), r = Depth(root->right);
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL) return true;
    int l = Depth(root->left);
    int r = Depth(root->right);
    if(abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);//左右是否平衡
}
```

#### [binary-tree-maximum-path-sum](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

>给定一个**非空**二叉树，返回其最大路径和。

思路：分治法，对于任意一个点，如果最大和路径包含该节点，那么有两种可能：

1. 其左右子树所构成的路径值较大的加上该节点的值后向父节点回溯构成最大路径
2. 左右子树都在最大路径中，加上该节点的值就构成最终的最大路径

```c++
class Solution {
public:
int result;

int dfs(TreeNode *root) {
  if(root == NULL) return 0;
  int l = max(dfs(root->left), 0);//如果子树路径和为赋值应当置为0表示最大路径不包含子树
  int r = max(dfs(root->right), 0);
  result = max(root->val + l + r, result);//判断在该节点包含左右子树和是否大于当前最大路径和
  return root->val + max(0, max(l, r));
}

int maxPathSum(struct TreeNode* root){
  if(root == NULL) return 0;
  result = root->val;
  dfs(root);
  return result;
}
};
```

#### [lowest-common-ancestor-of-a-binary-tree](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

>给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

思路：分治法，有左子树的公共祖先或者有右子树的公共祖先，就返回子树的祖先，否则返回根节点

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) {//回溯的关键代表左边和右边的公共祖先
          return root;
        }
        root->left = lowestCommonAncestor(root->left, p, q);//公共祖先在左边
        root->right = lowestCommonAncestor(root->right, p, q);//公共祖先在左边
        if(root->left && root->right) {//左右都有公共祖先那公共祖先是root
          return root;
        }
        if(root->left == NULL) {//左边的公共祖先为NULL,那么公共祖先是右边的
          return root->right;
        }
        if(root->right == NULL) {//右边的公共祖先为NULL,那么公共祖先是左边的
          return root->left;
        }
        return NULL;
    }
};
```

#### [binary-tree-level-order-traversal](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

>给你一个二叉树，请你返回其按 **层序遍历** 得到的节点值。 （即逐层地，从左到右访问所有节点）

**`BFS`**广搜

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;//二维的数组
        if (!root) return ret;

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();//记录每层的
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ret;
    }
};
```

#### [binary-tree-level-order-traversal-ii](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)

>给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

思路：在上一题的层次遍历基础上，翻转一下结果即可

```c++
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>>ret;
            if(!root) return ret;
            queue<TreeNode *>q;
            q.push(root);
            while(!q.empty()) {
                    int temp = q.size();
                    ret.push_back(vector<int>());
                    for(int i = 1; i <= temp; i++) {
                            auto node = q.front();
                            q.pop();
                            ret.back().push_back(node->val);
                            if(node->left) q.push(node->left);
                            if(node->right)q.push(node->right);
                    }
            }
            reverse(ret.begin(), ret.end());//结果反转一下就行
            return ret;
    }
};
```

#### [binary-tree-zigzag-level-order-traversal](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

>给定一个二叉树，返回其节点值的锯齿形层次遍历。Z 字形遍历

对结果进行处理，偶数行翻转就行了

```c++
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>>ret;
            if(!root) return ret;
            queue<TreeNode *>q;
            q.push(root);
            int flag = 1;
            while(!q.empty()) {
                    int temp = q.size();
                    vector<int>out;
                    for(int i = 1; i <= temp; i++) {
                            auto node = q.front();
                            q.pop();
                            out.push_back(node->val);
                            if(node->left) q.push(node->left);
                            if(node->right)q.push(node->right);
                    }
                    if(flag % 2 == 0) {
                            reverse(out.begin(), out.end());
                    }
                    flag++;
                    ret.push_back(out);
            }
            return ret;    
    }
};
```

#### [validate-binary-search-tree](https://leetcode-cn.com/problems/validate-binary-search-tree/)

>给定一个二叉树，判断其是否是一个有效的二叉搜索树。

* 思路 1：中序遍历，检查结果列表是否已经有序
* 思路 2：分治法，判断左 MAX < 根 < 右 MIN

```c++
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root -> val <= inorder) return false;
            inorder = root -> val;
            root = root -> right;
        }
        return true;
    }
};

```

```c++
class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) return true;
        if (root -> val <= lower || root -> val >= upper) return false;
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);//最小值 < left, right < 最大值
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);//LONG_MIN在LONG中最小值
    }
};
```

#### [insert-into-a-binary-search-tree](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)

>给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。

```c++
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
                return new TreeNode(val);
        }
        if(root->val < val) {
                root->right = insertIntoBST(root->right, val);
        } 
        if(root->val > val) {
                root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};
```

