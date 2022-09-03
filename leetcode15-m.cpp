#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	/*给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
	满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意不可以包含重复的三元组。
*/

    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            // 枚举 a
            for (int first = 0; first < n; ++first) {
                // 需要和上一次枚举的数不相同
                if (first > 0 && nums[first] == nums[first - 1]) {
                    continue;
                }
                // c 对应的指针初始指向数组的最右端
                int third = n - 1;
                int target = -nums[first];
                // 枚举 b
                for (int second = first + 1; second < n; ++second) {
                    // 需要和上一次枚举的数不相同
                    if (second > first + 1 && nums[second] == nums[second - 1]) {
                        continue;
                    }
                    // 需要保证 b 的指针在 c 的指针的左侧
                    while (second < third && nums[second] + nums[third] > target) {
                        --third;
                    }
                    // 如果指针重合，随着 b 后续的增加
                    // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                    if (second == third) {
                        break;
                    }
                    if (nums[second] + nums[third] == target) {
                        ans.push_back({ nums[first], nums[second], nums[third] });
                    }
                }
            }
            return ans;
        }
    };
	vector<int > nums= {-1, 0, 1, 2, -1, -4};
	Solution a;
    vector<vector<int>> ans=a.threeSum(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 3; j++) {
            printf("%d  ", ans[i][j]);
        }
        printf("\n");
    }
}