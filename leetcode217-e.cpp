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

/*给你一个整数数组 nums 。
如果任一值在数组中出现 至少两次 ，返回 true ；
如果数组中每个元素互不相同，返回 false 。
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};
int main() {
    class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            map<int, int> mapps;
            for (int i = 0; i < nums.size(); i++) {
                mapps[nums[i]]++;
                if (mapps[nums[i]] > 1)
                    return true;
            }
            return false;
        }
    };

    Solution a;
    vector<int> nums = { 1,2,3,1 };
    printf("%d", a.containsDuplicate(nums));


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





