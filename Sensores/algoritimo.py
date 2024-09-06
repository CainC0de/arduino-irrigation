def verificar_necessidade_irrigacao(umidade_solo, limite_umidade):
    if umidade_solo < limite_umidade:
        return True  # Necessidade de irrigação
    else:
        return False  # Não é necessário irrigar

# Exemplo de leitura do sensor de umidade do solo
umidade_solo_atual = 30  # Valor fictício para exemplo

# Limite de umidade para acionar a irrigação
limite_umidade = 40  # Valor fictício para exemplo

# Verifica se é necessário irrigar com base na leitura atual do sensor
if verificar_necessidade_irrigacao(umidade_solo_atual, limite_umidade):
    print("O solo está seco. É necessário irrigar.")
else:
    print("O solo está úmido. Não é necessário irrigar.")
