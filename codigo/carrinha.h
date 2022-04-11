#ifndef DA_T6_G62_CARRINHA_H
#define DA_T6_G62_CARRINHA_H

#include "encomenda.h"

#include <vector>

class Carrinha {
private:
    unsigned int volMax;
    unsigned int pesoMax;
    unsigned int custo;

    unsigned int vol=0;
    unsigned int peso=0;
    int balanco=-(int)custo;
    double var_decisiva;
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

    /**
     * Verifica se consegue adicionar encomenda a carrinha
     * @param encomenda encomenda a verificar
     * @return 0 se for possivel adicionar
     */
    int verificaDisponibilidade(Encomenda *encomenda) const;

    /**
     * Remover encomenda do transporte
     * @param encomenda encomenda a ser removida
     * @return 0 se conseguiu remover
     */
    int removerEncomenda(Encomenda *encomenda);

    /**
     * Retorna volume maximo da carrinha
     * @return volume maximo
     */
    unsigned int getVolMax() const {return volMax;};

    /**
     * Retorna peso maximo da carrinha
     * @return peso maximo
     */
    unsigned int getPesoMax() const {return pesoMax;};

    /**
     * Retorna custo do transporte
     * @return custo
     */
    unsigned int getCusto() const {return custo;};

    /**
     * Retorna volume atual
     * @return volume
     */
    unsigned int getVol() const {return vol;};

    /**
     * Retorna peso atual
     * @return  peso
     */
    unsigned int getPeso() const {return peso;};

    /**
     * Retorna balanco atual
     * @return balanco
     */
    int getBalanco() const {return balanco;};

    /**
     * Retorna vetor de encomendas
     * @return encomendas
     */
    std::vector<Encomenda *> getEncomendas() const {return encomendas;};

    /**
     * Define variável decisiva, balanço entre peso e volume
     * @param peso_peso percentagem do peso
     * @param peso_vol percentagem do volume
     */
    void setVarDecisiva(int peso_peso, int peso_vol);
};

#endif //DA_T6_G62_CARRINHA_H
