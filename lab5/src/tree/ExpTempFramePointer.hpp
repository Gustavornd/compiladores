#ifndef _EXP_TEMPFRAMEPOINTER_HPP_
#define _EXP_TEMPFRAMEPOINTER_HPP_
#include "ExpTemp.hpp"

class ExpTempFramePointer : public ExpTemp
{
	public:
	static ExpTempFramePointer *gera_Exp_TempFramePointer(/*Adaptar aas necessidades*/);
	void debug(int espacos);
	ExpTempFramePointer()
	{
	}
};

#endif
