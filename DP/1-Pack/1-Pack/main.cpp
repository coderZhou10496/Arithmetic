//
//  main.cpp
//  1-Pack
//
//  Created by zhoujian on 2020/1/6.
//  Copyright © 2020 zhoujian. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

//求恰好装满背包，初始化B[0] = 0,其他都是-∞。
//若是求最大价值，初始化B[0-N]都是0。

#pragma mark -- 01背包
int func1() {
    
    /*
    容量为8的背包，有4种物品，每种物品只有一个，其重量分别为2,3,4,5，其价值分别为3,4,5,6。
    设计算法，实现背包内物品价值最大。
     */
    
    int total_weight = 8;
    vector<int> w = { 0,2,3,4,5};
    vector<int> v = { 0,3,4,5,6};
//    vector<vector<int>> dp(v.size(), vector<int>(total_weight+1,0));
//    for(int i = 1; i <= v.size()-1; i++) {
//        for(int j = 1; j <= total_weight; j++) {
//            if(j < w[i]) {
//                dp[i][j] = dp[i-1][j];
//            }
//            else {
//                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
//            }
//        }
//    }
//    for(auto arr : dp) {
//        for(auto sec : arr) {
//            cout << sec << ' ';
//        }
//        cout << endl;
//    }
//    return dp[w.size()-1][total_weight];
    
    
    
//    // 可优化为一维DP
    /*
     这里的j为什么要逆序，是为了保证包里的物品每次只能取一次。举个例子，假如正序遍历，(j=w[i];j <= total_weight;j++)
     w = {0,2,3,4};
     v = {0,1000,1,2};
     当j=2时，dp[j=2] = 1000;
     当j=4时，dp[j=4] = dp[4-2] + 1000 = 2000,即这个物品取了2次。逆序遍历可以避免这种情况
     
     */
    vector<int> dp(total_weight+1, 0);
    for(int i = 1; i <= v.size()-1; i++) {
        for(int j = total_weight; j >= w[i]; j--) {

            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            cout << "i:" << i << " " << "j:" << " " << j << "  " << dp[j] << endl;
        }
    }
    return dp[total_weight];
     
}

#pragma mark -- 完全背包
int func2() {
    
    /*
     容量为8的背包，有4种物品，每种物品无限个，其重量分别为2,3,4,5，其价值分别为3,4,5,6。
     设计算法，实现背包内物品价值最大。
     */
    /*
     题解：
     
     如果不选，则：dp[i][j] = dp[i-1][j]；
     如果选了，遍历一下选择的数量，这里最大数量为j/w[i], dp[i][j] = dp[i-1][j-k*w[i]] + k*v[i];
     
     dp[i][j] = max(dp[i-1][j], dp[i-1][j-k*w[i]] + k(v[i]);
     */
    int total_weight = 8;
    vector<int> w = { 0,2,3,4,5};
    vector<int> v = { 0,3,4,5,6};
    vector<vector<int>> dp(v.size(), vector<int>(total_weight+1,0));
    for(int i = 1; i <= v.size()-1; i++) {
        for(int j = w[i]; j <= total_weight; j++) {
            for(int k = 1; k <= j/w[i]; k++) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-k*w[i]] + k*v[i]);
            }
        }
    }
    /*
     实际当前i的所有状态都只依赖于i-1，所以上面的二维数组很容易优化到一维,即3个for循环，一维数组
     注：这里第二个for循环，反着写 total_weight -> w[i]，也是没有问题的
     */
//    for(int i = 1; i <= v.size()-1; i++) {
//        for(int j = w[i]; j <= total_weight; j++) {
//            for(int k = 1; k <= j/w[i]; k++) {
//                dp[j] = max(dp[j], dp[j-k*w[i]] + k*v[i]);
//            }
//        }
//    }
    
//    // 也可为2个for循环，这里若取了1件第i个物品，则总容量变为j-W[i]，剩下的仍可以在前i件物品中去取，其最大总价值为dp[i][j-W[i]] + v[i]；
//    for(int i = 1; i <= v.size()-1; i++) {
//        for(int j = w[i]; j <= total_weight; j++) {
//            dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]] + v[i]);
//        }
//    }
    for(auto arr : dp) {
        for(auto sec : arr) {
            cout << sec << ' ';
        }
        cout << endl;
    }
    return dp[w.size()-1][total_weight];
    
    /*
     // 可优化为一维DP
     vector<int> dp(total_weight+1, 0);
     for(int i = 1; i <= v.size()-1; i++) {
      for(int j = w[i]; j <= total_weight ; j++) { // 这里是与01背包的唯一区别，这里是正序的。
          dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
         }
     }
     return dp[total_weight];
     */
}
int main(int argc, const char * argv[]) {
    int res = func1();
    cout << "01背包：" << res << endl;
    cout << endl;
    return 0;
}
