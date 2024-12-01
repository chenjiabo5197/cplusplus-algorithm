#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        // 构成丑数的因子
        vector<long> factors = {2, 3, 5};
        set<long> mySet;
        // 优先队列，最小堆，每次弹出最小的元素(队首)
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        mySet.insert(1);
        int result = 1;
        for (int i = 0; i < n; ++i) {
            result = pq.top();
            pq.pop();
            for (int j = 0; j < factors.size(); ++j) {
                if (mySet.insert(result * factors[j]).second)
                {
                    pq.push(result * factors[j]);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    auto result = s.nthUglyNumber(10);
    std::cout << result << std::endl;
    return 0;
}

