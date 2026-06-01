#ifndef _OPERADOR_HPP_
#define _OPERADOR_HPP_
#include <iostream>
using namespace std;
class Operador
{
	public:
	virtual void debug(int espacos)
	{
		cout << "debug operador não implementado" << endl;
	}
};

#endif
