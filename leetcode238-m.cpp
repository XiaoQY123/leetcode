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
/*238. 除自身以外数组的乘积
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。*/

int main() {
    //class Solution {
    //public:
    //    vector<int> productExceptSelf(vector<int>& nums) {
    //        int length = nums.size();

    //        // L 和 R 分别表示左右两侧的乘积列表
    //        vector<int> L(length, 0), R(length, 0);

    //        vector<int> answer(length);

    //        // L[i] 为索引 i 左侧所有元素的乘积
    //        // 对于索引为 '0' 的元素，因为左侧没有元素，所以 L[0] = 1
    //        L[0] = 1;
    //        for (int i = 1; i < length; i++) {
    //            L[i] = nums[i - 1] * L[i - 1];
    //        }

    //        // R[i] 为索引 i 右侧所有元素的乘积
    //        // 对于索引为 'length-1' 的元素，因为右侧没有元素，所以 R[length-1] = 1
    //        R[length - 1] = 1;
    //        for (int i = length - 2; i >= 0; i--) {
    //            R[i] = nums[i + 1] * R[i + 1];
    //        }

    //        // 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
    //        for (int i = 0; i < length; i++) {
    //            answer[i] = L[i] * R[i];
    //        }

    //        return answer;
    //    }
    //};//时间复杂度：O(N)O(N)，其中 NN 指的是数组 nums 的大小。
    //预处理 L 和 R 数组以及最后的遍历计算都是 O(N)O(N) 的时间复杂度。
    //居然可以这样，0（3N）->0(N)


    //优化：减少空间损失

    class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int length = nums.size();
            vector<int> answer(length);

            // answer[i] 表示索引 i 左侧所有元素的乘积
            // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
            answer[0] = 1;
            for (int i = 1; i < length; i++) {
                answer[i] = nums[i - 1] * answer[i - 1];
            }

            // R 为右侧所有元素的乘积
            // 刚开始右边没有元素，所以 R = 1
            int R = 1;
            for (int i = length - 1; i >= 0; i--) {
                // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
                answer[i] = answer[i] * R;
                // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
                R *= nums[i];
            }
            return answer;
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





