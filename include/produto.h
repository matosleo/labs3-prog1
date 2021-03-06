#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>

class Produto
{
public:
	Produto();
	Produto(std::string _codigo, std::string _descricao, short _preco);
	virtual ~Produto();
protected:
	std::string m_cod_barras;
	std::string m_descricao;
	double m_preco;		
public:
	// getters
	std::string getCodBarras();
	std::string getDescricao();
	double getPreco();
	// setters
	void setCodBarras(std::string _codigo);
	void setDescricao(std::string _descricao);
	void setPreco(double _preco);
	
	friend std::ostream& operator<< (std::ostream &o, Produto const &t);
	double operator+(Produto &produto);
	double operator-(Produto &produto);
	bool operator==(Produto &produto);

private:
	virtual std::ostream& print(std::ostream&) const = 0;
};
 
#endif
