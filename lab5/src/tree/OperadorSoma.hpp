#ifndef _OPERADOR_SOMA_HPP_
#define _OPERADOR_SOMA_HPP_
#include "Operador.hpp"

class OperadorSoma : public Operador
{
	public:
	void debug(int espacos)
	{
		for (int i = 0; i < espacos; i++)
		{
			cout << " ";
		}
		cout << "OP(SOMA)" << endl;
	}
};

#endif
