#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	/*给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

    class Solution {

    public:

		vector<string> ret;//保存所有结果组合
		unordered_map<int, string> valueSymbols = {
			  {2,"abc"},
			  {3,"def"},
			  {4,"ghi"},
			  {5,"jkl"},
			  {6,"mno"},
			  {7,"pqrs"},
			  {8,"tuv"},
			  {9,"wxyz"},
		};
		vector<string> letterCombinations(string digits) {
			if (digits.size() == 0)//特殊情况
				return ret;
			string cur;
			di(digits, cur, digits.size(),0);
			
			    return ret;
		}
		void di(string digits,string cur,int count,int n) {
			printf("%d.............\n", count);
			if (cur.size() == count) {
				ret.push_back(cur);
				return;//返回上层(n)
			}
			int a = digits[n] - '0';//字符转int
			//printf("%s\n", valueSymbols[a].c_str());
			for (int i = 0; i < valueSymbols[a].size(); i++)
			{
				cur.push_back(valueSymbols[a][i]);
				di(digits, cur, count, n+1);//回溯
				cur.pop_back();//删除最后一个数字，在该层(n)循环。
			}
		}
  
    };
    vector<string> c;
    Solution a;
    string digits = "234";
    c = a.letterCombinations(digits);
	for(int i=0;i<c.size();i++)
    printf("%s  ",c[i]);
}