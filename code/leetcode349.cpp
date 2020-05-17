/*************************************************************************
	> File Name: leetcode349.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 14时39分26秒
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ret;
       unordered_map<int , int>h;
       for(int i = 0; i < nums1.size(); i++) {
           h[nums1[i]] = 1;
       } 
       for(int i = 0; i < nums2.size() ; i++) {
           if(h.find(nums2[i]) == h.end())continue;
           if(h[nums2[i]] == 0)continue;
           ret.push_back(nums2[i]);
           h[nums2[i]] = 0;
       }
       return ret;
    }
};
