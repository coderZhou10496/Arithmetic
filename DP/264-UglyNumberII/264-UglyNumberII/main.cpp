//
//  main.cpp
//  264-UglyNumberII
//
//  Created by zhoujian on 2019/12/14.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
#include "queue"
using namespace std;

/*
 编写一个程序，找出第 n 个丑数。
 
 丑数就是只包含质因数 2, 3, 5 的正整数。
 
 示例:
 
 输入: n = 10
 输出: 12
 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 说明:
 
 1 是丑数。
 n 不超过1690。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/ugly-number-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
int nthUglyNumber(int n) {
    
    vector<int> v;
    v.push_back(1);
    
    int i_2 = 0, i_3 = 0, i_5 = 0;
    int index = 1;
    int result = 0;
    while (index < n) {
        result = min(min(2 * v[i_2], 3 * v[i_3]), 5 * v[i_5]);
        v.push_back(result);
        if(result == 2 * v[i_2]) {
            i_2++;
        }
        if(result == 3 * v[i_3]) {
            i_3++;
        }
        if(result == 5 * v[i_5]) {
            i_5++;
        }
        index++;
    }
    return v[n-1];
}

int nthUglyNumber_solution2(int n) {

    if(n == 1) {
        return 1;
    }
    queue<int> q2;
    queue<int> q3;
    queue<int> q5;
    
    q2.push(2);
    q3.push(3);
    q5.push(5);
    
    int index = 1;
    int result = 0;
    while (index < n) {
        result = min(min(q2.front(), q3.front()),q5.front());
        if(result == q2.front()) {
            q2.pop();
            q2.push(result * 2);
            q3.push(result * 3);
            q5.push(result * 5);
        }
        if(result == q3.front()) {
            q3.pop();
            q3.push(result * 3);
            q5.push(result * 5);
        }
        if(result == q5.front()) {
            q5.pop();
            q5.push(result * 5);
        }
        index++;
    }
    return result;

}

int main(int argc, const char * argv[]) {
    
    for(int i = 1; i < 20; i++) {
        cout << nthUglyNumber(i) << endl;
    }
    
    return 0;
}
