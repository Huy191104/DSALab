#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// ===================== TIEN ICH =====================
void HoanVi(int& a, int& b) {
    int t = a; a = b; b = t;
}

void XuatMang(int a[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << " ]\n";
}

// ===================== SELECTION SORT =====================
void SelectionSort(int a[], int n) {
    cout << "\n=== Selection Sort ===\n";
    XuatMang(a, n);

    for (int i = 0; i < n - 1; i++) {
        int vt = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[vt]) vt = j;

        HoanVi(a[i], a[vt]);

        cout << "Buoc " << i + 1 << ": ";
        XuatMang(a, n);
    }
}

// ===================== INSERTION SORT =====================
void InsertionSort(int a[], int n) {
    cout << "\n=== Insertion Sort ===\n";
    XuatMang(a, n);

    for (int i = 1; i < n; i++) {
        int x = a[i];
        int pos = i;

        while (pos > 0 && a[pos - 1] > x) {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = x;

        cout << "Buoc " << i << ": ";
        XuatMang(a, n);
    }
}

// ===================== BUBBLE SORT =====================
void BubbleSort(int a[], int n) {
    cout << "\n=== Bubble Sort ===\n";
    XuatMang(a, n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1])
                HoanVi(a[j], a[j - 1]);
        }

        cout << "Lan " << i + 1 << ": ";
        XuatMang(a, n);
    }
}

// ===================== QUICK SORT =====================
void QuickSort(int a[], int l, int r) {
    int i = l, j = r;
    int pivot = a[(l + r) / 2];

    do {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            HoanVi(a[i], a[j]);
            i++; j--;
        }
    } while (i <= j);

    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}

// ===================== HEAP SORT =====================
void Shift(int a[], int l, int r) {
    int i = l;
    int j = 2 * i + 1;
    int x = a[i];

    while (j <= r) {
        if (j < r && a[j] < a[j + 1]) j++;
        if (x >= a[j]) break;

        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = x;
}

void HeapSort(int a[], int n) {
    cout << "\n=== Heap Sort ===\n";
    XuatMang(a, n);

    for (int i = n / 2 - 1; i >= 0; i--)
        Shift(a, i, n - 1);

    cout << "Sau khi tao heap: ";
    XuatMang(a, n);

    for (int i = n - 1; i > 0; i--) {
        HoanVi(a[0], a[i]);
        Shift(a, 0, i - 1);

        cout << "Buoc " << n - i << ": ";
        XuatMang(a, n);
    }
}

// ===================== PHAN TICH DO PHUC TAP =====================
void PhanTichDoPhucTap() {
    cout << "\n================ PHAN TICH DO PHUC TAP ================\n";

    cout << "\n1. Selection Sort:\n";
    cout << "  - Tot nhat  : O(n^2)\n";
    cout << "  - Xau nhat  : O(n^2)\n";
    cout << "  - Giai thich: Luon phai duyet toan bo mang de tim min, "
        "khong phu thuoc du lieu ban dau.\n";

    cout << "\n2. Insertion Sort:\n";
    cout << "  - Tot nhat  : O(n)\n";
    cout << "  - Xau nhat  : O(n^2)\n";
    cout << "  - Giai thich: Neu mang da gan sap xep thi chi can so sanh, "
        "nguoc lai phai dich chuyen nhieu.\n";

    cout << "\n3. Bubble Sort:\n";
    cout << "  - Tot nhat  : O(n)\n";
    cout << "  - Xau nhat  : O(n^2)\n";
    cout << "  - Giai thich: Neu co kiem tra dung som thi nhanh, "
        "neu mang dao nguoc thi doi cho rat nhieu.\n";

    cout << "\n4. Quick Sort:\n";
    cout << "  - Tot nhat  : O(n log n)\n";
    cout << "  - Xau nhat  : O(n^2)\n";
    cout << "  - Giai thich: Phu thuoc vao pivot. Neu chia deu thi nhanh, "
        "neu lech thi giong Selection Sort.\n";

    cout << "\n5. Heap Sort:\n";
    cout << "  - Tot nhat  : O(n log n)\n";
    cout << "  - Xau nhat  : O(n log n)\n";
    cout << "  - Giai thich: Cau truc heap luon can bang nen do phuc tap on dinh.\n";
}

// ===================== MAIN =====================
int main() {
    int a[] = { 3, -12, 14, 9, 11, -50, -100 };
    int n = 7;
    int b[7];

    copy(a, a + n, b);
    SelectionSort(b, n);

    copy(a, a + n, b);
    InsertionSort(b, n);

    copy(a, a + n, b);
    BubbleSort(b, n);

    copy(a, a + n, b);
    cout << "\n=== Quick Sort ===\n";
    XuatMang(b, n);
    QuickSort(b, 0, n - 1);
    cout << "Ket qua: ";
    XuatMang(b, n);

    copy(a, a + n, b);
    HeapSort(b, n);

    // Phan tich
    PhanTichDoPhucTap();

    return 0;
}