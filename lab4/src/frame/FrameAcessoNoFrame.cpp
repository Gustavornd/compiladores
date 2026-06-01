#include "FrameAcessoNoFrame.hpp"

int FrameAcessoNoFrame::frame_pointer = -40;

FrameAcessoNoFrame::FrameAcessoNoFrame()
{
	posicao_no_frame = FrameAcessoNoFrame::frame_pointer;

	FrameAcessoNoFrame::frame_pointer -= 8;
}

void FrameAcessoNoFrame::imprime()
{
	cout << "variavel no frame" << endl;
	cout << "posicao_no_frame: " << posicao_no_frame << endl;
}
