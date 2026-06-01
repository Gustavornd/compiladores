#include "ExpTempFramePointer.hpp"

ExpTempFramePointer *ExpTempFramePointer::gera_Exp_TempFramePointer(/*Adaptar aas necessidades*/)
{
	ExpTempFramePointer *fp = new ExpTempFramePointer();

	return fp;
}
void ExpTempFramePointer::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "TEMP(FP)" << endl;
}
