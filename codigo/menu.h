#ifndef DA_T6_G62_MENU_H
#define DA_T6_G62_MENU_H

#include "empresa.h"

class Menu {
private:
    Empresa *e;
public:
    /**
     * Menu construtor
     * @param e Empresa a estudar
     */
    explicit Menu(Empresa *e);

    /**
     * Mostrar Menu
     * @return 0 quando acabar
     */
    int start();

    /**
     * Menu de extras
     * @return
     */
    int extras();

    /**
     *
     * @return
     */
    int Cenario1();

    /**
     *
     * @return
     */
    int Cenario2();

    /**
     *
     * @return
     */
    int Cenario3();

};


#endif //DA_T6_G62_MENU_H
