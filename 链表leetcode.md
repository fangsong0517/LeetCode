

[TOC]

##　链表leetcode

#### [19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)（找同步位置）

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
<img src="https://pic.leetcode-cn.com/cc43daa8cbb755373ce4c5cd10c44066dc770a34a6d2913a52f8047cbf5e6e56-file_1559548337458" alt="img" style="zoom:50%;" />
<font color = red>思想：刚开始创建一个虚拟头结点，让虚拟头结点的next指向head,然后将p,q同时指向虚拟头，将ｑ往后移动ｎ + 1位，然后将ｑ与ｐ同时往后移动直到ｑ为空时，ｐ指向的是所要删除的结点前一个位置，删掉即可。</font>

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

<font color = red> 先将ｐ指向虚拟头，ｑ指向ｈｅａｄ，将ｐ指向ｑ的下一个元素也就是２，ｑ指向３也就是ｐ的下下一个结点，然后将ｐ的下下一个节点指向１也就是ｑ，最后将ｑ赋值给ｐ，ｑ往后移动一位，继续循环</font>

<img src="https://pic.leetcode-cn.com/763b502bd7d33405e1f24473b509a4441fa24f5d074f2b0f2649b5842bce6712-leetcode24swapnodeinparis.JPG" alt="leetcode24swapnodeinparis.JPG" style="zoom: 33%;" />



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



<font color = red>思路：前后比较，如果相同则删除后一个，不相同的往后走</font>

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
        if(p->val - p->next->val) { // 如果前后不同指针往后走
            p = p->next;
        } else {//如果相同则删除释放一个节点
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
    return head;
}
```



#### [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)(双指针算法判环)

难度简单498

给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。

**示例 1：**
```
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
```
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png" alt="img" style="zoom:50%;" />
**示例 2：**

```
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
```
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png" alt="img" style="zoom:50%;" />
**示例 3：**

```
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
```
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png" alt="img" style="zoom:50%;" />
<font color = red> **快慢指针**:前面指针快，后面指针慢，如果能重合，证明有环存在的；</font>

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

#### [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)（双指针算法找入口）

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
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png" alt="img" style="zoom:50%;" />
**示例 2：**

```
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。
```
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png" alt="img" style="zoom:50%;" />
**示例 3：**

```
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。
```
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png" alt="img" style="zoom:50%;" />

 <font color = red> **思路** :先让一个快指针一个慢指针往后走，先让他俩在环中循环，肯定能交于随机的一点，但不一定是入口，此时将快指针指向０开始，然后按慢指针速度同步走，寻找到相同的点是入口点，返回即可</font>

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
   /* int cnt = 0;
    do {
        cnt ++;
        p = p->next;
    } while(p != q);
    p = head, q = head;
    while(cnt--)q = q -> next;*/
    p = head;
    while(p !=  q) p = p->next, q = q->next;
    return p;
}
 ```
