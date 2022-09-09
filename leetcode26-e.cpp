#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
using namespace std;

/*21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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

int main() {
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if ( nums.size() == 0) return 0;
            int p = 0;
            int q = 1;
            while (q < nums.size()) {
                if (nums[p] != nums[q]) {
                    nums[p + 1] = nums[q];
                    p++;
                }
                q++;
            }  
            return p + 1;
        
        }
    };

    Solution a;
    vector<int> nums = { 1,1,5,5,6,6,8 };
    int c = a.removeDuplicates(nums);
    printf("%d\n", a.removeDuplicates(nums));
    for (int i = 0; i < c; i++) {
        printf("%d,",nums[i]);

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

}



