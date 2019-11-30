//
//  main.cpp
//  73-SetMatrixZeroes
//
//  Created by zhoujian on 2019/11/30.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 
 输入:
 [
   [1,1,1],
   [1,0,1],
   [1,1,1]
 ]
 输出:
 [
   [1,0,1],
   [0,0,0],
   [1,0,1]
 ]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/set-matrix-zeroes
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


/*
 两种解法
 */

// 时间复杂度：O（mn） 空间复杂度：O（m+n）
void setZeroes1(vector<vector<int>>& matrix) {
    
    int row = (int)matrix.size();
    int column = (int)matrix[0].size();
    
    // 用两个数组分别记录下值为0时的row,column
    vector<int> rowVec;
    vector<int> columnVec;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if(matrix[i][j] == 0) {
                rowVec.push_back(i);
                columnVec.push_back(j);
            }
        }
    }
    
    for(int m = 0; m < rowVec.size(); m++) {
        int value = rowVec[m];
        for(int i = 0 ; i < matrix[value].size(); i++) {
            matrix[value][i] = 0;
        }
    }
    for(int m = 0; m < columnVec.size(); m++) {
        int value = columnVec[m];
        for(int i = 0 ; i < matrix.size(); i++) {
            matrix[i][value] = 0;
        }
    }
}

// 时间复杂度：O（mn） 空间复杂度：O（1）
void setZeroes2(vector<vector<int>>& matrix) {
    
    bool row = false;//第一行是否需要置零
    bool column = false;//第一列是否需要置零
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 0){
                if( i == 0){
                    row = true;//第一行需要置零
                }
                if(j == 0){
                    column = true;//第一列需要置零
                }
                matrix[i][0] = 0;//第i行第一个元素置零，表示这一行需要全部置零
                matrix[0][j] = 0;//第j列第一个元素置零，表示这一列需要全部置零
            }
        }
    }
    for(int i = 1; i < matrix.size(); i ++){
        if(matrix[i][0] == 0){//第i行第一个元素为零，表示这一行需要全部置零
            for(int j = 1; j < matrix[i].size(); j++){
                matrix[i][j] = 0;
            }
        }
    }
    for(int j = 1; j < matrix[0].size(); j ++){
        if(matrix[0][j] == 0){//第j列第一个元素为零，表示这一列需要全部置零
            for(int i = 1; i < matrix.size(); i++){
                matrix[i][j] = 0;
            }
        }
    }
    if(row == true){//第一行需要置零
        for(int j = 1; j < matrix[0].size(); j++){
            matrix[0][j] = 0;
        }
    }
    if(column == true){//第一列需要置零
        for(int i = 1; i < matrix.size(); i++){
            matrix[i][0] = 0;
        }
    }
}
void cusPrintf(vector<vector<int>> res) {
    for(auto val:res) {
        for(auto val2:val) {
            cout << val2 << " ";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5},
    };
    setZeroes1(matrix);
    cusPrintf(matrix);
    return 0;
}
