/*************************************************************************
	> File Name: leetcode08.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月19日 星期二 19时33分52秒
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
    int myAtoi(string str) {
      int flag = 1, num = 0, i = 0, pre_max = INT_MAX / 10, d = INT_MAX % 10;
      while(str[i] == ' ') i++;
      if(str[i] == '-')flag = -1, ++i;
        else if(str[i] == '+');
        num = num * 10 + (str[i] - '0');
        　return flag == 1? INT_MAX : INT_MIN;
          i++;
      }
        return num * flag;
    }
};

