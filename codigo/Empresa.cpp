//
// Created by oliveira on 06/04/22.
//

#include "Empresa.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

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
        cout << vol << endl;
        cout << peso << endl;
        cout << recompensa << endl;
        cout << tempo << endl;
    }
}

Empresa::Empresa() {

}
