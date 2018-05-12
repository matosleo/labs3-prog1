#ifndef ROUPA_H
#define ROUPA_H

#include "produto.h"

class Roupa : public Produto
{
public:
	Roupa();
	Roupa(std::string _codigo, std::string _descricao, short _preco, 
			std::string _data, std::string _tamanho);
	~Roupa();
private:
	std::string m_data_lote;
	std::string m_tamanho;
public:
	// getters
	std::string getDataLote();
	std::string getTamanho();
	// setters
	void setDataLote(std::string _data);
	void setTamanho(std::string _tamanho);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif