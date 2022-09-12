#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
using namespace std;

/*53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Status {
    int val;
    ListNode* ptr;
    bool operator < (const Status& rhs) const {
        return val > rhs.val;
    }
};
//
int main() {
    //暴力解法，超时了
    //class Solution {
    //public:
    //    int maxSubArray(vector<int>& nums) {
    //        int maxnum = INT_MIN;
    //        int Maxnum =INT_MIN;
    //        int i = 0;
    //        int j = 0;
    //        if (nums.size() == 1)
    //            return nums[0];
    //        for (j = 0; j < nums.size(); j++) {
    //            int sum = 0;
    //
    //            for (i = j; i < nums.size(); i++) {
    //                sum = sum + nums[i];
    //                if (sum > maxnum) {
    //                    maxnum = sum;
    //                }
    //            }
    //            if (maxnum > Maxnum) {
    //                Maxnum = maxnum;
    //            }
    //            maxnum = INT_MIN;
    //        }
    //        return Maxnum;

    //    }
    //};


    //动态规划
//class Solution {
//public:
//        int maxSubArray(vector<int>& nums) {
//            int pre = 0; int c = nums[0];
//            for (const int x : nums) {
//                pre = max(pre + x, x);//如果以i-1结尾的子序列一定小于0，才会使pre+x>x
//                c = max(pre, c);
//            }
//            return c;
//        }
//    };

//贪心算法,与线性规划相似代码
//class Solution {
//public:
//        int maxSubArray(vector<int>& nums) {
//            int a = nums[0];
//            int maxnum = nums[0];
//            for (int i = 1; i < nums.size(); i++) {
//                if (a < 0) {
//                    a = nums[i];
//                }
//                else {
//                    a = a + nums[i];
//                }
//                maxnum = max(a, maxnum);
//            }
//            return maxnum;
//        }
//    };


//分治合并
//线段数


    class Solution {
    public:
        struct Status {
            int lSum, rSum, mSum, iSum;
        };

        Status pushUp(Status l, Status r) {
            int iSum = l.iSum + r.iSum;
            int lSum = max(l.lSum, l.iSum + r.lSum);
            int rSum = max(r.rSum, r.iSum + l.rSum);
            int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
            return (Status){ lSum, rSum, mSum, iSum };//报错
        };

        Status get(vector<int>& a, int l, int r) {
            if (l == r) {
                return (Status) { a[l], a[l], a[l], a[l] };//报错
            }
            int m = (l + r) >> 1;
            Status lSub = get(a, l, m);
            Status rSub = get(a, m + 1, r);
            return pushUp(lSub, rSub);
        }

        int maxSubArray(vector<int>& nums) {
            return get(nums, 0, nums.size() - 1).mSum;
        }
    };

    vector<int> nums = { -3,-2,-2,-3};
    Solution a;
    printf("%d", a.maxSubArray(nums));
}



// ListNode* head = new ListNode(1);
// ListNode* h = new ListNode(4);
// head->next = h;
// ListNode* hh = new ListNode(5);
// h->next = hh;


// ListNode* head2 = new ListNode(1);
// ListNode* h2 = new ListNode(3);
// head2->next = h2;
// ListNode* hh2 = new ListNode(4);
// h2->next = hh2;

// ListNode* head3 = new ListNode(2);
// ListNode* h3 = new ListNode(6);
// head3->next = h3;
//// ListNode* hh3 = new ListNode(17);
//// h3->next = hh3;

// vector<ListNode*> lists;
// lists.push_back(head);
// lists.push_back(head2);
// lists.push_back(head3);

// Solution a;
// ListNode* ret = a.mergeKLists(lists);
// ListNode* p = head;
// int c = 0;
// for (; p != nullptr;) {
//     printf("%d  ", p->val);
//     // c++;
//     p = p->next;
//     //printf("%d ..", c);
// }





