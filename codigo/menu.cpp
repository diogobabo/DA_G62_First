#include "menu.h"
#include "cenarios.h"
#include <iomanip>
#include <iostream>

using namespace std;

Menu::Menu(Empresa e){
    this->e = e;
}

int Menu::start() {
    int option=-1;

    cout << "Bem vindo, qual dos seguintes cenário pretende explorar de forma a implementar na plataforma digital:\n";
    cout << "1) Cenario 1\n";
    cout << "2) Cenario 2\n";
    cout << "3) Cenario 3\n";
    cout << "4) Extras\n";
    cout << "Insert option (0 to exit):\n";

    while(option) {
        cin >> option;
        switch (option) {
            case 1:
                Cenario1();
                e.removerEncomendas();
                break;
            case 2:
                Cenario2();
                e.removerEncomendas();
                break;
            case 3:
                Cenario3();
                e.removerEncomendas();
                break;
            case 4:
                extras();
            default:
                break;
        }

        e.atualizaCarrinhas();
        string f = e.getFileEncomendas();
        e.novoDia(&f);

    }
    return 0;
}

int Menu::extras() {
    return 0;
}

int Menu::Cenario1() {
    class Cenario1 c1(e);
    cout << c1.tentativa() << endl;
    return 0;
}

int Menu::Cenario2() {
    class Cenario2 c2(e);
    cout << c2.solveMaxLucro() << endl;
    return 0;
}

int Menu::Cenario3() {
    vector<int>avg;
    vector<double>quo;
    class Cenario3 c3(e);
    avg = c3.greedyMinAvgTime();
    quo = c3.getQuocientes();

    int numeroDias = 1;
    for(int i = 0; i <avg.size(); i++) {
        cout << "Dia: " << numeroDias << endl;
        cout << "Tempo Médio: " << avg[i] << endl;
        cout << fixed;
        cout << setprecision(2);
        cout << "Percentagem encomendas entregues: " << (quo[i] * 100) << "%" << std::endl;
        if(i != avg.size() - 1) {
            cout << "--------------------------------------------------" << std::endl;
        }
        numeroDias++;
    }
    return 0;
}
