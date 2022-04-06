#include "encomenda.h"

Encomenda::Encomenda(unsigned int vol, unsigned int peso, unsigned int recompensa): vol(vol),peso(peso),recompensa(recompensa)
{}

bool Encomenda::sortByVolume(const Encomenda &e1, const Encomenda &e2) {
    return e1.vol < e2.vol;
}

bool Encomenda::sortByPeso(const Encomenda &e1, const Encomenda &e2) {
    return e1.peso < e2.peso;
}

bool Encomenda::sortByRecompensa(const Encomenda &e1, const Encomenda &e2) {
    return e1.recompensa < e2.recompensa;
}

ExpressoEncomenda::ExpressoEncomenda(unsigned int vol, unsigned int peso, unsigned int recompensa, unsigned int duracao): Encomenda(vol, peso, recompensa), duracao(duracao)
{}

bool ExpressoEncomenda::sortByDuracao(const ExpressoEncomenda &e1, const ExpressoEncomenda &e2) {
    return e1.duracao < e2.duracao;
}

NormalEncomenda::NormalEncomenda(unsigned int vol, unsigned int peso, unsigned int recompensa): Encomenda(vol, peso, recompensa)
{}
