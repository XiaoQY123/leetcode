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

/*给定一个二叉搜索树的根节点 root ，和一个整数 k ，
请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
 */

 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int main() {
    //暴力解法
    //class Solution {
    //    vector<int> nums;
    //public:
    //    int kthSmallest(TreeNode* root, int k) {
    //        //遍历，排序
    //        traverse(root);
    //        sort(nums.begin(), nums.end());
    //        return nums[k - 1];

    //    }

    //    void traverse(TreeNode* node) {
    //        if (node) {
    //            traverse(node->left);
    //            nums.push_back(node->val);//中序遍历
    //            traverse(node->right);
    //        }
    //    }
    //};

    //因为是二叉搜索数，所以，中序遍历即是排序后的顺序(但是不能是递归遍历)
    //中序的非递归遍历
    class Solution {
    public:
        int kthSmallest(TreeNode* root, int k) {
            stack<TreeNode*> stack;
            while (root != nullptr || stack.size() > 0) {
                while (root != nullptr) {
                    stack.push(root);//存储左子树的数据
                    root = root->left;
                }
                root = stack.top();
                stack.pop();
                --k;//当找到第k个元素，退出
                if (k == 0) {
                    break;
                }
                root = root->right;
            }
            return root->val;
        }
    };

    Solution a;
 


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





