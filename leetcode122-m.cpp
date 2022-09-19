#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
#include <bitset>
using namespace std;

/*21. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。*/
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

int main() {

    //动态规划
   /* class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<int>>dp(n,vector<int>(2));
            dp[0][0] = 0, dp[0][1] = -prices[0];
            for (int i = 1; i < n; ++i) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            }
            return dp[n - 1][0];
        }
    };*/

    //动态规划，内存优化
  /*  class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int dp0 = 0;
            int dp1 = -prices[0];
            for (int i = 0; i < n; i++) {
                int newDp0 = max(dp0, dp1 + prices[i]);
                int newDp1 = max(dp1, dp0 - prices[i]);
                dp0 = newDp0;
                dp1 = newDp1;
            }
            return dp0;
        }
    }; */

    //贪心算法
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int ret = 0;
            for (int i = 1; i < prices.size(); ++i) {
                ret = ret + max(0, prices[i] - prices[i - 1]);
            }
            return ret;
        }
    };


    Solution a;
    vector<int> prices = {6,1,3,2,4,7};
    int nums = a.maxProfit(prices);
    printf("%d ", nums);
}

   /*  ListNode* head = new ListNode(1);
     ListNode* h = new ListNode(2);
     head->next = h;
     ListNode* hh = new ListNode(3);
     h->next = hh;*/


    //ListNode* head2 = new ListNode(1);
    //ListNode* h2 = new ListNode(3);
    //head2->next = h2;
    //ListNode* hh2 = new ListNode(4);
    //h2->next = hh2;

    //ListNode* head3 = new ListNode(2);
    //ListNode* h3 = new ListNode(6);
    //head3->next = h3;
    // ListNode* hh3 = new ListNode(17);
    // h3->next = hh3;

   /* vector<ListNode*> lists;
    lists.push_back(head);*/
    //lists.push_back(head2);
    //lists.push_back(head3);

    //Solution a;
    //ListNode* ret = a.rotateRight(head,1);
    //ListNode* p = head;
    //int c = 0;
    //for (; p != nullptr;) {
    //    printf("%d  ", p->val);
    //    // c++;
    //    p = p->next;
    //    //printf("%d ..", c);
    //}
//}





