#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
using namespace std;
int main() {
	/*
	给你一个整数，将其转为罗马数字。*/
	class Solution {
	public:
		string intToRoman(int num) {
			string ronam = "";
			int i = 3;
			int k = 7;
			char R[]={'I','V','X','L','C','D','M','\0'};
			//string R = "IVXLCDM";
			while (num >0)
			{
				int q = num / pow(10,i);
				num = num % (int)pow(10, i);
				if (q == 4) {
					ronam = ronam + R[k - 1] + R[k];
					q = 0;
				}
				if (q == 9)
				{
					ronam = ronam + R[k - 1] + R[k + 1];
					q = 0;
				}
				if (q>=5&&q<9) {
					ronam = ronam + R[k];
					q = q - 5;
				}
				for (int j = 0; j < q; j++) {
					
					ronam = ronam + R[k-1];
				}
				k-=2;
				i--;
			}
		
			return ronam;
		}
	};
	//执行时间8ms

	//官方方法1，执行时间较短4ms,贪心算法
	/*
	const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        for (const auto &[value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};*/
	Solution a;
	int num =3645;
	
	printf("%s", a.intToRoman(num).c_str());

}