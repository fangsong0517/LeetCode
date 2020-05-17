/*************************************************************************
	> File Name: leetcode35.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 14时19分59秒
 ************************************************************************/
int searchInsert(int* nums, int numsSize, int target){
    int l = 0, r = numsSize - 1, mid;
      while(l <= r) {
        mid = (l + r) >> 1;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] < target){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(target > nums[numsSize - 1]) {
        return numsSize;
    }
    if(target < nums[0]) return 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > target) return i;
    }
    return -1;
}
