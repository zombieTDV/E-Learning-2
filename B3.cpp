#include <iostream>

using std::cout;
using std::cin;

void cross_shape(int n);


void cross_shape(int n){
    const int size = 2 * n + 1;

    for (int i = 1; i <= size; i++){
        for (int j = 1; j <= size; j++){
            if ((i == (size / 2 + 1)) || (j == (size / 2 + 1))){
                cout << " * ";
            }
            else{
                cout << "   ";
            }
    }
        cout << '\n';
    }
}

int main(){
    int n;

    cout << "Nhập một số nguyên dương n: "; cin >> n;
    while (n < 0)
    {
        cout << "Số bạn nhập không phải là một số nguyên dương, vui lòng nhập lại!" << '\n';
        cout << "n: "; cin >> n;
    }
    
    cross_shape(n);

    return 0;
}