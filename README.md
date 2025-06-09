# 🃏 Super Trunfo - Países: Comparação de Cartas

Este programa implementa o jogo **Super Trunfo de Cidades**, no qual duas cartas com dados de cidades são comparadas com base em atributos como população, área, PIB, etc.

## 🚀 O que o programa faz

### ✅ Funcionalidades principais:

- **Cadastro de Cartas:** Solicita ao usuário que cadastre duas cartas com informações detalhadas de uma cidade.
- **Exibição das Cartas:** Exibe os dados inseridos de forma organizada no terminal.
- **Comparação Avançada (Nível Mestre):**
  - Permite comparar **dois atributos diferentes** simultaneamente.
  - Atributos disponíveis:
    1. População
    2. Área
    3. PIB
    4. Pontos Turísticos
    5. Densidade Populacional (menor valor vence)
    6. PIB per capita
  - **Empates** são tratados e exibidos adequadamente.
  - Possibilidade de repetir a comparação com novos atributos via menu interativo.

---

## 🧠 Lógica de comparação

- A lógica considera dois atributos por vez.
- Para cada atributo:
  - Quem tiver o maior valor vence (exceto densidade populacional).
  - Se os dois atributos forem vencidos pela mesma carta, ela é a vencedora.
  - Em caso de empate nos dois atributos, o sistema informa que houve **empate**.

---

## 💻 Como rodar

### 🛠️ Requisitos:
- Compilador C (ex: GCC)

### ▶️ Passos para executar:

1. **Salve o código-fonte em um arquivo** (ex: `super_trunfo.c`)
2. **Compile o programa:**
   ```bash
   gcc super_trunfo.c -o super_trunfo
   ```
3. **Execute o programa:**
   ```bash
   ./super_trunfo
   ```

---

## 📝 Observações:

- O código usa estruturas como `struct`, `switch`, `if`, ternários e lógica aninhada para demonstrar domínio de programação.
- Ideal para treinar conceitos fundamentais de C com foco em manipulação de dados, decisões e interação com o usuário.

---

## 👨‍🏫 Projeto proposto por:

**Equipe de Ensino - MateCheck**

---
