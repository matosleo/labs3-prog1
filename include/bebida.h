#ifndef BEBIDA_H
#define BEBIDA_H

#include "produto.h"

class Bebida : public Produto
{
public:
	Bebida();
	Bebida(std::string _codigo, std::string _descricao, short _preco, 
		float m_teorAlcolico);
	~Bebida();
private:
	float m_teorAlcolico;
public:
	// getters
	float getTeor();
	// setters
	void setTeor(float _teorAlcolico);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif