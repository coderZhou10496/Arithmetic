//
//  main.cpp
//  127-单词接龙
//
//  Created by zhoujian on 2020/3/28.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "unordered_map"
#include "queue"
using namespace std;

/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。

*/
#pragma mark - BFS
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int len = (int)beginWord.size();
    unordered_map<string,vector<string>> mmap;
    for(string s:wordList){  ////建立邻接表
        for(int i=0; i<len; ++i){
            //截取字符串
            string newWord = s.substr(0,i)+ '*' + s.substr(i+1,len);
            mmap[newWord].push_back(s);
        }
    }
    
    queue<pair<string,int>> q;
    q.push(make_pair(beginWord,1));
    unordered_map<string,bool> visited;  //访问过的进行标记
    visited[beginWord] = true;
    while(!q.empty()){
        pair<string,int> node = q.front();
        q.pop();
        string word = node.first;
        int level = node.second;
        if(word == endWord) return level;
        
        // 找出currentWord的所有通用状态
        for(int i = 0; i < len; ++i){
            string newWord = word.substr(0,i)+ '*' + word.substr(i+1,len);
            vector<string> array = mmap[newWord];
            for(string adjacentWord:array){
                if(visited.find(adjacentWord) == visited.end()){  //未访问过
                    visited[adjacentWord] = true;
                    q.push(make_pair(adjacentWord,level+1));
                    
                }
            }
        }
    }
    return 0;
    
}
int main(int argc, const char * argv[]) {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int res = ladderLength(beginWord, endWord, wordList);
    cout << res << endl;
    return 0;
}
