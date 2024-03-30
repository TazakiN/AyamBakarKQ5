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
class UnableToOpenFile : public Exception {
    public:
        string what() {
            return "Tidak dapat membuka file!";
        }
};

// Lokasi invalid (folder belum ada)
class InvalidLocation : public Exception {
    public:
        string what() {
            return "Lokasi berkas tidak valid!";
        }
};

/* General Exception */
// Invalid Input
class InvalidInput : public Exception {
    public:
        string what() {
            return "Input salah, mohon ulangi dengan input yang valid!";
        }
};

// Invalid Command
class InvalidCommand : public Exception {
    public:
        string what() {
            return "Perintah tidak valid!";
        }
};

// Inventory
class InventoryFull : public Exception {
    public:
        string what() {
            return "Inventory sudah penuh!";
        }
};

// Uang tidak cukup
class NotEnoughMoney : public Exception {
    public:
        string what() {
            return "Uang tidak cukup!";
        }
};

// Penyimpanan tidak cukup
class NotEnoughInventorySpace : public Exception {
    public:
        string what() {
            return "Jumlah penyimpanan tidak cukup!";
        }
};

// Penyimpanan kosong
class InventoryEmpty : public Exception {
    public:
        string what() {
            return "Penyimpanan kosong!";
        }
};

// Petak kosong
class PetakEmpty : public Exception {
    public:
        string what() {
            return "Kamu memilih angin.. Petak ini kosong..";
        }
};

// Makan
class EmptySlot : public Exception {
    public:
        string what() {
            return "Kamu mengambil harapan kosong dari penyimpanan.\n Silahkan masukan slot yang berisi makanan."; 
        }
};

class ContainsOtherThanFood : public Exception {
    public:
        string what() {
            return "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!\n Silahkan masukan slot yang berisi makanan.";
        }
};

/* Petani Exception */
// Tanam
class HasNoPlants : public Exception {
    public:
        string what() {
            return "Perintah gagal dilakukan, tidak ada tanaman di penyimpanan!";
        }
};

// Ladang/kandang penuh (Petani-Peternak)
class FieldFull : public Exception {
    public:
        string what() {
            return "Perintah gagal dilakukan, ladang sudah penuh!";
        }
};

// Panen (Petani-Peternak)
class NotReadyToHarvest : public Exception {
    public:
        string what() {
            return "Jenis ini belum siap untuk dipanen!";
        }
};

class InvalidPetakPanen : public Exception {
    public:
        string what() {
            return "Jumlah petak panen tidak valid! mohon ulangi.";
        }
};


/* Peternak Exception */
// Ternak
class HasNoAnimals : public Exception {
    public:
        string what() {
            return "Perintah gagal dilakukan, tidak ada hewan di penyimpanan!";
        }
};

// class BarnFull : public Exception {
//     public:
//         string what() {
//             return "Perintah gagal dilakukan, kandang sudah penuh!";
//         }
// };

// Kasih_makan
class FieldEmpty : public Exception {
    public:
        string what() {
            return "Mau kasih makan apa??!!, kandangmu kosong!";
        }
};

class NoFoodForAnimal : public Exception {
    public:
        string what() {
            return "Yah, kamu tidak punya makanan untuk hewan tersebut!";
        }
};


/* Walikota Exception */
// Bangun
class NotEnoughMaterials : public Exception {
    public:
        string what() {
            return "Kamu tidak punya sumber daya yang cukup!"; // Nanti tambah message kurangnya apa
        }
};

class BuildingNotExists : public Exception {
    public:
        string what() {
            return "Kamu tidak punya resep bangunan tersebut!";
        }
};

// Tambah_pemain
class PlayerExists : public Exception {
    public:
        string what() {
            return "Nama pemain tersebut sudah digunakan! Silahkan gunakan nama lain.";
        }
};

class PlayerTypeNotExists : public Exception {
    public:
        string what() {
            return "Jenis pemain tidak valid! silahkan masukan peternak atau petani.";
        }
};



#endif