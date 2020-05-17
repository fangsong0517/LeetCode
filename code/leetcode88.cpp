/*************************************************************************
	> File Name: leetcode88.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 14时34分22秒
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
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0, j = 0;
    int t = n + m;
    int temp[1500], k = 0;
    while(i <= m - 1 && j <= n - 1) {
        if(nums1[i] < nums2[j]) {
            temp[k++] = nums1[i];
            i++;
        } else {
            temp[k++] = nums2[j];
            j++;
        }
    }
    while(i<=m - 1)temp[k++] = nums1[i ++];
    while(j<=n - 1)temp[k++] = nums2[j++];
    for(int i = 0, j = 0; i < k; i++, j++) {
        nums1[i] = temp[j];
    }
}
