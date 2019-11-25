//
//  main.cpp
//  48-RotateImage
//
//  Created by zhoujian on 2019/11/25.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 rotate1题解：
 第一步：按照 左上--右下 对角线翻转数组
 第二部：根据中线左右翻转数组
 */

void cusPrint(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        vector<int> v = matrix[i];
        for(int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotate1(vector<vector<int>>& matrix) {
    
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = i+1; j < matrix.size(); j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.size()/2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrix.size()-1-j];
            matrix[i][matrix.size()-1-j] = temp;
        }
    }

}

void rotate2(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - 1 - i; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
        }
    }
}
int main(int argc, const char * argv[]) {
    
    vector<vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15,14,12, 16}
    };
    rotate2(matrix);
    cusPrint(matrix);
    return 0;
}
