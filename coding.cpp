#include <iostream>
#include <vector>
#include <string>
#include <conio.h> // Untuk getch(), hanya bekerja di Windows

using namespace std;

// Struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    string NIM;
    string nama;
    string jurusan;
    float ipk;
};

// Fungsi untuk membersihkan layar
void clearScreen() {
    system("cls");
}

// Fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa(vector<Mahasiswa>& dataMahasiswa) {
    Mahasiswa mhs;
    clearScreen(); // Membersihkan layar
    cout << "Masukkan Nama Mahasiswa: ";
    cin >> mhs.nama;
    cin.ignore(); // Membersihkan newline character dari buffer input
    cout << "Masukkan NIM Mahasiswa: ";
    getline(cin, mhs.NIM);
    cout << "Masukkan Jurusan Mahasiswa: ";
    getline(cin, mhs.jurusan);
    cout << "Masukkan IPK Mahasiswa: ";
    cin >> mhs.ipk;

    dataMahasiswa.push_back(mhs);
    cout << "Data mahasiswa berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan semua data mahasiswa
void tampilkanMahasiswa(const vector<Mahasiswa>& dataMahasiswa) {
    clearScreen(); // Membersihkan layar
    if (dataMahasiswa.empty()) {
        cout << "Tidak ada data mahasiswa.\n";
        return;
    }

    for (const auto& mhs : dataMahasiswa) {
        cout << "Nama: " << mhs.nama << "\n";
        cout << "NIM: " << mhs.NIM << "\n";
        cout << "Jurusan: " << mhs.jurusan << "\n";
        cout << "IPK: " << mhs.ipk << "\n";
        cout << "--------------------------\n";
    }
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
void hapusMahasiswa(vector<Mahasiswa>& dataMahasiswa, const string& NIM) {
    clearScreen(); // Membersihkan layar
    auto it = dataMahasiswa.begin();
    while (it != dataMahasiswa.end()) {
        if (it->NIM == NIM) {
            it = dataMahasiswa.erase(it);
            cout << "Data mahasiswa dengan NIM " << NIM << " berhasil dihapus.\n";
            return;
        } else {
            ++it;
        }
    }
    cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
}

// Fungsi untuk memperbarui data mahasiswa berdasarkan NIM
void perbaruiMahasiswa(vector<Mahasiswa>& dataMahasiswa, const string& NIM) {
    clearScreen(); // Membersihkan layar
    for (auto& mhs : dataMahasiswa) {
        if (mhs.NIM == NIM) {
            cout << "Masukkan Nama Baru Mahasiswa: ";
            cin.ignore(); // Membersihkan newline character dari buffer input
            getline(cin, mhs.nama);
            cout << "Masukkan Jurusan Baru Mahasiswa: ";
            getline(cin, mhs.jurusan);
            cout << "Masukkan IPK Baru Mahasiswa: ";
            cin >> mhs.ipk;
            cout << "Data mahasiswa dengan NIM " << NIM << " berhasil diperbarui.\n";
            return;
        }
    }
    cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM atau Nama
void cariMahasiswa(const vector<Mahasiswa>& dataMahasiswa) {
    clearScreen(); // Membersihkan layar
    int pilihan;
    cout << "Cari berdasarkan:\n1. NIM\n2. Nama\nMasukkan pilihan: ";
    pilihan = _getch();
    cout << "\n";

    if (pilihan == '1') {
        string NIM;
        cout << "Masukkan NIM: ";
        cin >> NIM;
        for (const auto& mhs : dataMahasiswa) {
            if (mhs.NIM == NIM) {
                cout << "NIM: " << mhs.NIM << "\n";
                cout << "Nama: " << mhs.nama << "\n";
                cout << "Jurusan: " << mhs.jurusan << "\n";
                cout << "IPK: " << mhs.ipk << "\n";
                return;
            }
        }
    } else if (pilihan == '2') {
        string nama;
        cout << "Masukkan Nama: ";
        cin.ignore(); // Membersihkan newline character dari buffer input
        getline(cin, nama);
        for (const auto& mhs : dataMahasiswa) {
            if (mhs.nama == nama) {
                cout << "NIM: " << mhs.NIM << "\n";
                cout << "Nama: " << mhs.nama << "\n";
                cout << "Jurusan: " << mhs.jurusan << "\n";
                cout << "IPK: " << mhs.ipk << "\n";
                return;
            }
        }
    } else {
        cout << "Pilihan tidak valid.\n";
    }
    cout << "Data mahasiswa tidak ditemukan.\n";
}

int main() {
    vector<Mahasiswa> dataMahasiswa;
    int pilihan;
    do {
        clearScreen(); // Membersihkan layar setiap kali menu ditampilkan
        cout << "Menu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Perbarui Data Mahasiswa\n";
        cout << "4. Tampilkan Semua Data Mahasiswa\n";
        cout << "5. Cari Data Mahasiswa\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        pilihan = _getch();
        cout << "\n";

        switch (pilihan) {
            case '1':
                tambahMahasiswa(dataMahasiswa);
                break;
            case '2': {
                string NIM;
                cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
                cin >> NIM;
                hapusMahasiswa(dataMahasiswa, NIM);
                break;
            }
            case '3': {
                string NIM;
                clearScreen();
                cout << "Masukkan NIM Mahasiswa yang akan diperbarui: ";
                cin >> NIM;
                perbaruiMahasiswa(dataMahasiswa, NIM);
                break;
            }
            case '4':
                tampilkanMahasiswa(dataMahasiswa);
                break;
            case '5':
                cariMahasiswa(dataMahasiswa);
                break;
            case '6':
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

        cout << "Tekan sembarang tombol untuk kembali ke menu...";
        _getch();

    } while (pilihan != '6');

    return 0;
}