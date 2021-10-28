#include <iostream>
#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "ConteudoMinistrado.hpp"
#include "Console.hpp"
#include "SalaAula.hpp"

int main()
{

	Disciplina dis1{"C++", nullptr};
	Disciplina *dis2{new Disciplina{"Java", nullptr}};
	SalaAula sala{"Lab Info 1", 40};
	
	dis1.setSalaAula(&sala);
	dis2->setSalaAula(&sala);
	
	std::list<Disciplina *> disSala = sala.getDisciplinas();
	std::list<Disciplina *>::iterator it;
	
	for (it = disSala.begin(); it != disSala.end(); it++)
		std::cout << (*it)->getNome() << std::endl;
	delete dis2;
	
	std::cout << "Fim do Programa" << std::endl;
	return 0;

	//------------------ main antigo ------------------------

	// 	unsigned short int id{1};
	// 	Pessoa prof1{"João", 40};
	// 	Pessoa prof2{"Marcela", 40};

	// 	Disciplina dis1{"C++", nullptr};
	// 	Disciplina dis2{"Segurança", nullptr};

	// 	dis1.setProfessor(&prof1);
	// 	dis2.setProfessor(&prof2);

	// // adicionando conteudos nas disciplinas e imprimindo os dados
	// 	std::cout << "\n---------------Adicionando conteudos nas disciplinas e imprimindo os dados---------------\n" << std::endl;
	// 	dis1.adicionarConteudoMinistrado("Ponteiros", 4);
	// 	dis1.adicionarConteudoMinistrado("Referencias", 2);
	// 	dis2.adicionarConteudoMinistrado("DDoS", 3);
	// 	dis2.adicionarConteudoMinistrado("Pentest", 5);
	// 	Console::imprimirDadosDisciplina(dis1);
	// 	Console::imprimirDadosDisciplina(dis2);

	// // removendo um conteudo de uma disciplina

	// 	std::cout << "\n---------------Removendo o conteudo de " << dis1.getNome() << " com o ID - " << id << "---------------\n" << std::endl;
	// 	dis1.removerConteudoMinistrado(id);
	// 	Console::imprimirDadosDisciplina(dis1);

	// // limpando conteudos das disciplinas
	// 	std::cout << "\n---------------Limpando conteudos das disciplinas---------------\n" << std::endl;
	// 	dis1.limparConteudos();
	// 	dis2.limparConteudos();

	// 	std::cout << "\n---------------Imprimindo as disciplinas:---------------\n" << std::endl;
	// 	Console::imprimirDadosDisciplina(dis1);
	// 	Console::imprimirDadosDisciplina(dis2);
	// 	return 0;
}