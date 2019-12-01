//
//  main.cpp
//  74-Search2DMatrix
//
//  Created by zhoujian on 2019/12/1.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;
/*
 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 
 每行中的整数从左到右按升序排列。
 每行的第一个整数大于前一行的最后一个整数。
 示例 1:
 
 输入:
 matrix = [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 target = 3
 输出: true
 示例 2:
 
 输入:
 matrix = [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 target = 13
 输出: false
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/search-a-2d-matrix
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = (int)matrix.size();
    if(row == 0) {
        return false;
    }
    int column = (int)matrix[0].size();
    if(column == 0) {
        return false;
    }
    int begin = 0;
    int end = row-1;
    int mid = 0;
    int resultRow = -1;
    while (begin <= end) {
        mid = (begin+end)/2;
        vector<int> temp =matrix[mid];
        int value = temp[column-1];
        if(value == target) {
            return true;
        }
        else if(value > target) {
            resultRow = mid;
            end = mid-1;
        }
        else {
            begin = mid+1;
        }
    }
    if(resultRow == -1) {
        return false;
    }
    
    begin = 0;
    end = (int)matrix[resultRow].size()-1;
    while (begin <= end) {
        mid = (begin+end)/2;
        int value = matrix[resultRow][mid];
        if(value == target) {
            return true;
        }
        else if(value > target) {
            end = mid-1;
        }
        else {
            begin = mid+1;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    bool res = searchMatrix(matrix, 10);
    cout << res << endl;
    return 0;
}
