/*
Lakshay Khurana
2203312
MnC
*/

// Q1

#include <iostream>
#include <vector>
using namespace std;

vector<int> a = {-4,5,-2,15,-8,-11,8,-3,4,-7}; 
int n = 10;


int sumarr(vector<int> ans)
{
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        sum += ans[i];
    }
    return sum;
}

int endswith(int i, int &startindex)
{
    if (i == 0)
    {
        startindex = 0;
        return a[i];
    }

    int prevSum = endswith(i - 1, startindex);
    if (a[i] > prevSum + a[i])
    {
        startindex = i;
        return a[i];
    }
    else
    {
        return prevSum + a[i];
    }
}

int startswith(int i, int &endindex)
{
    if (i == n - 1)
    {
        endindex = n - 1;
        return a[i];
    }

    int nextSum = startswith(i + 1, endindex);
    if (a[i] > nextSum + a[i])
    {
        endindex = i;
        return a[i];
    }
    else
    {
        return nextSum + a[i];
    }
}

vector<int> subarray(int start, int end)
{

    if (start == end)
    {
        vector<int> ans;
        ans.push_back(a[start]);
        return ans;
    }
    if (start < end)
    {
        int mid = (start + end) / 2;

        vector<int> ans1 = subarray(start, mid);
        vector<int> ans2 = subarray(mid + 1, end);
        vector<int> ans3;
        int startindex = -1;
        endswith(mid, startindex);
        int endindex = -1;
        startswith(mid + 1, endindex);

        for (int i = startindex; i <= endindex; i++)
        {
            ans3.push_back(a[i]);
        }
        cout<<"We are done with the subproblem A["<<start<<"..."<<end<<"]"<<endl;
        int sum1 = sumarr(ans1);
        int sum2 = sumarr(ans2);
        int sum3 = sumarr(ans3);

        vector<int> finalans;
        int maxsum = sum1;
        finalans = ans1;
        if (sum2 > maxsum)
        {
            maxsum = sum2;
            finalans = ans2;
        }
        if (sum3 > maxsum)
        {
            maxsum = sum3;
            finalans = ans3;
        }

        return finalans;
    }
}

int main()
{
    // array is initialized globally at the top 

    cout<<"Array is [-4,5,-2,15,-8,-11,8,-3,4,-7]"<<endl;

    vector<int> final = subarray(0, n - 1);
    cout << "MaxSum = "<<sumarr(final) << endl;
    cout<<"Subarray with maximum sum is : ";

    for (int i = 0; i < final.size(); i++)
    {
        cout << final[i];
        if (i != final.size() - 1)
            cout << ",";
    }
}
