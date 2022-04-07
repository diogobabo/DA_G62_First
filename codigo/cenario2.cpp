#include "cenarios.h"

Cenario2::Cenario2() {
    Empresa e("../input/encomendas.txt","../input/carrinhas.txt");
    this->encomendas = e.getEncomendas();
    this->carrinhas = e.getCarrinhas();
}

bool Cenario2::sortByRecompensa(const Encomenda* e1, const Encomenda* e2) {
    return e1->getRecompensa() > e2->getRecompensa();
}
