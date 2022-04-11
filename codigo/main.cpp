#include <iostream>
#include "empresa.h"
#include "menu.h"

int main() {
    Empresa empresa("../input/encomendasC2.txt", "../input/carrinhasC2.txt");

    Menu menu(&empresa);
    menu.start();
    return 0;
}
