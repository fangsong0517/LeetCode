/*************************************************************************
	> File Name: leetcode28.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月19日 星期二 20时34分13秒
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
class Solution {
public:
    int strStr(string haystack, string needle) {
       int ind[256];
        for(int i = 0; i < 265; i++) ind[i] = needle.size() + 1;
        for(int i = 0; needle[i]; i++) {
            ind[needle[i]] = needle.size() - i;
        }
        for(int i = 0, I = haystack.size() - needle.size(); i <= I;) {
            int  j = 0;
            for(; needle[j]; j++) {
                if(haystack[i + j] == needle[j])continue;
                i += ind[haystack[i + needle.size()]];
                break;
            } 
            if(needle[j] == 0)return i;
        }
        return -1;
    }
};
