#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Identitas Mahasiswa
/*
    NAMA  : KISAWA WILDAN NUHA
    NIM   : 23533812
    KELAS : TI 4C
*/

struct Process {
    int id;
    int burstTime;
};

// Comparator untuk sorting berdasarkan burst time (Greedy)
bool compareByBurstTime(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

int main() {
    cout << "=== PROGRAM MINIMASI WAKTU EKSEKUSI (SJF Scheduling) ===\n";
    cout << "Nama  : KISAWA WILDAN NUHA\n";
    cout << "NIM   : 23533812\n";
    cout << "Kelas : TI 4C\n\n";

    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> processes(n);

    // Input burst time dari user
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "Masukkan waktu eksekusi (burst time) untuk proses " << processes[i].id << ": ";
        cin >> processes[i].burstTime;
    }

    // Sorting berdasarkan waktu eksekusi (SJF)
    sort(processes.begin(), processes.end(), compareByBurstTime);

    int totalWaitingTime = 0;
    int currentTime = 0;

    cout << "\nUrutan eksekusi proses (Greedy - SJF):\n";
    cout << "Proses\tBurst Time\tWaktu Tunggu\n";

    for (auto p : processes) {
        cout << "P" << p.id << "\t   " << p.burstTime << "\t\t    " << currentTime << endl;
        totalWaitingTime += currentTime;
        currentTime += p.burstTime;
    }

    float avgWaitingTime = (float)totalWaitingTime / n;
    cout << "\nTotal Waktu Tunggu: " << totalWaitingTime << endl;
    cout << "Rata-rata Waktu Tunggu: " << avgWaitingTime << endl;

    return 0;
}
