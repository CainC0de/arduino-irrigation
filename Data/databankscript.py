import sqlite3

# Conecte-se ao banco de dados (se não existir, será criado)
conexao = sqlite3.connect('dados_do_projeto.db')

# Crie um cursor para executar comandos SQL
cursor = conexao.cursor()

# Crie uma tabela para armazenar os dados dos sensores
cursor.execute('''CREATE TABLE IF NOT EXISTS leituras_sensor (
                    id INTEGER PRIMARY KEY,
                    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                    umidade_solo REAL,
                    quantidade_agua REAL,
                    data DATE,
                    hora TIME
                )''')

# Feche a conexão com o banco de dados
conexao.close()
