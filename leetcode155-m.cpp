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
using namespace std;

/*设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct Status {
    int val;
    ListNode* ptr;
    bool operator < (const Status& rhs) const {
        return val > rhs.val;
    }
};




  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
  int main() {




      class MinStack {//速度快，使用了两个栈
      public:
          stack<int>stk, f;
          MinStack() {

          }

          void push(int val) {
              stk.push(val);
              if (f.empty() || val <= f.top())f.push(val);//解决边界问题，更新最小值，在栈顶，必须要等于符号判断

          }

          void pop() {
              if (stk.top() == f.top())f.pop();//当pop一个数的时候，由于先进后出的栈的特性
              stk.pop();//如果不相等的话，说明，最大值是比stk.pop先进栈的，不会被删除。
              //如果相同的话，就说明要删除的也是当前最大值，删除f.pop；更新最小值

          }

          int top() {
              return stk.top();

          }

          int getMin() {
              return f.top();

          }
      };


     /* class MinStack {//内存使用较小，使用一个栈，一个普通变量
      private:
          stack<long long> m_diffStk;
          long long m_iMin;
      public:
          MinStack() {
              m_iMin = INT_MAX;//初始化，好像可以不写额
          }

          void push(int val) {
              if (m_diffStk.size() == 0)//边界处理
              {
                  m_diffStk.push(0);
                  m_iMin = val;
              }
              else
              {
                  long long diff = val - m_iMin;
                  m_diffStk.push(diff);
                  m_iMin = diff > 0 ? m_iMin : val;//m_iMin的值是val的小值的更新
              }
          }

          void pop() {
              long long diff = m_diffStk.top();
              m_diffStk.pop();
              if (diff > 0)//val大于m_imin,即m_imin没有更新，是之前的的元素为最大值，可以直接删除
              {
                  // val - min_ = diff
                  // diff > 0 => val > min_
                  // =>min = min_
                  // val = min_ + diff = min + diff
                  // m_iMin = m_iMin;
              }
              else  // diff <= 0，即m_imin更新了
              {
                  // val - min_ = diff
                  // diff < 0 => val < min_
                  // => min = val = diff + min_;
                  // min_ = min - diff; 然后将min赋值为min_
                  // val = diff + min_ = min
                  m_iMin = m_iMin - diff;
              }
          }

          int top() {
              long long diff = m_diffStk.top();
              if (diff > 0)
              {
                  //val>min
                  //val=diff+min(因为min没有更新)
                  return m_iMin + diff;
              }
              else
              {
                  //val<=min
                  //min更新了
                  //val=min
                  return m_iMin;
              }
          }

          int getMin() {
              return m_iMin;
          }
      };*/

      /**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
      MinStack m;
      m.push(-2);
      m.push(0);
      m.push(-3);
      int c=m.getMin();
      m.pop();
      m.pop();
      int d=m.getMin();
      printf("c,d %d,%d", c, d);


      
  }




   /*  ListNode* head = new ListNode(1);
     ListNode* h = new ListNode(2);
     head->next = h;
     ListNode* hh = new ListNode(3);
     h->next = hh;*/


    //ListNode* head2 = new ListNode(1);
    //ListNode* h2 = new ListNode(3);
    //head2->next = h2;
    //ListNode* hh2 = new ListNode(4);
    //h2->next = hh2;

    //ListNode* head3 = new ListNode(2);
    //ListNode* h3 = new ListNode(6);
    //head3->next = h3;
    // ListNode* hh3 = new ListNode(17);
    // h3->next = hh3;

   /* vector<ListNode*> lists;
    lists.push_back(head);*/
    //lists.push_back(head2);
    //lists.push_back(head3);

    //Solution a;
    //ListNode* ret = a.rotateRight(head,1);
    //ListNode* p = head;
    //int c = 0;
    //for (; p != nullptr;) {
    //    printf("%d  ", p->val);
    //    // c++;
    //    p = p->next;
    //    //printf("%d ..", c);
    //}
//}





