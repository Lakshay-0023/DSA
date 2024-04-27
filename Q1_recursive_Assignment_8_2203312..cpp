/*
    Lakshay Khurana 
    2203312
    MnC 
*/

#include <vector>
#include <iostream>
using namespace std;

// Function to find the index where the new element should be added     `
int binarySearch(vector<int>& arr, vector<int>& mem, int curr, int lo, int hi){
    int ans = -1;
    while(lo <= hi){
        int mid = (lo+hi) / 2;

        if (arr[mem[mid]] <= curr){
            lo = mid + 1;
        }else{
            ans = mid;
            hi = mid - 1;
        }
    }

    return ans;
}

// Recursive function to find LIS
void findLISrecursive(vector<int>& arr, vector<int>& tail, vector<int>& pred, vector<int>& mem, int& len, int i){
    int n = arr.size();
    if (i == 0){  // Base case 
        mem[0] = tail[0] = 0;
        return;
    }

    findLISrecursive(arr, tail, pred, mem, len, i-1);  // Recursive Call

    int index = binarySearch(arr, mem, arr[i],0, len);  // calling the binary search function 
    if (index != -1){
        pred[i] = pred[mem[index]];
        mem[index] = i;
        tail[i] = mem[len]; // ifn element not present then addd it to the last 
    }else{
        len++;
        mem[len] = i;
        tail[i] = mem[len];
        pred[i] = mem[len-1];   // if it is present then update it  
    }
    return;
}

int main() {
    vector<int> arr = {-2,7,4,0,1,5,3,8,6,5,6,4};
    int n = arr.size(),i;
    vector<int> tail(n), pred(n), mem(n);  // declaring the tail pred and mem array 
    int len = 0;

    cout<<"Original List: ";
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;   // printing the original array

    cout<<"Enter i: ";
    cin>>i;
    findLISrecursive(arr, tail, pred, mem, len, i - 1);

    cout << "Length of LIS: " << len + 1 << endl;
    cout << "Longest Increasing Subsequence: ";
    int curr = mem[len];
    vector <int> subseq;
    while (curr != 0) {
        subseq.push_back(arr[curr]);
        curr = pred[curr];
    }
    subseq.push_back(arr[curr]);
    for(int i = subseq.size()-1; i>=0; i--)
    {
        cout<<subseq[i]<<" ";   // printing the final ans 
    }
    cout<<endl;
    return 0;
}