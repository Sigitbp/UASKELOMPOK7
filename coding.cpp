#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Mahasiswa {
    std::string nama;
    std::string NIM;
    std::string jurusan;
    double nilai;
};

std::vector<Mahasiswa> database;

void tambahMahasiswa() {
    Mahasiswa mhs;
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
}

void hapusMahasiswa() {
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
}

void perbaruiMahasiswa() {
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
            return;
        }
    }
    std::cout << "Data mahasiswa tidak ditemukan.\n";
}

void tampilkanSemuaMahasiswa() {
    if (database.empty()) {
        std::cout << "Tidak ada data mahasiswa.\n";
        return;
    }
    for (const auto &mhs : database) {
        std::cout << "Nama: " << mhs.nama << "\nNIM: " << mhs.NIM << "\nJurusan: " << mhs.jurusan << "\nNilai: " << mhs.nilai << "\n\n";
    }
}

void cariMahasiswa() {
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
                return;
            }
        }
    } else if (pilihan == 2) {
        std::string nama;
        std::cout << "Masukkan nama: ";
        std::cin.ignore();
        std::getline(std::cin, nama);
        for (const auto &mhs : database) {
            if (mhs.nama == nama) {
                std::cout << "Nama: " << mhs.nama << "\nNIM: " << mhs.NIM << "\nJurusan: " << mhs.jurusan << "\nNilai: " << mhs.nilai << "\n";
                return;
            }
        }
    } else {
        std::cout << "Pilihan tidak valid.\n";
        return;
    }
    std::cout << "Data mahasiswa tidak ditemukan.\n";
}

int main() {
    int pilihan;
    while (true) {
        std::cout << "Sistem Manajemen Data Mahasiswa\n";
        std::cout << "1. Tambah Data Mahasiswa\n";
        std::cout << "2. Hapus Data Mahasiswa\n";
        std::cout << "3. Perbarui Data Mahasiswa\n";
        std::cout << "4. Tampilkan Semua Data Mahasiswa\n";
        std::cout << "5. Cari Data Mahasiswa\n";
        std::cout << "6. Keluar\n";
        std::cout << "Masukkan pilihan: ";
        std::cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tambahMahasiswa();
                break;
            case 2:
                hapusMahasiswa();
                break;
            case 3:
                perbaruiMahasiswa();
                break;
            case 4:
                tampilkanSemuaMahasiswa();
                break;
            case 5:
                cariMahasiswa();
                break;
            case 6:
                std::cout << "Terima kasih telah menggunakan aplikasi ini.\n";
                return 0;
            default:
                std::cout << "Pilihan tidak valid.\n";
                break;
        }
    }
}