#include <iostream>
#include <vector>

using namespace std;

// ========================
// Identitas Mahasiswa
// ========================
/*
    NAMA  : KISAWA WILDAN NUHA
    NIM   : 23533812
    KELAS : TI 4C
*/

// ========================
// Fungsi untuk menggabungkan dua bagian array terurut
// (Greedy: selalu pilih elemen terkecil terlebih dahulu)
// ========================
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Buat array sementara
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge array L dan R kembali ke arr
    int i = 0, j = 0, k = left;

    // Greedy choice: pilih yang lebih kecil tiap langkah
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Salin sisa elemen
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// ========================
// Fungsi Merge Sort (Divide and Conquer)
// ========================
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Divide
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Conquer: Gabungkan bagian terurut
        merge(arr, left, mid, right);
    }
}

// ========================
// Main Program
// ========================
int main() {
    cout << "=== PROGRAM MERGE SORT (Divide and Conquer + Greedy Merge) ===\n";
    cout << "Nama  : KISAWA WILDAN NUHA\n";
    cout << "NIM   : 23533812\n";
    cout << "Kelas : TI 4C\n\n";

    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // Panggil Merge Sort
    mergeSort(arr, 0, n - 1);

    cout << "\nHasil setelah Merge Sort:\n";
    for (int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}
