#include "Walikota.hpp"

Walikota::Walikota(string nama, int col, int row) : Pemain(nama, row, col)
{
}

Walikota::~Walikota()
{
}

// Membangun bangunan
void Walikota::bangunBangunan(int jenisBangunan)
{
    for (int i = 0; i < 4; i++)
    {
        // if (this->bahanBangunan[jenisBangunan][i] < listOfResepBangunan[jenisBangunan][i])
        // {
        //     // exception
        //     return;
        // }
        jenisBangunan++; // <-- ini ntar dihapus, ini supaya ga error unused variable aja
    }

    // Loop buat nyari inventory kosong, tambahin bangunan
}

void Walikota::tagihPajak()
{
    // Tagih semua pemain
}

// void Walikota::tambahProletar(string namaPemain, int jenisPemain)
// {

//     // Construct proletar
// }
