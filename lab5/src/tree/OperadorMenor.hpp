#ifndef _OPERADOR_MENOR_HPP_
#define _OPERADOR_MENOR_HPP_
#include "Operador.hpp"

class OperadorMenor : public Operador
{
	public:
	void debug(int espacos)
	{
		for (int i = 0; i < espacos; i++)
		{
			cout << " ";
		}
		cout << "OP(MENOR)" << endl;
	}
};

#endif
