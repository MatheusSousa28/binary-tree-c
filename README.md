# Binary Tree in C

A simple **Binary Search Tree (BST)** implementation in C with an interactive CLI menu.

## Features

- Build an initial balanced BST from a predefined sorted array.
- Print the tree in-order.
- Find:
  - minimum value
  - maximum value
  - a node by id
  - successor and predecessor of a node
- Insert new nodes.
- Remove nodes.

## Project Structure

```text
.
├── include/
│   └── tree.h
├── src/
│   └── tree.c
└── main.c
```

## Data Structure

Each node stores:

- `id` (int)
- `dad` (parent pointer)
- `left` (left child)
- `right` (right child)

## Build

From the repository root:

```bash
gcc -Wall -Wextra -Iinclude main.c src/tree.c -o binary-tree
```

## Run

```bash
./binary-tree
```

## CLI Menu

When running, you will see this menu:

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

> Note: menu messages are currently in Portuguese.

## Initial Tree

The program starts with a balanced tree generated from this sorted array:

```c
{101, 152, 230, 285, 340, 451, 512}
```

## Notes

- The implementation focuses on core BST operations.
- There is no full memory cleanup at program exit yet (only removed nodes are freed during deletion).

[Read this in Brazilian Portuguese](README.pt-br.md)
