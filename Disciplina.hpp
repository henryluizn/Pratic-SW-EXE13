#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <list>

#include "Pessoa.hpp"
class SalaAula;//forward declaration
class ConteudoMinistrado;

class Disciplina{
	friend class SalaAula;
	public:
		Disciplina(std::string nome, SalaAula* sala);
		~Disciplina();

		std::string getNome();
		void setNome(std::string nome);
		
		int getCargaHoraria();
		void setCargaHoraria(unsigned int cargaHoraria);
		
		Pessoa* getProfessor();
		void setProfessor(Pessoa* professor);

		void adicionarAluno(Pessoa* aluno);
		void removerAluno(Pessoa* aluno);
		void removerAluno(unsigned long cpf);
		std::list<Pessoa*>& getAlunos();

		void setSalaAula(SalaAula* sala);
		SalaAula* getSalaAula();

		void imprimeDados(std::string& cabecalho, unsigned int& cargaTotalCurso);

		// novas implementacoes

		void adicionarConteudoMinistrado(std::string conteudo, unsigned short cargaHorariaConteudo);
		void imprimirConteudosMinistrados();
		std::list<ConteudoMinistrado*> getConteudos();
		void limparConteudos();
		void removerConteudoMinistrado(unsigned long id);

	private:
		std::string nome;
		unsigned short int cargaHoraria;

		Pessoa* professor;
		SalaAula* sala;
		std::list<Pessoa*> alunos;
		// novas implementacoes
		std::list<ConteudoMinistrado*> conteudos;

};
#endif
