#include <iostream>
using namespace std;

// deklarasi kelas
class Petugas;
class Admin;

class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    void info() const {
        cout << "Judul: " << judul << ", Penulis: " << penulis
             << ", Status: " << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    friend class Petugas;
    friend void lihatStatistik(const Buku& b, const Peminjam& p);
};

class Peminjam {
private:
    string nama;
    int id;
    int totalPinjaman;

public:
    Peminjam(string n, int i) : nama(n), id(i), totalPinjaman(0) {}

    void info() const {
        cout << "Nama: " << nama << ", ID: " << id
             << ", Total Pinjaman: " << totalPinjaman << endl;
    }

    friend class Petugas;
    friend void lihatStatistik(const Buku& b, const Peminjam& p);
};

class Petugas {
private:
    string nama;
    int idPetugas;
    string levelAkses;

public:
    Petugas(string n, int id, string la) : nama(n), idPetugas(id), levelAkses(la) {}

    void prosesPinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            p->totalPinjaman += 1;
            cout << "Petugas " << nama << " memproses peminjaman buku.\n";
        } else {
            cout << "Buku sudah dipinjam.\n";
        }
    }

    void prosesKembali(Buku* b, Peminjam* p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            p->totalPinjaman -= 1;
            cout << "Petugas " << nama << " memproses pengembalian buku.\n";
        } else {
            cout << "Buku tidak sedang dipinjam.\n";
        }
    }
    friend class Admin;
};

class  Admin {
public : 
    void ubahLevelAkses(Petugas* ptg, string aksesBaru) {
        ptg->levelAkses = aksesBaru;
        cout << "Level akses petugas " << ptg->nama << " diubah menjadi " << aksesBaru << endl;
    }

    void tampilkanLevelAkses(const Petugas* ptg) const {
        cout << "Petugas: " << ptg->nama << ", Akses: " << ptg->levelAkses << endl;
    }

};