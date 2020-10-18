* [数据结构篇](#数据结构篇)
   * [二叉树](#二叉树)
      * [maximum-depth-of-binary-tree](#maximum-depth-of-binary-tree)
      * [balanced-binary-tree](#balanced-binary-tree)
      * [binary-tree-maximum-path-sum](#binary-tree-maximum-path-sum)
      * [lowest-common-ancestor-of-a-binary-tree](#lowest-common-ancestor-of-a-binary-tree)
      * [binary-tree-level-order-traversal](#binary-tree-level-order-traversal)
      * [binary-tree-level-order-traversal-ii](#binary-tree-level-order-traversal-ii)
      * [binary-tree-zigzag-level-order-traversal](#binary-tree-zigzag-level-order-traversal)
      * [validate-binary-search-tree](#validate-binary-search-tree)
      * [insert-into-a-binary-search-tree](#insert-into-a-binary-search-tree)

[TOC]

## 数据结构篇

### 二叉树

#### maximum-depth-of-binary-tree[二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

[maximum-depth-of-binary-tree](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

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

#### balanced-binary-tree[平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)

[balanced-binary-tree](https://leetcode-cn.com/problems/balanced-binary-tree/)

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

#### binary-tree-maximum-path-sum[二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

[binary-tree-maximum-path-sum](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

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

#### lowest-common-ancestor-of-a-binary-tree[二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

[lowest-common-ancestor-of-a-binary-tree](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

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

#### binary-tree-level-order-traversal[二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

[binary-tree-level-order-traversal](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

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

#### binary-tree-level-order-traversal-ii[二叉树的层次遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)

[binary-tree-level-order-traversal-ii](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)

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

#### binary-tree-zigzag-level-order-traversal [二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

[binary-tree-zigzag-level-order-traversal](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

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

#### validate-binary-search-tree[ 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)

[validate-binary-search-tree](https://leetcode-cn.com/problems/validate-binary-search-tree/)

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

#### insert-into-a-binary-search-tree[二叉搜索树中的插入操作](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)

[insert-into-a-binary-search-tree](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)

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

### 链表

#### remove-duplicates-from-sorted-list[ 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

[remove-duplicates-from-sorted-list](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

>给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

```c
struct ListNode* deleteDuplicates(struct ListNode* head){
        struct ListNode *p = head, *q;
        while(p && p->next) {
                if(p->val != p->next->val) {//不相同就一直往后走
                        p = p->next;
                } else {//相同时删除后面结点
                        q = p->next;
                        p->next = q->next;
                        free(q);
                }
        }
        return head;
}
```

#### remove-duplicates-from-sorted-list-ii[删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)

[remove-duplicates-from-sorted-list-ii](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)

>给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现的数字。
>
>有可能把头删掉

```c

struct ListNode* deleteDuplicates(struct ListNode* head){
        struct ListNode dummy;//虚拟头结点
        dummy.next = head;
        struct ListNode *p = &dummy;
        while(p->next && p->next->next) {
                if(p->next->val == p->next->next->val) {
                        struct ListNode *q = p->next;
                        while(q && q->next && q->val == q->next->val) {
                                q = q->next;
                        }
                        p->next = q->next;
                } else {
                        p = p->next;
                }
        }
        return dummy.next;
}
```

#### reverse-linked-list[反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

[reverse-linked-list](https://leetcode-cn.com/problems/reverse-linked-list/)

>反转一个单链表。

```c++
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) return NULL;
    struct ListNode ret, *p, *q;
    ret.next = NULL;
    p = head;
    while(p) {
            q = p->next;
            p->next = ret.next;
            ret.next = p;
            p = q;
    }
    return ret.next;
}
```

#### reverse-linked-list-ii[反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)

[reverse-linked-list-ii](https://leetcode-cn.com/problems/reverse-linked-list-ii/)

>反转从位置 *m* 到 *n* 的链表。请使用一趟扫描完成反转。

```c
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
        if(head== NULL) return NULL;
        struct ListNode ret;
        ret.next = head;
        struct ListNode *p;
        p = &ret;
        for(int i = 1; i < m; i++){//先找到要翻转的起点前一个位置
                p = p->next;
        }
        head = p->next;//因为不要返回ｈｅａｄ，所以这里可以直接利用ｈｅａｄ
        for(int i = m; i < n; i++) {
                struct ListNode *q = head->next;
                head->next = q->next;
                q->next = p->next;
                p->next = q;
        }
        return ret.next;
}
```

![image-20200731115124169](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200731115124169.png)

#### merge-two-sorted-list[合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

[merge-two-sorted-lists](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

>将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

思路:使用ret连接各个元素.

```c++

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
        struct ListNode ret, *p = &ret;
        ret.next = NULL;
        while(l1 || l2) {//都为空的时候跳出
                if(l2 == NULL || (l1 && l1->val <= l2->val)) {//l2为空，或者l1不为空且l1->val <= l2->val
                        p->next = l1;
                        l1= l1->next;
                } else {//l1为空连接l2，或者l2不为空且l1->val > l2->val;
                        p->next = l2;
                        l2 = l2->next;
                }
                p = p->next;//ｐ往后走一个
                p->next = NULL;//末未处理
        }
        return ret.next;
}
```

#### partition-list[分隔链表](https://leetcode-cn.com/problems/partition-list/)

**[partition-list](https://leetcode-cn.com/problems/partition-list/)**

>给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 *x* 的节点都在大于或等于 *x* 的节点之前。

思路：将大于 x 的节点，放到另外一个链表，最后连接这两个链表

```c++
struct ListNode* partition(struct ListNode* head, int x){
        if(head == NULL) return head;
        struct ListNode headLess, headGreater;
        struct ListNode *curLess, *curGreater;
        headLess.next = headGreater.next = NULL;
        curLess = &headLess;
        curGreater = &headGreater;

        while(head) {
                if(head->val < x) {
                        curLess->next = head;
                        curLess = curLess->next;
                } else {
                        curGreater->next = head;
                        curGreater = curGreater->next;
                }
                head = head->next;
        }
        curGreater->next = NULL;
        curLess->next = headGreater.next;
        return headLess.next;
}
```

#### sort-list [排序链表](https://leetcode-cn.com/problems/sort-list/)

**[sort-list](https://leetcode-cn.com/problems/sort-list/)**

>在 *O*(*n* log *n*) 时间复杂度和常数级空间复杂度下，对链表进行排序。

思路：归并排序，找中点和合并操作

```c++
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int length = 0;
        while (p) {
            ++length;
            p = p->next;
        }
        
        for (int size = 1; size < length; size <<= 1) {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
            
            while (cur) {
                auto left = cur;
                auto right = cut(left, size); 
                cur = cut(right, size); 
                
                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }
    
    ListNode* cut(ListNode* head, int n) {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }
        
        if (!p) return nullptr;
        
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;       
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};
```

#### reorder-list [重排链表](https://leetcode-cn.com/problems/reorder-list/)

>给定一个单链表 *L*：*L*→*L*→…→*L__n*→*L* 将其重新排列后变为： *L*→*L__n*→*L*→*L__n*→*L*→*L__n*→…

双指针，l++, r--

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
       if(head == NULL) return;
       vector<ListNode *>vec;
       ListNode *p = head;
       while(p) {
           vec.push_back(p);
           p = p ->next;
       }
       int l = 0, r = vec.size() - 1;
       while(l < r) {
           vec[l]->next = vec[r];
           vec[r--]->next = vec[++l];//核心
       } 
       vec[l]->next = nullptr;
    }
};
```

#### linked-list-cycle[环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

> 给定一个链表，判断链表中是否有环。

思路：快慢指针，快慢指针相同则有环

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *p = head, *q = head;
        do{
            p = p->next;
            q = q->next;
            if(p == NULL || p->next == NULL) {
                return false;
            }
            p = p->next;
        }while(p != q);
        return true;
    }
};
```



#### linked-list-cycle-ii [环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

> 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 `null`。

思路：快慢指针，快慢相遇之后，慢指针回到头，快慢指针步调一致一起移动，相遇点即为入环点 

![cycled_linked_list](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/cycled_linked_list.png)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *p = head, *q = head;
        do {
            p = p->next;
            q = q->next;
            if(p == NULL || p->next == NULL) return NULL;
            p = p->next;
        }while(p != q);
        p = head;
        while(p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
}
```

#### palindrome-linked-list[ 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)

>请判断一个链表是否为回文链表。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode *>stk;
        ListNode *q = head;
        while(q) {
            stk.push(q);
            q = q->next;
        }
        q = head;
        while(!stk.empty()) {
            ListNode *temp = stk.top();
            stk.pop();
            if(temp->val != q->val) return false;
            q = q->next;
        }
        return true;
    }
};
```

#### copy-list-with-random-pointer[复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)

>给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。 要求返回这个链表的 深拷贝。

思路：1、hash 表存储指针，2、复制节点跟在原节点后面

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node *cur = head;
        // 复制节点，紧挨到到后面
    // 1->2->3  ==>  1->1'->2->2'->3->3'
        while(cur) {
            Node *clone = new Node(cur->val, cur->next, nullptr);
            Node *temp = cur->next;
            cur->next = clone;
            cur = temp;
        }
        //处理random指针
        cur = head;
        while(cur) {
            if(cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // 分离两个链表
        cur = head;
        Node *ret = head->next;
        while(cur->next) {
            Node *temp = cur->next;
            cur->next = cur->next->next;
            cur = temp;
        }
    // 原始链表头：head 1->2->3
    // 克隆的链表头：cloneHead 1'->2'->3'
        return ret;
    }
};
```

