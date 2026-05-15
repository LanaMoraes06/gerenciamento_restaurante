#include <iostream>
#include <string.h>
using namespace std;

struct Categoria {
    int codigo;
    string descricao;
};

struct Produto {
    int codigo;
    string descricao;
    int codigo_categoria;
    double preco_unitario;
};

struct Ingrediente {
    int codigo;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    double preco_unitario;

};

struct Cliente {
    int codigo;
    string nome;
    int telefone;
};

struct Garcom {
    int codigo;
    string nome;
};

struct Pedido {
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

void criarListaCategorias(Categoria *cats);
void criarListaProdutos(Produto *prods);
void criarListaIngredientes(Ingrediente *ingredientes);
void criarListaClientes(Cliente *clientes);
void criarListaGarcom(Garcom *garcons);
void criarListaPedido(Pedido *pedidos);
void criarListaItensPedidos(ItensPedido *ips);
void criarListaConsumoIngredientes(ConsumoIngredientes *cis);
void criarListas(Categoria *cats, Produto *prods, Ingrediente *ingredientes, Cliente *clientes, Garcom *garcom, Pedido *pedido, ItensPedido *ips, ConsumoIngredientes *cis);
void leitura_categoria(struct Categoria cat[], int &contCAT);
void leitura_produto(struct Produto prod[], int &contPROD);
void leitura_ingredientes(struct Ingrediente ing[], int &contING);
void inclusao_clientes(struct Cliente S[], int contS, struct Clientes T[], int contT, struct Clientes A[], int &contA); //2
void inclusao_garcom(struct Garcom S[], int contS, struct Garcom T[], int contT, struct Garcom A[], int &contA); //3
void consulta_ingrediente(struct Ingrediente S[], int constS);
void exibir_minimo(struct Ingrediente S[], int contS);




int main() {


    return 0;
}

void criarListaCategorias(Categoria* cats)
{
    //Inicializar uma lista de categorias
    cats[0].codigo = 1;
    cats[0].descricao = "Bebidas";
    cats[1].codigo = 2;
    cats[1].descricao = "Alimentos";
    cats[2].codigo = 3;
    cats[2].descricao = "Doces";
}

void criarListaProdutos(Produto* prods)
{
    //Inicializar uma lista de produtos
    prods[0].codigo = 1;
    prods[0].descricao = "Coca Cola";
    prods[0].codigo_categoria = 1;
    prods[0].preco_unitario = 5.20;

    prods[1].codigo = 2;
    prods[1].descricao = "Cerveja";
    prods[1].codigo_categoria = 1;
    prods[1].preco_unitario = 10.20;

    prods[2].codigo = 3;
    prods[2].descricao = "Suco de Laranja";
    prods[2].codigo_categoria = 1;
    prods[2].preco_unitario = 15.50;

    prods[3].codigo = 4;
    prods[3].descricao = "Strogonoff";
    prods[3].codigo_categoria = 2;
    prods[3].preco_unitario = 28.90;

    prods[4].codigo = 5;
    prods[4].descricao = "Pizza";
    prods[4].codigo_categoria = 2;
    prods[4].preco_unitario = 30.80;

    prods[5].codigo = 6;
    prods[5].descricao = "Pastel";
    prods[5].codigo_categoria = 2;
    prods[5].preco_unitario = 16.75;

    prods[6].codigo = 7;
    prods[6].descricao = "Tiramissu";
    prods[6].codigo_categoria = 3;
    prods[6].preco_unitario = 25.50;
}

void criarListaIngredientes(Ingrediente* ingredientes)
{
    //Inicializar lista de Ingredientes
    ingredientes[0].codigo = 1;
    ingredientes[0].descricao = "Açucar";
    ingredientes[0].quant_estoque = 10;
    ingredientes[0].estoque_minimo = 2;
    ingredientes[0].estoque_maximo = 15;
    ingredientes[0].preco_unitario = 10.50;

    ingredientes[1].codigo = 2;
    ingredientes[1].descricao = "Temperos";
    ingredientes[1].quant_estoque = 250;
    ingredientes[1].estoque_minimo = 100;
    ingredientes[1].estoque_maximo = 250;
    ingredientes[1].preco_unitario = 1.50;

    ingredientes[2].codigo = 3;
    ingredientes[2].descricao = "Queijo";
    ingredientes[2].quant_estoque = 2;
    ingredientes[2].estoque_minimo = 5;
    ingredientes[2].estoque_maximo = 15;
    ingredientes[2].preco_unitario = 45.80;

    ingredientes[3].codigo = 4;
    ingredientes[3].descricao = "Creme de leite";
    ingredientes[3].quant_estoque = 20;
    ingredientes[3].estoque_minimo = 10;
    ingredientes[3].estoque_maximo = 15;
    ingredientes[3].preco_unitario = 5.50;

    ingredientes[4].codigo = 5;
    ingredientes[4].descricao = "Leite Condensado";
    ingredientes[4].quant_estoque = 11;
    ingredientes[4].estoque_minimo = 5;
    ingredientes[4].estoque_maximo = 20;
    ingredientes[4].preco_unitario = 5.50;

    ingredientes[5].codigo = 6;
    ingredientes[5].descricao = "Tomate";
    ingredientes[5].quant_estoque = 2;
    ingredientes[5].estoque_minimo = 1;
    ingredientes[5].estoque_maximo = 5;
    ingredientes[5].preco_unitario = 8.00;

    ingredientes[6].codigo = 7;
    ingredientes[6].descricao = "Carne de Boi";
    ingredientes[6].quant_estoque = 1;
    ingredientes[6].estoque_minimo = 1;
    ingredientes[6].estoque_maximo = 3;
    ingredientes[6].preco_unitario = 45.80;

    ingredientes[7].codigo = 8;
    ingredientes[7].descricao = "Molho de Tomate";
    ingredientes[7].quant_estoque = 5;
    ingredientes[7].estoque_minimo = 5;
    ingredientes[7].estoque_maximo = 20;
    ingredientes[7].preco_unitario = 2.70;

    ingredientes[8].codigo = 9;
    ingredientes[8].descricao = "Massa de Pastel";
    ingredientes[8].quant_estoque = 12;
    ingredientes[8].estoque_minimo = 5;
    ingredientes[8].estoque_maximo = 20;
    ingredientes[8].preco_unitario = 10.50;

    ingredientes[9].codigo = 10;
    ingredientes[9].descricao = "Laranja";
    ingredientes[9].quant_estoque = 6;
    ingredientes[9].estoque_minimo = 10;
    ingredientes[9].estoque_maximo = 20;
    ingredientes[9].preco_unitario = 3.50;

    ingredientes[10].codigo = 11;
    ingredientes[10].descricao = "Massa de Pizza";
    ingredientes[10].quant_estoque = 30;
    ingredientes[10].estoque_minimo = 5;
    ingredientes[10].estoque_maximo = 15;
    ingredientes[10].preco_unitario = 25.50;

}

void criarListaClientes(Cliente* clientes)
{
    //Inicializar lista de clientes
    clientes[0].codigo = 1;
    clientes[0].nome = "Pedro";
    clientes[0].telefone = 99999999999;

    clientes[1].codigo = 2;
    clientes[1].nome = "Matheus";
    clientes[1].telefone = 88888888888;

    clientes[2].codigo = 1;
    clientes[2].nome = "Ana";
    clientes[2].telefone = 77777777777;

}

void criarListaGarcom(Garcom* garcons)
{
    //Inicializar lista de garçons
    garcons[0].codigo = 1;
    garcons[0].nome = "Lana";

    garcons[1].codigo = 2;
    garcons[1].nome = "Rafaela";
}

void criarListaPedido(Pedido* pedidos)
{
    //Inicializar lista de pedidos
    pedidos[0].codigo = 1;
    pedidos[0].codigo_cliente = 1;
    pedidos[0].codigo_garcom = 1;
    pedidos[0].data = "23/01/2025";

    pedidos[1].codigo = 2;
    pedidos[1].codigo_cliente = 1;
    pedidos[1].codigo_garcom = 2;
    pedidos[1].data = "27/01/2025";

    pedidos[2].codigo = 3;
    pedidos[2].codigo_cliente = 2;
    pedidos[2].codigo_garcom = 2;
    pedidos[2].data = "01/02/2025";

    pedidos[3].codigo = 4;
    pedidos[3].codigo_cliente = 2;
    pedidos[3].codigo_garcom = 2;
    pedidos[3].data = "01/02/2025";

    pedidos[4].codigo = 5;
    pedidos[4].codigo_cliente = 2;
    pedidos[4].codigo_garcom = 1;
    pedidos[4].data = "02/02/2025";

    pedidos[5].codigo = 6;
    pedidos[5].codigo_cliente = 3;
    pedidos[5].codigo_garcom = 1;
    pedidos[5].data = "02/02/2025";

}

void criarListaItensPedidos(ItensPedido* ips)
{
    //Inicializar lista de itens no pedido
    ips[0].codigo_pedido = 1;
    ips[0].codigo_produto = 1;
    ips[0].quantidade = 1;

    ips[1].codigo_pedido = 1;
    ips[1].codigo_produto = 4;
    ips[1].quantidade = 1;

    ips[2].codigo_pedido = 2;
    ips[2].codigo_produto = 2;
    ips[2].quantidade = 1;

    ips[3].codigo_pedido = 2;
    ips[3].codigo_produto = 4;
    ips[3].quantidade = 1;

    ips[4].codigo_pedido = 3;
    ips[4].codigo_produto = 2;
    ips[4].quantidade = 2;

    ips[5].codigo_pedido = 3;
    ips[5].codigo_produto = 1;
    ips[5].quantidade = 2;

    ips[6].codigo_pedido = 3;
    ips[6].codigo_produto = 5;
    ips[6].quantidade = 1;

    ips[7].codigo_pedido = 4;
    ips[7].codigo_produto = 5;
    ips[7].quantidade = 2;

    ips[8].codigo_pedido = 5;
    ips[8].codigo_produto = 1;
    ips[8].quantidade = 5;

    ips[9].codigo_pedido = 5;
    ips[9].codigo_produto = 5;
    ips[9].quantidade = 2;

    ips[10].codigo_pedido = 6;
    ips[10].codigo_produto = 1;
    ips[10].quantidade = 2;

    ips[11].codigo_pedido = 6;
    ips[11].codigo_produto = 6;
    ips[11].quantidade = 1;

    ips[12].codigo_pedido = 6;
    ips[12].codigo_produto = 7;
    ips[12].quantidade = 1;

}

void criarListaConsumoIngredientes(ConsumoIngredientes* cis)
{

    cis[0].codigo_produto = 3;
    cis[0].codigo_ingrediente = 10;
    cis[0].quantidade_necessaria = 8;

    cis[1].codigo_produto = 4;
    cis[1].codigo_ingrediente = 2;
    cis[1].quantidade_necessaria = 30;

    cis[2].codigo_produto = 4;
    cis[2].codigo_ingrediente = 4;
    cis[2].quantidade_necessaria = 1;

    cis[3].codigo_produto = 4;
    cis[3].codigo_ingrediente = 6;
    cis[3].quantidade_necessaria = 1;

    cis[4].codigo_produto = 4;
    cis[4].codigo_ingrediente = 7;
    cis[4].quantidade_necessaria = 1;

    cis[5].codigo_produto = 5;
    cis[5].codigo_ingrediente = 11;
    cis[5].quantidade_necessaria = 1;

    cis[6].codigo_produto = 5;
    cis[6].codigo_ingrediente = 8;
    cis[6].quantidade_necessaria = 1;

    cis[7].codigo_produto = 5;
    cis[7].codigo_ingrediente = 3;
    cis[7].quantidade_necessaria = 2;

    cis[8].codigo_produto = 6;
    cis[8].codigo_ingrediente = 3;
    cis[8].quantidade_necessaria = 2;

    cis[9].codigo_produto = 6;
    cis[9].codigo_ingrediente = 6;
    cis[9].quantidade_necessaria = 1;

    cis[10].codigo_produto = 6;
    cis[10].codigo_ingrediente = 9;
    cis[10].quantidade_necessaria = 1;

    cis[11].codigo_produto = 6;
    cis[11].codigo_ingrediente = 7;
    cis[11].quantidade_necessaria = 1;

    cis[12].codigo_produto = 7;
    cis[12].codigo_ingrediente = 1;
    cis[12].quantidade_necessaria = 1;

    cis[13].codigo_produto = 7;
    cis[13].codigo_ingrediente = 4;
    cis[13].quantidade_necessaria = 1;

    cis[13].codigo_produto = 7;
    cis[13].codigo_ingrediente = 5;
    cis[13].quantidade_necessaria = 1;

}

void criarListas(Categoria* cats, Produto* prods, Ingrediente* ingredientes, Cliente* clientes, Garcom* garcom,
    Pedido* pedido, ItensPedido* ips, ConsumoIngredientes* cis)
{
    criarListaCategorias(cats);
    criarListaProdutos(prods);
    criarListaIngredientes(ingredientes);
    criarListaClientes(clientes);
    criarListaGarcom(garcom);
    criarListaPedido(pedido);
    criarListaItensPedidos(ips);
    criarListaConsumoIngredientes(cis);
}

//1. Escreva funções específicas para a leitura dos dados das estruturas: Categorias, Produtos e Ingredientes.
//1.1
void leitura_categoria (struct Categoria cat[], int &contCAT){
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
void leitura_produto(struct Produto prod[], int &contPROD) {
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
void leitura_ingredientes(struct Ingrediente ing[], int &contING) {
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

//2. Escreva uma função para permitir a inclusão de novos registros na tabela de Clientes.
void inclusao_clientes(struct Cliente S[], int contS, struct Cliente T[], int contT, struct Cliente A[], int &contA) {
    int i = 0, j = 0, k = 0;
    for (;i < contS && j < contT;k++){
            if (S[i].codigo < T[j].codigo){
                A[k].codigo = S[i].codigo;
                A[k].nome = S[i].nome;
                A[k].telefone = S[i].telefone;
                i++;
            }
        else if (T[j].codigo < S[i].codigo){
            A[k].codigo = T[j].codigo;
            A[k].nome = T[j].nome;
            A[k].telefone = T[j].telefone;
            j++;
        } else {
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;                          //2.1
            A[k].telefone = S[i].telefone;
            i++;
            j++;
        }}

    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].telefone = S[i].telefone;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].nome = T[j].nome;
        A[k].telefone = T[j].telefone;
        j++;
        k++;
    }
    contA = k;
}

//3.Escreva uma função para permitir a inclusão de novos registros na tabela de Garçons.
void inclusao_garcom(struct Garcom S[], int contS, struct Garcom T[], int contT, struct Garcom A[], int &contA) {
    int i = 0, j = 0, k = 0;
    for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            i++;
        }
        else if (T[j].codigo < S[i].codigo){
            A[k].codigo = T[j].codigo;
            A[k].nome = T[j].nome;
            j++;
        } else {
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;                          //3.1
            i++;
            j++;
        }}

    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].nome = T[j].nome;
        j++;
        k++;
    }
    contA = k;
}

//7. Escreva uma função para permitir ao usuário consultar os dados de determinado ingrediente.
void consulta_ingrediente(struct Ingrediente S[], int tamanho) {
    char resp;
    do {
        int cod = 0;
        cout << "Selecione o código do ingrediente que deseja consultar: " << endl;
        for (int i = 0; i < tamanho; i++) {
            cout << S[i].codigo << " - " << S[i].descricao << endl;
        }
        cout << "Escolha: ";
        cin >> cod;
        for (int i = 0; i < tamanho; i++) {
            if (S[i].codigo == cod) {
                cout <<"Codigo: "<< S[i].codigo << endl;
                cout << "Descricao: "<< S[i].descricao << endl;
                cout << "Quantidade estoque: " << S[i].quant_estoque;
                cout << "Estoque minimo: " << S[i].estoque_minimo;
                cout << "Estoque maximo: " << S[i].estoque_maximo;
                cout << "Preco unitario R$: " << S[i].preco_unitario;
                cout << "Valor total em estoque: " << (S[i].quant_estoque * S[i].preco_unitario);
            }
        }
        cout << "Deseja consultar mais ingredientes?" << endl;
        cout << "Escolha: ";
        cin >> resp;
    }while (resp == 's' || resp == 'S');
}

//8. Escreva uma função para exibir todos os ingredientes que estejam com a quantidade em estoque abaixo do estoque mínimo.
//8.1) As seguintes informações devem ser exibidas: Código, Descrição, Quantidade em estoque, Estoque máximo, Quantidade a ser comprada, Valor da compra
//8.1.1) A quantidade a ser comprada é calculada pela diferença entre o estoque máximo e a quantidade em estoque
//8.2) Ao final, a função deverá exibir o valor total a ser gasto na reposição de ingredientes

void exibir_minimo(struct Ingrediente S[], int tamanho) {
    double valorTotal = 0;
    for (int i = 0; i < tamanho; i++) {
        if (S[i].quant_estoque < S[i].estoque_minimo) {
            int qtdCompra = S[i].estoque_maximo - S[i].quant_estoque;
            double valorCompra = qtdCompra * S[i].preco_unitario;
            cout <<"Codigo: "<< S[i].codigo << endl;
            cout << "Descricao: "<< S[i].descricao << endl;
            cout << "Quantidade estoque: " << S[i].quant_estoque << endl;
            cout << "Estoque maximo: " << S[i].estoque_maximo << endl;
            cout << "Quantidade a ser comprada: " << qtdCompra << endl;
            cout << "Valor da compra R$: " << valorCompra << endl;
            valorTotal += valorCompra;
        }
    }
    cout << "Valor total da compra R$: " << valorTotal;
}

//9. Escreva uma função para exibir o valor total arrecadado com todos os pedidos.
//9.1) O valor de cada pedido deve ser calculado pela soma dos valores de seus itens
//9.2) O valor de cada item é calculado multiplicando a quantidade pelo preço unitário do produto

void valor_arrecadado(struct Pedido P[], struct ItensPedido I[], struct  Produto PD[], int tamanho) {
    int valorItem=0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            valorItem += PD[j].preco_unitario * P[j];
        }
    }
}