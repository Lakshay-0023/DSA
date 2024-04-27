// Online C++ compiler to run C++ program online
#include<iostream>
#include<fstream>
#include <vector>
using namespace std;
int counter;

vector<vector<int>> matrix_multiplication(vector<vector<int>>& a, vector<vector<int>>& b){
    vector<vector<int>> result(a.size(),vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            for (int k = 0; k < a[0].size(); ++k) {
                result[i][j] += a[i][k] * b[k][j];
                counter++;
            }
        }
    }

    return result;
}

vector<vector<int>> matrix_power(vector<vector<int>> matrix , int n){
    counter = 0;
    vector<vector<int>> result(matrix.size(),vector<int>(matrix.size(),0));
    for(int i=0;i<matrix.size();i++){
        result[i][i]=1;
    }
    
    vector<vector<int>> base = matrix;
    while (n > 0) {
        if (n % 2 == 1) {
            result = matrix_multiplication(result, base);
        }
        base = matrix_multiplication(base, base);
        n /= 2;
    }

    return result;
}

int fibonacci_value(vector<vector<int>> matrix ,int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    vector<vector<int>> ans = matrix_power(matrix,n - 1);
    return ans[0][0];
}

void fibonacci(int n){
    ofstream ansfile;
    ansfile.open("fibonacci_by+repeated_squaring.csv");
    ansfile << "n,Fibonacci,F(n) \n"; 
    int val;
    vector<vector<int>> matrix = {{1,1},{1,0}};
    for(int i=0; i<n; i++)
    {
        val = fibonacci_value(matrix,i);
        cout<< "("<<i<<","<<val<<","<<counter<<")"<<endl;
        ansfile<<i<<","<<val<<","<<counter<<endl;
    }
    ansfile.close();
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    fibonacci(n);
    return 0;
}