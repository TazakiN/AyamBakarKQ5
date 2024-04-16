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
            return p_rgb(224,23,96) + "Tidak dapat membuka file!" + reset();
        }
};

// Lokasi invalid (folder belum ada)
class LokasiInvalid : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Lokasi berkas tidak valid!" + reset();
        }
};

/* General Exception */
// Inventory
class InventoryPenuh : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Inventory sudah penuh!" + reset();
        }
};

// Uang tidak cukup
class UangTidakCukup : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Uang tidak cukup!" + reset();
        }
};

// Penyimpanan tidak cukup
class PenyimpananTidakCukup : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Jumlah penyimpanan tidak cukup!" + reset();
        }
};

// Penyimpanan kosong
class InventoryKosong : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Penyimpanan kosong!" + reset();
        }
};

// Petak kosong
class PetakKosong : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Kamu memilih angin.. Petak ini kosong.." + reset();
        }
};

/* Petani Exception */
// Tanam
class BukanTanaman : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Item yang dipilih bukanlah tanaman." + reset();
        }
};

class PilihanTanamanInvalid : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Pilihan tanaman tidak valid." + reset();
        }
};

class PetakTidakValid : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Petak yang dipilih tidak valid." + reset();
        }
};

class PetakSudahTerisi : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Petak ladang sudah terisi." + reset();
        }
};

class PetakKandangSudahTerisi : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Petak kandang sudah terisi." + reset();
        }
};

// Ladang penuh
class LadangPenuh : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Perintah gagal dilakukan, ladang sudah penuh!" + reset();
        }
};

// Panen (Petani-Peternak)
class BelumSiapPanen : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Jenis ini belum siap untuk dipanen!" + reset();
        }
};

class PetakPanenInvalid : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Jumlah petak panen tidak valid!" + reset();
        }
};


/* Peternak Exception */
class PilihanHewanInvalid : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Pilihan hewan tidak valid." + reset();
        }
};

class BukanMakanan : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Item yang dipilih bukanlah makanan." + reset();
        }
};

// kasih makan, tapi isi row col nya bukan hewan
class BukanHewan : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Item yang dipilih bukanlah hewan." + reset();
        }
};

// Ternak
class TidakAdaHewan : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Perintah gagal dilakukan, tidak ada hewan di penyimpanan!" + reset();
        }
};

// Kandang penuh
class KandangPenuh : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Perintah gagal dilakukan, kandang sudah penuh!" + reset();
        }
};

// Kasih_makan
class KandangKosong : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Mau kasih makan apa??!!, kandangmu kosong!" + reset();
        }
};

class TidakAdaPakan : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Yah, kamu tidak punya makanan untuk hewan tersebut!" + reset();
        }
};

class SlotKosong : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Kamu mengambil harapan kosong dari penyimpanan.\n Silahkan masukan slot yang berisi makanan." + reset(); 
        }
};

// class ContainsOtherThanFood : public Exception {
//     public:
//         string what() {
//             return p_rgb(224,23,96) + "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!\n Silahkan masukan slot yang berisi makanan." + reset();
//         }
// };

class WrongFood : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Makanan yang dipilih tidak sesuai untuk jenis hewan yang dipilih." + reset(); 
        }
};

/* Walikota Exception */
// Bangun
class MaterialTidakCukup : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Kamu tidak punya sumber daya yang cukup!" + reset(); // Nanti tambah message kurangnya apa
        }
};

class ResepBangunanInvalid : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Kamu tidak punya resep bangunan tersebut!" + reset();
        }
};

// Tambah_pemain
class NamaPlayerTerpakai : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Nama pemain tersebut sudah digunakan! Silahkan gunakan nama lain." + reset();
        }
};

class TipePlayerInvalid : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Jenis pemain tidak valid! silahkan masukan peternak atau petani." + reset();
        }
};

class GuldenTidakCukup : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Kamu tidak punya cukup gulden!" + reset();
        }
};

class QuantityTokoTidakCukup : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Kuantitas yang kamu beli melebihi limit yang ada di toko!" + reset();
        }
};

class WalikotaHanya1 : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Kamu tidak dapat menambah walikota!" + reset();
        }
};

class PeranInvalid : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Peran tidak valid!" + reset();
        }
};

class IndexOutOfRange : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Index out of range!" + reset();
        }
};

class InvalidGridSlot : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Slot yang dipilih tidak valid." + reset();
        }
};

class JualBangunan : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Kamu bukan walikota, kamu tidak dapat menjual bangunan!" + reset();
        }
};

class KuantitasTidakValid : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Kuantitas tidak valid!" + reset();
        }
};

class InvalidDataType : public Exception {
    public:
        string what() {
            return p_rgb(224,23,96) + "Tipe data invalid!" + reset();
        }
};

// class NamaSudahAda : public Exception {
//     public:
//         string what() {
//             return "Pemain dengan nama tersebut sudah ada. Silakan cari nama lain!";
//         }
// };

#endif