//
//  main.cpp
//  1162-地图分析
//
//  Created by zhoujian on 2020/3/29.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "queue"
using namespace std;


/*
 你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
 
 我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
 
 如果我们的地图上只有陆地或者海洋，请返回 -1。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

/*
 这道题主要是理解转换，将所有的陆地看成一个整体，去填充海洋，求多少步能将海洋填满。
 思路跟腐烂的橘子一模一样
 */

#pragma mark - BFS 解法一

int dir_x[4] = {-1,1,0,0};
int dir_y[4] = {0,0,-1,1};

int maxDistance(vector<vector<int>>& grid) {
    
    int rows = (int)grid.size();
    int cols = (int)grid[0].size();
    queue<pair<int, int>> q;
    for(int row = 0; row < grid.size(); row++) {
        for(int col = 0; col < grid[0].size(); col++) {
            if(grid[row][col] == 1) {
                q.push({row, col});
            }
        }
    }
    if(q.size() == 0 || q.size() == rows * cols) {
        return -1;
    }
    
    int res = -1; // 这里要从-1开始，因为这里已经是陆地了
    while(q.size() > 0) {
        int size = (int)q.size();
        res++;
        for(int j = 0; j < size; j++) {
            pair<int ,int> p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nextRow = p.first + dir_x[i];
                int nextCol = p.second + dir_y[i];
                if(nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && grid[nextRow][nextCol] == 0) {
                    grid[nextRow][nextCol] = 1;
                    q.push(make_pair(nextRow, nextCol));
                }
            }
        }
    }
    return res;
    
}

#pragma mark - BFS 解法二

int maxDistance_2(vector<vector<int>>& grid) {
    
    int rows = (int)grid.size();
    int cols = (int)grid[0].size();
    queue<pair<int, int>> q;
    for(int row = 0; row < grid.size(); row++) {
        for(int col = 0; col < grid[0].size(); col++) {
            if(grid[row][col] == 1) {
                q.push({row, col});
            }
        }
    }
    if(q.size() == 0 || q.size() == rows * cols) {
        return -1;
    }
    
    int res = 0;
    while(q.size() > 0) {

        pair<int ,int> p = q.front();
        q.pop();
        res = grid[p.first][p.second];
        for(int i = 0; i < 4; i++) {
            int nextRow = p.first + dir_x[i];
            int nextCol = p.second + dir_y[i];
            if(nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && grid[nextRow][nextCol] == 0) {
                grid[nextRow][nextCol] = res+1;
                q.push(make_pair(nextRow, nextCol));
            }
        }
    }
    return res-1;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
