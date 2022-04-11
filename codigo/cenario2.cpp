#include "cenarios.h"

Cenario2::Cenario2(Empresa *e) {
    this->encomendas = e->getEncomendas();
    this->carrinhas = e->getCarrinhas();
}

bool Cenario2::sortByRecompensa(const Encomenda* e1, const Encomenda* e2) {
    return e1->getRecompensa() > e2->getRecompensa();
}

bool Cenario2::sortByVarCarrinha(const Carrinha *c1, const Carrinha *c2) {
    return c1->getVarDecisiva() > c2->getVarDecisiva();
}

bool Cenario2::sortByVarEncomenda(const Encomenda *e1, const Encomenda *e2) {
    return e1->getVarDecisiva() > e2->getVarDecisiva();
}
