#include "cenarios.h"
//#include "dpmatrix.h"

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
ENCOMENDA_VALOR Cenario2::solveKnapsack(Carrinha &c,vector<Encomenda *> encomendas) {
    ENCOMENDA_VALOR ev;
    if(!c.getEncomendas()->empty()){
        return ev;
    }

    int n = (int)encomendas.size();
    int cGetVol = (int) c.getVolMax(),cGetPeso = (int)c.getPesoMax();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(cGetVol+1, vector<int>(cGetPeso+1)));// dp[index][volume][peso]

    for (int i=0; i<=n; i++) {
        for (int v = 0; v <= cGetVol;v++) {
                for(int w = 0; w <= cGetPeso; w++){
                    if(i == 0 || w == 0 || v == 0){
                        dp[i][v][w] = 0;
                        continue;
                    }
                    int eVol = (int) encomendas[i-1]->getVol(),ePes = (int)encomendas[i-1]->getPeso(), eRec=(int)encomendas[i-1]->getRecompensa();
                    if (eVol<=v && ePes<=w) {
                        dp[i][v][w] = max(eRec + dp[i-1][v-eVol][w-ePes], dp[i-1][v][w]);
                    }
                    else dp[i][v][w] = dp[i - 1][v][w];
            }
        }
    }

    ev.profit = dp[n][cGetVol][cGetPeso];
    int last=dp[n][c.getVolMax()][c.getPesoMax()];
    int nr=n, vol=(int)c.getVolMax(), peso=(int)c.getPesoMax();
    while(last!=0){
        nr-=1;
        if(dp[nr][vol][peso]==last) continue;
        ev.CarrinhaEncomenda.push_back(encomendas.at(nr+1));
        last=dp[nr][vol - encomendas.at(nr)->getVol()][peso - encomendas.at(nr)->getPeso()];
    }
    return ev;
}

int Cenario2::solveMaxLucro() {
    prepareSolve();

    for(auto & carrinha : carrinhas){
        ENCOMENDA_VALOR solved = prepareKnapsack(*carrinha);
        if(solved.profit == -5){
            break;
        }
        for(auto & n : solved.CarrinhaEncomenda){
            carrinha->adicionarEncomenda(n);
        }
    }


    int profit = 0;
    for(auto & carrinha : carrinhas){
        if(carrinha->getBalanco()>0){
            profit +=carrinha->getBalanco();
        }else{
            auto v = carrinha->getEncomendas();
            for(auto & n : *v){
                carrinha->removerEncomenda(n);
            }
        }
    }
    return profit;
}

void Cenario2::prepareSolve() {

    sort(carrinhas.begin(),carrinhas.end(), sortByVarCarrinha);
    sort(encomendas.begin(), encomendas.end(), sortByVarEncomendaRecompensa);

    std::reverse(encomendas.begin(), encomendas.end());
}

ENCOMENDA_VALOR Cenario2::prepareKnapsack(Carrinha &c) {
    vector<Encomenda *> e;
    for(auto & encomenda : encomendas){
        if(!encomenda->getEstado()){
            e.push_back(encomenda);
        }
    }
    if(e.size()<=1){
        ENCOMENDA_VALOR v;
        v.profit = -5;
        return v;
    }
    return solveKnapsack(c,e);
}

double Cenario2::getQuocient() {
    int counter = 0;
    for(auto x : encomendas) {
        if(x->getEstado()) {
            counter++;
        }
    }
    return(counter / (double) encomendas.size());
}

