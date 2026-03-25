#include <iostream>
using namespace std;

/*
    CON TRO TRONG C++
    - Lưu địa chỉ của biến
    - Thay đổi dữ liệu trực tiếp thông qua địa chỉ
    - Quản lý bộ nhớ động
    - Là nền tảng của DSLK (Linked List, Tree...)
*/

// 1. Hiển thị địa chỉ và giá trị
void hienThiConTro() {
    int x = 10;
    int* p = &x; // con trỏ trỏ tới x

    cout << "Gia tri x: " << x << endl;
    cout << "Dia chi cua x: " << &x << endl;
    cout << "Con tro p tro toi: " << p << endl;
    cout << "Gia tri ma p tro toi: " << *p << endl;
}

// 2. Thay đổi giá trị thông qua con trỏ
void thayDoiGiaTri() {
    int x = 5;
    int* p = &x;

    cout << "Truoc khi thay doi: x = " << x << endl;
    *p = 20; // thay đổi giá trị x thông qua con trỏ
    cout << "Sau khi thay doi qua con tro: x = " << x << endl;
}

// 3. Swap hai số bằng con trỏ
void swapPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void chucNangSwap() {
    int a = 3, b = 7;
    cout << "Truoc swap: a = " << a << ", b = " << b << endl;

    swapPointer(&a, &b);

    cout << "Sau swap: a = " << a << ", b = " << b << endl;
}

// 4. Duyệt mảng bằng con trỏ
void duyetMang() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int* p = arr; // con trỏ trỏ tới đầu mảng

    cout << "Duyet mang bang con tro: ";
    for (int i = 0; i < 5; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;
}

// 5. Cấp phát bộ nhớ động
void capPhatDong() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    if (n <= 0) {
        cout << "So phan tu phai lon hon 0!\n";
        return;
    }

    int* arr = new int[n]; // cấp phát động

    for (int i = 0; i < n; i++) {
        cout << "Nhap arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << "Mang vua nhap: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete[] arr; // giải phóng bộ nhớ
}

// ===== MENU CHUC NANG CON TRO =====
int main() {
    int choice;

    do {
        cout << "\n===== MENU CON TRO =====\n";
        cout << "1. Hien thi con tro\n";
        cout << "2. Thay doi gia tri qua con tro\n";
        cout << "3. Swap 2 so bang con tro\n";
        cout << "4. Duyet mang bang con tro\n";
        cout << "5. Cap phat mang dong\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1: hienThiConTro(); break;
        case 2: thayDoiGiaTri(); break;
        case 3: chucNangSwap(); break;
        case 4: duyetMang(); break;
        case 5: capPhatDong(); break;
        case 0: cout << "Thoat chuong trinh!\n"; break;
        default: cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }

    } while (choice != 0);

    return 0;
}