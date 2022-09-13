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
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ret;
            int a = INT_MAX;
            bool flage1 = true;
            bool flage2 = true;
            int count = 0;
            int i = 0, j = -1;
            for (int k = 0; count < matrix[0].size() * matrix.size(); k++) {
                if (k % 2 != 0 && flage1 == true) {
                    printf("1--  ");
                    i = i + 1;
                    while (i < matrix.size() && matrix[i][j] != a) {
                        printf("1  ");
                        count++;
                        ret.push_back(matrix[i][j]);
                        printf("ma:%d   ", matrix[i][j]);
                        matrix[i][j] = a;
                        i++;
                    }
                   
                    i--;
                    printf("i,j %d,%d\n", i, j);
                    flage1 = false;
                    continue;

                }
                else if (k % 2 == 0 && flage2 == true) {
                    j = j + 1;
                    printf("2--  ");
                    while (j < matrix[0].size() && matrix[i][j] != a) {
                        printf("2  ");
                        ret.push_back(matrix[i][j]);
                        printf("ma:%d   ", matrix[i][j]);
                        matrix[i][j] = a;
                        j++;
                        count++;
                    }
                    j--;
                    printf("i,j %d,%d\n", i, j);
                    flage2 = false;
                    continue;
                }
                else if (k % 2 != 0 && flage1 == false) {
                    printf("3--  ");
                   i = i - 1;
                    while (i>=0&&matrix[i][j] != a) {
                        printf("3  ");
                       
                        ret.push_back(matrix[i][j]);
                        printf("ma:%d   ", matrix[i][j]);
                        matrix[i][j] = a;
                        i--;
                        count++;
                    }
                    i++;
                    printf("i,j %d,%d\n", i, j);
                    flage1 = true;
                    continue;

                }
                else if (k % 2 == 0 && flage2 == false) {
                    printf("4--  ");
                    j = j - 1;
                    while (j >= 0&& matrix[i][j] != a) {
                        printf("4  ");
                        ret.push_back(matrix[i][j]);
                        printf("ma:%d   ", matrix[i][j]);
                        matrix[i][j] = a;
                        count++;
                        j--;
                    }
                    j++;
                    printf("i,j %d,%d\n", i, j);
                    flage2 = true;
                    continue;
                }
                else
                {
                    printf("xijoakx");
                    return {};
                }
            }
            return ret;
        }

    };
   

    Solution a;
    vector<vector<int>> nums = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
    vector<int> ret = a.spiralOrder(nums);
    for (int i = 0; i < ret.size(); i++) {
        printf("%d  ", ret[i]);
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





