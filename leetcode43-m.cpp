#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
#include<queue>
using namespace std;

/*43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。*/
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

    //做加法
    //class Solution {
    //public:
    //    string multiply(string num1, string num2) {
    //        if (num1 == "0" || num2 == "0") {
    //            return "0";
    //        }
    //        string ans = "0";
    //        int m = num1.size(), n = num2.size();
    //        for (int i = n - 1; i >= 0; i--) {
    //            string curr;
    //            int add = 0;
    //            for (int j = n - 1; j > i; j--) {//进位添0
    //                curr.push_back(0);
    //            }
    //            int y = num2.at(i) - '0';
    //            for (int j = m - 1; j >= 0; j--) {
    //                int x = num1.at(j) - '0';
    //                int product = x * y + add;
    //                curr.push_back(product % 10);
    //                add = product / 10;
    //                
    //            }
    //            if(add!=0)
    //                curr.push_back(add % 10);//最后一步的进位
    //            reverse(curr.begin(), curr.end());//转化为字符
    //            for (auto& c : curr) {//这样循环额
    //                c += '0';
    //            }
    //            ans = addStrings(ans, curr);
    //        }
    //        return ans;
    //    }
    //
    //    string addStrings(string& num1, string& num2) {//上下层相加
    //        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
    //        string ans;
    //        while (i >= 0 || j >= 0 || add != 0) {
    //            int x = i >= 0 ? num1.at(i) - '0' : 0;//对最后一次相加的判断，添0
    //            int y = j >= 0 ? num2.at(j) - '0' : 0;
    //            int result = x + y + add;
    //            ans.push_back(result % 10);
    //            add = result / 10;
    //            i--;
    //            j--;
    //        }
    //        reverse(ans.begin(), ans.end());//反转该字符串
    //        for (auto& c : ans) {
    //            c += '0';
    //        }
    //        return ans.c_str();
    //    }
    //};
    //做乘法
    class Solution {
    public:
        string multiply(string num1, string num2) {
            if (num1 == "0" || num2 == "0") {
                return "0";
            }
            int m = num1.size(), n = num2.size();
            auto ansArr = vector<int>(m + n);//两数相乘的最大长度
            for (int i = m - 1; i >= 0; i--) {
                int x = num1.at(i) - '0';
                for (int j = n - 1; j >= 0; j--) {
                    int y = num2.at(j) - '0';
                    ansArr[i + j + 1] += x * y;//从最后一位添加元素
                }
            }
            for (int i = m + n - 1; i > 0; i--) {//开始进位
                ansArr[i - 1] += ansArr[i] / 10;
                ansArr[i] %= 10;
            }
            int index = ansArr[0] == 0 ? 1 : 0;
            string ans;
            while (index < m + n) {
                ans.push_back(ansArr[index]);//判断从哪一位开始进行插入，从前往后插入，达到反转列表效果
                index++;
            }
            for (auto& c : ans) {//转化为字符
                c += '0';
            }
            return ans;
        }
    };
    // 乘法比加分快很多额
    Solution a;
    string nums1 = "123";
    string nums2 = "109";
    printf("%s", a.multiply(nums1, nums2).c_str());
}
//int target = 2;
// printf("%s", a.multiply(nums1, nums2));
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





