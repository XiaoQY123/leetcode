#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
using namespace std;
int main() {
	/*
	* 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
	*/

	//class Solution {
	//public:
	//	bool isMatch(string s, string p) {
	//		int j = 0;
	//		int i = 0;
	//		for (; i < p.size()&&j<s.size();)
	//		{
	//			if ((p[0] == '.' && p.size()==1&&s.size()==1)||p[i]=='.'&&(i+1==p.size()&&j+1==s.size()))
	//				return true;
	//			if (p[i] == '.' && i + 1 < p.size() && p[i+1] == '*')
	//			{
	//				//匹配后面的元素
	//				while (p[i+2] != s[j] && j < s.size())
	//				{
	//					j++;

	//				}
	//				printf("1:i,j %d,%d\n", i, j);
	//				i=i+2;
	//			}
	//			else if ((p[i] == '.' && (i + 1 < p.size() && p[i + 1] != '*')) || p[i] == s[j])
	//			{
	//				printf("2:i,j %d,%d\n", i, j);
	//				i++;
	//				j++;
	//				
	//			}
	//			else if (p[i] == '*' && i - 1 >= 0 && p[i - 1] != '.')
	//			{//匹配到不相同的时候
	//				while (p[i - 1] == s[j] && j < s.size()) {
	//					j++;
	//				}
	//				i++;
	//			
	//				printf("3:i,j %d,%d\n", i, j);
	//			}
	//			else if (p[i]!=s[j]&&i + 1 < p.size()&&p[i+1]=='*')
	//			{
	//				if (p[i + 2] == s[j]||p[i+2]=='.')
	//				{
	//					printf("4:i,j %d,%d\n", i, j);
	//					i += 2;
	//				}
	//				else
	//				{
	//					printf("5:");
	//					return false;
	//				}
	//			
	//			}
	//			else
	//			{
	//				printf("4;");
	//				return false;
	//			}
	//			//当s匹配完但p没有匹配完时
	//			
	//			while (j >= s.size() && i < p.size()&& (p[i] == s[j - 1]&&p[i+1]=='*' ||
	//				p[i + 1] == '*' || p[i] == '*' || p[i] == '.'||i+1==p.size()&&p[i]==s[j-1]))
	//			{
	//				i++;
	//			}
	//			printf("i:%d\n", i);
	//		}
	//		if (j >=s.size()&&i>=p.size())
	//			return true;
	//		else
	//			return false;
	//	}
	//};
//   垃圾代码:291/356,最后一个没过的是s="aaa";p="aaaaaa",return false
	class Solution {
	public:
		bool isMatch(string s, string p) {
			int m = s.size();
			int n = p.size();

			auto matches = [&](int i, int j) {
				if (i == 0) {//对第一行' '的处理 
					return false;
				}
				if (p[j - 1] == '.') {
					return true;
				}
				return s[i - 1] == p[j - 1];
			};

			vector<vector<int>> f(m + 1, vector<int>(n + 1));
			f[0][0] = true;//默认为0，即为F
		
			for (int i = 0; i <= m; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (p[j - 1] == '*') {//对于"*"时，如果前面空一格的f为T，则为T；
						f[i][j] |= f[i][j - 2];//如果为F观察是否该点这一行s与前一列对应的p是否相等，如果相等则观察上一行该列的T,F并与之相同。
						if (matches(i, j - 1)) {//如果不相同，则直接F
                        //输入j-1，更好处理，前一列的对比；
							f[i][j] |= f[i - 1][j];
						}
					}
					else {
						if (matches(i, j)) {//对于其他情况，如果相同，则返回斜上角的相同的T,F，否则，则直接F
							f[i][j] |= f[i - 1][j - 1];
						}
					}
				}
			}
		
			return f[m][n];
		}
	};

	Solution a;
	string s = "aaabcaab";
	string p = "a*b.a*b";
	printf("%d", a.isMatch(s, p));
	
	
}