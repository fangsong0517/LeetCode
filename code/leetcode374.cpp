/*************************************************************************
	> File Name: leetcode374.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 14时50分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(n == 1) return 1;
        int l  = 1, r =  n;
        while(l <= r) {
            int mid = ((l ^ r) >> 1) + (l & r);
 //         int mid = l + (r - l) / 2;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == -1) r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }
};
