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

/*编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
int main() {

    class Solution {
    public:
        void reverseString(vector<char>& s) {
            int length = s.size() - 1;
            int i = 0;
            int j = length;
            for (; i<j; i++, j--) {//由于机构数的关系，不能用！=
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
            }
        }
    };
    Solution a;
    vector<char> s = { 'a','f','g','s' };
    a.reverseString(s);
    for(int i=0;i<s.size();i++)
    printf("%c  ", s[i]);

}
