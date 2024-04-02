#include "Hewan.hpp"
#include "Produk.hpp"

class Omnivora : public Hewan
{
private:
public:
    /**
     * @brief konstruktor hewan omnivora
     *
     * @param nama hewan omnivora
     * @param kode_huruf hewan omnivora
     */
    Omnivora(string nama, string kode_huruf);

    /**
     * Destruktor hewan omnivora
     */
    ~Omnivora();

    /**
     * Hewan omnivora makan
     * 
     * @param makanan yang akan dimakan
     */
    void Makan(Produk &makanan);
};