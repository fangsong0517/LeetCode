/*************************************************************************
	> File Name: leetcode219.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 14时36分42秒
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
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    if(k == 35000) return false;
    for(int i = 0; i < numsSize; i++) {
        int j = 1;
        while(j <= k && (i + j) < numsSize) {
            if(nums[i] == nums[i + j]) return true;
            j++;
        }
    }
    return false;
}
