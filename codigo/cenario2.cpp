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
    return e1->getRecompensaUnidade() < e2->getRecompensaUnidade();
}
bool Cenario2::sortStruct(const ENCOMENDA_VALOR &e1, const ENCOMENDA_VALOR &e2) {
    return e1.profit < e2.profit;
}
ENCOMENDA_VALOR Cenario2::solveKnapsack(Carrinha &c) {

    if(!c.getEncomendas()->empty()){
        ENCOMENDA_VALOR v;
        return v;
    }

    ENCOMENDA_VALOR v;
    auto*e = new Encomenda(0,0,0);
    encomendas.push_back(e);
    sort(encomendas.begin(), encomendas.end(), sortByVarEncomendaRecompensa);
    if (c.getPesoMax() <= 0 || c.getVolMax() <= 0 ||encomendas.empty()) {
        ENCOMENDA_VALOR v;
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
    ENCOMENDA_VALOR resposta = dp[n - 1][c.getVolMax()-1][c.getPesoMax()-1];

    return resposta;
}

int Cenario2::solveMaxLucro() {
    for(int i=0; i<carrinhas.size(); i++){
        Carrinha *max=nullptr;
        ENCOMENDA_VALOR maxs;
        for(int car = 0; car<carrinhas.size();car++){
            ENCOMENDA_VALOR solved = solveKnapsack(*carrinhas[car]);
            if(maxs.profit < solved.profit){
                maxs = solved;
                max = carrinhas[car];
            }
        }
        if(maxs.profit<0 || porEntregar()){
            break;
        }
        for(int n = 0;n<maxs.CarrinhaEncomneda.size();n++){
            max->adicionarEncomenda(maxs.CarrinhaEncomneda[n]);
        }
    }
    int profit = 0;
    for(int car = 0; car<carrinhas.size();car++){
        if(carrinhas[car]->getBalanco()>0){
            profit +=carrinhas[car]->getBalanco();
        }
    }
    return profit;
}

bool Cenario2::porEntregar() {
    for(auto itr=encomendas.begin(); itr!=encomendas.end(); itr++)
        if(!(*itr)->getEstado()) return true;
    return false;
}

ENCOMENDA_VALOR Cenario2::solveKnapsackBabado(vector<vector<vector<ENCOMENDA_VALOR>>> &dp,Carrinha &c,int v,int w,int n,int i) {
    if (v <= 0 || w <= 0 ||i >= encomendas.size()){
        ENCOMENDA_VALOR v;
        v.profit = 0;
        return v;
    }
    if(dp[i][v][w].profit != -1)
        return dp[i][v][w];
    ENCOMENDA_VALOR profit1 , profit2;
    profit1.profit = 0;
    profit2.profit = 0;

    if(encomendas[i]->getEstado()){
        return {};
    }

    if (encomendas[i]->getVol()<=v && encomendas[i]->getPeso()<=w) {
        ENCOMENDA_VALOR var = dp[i - 1][v - encomendas[i]->getVol()][w - encomendas[i]->getPeso()];
        var.profit = var.profit + encomendas[i]->getRecompensa() ;
        var.CarrinhaEncomneda.push_back(encomendas[i]);
        profit1 = var;
    }

    profit2 = dp[i - 1][v][w];

    dp[i][v][w] = max(profit1, profit2,sortStruct);

    ENCOMENDA_VALOR resposta = dp[n - 1][c.getVolMax()-1][c.getPesoMax()-1];

    return resposta;
}

ENCOMENDA_VALOR Cenario2::solveKnapsackBabadonsei(Carrinha &c) {
    if(!c.getEncomendas()->empty()){
        ENCOMENDA_VALOR v;
        return v;
    }
    Encomenda*e = new Encomenda(0,0,0);
    encomendas.push_back(e);
    sort(encomendas.begin(), encomendas.end(), sortByVarEncomendaRecompensa);
    if (c.getPesoMax() <= 0 || c.getVolMax() <= 0 ||encomendas.empty()) {
        ENCOMENDA_VALOR v;
        return v;
    }
    ENCOMENDA_VALOR v;
    static int n = encomendas.size();
    static vector<vector<vector<ENCOMENDA_VALOR>>> dp(n, vector<vector<ENCOMENDA_VALOR>>(c.getVolMax(), vector<ENCOMENDA_VALOR>(c.getPesoMax(), v)));// dp[index][volume][peso]
    for (int i = 0; i < n; i++) {
        for(int v = 0; v < c.getVolMax();v++){
            dp[i][v][0].profit = 0;
        }
        for(int w = 0; w < c.getPesoMax(); w++){
            dp[i][0][w].profit = 0;
        }
    }
    return solveKnapsackBabado(dp,c,c.getVolMax(),c.getPesoMax(),n,1);
}
