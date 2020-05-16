/*************************************************************************
	> File Name: leetcode703.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月16日 星期六 18时09分30秒
 ************************************************************************/

/*class KthLargest {
    priority_queue<int, vector<int>, greater<int>> s;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }

    int add(int val) {
        if(s.size() < n) {
            s.push(val);
        } else if(val > s.top()) {
            s.pop();
            s.push(val);
        }
        return s.top();
    }
};
*/
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class KthLargest {
public:
    typedef pair<int, int>PII;
    set<PII>s;
    int k, t;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->t = 0;
        for(int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
        return;
    }

    int add(int val) {
        if(s.size() < k) {
            s.insert(PII(val, t++));
        } else if(val > s.begin()->first) {
            s.erase(s.begin());
            s.insert(PII(val, t++));
        }
        return s.begin()->first;
    }
};
