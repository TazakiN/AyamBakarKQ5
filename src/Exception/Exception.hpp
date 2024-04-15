#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
using namespace std;

class Exception {
    public:
        virtual string what() = 0;
};

/* File Exception */
// File tidak dapat dibuka
class TidakDapatBukaFile : public Exception {
    public:
        string what() {
            return "Tidak dapat membuka file!";
        }
};

// Lokasi invalid (folder belum ada)
class LokasiInvalid : public Exception {
    public:
        string what() {
            return "Lokasi berkas tidak valid!";
        }
};

/* General Exception */
// Inventory
class InventoryPenuh : public Exception {
    public:
        string what() {
            return "Inventory sudah penuh!";
        }
};

// Uang tidak cukup
class UangTidakCukup : public Exception {
    public:
        string what() {
            return "Uang tidak cukup!";
        }
};

// Penyimpanan tidak cukup
class PenyimpananTidakCukup : public Exception {
    public:
        string what() {
            return "Jumlah penyimpanan tidak cukup!";
        }
};

// Penyimpanan kosong
class InventoryKosong : public Exception {
    public:
        string what() {
            return "Penyimpanan kosong!";
        }
};

// Petak kosong
class PetakKosong : public Exception {
    public:
        string what() {
            return "Kamu memilih angin.. Petak ini kosong..";
        }
};

/* Petani Exception */
// Tanam
class BukanTanaman : public Exception {
    public:
        string what() {
            return "Item yang dipilih bukanlah tanaman.";
        }
};

class PilihanTanamanInvalid : public Exception {
    public:
        string what() {
            return "Pilihan tanaman tidak valid.";
        }
};

class PetakTidakValid : public Exception {
    public:
        string what() {
            return "Petak yang dipilih tidak valid.";
        }
};

class PetakSudahTerisi : public Exception {
    public:
        string what() {
            return "Petak ladang sudah terisi.";
        }
};

// Ladang penuh
class LadangPenuh : public Exception {
    public:
        string what() {
            return "Perintah gagal dilakukan, ladang sudah penuh!";
        }
};

// Panen (Petani-Peternak)
class BelumSiapPanen : public Exception {
    public:
        string what() {
            return "Jenis ini belum siap untuk dipanen!";
        }
};

class PetakPanenInvalid : public Exception {
    public:
        string what() {
            return "Jumlah petak panen tidak valid!";
        }
};


/* Peternak Exception */

class BukanMakanan : public Exception {
    public:
        string what() {
            return "Item yang dipilih bukanlah makanan.";
        }
};

// kasih makan, tapi isi row col nya bukan hewan
class BukanHewan : public Exception {
    public:
        string what() {
            return "Tidak ada hewan di petak yang diberikan.";
        }
};

// Ternak
class TidakAdaHewan : public Exception {
    public:
        string what() {
            return "Perintah gagal dilakukan, tidak ada hewan di penyimpanan!";
        }
};

// Kandang penuh
class KandangPenuh : public Exception {
    public:
        string what() {
            return "Perintah gagal dilakukan, kandang sudah penuh!";
        }
};

// Kasih_makan
class KandangKosong : public Exception {
    public:
        string what() {
            return "Mau kasih makan apa??!!, kandangmu kosong!";
        }
};

class TidakAdaPakan : public Exception {
    public:
        string what() {
            return "Yah, kamu tidak punya makanan untuk hewan tersebut!";
        }
};

class SlotKosong : public Exception {
    public:
        string what() {
            return "Kamu mengambil harapan kosong dari penyimpanan.\n Silahkan masukan slot yang berisi makanan."; 
        }
};

// class ContainsOtherThanFood : public Exception {
//     public:
//         string what() {
//             return "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!\n Silahkan masukan slot yang berisi makanan.";
//         }
// };

class WrongFood : public Exception {
    public:
        string what() {
            return "Makanan yang dipilih tidak sesuai untuk jenis hewan yang dipilih."; 
        }
};

/* Walikota Exception */
// Bangun
class MaterialTidakCukup : public Exception {
    public:
        string what() {
            return "Kamu tidak punya sumber daya yang cukup!"; // Nanti tambah message kurangnya apa
        }
};

class ResepBangunanInvalid : public Exception {
    public:
        string what() {
            return "Kamu tidak punya resep bangunan tersebut!";
        }
};

// Tambah_pemain
class NamaPlayerTerpakai : public Exception {
    public:
        string what() {
            return "Nama pemain tersebut sudah digunakan! Silahkan gunakan nama lain.";
        }
};

class TipePlayerInvalid : public Exception {
    public:
        string what() {
            return "Jenis pemain tidak valid! silahkan masukan peternak atau petani.";
        }
};

class GuldenTidakCukup : public Exception {
    public:
        string what() {
            return "Kamu tidak punya cukup gulden!";
        }
};

class QuantityTokoTidakCukup : public Exception {
    public:
        string what() {
            return "Kuantitas yang kamu beli melebihi limit yang ada di toko!";
        }
};

class WalikotaHanya1 : public Exception {
    public:
        string what() {
            return "Kamu tidak dapat menambah walikota!";
        }
};

class PeranInvalid : public Exception {
    public:
        string what() {
            return "Peran tidak valid!";
        }
};

class IndexOutOfRange : public Exception {
    public:
        string what() {
            return "Index out of range!";
        }
};

class InvalidGridSlot : public Exception {
    public:
        string what() {
            return "Slot yang dipilih tidak valid.";
        }
};

#endif