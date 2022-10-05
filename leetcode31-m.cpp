#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
#include <bitset>
#include <unordered_set>
#include <time.h>

using namespace std;
/**/

int main() {
    class Solution {
    public:
        void nextPermutation(vector<int>& nums)
        {
            int i = 0;
            for (i = nums.size() - 2; i >= 0; i--)
            {
                //逆序查找，找到第一个不符合升序的数字
                //找到需要改变的位置
                if (nums[i] < nums[i + 1])
                {
                    //再逆序查找，第一个比刚才的数字大的数字，进行交换
                    //用该范围最小的数字去替换，保证最小
                    for (int j = nums.size() - 1; j > i; j--)
                    {
                        if (nums[j] > nums[i])
                        {
                            swap(nums[i], nums[j]);//14865

                            //交换完毕以后，将交换坐标以右的数字串逆转一下，保证数字串的升序
                            //目的：保证最小
                            reverse(nums.begin() + i + 1, nums.end());//14856
                            return;
                        }
                    }
                }
            }

            if (i < 0)
            {
                //如果没有找到不符合升序的数字，说明整个数字串是升序，就是最大数字的组合
                //那么我们重新返回最小的数字组合，也就是将当前最大的数字串逆序
                reverse(nums.begin(), nums.end());
                return;
            }

            return;
        }
    };

    Solution a;
    vector<int> s = {1,4,6,8,5};
    a.nextPermutation(s);
    for(int i=0;i<s.size();i++)
    printf("%d  ", s[i]);

}