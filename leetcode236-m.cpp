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

/*236. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
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
//运行时间快

    //改代码最好画图演示一遍
    class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (!root) return NULL;
            //开始递归返回
            if ((root->val == p->val) || root->val == q->val) return root;
            auto findleft = lowestCommonAncestor(root->left, p, q);
            auto findright = lowestCommonAncestor(root->right, p, q);


          //对子树中没有目标节点的子树中，返回的一定是null，直到递归到有目标节点的那个层次
            //画个图吧
            if (findleft && findright) return root;
            else if (findright) return findright;
            else return findleft;
        }
    };
  
    
    //官方代码
    //class Solution {
    //public:
    //    TreeNode* ans;
    //    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {//尝试使用bool类型来表示
    //        if (root == nullptr) return false;
    //        bool lson = dfs(root->left, p, q);
    //        bool rson = dfs(root->right, p, q);
    //        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
    //            ans = root;
    //        }
    //        返回条件为，只要任意一个子树中含有p or q的元素，都表示那一颗子树为真。
    //        若该节点元素相同与p or q 相同 ,也表示这颗子树为真 
    //        return lson || rson || (root->val == p->val || root->val == q->val);

    //    }
    //    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //        dfs(root, p, q);
    //        return ans;
    //    }
    //};




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





