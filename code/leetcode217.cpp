/*************************************************************************
	> File Name: leetcode217.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 14时35分27秒
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
/*#define swap(a, b) {\
__typeof(a) __temp = a;\
a = b; b = __temp;\
}
void quick_sort(int *nums, int l, int r) {
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = nums[(l + r) >> 1];
    while(i < j) {
        do i++; while(nums[i] < x);
        do j --; while(nums[j] > x);
        if(i < j) swap(nums[i], nums[j]);
    }
    quick_sort(nums, l, j), quick_sort(nums, j + 1, r);
}
*/
int CompareInt(const void *p1, const void *p2)
{
    return (*(int *)p1) - (*(int *)p2);
}

bool containsDuplicate(int* nums, int numsSize){
 //   quick_sort(nums, 0, numsSize - 1);
    /*for(int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }*/
    qsort(nums, numsSize, sizeof(int), CompareInt);
    for(int i = 1; i < numsSize; i++ ) {
        if(nums[i] == nums[i - 1]) {
         return true;   
        }
    }
    return false;
}
