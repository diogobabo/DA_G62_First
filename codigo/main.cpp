#include <iostream>
#include "empresa.h"
#include "menu.h"

int main() {
    Empresa empresa("../input/encomendasC3.txt", "../input/carrinhasC3.txt");
    Menu menu(empresa);
    menu.start();
    return 0;
}
