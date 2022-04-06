
class Encomenda {
private:
    unsigned int vol;
    unsigned int peso;
    unsigned int recompensa;
public:
    /**
     * Encomenda
     * @param recompensa recompensa da encomenda
     */
    explicit Encomenda(unsigned int vol, unsigned int peso, unsigned int recompensa);

    /**
     * Desconstrutor do objeto Encomenda
     */
    virtual ~Encomenda() = default;
};

class ExpressoEncomenda: public Encomenda {
private:
    unsigned int duracao;
public:
    /**
     * Encomenda do tipo expresso
     * @param recompensa recompensa da encomenda
     * @param duracao duracao da encomenda ( viagem de ida e volta )
     */
    ExpressoEncomenda(unsigned int vol, unsigned int peso, unsigned int recompensa, unsigned int duracao);
};

class NormalEncomenda: public Encomenda {
private:
public:
    /**
     * Encomenda do tipo normal
     * @param vol volume da encomenda
     * @param peso peso da encomenda
     * @param recompensa recompensa da encomenda
     */
    NormalEncomenda(unsigned int vol, unsigned int peso, unsigned int recompensa);
};
