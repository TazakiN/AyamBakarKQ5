#include "Hewan.hpp"
#include "Produk.hpp"

class Herbivora : public Hewan
{
private:
public:
    /**
     * @brief konstruktor hewan herbivora
     *
     * @param nama hewan herbivora
     * @param kode_huruf hewan herbivora
     */
    Herbivora(string nama, string kode_huruf);

    /**
     * Destruktor hewan herbivora
     */
    ~Herbivora();

    /**
     * Hewan herbivora makan
     * 
     * @param makanan yang akan dimakan
     */
    void Makan(Produk &makanan);
};