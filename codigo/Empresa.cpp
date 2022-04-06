#include "Empresa.h"
#include <iostream>
#include <fstream>
#include <sstream>




Empresa::Empresa() {

}

Empresa::Empresa(string fileEncomendas, string fileCarrinhas) {
    lerEncomendas(fileEncomendas);
    lerCarrinhas(fileCarrinhas);
}

void Empresa::lerEncomendas(std::string fileName) {
    string s,tempo;
    string vol,peso,recompensa;
    ifstream file;
    file.open(fileName);
    getline(file,s);
    while(getline(file,s)) {
        std::stringstream str(s);
        getline(str,vol,' ');
        getline(str,peso,' ');
        getline(str,recompensa,' ');
        getline(str,tempo,' ');
        Encomenda encomenda(stoi(vol),stoi(peso),stoi(recompensa));
        encomendas.push_back(&encomenda);
    }
}

void Empresa::lerCarrinhas(std::string fileName) {
    string s,tempo;
    string volMax,pesoMax,custo;
    ifstream file;
    file.open(fileName);
    getline(file,s);
    while(getline(file,s)) {
        std::stringstream str(s);
        getline(str,volMax,' ');
        getline(str,pesoMax,' ');
        getline(str,custo,' ');
        Carrinha carrinha(stoi(volMax), stoi(pesoMax), stoi(custo));
        carrinhas.push_back(&carrinha);
    }
}
