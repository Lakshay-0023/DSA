#include<iostream>
#include<vector>
using namespace std;

// Function to find the maximum sum subarray ending at index i
int findMaxSubarrayEndingHere(vector<int> arr, int i, int& startIdx) {
    if (i == 0) {
        startIdx = 0;
        return arr[0];
    }
    if (arr[i] > findMaxSubarrayEndingHere(arr, i - 1, startIdx) + arr[i]) {
        startIdx = i;
        return arr[i];
    } else
        return findMaxSubarrayEndingHere(arr, i - 1, startIdx) + arr[i];
}

// Function to find the maximum sum subarray of an array
pair<int, pair<int, int>> findMaxSubarray(vector<int> arr, int n) {
    pair<int, pair<int, int>> sumArray[n];
    for (int i = 0; i < n; i++) {
        int startIdx = -1;
        int sum = findMaxSubarrayEndingHere(arr, i, startIdx);
        pair<int, pair<int, int>> ans;
        ans.first = sum;
        ans.second.first = startIdx;
        ans.second.second = i;
        
        sumArray[i] = ans;
    }
    int maxSum = 0;
    pair<int, pair<int, int>> maxSubarray;
    for (int i = 0; i < n; i++) {
        if (sumArray[i].first > maxSum) {
            maxSum = sumArray[i].first;
            maxSubarray = sumArray[i];
        }
    }
    return maxSubarray;
}

// Function to find the maximum sum submatrix of a matrix
int findMaxSubMatrix(vector<vector<int>> matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxSum = 0;
    int startRow = 0;
    int endRow = 0;
    int endCol = 0;

    for(int i = 0; i < rows; i++){
        vector<int> colSum(cols, 0);
        for(int j = i; j < rows; j++){
            for(int k = 0; k < cols; k++){
                colSum[k] += matrix[j][k];
            }
            pair<int, pair<int, int>> temp = findMaxSubarray(colSum, cols);
            if(temp.first > maxSum){
                maxSum = temp.first;
                startRow = temp.second.first;
                endRow = temp.second.second;
                endCol = j;
            }
        }
    }

    cout<<"Maximum Sum Submatrix: "<<endl;
    for(int i = startRow; i <= endCol; i++){
        for(int j = startRow; j <= endRow; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return maxSum;
}

int main(){
    vector<vector<int> > matrix = {{1, 6, -8, -4, -15},
                                    {-5, -3, 7, 2, 1},
                                    {3, 8, 2, 7, 31},
                                    {-4, -12, 1, -6, -6}}; 

    int result = findMaxSubMatrix(matrix);
    cout<<"Maximum sum: "<<result;
}
