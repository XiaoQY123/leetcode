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

/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/single-number
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

    /*答案是使用位运算。对于这道题，可使用异或运算 \oplus⊕。异或运算有以下三个性质。

    任何数和 00 做异或运算，结果仍然是原来的数，即 a \oplus 0 = aa⊕0 = a。
        任何数和其自身做异或运算，结果是 00，即 a \oplus a = 0a⊕a = 0。
        异或运算满足交换律和结合律，即 a \oplus b \oplus a = b \oplus a \oplus a = b \oplus(a \oplus a) = b \oplus0 = ba⊕b⊕a = b⊕a⊕a = b⊕(a⊕a) = b⊕0 = b。
*/
        
    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int ret = 0;
            for (auto e : nums) ret ^= e;
            return ret;
        }
    };
    vector<int> nums = { 1,2,2,4,4 };
    Solution a;
    printf("%d", a.singleNumber(nums));

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





