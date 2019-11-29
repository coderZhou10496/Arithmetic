//
//  main.cpp
//  63-UniquePathsII
//
//  Created by zhoujian on 2019/11/29.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 
 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 
 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/unique-paths-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
void cusPrintf(vector<vector<int>> res) {
    for(auto val:res) {
        for(auto val2:val) {
            cout << val2 << " ";
        }
        cout << endl;
    }
}
/*
 提示：用long接收，否则leetcode上不会AC
 */
long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    
    if(obstacleGrid.size() == 0) {
        return 0;
    }
    int row = (int)obstacleGrid.size();
    int column = (int)obstacleGrid[0].size();
    
    vector<vector<long>> res(row, vector<long>(column, 0));

    for(int i = 0; i < row; i++) {
        if(obstacleGrid[i][0] == 0) {
            res[i][0] = 1;
        }
        else {
            break;
        }
    }
    for(int i = 0; i < column; i++) {
        if(obstacleGrid[0][i] == 0) {
            res[0][i] = 1;
        }
        else {
            break;
        }
    }

    for(int i = 1; i < row; i++) {
        for(int j = 1; j < column; j++) {
            if(obstacleGrid[i][j] == 1) {
                res[i][j] = 0;
            }
            else {
                res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
    }
    return res[row-1][column-1];
}


int main(int argc, const char * argv[]) {
    
    /*
     0 0 0 0 0
     0 0 1 0 0
     0 0 0 0 0
     */
    vector<vector<int>> grid(3, vector<int>(3, 0));
    grid[1][1] = 1;

    cusPrintf(grid);
    

    
    long res = uniquePathsWithObstacles(grid);
    
    
    cout << endl;
    
    cout << res << endl;
    return 0;
}
