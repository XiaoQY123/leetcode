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

/*给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};
int main() {
    //迭代法；
    ///*class Solution {
    //public:
    //    ListNode* reverseList(ListNode* head) {
    //        ListNode* p1 = head;
    //        ListNode* p3 = nullptr;
    //        while (p1 != nullptr) {
    //            ListNode* p2 = p1->next;
    //            p1->next = p3;
    //            p3 = p1;
    //            p1 = p2;

    //        }
    //        return p3;
    //    }
    //};*/
 
    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if (!head || !head->next) {
                return head;
            }
            ListNode* newHead = reverseList(head->next);
            head->next->next = head;//自己画图运行一下
            head->next = nullptr;//断开
            return newHead;
        }
    };

    

      ListNode* head = new ListNode(1);
      ListNode* h = new ListNode(2);
      head->next = h;
      ListNode* hh = new ListNode(3);
      h->next = hh;
    Solution a;
    ListNode* ret =a.reverseList(head) ;
    ListNode* p =ret;
    int c = 0;
    for (; p != nullptr;) {
        printf("%d  ", p->val);
        // c++;
        p = p->next;
        //printf("%d ..", c);
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





