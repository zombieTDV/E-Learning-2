#include <iostream>

using std::cout;
using std::cin;

bool is_prime(int n);
int upper_bound_prime(int n);


bool is_prime(int n){
    if (n < 2){
        return false;
    }

    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int upper_bound_prime(int n){
    while (is_prime(n) != true)
    {
        n += 1;
    }
    
    return n;
}

int main(){
    int n;

    do
    {
        cout << "Nhập một số nguyên dương n: "; cin >> n;
    } while (n <= 0);
    
    

    cout << "Số nguyên tố cận trên gần nhất với số nguyên dương " << n << " là số: " << upper_bound_prime(n) << '\n';

    return 0;
}