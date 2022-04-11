#ifndef DA_T6_G62_CENARIOS_H
#define DA_T6_G62_CENARIOS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "encomenda.h"
#include "carrinha.h"
#include "empresa.h"


struct ENCOMENDA_VALOR{
    int profit = -1;
    std::vector<Encomenda *> CarrinhaEncomneda;
};

    /**
     * A soluçao do senario 1 vai ser usar Top-down Dynamic Programming with Memoization ou seja vamos usar uma soluçao recursiva
     * que vai contruir uma tabela e cima para baixo cujo o tempo de execuçao é igual a uma soluçao Bottom-up Dynamic Programming
     * a catch é que normalmente essas tabelas sao de 2 entradas. Nesta soluçao nos iremos ter que trabalhar inicialmente com uma soluçao
     * de uma tabela de 3 entradas para compensar o facto de termos 2 constraints e mais tarde de 4 entradas para ter em conta as diferentes carrinhas
     */
class Cenario1 {
private:
    std::vector<Encomenda *> encomendas;
    std::vector<Carrinha *> carrinhas;
    /** Estas funçoes sao modelos da soluçao para 1 constraint e serao base para o nosso modelo. Vao mudar de nome e argumentos para adaptar ao nosso problema */
    int knapsackRecursive(std::vector<std::vector<int>> &dp, const std::vector<int> &profits,const std::vector<int> &weights, int capacity, int currentIndex);
public:
    /**
     * Constructor Montar argumentos necessarios para o funcionamento do cenario 1
     * @param e Empresa a ser estudada
     */
    explicit Cenario1(Empresa *e);

    /** Estas funçoes sao modelos da soluçao para 1 constraint e serao base para o nosso modelo. Vao mudar de nome e argumentos para adaptar ao nosso problema */
    int solveKnapsack(const std::vector<int> &profits, const std::vector<int> &weights, int capacity);

    /**
     * Função para ordenar por volume
     * @param e1 encomenda 1
     * @param e2 encomenda 2
     * @return
     */
    static bool sortByVolume(const Encomenda* e1, const Encomenda* e2);

    /**
     * Função para ordenar por peso
     * @param e1 encomenda 1
     * @param e2 encomenda 2
     * @return
     */
    static bool sortByPeso(const Encomenda* e1, const Encomenda* e2);

    /**
     * Função responsável pelo job scheduling
     * @return tempo medio
     */
    int tentativa();

    /**
     * Função responsável pelo job scheduling
     * @return tempo medio
     */
    int bestFit();

    /**
     * Função para ordenar pela variavel decisiva
     * @param e1 encomenda 1
     * @param e2 encomenda 2
     * @return
     */
    static bool sortByVarEncomenda(const Encomenda* e1, const Encomenda* e2);

    /**
     * Função para ordenar pela variavel decisiva
     * @param c1 encomenda 1
     * @param c2 encomenda 2
     * @return
     */
    static bool sortByVarCarrinha(const Carrinha* c1, const Carrinha* c2);
};

class Cenario2 {
private:
    std::vector<Encomenda *> encomendas;
    std::vector<Carrinha *> carrinhas;
public:
    /**
     * Constructor Montar argumentos necessarios para o funcionamento do cenario 2
     * @param e Empresa a ser estudada
     */
    explicit Cenario2(Empresa *e);
    int solveMaxLucro();
    int solveKnapsack(Carrinha &c);
    /**
     * Função para ordenar por recompensa
     * @param e1 encomenda 1
     * @param e2 encomenda 2
     * @return
     */
    static bool sortByRecompensa(const Encomenda* e1, const Encomenda* e2);

    /**
     * Função para ordenar pela variavel decisiva
     * @param e1 encomenda 1
     * @param e2 encomenda 2
     * @return
     */
    static bool sortByVarEncomendaRecompensa(const Encomenda* e1, const Encomenda* e2);

    /**
     * Função para ordenar pela variavel decisiva
     * @param c1 encomenda 1
     * @param c2 encomenda 2
     * @return
     */
    static bool sortByVarCarrinha(const Carrinha* c1, const Carrinha* c2);

    /**
     * Função para ordenar a struct
     * @param c1 encomenda_valor 1
     * @param c2 encomenda_valor 2
     * @return
     */
    static bool sortStruct(const ENCOMENDA_VALOR &e1, const ENCOMENDA_VALOR &e2);
};

class Cenario3 {
private:
    std::vector<ExpressoEncomenda *> encomendasExp;
public:

    /**
     * Constructor Montar argumentos necessarios para o funcionamento do cenario 3
     * @param e Empresa a ser estudada
     */
    explicit Cenario3(Empresa *e);

    /**
     * Função para ordenar por duração
     * @param e1 encomenda 1
     * @param e2 encomenda 2
     * @return
     */
    static bool sortByDuracao(const ExpressoEncomenda* e1, const ExpressoEncomenda* e2);

    /**
     * Função responsável por minimizar o tempo das entregas expresso
     * @return o tempo medio minimizado
     */
    int greedyMinAvgTime();
};

#endif //DA_T6_G62_CENARIOS_H
