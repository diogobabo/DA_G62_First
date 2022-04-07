#include "cenarios.h"

using namespace std;


Cenario1::Cenario1() {
    Empresa e("../input/encomendas.txt","../input/carrinhas.txt");
    this->encomendas = e.getEncomendas();
    this->carrinhas = e.getCarrinhas();
}


int Cenario1::solveKnapsack(const std::vector<int> &profits, const std::vector<int> &weights, int capacity) {
    vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1, -1));//aqui vai ter que ser 3 entradas ou seja vector<vector<vector<int>>>
    return this->knapsackRecursive(dp, profits, weights, capacity, 0);//vamos ter problemas no currentindex pq n vai ser um numero
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
