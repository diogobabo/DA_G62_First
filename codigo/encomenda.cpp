#include "encomenda.h"

Encomenda::Encomenda(unsigned int vol, unsigned int peso, unsigned int recompensa): vol(vol),peso(peso),recompensa(recompensa)
{}

ExpressoEncomenda::ExpressoEncomenda(unsigned int vol, unsigned int peso, unsigned int recompensa, unsigned int duracao): Encomenda(vol, peso, recompensa), duracao(duracao)
{}

NormalEncomenda::NormalEncomenda(unsigned int vol, unsigned int peso, unsigned int recompensa): Encomenda(vol, peso, recompensa)
{}
