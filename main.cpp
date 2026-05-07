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

struct Ingredientes {
    int codigo;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
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

void leitura_categoria(struct Categorias cat[], int &contCAT);
void leitura_produto(struct Produtos prod[], int &contPROD);
void leitura_ingredientes(struct Ingredientes ing[], int &contING);




int main() {


    return 0;
}



//1. Escreva funções específicas para a leitura dos dados das estruturas: Categorias, Produtos e Ingredientes.
//1.1
void leitura_categoria (struct Categorias cat[], int &contCAT){
    int i = 0;
    cout << "-_-_-_- LEITURA CATEGORIA -_-_-_-";
    for (int saida = 1; i < 1000 && saida != 0; i++){
        cout << "\n\nCodigo do Cliente " << (i+1) << ": ";
        cin >> cat[i].codigo;
        if (cat[i].codigo > 0){
            cout << "Descricao: ";
            getline(cin >> ws, cat[i].descricao);  //usando o getline pois o gets pode dar erro de buffer, ainda mais que é um programa grande
            }
        else saida = 0;
    }
    contCAT = i-1;
}

//1.2
void leitura_produto(struct Produtos prod[], int &contPROD) {
    int i = 0;
    cout << "-_-_-_- LEITURA PRODUTOS -_-_-_-";
    for (int saida = 1; i < 1000 && saida != 0; i++) {
        cout << "\n\nCodigo do Produto " << (i+1) << ": ";
        cin >> prod[i].codigo;
        if (prod[i].codigo > 0) {
            cout << "Descricao: ";
            getline(cin >> ws, prod[i].descricao);
            cout << "Codigo categoria: ";
            cin >> prod[i].codigo_categoria;
            cout << "Preco unitario R$: ";
            cin >> prod[i].preco_unitario;
        }
        else saida = 0;
    }
    contPROD = i-1;
}

//1.3
void leitura_ingredientes(struct Ingredientes ing[], int &contING) {
    int i = 0;
    cout << "-_-_-_- LEITURA INGREDIENTES -_-_-_-";
    for (int saida = 1; i < 1000 && saida != 0; i++) {
        cout << "Codigo do Ingrediente " << (i+1) << ": ";
        cin >> ing[i].codigo;
        if (ing[i].codigo > 0) {
            cout << "Descricao: ";
            getline(cin >> ws, ing[i].descricao);
            cout << "Quantidade estoque: ";
            cin >> ing[i].quant_estoque;
            cout << "Estoque minimo: ";
            cin >> ing[i].estoque_minimo;
            cout << "Estoque maximo: ";
            cin >> ing[i].estoque_maximo;
            cout << "Preco unitario R$: ";
            cin >> ing[i].preco_unitario;
        }
        else saida = 0;
    }
    contING = i-1;
}

