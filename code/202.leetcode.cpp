/*************************************************************************
	> File Name: 202.leetcode.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年02月27日 星期四 21时22分35秒
 ************************************************************************/
//如果给定的数字最后会一直循环重复，那么快的指针（值）一定会追上慢的指针（值），也就是
//两者一定会相等。如果没有循环重复，那么最后快慢指针也会相等，且都等于1。
int get_next(int n) {
    int temp = 0;
    while(n) {
        temp+= (n % 10) * ( n % 10);
        n /= 10;
    }
    return temp;
}
bool insHappy(int n) {
    int p = n, q = n;
    while(q != 1) {
        p = get_next(p);
        q = get_next(get_next(q));
        if(p == q) break;
    }
    return q == 1;
}
