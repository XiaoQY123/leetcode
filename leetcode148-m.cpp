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
using namespace std;

/*给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。*/
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




  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
  int main() {
      //无语，运行出来咋不对嘞，我是cv的啊
      class Solution {
      public:
          ListNode* sortList(ListNode* head) {
              if (head == nullptr) {
                  return head;
              }
              int length = 0;
              ListNode* node = head;
              while (node != nullptr) {
                  length++;
                  node = node->next;
              }
              ListNode* dummyHead = new ListNode(0, head);
              for (int subLength = 1; subLength < length; subLength <<= 1) {
                  ListNode* prev = dummyHead, * curr = dummyHead->next;
                  while (curr != nullptr) {
                      ListNode* head1 = curr;
                      for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                          curr = curr->next;
                      }
                      ListNode* head2 = curr->next;
                      curr->next = nullptr;
                      curr = head2;
                      for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                          curr = curr->next;
                      }
                      ListNode* next = nullptr;
                      if (curr != nullptr) {
                          next = curr->next;
                          curr->next = nullptr;
                      }
                      ListNode* merged = merge(head1, head2);
                      prev->next = merged;
                      while (prev->next != nullptr) {
                          prev = prev->next;
                      }
                      curr = next;
                  }
              }
              return dummyHead->next;
          }

          ListNode* merge(ListNode* head1, ListNode* head2) {
              ListNode* dummyHead = new ListNode(0);
              ListNode* temp = dummyHead, * temp1 = head1, * temp2 = head2;
              while (temp1 != nullptr && temp2 != nullptr) {
                  if (temp1->val <= temp2->val) {
                      temp->next = temp1;
                      temp1 = temp1->next;
                  }
                  else {
                      temp->next = temp2;
                      temp2 = temp2->next;
                  }
                  temp = temp->next;
              }
              if (temp1 != nullptr) {
                  temp->next = temp1;
              }
              else if (temp2 != nullptr) {
                  temp->next = temp2;
              }
              return dummyHead->next;
          }
      };



      ListNode* head = new ListNode(-1);
      ListNode* h = new ListNode(2);
      head->next = h;
      ListNode* hh = new ListNode(-3);
      h->next = hh;

      Solution a;
      ListNode * p = head;
      ListNode* cc = a.sortList(head);
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





