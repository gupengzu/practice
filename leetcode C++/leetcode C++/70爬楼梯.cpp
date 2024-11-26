#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        int a = 1;
        int b = 2;
        int c = 0;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};

int  main()
{
    Solution s;
    int a = s.climbStairs(45);
    cout << "答案是：" << a << endl;
    return 0;
}
