#include "encomenda.h"

#include <vector>

class Carrinha {
private:
    unsigned int volMax;
    unsigned int pesoMax;
    unsigned int custo;

    unsigned int vol;
    unsigned int peso;
    int balanco=-(int)custo;
    std::vector<Encomenda *> encomendas;
public:
    /**
     * Carrinha
     * @param volMax volume maximo
     * @param pesoMax peso maximo
     * @param custo custo
     */
    Carrinha(unsigned int volMax, unsigned int pesoMax, unsigned int custo);

    /**
     * Adicionar encomenda para transporte
     * @param encomenda encomenda a ser transportada
     * @return 0 se for possivel adicionar a encomenda a carrinha
     */
    int adicionarEncomenda(Encomenda *encomenda);


};