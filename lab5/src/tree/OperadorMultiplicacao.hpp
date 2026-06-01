#ifndef _OPERADOR_MULTIPLICACAO_HPP_
#define _OPERADOR_MULTIPLICACAO_HPP_
#include "Operador.hpp"

class OperadorMultiplicacao : public Operador
{
	public:
	void debug(int espacos)
	{
		for (int i = 0; i < espacos; i++)
		{
			cout << " ";
		}
		cout << "OP(MUL)" << endl;
	}
};

#endif
