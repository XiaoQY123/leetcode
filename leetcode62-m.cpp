#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
using namespace std;

/*一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
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


    //线性规划
    /*class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> f(m, vector<int>(n));
            for (int i = 0; i < m; ++i) {
                f[i][0] = 1;
            }
            for (int j = 0; j < n; ++j) {
                f[0][j] = 1;
            }
            for (int i = 1; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
            return f[m - 1][n - 1];
        }
    };*/


    //线性规划，滚动数组，内存优化
    class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<int> dp(n, 1);//申请一个n大小全为1的向量
            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    dp[j] += dp[j - 1];//我不理解（问号脸)
                }
            }
            return dp[n - 1];
        }
    };

    //组合数学
  /*class Solution {
  public:
      int uniquePaths(int m, int n) {
          long long ans = 1;
          for (int x = n, y = 1; y < m; ++x, ++y) {
              ans = ans * x / y;
          }
          return ans;
      }
  };

  */

    Solution a;
    int ret = a.uniquePaths(3, 6);
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





