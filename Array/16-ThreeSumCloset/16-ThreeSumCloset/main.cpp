//
//  main.cpp
//  16-ThreeSumCloset
//
//  Created by zhoujian on 2019/11/16.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;



int threeSumCloset(vector<int>& nums, int target) {
    
    sort(nums.begin(), nums.end());
    int length = (int)nums.size();
    int diff = INT_MAX;
    int result = 0;
    for(int i = 0; i < length-2; i++) {
        int left = i+1;
        int right = length-1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int currentDif = abs(sum-target);
            if(currentDif < diff) {
                diff = currentDif;
                result = sum;
            }
            if(sum == target) {
                return target;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
//    vector<int> nums = {-1, 2, 1, -4};
    vector<int> nums = {0, 2, 1, -3};
    
    int sum = threeSumCloset(nums, 1);
    cout << sum << endl;
    return 0;
}
