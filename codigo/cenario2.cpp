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

    if (c.getPesoMax() <= 0 || c.getVolMax() <= 0 ||encomendas.empty()) {
        return ev;
    }

    int n = (int)encomendas.size();
    vector<vector<vector<ENCOMENDA_VALOR>>> dp(n, vector<vector<ENCOMENDA_VALOR>>(c.getVolMax(), vector<ENCOMENDA_VALOR>(c.getPesoMax(), ev)));// dp[index][volume][peso]
    //dpmatrix dp(n, c.getVolMax(), c.getPesoMax());

    for (int i = 0; i < n; i++) {
        for(int v = 0; v < c.getVolMax();v++){
            dp[i][v][0].profit = 0;
            /*ENCOMENDA_VALOR p(dp.getPos(i, v, 0));
            p.profit=0;
            dp.setPos(i, v, 0, p);*/
        }
        for(int w = 0; w < c.getPesoMax(); w++){
            dp[i][0][w].profit = 0;
            /*ENCOMENDA_VALOR p(dp.getPos(i, w, 0));
            p.profit=0;
            dp.setPos(i, w, 0, p);*/
        }
    }
    ENCOMENDA_VALOR profit1;
    int cGetVol = (int) c.getVolMax(),cGetPeso = (int)c.getPesoMax();
    for (int i = 1; i < n; i++) {
        if(encomendas[i]->getEstado()) {
            continue;
        }
        int eVol = (int) encomendas[i]->getVol(),ePes = (int)encomendas[i]->getPeso();

        for (int v = 0; v < cGetVol;v++) {
                for(int w = 0; w < cGetPeso; w++){

                if (eVol<=v && ePes<=w) {
                    profit1 = dp[i - 1][v - encomendas[i]->getVol()][w - encomendas[i]->getPeso()];
                    //profit1 = dp.getPos(i-1, v - encomendas[i]->getVol(),w - encomendas[i]->getPeso());
                    profit1.profit = (int) (profit1.profit + encomendas[i]->getRecompensa()) ;
                    profit1.CarrinhaEncomenda.push_back(encomendas[i]);
                }

                dp[i][v][w] = max(profit1, dp[i - 1][v][w],sortStruct);
                //dp.setPos(i, v, w, max(profit1, dp.getPos(i-1, v, w),sortStruct));
            }
        }
    }

    return dp[n - 1][c.getVolMax()-1][c.getPesoMax()-1];
    //return dp.getPos(n-1, c.getVolMax()-1,c.getPesoMax()-1);
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

    auto*e = new Encomenda(0,0,1);
    encomendas.push_back(e);

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

