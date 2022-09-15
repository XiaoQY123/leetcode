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
//
int main() {

    class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            ListNode* p = head;
            ListNode* last = head;
            ListNode* m = nullptr;
            for (int i = 0; last != nullptr; i++) {
                if (i == k) {
                    //last= p->next;
                    m = p->next;
                    last = m;
                    printf("p:%d..\n", p->val);
                    printf("last:%d..\n", last->val);
                    p->next = nullptr;
                    continue;
                }
                if (i < k)
                    p = p->next;
                if (last->next == nullptr)
                    break;
                last = last->next;
                printf("1:last:%d..\n", last->val);
            }
            printf("head:%d..\n", head->val);
            last->next = head;
            return m;
        }

    };

    /*
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 1;
        ListNode* iter = head;
        while (iter->next != nullptr) {
            iter = iter->next;
            n++;
        }
       
        int add=n-k%n;
         if (add == n) {
            return head;
        }
        iter->next = head;
        while (add--) {
            iter = iter->next;
        }
        ListNode* ret = iter->next;
        iter->next = nullptr;
        return ret;
    }
};*/


     ListNode* head = new ListNode(1);
     ListNode* h = new ListNode(2);
     head->next = h;
     ListNode* hh = new ListNode(3);
     h->next = hh;


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

    Solution a;
    ListNode* ret = a.rotateRight(head,0);
    ListNode* p = head;
    int c = 0;
    for (; p != nullptr;) {
        printf("%d  ", p->val);
        // c++;
        p = p->next;
        //printf("%d ..", c);
    }
}





