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
/*22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用
于能够生成所有可能的并且 有效的 括号组合。*/

int main() {
    //class Solution {
    //public:
    //    vector <string> ret;
    //    vector<char> str = { '(',')' };
    //    string aa ="";
    //    vector<string> generateParenthesis(int n) {
    //        Fus(n);
    //       return ret;
    //    }
    //    //思路有问题；运行一遍看看，有点想当然了
    //    void Fus(int n) {
    //        aa.push_back('(');
    //        if (aa.size()== 2 * n - 1) {
    //            aa.push_back(')');
    //            ret.push_back(aa);
    //            return;
    //        }
    //        for (int i = 0; i < 2; i++) {
    //            aa.push_back(str[i]);
    //            Fus(n);
    //            aa.pop_back();
    //        }
    //    }
    //};

    class Solution {
        void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
            if (cur.size() == n * 2) {
                ans.push_back(cur);
                return;
            }
            //保证左右括号数相同
            //先open,再close，注意顺序
            if (open < n) {
                cur.push_back('(');
                backtrack(ans, cur, open + 1, close, n);
                cur.pop_back();
            }
            if (close < open) {
                cur.push_back(')');
                backtrack(ans, cur, open, close + 1, n);
                cur.pop_back();
            }
        }
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            string current;
            backtrack(result, current, 0, 0, n);
            return result;
        }
    };
    Solution a;
    vector<string> s = a.generateParenthesis(3);
    for(int i=0;i<s.size();i++)
    printf("%s  ", s[i].c_str());

}