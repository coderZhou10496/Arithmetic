//
//  main.cpp
//  66-PlusOne
//
//  Created by zhoujian on 2019/11/30.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 
 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 
 你可以假设除了整数 0 之外，这个整数不会以零开头。
 
 示例 1:
 
 输入: [1,2,3]
 输出: [1,2,4]
 解释: 输入数组表示数字 123。
 示例 2:
 
 输入: [4,3,2,1]
 输出: [4,3,2,2]
 解释: 输入数组表示数字 4321。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/plus-one
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

vector<int> plusOne(vector<int>& digits) {
    
    // 这个是LeetCode别人的写法， 非常简洁
    int len = (int)digits.size();
    for(int i=len-1;i>=0;i--){
        if(digits[i]!=9){
            digits[i]++;
            return digits;
        }else{
            digits[i]=0;
        }
    }
    digits.insert(digits.begin(),1);
    return digits;
    
    
    // 这个是我自己的写的，也能AC
    
//    int needAdd = 0;
//    for(int i = (int)digits.size()-1; i >=0 ;i--) {
//
//        int value = digits[i] + needAdd;
//        if(i == digits.size()-1) {
//            value += 1;
//        }
//        needAdd = value/10;
//        digits[i] = value%10;
//
//        if(needAdd == 0) {
//            break;
//        }
//    }
//
//    if(needAdd == 1) {
//        digits.insert(digits.begin(), needAdd);
//    }
//
//    return digits;
    
}
int main(int argc, const char * argv[]) {
    vector<int> nums = {9,9,9,8};
    vector<int> res = plusOne(nums);
    for(auto val : res) {
        cout << val;
    }
    cout << endl;
    return 0;
}
