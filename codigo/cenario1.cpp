#include <algorithm>
#include "cenarios.h"

using namespace std;


Cenario1::Cenario1(Empresa *e) {
    this->encomendas = e->getEncomendas();
    this->carrinhas = e->getCarrinhas();
}


int Cenario1::solveKnapsack(const std::vector<int> &profits, const std::vector<int> &weights, int capacity) {
    vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1, -1)); //aqui vai ter que ser 3 entradas, ou seja, vector<vector<vector<int>>>
    return this->knapsackRecursive(dp, profits, weights, capacity, 0);//vamos ter problemas no currentindex porque não vai ser um número
}


int Cenario1::knapsackRecursive(vector<vector<int>> &dp, const vector<int> &profits,const vector<int> &weights, int capacity, int currentIndex) {
    // base checks
    if (capacity <= 0 || currentIndex >= profits.size()) {
        return 0;
    }

    // if we have already solved a similar problem, return the result from memory
    if (dp[currentIndex][capacity] != -1) {
        return dp[currentIndex][capacity];
    }

    // recursive call after choosing the element at the currentIndex
    // if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
    int profit1 = 0;
    if (weights[currentIndex] <= capacity) {
        profit1 = profits[currentIndex] + knapsackRecursive(dp, profits, weights,capacity - weights[currentIndex],currentIndex + 1);
    }

    // recursive call after excluding the element at the currentIndex
    int profit2 = knapsackRecursive(dp, profits, weights, capacity, currentIndex + 1);

    dp[currentIndex][capacity] = max(profit1, profit2);
    return dp[currentIndex][capacity];
}

bool Cenario1::sortByVolume(const Encomenda *e1, const Encomenda *e2) {
    return e1->getVol() < e2->getVol();
}

bool Cenario1::sortByPeso(const Encomenda *e1, const Encomenda *e2) {
    return e1->getPeso() < e2->getPeso();
}

bool Cenario1::sortByVarCarrinha(const Carrinha *c1, const Carrinha *c2) {
    return c1->getVarDecisiva() > c2->getVarDecisiva();
}

bool Cenario1::sortByVarEncomenda(const Encomenda *e1, const Encomenda *e2) {
    return e1->getVarDecisiva() < e2->getVarDecisiva();
}

int Cenario1::tentativa() {
    sort(encomendas.begin(),encomendas.end(), sortByVarEncomenda);
    sort(carrinhas.begin(),carrinhas.end(), sortByVarCarrinha);
    int numCarrinhas = 0;
    for(int i = 0; i < carrinhas.size(); i++) {
        for(int j = 0; j < encomendas.size(); j++) {
            if(encomendas[j]->getEstado()) {
                continue;
            }
            if (!carrinhas[i]->verificaDisponibilidade(encomendas[j])) {
                carrinhas[i]->adicionarEncomenda(encomendas[j]);
            }
        }
    }
    for(auto x : carrinhas) {
        if(x->getEncomendas().size() != 0) {
            numCarrinhas++;
        }
    }
    return numCarrinhas;
}

int Cenario1::bestFit() {
    int numCarrinhas = 0;
    pair<int, int> bin_rem[encomendas.size()];

    for(int i = 0; i < encomendas.size(); i++) {
        int j;

        unsigned int minV = carrinhas[0]->getVolMax(), minP = carrinhas[0]->getPesoMax(), bi = 0;

        for(j=0; j<numCarrinhas; j++) {
            if(bin_rem[j].first >= encomendas[i]->getVol() && bin_rem[j].second >= encomendas[i]->getPeso() &&
            bin_rem[j].first-encomendas[i]->getVol()<minV && bin_rem[j].second-encomendas[i]->getPeso()<minP){
                bi = j;
                minV = bin_rem[j].first - encomendas[i]->getVol();
                minP = bin_rem[j].second - encomendas[i]->getPeso();
            }
        }

        if(minV==carrinhas[0]->getVolMax()&&minP==carrinhas[0]->getPesoMax()){
            bin_rem[numCarrinhas] = make_pair(minV-encomendas[i]->getVol(), minP-encomendas[i]->getPeso());
            numCarrinhas++;
        }
        else
            bin_rem[bi] = make_pair( bin_rem[bi].first-encomendas[i]->getVol(), bin_rem[bi].second-encomendas[i]->getPeso());
    }

    return numCarrinhas;
}
