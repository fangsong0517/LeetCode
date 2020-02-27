/*************************************************************************
	> File Name: 287.leetcode.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年02月27日 星期四 21时24分56秒
 ************************************************************************/
/*int findDuplicate(int* nums, int numsSize){
    int k = 0, m = 0;
    while(1) {
        k = nums[nums[k]];
        m = nums[m];
        if(k == m) {
            k = 0;
            while(nums[k] != nums[m]) {
                k = nums[k];
                m = nums[m];
            }
            return nums[m];
        }
    }
}*/
int findDuplicate(int* nums, int numsSize){
    int p = nums[0], q = nums[0];
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while(p != q);
    q = nums[0];
    while(p!=q) {
        p = nums[p];
        q = nums[q];
    }
    return p;
}
