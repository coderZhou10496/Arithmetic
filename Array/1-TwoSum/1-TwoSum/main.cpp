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
    
    map<int, int> m;
    
    vector<int> result;
    
    map<int, int>::iterator iter;
    
    for(int i = 0; i < nums.size(); i++) {
        
        iter = m.find(target-nums[i]);
        
        if(iter != m.end()) {
            result.push_back(iter->second);
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
    vector<int> nums = {2,7,11,5};
    vector<int> result = twoSum(nums, 18);
    for(vector<int>::iterator iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}
