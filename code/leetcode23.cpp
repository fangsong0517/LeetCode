/*************************************************************************
	> File Name: leetcode23.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月16日 星期六 18时45分16秒
 ************************************************************************/
class Solution {
public:
    typedef pair<int, ListNode *> PIL;
    typedef pair<int, PIL> PIP;
    set<PIP> s;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL) continue;
            s.insert(PIP(lists[i]->val, PIL(i, lists[i])));
            lists[i] = lists[i]->next;
        }
        ListNode ret, *p = &ret;
        ret.next = NULL;
        while (s.size()) {
            PIP temp = *s.begin();
            s.erase(s.begin());
            p->next = temp.second.second;
            p = p->next;
            int i = temp.second.first;
            if (lists[i] == NULL) continue;
            s.insert(PIP(lists[i]->val, PIL(i, lists[i])));
            lists[i] = lists[i]->next;
        }
        return ret.next;
    }
};
