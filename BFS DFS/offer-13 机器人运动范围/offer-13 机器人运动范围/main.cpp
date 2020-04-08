//
//  main.cpp
//  offer-13 机器人运动范围
//
//  Created by zhoujian on 2020/4/8.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "queue"

using namespace std;

/*
 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

int dir_x[4] = {-1, 1, 0, 0};
int dir_y[4] = {0, 0, -1, 1};

int mySum(int i, int j) {
    int res = 0;
    while(i > 0) {
        res += i%10;
        i = i/10;
    }
    while(j > 0) {
        res += j%10;
        j = j/10;
    }
    return res;
    
}
#pragma mark - BFS
int bfs(vector<vector<bool>> &visit, int m, int n, int i, int j, int k) {
    int count = 1;
    queue<pair<int, int>> q;
    q.push({i,j});
    visit[i][j] = true;
    while(q.size() > 0) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nextI = dir_x[i] + p.first;
            int nextJ = dir_y[i] + p.second;
            if(nextI >= 0 &&
               nextJ >= 0 &&
               nextI < m &&
               nextJ < n &&
               visit[nextI][nextJ] == false &&
               mySum(nextI,nextJ) <= k) {
                visit[nextI][nextJ] = true;
                count++;
                q.push({nextI, nextJ});
            }
        }
        
    }
    return count;
}
#pragma mark - DFS
int dfs(vector<vector<bool>> &visit, int m, int n, int i, int j, int k) {
    int count = 0;
    if(i >= 0 &&
       j >= 0 &&
       i < m &&
       j < n &&
       visit[i][j] == false &&
       mySum(i,j) <= k) {
        visit[i][j] = true;
        count = 1 + dfs(visit, m, n, i+1, j, k) +
        dfs(visit, m, n, i-1, j, k) +
        dfs(visit, m, n, i, j+1, k) +
        dfs(visit, m, n, i, j-1, k);
    }
    return count;
}
int movingCount(int m, int n, int k) {
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    return bfs(visit, m, n, 0, 0, k);
//    return dfs(visit, m, n, 0, 0, k); // 或者dfs
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
