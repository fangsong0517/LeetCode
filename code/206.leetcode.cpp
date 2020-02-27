/*************************************************************************
	> File Name: 206.leetcode.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年02月27日 星期四 21时23分31秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

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
