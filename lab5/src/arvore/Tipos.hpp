#pragma once
#define TIPOS_HPP
#include "../frame/FrameAcesso.hpp"
#include "Valor.hpp"
#include <map>
#include <string>
using namespace std;

const string TIPO_INT = "int";
const string TIPO_FLOAT = "float";
const string TIPO_BOOL = "bool";
const string TIPO_UNIT = "unit";
const string TIPO_ID = "id";
const string TIPO_REF_INT = "int ref";

const string TIPO_REF_FLOAT = "float ref";
const string TIPO_REF_BOOL = "bool ref";

struct Simbolo
{
	string tipo;
	bool usado = false;
	bool parametro = false;
	FrameAcesso *frame_acesso = nullptr;
};

class Tipos
{
	// private:
	//   static map<string, Simbolo> tabela;

	public:
	static void adiciona_valor_tabela(string id, string tipo, bool parametro = false);
	static Simbolo recupera_valor_tabela(string id);
	static map<string, Simbolo> tabela;
	static void coloca_frame(string id, FrameAcesso *frame);
};
