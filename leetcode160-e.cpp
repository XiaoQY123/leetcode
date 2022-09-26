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

/*160. 相交链表
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

图示两个链表在节点 c1 开始相交：



题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。

自定义评测：

评测系统 的输入如下（你设计的程序 不适用 此输入）：

intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0
listA - 第一个链表
listB - 第二个链表
skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数
skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数
评测系统将根据这些输入创建链式数据结构，并将两个头节点 headA 和 headB 传递给你的程序。如果程序能够正确返回相交节点，那么你的解决方案将被 视作正确答案 。

 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};
int main() {
    //class Solution {
    //public:
    //    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    //        //相交节点，题目意思是地址相同
    //        ListNode* pa = headA;
    //        ListNode* pb = headB;
    //        if (pa == nullptr || pb == nullptr)
    //            return nullptr;
    //        while (pa != pb) {
    //            pa = pa == nullptr ? headA : pa->next;
    //            pb = pb == nullptr ? headB : pb->next;
    //        }
    //        return pa;
    //    }
    //};
  

    //这个快很多额
    class Solution {
    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            ListNode* curA = headA;
            ListNode* curB = headB;

            int lenA = 0;
            int lenB = 0;
            //得到两个链表的长度
            while (curA != NULL) {
                lenA++;
                curA = curA->next;
            }

            while (curB != NULL) {
                lenB++;
                curB = curB->next;
            }

            curA = headA;
            curB = headB;

            //得到相差的
            if (lenB > lenA) {
                swap(lenA, lenB);
                swap(curA, curB);
            }

            int gap = lenA - lenB;
            //使在同一长度开始，起点
            while (gap--) {
                curA = curA->next;
            }

            while (curA != NULL) {
                if (curA == curB) {
                    return curA;
                }
                curA = curA->next;
                curB = curB->next;
            }
            return NULL;
        }
    };

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





