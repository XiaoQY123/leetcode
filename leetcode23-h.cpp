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

    //递归
    /*BUG直接显示指针溢出，某些可以正常运行；1,输入 [[1,4,5],[1,3,4],[2,4]] 输出：1  2  3  4  4  4  5
    某些会报错，2,[[0,2,3],[1,2,3,4]]
    有些会最少一个数字:输入：3,[[1,4,5],[1,3,4],[2,6]] 输出：1  2  3  4  4  5
    */
    /*解决方法：我认认真真的走了一遍1,和2,找出了我对错误，我在逻辑上用的contiu写成了break.啊啊啊啊，md好无语，
    我还说我对逻辑这么正确，代码也这么正确，我就是个笑话,wuwuwuwuwu。浪费我时间，谁来教我debug啊*/

    //md 为什么测试完用例1004ms啊，内存消耗也大，mmmmmm
    //class Solution {

    //public:
    //    ListNode* mergeKLists(vector<ListNode*>& lists) {
    //        ListNode* p = nullptr;
    //        int count = 0;
    //        int minnum = INT_MAX;
    //        int a = -1;
    //        if (lists.size() == 0)//lists为空的特殊情况
    //            return nullptr;
    //        for (int i = 0; i < lists.size(); i++) {
    //            if (lists[i] == nullptr)
    //                continue;
    //               // break;
    //            count++;
    //            if (min(minnum, lists[i]->val) == lists[i]->val) {
    //                minnum = lists[i]->val;
    //                a = i;
    //            }
    //        }
    //        if (a == -1) {//lists不为空，但链表为空的特殊情况
    //            return nullptr;
    //        }
    //        if (count == 1) {
    //            return lists[a];
    //        }
    //        else
    //            p = lists[a];
    //        lists[a] = lists[a]->next;
    //        p->next = mergeKLists(lists);
    //        return p;
    //    }
    //};



    //优先队列
    //24ms,比我的低那么多，而且才战胜50%几，无语了，给不给人点信心啊
    //class Solution {
    //public:
    //  

    //    priority_queue <Status> q;

    //    ListNode* mergeKLists(vector<ListNode*>& lists) {
    //        for (auto node : lists) {
    //            if (node) q.push({ node->val, node });
    //        }
    //        ListNode head, * tail = &head;
    //        while (!q.empty()) {
    //            auto f = q.top(); q.pop();
    //            tail->next = f.ptr;
    //            tail = tail->next;
    //            if (f.ptr->next) q.push({ f.ptr->next->val, f.ptr->next });
    //        }
    //        return head.next;
    //    }
    //};

    //顺序合并，直接在主函数循环，调用两个链表合并的函数进行运行。

    //分治合并
    //我想起来我之前进行这方面的有一道相识的题：最大公共字符串利用了递归（好像还是两个递归调用))


    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
            if ((!a) || (!b)) return a ? a : b;
            ListNode head, * tail = &head, * aPtr = a, * bPtr = b;
            while (aPtr && bPtr) {
                if (aPtr->val < bPtr->val) {
                    tail->next = aPtr; aPtr = aPtr->next;
                }
                else {
                    tail->next = bPtr; bPtr = bPtr->next;
                }
                tail = tail->next;
            }
            tail->next = (aPtr ? aPtr : bPtr);
            return head.next;
        }

        ListNode* merge(vector <ListNode*>& lists, int l, int r) {
            if (l == r) return lists[l];
            if (l > r) return nullptr;
            int mid = (l + r) >> 1;//我忘记怎么算了
            /*l+r的值右移1位，相当l+r的值除以2取整。
             Int是将一个数值向下取整为最接近的整数的函数。
             INT是数据库中常用函数中的取整函数，
             常用来判别一个数能否被另一个数整除。*/
            return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
        }

        ListNode* mergeKLists(vector<ListNode*>& lists) {
            return merge(lists, 0, lists.size() - 1);
        }
    };

  
    ListNode* head = new ListNode(1);
    ListNode* h = new ListNode(4);
    head->next = h;
    ListNode* hh = new ListNode(5);
    h->next = hh;


    ListNode* head2 = new ListNode(1);
    ListNode* h2 = new ListNode(3);
    head2->next = h2;
    ListNode* hh2 = new ListNode(4);
    h2->next = hh2;

    ListNode* head3 = new ListNode(2);
    ListNode* h3 = new ListNode(6);
    head3->next = h3;
   // ListNode* hh3 = new ListNode(17);
   // h3->next = hh3;

    vector<ListNode*> lists;
    lists.push_back(head);
    lists.push_back(head2);
    lists.push_back(head3);

    Solution a;
    ListNode* ret = a.mergeKLists(lists);
    ListNode* p = head;
    int c = 0;
    for (; p != nullptr;) {
        printf("%d  ", p->val);
        // c++;
        p = p->next;
        //printf("%d ..", c);
    }

}



