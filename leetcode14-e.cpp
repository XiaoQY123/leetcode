#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
using namespace std;
int main() {
	
/*编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。*/

	//暴力解法:纵向遍历
	//class Solution {
	//public:
	//	string longestCommonPrefix(vector<string>& strs) {
	//		string a = "";
	//		int j = 0;
	//		int i = 0;
	//		if (strs.size() == 1)
	//			return strs[0];
	//		for (j = 0;; j++) {
	//			for (i = 0; i < strs.size() - 1; i++)
	//			{
	//				if (strs[i][j] == '\0' || strs[i][j] != strs[i + 1][j])
	//				{
	//					return a;
	//				}
	//			}
	//			a = a + strs[i][j];
	//			
	//		}
	//		return a.c_str();
	//	}
	//};

	//官方1.横向遍历，找相邻最大公共前缀时间复杂度n(mn),
	//官方3.分治，与方法1类似n(mn)
	class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        else {
            return longestCommonPrefix(strs, 0, strs.size() - 1);
        }
    }

    string longestCommonPrefix(const vector<string>& strs, int start, int end) {
        if (start == end) {
            return strs[start];
        }
        else {
            int mid = (start + end) / 2;
            string lcpLeft = longestCommonPrefix(strs, start, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, end);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    string commonPrefix(const string& lcpLeft, const string& lcpRight) {
        int minLength = min(lcpLeft.size(), lcpRight.size());
        for (int i = 0; i < minLength; ++i) {
            if (lcpLeft[i] != lcpRight[i]) {
                return lcpLeft.substr(0, i);
            }
        }
        return lcpLeft.substr(0, minLength);
    }
};

	//二分查找，n(mnlogm)
	/*class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        int minLength = min_element(strs.begin(), strs.end(), [](const string& s, const string& t) {return s.size() < t.size();})->size();
        int low = 0, high = minLength;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (isCommonPrefix(strs, mid)) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
        return strs[0].substr(0, low);
    }

    bool isCommonPrefix(const vector<string>& strs, int length) {
        string str0 = strs[0].substr(0, length);
        int count = strs.size();
        for (int i = 1; i < count; ++i) {
            string str = strs[i];
            for (int j = 0; j < length; ++j) {
                if (str0[j] != str[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
*/
	Solution a;
	vector<string> strs = { "flower","flow","flght","fab" };
	printf("%s", a.longestCommonPrefix(strs).c_str());
}