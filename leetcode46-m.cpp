#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
using namespace std;

/*给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 */
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


//利用标识的全排列
int main() {
   /* class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> re;
            vector<int> used(nums.size(), 0);
            dfs(res, re, used, nums);
            return res;
        }

        void dfs(vector<vector<int>>& res, vector<int>& re, vector<int>& used, vector<int>& nums)
        {
            if (re.size() == nums.size()) {
                res.push_back(re);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (used[i] != 0)  continue;
                else {
                    re.push_back(nums[i]);
                    used[i] = 1;
                    dfs(res, re, used, nums);
                    re.pop_back();
                    used[i] = 0;
                }
            }
        }
    };*/
   //巧妙的方法
    class Solution {
    public:
        void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
            // 所有数都填完了
            if (first == len) {
                res.emplace_back(output);
                return;
            }
            for (int i = first; i < len; ++i) {
                // 动态维护数组
                swap(output[i], output[first]);
                // 继续递归填下一个数
                backtrack(res, output, first + 1, len);
                // 撤销操作
                swap(output[i], output[first]);
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int> > res;
            backtrack(res, nums, 0, (int)nums.size());
            return res;
        }
    };


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





