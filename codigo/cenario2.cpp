#include "cenarios.h"
//#include "dpmatrix.h"

Cenario2::Cenario2(const Empresa &e) {
    this->encomendas = e.getEncomendas();
    this->carrinhas = e.getCarrinhas();
}

bool Cenario2::sortByRecompensa(const Encomenda *e1, const Encomenda *e2) {
    return e1->getRecompensa() > e2->getRecompensa();
}

bool Cenario2::sortByVarCarrinha(const Carrinha *c1, const Carrinha *c2) {
    return c1->getCustoUnidade() < c2->getCustoUnidade();
}

bool Cenario2::sortByVarEncomendaRecompensa(const Encomenda *e1, const Encomenda *e2) {
    return e1->getRecompensaUnidade() < e2->getRecompensaUnidade();
}

bool Cenario2::sortStruct(const ENCOMENDA_VALOR &e1, const ENCOMENDA_VALOR &e2) {
    return e1.profit < e2.profit;
}

ENCOMENDA_VALOR Cenario2::solveKnapsack(Carrinha &c, vector<Encomenda *> encomendas) {
    ENCOMENDA_VALOR ev;
    if (!c.getEncomendas()->empty()) {
        return ev;
    }

    int n = (int) encomendas.size();

    // dp[index][volume][peso]
    vector<vector<vector<ENCOMENDA_VALOR>>> dp(2,
                                               vector<vector<ENCOMENDA_VALOR>>(c.getVolMax() + 1,
                                                                               vector<ENCOMENDA_VALOR>(
                                                                                       c.getPesoMax() + 1,
                                                                                       ev)));

    ENCOMENDA_VALOR profit1;
    int cGetVol = (int) c.getVolMax(), cGetPeso = (int) c.getPesoMax();

    for (int i = 0; i <= n; i++) {
        int eVol, ePes, eRec; // vars da encomenda a ser iterada
        if (i != 0) {
            if (encomendas[i - 1]->getEstado()) {
                continue; // entregue
            }
            eVol = (int) encomendas[i - 1]->getVol(), ePes = (int) encomendas[i -
                                                                              1]->getPeso(), eRec = (int) encomendas[i -
                                                                                                                     1]->getRecompensa();
        }
        for (int v = 0; v <= cGetVol; v++) {
            for (int w = 0; w <= cGetPeso; w++) {
                if (i == 0 || v == 0 || w == 0) {
                    dp[i % 2][v][w].profit = 0;
                    continue;
                }
                if (eVol <= v && ePes <= w) { // encomenda cabe na celula da tabela
                    if (eRec + dp[(i - 1) % 2][v - eVol][w - ePes].profit > dp[(i - 1) % 2][v][w].profit) {
                        dp[i % 2][v][w] = dp[(i - 1) % 2][v - eVol][w - ePes];
                        dp[i % 2][v][w].profit += eRec;
                        dp[i % 2][v][w].CarrinhaEncomenda.push_back(encomendas[i - 1]);
                    } else {
                        dp[i % 2][v][w] = dp[(i - 1) % 2][v][w];
                    }
                } else
                    dp[i % 2][v][w] = dp[(i - 1) %
                                         2][v][w]; // encomenda a ser iterada nao cabe, dp igual a linha anterior
            }
        }
    }
    return dp[n % 2][cGetVol][cGetPeso];
}

int Cenario2::solveMaxLucro() {
    prepareSolve();

    int profit = 0;
    int nr_carrinhas = 0, iteracoes = 0;
    for (auto &carrinha: carrinhas) {
        cout << ++iteracoes << endl;
        ENCOMENDA_VALOR solved = prepareKnapsack(*carrinha);
        if (solved.profit==-5) {
            break;
        }
        else if(solved.profit-carrinha->getCusto()<0){
            cout << "unprofit, profit: " << solved.profit << ", custo: " << carrinha->getCusto() << endl;
            continue;
        }
        for (auto &n: solved.CarrinhaEncomenda) {
            carrinha->adicionarEncomenda(n);
        }

        profit += carrinha->getBalanco();
        cout << "Carrinha nr: " << ++nr_carrinhas << ", nr de encomendas: " << solved.CarrinhaEncomenda.size() << ", balanco: " << carrinha->getBalanco() << endl;
    }

    return profit;
}

void Cenario2::prepareSolve() {
    sort(carrinhas.begin(), carrinhas.end(), sortByVarCarrinha);
    sort(encomendas.begin(), encomendas.end(), sortByVarEncomendaRecompensa);

    std::reverse(encomendas.begin(), encomendas.end());
}

ENCOMENDA_VALOR Cenario2::prepareKnapsack(Carrinha &c) {
    vector<Encomenda *> e;
    for (auto &encomenda: encomendas) {
        if (!encomenda->getEstado()) {
            e.push_back(encomenda);
        }
    }
    if (e.empty()) {
        ENCOMENDA_VALOR v;
        v.profit=-5;
        return v;
    }
    cout << e.size() << " encomendas por entregar\n";
    return solveKnapsack(c, e);
}

double Cenario2::getQuocient() {
    int counter = 0;
    for (auto x: encomendas) {
        if (x->getEstado()) {
            counter++;
        }
    }
    return (counter / (double) encomendas.size());
}

