#include "ExpTemp.hpp"

ExpTemp *ExpTemp::gera_Exp_Temp(int id)
{
	ExpTemp *temp = new ExpTemp();
	temp->id = id;
	return temp;
}
void ExpTemp::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "TEMP(R" << id << ")" << endl;
}