#### [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)（消除长度差）
难度简单543
编写一个程序，找到两个单链表相交的起始节点。
如下面的两个链表**：**
[<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png" alt="img" style="zoom:50%;" />](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)
在节点 c1 开始相交。
**示例 1：**
[<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_1.png" alt="img" style="zoom:50%;" />](https://assets.leetcode.com/uploads/2018/12/13/160_example_1.png)

```
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
```
**示例 2：**
[<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_2.png" alt="img" style="zoom:50%;" />](https://assets.leetcode.com/uploads/2018/12/13/160_example_2.png)

```
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
```
**示例 3：**
[<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_example_3.png" alt="img" style="zoom:50%;" />](https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png)

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

<font color = red>**思路**：消除长度差，在开始同步寻找时，先消除长度差，然后一起往后进行遍历，走到相同地址时返回即可，在消除长度差时，先让其同步往后走，如果谁先走到ＮＵＬＬ然后以另一方为头开始往后走，直到结束为止</font>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p1 = headA, *p2 = headB; //定义两个指针分别指向头
    while(p1!=p2) {//寻找两个指针指向同一地址时
        p1 = (p1 == NULL ? headB : p1->next);// 如果p1为空则指向headB,也就是另一个头，不为空往后走
        p2 = (p2 == NULL ? headA : p2->next);//如果p2为空则指向另一个头headA,不为空往后走
    }
    return p1; //返回p1和p2都行
}
```



#### [202. 快乐数](https://leetcode-cn.com/problems/happy-number/)（双指针算法判环）
难度简单241
编写一个算法来判断一个数是不是“快乐数”。
一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
**示例:** 

```
输入: 19
输出: true
解释: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

<font color = red>思路：抽象成链表，快慢指针是否出现环使用“快慢指针”思想找出循环：“快指针”每次走两步，“慢指针”每次走一步，当二者相等时，即为一个循环周期。此时，判断是不是因为1引起的循环，是的话就是快乐数，否则不是快乐数。</font>

```cpp
//如果给定的数字最后会一直循环重复，那么快的指针（值）一定会追上慢的指针（值），也就是
//两者一定会相等。如果没有循环重复，那么最后快慢指针也会相等，且都等于1。
int get_next(int n) {// 获取一个加法后的值
    int temp = 0;
    while(n) {
        temp+= (n % 10) * ( n % 10);
        n /= 10;
    }
    return temp;
}
bool insHappy(int n) { //双指针算法
    int p = n, q = n;//刚开始将其都指向ｎ
    while(q != 1) {//当ｑ为１的时候结束
        p = get_next(p);//慢指针走一步
        q = get_next(get_next(q));//快指针走２步
        if(p == q) break;//当ｐ和ｑ相同时说明其中成环结束之
    }
    return q == 1;//因为ｑ总是在ｐ前面，所以要判断ｑ是否先等于１
}
```

#### [203. 移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements/)

难度简单346

删除链表中等于给定值 **val** 的所有节点。
**示例:**

```
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
```
<font color = red>思路：整一个虚拟头，找到p->next是否等于所要删除的元素，此时ｐ为所要删除的前一个元素，将p->next删除就可以了 </font>

![image.png](https://pic.leetcode-cn.com/79abd00de9bc8811483d019b86b1eafd7f3735800cc244012cde7b8a3d1dd751-image.png)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode ret, *p , *q;
    ret.next = head;// 虚拟头指向真正的头
    p = &ret;//ｐ在虚拟头处
    while(p && p->next) {//循环判断p->next ->val == val,如果找到则为所要删除元素的前一个元素
        if(p->next ->val== val) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {//没找到继续往后走
            p = p->next;
        }
    }
    return ret.next;
}
```

#### [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)（头插法）

难度简单781

反转一个单链表。

**示例:**

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

**进阶:**
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//先将虚拟头质控，将p = head;头插法
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) return head;
    struct ListNode * p, *q, ret;
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

#### [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)（中分判回文）

难度简单409收藏分享切换为英文关注反馈

请判断一个链表是否为回文链表。

**示例 1:**

```
输入: 1->2
输出: false
```

**示例 2:**

```
输入: 1->2->2->1
输出: true
```

**进阶：**
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

<font color = red>思路：先将链表分为两部分，将后面一部分进行翻转，然后进行比较两段是否匹配</font>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int get_length(struct ListNode *head) { //获取长度
    int n = 0;
    while(head)n+=1,head=head->next;
    return n;
}

struct ListNode *reverse(struct ListNode *head, int n) {//翻转后半部分
    struct ListNode ret, *p = head, *q;
    while(n--) p = p->next;
    ret.next = NULL;
    while(p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
bool isPalindrome(struct ListNode* head){
    int len = get_length(head);
    struct ListNode *p = head, *q = reverse(head, (len + 1 ) / 2);
    while(q) {//同步比较
        if(p->val - q->val)return false;
        p=p->next;
        q=q->next;
    }
return true;
}
```

#### [237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)（覆盖删除法）

难度简单623

请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

现有一个链表 -- head = [4,5,1,9]，它可以表示为:

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/01/19/237_example.png)

 

**示例 1:**

```
输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
```

**示例 2:**

```
输入: head = [4,5,1,9], node = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
```

**说明:**

- 链表至少包含两个节点。
- 链表中所有节点的值都是唯一的。
- 给定的节点为非末尾节点并且一定是链表中的一个有效节点。
- 不要从你的函数中返回任何结果。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *t = node->next;//先记录所要删除点的下一个节点
    node->val = t->val;//将其值付给所要删除的点
    node->next = t->next;//删除下一个节点
    free(t);
}
```

#### [287. 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/)（双指针算法找入口）

难度中等433

给定一个包含 *n* + 1 个整数的数组 *nums*，其数字都在 1 到 *n* 之间（包括 1 和 *n*），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

**示例 1:**

```
输入: [1,3,4,2,2]
输出: 2
```

**示例 2:**

```
输入: [3,1,3,4,2]
输出: 3
```

**说明：**

1. **不能**更改原数组（假设数组是只读的）。
2. 只能使用额外的 *O*(1) 的空间。
3. 时间复杂度小于 *O*(*n*2) 。
4. 数组中只有一个重复的数字，但它可能不止重复出现一次。

```cpp
/*int findDuplicate(int* nums, int numsSize){
    int k = 0, m = 0;
    while(1) {
        k = nums[nums[k]];
        m = nums[m];
        if(k == m) {
            k = 0;
            while(nums[k] != nums[m]) {
                k = nums[k];
                m = nums[m];
            }
            return nums[m];
        }
    }
}*/
int findDuplicate(int* nums, int numsSize){
    int p = nums[0], q = nums[0];
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while(p != q);
    q = nums[0];
    while(p!=q) {
        p = nums[p];
        q = nums[q];
    }
    return p;
}
```
## <font color =red>快慢指针寻找环入口法证明：</font><img src="https://static.dingtalk.com/media/lADPGoGu6sN4h9nNB43NCCw_2092_1933.jpg_620x10000q90g.jpg?auth_bizType=IM&amp;auth_bizEntity=%7B%22cid%22%3A%22627064533%3A627064533%22%2C%22msgId%22%3A%222541553216786%22%7D&amp;bizType=im&amp;open_id=627064533" alt="图片" style="zoom: 80%;" />





### 链表操作摘要

- 单链表插入、删除、查找
- 单链表反转
- 单链表反转从位置 m 到 n 的部分
- 链表中环的检测
- 合并两个有序的链表
- 合并K个排序链表
- 删除链表倒数第n个节点
- 求链表的中间结点
- 求链表环的入口节点
- 两两交换链表中的节点
- K 个一组翻转链表

[https://github.com/Alex660/Algorithms-and-data-structures/blob/master/algo/%E9%93%BE%E8%A1%A8_linkedList.md](https://github.com/Alex660/Algorithms-and-data-structures/blob/master/algo/链表_linkedList.md)

