#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
using namespace std;

/*33.整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
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
    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = (int)nums.size();
            if (!n) {
                return -1;
            }
            if (n == 1) {
                return nums[0] == target ? 0 : -1;
            }
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid] == target) return mid;
                if (nums[0] <= nums[mid]) {
                    if (nums[0] <= target && target < nums[mid]) {
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                else {
                    if (nums[mid] < target && target <= nums[n - 1]) {
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
            }
            return -1;
        }
    };

    Solution a;
    vector<int> nums = { 3,4,5,0,1,2};
    int target = 2;
    printf("%d", a.search(nums,target));
    /*for (int i = 0; i < 9; i++) {
        printf("%d,",nums[i]);

    }*/


  
   // ListNode* head = new ListNode(1);
   // ListNode* h = new ListNode(4);
   // head->next = h;
   // ListNode* hh = new ListNode(5);
   // h->next = hh;


   // ListNode* head2 = new ListNode(1);
   // ListNode* h2 = new ListNode(3);
   // head2->next = h2;
   // ListNode* hh2 = new ListNode(4);
   // h2->next = hh2;

   // ListNode* head3 = new ListNode(2);
   // ListNode* h3 = new ListNode(6);
   // head3->next = h3;
   //// ListNode* hh3 = new ListNode(17);
   //// h3->next = hh3;

   // vector<ListNode*> lists;
   // lists.push_back(head);
   // lists.push_back(head2);
   // lists.push_back(head3);

   // Solution a;
   // ListNode* ret = a.mergeKLists(lists);
   // ListNode* p = head;
   // int c = 0;
   // for (; p != nullptr;) {
   //     printf("%d  ", p->val);
   //     // c++;
   //     p = p->next;
   //     //printf("%d ..", c);
   // }

}



