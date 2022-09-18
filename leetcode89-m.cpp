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

/*89.n 位格雷码序列 是一个由 2n 个整数组成的序列，其中：
每个整数都在范围 [0, 2n - 1] 内（含 0 和 2n - 1）
第一个整数是 0
一个整数在序列中出现 不超过一次
每对 相邻 整数的二进制表示 恰好一位不同 ，且
第一个 和 最后一个 整数的二进制表示 恰好一位不同
给你一个整数 n ，返回任一有效的 n 位格雷码序列 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/gray-code
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

    //镜像法,画图只有一遍程序
    /*
    * CV 镜像法,观察雷格码二进制排列顺序，发现以下规律：
当n的码的前一半为n-1的全部。后一半为前一半的最高位改为1
    */
    //class Solution {
    //public:
    //    vector<int> grayCode(int n) {
    //        vector<int> ret;
    //       ret.reserve(1 << n);
    //        ret.push_back(0);
    //        for (int i = 1; i <= n; i++) {
    //            int m = ret.size();
    //            for (int j = m - 1; j >= 0; j--) {
    //                ret.push_back(ret[j] | (1 << (i - 1)));//牛啊啊
    //            }
    //        }
    //        return ret;
    //    }
    //};

    //好家伙，直接结合10进制和2进制找到规律，牛啊
    //class Solution {
    //public:
    //    vector<int> grayCode(int n) {
    //        vector<int> ans = { 0 };
    //        int head = 1;

    //        for (int i = 1; i <= n; i++) {
    //            int len = ans.size();
    //            for (int j = len - 1; j >= 0; j--) {
    //                ans.push_back(ans[j]+head);
    //            }
    //            head = head << 1;
    //        }
    //        return ans;
    //    }
    //};


    //直接构造法
    /*
    * CV ,观察发现 1,2,3,4,..n可以直接求出对应的码
    */
    class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> ret(1 << n);
            for (int i = 0; i < ret.size(); i++) {
                ret[i] = (i >> 1) ^ i;//该操作,相当于二进制i先删除最右一位，再与i的二进制 
            }//做二进制的异或运算,返回的是10进制的数
            return ret;
        }
    };

    Solution a;
    vector<int> nums1 = a.grayCode(3);
    for (int i = 0; i < nums1.size();i++)
    printf("%d ", nums1[i]);
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





