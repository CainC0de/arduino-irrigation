def verificar_necessidade_irrigacao(umidade_solo, limite_umidade):
    if umidade_solo < limite_umidade:
        return True  
    else:
        return False  


umidade_solo_atual = 30 

limite_umidade = 40  


if verificar_necessidade_irrigacao(umidade_solo_atual, limite_umidade):
    print("O solo está seco. É necessário irrigar.")
else:
    print("O solo está úmido. Não é necessário irrigar.")
