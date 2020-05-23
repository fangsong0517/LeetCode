/*************************************************************************
	> File Name: leetcode200.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月23日 星期六 14时20分40秒
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
    struct UnionSet {
        int *fa, *cnt;
        UnionSet(int n) {
            fa = new int[n + 1];
            cnt = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                fa[i] = i;
                cnt[i] = 1;
            }
        }
        bool isroot(int x) {
            return x == fa[x];
        }
        int get(int x) {
            return (fa[x] = (x == fa[x] ? x : get(fa[x])));
        }
        void merge(int a, int b) { 
            int aa = get(a), bb = get(b);
            if (aa == bb) return ;
            fa[aa] = bb;
            cnt[bb] += cnt[aa];
            return ;
        }
        ~UnionSet() {
            delete[] fa;
            delete[] cnt;
        }
    };
    int n, m;
    int ind(int i, int j) {
        return (i * m) + j + 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        n = grid.size();
        m = grid[0].size();
        UnionSet u(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;
                if (i && grid[i - 1][j] == '1') u.merge(ind(i, j), ind(i - 1, j));
                if (j && grid[i][j - 1] == '1') u.merge(ind(i, j), ind(i, j - 1));
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;
                if (!u.isroot(ind(i, j))) continue;
                ans += 1;
            }
        }
        return ans;
    }
};
