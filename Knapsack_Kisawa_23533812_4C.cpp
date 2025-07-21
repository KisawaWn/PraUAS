#include <iostream>
#include <vector>
#include <algorithm>

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
// Struktur Data Barang
// ========================
struct Item {
    int weight, value;
};

// ========================
// GREEDY: Fractional Knapsack
// ========================
bool cmpFractional(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> items) {
    sort(items.begin(), items.end(), cmpFractional);

    double totalValue = 0.0;
    for (auto &item : items) {
        if (W == 0) break;

        if (item.weight <= W) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            W = 0;
        }
    }
    return totalValue;
}

// ========================
// DIVIDE & CONQUER: 0/1 Knapsack
// ========================
int knapsackDC(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) return 0;

    if (wt[n-1] > W)
        return knapsackDC(W, wt, val, n-1);
    else
        return max(
            val[n-1] + knapsackDC(W - wt[n-1], wt, val, n-1),
            knapsackDC(W, wt, val, n-1)
        );
}

// ========================
// MAIN FUNCTION
// ========================
int main() {
    cout << "=== PROGRAM KNAPSACK (Greedy dan Divide and Conquer) ===\n";
    cout << "Nama  : KISAWA WILDAN NUHA\n";
    cout << "NIM   : 23533812\n";
    cout << "Kelas : TI 4C\n\n";

    // Data tetap dari soal
    const int n = 8;
    int val[n] = {21, 35, 70, 42, 80, 20, 10, 5};
    int wt[n]  = {2,  3,  5,  3,  3,  8,  1, 2};

    vector<Item> items;
    for (int i = 0; i < n; ++i) {
        items.push_back({wt[i], val[i]});
    }

    int W;
    cout << "Masukkan kapasitas maksimum Knapsack: ";
    cin >> W;

    // Divide and Conquer Result (0/1 Knapsack)
    int maxValDC = knapsackDC(W, wt, val, n);
    cout << "\n[Divide and Conquer - 0/1 Knapsack]\n";
    cout << "Nilai maksimum (tanpa pecahan): " << maxValDC << endl;

    // Greedy Result (Fractional Knapsack)
    double maxValGreedy = fractionalKnapsack(W, items);
    cout << "\n[Greedy - Fractional Knapsack]\n";
    cout << "Perkiraan nilai maksimum (boleh pecah): " << maxValGreedy << endl;

    return 0;
}
