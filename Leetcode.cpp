#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
using namespace std;
int main() {
    /*
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            std::unordered_map <char, int> map;
            int x=0;
            int k = 0;
            for (int i = 0; i < s.size(); i++)
            {
                auto iter = map.find(s[i]);
                k++;
                if (iter != map.end())
                {
                    
                    map.erase(iter);
                    k--;
                    if (x < k)
                        x = k;
                }
                map[s[i]];
            }
            return x;
        }
    };
    */


   /* class Solution {
    public:
        int findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2) {
            
            if (nums1.size() > nums2.size())
            {
                vector<int>temp = nums1;
                nums1 = nums2;
                nums2 = nums1;
            }
           
            int m = nums1.size();
            int n = nums2.size();
            int left = 0, right = m, toleft = (m + n + 1) / 2;
           // int index1 = 0, index2 = 0;
            while (left < right)
            {
               int index1 = left+(right-left+1)/ 2;
               int index2 = toleft - index1;
                if (nums1[index1 - 1] > nums2[index2])
                    right = index1 - 1;
                else
                    left = index1;
            }
            int index1 = left;
            int index2 = toleft - index1;
            int nums1LeftMax = index1 == 0 ? INT_MIN: nums1[index1 - 1];
            int nums1rightMin = index1 = m ? INT_MAX :nums1[index1];
            int nums2LeftMax = index2 == 0 ? INT_MIN: nums2[index2 - 1];
            int nums2rightMin = index2 == n ? INT_MAX : nums2[index2];

            if (((m + n) % 2) == 0)
                return (double)((max(nums1LeftMax, nums2LeftMax) + min(nums1rightMin, nums2rightMin))) / 2.0;
            else
                return (double)max(nums1LeftMax, nums2LeftMax);
           
           
        }


    };
    Solution s;
    vector<int>nums1 = {1,3};
    vector<int>nums2 = {2};
    printf("%d", s.findMedianSortedArrays(nums1, nums2));
    */

    //class Solution {
    //public:
    //    string convert(string s, int numRows) {
    //        s = s.c_str();
    //        string a = "";
    //        int k = numRows;
    //        printf("s: %s\n", s.c_str());
    //        for (int j = 0; j < k; j++)
    //        { 
    //            printf("j: %d\n", j);
    //            int b = j;
    //            a = a + s[j];
    //            int c = (numRows - 1) * 2;
    //            int m = (k - 1) * 2 - c;
    //            for (int i = 0; numRows>1&&((b + c <= s.size() -1)&&(i%2==0||m==0))
    //                ||((b + m <= s.size() - 1)&&(i%2!=0)&&(m!=0));i++) {
    //                printf("i: %d \n", i);
    //                printf("b: %d \n", b);

    //                if (i % 2 == 0||k==numRows) 
    //                    b = b + c;
    //                else
    //                    b = b + m;
    //                    a = a + s[b];
    //                printf("a: %s\n", a.c_str());
    //            }
    //            printf("num: %d\n", numRows);
    //            numRows--;
    //            if (numRows == 1)
    //                numRows = k;
    //          
    //        }
    //        return a.c_str();
    //    }
    //};

//
//class Solution {
//public:
//    string convert(string s, int numRows) {
//        int n = s.length(), r = numRows;
//        printf("s:%s\n", s.c_str());
//        if (r == 1 || r >= n) {
//            return s;
//        }
//        string ans;
//        int t = r * 2 - 2;
//        for (int i = 0; i < r; ++i) { // 枚举矩阵的行
//            printf("i%d\n", i);
//            for (int j = 0; j + i < n; j += t) { // 枚举每个周期的起始下标
//                ans += s[j + i]; // 当前周期的第一个字符
//                if (0 < i && i < r - 1 && j + t - i < n) {
//                    ans += s[j + t - i]; // 当前周期的第二个字符
//                   
//                   
//                }
//            }
//        }
//        return ans;
//    }
//};
//
//
//    string s = "PAYPALISHIRING";
//        int num = 4;
//        Solution a;
//   
//        printf("%s",a.convert(s,num));
//
//      



//class Solution {
//public:
//    int reverse(int x) {
//        int reserve = 0;
//        while (x!=0)
//        {
//        
//                reserve = reserve * 10 + x % 10;
//                x = x / 10;
//            
//            
//        }
//        return reserve;
//    }
//};
//int x = 1534236469;
//Solution a;
//printf("%d", a.reverse(x));

}
