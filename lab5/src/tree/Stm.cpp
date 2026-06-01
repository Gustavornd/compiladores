#include "Stm.hpp"
#include "../arvore/Comando.hpp"
#include "../frame/FrameFuncao.hpp"
Stm *Stm::converte_comando_para_ri(Comando *comando, FrameFuncao *frame)
{
	Stm *stm = comando->cria_ri(frame);

	return stm;
}
