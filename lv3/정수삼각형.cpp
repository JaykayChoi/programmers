#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/43105

int solution(vector<vector<int>> triangle)
{
    int cache[2][500];
    int n = triangle.size();
    for (int i = 0; i < n; i++)
    {
        cache[(n - 1) % 2][i] = triangle[n - 1][i];
    }

    for (int y = n - 2; y >= 0; y--)
    {
        for (int x = 0; x <= y; x++)
        {
            cache[y % 2][x]
                = max(cache[(y + 1) % 2][x], cache[(y + 1) % 2][x + 1]) + triangle[y][x];
        }
    }

    return cache[0][0];
}

int main()
{
    //
    return 0;
}