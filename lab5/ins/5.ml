let processamento_complexo
    (id_transacao : int)
    (fator_risco : float)
    (requer_validacao_manual : bool)
    (nivel_prioridade : int)
    (limite_confianca : float)
    (registrar_log_detalhado : bool)
    : bool =

  (* Variáveis não utilizadas podem continuar sendo declaradas aqui, se necessário. *)
  (* Elas são internas à lógica da função e não dependem dos parâmetros. *)
  let _id_legado = 456 in
  let _fator_correlacao_antigo = 1.25 in
  
  (* A chamada para a função externa agora usa diretamente os parâmetros 
    recebidos por 'processamento_complexo'.
  *)
  let resultado_analise =
    analise_de_risco_detalhada
      id_transacao
      fator_risco
      requer_validacao_manual
      nivel_prioridade
      limite_confianca
      registrar_log_detalhado
  in

  (* Lógica final baseada no resultado da análise. *)
  if resultado_analise then
    true
  else
    false
