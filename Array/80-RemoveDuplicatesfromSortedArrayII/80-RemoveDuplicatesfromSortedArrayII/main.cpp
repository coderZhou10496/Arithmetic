//
//  main.cpp
//  80-RemoveDuplicatesfromSortedArrayII
//
//  Created by zhoujian on 2019/12/4.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 
 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
 
 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 
 示例 1:
 
 给定 nums = [1,1,1,2,2,3],
 
 函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
 
 你不需要考虑数组中超出新长度后面的元素。
 示例 2:
 
 给定 nums = [0,0,1,1,1,1,2,3,3],
 
 函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
 
 你不需要考虑数组中超出新长度后面的元素。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

int removeDuplicates(vector<int>& nums) {
    
    if(nums.size() == 0) {
        return 0;
    }
    int result = 0;
    bool repeat = false;
    
    for(int i = 0; i < nums.size(); i++) {
        
        if(!repeat || nums[i] != nums[i-1]) {
            
            if(i > 0 && nums[i] == nums[i-1]) {
                repeat = true;
            }
            else {
                repeat = false;
            }
            
            nums[result] = nums[i];
            result++;

        }
        else {
            repeat = true;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {0, 0, 1, 1, 2, 3, 3};
    int res = removeDuplicates(nums);
    cout << res << endl;
    cout << endl;
    for(auto val : nums) {
        cout << val << " ";
    }
    
    return 0;
}
