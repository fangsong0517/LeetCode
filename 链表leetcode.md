##　链表leetcode

#### [19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

难度 中等 696

给定一个链表，删除链表的倒数第 *n* 个节点，并且返回链表的头结点。

**示例：**

```
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```

**说明：**

给定的 *n* 保证是有效的。

**进阶：**

你能尝试使用一趟扫描实现吗？

![img](https://pic.leetcode-cn.com/cc43daa8cbb755373ce4c5cd10c44066dc770a34a6d2913a52f8047cbf5e6e56-file_1559548337458)

思想：刚开始创建一个虚拟头结点，让虚拟头结点的next指向head,然后将p,q同时指向虚拟头，将ｑ往后移动ｎ + 1位，然后将ｑ与ｐ同时往后移动直到ｑ为空时，ｐ指向的是所要删除的结点前一个位置，删掉即可。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = q = &ret;//然后将p,q同时指向虚拟头
    while(n --) q= q->next;
    q = q->next;//将ｑ往后移动ｎ + 1位
    while(q) {//然后将ｑ与ｐ同时往后移动直到ｑ为空时
        p = p->next;
        q = q->next;
    }//ｐ指向的是所要删除的结点前一个位置
    q = p->next;//删掉即可。
    p->next = q->next;
    free(q);
    return ret.next;
}
```



#### [24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

难度　中等　423

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

 

**示例:**

```
给定 1->2->3->4, 你应该返回 2->1->4->3.
```

![leetcode24swapnodeinparis.JPG](https://pic.leetcode-cn.com/763b502bd7d33405e1f24473b509a4441fa24f5d074f2b0f2649b5842bce6712-leetcode24swapnodeinparis.JPG)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *ret, *p, *q; // ret是虚拟头结点
    ret.next = head;
    p = &ret;
    q = head;
    while(q&&q->next) {
        p->next = q->next;
        q->next = p->next->next;
        p->next->next = q;
        p = q;
        q = q ->next;
    }
    return ret.next; //返回头结点
}
```

#### [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

难度简单262

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

**示例 1:**

```
输入: 1->1->2
输出: 1->2
```

**示例 2:**

```
输入: 1->1->2->3->3
输出: 1->2->3
```

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head, *q;
    while(p && p->next) {
        if(p->val - p->next->val) {
            p = p->next;
        } else {
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
    return head;
}
```

#### [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

难度简单498

给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。

 

**示例 1：**

```
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png)

**示例 2：**

```
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png)

**示例 3：**

```
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png)

 **快慢指针**:前面指针快，后面指针慢，如果能重合，就相当于是圆的；

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
struct ListNode *p = head, *q = head;
 if(p == NULL) return false;//如果为空的就返回false;
 do {
     p = p->next;
     q = q->next;
     if(q == NULL || q->next == NULL) return false;
     q = q->next;
 } while(p != q);
    return true;
}
```

#### [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

难度中等369

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 `null`。

为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。

**说明：**不允许修改给定的链表。

 

**示例 1：**

```
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png)

**示例 2：**

```
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png)

**示例 3：**

```
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。
```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png)

 ```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    if(p == NULL) return NULL;
    do {
        p = p->next;
        q = q->next;
        if(q == NULL || q->next == NULL) return NULL;
        q = q->next;
    } while(p != q);
    int cnt = 0;
    do {
        cnt ++;
        p = p->next;
    } while(p != q);
    p = head, q = head;
    while(cnt--)q = q -> next;
    while(p !=  q) p = p->next, q = q->next;
    return p;
}
 ```



#### [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)

难度简单543

编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表**：**

[![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)

在节点 c1 开始相交。

**示例 1：**

[![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_1.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_1.png)

```
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
```
**示例 2：**
[![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_2.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_2.png)
```
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
```
**示例 3：**

[![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_3.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png)

```
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
```
**注意：**
- 如果两个链表没有交点，返回 `null`.
- 在返回结果后，两个链表仍须保持原有的结构。
- 可假定整个链表结构中没有循环。
- 程序尽量满足 O(*n*) 时间复杂度，且仅用 O(*1*) 内存。



**思路**：消除长度差

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p1 = headA, *p2 = headB;
    while(p1!=p2) {
        p1 = (p1 == NULL ? headB : p1->next);
        p2 = (p2 == NULL ? headA : p2->next);
    }
    return p1;
}
```

