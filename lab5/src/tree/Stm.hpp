#ifndef _STM_HPP_
#define _STM_HPP_

#include <iostream>
class FrameFuncao;
class Comando;

using namespace std;
class Stm
{
	public:
	static Stm *converte_comando_para_ri(Comando *comando, FrameFuncao *frame);
	virtual void debug(int espacos)
	{
		cout << "Debug não implementado stm" << endl;
	}
};

#endif
