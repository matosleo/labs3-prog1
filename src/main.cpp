#include <iostream>
#include "loja.h"


int main(int argc, char const *argv[])
{
	Loja lista;
	
	lista.removeProduto("001002003-45");
	lista.lerFrutas();
	lista.lerBebidas();
	lista.lerRoupas();
	lista.listarProdutos();
	lista.removeProduto("001002003-45");
	lista.listarProdutos();

	

	return 0;
}