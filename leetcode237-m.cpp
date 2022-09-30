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

/*237. 删除链表中的节点
有一个单链表的 head，我们想删除它其中的一个节点 node。

给你一个需要删除的节点 node 。你将 无法访问 第一个节点  head。

链表的所有值都是 唯一的，并且保证给定的节点 node 不是链表中的最后一个节点。

删除给定的节点。注意，删除节点并不是指从内存中删除它。这里的意思是：

给定节点的值不应该存在于链表中。
链表中的节点数应该减少 1。
node 前面的所有值顺序相同。
node 后面的所有值顺序相同。
 */


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
     
//理解题目意思：
 //有一个链表，将要删除node节点，但是你并不知道head地址,只能从node入手
//代码入下
int main() {
   
    class Solution {
    public:
        void deleteNode(ListNode* node) {
            class Solution {
            public:
                void deleteNode(ListNode* node) {
                    node->val = node->next->val;
                    node->next = node->next->next;
                }
            };
        }
    };
}