#include "cenarios.h"




bool Cenario3::sortByDuracao(const ExpressoEncomenda* e1, const ExpressoEncomenda* e2) {
    return e1->getDuracao() < e2->getDuracao();
}