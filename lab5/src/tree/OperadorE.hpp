#ifndef _OPERADOR_E_HPP_
#define _OPERADOR_E_HPP_
#include "Operador.hpp"

class OperadorE : public Operador
{
	public:
	void debug(int espacos)
	{
		for (int i = 0; i < espacos; i++)
		{
			cout << " ";
		}
		cout << "OP(E)" << endl;
	}
};

#endif
