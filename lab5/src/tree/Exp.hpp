#ifndef _EXP_HPP_
#define _EXP_HPP_

class Expressao;
#include <iostream>
using namespace std;
class Exp
{
	public:
	Exp()
	{
	}
	static Exp *gera_Exp_de_Expressao(Expressao *e);
	virtual void debug(int espacos)
	{
		cout << "Não implementado" << endl;
	}
};

#endif
