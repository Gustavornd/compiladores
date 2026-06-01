int processamento_complexo(
    int id_transacao,
    double fator_risco,
    int requer_validacao_manual,
    int nivel_prioridade,
    double limite_confianca,
    int registrar_log_detalhado
) {
    int id_legado = 456;
    double fator_correlacao_antigo = 1.25;

    int resultado_analise = analise_de_risco_detalhada(
        id_transacao,
        fator_risco,
        requer_validacao_manual,
        nivel_prioridade,
        limite_confianca,
        registrar_log_detalhado
    );

    if (resultado_analise) {
        return 1;
    } else {
        return 0;   
    }
}
