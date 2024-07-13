#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <conio.h> // Include library for _getch()

#ifdef _WIN32
    #include <windows.h>
    void clearScreen() {
        system("cls");
    }
#else
    #include <unistd.h>
    void clearScreen() {
        system("clear");
    }
#endif

struct Mahasiswa {
    std::string nama;
    std::string NIM;
    std::string jurusan;
    double nilai;
};

std::vector<Mahasiswa> database;

void tambahMahasiswa() {
    Mahasiswa mhs;
    clearScreen(); // Clear the screen
    std::cout << "Masukkan nama mahasiswa: ";
    std::cin.ignore();
    std::getline(std::cin, mhs.nama);
    std::cout << "Masukkan NIM: ";
    std::cin >> mhs.NIM;
    std::cout << "Masukkan jurusan: ";
    std::cin.ignore();
    std::getline(std::cin, mhs.jurusan);
    std::cout << "Masukkan nilai: ";
    std::cin >> mhs.nilai;
    database.push_back(mhs);
    std::cout << "Data mahasiswa telah ditambahkan.\n";
    std::cout << "Tekan sembarang tombol untuk kembali ke menu...";
    _getch();
}

void hapusMahasiswa() {
    clearScreen(); // Clear the screen
    std::string NIM;
    std::cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
    std::cin >> NIM;
    auto it = std::remove_if(database.begin(), database.end(), [&](const Mahasiswa& m) { return m.NIM == NIM; });
    if (it != database.end()) {
        database.erase(it, database.end());
        std::cout << "Data mahasiswa dengan NIM " << NIM << " telah dihapus.\n";
    } else {
        std::cout << "Data mahasiswa tidak ditemukan.\n";
    }
    std::cout << "Tekan sembarang tombol untuk kembali ke menu...";
    _getch();
}

void perbaruiMahasiswa() {
    clearScreen(); // Clear the screen
    std::string NIM;
    std::cout << "Masukkan NIM mahasiswa yang akan diperbarui: ";
    std::cin >> NIM;
    for (auto &mhs : database) {
        if (mhs.NIM == NIM) {
            std::cout << "Masukkan nama baru: ";
            std::cin.ignore();
            std::getline(std::cin, mhs.nama);
            std::cout << "Masukkan jurusan baru: ";
            std::getline(std::cin, mhs.jurusan);
            std::cout << "Masukkan nilai baru: ";
            std::cin >> mhs.nilai;
            std::cout << "Data mahasiswa dengan NIM " << NIM << " telah diperbarui.\n";
            std::cout << "Tekan sembarang tombol untuk kembali ke menu...";
            _getch();
            return;
        }
    }
    std::cout << "Data mahasiswa tidak ditemukan.\n";
    std::cout << "Tekan sembarang tombol untuk kembali ke menu...";
    _getch();
}

void tampilkanSemuaMahasiswa() {
    clearScreen(); // Clear the screen
    if (database.empty()) {
        std::cout << "Tidak ada data mahasiswa.\n";
    } else {
        for (const auto &mhs : database) {
            std::cout << "Nama: " << mhs.nama << "\nNIM: " << mhs.NIM << "\nJurusan: " << mhs.jurusan << "\nNilai: " << mhs.nilai << "\n\n";
        }
    }
    std::cout << "Tekan sembarang tombol untuk kembali ke menu...";
    _getch();
}

void cariMahasiswa() {
    clearScreen(); // Clear the screen
    int pilihan;
    std::cout << "Cari berdasarkan:\n1. NIM\n2. Nama\nMasukkan pilihan: ";
    std::cin >> pilihan;
    std::cin.ignore();
    if (pilihan == 1) {
        std::string NIM;
        std::cout << "Masukkan NIM: ";
        std::cin >> NIM;
        for (const auto &mhs : database) {
            if (mhs.NIM == NIM) {
                std::cout << "Nama: " << mhs.nama << "\nNIM: " << mhs.NIM << "\nJurusan: " << mhs.jurusan << "\nNilai: " << mhs.nilai << "\n";
                std::cout << "Tekan sembarang tombol untuk kembali ke menu...";
                _getch();
                return;
            }
        }
    } else if (pilihan == 2) {
        std::string nama;
        std::cout << "Masukkan nama: ";
        std::getline(std::cin, nama);
        for (const auto &mhs : database) {
            if (mhs.nama == nama) {
                std::cout << "Nama: " << mhs.nama << "\nNIM: " << mhs.NIM << "\nJurusan: " << mhs.jurusan << "\nNilai: " << mhs.nilai << "\n";
                std::cout << "Tekan sembarang tombol untuk kembali ke menu...";
                _getch();
                return;
            }
        }
    } else {
        std::cout << "Pilihan tidak valid.\n";
    }
    std::cout << "Data mahasiswa tidak ditemukan.\n";
    std::cout << "Tekan sembarang tombol untuk kembali ke menu...";
    _getch();
}

int main() {
    char pilihan;
    while (true) {
        clearScreen();
        std::cout << "Sistem Manajemen Data Mahasiswa\n";
        std::cout << "1. Tambah Data Mahasiswa\n";
        std::cout << "2. Hapus Data Mahasiswa\n";
        std::cout << "3. Perbarui Data Mahasiswa\n";
        std::cout << "4. Tampilkan Semua Data Mahasiswa\n";
        std::cout << "5. Cari Data Mahasiswa\n";
        std::cout << "6. Keluar\n";
        std::cout << "Masukkan pilihan: ";
        pilihan = _getch(); // Menangkap input karakter tanpa harus menekan enter
        std::cout << pilihan << "\n"; // Tampilkan pilihan untuk kenyamanan pengguna
        
        switch (pilihan) {
            case '1':
                tambahMahasiswa();
                break;
            case '2':
                hapusMahasiswa();
                break;
            case '3':
                perbaruiMahasiswa();
                break;
            case '4':
                tampilkanSemuaMahasiswa();
                break;
            case '5':
                cariMahasiswa();
                break;
            case '6':
                std::cout << "Terima kasih telah menggunakan aplikasi ini.\n";
                return 0;
            default:
                std::cout << "Pilihan tidak valid.\n";
                std::cout << "Tekan sembarang tombol untuk kembali ke menu...";
                _getch();
                break;
        }
    }
}