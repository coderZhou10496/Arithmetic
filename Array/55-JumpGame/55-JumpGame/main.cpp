//
//  main.cpp
//  55-JumpGame
//
//  Created by zhoujian on 2019/11/27.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

/*
 给定一个非负整数数组，你最初位于数组的第一个位置。
 
 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 
 判断你是否能够到达最后一个位置。
 
 示例 1:
 
 输入: [2,3,1,1,4]
 输出: true
 解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
 示例 2:
 
 输入: [3,2,1,0,4]
 输出: false
 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/jump-game
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */


/*
 题解1：
 如果倒数第二个格子可以跳到最后的格子上，说明这个格子是有效的格子；
 如果倒数第三个格子可以跳到倒数第二个格子上，说明这个格子是也是有效的格子；
 不断更新有效的格子索引
 */
bool canJump1(vector<int>& nums) {
    
    int leftPoint = (int)nums.size()-1;
    
    for(int index = (int)nums.size()-2; index >= 0; index--){
        if(nums[index]+index >= leftPoint){
            leftPoint=index;
        }
    }
    
    return leftPoint==0?1:0;
    
}

/*
  题解2：
 如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
 可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
 如果可以一直跳到最后，就成功了。
 */
bool canJump2(vector<int>& nums) {
    
    int k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > k) return false;
        k = max(k, i + nums[i]);
    }
    return true;
    
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {2,3,1,1,4};
    vector<int> nums2 = {3,2,1,0,4};
    bool res1 = canJump1(nums);
    bool res2 = canJump1(nums2);
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}
