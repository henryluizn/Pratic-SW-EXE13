#include "Disciplina.hpp"
#include "SalaAula.hpp"
#include "ConteudoMinistrado.hpp"

#include <iostream>

Disciplina::Disciplina(std::string nome, SalaAula *sala)
	: nome{nome}, sala{sala}
{
}

Disciplina::~Disciplina()
{
	this->setSalaAula(nullptr);
	std::list<ConteudoMinistrado *>::iterator it;
	for (it = conteudos.begin(); it != conteudos.end(); it++)
		delete *it; //liberando a memória de cada conteúdo
}

void Disciplina::adicionarAluno(Pessoa *aluno)
{
	this->alunos.push_back(aluno);
}

void Disciplina::removerAluno(Pessoa *aluno)
{
	this->alunos.remove(aluno);
}

void Disciplina::removerAluno(unsigned long cpf)
{
	std::list<Pessoa *>::iterator it;

	for (it = this->alunos.begin(); it != this->alunos.end(); it++)
		if ((*it)->getCpf() == cpf)
			break;
	if (it != this->alunos.end())
		alunos.erase(it);
}

std::list<Pessoa *> &Disciplina::getAlunos()
{ //retornamos uma referência para a lista, o que custa mais barato
	return alunos;
}

std::string Disciplina::getNome()
{
	return this->nome;
}

void Disciplina::setNome(std::string nome)
{
	this->nome = nome;
}

int Disciplina::getCargaHoraria()
{
	return this->cargaHoraria;
}

void Disciplina::setCargaHoraria(unsigned int cargaHoraria)
{
	this->cargaHoraria = cargaHoraria;
}

Pessoa *Disciplina::getProfessor()
{
	return this->professor;
}

void Disciplina::setProfessor(Pessoa *professor)
{
	this->professor = professor;
}

void Disciplina::setSalaAula(SalaAula *sala)
{
	if (this->sala != nullptr)
	{
		this->sala->disciplinasMinistradas.remove(this);
	}
	this->sala = sala;
	if (this->sala != nullptr)
	{
		sala->disciplinasMinistradas.push_back(this);
	}
}

SalaAula *Disciplina::getSalaAula()
{
	return this->sala;
}
void Disciplina::imprimeDados(std::string &cabecalho, unsigned int &cargaTotalCurso)
{
	double pctCurso = (double)cargaHoraria / cargaTotalCurso;
	pctCurso = pctCurso * 100;
	std::cout << cabecalho << std::endl;
	std::cout << "Disciplina: " << this->nome << std::endl;
	std::cout << "Carga: " << this->cargaHoraria << std::endl;
	std::cout << "Percentagem do curso: " << pctCurso << "%" << std::endl;
	std::cout << "Professor: " << this->professor->getNome() << std::endl;
}

// novas implementacoes

void Disciplina::adicionarConteudoMinistrado(std::string conteudo, unsigned short cargaHorariaConteudo)
{
	this->conteudos.push_back(new ConteudoMinistrado{conteudo, cargaHorariaConteudo});
}

void Disciplina::imprimirConteudosMinistrados()
{
	std::list<ConteudoMinistrado *>::iterator it;
	for (it = this->conteudos.begin(); it != this->conteudos.end(); it++)
	{
		std::cout << "Id: " << (*it)->getId() << std::endl
				  << "Conteudo: " << (*it)->getDescricao() << std::endl
				  << "Carga: " << (*it)->getCargaHorariaConteudo() << std::endl
				  << std::endl;
	}
}

std::list<ConteudoMinistrado *> Disciplina::getConteudos()
{
	return this->conteudos;
}

void Disciplina::limparConteudos()
{
	std::list<ConteudoMinistrado *>::iterator it{this->conteudos.begin()};
	while (it != this->conteudos.end())
	{
		if ((*it) != nullptr)
		{
			delete *it;
			it = this->conteudos.erase(it);
			std::cout << "\nConteudo removido com sucesso" << std::endl;
		}
		else
		{
			it++;
		}
	}
	delete[] & this->conteudos;
}

void Disciplina::removerConteudoMinistrado(unsigned long id)
{
	std::list<ConteudoMinistrado *>::iterator it;
	for (it = this->conteudos.begin(); it != this->conteudos.end(); it++)
	{
		if ((*it)->getId() == id)
		{
			std::cout << "\nRemovendo conteúdo " << (*it)->getDescricao() << "\n"
					  << std::endl;
			this->conteudos.remove((*it));
			break;
		}
	}
}