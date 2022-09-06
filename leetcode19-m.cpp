#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
int main() {

    //方法一，暴力解法，直接先遍历得到长度
    //class Solution {
    //public:
    //    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //        int len = 0;
    //        ListNode* h = head;
    //        ListNode* q = head;
    //        ListNode* p=head;
    //        if (head == nullptr)
    //            return head;

    //        while (h!= nullptr) {
    //            h = h->next;
    //            len++;
    //        }
    //        int i = 0;
    //        if (len - n - 1<0) {
    //            p = p->next;
    //            delete head;
    //            return p;
    //        }
    //        for (int i = 0; i < len - n-1; i++) {
    //            q = q->next;
    //        }
    //        p = q;
    //       // printf("q:%d \n", q->val);
    //        p = p->next;
    //        //printf("p:%d  \n", p->val);
    //        q->next = p->next;
    //        delete p;
    //        return head;
    //    }

    //};


    //快慢指针
    //class Solution {
    //public:
    //    ListNode* removeNthFromEnd(ListNode* head, int n) {

    //        ListNode* head0 = new ListNode(-1);//消除特殊情况
    //        head0->next = head;
    //        ListNode* p = head0;
    //        ListNode* q = head0;
    //        while (n >= 0)
    //        {
    //            p = p->next;
    //            n--;
    //        }
    //        while (p!= nullptr) {
    //            
    //            p = p->next;
    //            q = q->next;
    //        }
    //        p = q->next;
    //        q->next = p->next;//不晓得为什么有个提示p和h都指向null
    //        delete p;
    //        return head0->next;
  
    //    }
    //};
    //
    //回溯法，递归
    class Solution {
    public:
        int cur = 0;
        ListNode* removeNthFromEnd(ListNode* head, int n) {

            //简洁版
            //if (!head) return NULL;
            //head->next = removeNthFromEnd(head->next, n);
            //cur++;
            //if (n == cur) return head->next;
            //return head;
           
            int num = traver(head, n);
            if (num == n) {
                ListNode* p = head->next;
                delete head;
                return p;
            }
            return head;
        
        }
        int traver(ListNode *node, int n) {//传入地址，直接改变链表
           
            if (node == NULL) {
               
                return 0;
            }
            int num = traver(node->next, n);
            if (num == n) {
                ListNode* p = node->next;
                node->next = node->next->next;
                delete p;
            }
            return num + 1;
        }
    };
  
    ListNode* head = new ListNode(1);
    ListNode* h = new ListNode(2);
    head->next = h;
    ListNode * hh = new ListNode(3);
    h->next=hh;
    Solution a;
    ListNode* ret = a.removeNthFromEnd(head, 2);
    ListNode* p = ret;
    int c = 0;
    for (; p!=nullptr;) {
        printf("%d  ", p->val);
        //c++;
        p = p->next;
       // printf("%d ..", c);
    }
}