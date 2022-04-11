#include "menu.h"
#include "cenarios.h"

#include <iostream>

using namespace std;

Menu::Menu(Empresa *e): e(e) {}

int Menu::start() {
    int option=0;

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
                break;
            case 2:
                break;
            case 3:
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

