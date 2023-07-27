#include <bits/stdc++.h>
#include <iostream>

using namespace std;
struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs > rhs;
    }
};
// void printQueue(T& q)
// {
//     while (!q.empty())
//     {
//         cout << q.top() << endl;
//         q.pop();
//     }
// }
void SamplePriorityQueueWithCustomComparator()
{
    priority_queue<int,vector<int>, CustomCompare > pq;

    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(8);

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
int main()
{
  SamplePriorityQueueWithCustomComparator();
    vector<int>t={3,5,1,8};
    sort(t.begin(),t.end(),CustomCompare());
    cout<<"\narray:\n";
    for(auto x:t)
    cout<<x<<" ";
    return 0;
}
