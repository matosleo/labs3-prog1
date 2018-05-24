#include "loja.h"

Loja::Loja() {}

Loja::~Loja() {}

void 
Loja::addProduto(shared_ptr<Produto> produto)
{
    bool existe = false;
    if(lista.size() != 0)
    {
        for(auto i = lista.begin(); i != lista.end(); i++)
        {
            if(**i == *produto)
            {
                cerr << "ERRO! Este produto ja existe" << endl;
                existe = true;
            }
        }
    }
    
    if(!existe)
    {
        lista.push_back(produto);
    }
}

void 
Loja::removeProduto(string cod_barra)
{
    if(lista.size() != 0)
    {
        for(auto i = lista.begin(); i != lista.end(); i++)
        {
            if((**i).getCodBarras().compare(cod_barra) == 0)
            {
                lista.erase(i);
                cout << "Produto removido com sucesso" << endl;
            }
        }
    }
    else
    {
        cerr << "ERRO! Lista vazia. Impossivel realizar esta operacao" << endl;
    }
}

void
Loja::listarProdutos()
{
    if(lista.size() != 0)
    {
        for(auto i = lista.begin(); i != lista.end(); i++)
        {
            cout << **i << endl;
        }
    }
    else
    {
        cout << "ERRO! Nao foi possivel exibir os produtos" << endl;    
    }
}

void 
Loja::lerFrutas()
{
    ifstream frutas;
    frutas.open("data/frutas.dat");
    if(frutas.bad())
    {
        cerr << "ERRO! Nao foi possivel abrir o arquivo" << endl;
        exit(EXIT_FAILURE);
    }
    string linha;
    while(getline(frutas, linha))
    {
        stringstream aux(linha);
        string cod_barra, descricao, preco, data_lote, vencimento;
        
        getline(aux, cod_barra, ',');
        getline(aux, descricao, ',');
        getline(aux, preco, ',');
        getline(aux, data_lote,',');
        getline(aux, vencimento, ';');
        
        addProduto(make_shared<Fruta>(cod_barra, descricao, stod(preco), data_lote, stoi(vencimento)));
    }
}

void 
Loja::lerBebidas()
{
    ifstream bebidas;
    bebidas.open("data/bebidas.dat");
    if(bebidas.bad())
    {
        cerr << "ERRO! Nao foi possivel abrir o arquivo" << endl;
        exit(EXIT_FAILURE);
    }
    string linha;
    while(getline(bebidas, linha))
    {
        stringstream aux(linha);
        string cod_barra, descricao, preco, teor_alcoolico;
        
        getline(aux, cod_barra, ',');
        getline(aux, descricao, ',');
        getline(aux, preco, ',');
        getline(aux, teor_alcoolico, ';');
        
        addProduto(make_shared<Bebida>(cod_barra, descricao, stod(preco), stod(teor_alcoolico)));
    }
}

void 
Loja::lerRoupas()
{
    ifstream roupas;
    roupas.open("data/roupas.dat");
    if(roupas.bad())
    {
        cerr << "ERRO! Nao foi possivel abrir o arquivo" << endl;
        exit(EXIT_FAILURE);
    }
    
    string linha;
    while(getline(roupas, linha))
    {
        stringstream aux(linha);
        string cod_barra, descricao, preco, marca, sexo, tamanho;
        
        getline(aux, cod_barra, ',');
        getline(aux, descricao, ',');
        getline(aux, preco, ',');
        getline(aux, marca, ',');
        getline(aux, sexo, ',');
        getline(aux, tamanho, ';');
        
        addProduto(make_shared<Roupa>(cod_barra, descricao, stod(preco), marca, sexo, tamanho));
    }
}