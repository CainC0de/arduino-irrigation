import sqlite3


conexao = sqlite3.connect('dados_do_projeto.db')


cursor = conexao.cursor()


cursor.execute('''CREATE TABLE IF NOT EXISTS leituras_sensor (
                    id INTEGER PRIMARY KEY,
                    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                    umidade_solo REAL,
                    quantidade_agua REAL,
                    data DATE,
                    hora TIME
                )''')


conexao.close()
