#include <iostream>
#include "empresa.h"
#include "menu.h"

int main() {
    Empresa empresa("../input/encomendasExp.txt", "../input/carrinhas.txt");

    Menu menu(&empresa);
    menu.start();
    return 0;
}


