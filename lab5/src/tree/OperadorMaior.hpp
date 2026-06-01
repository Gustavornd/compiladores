#ifndef _OPERADOR_MAIOR_HPP_
#define _OPERADOR_MAIOR_HPP_
#include "Operador.hpp"

class OperadorMaior : public Operador
{
	public:
	void debug(int espacos)
	{
		for (int i = 0; i < espacos; i++)
		{
			cout << " ";
		}
		cout << "OP(MAIOR)" << endl;
	}
};

#endif
