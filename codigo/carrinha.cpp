#include "carrinha.h"

Carrinha::Carrinha(unsigned int volMax, unsigned int pesoMax, unsigned int custo): volMax(volMax), pesoMax(pesoMax), custo(custo)
{
}

int Carrinha::adicionarEncomenda(Encomenda *encomenda) {
    if(encomenda->getVol()+vol>volMax || encomenda->getPeso()+peso>pesoMax) {
        return 1;
    }
    vol+=encomenda->getVol();
    peso+=encomenda->getPeso();
    balanco
    encomendas.push_back(encomenda);

    return 0;
}
