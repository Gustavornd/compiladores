void exemplo_funcao(void) {
  int a = 10;
  double b = 5.5;
  int c = 0;
  int resultado_int = 0;
  int contador = 5;

  int soma = a + 5;
  double subtracao = 15.0 - b;
  int multiplicacao = a * 5;
  double divisao = 20.0 / 4.0;
  int modulo = a % 3;

  int condicao1 = soma < 20;
  int condicao2 = 9.5 == subtracao;
  int condicao_logica = (condicao1 && condicao2) || (!c);

  if (condicao_logica) {
    resultado_int = soma + modulo;
  } else {
    resultado_int = multiplicacao - divisao;
  }

  while (contador > 0) {
    resultado_int = resultado_int + contador;
    contador = contador - 1;
  }
}
