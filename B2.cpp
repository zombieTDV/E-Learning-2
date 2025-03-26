#include <iostream>

using std::cout;
using std::cin;

const int PRICE_PER_HOURS = 80;
const int PRICE_PER_MINUTES = 2;\

void input_terminal(int& start_hours, int& start_minutes, int& end_hours, int& end_minutes);
int Invoice(int start_hours, int start_minutes, int end_hours, int end_minutes);


void input_terminal(int& start_hours, int& start_minutes, int& end_hours, int& end_minutes){
    cout << "Dịch vụ thuê phòng karaoke. Chúng tôi hoạt động từ: 8h -> 23h" << '\n';
    cout << "Giá cả theo giờ và phút: " << '\n';
    cout << '\t' << PRICE_PER_HOURS << "k - 1 giờ" << '\n';
    cout << '\t' << PRICE_PER_MINUTES << "k - 1 phút" << '\n'; 
    cout <<  "------[Ưu tiên giá cả khi thuê theo giờ.]------" << '\n';

    cout << "Nhập thời gian NHẬN phòng: " << '\n';
    cout << '\t' << "Giờ : "; cin >> start_hours;
    while (start_hours < 8 || start_hours > 23){
        cout << "Giờ NHẬN PHÒNG không hợp lệ, vui lòng kiểm tra và nhập lại!" << '\n';
        cout << '\t' << "Giờ : "; cin >> start_hours;
    };
    
    cout << '\t' << "Phút: "; cin >> start_minutes;
    while (start_minutes < 0 || start_minutes > 60)
    {
        cout << "Phút NHẬN PHÒNG không hợp lệ, vui lòng kiểm tra và nhập lại!" << '\n';
        cout << '\t' << "Phút: "; cin >> start_minutes;
    }
    
    cout << "Nhập thời gian TRẢ phòng: " << '\n';
    cout << '\t' << "Giờ: "; cin >> end_hours;
    while (end_hours < 8 || end_hours > 23 || end_hours < start_hours){
        cout << "Giờ TRẢ PHÒNG không hợp lệ, vui lòng kiểm tra và nhập lại!" << '\n';
        cout << '\t' << "Giờ: "; cin >> end_hours;
    };
    
    cout << '\t' << "Phút: "; cin >> end_minutes;
    while (end_minutes < 0 || end_minutes > 60)
    {
        cout << "Phút TRẢ PHÒNG không hợp lệ, vui lòng kiểm tra và nhập lại!" << '\n';
        cout << '\t' << "Phút: "; cin >> end_minutes;
    }
}

int Invoice(int start_hours, int start_minutes, int end_hours, int end_minutes){
    int service_hours = end_hours - start_hours;
    int servce_minutes = start_minutes - end_minutes;

    if (end_minutes > start_minutes){
        return (((service_hours - 1) * PRICE_PER_HOURS) + ((60 - servce_minutes) * PRICE_PER_MINUTES));
    }
    else{
        return ((service_hours * PRICE_PER_HOURS) + (servce_minutes * PRICE_PER_MINUTES));}
}

int main(){
    int start_hours, start_minutes;
    int end_hours, end_minutes;

    input_terminal(start_hours, start_minutes, end_hours, end_minutes);
    
    cout << "Thành tiền cho " << start_hours << "h_" << start_minutes << "p ->" << end_hours << "h_" << end_minutes << "p " << Invoice(start_hours, start_minutes, end_hours, end_minutes) << "k\n";

    return 0;
}