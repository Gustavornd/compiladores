#ifndef _OPERADOR_OU_HPP_
#define _OPERADOR_OU_HPP_
#include "Operador.hpp"

class OperadorOU : public Operador
{
	public:
	void debug(int espacos)
	{
		for (int i = 0; i < espacos; i++)
		{
			cout << " ";
		}
		cout << "OP(OU)" << endl;
	}
};

#endif
