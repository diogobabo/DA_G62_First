#include "carrinha.h"

Carrinha::Carrinha(unsigned int volMax, unsigned int pesoMax, unsigned int custo): volMax(volMax), pesoMax(pesoMax), custo(custo)
{
}

int Carrinha::adicionarEncomenda(Encomenda *encomenda) {
    if(!verificaDisponibilidade(encomenda)) {
        return 1; // encomenda não cabe na carrinha
    }

    encomendas.push_back(encomenda);
    vol+=encomenda->getVol();
    peso+=encomenda->getPeso();
    balanco+=(int) encomenda->getRecompensa();
    return 0;
}

int Carrinha::verificaDisponibilidade(Encomenda *encomenda) {
    if(encomenda->getVol()+vol>volMax || encomenda->getPeso()+peso>pesoMax) {
        return 1; // encomenda não cabe na carrinha
    }
    return 0;
}


int Carrinha::removerEncomenda(Encomenda *encomenda) {
    for(auto itr = encomendas.begin(); itr!=encomendas.end(); itr++) {
        if(*itr==encomenda) {
            balanco-= (int) encomenda->getRecompensa();
            peso-=encomenda->getPeso();
            vol-=encomenda->getVol();
            encomendas.erase(itr);
            return 0;
        }
    }
    return 1;
}
