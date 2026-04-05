# Árvore Binária em C

Uma implementação simples de **Árvore de Busca Binária (BST)** em C com um menu interativo no terminal.

## Funcionalidades

- Gera uma BST inicial balanceada a partir de um vetor ordenado predefinido.
- Imprime a árvore em ordem (in-order).
- Busca:
  - menor valor
  - maior valor
  - nó por id
  - sucessor e predecessor de um nó
- Insere novos nós.
- Remove nós.

## Estrutura do Projeto

```text
.
├── include/
│   └── tree.h
├── src/
│   └── tree.c
└── main.c
```

## Estrutura de Dados

Cada nó armazena:

- `id` (int)
- `dad` (ponteiro para pai)
- `left` (filho esquerdo)
- `right` (filho direito)

## Compilação

Na raiz do repositório:

```bash
gcc -Wall -Wextra -Iinclude main.c src/tree.c -o binary-tree
```

## Execução

```bash
./binary-tree
```

## Menu da CLI

Ao executar, você verá este menu:

```text
1 imprimir
2 minimo
3 maximo
4 buscar
5 sucessor/predecessor
6 inserir
7 remover
0 sair
```

## Árvore Inicial

O programa inicia com uma árvore balanceada gerada a partir deste vetor ordenado:

```c
{101, 152, 230, 285, 340, 451, 512}
```

## Observações

- A implementação está focada nas operações principais de BST.
- Ainda não há limpeza completa de memória ao encerrar o programa (somente nós removidos são liberados durante deleção).

[Leia isso em Inglês](README.md)
