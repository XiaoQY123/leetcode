#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
/*给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。
*/
    //错误实现;只考虑了贪心，返回大小转变时的两对数，实际上，当转变之后，可以逼近更小的数。
    //通过132/161:（真的无语了，怎么通过了这么多啊，你要是只通过几个，我倒还不会搞这么久才知道我的思考方法都错了）
    //对两边变号的判断，利用了两个flage来表示状态位。
    //对变号两边的数，进行了逻辑思考，利用c状态位来发现变化的值的取
    //class Solution {
    //public:
    //    int threeSumClosest(vector<int>& nums, int target) {
    //        sort(nums.begin(), nums.end());
    //        bool flage1 = 1,flage2=1;
    //        int i, j, k, a1, result = 10001;
    //        int a, b,c=0;
    //        int minnums = 0;
    //        for (i = 0; i < nums.size() - 2; i++)
    //        {
    //                for (j = i + 1, k = nums.size() - 1; j < k&&(flage1||flage2);)
    //            {
    //                b = nums[k];
    //                a = nums[j];
    //                if (target - nums[i] < nums[j] + nums[k])
    //                {
    //                    if (flage2 == 0) {
    //                        c = nums[j - 1];
    //                        a = abs(a + b + nums[i] - target) < abs(a + c + nums[i] - target) ? a : c;
    //                    }
    //                    flage1 = 0;
    //                    printf("1j;%d\n", j);
    //                    printf("1k;%d\n", k);
    //                    k--;
    //                }
    //                else if (target - nums[i] == nums[j] + nums[k])
    //                {
    //                    printf("lax");
    //                    return target;
    //                }
    //                else if (target - nums[i] > nums[j] + nums[k])
    //                {
    //                    if (flage1 == 0)
    //                    {
    //                        c = nums[k + 1];
    //                        b = abs(a + b + nums[i] - target)<abs(a + c + nums[i]-target) ? b:c;
    //                    }
    //                    flage2 = 0;
    //                    printf("2j;%d\n", j);
    //                    printf("2k;%d\n", k);
    //                    j++;
    //                   
    //                }
    //                
    //            }
    //            flage1 = 1;
    //            flage2 = 1;
    //            printf("%d,%d,%d\n", nums[i],a, b);
    //            a1 = nums[i] +a+b;
    //            if (abs(result - target) > abs(a1 - target))
    //                result = a1;

    //        }
    //        return result;
    //    }
    //};

    //正确答案与我的错误答案是差不多的，只是对相同数据直接进行while循环掉，
    //用依次对比。我只需要删除对变号地方的判断即可。
    class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int best = 1e7;//保证对原数据比较不会出现问题
            // 根据差值的绝对值来更新答案
            auto update = [&](int cur) {
                if (abs(cur - target) < abs(best - target)) {
                    best = cur;
                }
            };

            // 枚举 a
            for (int i = 0; i < n; ++i) {
                // 保证和上一次枚举的元素不相等
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                // 使用双指针枚举 b 和 c
                int j = i + 1, k = n - 1;
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    // 如果和为 target 直接返回答案
                    if (sum == target) {
                        return target;
                    }
                    update(sum);
                    if (sum > target) {
                        // 如果和大于 target，移动 c 对应的指针
                        int k0 = k - 1;
                        // 移动到下一个不相等的元素
                        while (j < k0 && nums[k0] == nums[k]) {
                            --k0;
                        }
                        k = k0;
                    }
                    else {
                        // 如果和小于 target，移动 b 对应的指针
                        int j0 = j + 1;
                        // 移动到下一个不相等的元素
                        while (j0 < k && nums[j0] == nums[j]) {
                            ++j0;
                        }
                        j = j0;
                    }
                }
            }
            return best;
        }
    };
	vector<int > nums= { 4,0,5,-5,3,3,0,-4,-5 };
	Solution a;
    printf("%d",a.threeSumClosest(nums,-2));
}