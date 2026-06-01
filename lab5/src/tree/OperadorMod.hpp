#ifndef _OPERADOR_MOD_HPP_
#define _OPERADOR_MOD_HPP_
#include "Operador.hpp"

class OperadorMod : public Operador
{
	public:
	void debug(int espacos)
	{
		for (int i = 0; i < espacos; i++)
		{
			cout << " ";
		}
		cout << "OP(MOD)" << endl;
	}
};

#endif
