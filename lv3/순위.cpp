#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/49191

int solution(int n, vector<vector<int>> results)
{
    vector<vector<bool>> bHas(n, vector<bool>(n, false));
    for (auto elem : results)
    {
        bHas[elem[0] - 1][elem[1] - 1] = true;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (bHas[k][i] && bHas[i][j])
                {
                    bHas[k][j] = true;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (bHas[i][j] || bHas[j][i])
            {
                cnt++;
            }
        }
        if (cnt == n - 1)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    cout << solution(5, { { 4, 3 }, { 4, 2 }, { 3, 2 }, { 1, 2 }, { 2, 5 } }) << endl;
    return 0;
}
