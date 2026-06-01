#ifndef _OPERADOR_DIVISAO_HPP_
#define _OPERADOR_DIVISAO_HPP_
#include "Operador.hpp"

class OperadorDivisao : public Operador
{
	public:
	void debug(int espacos)
	{
		for (int i = 0; i < espacos; i++)
		{
			cout << " ";
		}
		cout << "OP(DIV)" << endl;
	}
};

#endif
