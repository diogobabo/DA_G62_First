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
    vector<ExpressoEncomenda *> expEncomendas;


public:
    /**
     * Constructor
     */
    Empresa() = default;

    /**
     * Constructor
     * @param fileEncomendas localizacao do ficheiro de carrinhas.txt
     * @param fileCarrinhas localizacao do ficheiro encomendas.txt
     */
    Empresa(string fileEncomendas, string fileCarrinhas);

    /**
     * Função responsável por ler o ficheiro das carrinhas
     * @param fileName localizacao do ficheiro de carrinhas.txt
     */
    void lerCarrinhas(std::string *fileName);

    /**
     * Função responsável por ler o ficheiro das encomendas
     * @param fileName localizacao do ficheiro encomendas.txt
     */
    void lerEncomendas(std::string *fileName);

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

    /**
     * Retorna vetor de encomendas expresso
     * @return encomendas
     */
    std::vector<ExpressoEncomenda *> getExpEncomendas() const {return expEncomendas;};
};


#endif //DA_T4_G62_EMPRESA_H
