#include <iostream>
#include <queue>
using namespace std;
void solve(priority_queue<int, vector<int>, greater<int>> &mini, priority_queue<int> &maxi, double &median, int element)
{
    // 1 case
    if (maxi.size() == mini.size())
    {
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else
        {
            maxi.push(element);
            median = maxi.top();
        }
    }
    else if (maxi.size() > mini.size())
    { // 2 case
        if (element > median)
        {
            mini.push(element);
        }
        else
        {
            int maxiTop = maxi.top();
            maxi.pop();
            mini.push(maxiTop);
            maxi.push(element);
        }
        median = (mini.top() + maxi.top()) / 2.0;
    }
    else if (mini.size() > maxi.size())
    { // 3 case
        if (element > median)
        {
            int miniTop = mini.top();
            mini.pop();
            maxi.push(miniTop);
            mini.push(element);
        }
        else
        {
            maxi.push(element);
        }
        median = (mini.top() + maxi.top()) / 2.0;
    }
}

int main()
{
    // int arr[]={5,13,1,3,2,8};
    int arr[] = {2, 2, 2, 2};
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    int n = sizeof(arr) / sizeof(arr[0]);
    double median = 0;
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        solve(mini, maxi, median, element);
        cout << "median element is -> " << median << endl;
    }
    return 0;
}
//**************************************************************************************
// using switch case
int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
}
void solve(priority_queue<int, vector<int>, greater<int>> &mini, priority_queue<int> &maxi, double &median, int element)
{

    switch (signum(maxi.size(), mini.size()))
    {
    case 0:
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else
        {
            maxi.push(element);
            median = maxi.top();
        }
        break;
    case 1:
        if (element > median)
        {
            mini.push(element);
        }
        else
        {
            int maxiTop = maxi.top();
            maxi.pop();
            mini.push(maxiTop);
            maxi.push(element);
        }
        median = (mini.top() + maxi.top()) / 2.0;
        break;
    case -1:
        if (element > median)
        {
            int miniTop = mini.top();
            mini.pop();
            maxi.push(miniTop);
            mini.push(element);
        }
        else
        {
            maxi.push(element);
        }
        median = (mini.top() + maxi.top()) / 2.0;
        break;
    }
}