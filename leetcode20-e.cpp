#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
#include <stack>
using namespace std;


 /*给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
int main() {
    class Solution {
    public:
        bool isValid(string s) {
            stack<char> stk1;
            if (s.size() % 2 != 0)
                return false;
            for (int i = 0; i < s.size(); i++) {

                if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                    stk1.push(s[i]);

                }
                else {
                    if (stk1.empty())
                        return false;
                    if (s[i] == ']') {
                        if (stk1.top() != '[')
                            return false;
                    }
                    if (s[i] == '}') {
                        if (stk1.top() != '{')
                            return false;
                    }
                    if (s[i] == ')') {
                        if (stk1.top() != '(')
                            return false;
                    }
                    stk1.pop();
                }
            }
            if (stk1.empty())
                return true;
            return false;
        }
    };

        Solution a;
        string s = "}[]";
        printf("%d", a.isValid(s));
  }

   
  
    ////ListNode* head = new ListNode(1);
    ////ListNode* h = new ListNode(2);
    ////head->next = h;
    ////ListNode * hh = new ListNode(3);
    ////h->next=hh;
    ////Solution a;
    ////ListNode* ret = a.removeNthFromEnd(head, 2);
    ////ListNode* p = ret;
    ////int c = 0;
    ////for (; p!=nullptr;) {
    ////    printf("%d  ", p->val);
    ////    //c++;
    ////    p = p->next;
    ////   // printf("%d ..", c);
    
