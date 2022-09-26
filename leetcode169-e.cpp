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
 /*   class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int, int>  map;
            for (int i = 0; i < nums.size(); i++) {
                map[nums[i]]++;
                if (map[nums[i]] >= nums.size() / 2) {
                    return nums[i];
                }
            }
            return -1;
          
        }
    };*/


    //找众数的思想，但是利用随机数，应为概率问题的思想
 /*   class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            while (true) {
                int candidate = nums[rand() % nums.size()];
                int count = 0;
                for (int num : nums)
                    if (num == candidate)
                        ++count;
                if (count > nums.size() / 2)
                    return candidate;
            }
            return -1;
        }
    };*/

    //投票选举
    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int candidate = -1;//开始可以为任意数
            int count = 0;
            for (int num : nums) {
                if (num == candidate)
                    ++count;//如果是选举人，投本身一票
                else if (--count < 0) {//其他人投反对票
                    candidate = num;//换人
                    count = 1;
                }
            }
            return candidate;
        }
    };


    Solution a;
    vector<int> nums = { 2,4,5,5,6,5 };
    int s=a.majorityElement(nums);
    printf("%d", s);

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





