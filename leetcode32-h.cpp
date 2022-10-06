
//题目：
/*32. 最长有效括号
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。*/

//1.线性规划，我不理解，我恨啊
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};


//前后遍历，取最大
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int len = 0;

        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                len = max(len, 2*left);
            } else if (left < right) {
                left = right = 0;
            }
        }
        //得到len的值，如果左括号多余右括号
        //反向
        left = right = 0;
        for(int i = s.length()-1; i >= 0; --i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                len  =max(len, 2*left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return len;
    }
};

//栈,也挺妙的
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);//也挺妙的
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);//妙啊，存储的数字
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);//不更换继续
                } else {//更换新的开始
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};
