/*************************************************************************
	> File Name: 203.leetcode.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年02月27日 星期四 21时23分11秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode ret, *p , *q;
    ret.next = head;
    p = &ret;
    while(p && p->next) {
        if(p->next ->val== val) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return ret.next;
}
