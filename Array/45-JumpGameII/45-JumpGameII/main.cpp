//
//  main.cpp
//  45-JumpGameII
//
//  Created by zhoujian on 2019/11/24.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;
/*
 给定一个非负整数数组，你最初位于数组的第一个位置。
 
 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 
 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 
 示例:
 
 输入: [2,3,1,1,4]
 输出: 2
 解释: 跳到最后一个位置的最小跳跃数是 2。
      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/jump-game-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

int jump(vector<int>& nums) {
    if(nums.size() <= 1) {
        return 0;
    }
    int length = (int)nums.size() - 1;
    int index = 0;
    int res = 0;
    while (index <= length) {
        if(index + nums[index] >= length) {
            return ++res;
        }
        
        int max = -1;
        int tempIndex = -1;
        for(int i = index+1; i <= index + nums[index]; i++) {
            if(i + nums[i] > max) {
                max = i + nums[i];
                tempIndex = i;
            }
        }
        index = tempIndex;
        res++;
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,3,1,1,4};
    int res = jump(nums);
    cout << res << endl;
    
    return 0;
}
