#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
using namespace std;

/*给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。*/
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
    //错误代码，逻辑错误
    //逻辑错误，本想利用排列组合计算，每一次两个台阶的出现次数的可能的和。
    //发现用排列组合不能控制是两个一体的排列组合

    //class Solution {
    //public:
    //    int climbStairs(int n) {
    //        int sum = 0;
    //        for (int i = 0; 2 * i <= n; i++) {
    //            sum = sum + uniquePaths(i, n);
    //            printf("%d \n", sum);
    //        }
    //        return sum;
    //    }
    //    int uniquePaths(int m, int n) {//函数，帮助计算C排列组合
    //        long long ans = 1;
    //        for (int x = n, y = m; x != (n - m) || y != 0; x--, y--) {
    //            if (x == n - m)
    //                ans = ans * 1 / y;
    //            if (y == 0)
    //                ans = ans * x;
    //            else
    //                ans = ans * x / y;

    //        }
    //        return ans;
    //    }
    //};

    //线性规划
    class Solution {
    public:
        int climbStairs(int n) {
            vector<int> dp(n + 1, 1);
            for (int i = 2; i < n + 1; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];

            }
            return dp[n];
        }
    };

    
    Solution a;
    int ret = a.climbStairs(5);
    printf("%d", ret);
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





