#ifndef BEBIDA_H
#define BEBIDA_H

#include "produto.h"

class Bebida : public Produto
{
public:
	Bebida();
	Bebida(std::string _codigo, std::string _descricao, short _preco, 
			std::string _data, float m_teorAlcolico);
	~Bebida();
private:
	std::string m_data_lote;
	float m_teorAlcolico;
public:
	// getters
	std::string getDataLote();
	float getTeor();
	// setters
	void setDataLote(std::string _data);
	void setTeor(float _teorAlcolico);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif