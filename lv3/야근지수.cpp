#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/12927

long long solution(int n, vector<int> works)
{
    sort(works.begin(), works.end(), greater<int>());
    set<int> nums;
    int numWorks = works.size();
    for (int i = 0; i < numWorks; i++)
    {
        nums.insert(works[i]);
    }

    set<int>::reverse_iterator rit;
    int workload = 0;
    int nextIdx = 0;
    for (rit = nums.rbegin(); rit != nums.rend(); rit++)
    {
        int cur = *rit;
        int next = 0;
        rit++;
        if (rit != nums.rend())
        {
            next = *rit;
        }
        rit--;
        int diff = cur - next;

        for (; nextIdx < numWorks;)
        {
            if (works[nextIdx] == next)
            {
                break;
            }
            nextIdx++;
        }

        int remainingWorkload = max(0, n - workload);
        if (diff * nextIdx <= remainingWorkload)
        {
            for (int i = 0; i < nextIdx; i++)
            {
                works[i] = next;
            }

            workload += diff * nextIdx;

            if (n == workload)
            {
                break;
            }
        }
        else
        {
            int quotient = remainingWorkload / nextIdx;
            int remainder = remainingWorkload - (nextIdx * quotient);

            int v = cur - quotient;

            for (int i = 0; i < nextIdx; i++)
            {
                works[i] = v;
                if (remainder > 0)
                {
                    works[i]--;
                    remainder--;
                }
            }

            break;
        }
    }

    long long answer = 0;
    for (int x : works)
    {
        answer += x * x;
    }

    return answer;
}

int main()
{
    cout << solution(1, { 2, 1, 2 }) << endl;
    return 0;
}