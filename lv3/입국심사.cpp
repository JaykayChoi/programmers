#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/43238

typedef long long ll;

ll solution(int n, vector<int> times)
{
    ll low = 0;
    ll high = (ll)*max_element(times.begin(), times.end()) * n;

    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll time = 0;
        for (int x : times)
        {
            time += mid / x;
        }

        if (time >= n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    cout << solution(6, { 7, 10 }) << endl;
    return 0;
}