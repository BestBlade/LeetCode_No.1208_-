/* ------------------------------------------------------------------|
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了98.68%的用户
*	内存消耗：7.3 MB, 在所有 C++ 提交中击败了97.35%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


int equalSubstring(string s, string t, int maxCost) {
    //int costsum = 0;
    //int res = 0;
    //int left = 0;
    //int right = 0;
    //while (right < s.size()) {
    //    if (costsum + abs(s[right]-t[right]) <= maxCost) {
    //        costsum += abs(s[right] - t[right]);
    //        res = max(res, right - left + 1);
    //        right++;
    //    }
    //    else {
    //        costsum -= abs(s[left] - t[left]);
    //        left++;
    //    }
    //}
    //return res;

    //这种方法更巧妙
    int l = 0;
    int r = 0;
    int cost = 0;
    while (r < s.size()) {
        //如果窗口可以扩大，就扩大窗口
        cost += abs(s[r] - t[r++]);
        //否则就l跟随r一起+1，维持这个最大窗口
        if (cost > maxCost) {
            cost -= abs(s[l] - t[l++]);
        }
    }
    return r - l;
}

int main() {
    string s = "abcd";
    string t = "cdef";
    equalSubstring(s, t, 3);
}