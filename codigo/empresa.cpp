#include "empresa.h"
#include <iostream>
#include <fstream>
#include <sstream>


Empresa::Empresa(string fileEncomendas, string fileCarrinhas) {
    lerCarrinhas(&fileCarrinhas);
    novoDia(&fileEncomendas);
}

void Empresa::lerEncomendas(std::string *fileName) {
    string s,tempo;
    string vol,peso,recompensa;
    ifstream file;
    file.open(*fileName);
    getline(file,s);
    while(getline(file,s)) {
        std::stringstream str(s);
        getline(str,vol,' ');
        getline(str,peso,' ');
        getline(str,recompensa,' ');
        getline(str,tempo,' ');
        auto *encomenda = new Encomenda(stoi(vol),stoi(peso),stoi(recompensa));
        auto *expEncomenda = new ExpressoEncomenda(stoi(vol),stoi(peso),stoi(recompensa), stoi(tempo));
        encomendas.push_back(encomenda);
        expEncomendas.push_back(expEncomenda);
    }
}

void Empresa::lerCarrinhas(std::string *fileName) {
    string s,tempo;
    string volMax,pesoMax,custo;
    ifstream file;
    file.open(*fileName);
    getline(file,s);
    while(getline(file,s)) {
        std::stringstream str(s);
        getline(str,volMax,' ');
        getline(str,pesoMax,' ');
        getline(str,custo,' ');
        auto *carrinha = new Carrinha(stoi(volMax), stoi(pesoMax), stoi(custo));
        carrinhas.push_back(carrinha);
    }
}

void Empresa::novoDia(std::string *fileEncomendas) {
    for(auto itr=carrinhas.begin(); itr!=carrinhas.end();itr++){
        (*itr)->clearEncomendas();
    }

    for(auto itr= encomendas.begin(); itr!=encomendas.end();) {
        auto temp = itr;
        itr++;
        if((*temp)->getEstado()) encomendas.erase(temp); // se foi entregue, remove do vetor
        else (*temp)->setPrioridade(true); // se não foi entregue no dia anterior, muda prioridade para elevada
    }
    lerEncomendas(fileEncomendas); // ler encomendas para novo dia
    // novos pesos variaveis
    pesoVol=0;
    pesoPeso=0;
    balancaVars();
    for(auto &encomenda: encomendas) {
        encomenda->setVarDecisiva(pesoPeso, pesoVol);
    }
    for(auto &carrinha: carrinhas) {
        carrinha->setVarDecisiva(pesoPeso, pesoVol);
    }
}

void Empresa::balancaVars() {
    unsigned int totalPeso=0, totalVol=0;
    for(auto & encomenda : encomendas) {
        totalPeso+=encomenda->getPeso();
        totalVol+=encomenda->getVol();
    }
    auto totalVar= (float) (totalVol+totalPeso);
    pesoPeso =  (float) totalPeso / totalVar;
    pesoVol = (float) totalVol / totalVar;
}

void Empresa::removerEntregues() {
    for(auto itr= encomendas.begin(); itr!=encomendas.end();) {
        auto temp = itr;
        itr++;
        if((*temp)->getEstado()) encomendas.erase(temp); // se foi entregue, remove do vetor
    }
}

void Empresa::removerEncomendas() {
    for(auto itr=encomendas.begin(); itr!=encomendas.end(); itr++)
        delete *itr;
}
