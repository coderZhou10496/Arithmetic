//
//  main.cpp
//  695-岛屿的最大面积
//
//  Created by zhoujian on 2020/3/24.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "queue"
using namespace std;


/*
 给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。
 
 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
 
 作者：jsyt
 链接：https://leetcode-cn.com/problems/max-area-of-island/solution/js-dfs-yu-bfs-jie-fa-by-jsyt/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

#pragma mark - DFS
int dir_x[4] = {-1,1,0,0};
int dir_y[4] = {0,0,-1,1};
int dfs(vector<vector<int>> &grid, int row, int col) {
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
        return 0;
    }
    grid[row][col] = 0;
    int count = 1;
    for(int i = 0; i < 4; i++) {
        count += dfs(grid, row + dir_x[i], col + dir_y[i]);
    }
    return count;
}

int maxAreaOfIsland(vector<vector<int>> &grid) {
    if(grid.size() == 0) {
        return 0;
    }
    if(grid[0].size() == 0) {
        return 0;
    }
    int res = 0;
    for(int row = 0; row < grid.size(); row++) {
        for(int col = 0; col < grid[0].size(); col++) {
            res = max(res, dfs(grid, row, col));
        }
    }
    return res;
}

#pragma mark - BFS


int maxAreaOfIsland_solution2(vector<vector<int>> &grid) {
    if(grid.size() == 0) {
        return 0;
    }
    if(grid[0].size() == 0) {
        return 0;
    }
    int res = 0;
    queue<pair<int, int>> q;
    for(int row = 0; row < grid.size(); row++) {
        for(int col = 0; col < grid[0].size(); col++) {
            if(grid[row][col] == 1) {
                q.push({row, col});
                grid[row][col] = 0;
                
                int temp = 0;
                while (q.size() > 0) {
                    pair<int, int> front = q.front();
                    q.pop();
                    temp += 1;
                    for(int k = 0; k < 4; k++) {
                        int targetRow = front.first + dir_x[k];
                        int targetCol = front.second + dir_y[k];
                        if(targetRow >= 0 && targetRow < grid.size() && targetCol >= 0 && targetCol < grid[0].size() && grid[targetRow][targetCol] == 1) {
                            q.push({targetRow, targetCol});
                            grid[targetRow][targetCol] = 0;
                        }
                    }
                }
                res = max(temp, res);
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
//    vector<vector<int>> grid = {
//        {0,0,1,0,0,0,0,1,0,0,0,0,0},
//        {0,0,0,0,0,0,0,1,1,1,0,0,0},
//        {0,1,1,0,1,0,0,0,0,0,0,0,0},
//        {0,1,0,0,1,1,0,0,1,0,1,0,0},
//        {0,1,0,0,1,1,0,0,1,1,1,0,0},
//        {0,0,0,0,0,0,0,0,0,0,1,0,0},
//        {0,0,0,0,0,0,0,1,1,1,0,0,0},
//        {0,0,0,0,0,0,0,1,1,0,0,0,0}
//    };
    vector<vector<int>> grid = {
        {1,1,0,1,1,},
        {1,1,0,1,1,},
        {1,1,0,1,1,},
    };
    int res = maxAreaOfIsland_solution2(grid);
    cout << res << endl;
    return 0;
}
