#pragma once
#define _FRAME_ACESSO_TEMP_HPP_
#include "FrameAcesso.hpp"
class FrameAcessoTemp : public FrameAcesso
{
	public:
	static int id_atual;
	int id; // id unico do pseudo-registrador/temporario.
	FrameAcessoTemp();
	void imprime();
};
