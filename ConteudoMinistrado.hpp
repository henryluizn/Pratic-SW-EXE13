#ifndef CONTEUDO_MINISTRADO_HPP
#define CONTEUDO_MINISTRADO_HPP

#include<string>

class ConteudoMinistrado{
	public:
		ConteudoMinistrado(std::string descricao, unsigned short cargaHorariaConteudo);
		~ConteudoMinistrado();

		std::string& getDescricao();
		unsigned short getCargaHorariaConteudo();
		unsigned int getId();
	private:
		std::string descricao;
		unsigned short cargaHorariaConteudo;
		unsigned int id;
		static unsigned int proxId;
};
#endif
