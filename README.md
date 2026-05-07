# Sistema de Gerenciamento de Restaurante (C++)

Este projeto é uma simulação de um sistema de gestão hospitalar/restaurante desenvolvido em C++. O foco principal é o gerenciamento de arquivos sequenciais (simulados em memória via vetores), controle de estoque de ingredientes, registro de pedidos e validação de dados.

## 📌 Funcionalidades

O sistema permite realizar as seguintes operações através de um menu interativo:

- **Cadastros:** Inclusão de Clientes e Garçons com validação de unicidade de código.
- **Gerenciamento de Produtos:** Leitura de categorias, produtos e exclusão de itens do cardápio.
- **Fluxo de Pedidos:** - Registro de pedidos vinculando clientes e garçons.
    - Verificação automática de estoque de ingredientes baseada na tabela de consumo.
    - Baixa automática no estoque após a confirmação do preparo.
- **Consultas e Relatórios:**
    - Consulta detalhada de ingredientes (incluindo valor total em estoque).
    - Relatório de reposição: Identifica ingredientes abaixo do estoque mínimo e calcula o custo de compra.
    - Fechamento de caixa: Exibe o faturamento total arrecadado.

## 🛠️ Tecnologias Utilizadas

- Linguagem: C++
- Paradigma: Programação Estruturada / Orientada a Objetos (Baseada em Structs)
- Armazenamento: Estruturas de dados em memória (Simulando arquivos sequenciais)

## 🚀 Como Executar

### Pré-requisitos
- Compilador C++ (GCC, Clang ou MSVC)
- IDE sugerida: CLion, VS Code ou Code::Blocks

### Compilação via Terminal
1. Clone o repositório ou baixe os arquivos.
2. Abra o terminal na pasta do projeto.
3. Compile o código:
   ```bash
   g++ -o restaurante main.cpp
   
## 📊 Estrutura de Dados (Esquema Relacional)
O sistema utiliza diversas tabelas relacionadas para garantir a integridade dos dados:

## 📝 Regras de Negócio Implementadas
Unicidade: Não é permitido cadastrar dois clientes ou garçons com o mesmo código.

Estoque Crítico: O sistema impede a venda de um produto caso qualquer um de seus ingredientes não possua quantidade suficiente em estoque.

Baixa de Estoque: Ao confirmar um item no pedido, a quantidade necessária de cada ingrediente é subtraída imediatamente.
