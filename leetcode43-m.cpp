#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
using namespace std;


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
//int main() {
//   
//    class Solution {
//    public:
//        string multiply(string nums1, string nums2) {
//         
//            int m = nums2.size();
//            int n = nums1.size();
//            string arr = "";
//            int j = 0;
//            for (int i = nums1.size() - 1; i >= 0; i--) {
//
//                for (j = nums2.size()-1; j>=0; j--) {
//                    int a = (nums1[i] - '0') * (nums2[j] - '0');
//                    m = a / 10;
//                    a = a % 10;
//  
//                  
//                }
//               
//            }
//           
//
//            return sum;
//        }
//    };

//做加法
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for (auto& c : curr) {
                c += '0';
            }
            ans = addStrings(ans, curr);
        }
        return ans;
    }

    string addStrings(string& num1, string& num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto& c : ans) {
            c += '0';
        }
        return ans;
    }
};


    Solution a;
    string nums1 = "123";
    string nums2 = "109";
    //int target = 2;
    printf("%d", a.multiply(nums1, nums2));
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



