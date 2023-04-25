#include <bits/stdc++.h>
#include <vector>
using namespace std;


void sortActivity(vector<int> &start, vector<int> &finish, vector<int> &activity)
{
    for (int i = 0; i < finish.size() - 1; i++)
    {
        for (int j = 0; j < finish.size() - i - 1; j++)
        {
            if (finish[j] > finish[j + 1])
            {
                swap(activity[j], activity[j + 1]);
                swap(start[j], start[j + 1]);
                swap(finish[j], finish[j + 1]);
            }
        }
    }
}

void activitySelection(vector<int> start, vector<int> finish, vector<int> activity)
{
    int pre = 0;
    cout<<"Activity 1";

    for (int i = 1; i < finish.size(); i++)
    {
        if (start[i] >= finish[pre])
        {
            cout<<"Activity "<< activity[i];
            pre = i;
        }
    }
}

int main()
{
    vector<int> start, finish, activity;

    activity = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    start = {1, 0, 3, 3, 5, 5, 6, 8, 8, 2, 12};
    finish = {4, 6, 5, 8, 7, 9, 10, 11, 12, 13, 14};

    sortActivity(start, finish, activity);
    activitySelection(start, finish, activity);

    return 0;
}