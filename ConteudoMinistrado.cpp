#include "ConteudoMinistrado.hpp"
#include <iostream>
// inicialização do dado static
unsigned int ConteudoMinistrado::proxId{0};

ConteudoMinistrado::~ConteudoMinistrado()
{
	std::cerr << "\nDestruindo o conteudo ministrado " << this->descricao << std::endl;
}

ConteudoMinistrado::ConteudoMinistrado(std::string descricao, unsigned short cargaHorariaConteudo):
	descricao(descricao), cargaHorariaConteudo(cargaHorariaConteudo), id{ConteudoMinistrado::proxId}
{
	ConteudoMinistrado::proxId++;
}

std::string& ConteudoMinistrado::getDescricao(){
	return descricao;
}

unsigned short ConteudoMinistrado::getCargaHorariaConteudo(){
	return cargaHorariaConteudo;
}

unsigned int ConteudoMinistrado::getId(){
	return id;
}
