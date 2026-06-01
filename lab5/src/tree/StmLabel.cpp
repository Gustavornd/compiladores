#include "StmLabel.hpp"
#include "Stm.hpp"

StmLabel *StmLabel::gera_Stm_Label(string nome)
{
	StmLabel *label = new StmLabel();
	label->nome = nome;

	return label;
}

void StmLabel::debug(int espacos)
{
	for (int i = 0; i < espacos; i++)
	{
		cout << " ";
	}
	cout << "LABEL(" << nome << ")" << endl;
}
