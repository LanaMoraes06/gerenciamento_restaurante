#include <iostream>
using namespace std;

struct Categorias {
    int codigo;
    string descricao;
};

struct Produtos {
    int codigo;
    string descricao;
    int codigo_categoria;
    double preco_unitario;
};

struct Clientes {
    int codigo;
    string nome;
    int telefone;
};

struct Garcom {
    int codigo;
    string nome;
};

struct Pedidos {
    int codigo;
    int codigo_cliente;
    int codigo_garcom;
    string data;
};

struct ItensPedido {
    int codigo_pedido;
    int codigo_produto;
    int quantidade;
};

struct ConsumoIngredientes {
    int codigo_produto;
    int codigo_ingrediente;
    int quantidade_necessaria;
};