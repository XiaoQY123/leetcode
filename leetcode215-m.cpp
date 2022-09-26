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

  
int main() {
    //快速排序，加分治思想
    //我不理解，为什么不行啊，报错欸
    class Solution {
    public:
        void Fs(vector<int>nums, int left, int right, int k) {
            //srand(time(nullptr));
            int r = rand() % (right - left + 1) + left;
            int base = nums[r];
            int index = left;
            swap(nums[r], nums[left]);//基点，并且放在头部
            for (int i = left+1; i <= right;++i) {
                if (nums[i] >= base) {
                    swap(nums[index+1], nums[i]);
                    index++;
                }
            }
            swap(nums[index], nums[left]);//确定基点的位置
            //分治
            if (index > k)
                Fs(nums,index+1,right ,k);
            else if (index < k)
                Fs(nums, left, index - 1, k);

        }

        int findKthLargest(vector<int>& nums, int k) {
            Fs(nums, 0, nums.size() - 1, k - 1);
            return nums[k - 1];
        }
    };
    //class Solution {
    //public:
    //    void quickPartition(vector<int>& nums, int start, int end, int target) {
    //        // 随机取一个数作为基准
    //        srand(time(nullptr));
    //        int random = rand() % (end - start + 1) + start;
    //        int base = nums[random];
    //        // 将该数放到待快排区间开头第一个元素
    //        swap(nums[start], nums[random]);
    //        int index = start;
    //        // 从待快排区间的第二个元素开始，依次与base比较，如果大于等于base则将该元素
    //        // 交换到index + 1位置，index++，使得最终index前面的元素都比base大。
    //        for (int i = start + 1; i <= end; ++i) {
    //            if (nums[i] >= base) {
    //                swap(nums[index + 1], nums[i]);
    //                index++;
    //            }
    //        }
    //        // base存放在区间开头，现在需要把它交换到index位置，这就是它在整个有序数组中的位置。
    //        swap(nums[index], nums[start]);

    //        // 如果index小于target，需要在右边区间继续快排查找，否则到在边区间查找，
    //        // 如果等于已经找到目标值不需要递归，这里这么做优化了传统快排的复杂度。
    //        if (index < target) {
    //            quickPartition(nums, index + 1, end, target);
    //        }
    //        else if (index > target) {
    //            quickPartition(nums, start, index - 1, target);
    //        }
    //    }

    //    int findKthLargest(vector<int>& nums, int k) {
    //        // 方法1. 快速排序的分区思想，快排的思想是一次找出一个数的正确位置，
    //        // 并使得该数左边的元素都比它小，该数右边的元素都比它大，要找出第k
    //    // 大的元素，只需要在快排的时候采用降序排序，找到下标为k-1的元素即可。

    //        quickPartition(nums, 0, nums.size() - 1, k - 1);
    //        return nums[k - 1];
    //    }
    //};
    vector<int>nums = { 3,2,3,1,2,4,5,5,6 };
    Solution a;
    printf("%d ", a.findKthLargest(nums, 4));

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





