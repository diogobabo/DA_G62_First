#ifndef DA_T6_G62_DPMATRIX_H
#define DA_T6_G62_DPMATRIX_H

#include <iostream>
#include <utility>
#include <vector>

#include "cenarios.h"

using namespace std;
class dpmatrix {
private:
    vector<ENCOMENDA_VALOR> dpMatrix;
    unsigned int m_l;
    unsigned int m_w;
    unsigned int m_h;
public:
    dpmatrix(unsigned int l, unsigned int w, unsigned int h): dpMatrix(l * w * h, ENCOMENDA_VALOR()), m_l(l), m_w(w), m_h(h) {}

    ENCOMENDA_VALOR getPos(unsigned int i, unsigned int j, unsigned int k) {
        return dpMatrix[i*m_w*m_h + j*m_w + k];
    }

    void setPos(unsigned int i, unsigned int j, unsigned int k, ENCOMENDA_VALOR r) {
        dpMatrix[ i*m_w*m_h + j*m_w + k ]=std::move(r);
    }
};




#endif //DA_T6_G62_DPMATRIX_H
