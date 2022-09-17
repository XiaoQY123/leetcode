#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
using namespace std;

/*给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。*/
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
    //class Solution {
    //    vector<vector<int>> ret1;
    //    vector<int> ret;//如果在递归函数内部，只管他那一层，所有要把他放在函数外部
    //public:
    //    
    //    vector<vector<int>> subsets(vector<int>& nums) {
    //        for (int i = 0; i < nums.size()+1; i++) {//nums.size()+1，保证可以从0到该数字数字
    //            di(i,nums,0);
    //        }
    //        return ret1;
    //    }

    //    void di(int n, vector<int>& nums,int count) {
    //        if (ret.size() == n) {
    //            ret1.push_back(ret);
    //            return;
    //        }
    //        for (int i =count; i < nums.size(); i++) {
    //            ret.push_back(nums[i]);
    //            di(n, nums,++count);//让下一层初始循环值为上一层的下一个数
    //            ret.pop_back();
    //        }
    //    }
    //};


    //优化调用递归函数的次数
    class Solution {
    public:
        vector<int> t;
        vector<vector<int>> ans;

        void dfs(int cur, vector<int>& nums) {
            if (cur == nums.size()) {
                ans.push_back(t);
                return;
            }
            t.push_back(nums[cur]);//这里直接代替了count的作用,直接下一个
            dfs(cur + 1, nums);//dfs1
            t.pop_back();
            dfs(cur + 1, nums);//dfs2
        }//原理：画图走一遍，第一次 cur==nums.size()//3,ans[1,2,3],return到上一层/3，pop(3)再次进入，cur==nums.size(),ans[1,2]
        //return 到 cur==nums.size()-1//2该层全部完成,return 到cur==nums.size()-2,pop(2);
        //重新进入第cur==nums.size()-1//2。。。。依次类推
        

        vector<vector<int>> subsets(vector<int>& nums) {
            dfs(0, nums);
            return ans;
        }
    };


    Solution a;
    vector<int>nums = { 1,2,3 };
    vector<vector<int>> ret = a.subsets(nums);
    for (int i = 0; i < ret.size(); i++) {
        printf("[");
        for (int j =0; j < ret[i].size(); j++) {
           
            printf("%d ", ret[i][j]);
        }
        printf("],");
    }
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





