#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
using namespace std;

/*21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 */
struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 
int main() {
    //迭代，要了解链表结构，直接指向，本题中，直接指向，不需要申请新的节点，、、
    //并更新数值，也不用判断当链表为空时的问题
    /*class Solution {
    public:*/
    //    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //        ListNode* head = new ListNode(-1);
    //        ListNode *p = head;
    //        bool flage1 = true;
    //        bool flage2 = true;
    //        for (; list1 != nullptr || list2 != nullptr;) {
    //            if (list1 == nullptr)
    //                flage1 = false;
    //            if (list2 == nullptr)
    //                flage2 = false;
    //          
    //            if(flage1 &&flage2&& list1->val>list2->val) //异常.list1为空?我不是判断了吗？无语：                                         
    //            {  
    //                printf("list2..  %d\n", list2->val);
    //                ListNode* node = new ListNode(list2->val);//哦抱歉，我发现我打错变量了
    //                p->next = node;
    //                p = p->next;
    //                list2 = list2->next;
    //            }
    //            else if (flage1 && flage2 && list1->val <= list2->val) {
    //                printf("list1..  %d\n", list1->val);
    //                ListNode* node2 = new ListNode(list1->val);
    //                p->next = node2;
    //                p = p->next;
    //                list1 = list1->next;
    //            }
    //            else if (flage1 == false) {
    //                printf("list2..  %d\n", list2->val);
    //                ListNode* node3 = new ListNode(list2->val);
    //                p->next = node3;
    //                p = p->next;
    //                list2 = list2->next;
    //            }
    //            else if (flage2==false) {
    //                printf("list1..  %d\n", list1->val);
    //                ListNode* node4 = new ListNode(list1->val);
    //                p->next = node4;
    //                p = p->next;
    //                list1 = list1->next;
    //            }
    //            else
    //                printf("k;;l");
    //               
    //        }
    //           return head->next;
    //    }
    //};




    //class Solution {
    //public:
    //    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //        ListNode* preHead = new ListNode(-1);
    //        ListNode* prev = preHead;
    //        //int n = 0;
    //        while (l1 != nullptr && l2 != nullptr) {
    //          //  printf("kjal   ");
    //            if (l1->val <= l2->val) {
    //                prev->next = l1;
    //                l1 = l1->next;
    //            }
    //            else {
    //                prev->next = l2;
    //                l2 = l2->next;
    //               
    //            }
    //            prev = prev->next;
    //            //n++;
    //        }
    //        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
    //        prev->next = l1 == nullptr ? l2 : l1;
    //       // return l1;
    //        return preHead->next;
    //    }
    //};
   /* BUG
    我不明白，为什么啊，为什么会无线循环啊。在leetcode平台上就是正确的啊；无语死了   
    如果将循环加入一个判断条件，例如&&n<3，则结果显示无线循环’1‘这个数字
    如果将 主函数里循环输出注释掉，则显示正确次数的  kjal；
    如果不调用该函数，直接输出head，也是成功的
    怀疑没有将->next执行下去
    但是将 l1直接在函数循环前用return返回，则可以直接输出元素
    */
    /*
    * 调试，发现l1链表没有next，导致l1的数一直最小（为1）,并且一直不能next
    * 发现之前传入的链表为同一条链表，传入的地址；
    * 解决：
    * 建立一条新的链表，传入参数
    * 
    */
    //bug
    //为什么少了一个1,调试发现当链表的第一个数相同时，只输出一个数，其他情况正确
    /*解决办法，将第一个判断条件<改为<=
    但是按道理来说,他用的else啊，相同情况不是都可以吗，无语死了，还不如让我一头撞死*/


//递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val > l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2 ;
        }
        else {
            l1->next = mergeTwoLists(l1->next, l2);

            return  l1;
        }
        
    }
};
/*
* 过程：
* l1=1,2,3
* l2=1,4,5,6,7
* 当进入时，一直到达最后,即L1为空，返回当时L2(4,5,6,7);前面与之相连接的是l1->next=4,5,6,7；l1为3所以3,4,5,6,7;
* 返回l1->next=3,4,5,6,7;l1=2即l1=2,3,4,5,6,7；返回到l2->next=2,3,4,5,6,7;l2=1即1,2,3,4,5,6,7返回到l1->next=1,2,3,4,5,6,7,l1=1;
* 即l1=1,1,2,3,4,5,6,7;完成所有层次
*/

    ListNode* head = new ListNode(0);
    ListNode* h = new ListNode(2);
    head->next = h;
    ListNode * hh = new ListNode(3);
    h->next=hh;


    ListNode* head2 = new ListNode(0);
    ListNode* h2 = new ListNode(4);
    head2->next = h2;
    ListNode* hh2 = new ListNode(5);
    h2->next = hh2;

    Solution a;
    ListNode* ret=a.mergeTwoLists(head,head2);
    ListNode* p = head;
    int c = 0;
    for (; p != nullptr;) {
        printf("%d  ", p->val);
       // c++;
        p = p->next;
        //printf("%d ..", c);
    }

}
  
    ////ListNode* head = new ListNode(1);
    ////ListNode* h = new ListNode(2);
    ////head->next = h;
    ////ListNode * hh = new ListNode(3);
    ////h->next=hh;
    ////Solution a;
    ////ListNode* ret = a.removeNthFromEnd(head, 2);
    ////ListNode* p = ret;
    ////int c = 0;
    ////for (; p!=nullptr;) {
    ////    printf("%d  ", p->val);
    ////    //c++;
    ////    p = p->next;
    ////   // printf("%d ..", c);
    
