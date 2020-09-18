//
//  main.cpp
//  1-TwoSum
//
//  Created by zhoujian on 2019/11/15.
//  Copyright © 2019 zhoujian. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    
    map<int, int> m; // key为值，value为索引
    
    vector<int> result;
    
    for(int i = 0; i < nums.size(); i++) {

        if(m.count(target-nums[i])) {
            result.push_back(m[target-nums[i]]);
            result.push_back(i);
            return result;
        }
        else {
            m[nums[i]] = i;
        }
    }
    return result;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {2,4,5,4,2,1};
    vector<int> result = twoSum(nums, 6);
    for(vector<int>::iterator iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}
