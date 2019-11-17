//
//  main.cpp
//  27-RemoveElement
//
//  Created by zhoujian on 2019/11/17.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;
/*
 
链接：https://leetcode-cn.com/problems/remove-element
 
 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
 
 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 
 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 
 示例 1:
 
 给定 nums = [3,2,2,3], val = 3,
 
 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
 
 你不需要考虑数组中超出新长度后面的元素。
 示例 2:
 
 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
 
 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
 
 注意这五个元素可为任意顺序。
 
 你不需要考虑数组中超出新长度后面的元素。

 */

/*
 此解法提交后，时间复杂度击败了100.00%的用户，我惊呆了(应该不是lc的bug？)
 其他解法：
 https://blog.csdn.net/qq_33168253/article/details/79751414
 https://blog.csdn.net/ma_chen_qq/article/details/80501367
 */

int removeElement(vector<int>& nums, int val) {
    
    int resultLength = 0;
    bool need = false;
    for(int i = 0; i < nums.size(); i++) {
        
        if(nums[resultLength] == val) {
            need = true;
        }
        else {
            need = false;
        }
        
        if(!need) {
            resultLength++;
        }
        else {
            if(nums[i] != val) {
                int temp = nums[i];
                nums[i] = nums[resultLength];
                nums[resultLength] = temp;
                
                resultLength++;
            }
        }
    }
    return resultLength;
}

int main(int argc, const char * argv[]) {
    
        vector<int> nums = {1,1,1};
//        vector<int> nums = {0,1,2,2,3,0,4,2};
//    vector<int> nums = {3,2,2,3};
    int result = removeElement(nums, 2);
    
    cout << "result:" << result << endl;
    for(int i = 0; i < result; i++) {
        cout << nums[i] << endl;
    }
    
    return 0;
}
