//
//  main.cpp
//  79-WordSearch
//
//  Created by zhoujian on 2019/12/3.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;


/*
 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 
 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 
 示例:
 
 board =
 [
 ['A','B','C','E'],
 ['S','F','C','S'],
 ['A','D','E','E']
 ]
 
 给定 word = "ABCCED", 返回 true.
 给定 word = "SEE", 返回 true.
 给定 word = "ABCB", 返回 false.
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/word-search
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//
bool judgeCore(vector<vector<char>> &board, vector<vector<int>> &record, int rowIndex, int columnIndex, int row, int column, string word, int &stringIndex) {
    if(stringIndex == word.length()) {
        return true;
    }
    
    if(rowIndex < row &&
       rowIndex >= 0 &&
       columnIndex < column &&
       columnIndex >= 0 &&
       record[rowIndex][columnIndex] == 0 &&
       word[stringIndex] == board[rowIndex][columnIndex]) {
        stringIndex++;
        record[rowIndex][columnIndex] = 1;
        
        
        bool result =
        judgeCore(board, record, rowIndex+1, columnIndex, row, column, word, stringIndex) ||
        judgeCore(board, record, rowIndex-1, columnIndex, row, column, word, stringIndex) ||
        judgeCore(board, record, rowIndex, columnIndex+1, row, column, word, stringIndex) ||
        judgeCore(board, record, rowIndex, columnIndex-1, row, column, word, stringIndex);
        if(result == false) {
            stringIndex--;
            record[rowIndex][columnIndex] = 0;
        }
                      
        return result;
    }
    
    
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    if(word.size() == 0) {
        return false;
    }
    int row = (int)board.size();
    if(row == 0) {
        return false;
    }
    int column = (int)board[0].size();
    if(column == 0) {
        return false;
    }
    
    int start = 0;
    vector<vector<int>> record(row, vector<int>(column, 0));
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if(board[i][j] == word[0]) {
                bool result = judgeCore(board, record, i, j, row, column, word, start);
                if(result == true) {
                    return result;
                }
            }
        }
    }

    return false;
    
}

// 此方法是别人AC的，原矩阵内直接处理
bool backtrack(vector<vector<char>>& board,string word,int i,int x,int y)
{
    if(x<0||x==board.size()||y<0||y==board[0].size())return false;    //超过递归边界
    if(board[x][y]=='#'||board[x][y]!=word[i])return false;        //递归方向不对
    if(i==word.size()-1)return true;                //已经找到单词，递归结束
    
    //choose过程：加入决策路径
    char temp=board[x][y];
    board[x][y]='#';
    
    //进入下一步决策
    bool flag=  backtrack(board,word,i+1,x-1,y)||backtrack(board,word,i+1,x+1,y)
    ||backtrack(board,word,i+1,x,y-1)||backtrack(board,word,i+1,x,y+1);
    
    //unchoose：移除决策
    board[x][y]=temp;
    return flag;
}

bool exist2(vector<vector<char>>& board, string word) {
    for(int x=0;x<board.size();++x)
    {
        for(int y=0;y<board[0].size();++y)
            if(board[x][y] == word[0]) {
                if(backtrack(board,word,0,x,y))
                    return true;
            }
            
    }
    return false;
}



int main(int argc, const char * argv[]) {
    
//    给定 word = "ABCCED", 返回 true.
//    给定 word = "SEE", 返回 true.
//    给定 word = "ABCB", 返回 false.
    
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";


    bool res = exist(board, word);
    cout << res << endl;

    
    return 0;
}
