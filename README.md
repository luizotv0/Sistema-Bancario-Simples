# 🏦 Sistema Bancário Simples
## 📄 Descrição

Este é um programa em C que simula um sistema bancário simples. Ele permite que o usuário faça depósitos, saques, consulte o saldo e visualize o extrato das transações realizadas durante a sessão.

O programa também inclui autenticação por senha, garantindo que apenas usuários autorizados possam acessar as funcionalidades.

## ⚙️ Funcionalidades

🔑 Autenticação por senha (senha padrão: 1234)  
💰 Depósito de valores positivos  
💸 Saque com verificação de saldo suficiente  
🏦 Consulta de saldo atualizado  
📋 Extrato de transações da sessão (depósitos e saques)  
🖥️ Menu interativo que permite múltiplas operações até o usuário escolher sair  

## 📝 Como usar

1️⃣Compile o código:

2️⃣Execute o programa:

3️⃣Digite a senha para acessar o sistema.

Escolha uma das opções do menu:

1 - Deposito 💰

2 - Saque 💸

3 - Saldo 🏦

4 - Extrato 📋

5 - Sair 🚪

Repita as operações quantas vezes desejar.

Ao sair, o programa exibirá o extrato final e o saldo atualizado.

## 🛠️ Estruturas utilizadas

🔄 Laços de repetição (while, do...while) para autenticação e menu.

⚖️ Estruturas condicionais (if / else e switch) para decisões como validação de senha, saldo e opção do menu.

🗂️ Array de struct para armazenar o extrato das transações.

## ⚠️ Observações

O programa não persiste dados: todas as transações são registradas apenas durante a sessão.  
O limite máximo de transações na sessão é definido pela constante MAX_TRANSACOES (padrão: 50).
