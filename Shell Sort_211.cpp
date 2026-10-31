#include <iostream>
using namespace std;
 
const int MAKS = 100;   // batas jumlah elemen
 
// Menampilkan isi array dalam format [a, b, c, ...]
void cetakArray(int data[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << data[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}
 
// Menampilkan kondisi array saat temp sedang dipegang:
// posisi 'indeks' dianggap sudah berisi nilai temp
void cetakArrayDenganTemp(int data[], int n, int indeks, int temp) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << (i == indeks ? temp : data[i]);
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}
 
// Meminta pengguna mengisi jumlah dan nilai elemen array
int inputData(int data[]) {
    int n;
 
    do {
        cout << "Masukkan jumlah elemen (1-" << MAKS << ") : ";
        cin >> n;
        if (n < 1 || n > MAKS) {
            cout << "Jumlah tidak valid, coba lagi.\n";
        }
    } while (n < 1 || n > MAKS);
 
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen ke-" << i + 1 << " : ";
        cin >> data[i];
    }
    return n;
}
 
// Shell Sort (versi temp + geser ke kanan) dengan menampilkan langkahnya
void shellSort(int data[], int n) {
    int nomorTahap = 1;
 
    // Gap awal = n/2, lalu dibagi 2 setiap iterasi sampai gap = 1
    for (int gap = n / 2; gap > 0; gap /= 2) {
        cout << "\n=== TAHAP " << nomorTahap++ << " | Gap = " << gap << " ===\n";
 
        for (int i = gap; i < n; i++) {
            int temp = data[i];   // simpan elemen yang sedang diproses
            int j = i;
 
            // Geser elemen yang lebih besar dari temp ke kanan
            while (j >= gap) {
                cout << "Pasangan (" << j - gap << ", " << j << ") : ("
                     << data[j - gap] << ", " << temp << ") -> ";
 
                if (data[j - gap] > temp) {
                    cout << data[j - gap] << " > " << temp << " | Tukar posisi | ";
                    data[j] = data[j - gap];
                    j -= gap;
                    cetakArrayDenganTemp(data, n, j, temp);
                    cout << endl;
                } else {
                    cout << data[j - gap] << " <= " << temp << " | Tidak ditukar | ";
                    cetakArrayDenganTemp(data, n, j, temp);
                    cout << endl;
                    break;
                }
            }
            data[j] = temp;       // letakkan temp di posisi yang tepat
        }
    }
}
 
int main() {
    int data[MAKS];
 
    cout << "=====================================\n";
    cout << "             SHELL SORT      \n";
    cout << "=====================================\n\n";
 
    // 1. Tahap pengisian data
    int n = inputData(data);
 
    // 2. Tampilkan data awal
    cout << "\n-------------------------------------\n";
    cout << "Data awal  : ";
    cetakArray(data, n);
    cout << "\n-------------------------------------\n";
 
    // 3. Proses pengurutan beserta langkah-langkahnya
    shellSort(data, n);
 
    // 4. Tampilkan hasil akhir
    cout << "\n=====================================\n";
    cout << "Data akhir : ";
    cetakArray(data, n);
    cout << "\n=====================================\n";
 
    return 0;
}
 