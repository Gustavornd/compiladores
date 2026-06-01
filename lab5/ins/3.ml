let exemplo_funcao () =
  let a : int = 10 in
  let b : float = 5.5 in
  let c : bool = true in
  let resultado_int : int ref = ref 0 in
  let contador : int ref = ref 5 in

 let soma = a + 5 in
  let subtracao = 15.0 - b in
  let multiplicacao = a * 5 in
  let divisao = 20.0 / 4.0 in
  let modulo = a mod 3 in

  let condicao1 = soma < 20 in                         (* Menor que *)
  let condicao2 = 9.5 == subtracao in                      (* Igual a *)
  let condicao_logica = (condicao1 && condicao2) || (not c) in

 if condicao_logica then
    resultado_int := soma + modulo
  else
    resultado_int := multiplicacao - divisao;

 while !contador > 0 do
    resultado_int := !resultado_int + !contador;
    contador := !contador - 1
  done;

 ()
