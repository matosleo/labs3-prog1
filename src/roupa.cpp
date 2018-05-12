#include <iomanip>
#include "roupa.h"

Roupa::Roupa() {}

Roupa::Roupa(std::string _codigo, std::string _descricao, short _preco, 
	std::string _data, std::string _tamanho):
	Produto(_codigo, _descricao, _preco), m_data_lote(_data), m_tamanho(_tamanho) {}

Roupa::~Roupa() {}

std::string 
Roupa::getDataLote() {
	return m_data_lote;
}

std::string
Roupa::getTamanho() {
	return m_tamanho;
}

void 
Roupa::setDataLote(std::string _data) {
	m_data_lote = _data;
}

void
Roupa::setTamanho(std::string _tamanho) {
	m_tamanho = _tamanho;
}

 
std::ostream& 
Roupa::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << m_data_lote << " | " 
		<< std::setfill (' ') << std::setw (3) << m_tamanho;
	return o;
}