#include "menu.h"
#include "cenarios.h"

#include <iostream>

using namespace std;

Menu::Menu(Empresa *e): e(e) {}

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
                break;
            case 2:
                Cenario2();
                break;
            case 3:
                Cenario3();
                break;
            case 4:
                extras();
            default:
                break;
        }
    }
    return 0;
}

int Menu::extras() {
    return 0;
}

int Menu::Cenario1() {
    class Cenario1 c1(e);
    cout << "." << c1.tentativa();
    return 0;
}

int Menu::Cenario2() {
    class Cenario2 c2(e);
    cout << c2.solveMaxLucro() << endl;
    return 0;
}

int Menu::Cenario3() {
    class Cenario3 c3(e);
    cout << "Average time to deliver " <<  c3.greedyMinAvgTime() << endl;

    int novo_dia = 1;
    return 0;
}