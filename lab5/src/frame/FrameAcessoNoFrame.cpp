#include "FrameAcessoNoFrame.hpp"

int FrameAcessoNoFrame::stack_pointer = -40;

FrameAcessoNoFrame::FrameAcessoNoFrame()
{
	posicao_no_frame = FrameAcessoNoFrame::stack_pointer;

	FrameAcessoNoFrame::stack_pointer -= 8;
}

void FrameAcessoNoFrame::imprime()
{
	cout << "variavel no frame" << endl;
	cout << "posicao_no_frame: " << posicao_no_frame << endl;
}
