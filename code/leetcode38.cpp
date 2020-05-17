/*************************************************************************
	> File Name: leetcode38.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 14时26分59秒
 ************************************************************************/
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return string ("1");
        string pre_str = countAndSay(n - 1);
        char str[10000];
        int ret = 0, num = pre_str[0], cnt = 1;
        for(int i = 1; pre_str[i]; i++) {
            if(pre_str[i] == num) cnt += 1;
            else {
                ret += sprintf(str + ret, "%d%c", cnt, num);
                num = pre_str[i];
                cnt = 1;
            }
        }
                ret += sprintf(str + ret, "%d%c", cnt, num);
                return str;
    }
};
