#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
using namespace std;
int main() {
	/*
	给定一个罗马数字，将其转换成整数。*/
	

	class Solution {
	public:
		int romanToInt(string s) {
			unordered_map<char, int> symbolValues = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
			};
			int num = 0;
			for (int i = 0; i < s.size(); i++)
			{

				int n = symbolValues[s[i]];
				if (n < symbolValues[s[i + 1]] && i < s.size() - 1)
				{
					num = num - n;
				}
				else
					num = num + n;

			}
			
			return num;
		}
	};
	Solution a;
	string roman= "IV";
	
	printf("%d", a.romanToInt(roman));

}