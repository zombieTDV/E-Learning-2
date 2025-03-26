#include <iostream>

using std::cout;
using std::cin;

int series(int n);

int series(int n){
    if (n == 0) {
        return 0; 
    }
    int current_term = (n - 1) * n;

    return current_term + series(n - 1);
}

int main(){
    int n;
    int S = 0;

    cout << "Nhập một số nguyên dương n: "; cin >> n;
    while (n < 0)
    {
        cout << "Số bạn nhập không phải là một số nguyên dương, vui lòng nhập lại!" << '\n';
        cout << "n: "; cin >> n;
    }

    cout << "Chuỗi (n-1)*n với n = " << n << " Là "<< series(n);
    return 0;
}