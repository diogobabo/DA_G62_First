#include "cenarios.h"

Cenario2::Cenario2(const Empresa& e) {
    this->encomendas = e.getEncomendas();
    this->carrinhas = e.getCarrinhas();
}

bool Cenario2::sortByRecompensa(const Encomenda* e1, const Encomenda* e2) {
    return e1->getRecompensa() > e2->getRecompensa();
}

bool Cenario2::sortByVarCarrinha(const Carrinha *c1, const Carrinha *c2) {
    return c1->getVarDecisiva() > c2->getVarDecisiva();
}

bool Cenario2::sortByVarEncomendaRecompensa(const Encomenda *e1, const Encomenda *e2) {
    return e1->getRecompensaUnidade() > e2->getRecompensaUnidade();
}
bool Cenario2::sortStruct(const ENCOMENDA_VALOR &e1, const ENCOMENDA_VALOR &e2) {
    return e1.profit < e2.profit;
}
ENCOMENDA_VALOR Cenario2::solveKnapsack(Carrinha &c) {
    ENCOMENDA_VALOR v;
    if(!c.getEncomendas().empty()){
        return v;
    }

    if (c.getPesoMax() <= 0 || c.getVolMax() <= 0 ||encomendas.empty()) {
        return v;
    }

    int n = (int)encomendas.size();
    vector<vector<vector<ENCOMENDA_VALOR>>> dp(n, vector<vector<ENCOMENDA_VALOR>>(c.getVolMax(), vector<ENCOMENDA_VALOR>(c.getPesoMax(), v)));// dp[index][volume][peso]

    for (int i = 0; i < n; i++) {
        for(int v = 0; v < c.getVolMax();v++){
            dp[i][v][0].profit = 0;
        }
        for(int w = 0; w < c.getPesoMax(); w++){
            dp[i][0][w].profit = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        if(encomendas[i]->getEstado()){
            continue;
        }
        for (int v = 0; v < c.getVolMax();v++) {
            for(int w = 0; w < c.getPesoMax(); w++){
                if(encomendas[i]->getEstado()){
                    continue;
                }
                ENCOMENDA_VALOR profit1 , profit2;
                profit1.profit = 0;
                profit2.profit = 0;

                if (encomendas[i]->getVol()<=v && encomendas[i]->getPeso()<=w) {
                    ENCOMENDA_VALOR var = dp[i - 1][v - encomendas[i]->getVol()][w - encomendas[i]->getPeso()];
                    var.profit = (int) (var.profit + encomendas[i]->getRecompensa()) ;
                    var.CarrinhaEncomneda.push_back(encomendas[i]);
                    profit1 = var;
                }

                profit2 = dp[i - 1][v][w];

                dp[i][v][w] = max(profit1, profit2,sortStruct);
            }

        }
    }

    return dp[n - 1][c.getVolMax()-1][c.getPesoMax()-1];
}

int Cenario2::solveMaxLucro() {
    prepareSolve();
    Carrinha *max=nullptr;
    ENCOMENDA_VALOR maxs;
    for(int car = 0; car<carrinhas.size();car++){
        ENCOMENDA_VALOR solved = solveKnapsack(*carrinhas[car]);
        if(maxs.profit < solved.profit){
            maxs = solved;
            max = carrinhas[car];
        }
    }
    for(int n = 0;n<maxs.CarrinhaEncomneda.size();n++){
        max->adicionarEncomenda(maxs.CarrinhaEncomneda[n]);
    }

    int profit = 0;
    for(int car = 0; car<carrinhas.size();car++){
        if(carrinhas[car]->getBalanco()>0){
            profit +=carrinhas[car]->getBalanco();
        }
    }
    return profit;
}

void Cenario2::prepareSolve() {

    sort(carrinhas.begin(),carrinhas.end(), sortByVarCarrinha);

    Encomenda*e = new Encomenda(0,0,0);
    encomendas.push_back(e);
    sort(encomendas.begin(), encomendas.end(), sortByVarEncomendaRecompensa);


    return;
}

ENCOMENDA_VALOR Cenario2::prepareKnapsack() {
    return ENCOMENDA_VALOR();
}
