#include "Hewan.hpp"
#include "Produk.hpp"

class Karnivora : public Hewan
{
private:
public:
    /**
     * @brief konstruktor hewan karnivora
     *
     * @param nama hewan karnivora
     * @param kode_huruf hewan karnivora
     */
    Karnivora(string nama, string kode_huruf);

    /**
     * Destruktor hewan karnivora
     */
    ~Karnivora();

    /**
     * Hewan karnivora makan
     * 
     * @param makanan yang akan dimakan
     */
    void Makan(Produk &makanan);
};