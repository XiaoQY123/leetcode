#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
using namespace std;
int main() {
	/*
	* 
    
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
提示：

0 <= s.length <= 200
s 由英文字母（大写和小写）、数字（0-9）、' '、'+'、'-' 和 '.' 组成
*/
	class Solution {
	public:
		int myAtoi(string s) {
			int k = 0;
			bool flag = 0;
			double num = 0;
			for (int i = 0; i < s.size(); i++)
			{

				if ((s[i] <= 'z' && s[i]>='A') || (i + 1) < s.size() && (s[i] == '+' || s[i] == '-')
					&& (s[i + 1] > '9' || s[i + 1] < '0') || s[i] == '.')
				{
					break;
				}
				k++;
				if (s[i] <= '9' && s[i]>='0')
				{
					k--;
					flag = 1;
					printf("s[i]: %c\n",s[i]);
					num = num * 10 + (s[i]-'0');
					printf("num: %lf\n", num);
				}
				else if (flag == 1)
				{
					k--;
					break;
				}
			}
			printf("k: %d\n", k);
			if (k>0&&s[k - 1] == '-')
				num = -num;
			return (int)num;
			
		}
	};

	//自动机

	/*
	class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;//isspace（）空格返回true,否则返回flase
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];//自动机，消除冗杂；
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")//符号
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
*/
	Solution s;
	string x = "     z12067693647";
	printf("%d", s.myAtoi(x));
}
