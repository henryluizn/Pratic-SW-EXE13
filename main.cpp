#include <iostream>
#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "ConteudoMinistrado.hpp"
#include "Console.hpp"
#include "SalaAula.hpp"

int main()
{

	Disciplina *dis1{new Disciplina{"C++", nullptr}};
	Disciplina *dis2{new Disciplina{"Java", nullptr}};
	SalaAula sala{"Lab Info 1", 40};
	Pessoa* prof{new Pessoa{"Joao"}};
	dis1->setProfessor(prof);

	dis1->setSalaAula(&sala);
	dis2->setSalaAula(&sala);
	
	std::list<Disciplina *> disSala = sala.getDisciplinas();
	std::list<Disciplina *>::iterator it;
	std::cout << "\nDisciplinas adicionadas: " << std::endl;
	for (it = disSala.begin(); it != disSala.end(); it++)
		std::cout << "\t - " << (*it)->getNome() << std::endl;
	
	delete dis2;
	delete dis1;
	delete prof;
	
	std::cout << "\nFim do Programa" << std::endl;
	return 0;
}