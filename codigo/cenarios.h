#ifndef DA_T6_G62_CENARIOS_H
#define DA_T6_G62_CENARIOS_H

#include <iostream>
#include <vector>
#include "encomenda.h"
#include "carrinha.h"
#include "Empresa.h"

class Cenario1 {
    /*
     * a soluçao do senario 1 vai ser usar Top-down Dynamic Programming with Memoization ou seja vamos usar uma soluçao recursiva
     * que vai contruir uma tabela e cima para baixo cujo o tempo de execuçao é igual a uma soluçao Bottom-up Dynamic Programming
     * a catch é que normalmente essas tabelas sao de 2 entradas. Nesta soluçao nos iremos ter que trabalhar inicialmente com uma soluçao
     * de uma tabela de 3 entradas para compensar o facto de termos 2 constraints e mais tarde de 4 entradas para ter em conta as diferentes carrinhas
     */
private:
    std::vector<Encomenda *> encomendas;
    std::vector<Carrinha *> carrinhas;

    //estas funçoes sao modelos da soluçao para 1 constraint e serao base para o nosso modelo. Vao mudar de nome e argumentos para adaptar ao nosso problema
    int knapsackRecursive(std::vector<std::vector<int>> &dp, const std::vector<int> &profits,const std::vector<int> &weights, int capacity, int currentIndex);
public:
    /**
     * Constructor
     * Montar os argumentos nessecarios para o funcionamento do cenario 1
     */
    Cenario1();

    //estas funçoes sao modelos da soluçao para 1 constraint e serao base para o nosso modelo. Vao mudar de nome e argumentos para adaptar ao nosso problema
    int solveKnapsack(const std::vector<int> &profits, const std::vector<int> &weights, int capacity);
};

class Cenario2 {
private:
public:
};

class Cenario3 {
private:
public:
};

#endif //DA_T6_G62_CENARIOS_H
