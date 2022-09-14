#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
using namespace std;

/*54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。。*/
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
//
int main() {
   
    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {

            vector<vector <int>> matrix(n, vector<int>(n));
            if (n == 0) return matrix; //若数组为空，直接返回答案
            int u = 0; //赋值上下左右边界
            int d = n - 1;
            int l = 0;
            int r = n - 1;
            int count = 1;
            while (true)
            {
                for (int i = l; i <= r; ++i) matrix[u][i] = count++; //向右移动直到最右
                if (++u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
                for (int i = u; i <= d; ++i)  matrix[i][r] = count++; //向下
                if (--r < l) break; //重新设定有边界
                for (int i = r; i >= l; --i) matrix[d][i] = count++; //向左
                if (--d < u) break; //重新设定下边界
                for (int i = d; i >= u; --i)  matrix[i][l] = count++; //向上
                if (++l > r) break; //重新设定左边界
            }
            return matrix;
        }
    };

    

    Solution a;
    int n = 3;
    vector<vector<int>> nums = a.generateMatrix(n);
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d  ", nums[i][j]);
        printf("\n");

    }
}



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





