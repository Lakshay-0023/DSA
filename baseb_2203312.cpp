// Lakshay Khurana
// 2203312
// Mnc
// Assignment 5

#include <iostream>
#include <vector>
using namespace std;

vector<int> ConvertToOtherBase(int base, int number) {
    vector<int> BaseForm;
    if (number == 0) {
        // BaseForm.push_back(0);
        return BaseForm;
    }
    while (number > 0) {
        BaseForm.insert(BaseForm.begin(), number % base);
        number = number / base;
    }
    return BaseForm;
}

vector<int> SumInOtherBase(int base, vector<int>& num1, vector<int>& num2) {
    vector<int> Sum;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int currentSum = carry;
        if (i >= 0) {
            currentSum += num1[i];
            i--;
        }
        if (j >= 0) {
            currentSum += num2[j];
            j--;
        }
        carry = currentSum / base;
        currentSum %= base;
        Sum.insert(Sum.begin(), currentSum);
    }
    return Sum;
}

void PrintNumber(vector<int>& res) {
    for (int k = 0; k < res.size(); k++) {
        cout << res[k];
    }
    cout << endl;
}

int main() {

    int n1, n2, base;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter first Number: ";
    cin >> n1;
    cout << "Enter second Number: ";
    cin >> n2;

    vector<int> n1_in_baseb = ConvertToOtherBase(base,n1);
    vector<int> n2_in_baseb = ConvertToOtherBase(base,n2);

    vector<int> Sum = SumInOtherBase(base, n1_in_baseb, n2_in_baseb);

    cout << n1 << " written in base " << base << " is : ";
    PrintNumber(n1_in_baseb);
    cout << n2 << " written in base " << base << " is : ";
    PrintNumber(n2_in_baseb);

    cout << "Sum of these numbers in base " << base << " is : ";
    PrintNumber(Sum);
}
