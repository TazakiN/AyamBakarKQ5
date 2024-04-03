#include "Petani.hpp"

Petani::Petani(string name, int row, int col) : Proletar(name, row, col) {}

Petani::~Petani() {}

void Petani::tanam(Tanaman& nama_tanaman, int row, int col)
{
    // nanti
}

void Petani::CetakPetak() 
{
    // nanti
}

void Petani::Panen() 
{
    // nanti
}

float Petani::HitungPajak() 
{
    float ktkp = 13;
    float kkp = getGulden();
    float tarif;
    if (kkp <= 6) {
        tarif = 0.05;
    } else if (6 < kkp && kkp <= 25) {
        tarif = 0.15;
    } else if (25 < kkp && kkp <= 50) {
        tarif = 0.25;
    } else if (50 < kkp & kkp <= 500) {
        tarif = 0.30;
    } else {
        tarif = 0.35;
    }

    return (hitungKekayaan()-ktkp)*tarif;
}
