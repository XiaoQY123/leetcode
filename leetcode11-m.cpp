#include<stdio.h>
#include<map>
#include<string>
#include <unordered_map>
using namespace std;
int main() {
	class Solution {
	public:
		int maxArea(vector<int>& height) {
			
			int i = 0;
			int j = height.size() - 1;
			int maxnum = min(height[i], height[j]) * (j - i);
			
			for (; i<j; )
			{
				
				if (height[i] < height[j])
					i++;
				else
					j--;
				maxnum = max(maxnum, min(height[i], height[j]) * (j - i));

			}
			return maxnum;
		}
	};

	Solution a;
	vector<int> height = { 1,8,6,2,5,4,8,3,7 };
	printf("%d",a.maxArea(height));
	
	
}