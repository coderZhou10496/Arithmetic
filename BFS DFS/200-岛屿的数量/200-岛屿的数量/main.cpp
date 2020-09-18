//
//  main.cpp
//  200-岛屿的数量
//
//  Created by zhoujian on 2020/4/20.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "queue"
using namespace std;

int dir_x[4] = {-1,1,0,0};
int dir_y[4] = {0,0,-1,1};
/*
 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/number-of-islands
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#pragma mark - DFS
void dfs(vector<vector<char>> &grid,int i,int j) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    for(int index = 0; index < 4; index++) {
        dfs(grid, i+dir_x[index], j+dir_y[index]);
    }
}
int numIslands_DFS(vector<vector<char>>& grid) {
    if(grid.size() == 0) {
        return 0;
    }
    int rows = (int)grid.size();
    int cols = (int)grid[0].size();
    int res = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j]  == '1') {
                res++;
                dfs(grid, i, j);
            }
        }
    }
    return res;
    
}

#pragma mark - BFS
int numIslands_BFS(vector<vector<char>>& grid) {
    if(grid.size() == 0) {
        return 0;
    }
    queue<pair<int, int>> q;
    int rows = (int)grid.size();
    int cols = (int)grid[0].size();
    int res = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] - '0' == 1) {
                res++;
                q.push({i, j});
                grid[i][j] = 0;
                while(q.size() > 0) {
                    pair<int, int> p = q.front();
                    q.pop();
                    for(int i = 0; i < 4; i++) {
                        int nextI = p.first+dir_x[i];
                        int nextJ = p.second+dir_y[i];
                        if(nextI >= 0 && nextI < rows && nextJ >= 0 && nextJ < cols && grid[nextI][nextJ]-'0' == 1) {
                            grid[nextI][nextJ] = 0+'0';
                            q.push({nextI, nextJ});
                        }
                    }
                    
                }
            }
        }
    }
    return res;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
