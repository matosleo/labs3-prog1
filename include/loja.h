#ifndef LOJA_H
#define LOJA_H

#include "produto.h"
#include "fruta.h"
#include "roupa.h"
#include "bebida.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>

using namespace std;

class Loja
{
private:
    std::vector<shared_ptr<Produto>> lista;
    
public:
    Loja();
    ~Loja();
    void addProduto(shared_ptr<Produto> produto);
    void removeProduto(std::string cod_barra);
    void listarProdutos();
    void lerFrutas();
    void lerBebidas();
    void lerRoupas();
};

#endif