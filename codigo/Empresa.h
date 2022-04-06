#ifndef DA_T4_G62_EMPRESA_H
#define DA_T4_G62_EMPRESA_H

#include <string>
#include <vector>
#include "encomenda.h"
#include "carrinha.h"

using namespace std;

class Empresa {
private:
    vector<Encomenda *> encomendas;
    vector<Carrinha *> carrinhas;


public:
    /**
     * Constructor
     */
    Empresa();

    /**
     * Constructor
     * @param fileEncomendas
     * @param fileCarrinhas
     */
    Empresa(string fileEncomendas, string fileCarrinhas);

    /**
     * Função responsável por ler o ficheiro das carrinhas
     * @param fileName
     */
    void lerCarrinhas(std::string fileName);

    /**
     * Função responsável por ler o ficheiro das encomendas
     * @param fileName
     */
    void lerEncomendas(std::string fileName);

    /**
     * Retorna vetor de encomendas
     * @return encomendas
     */
    std::vector<Encomenda *> getEncomendas() const {return encomendas;};

    /**
     * Retorna vetor de carrinhas
     * @return carrinhas
     */
    std::vector<Carrinha *> getCarrinhas() const {return carrinhas;};
};


#endif //DA_T4_G62_EMPRESA_H
