#include <algorithm>
#include "cenarios.h"

Cenario3::Cenario3(Empresa *e) {
    encomendasExp = e->getExpEncomendas();
}

bool Cenario3::sortByDuracao(const ExpressoEncomenda* e1, const ExpressoEncomenda* e2) {
    return e1->getDuracao() < e2->getDuracao();
}

int Cenario3::greedyMinAvgTime() {
    sort(encomendasExp.begin(), encomendasExp.end(), sortByDuracao);
    double sum = encomendasExp[0]->getDuracao();
    int startTime = 32400 + (int) encomendasExp[0]->getDuracao(); // corresponde a 09:00 + a 1st encomenda
    int endTime = 61200; // corresponde a 17:00
    double avgTime;
    int numEncomendas = 1;
    int temp = 0;
    for(int i = 1; i < encomendasExp.size(); i++) {
        if(startTime + encomendasExp[i]->getDuracao() <= endTime) {
            temp += (int) encomendasExp[i-1]->getDuracao();
            sum += temp + encomendasExp[i]->getDuracao();
            numEncomendas++;
        }
        else {
            break;
        }
    }
    avgTime = sum / numEncomendas; // tempo minimizado
    return (int) avgTime;
}
