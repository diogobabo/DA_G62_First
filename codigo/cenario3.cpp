#include <algorithm>
#include "cenarios.h"

Cenario3::Cenario3(const Empresa& e) {
    encomendasExp = e.getExpEncomendas();
}

bool Cenario3::sortByDuracao(const ExpressoEncomenda* e1, const ExpressoEncomenda* e2) {
    return e1->getDuracao() < e2->getDuracao();
}

vector<int> Cenario3::greedyMinAvgTime() {
    sort(encomendasExp.begin(), encomendasExp.end(), sortByDuracao);
    double sum = encomendasExp[0]->getDuracao();
    int startTime = 32400 + (int) encomendasExp[0]->getDuracao(); // corresponde a 09:00 + a 1st encomenda
    int endTime = 61200; // corresponde a 17:00
    int avgTime;
    int numEncomendas = 1;
    int temp = 0;
    int numDias = 1;
    vector<int> avgTimeAllDays;
    for(int i = 1; i < encomendasExp.size(); i++) {
        if(startTime + (int) encomendasExp[i]->getDuracao() <= endTime) {
            temp += (int) encomendasExp[i-1]->getDuracao();
            sum += temp + encomendasExp[i]->getDuracao();
            numEncomendas++;
            startTime += (int)encomendasExp[i]->getDuracao();
        }
        else {
            numDias++;
            avgTime = (int) sum / numEncomendas;

            avgTimeAllDays.push_back(avgTime);
            startTime = 32400 + (int) encomendasExp[i]->getDuracao();
            if(startTime > endTime) {
                break;
            }
            if(i == encomendasExp.size() - 1){
                avgTimeAllDays.push_back((int)encomendasExp[i]->getDuracao());
                break;
            }
            numEncomendas = 1;
            temp = 0;
            sum = encomendasExp[i]->getDuracao();
        }
    }

    avgTime = (int) sum / numEncomendas;
    if(avgTimeAllDays.empty() || numEncomendas < encomendasExp.size()) {
        avgTimeAllDays.push_back(avgTime);
    }
    return avgTimeAllDays;
}
