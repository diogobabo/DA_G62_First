#ifndef DA_T4_G62_EMPRESA_H
#define DA_T4_G62_EMPRESA_H

#include <string>

class Empresa {
private:
    std::string oi;

public:
    /**
     * Constructor
     */
    Empresa();

    /**
     * Constructor
     */
    void lerCarrinhas(std::string fileName);
    void lerEncomendas(std::string fileName);
};


#endif //DA_T4_G62_EMPRESA_H
