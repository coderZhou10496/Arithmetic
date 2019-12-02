//
//  main.cpp
//  75-SortColors
//
//  Created by zhoujian on 2019/12/2.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 
 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 
 注意:
 不能使用代码库中的排序函数来解决这道题。
 
 示例:
 
 输入: [2,0,2,1,1,0]
 输出: [0,0,1,1,2,2]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sort-colors
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


// 使用三个指针

void sortColors(vector<int>& nums) {
    
    int length = (int)nums.size();
    if(length == 0) {
        return;
    }
    int left = 0; // 表示0的最右边界
    int right = length-1; // 表示2的最左边界
    int current = 0;
    
    while (current <= right) {
        if(nums[current] == 0) {
            swap(nums[current], nums[left]);
            left++;
            current++;
        }
        else if (nums[current] == 1)  {
            current++;
        }
        else {
            swap(nums[current], nums[right]);
            right--;
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,0,2,1,0,0,0,0};
    sortColors(nums);
    for(auto val : nums) {
        cout << val;
    }
    cout << endl;

    return 0;
}
