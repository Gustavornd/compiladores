#ifndef _OPERADOR_SUBTRACAO_HPP_
#define _OPERADOR_SUBTRACAO_HPP_
#include "Operador.hpp"

class OperadorSubtracao : public Operador
{
	public:
	void debug(int espacos)
	{
		for (int i = 0; i < espacos; i++)
		{
			cout << " ";
		}
		cout << "OP(SUB)" << endl;
	}
};

#endif
