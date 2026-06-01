#include "FrameAcessoTemp.hpp"

int FrameAcessoTemp::id_atual = 0;

FrameAcessoTemp::FrameAcessoTemp()
{
	id = FrameAcessoTemp::id_atual++;
}

void FrameAcessoTemp::imprime()
{
	cout << "variavel em temporario" << endl;
	cout << "id: " << id << endl;
}
