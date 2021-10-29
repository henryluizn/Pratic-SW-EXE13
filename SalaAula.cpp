#include "SalaAula.hpp"
#include <iostream>

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
	:nome{nome}, capacidade{capacidade}{
}



SalaAula::~SalaAula()
{
	std::cerr << "\nDestruindo a sala " << this->nome << std::endl;

	std::list<Disciplina *>::iterator it{this->disciplinasMinistradas.begin()};
	for ( ; it != this->disciplinasMinistradas.end(); it++)
	{
		if ((*it)->sala != nullptr)
		{
			// setando a sala da disciplina como nullptr
			(*it)->sala = nullptr;
		}
	}
}


std::string SalaAula::getNome(){
	return nome;
}

void SalaAula::setNome(std::string nome){
	this->nome = nome;
}

unsigned int SalaAula::getCapacidade(){
	return capacidade;
}

void SalaAula::setCapcidade(unsigned int capacidade){
	this->capacidade = capacidade;
}

void SalaAula::adicionarDisciplina(Disciplina* disciplina){
	if (disciplina->sala != nullptr)
	{
		disciplina->sala->disciplinasMinistradas.remove(disciplina);
		this->disciplinasMinistradas.push_back(disciplina);
		disciplina->sala = this;
	}
	else
	{
		this->disciplinasMinistradas.push_back(disciplina);
		disciplina->sala = this;
	}
}


std::list<Disciplina*>& SalaAula::getDisciplinas(){
	return disciplinasMinistradas;
}
