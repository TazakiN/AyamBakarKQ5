#ifndef PETANI_HPP
#define PETANI_HPP

#include "Proletar.hpp"
#include "../Item/Tanaman.hpp"

class Petani : public Proletar
{
public:
    /**
     * @brief Konstruktor petani dengan nama tertentu.
     *
     * @param name nama petani
     * @param row banyak baris ladang petani
     * @param col banyak kolom ladang petani
     */
    Petani(string name, int row, int col);

    /**
     * Destruktor petani
     */
    ~Petani();

    /**
     * Menanam tanaman
     *
     * @param nama_tanaman nama tanaman yang ingin ditanam
     * @param row row inventory tempat tanaman ditanam
     * @param col kolom inventory tempat tanaman ditanam
     */
    void tanam(Tanaman& nama_tanaman, int row, int col);

    /**
     * Menampilkan ladang milik petani
     */
    void CetakPetak();

    /**
     * Melakukan panen pada ladang milik petani
     */
    void Panen();

    /**
     * Mengembalikan jumlah pajak yang dimiliki petani
     *
     * @return jumlah pajak petani
     */
    float HitungPajak();
};

#endif