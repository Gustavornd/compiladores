#ifndef _OPERADOR_IGUAL_HPP_
#define _OPERADOR_IGUAL_HPP_
#include "Operador.hpp"

class OperadorIgual : public Operador
{
	public:
	void debug(int espacos)
	{
		for (int i = 0; i < espacos; i++)
		{
			cout << " ";
		}

		cout << "OP(IGUAL)" << endl;
	}
};

#endif
