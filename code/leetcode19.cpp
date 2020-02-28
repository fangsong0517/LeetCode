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
