#include <iostream>
#include <vector>
using namespace std;

vector<int> LCS(vector<int>& arr1, vector<int>& arr2, int m, int n) {

    // Base Case : if any of the array is empty , then the common subsequence is also empty so return the empty vector
    if (m == 0 || n == 0) {
        vector<int> a;
        return a;   
    }
    
    // if the last element is same then it will be included in the ans so add it to the smaller ans 
    if (arr1[m - 1] == arr2[n - 1]) {
        vector<int> smallans = LCS(arr1, arr2, m - 1, n - 1);
        smallans.push_back(arr1[m - 1]);
        return smallans;
    } 
    
    // otherwise last element will not be included so take the max of the ans od the two subarrays 
    vector<int> smallans1 = LCS(arr1, arr2, m - 1, n);
    vector<int> smallans2 = LCS(arr1, arr2, m, n - 1);
    if(smallans1.size() > smallans2.size()){
        return smallans1;
    }
    else{
        return smallans2;
    }
    
    
}

int main() {
    vector<int> arr1 = {2, 5, 3, 8, 7};
    vector<int> arr2 = {3, 5, 8, 6, 9};
    
    vector<int> ans = LCS(arr1, arr2, arr1.size(), arr2.size());
    
    cout << "First Array:"<<endl;    //Printing the first array 
    for (int i =0; i <arr1.size(); i++) {
        cout << arr1[i]<<" ";
    }
    cout << endl;
    cout << "Second Array:"<<endl;    //Printing the second array
    for (int i =0; i <arr2.size(); i++) {
        cout << arr2[i]<<" ";
    }
    cout << endl;

    cout << "Longest Common Subsequence of these 2 arrays is :";   //Printing the final ans 
    for (int i =0; i <ans.size(); i++) {
        cout << " " << ans[i];
    }
    

}