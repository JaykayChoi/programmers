#include <set>
#include <string>
#include <vector>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/43162

// my solution.
void link(vector<vector<int>>& computers, set<int>& linkedComs, int idx)
{
    vector<int> coms = computers[idx];
    for (int i = 0; i < coms.size(); i++)
    {
        if (i == idx)
        {
            continue;
        }
        if (coms[i] == 0)
        {
            continue;
        }
        set<int>::iterator itr = linkedComs.find(i);
        if (itr != linkedComs.end())
        {
            continue;
        }
        linkedComs.insert(i);
        link(computers, linkedComs, i);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    set<int> linkedComs;
    for (int i = 0; i < n; i++)
    {
        set<int>::iterator itr = linkedComs.find(i);
        if (itr != linkedComs.end())
        {
            continue;
        }
        answer++;
        vector<int> coms = computers[i];
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (coms[j] == 0)
            {
                continue;
            }
            linkedComs.insert(i);
            linkedComs.insert(j);
            link(computers, linkedComs, j);
        }
    }

    return answer;
}

// best solusions.
void dfs(int from, int n, vector<int>& visited, vector<vector<int>>& computers)
{
    for (int i = 0; i < n; i++)
    {
        if (from == i)
        {
            continue;
        }
        if (computers[from][i] == 0)
        {
            continue;
        }
        if (visited[i] == 1)
        {
            continue;
        }
        visited[i] = 1;
        dfs(i, n, visited, computers);
    }
}

int solution2(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }

        answer++;
        visited[i] = 1;
    }

    return answer;
}