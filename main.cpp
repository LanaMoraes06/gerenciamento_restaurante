#include <iostream>
#include <string>

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

// Criar as listas
void criarListaCategorias(Categoria* cats, int &endIndex);
void criarListaProdutos(Produto* prods, int &endIndex);
void criarListaIngredientes(Ingrediente* ingredientes, int &endIndex);
void criarListaClientes(Cliente* clientes, int &endIndex);
void criarListaGarcom(Garcom* garcons, int &endIndex);
void criarListaPedido(Pedido* pedidos, int &endIndex);
void criarListaItensPedidos(ItensPedido* ips, int &endIndex);
void criarListaConsumoIngredientes(ConsumoIngredientes* cis, int &endIndex);
void criarListas(Categoria* cats, Produto* prods, Ingrediente* ingredientes, Cliente* clientes, Garcom* garcom,
    Pedido* pedido, ItensPedido* ips, ConsumoIngredientes* cis, int &endIndexCategoria, int &endIndexProduto, int &endIndexIngredientes ,int &endIndexCliente, int &endIndexGarcom, int &endIndexPedido, int &endIndexIps, int &endIndexCis);

// Metodos de pesquisa binaria find
Categoria findCategoria(Categoria *cats, int codCategoria, int endIndex);
Produto findProduto(Produto *produtos, int codProduto, int endIndex);
Ingrediente findIngrediente(Ingrediente *ingredientes, int codIngrediente, int endIndex);
Cliente findCliente(Cliente *clientes, int codCliente, int endIndex);
Garcom findGarcom(Garcom *garcons, int codGarcom, int endIndex);
Pedido findPedido(Pedido *pedidos, int codPedido, int endIndex);
ItensPedido findIps(ItensPedido *ics, int codPedido, int codProduto, int endIndex);
ItensPedido findCis(ConsumoIngredientes *cis, int codPedido, int codIngrediente, int endIndex);
void findCisByProdutos(ConsumoIngredientes* cis, int endIndexCis, int codProduto, ConsumoIngredientes *cisRetorno, int &endIndexCisRetorno);

// Exercicios 1
void lerCategoria(struct Categoria cat[], int &contCAT);
void lerProduto(struct Produto prod[], int &contPROD);
void lerIngrediente(struct Ingrediente ing[], int &contING);
void lerCliente(struct Cliente cli[], int &contCLI);
void lerGarcom(struct Garcom garcom[], int &contGARCOM);

// Exercicio 2-3
void incluirCliente(struct Cliente S[], int contS, struct Cliente T[], int contT, struct Cliente A[], int &contA);
void incluirGarcom(struct Garcom S[], int contS, struct Garcom T[], int contT, struct Garcom A[], int &contA);
void incluirCategoria(struct Categoria S[], int contS, struct Categoria T[], int contT, struct Categoria A[], int &contA);
void incluirProduto(struct Produto S[], int contS, struct Produto T[], int contT, struct Produto A[], int &contA);
void incluirIngrediente(struct Ingrediente S[], int contS, struct Ingrediente T[], int contT, struct Ingrediente A[], int &contA);


// Exercicio 4
void removerProduto(Produto* produtos, int endIndexProdutos, int* codsProdutosExclusao, int endIndexExclusao, Produto* listaFinal, int &contFinal);
void telaRemoverProduto(Produto* produtos, int &endIndexProdutos);

// Exercicio 5
Pedido createPedido(Cliente *clientes, int endIndexCliente, Garcom *garcons, int endIndexGarcom, Pedido *pedidos, int endIndexPedidos);
void inserirPedido(Pedido* pedidos, int endIndexPedido, Cliente *clientes, int endIndexCliente, Garcom *garcons, int endIndexGarcom, Pedido *pedidoResultado, int &endIndexResultado);

// Exercicio 6
ItensPedido inserirProdutoNoPedido(int pedido, int produto, int qtde);
void incluirItensPedido(ItensPedido *ips, int &endIndexIps, ItensPedido ipIncluir);
void consumirIngredientes(ConsumoIngredientes &ci, Ingrediente &in, bool &resultado, int qtde);
void telaInserirProdutoNoPedido(Produto *produtos, int endIndexProduto, Categoria *categorias, int endIndexCategorias, ItensPedido *ips, int &endIndexIps, ConsumoIngredientes *cis, int endIndexCis, Ingrediente *ingredientes, int endIndexIngredientes);


// Exercicio 7
void consultarIngrediente(struct Ingrediente S[], int tamanho);


// Exercicio 8
void exibirMinimo(struct Ingrediente S[], int tamanho);


//Exercicio 9
void valorTotal(Pedido pedidos[], int contPedidos, ItensPedido itens[], int contItens, Produto produtos[], int contProdutos);


// TELAS - 1, 2 e 3
void telaInserirCategoria(Categoria* categoriasPrincipais, int &endIndexCategorias);
void telaInserirProduto(Produto* produtosPrincipais, int &endIndexProdutos);
void telaInserirIngrediente(Ingrediente* ingredientesPrincipais, int &endIndexIngredientes);
void telaInserirClientes(Categoria* clientesPrincipais, int &endIndexClientes);
void telaInserirGarcom(Categoria* garconsPrincipais, int &endIndexGarcoms);



int main() {
    // Declaração das listas
    Categoria cats[1000];
    Produto prods[1000];
    Ingrediente ingredientes[1000];
    Cliente clientes[1000];
    Garcom garcons[1000];
    Pedido pedidos[1000];
    ItensPedido ips[1000];
    ConsumoIngredientes cis[1000];

    int endIndexCats;
    int endIndexProdutos;
    int endIndexIngredientes;
    int endIndexClientes;
    int endIndexGarcons;
    int endIndexPedidos;
    int endIndexIps;
    int endIndexCis;

    // Inicialização das listas
    criarListas(cats, prods, ingredientes, clientes, garcons, pedidos, ips, cis, endIndexCats, endIndexProdutos, endIndexIngredientes,
        endIndexClientes, endIndexGarcons, endIndexPedidos, endIndexIps, endIndexCis);

    // Teste do código do Pedro (Exercicio 6)
    telaInserirProdutoNoPedido(prods, endIndexProdutos, cats, endIndexCats, ips, endIndexIps, cis, endIndexCis, ingredientes, endIndexIngredientes);

    /* // Se quiser testar o Exercicio 4 depois, basta descomentar este bloco:
    Produto produtosFinal[1000];
    int CodParaExclusao[2] = {2, 5};
    int endIndexFinal;

    removerProduto(prods, endIndexProdutos, CodParaExclusao, 1, produtosFinal, endIndexFinal);

    cout << "\nUltimo index: " << endIndexFinal << endl;
    for (int i = 0; i <= endIndexFinal; i++) {
        cout << produtosFinal[i].descricao << endl;
    }
    */

    return 0;
}

// ====================== INICIALIZAÇÃO DE LISTAS ======================

void criarListaCategorias(Categoria* cats, int &endIndex) {
    cats[0].codigo = 1;
    cats[0].descricao = "Bebidas";
    cats[1].codigo = 2;
    cats[1].descricao = "Alimentos";
    cats[2].codigo = 3;
    cats[2].descricao = "Doces";
    endIndex = 2;
}

void criarListaProdutos(Produto* prods, int &endIndex) {
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

    prods[5].codigo = 7;
    prods[5].descricao = "Pastel";
    prods[5].codigo_categoria = 2;
    prods[5].preco_unitario = 16.75;

    prods[6].codigo = 8;
    prods[6].descricao = "Tiramissu";
    prods[6].codigo_categoria = 3;
    prods[6].preco_unitario = 25.50;

    endIndex = 6;
}

void criarListaIngredientes(Ingrediente* ingredientes, int &endIndex) {
    ingredientes[0].codigo = 1;
    ingredientes[0].descricao = "Acucar";
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

    endIndex = 10;
}

void criarListaClientes(Cliente* clientes, int &endIndex) {
    clientes[0].codigo = 1;
    clientes[0].nome = "Pedro";
    clientes[0].telefone = 999999999;

    clientes[1].codigo = 2;
    clientes[1].nome = "Matheus";
    clientes[1].telefone = 888888888;

    clientes[2].codigo = 4;
    clientes[2].nome = "Ana";
    clientes[2].telefone = 777777777;

    endIndex = 2;
}

void criarListaGarcom(Garcom* garcons, int &endIndex) {
    garcons[0].codigo = 1;
    garcons[0].nome = "Lana";

    garcons[1].codigo = 2;
    garcons[1].nome = "Rafaela";

    endIndex = 1;
}

void criarListaPedido(Pedido* pedidos, int &endIndex) {
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

    endIndex = 5;
}

void criarListaItensPedidos(ItensPedido* ips, int &endIndex) {
    ips[0].codigo_pedido = 0;
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
    ips[11].codigo_produto = 7;
    ips[11].quantidade = 1;

    ips[12].codigo_pedido = 6;
    ips[12].codigo_produto = 8;
    ips[12].quantidade = 1;

    endIndex = 12;
}

void criarListaConsumoIngredientes(ConsumoIngredientes* cis, int &endIndex) {
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
    cis[5].codigo_ingrediente = 3;
    cis[5].quantidade_necessaria = 1;

    cis[6].codigo_produto = 5;
    cis[6].codigo_ingrediente = 8;
    cis[6].quantidade_necessaria = 1;

    cis[7].codigo_produto = 5;
    cis[7].codigo_ingrediente = 11;
    cis[7].quantidade_necessaria = 2;

    cis[8].codigo_produto = 6;
    cis[8].codigo_ingrediente = 3;
    cis[8].quantidade_necessaria = 2;

    cis[9].codigo_produto = 6;
    cis[9].codigo_ingrediente = 6;
    cis[9].quantidade_necessaria = 1;

    cis[10].codigo_produto = 6;
    cis[10].codigo_ingrediente = 7;
    cis[10].quantidade_necessaria = 1;

    cis[11].codigo_produto = 6;
    cis[11].codigo_ingrediente = 9;
    cis[11].quantidade_necessaria = 1;

    cis[12].codigo_produto = 7;
    cis[12].codigo_ingrediente = 1;
    cis[12].quantidade_necessaria = 1;

    cis[13].codigo_produto = 7;
    cis[13].codigo_ingrediente = 4;
    cis[13].quantidade_necessaria = 1;

    cis[14].codigo_produto = 7;
    cis[14].codigo_ingrediente = 5;
    cis[14].quantidade_necessaria = 1;

    endIndex = 14;
}

void criarListas(Categoria* cats, Produto* prods, Ingrediente* ingredientes, Cliente* clientes, Garcom* garcom,
    Pedido* pedido, ItensPedido* ips, ConsumoIngredientes* cis, int &endIndexCategoria, int &endIndexProduto,
    int &endIndexIngredientes ,int &endIndexCliente, int &endIndexGarcom, int &endIndexPedido, int &endIndexIps, int &endIndexCis)
{
    criarListaCategorias(cats, endIndexCategoria);
    criarListaProdutos(prods, endIndexProduto);
    criarListaIngredientes(ingredientes, endIndexIngredientes);
    criarListaClientes(clientes, endIndexCliente);
    criarListaGarcom(garcom, endIndexGarcom);
    criarListaPedido(pedido, endIndexPedido);
    criarListaItensPedidos(ips, endIndexIps);
    criarListaConsumoIngredientes(cis, endIndexCis);
}

// ====================== MÉTODOS FIND ======================

Categoria findCategoria(Categoria* cats, int codCategoria, int endIndex) {
    int inicio = 0;
    int fim = endIndex;
    int meio = (inicio + fim) / 2;

    for (; inicio < fim && codCategoria != cats[meio].codigo; meio = (inicio + fim) / 2) {
        if (cats[meio].codigo > codCategoria) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return cats[meio];
}

Produto findProduto(Produto* produtos, int codProduto, int endIndex) {
    int inicio = 0;
    int fim = endIndex;
    int meio = (inicio + fim) / 2;

    for (; inicio < fim && codProduto != produtos[meio].codigo ; meio = (inicio + fim) / 2) {
        if(produtos[meio].codigo > codProduto) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return produtos[meio];
}

Ingrediente findIngrediente(Ingrediente* ingredientes, int codIngrediente, int endIndex) {
    int inicio = 0;
    int fim = endIndex;
    int meio = (inicio + fim) / 2;

    for (;inicio < fim && codIngrediente != ingredientes[meio].codigo; meio = (inicio + fim) / 2) {
        if (ingredientes[meio].codigo > codIngrediente) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return ingredientes[meio];
}

Cliente findCliente(Cliente* clientes, int codCliente, int endIndex) {
    int inicio = 0;
    int fim = endIndex;
    int meio = (inicio + fim) / 2;

    for (;inicio < fim && codCliente != clientes[meio].codigo; meio = (inicio + fim) / 2) {
        if(clientes[meio].codigo > codCliente) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return clientes[meio];
}

Garcom findGarcom(Garcom* garcons, int codGarcom, int endIndex) {
    int inicio = 0;
    int fim = endIndex;
    int meio = (inicio + fim) / 2;

    for (; inicio < fim && codGarcom != garcons[meio].codigo; meio = (inicio + fim) / 2) {
        if(garcons[meio].codigo > codGarcom) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return garcons[meio];
}

Pedido findPedido(Pedido* pedidos, int codPedido, int endIndex) {
    int inicio = 0;
    int fim = endIndex;
    int meio = (inicio + fim) / 2;

    for (; inicio<fim && codPedido != pedidos[meio].codigo; meio = (inicio + fim) / 2) {
        if(pedidos[meio].codigo > codPedido) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return pedidos[meio];
}

ItensPedido findIps(ItensPedido* ics, int codPedido, int codProduto, int endIndex) {
    ItensPedido result = {-1, -1, 0}; // mock return
    return result;
}

ItensPedido findCis(ConsumoIngredientes* cis, int codPedido, int codIngrediente, int endIndex) {
    ItensPedido result = {-1, -1, 0}; // mock return
    return result;
}

void findCisByProdutos(ConsumoIngredientes* cis, int endIndexCis, int codProduto, ConsumoIngredientes *cisRetorno, int &endIndexCisRetorno) {
    if (cisRetorno[endIndexCisRetorno].codigo_ingrediente != 0) {
        endIndexCisRetorno++;
    }
    for (int i = 0; i<=endIndexCis || cis[i].codigo_produto <= codProduto; i++) {
        if (cis[i].codigo_produto == codProduto) {
            cisRetorno[endIndexCisRetorno] = cis[i];
            endIndexCisRetorno++;
        }
    }
    endIndexCisRetorno = endIndexCisRetorno - 1;
}

//1. Escreva funções específicas para a leitura dos dados das estruturas: Categorias, Produtos e Ingredientes.

void lerCategoria (struct Categoria cat[], int &contCAT){
    int i = 0;
    cout << "-_-_-_- LEITURA CATEGORIA -_-_-_-";
    for (int saida = 1; i < 1000 && saida != 0; i++){
        cout << "\n\nCodigo da Categoria " << (i+1) << ": ";
        cin >> cat[i].codigo;
        if (cat[i].codigo > 0){
            cout << "Descricao: ";
            getline(cin >> ws, cat[i].descricao);
        }
        else saida = 0;
    }
    contCAT = i-1;
}

void lerProduto(struct Produto prod[], int &contPROD) {
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

void lerIngrediente(struct Ingrediente ing[], int &contING) {
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

void lerCliente(struct Cliente cli[], int &contCLI) {
    int i = 0;
    cout << "-_-_-_- LER CLIENTE -_-_-_-";
    for (int saida = 1; i < 1000 && saida != 0; i++) {
        int tempCodigo;
        cout << "\nCodigo do Cliente " << (i + 1) << " (Digite 0 para sair): ";
        cin >> tempCodigo;
        if (tempCodigo > 0) {
            bool existe = false;
            for (int j = 0; j < i; j++) {
                if (cli[j].codigo == tempCodigo) {
                    existe = true;
                    break;
                }
            }
            if (!existe) {
                cli[i].codigo = tempCodigo;
                cout << "Nome: ";
                getline(cin >> ws, cli[i].nome);
                cout << "Telefone: ";
                cin >> cli[i].telefone;

                i++;
            } else {
                cout << "Codigo ja cadastrado no sistema!";
            }
        }
        else saida = 0;
    }
    contCLI = i - 1;
}

void lerGarcom(struct Garcom garcom[], int &contGARCOM) {
    int i = 0;
    cout << "-_-_-_- LER GARCOM -_-_-_-";
    for (int saida = 1; i < 1000 && saida != 0; i++) {
        int tempCodigo;
        cout << "\nCodigo do Garcom " << (i + 1) << " (Digite 0 para sair): ";
        cin >> tempCodigo;
        if (tempCodigo > 0) {
            bool existe = false;
            for (int j = 0; j < i; j++) {
                if (garcom[j].codigo == tempCodigo) {
                    existe = true;
                    break;
                }
            }
            if (!existe) {
                garcom[i].codigo = tempCodigo;
                cout << "Nome: ";
                getline(cin >> ws, garcom[i].nome);
                i++;
            } else {
                cout << "Codigo ja cadastrado no sistema!";
            }
        }
        else saida = 0;
    }
    contGARCOM = i - 1;
}

//2. Escreva uma função para permitir a inclusão de novos registros na tabela de Clientes.
//2.1) O programa deverá garantir que o código do cliente a ser inserido não existe na tabela de Clientes.
//
//3. Escreva uma função para permitir a inclusão de novos registros na tabela de Garçons.
//3.1) O programa deverá garantir que o código do garçom a ser inserido não existe na tabela de Garçons.


void incluirCliente(struct Cliente S[], int contS, struct Cliente T[], int contT, struct Cliente A[], int &contA) {
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
            A[k].nome = S[i].nome;
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

void incluirCategoria(struct Categoria S[], int contS, struct Categoria T[], int contT, struct Categoria A[], int &contA) {
    int i = 0, j = 0, k = 0;
    for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].descricao = S[i].descricao;
            i++;
        }
        else if (T[j].codigo < S[i].codigo){
            A[k].codigo = T[j].codigo;
            A[k].descricao = T[j].descricao;
            j++;
        } else {
            A[k].codigo = S[i].codigo;
            A[k].descricao = S[i].descricao;
            i++;
            j++;
        }}

    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].descricao = S[i].descricao;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].descricao = T[j].descricao;
        j++;
        k++;
    }
    contA = k;
}

void incluirProduto(struct Produto S[], int contS, struct Produto T[], int contT, struct Produto A[], int &contA) {
    int i = 0, j = 0, k = 0;
    for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].descricao = S[i].descricao;
            A[k].codigo_categoria = S[i].codigo_categoria;
            A[k].preco_unitario = S[i].preco_unitario;
            i++;
        }
        else if (T[j].codigo < S[i].codigo){
            A[k].codigo = T[j].codigo;
            A[k].descricao = T[j].descricao;
            A[k].codigo_categoria = T[j].codigo_categoria;
            A[k].preco_unitario = T[j].preco_unitario;
            j++;
        } else {
            A[k].codigo = S[i].codigo;
            A[k].descricao = S[i].descricao;
            A[k].codigo_categoria = S[i].codigo_categoria;
            A[k].preco_unitario = S[i].preco_unitario;
            i++;
            j++;
        }}

    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].descricao = S[i].descricao;
        A[k].codigo_categoria = S[i].codigo_categoria;
        A[k].preco_unitario = S[i].preco_unitario;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].descricao = T[j].descricao;
        A[k].codigo_categoria = T[j].codigo_categoria;
        A[k].preco_unitario = T[j].preco_unitario;
        j++;
        k++;
    }
    contA = k;
}

void incluirIngredientes(struct Ingrediente S[], int contS, struct Ingrediente T[], int contT, struct Ingrediente A[], int &contA) {
    int i = 0, j = 0, k = 0;
    for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].descricao = S[i].descricao;
            A[k].quant_estoque = S[i].quant_estoque;
            A[k].estoque_minimo = S[i].estoque_minimo;
            A[k].estoque_maximo = S[i].estoque_maximo;
            i++;
        }
        else if (T[j].codigo < S[i].codigo){
            A[k].codigo = T[j].codigo;
            A[k].descricao = T[j].descricao;
            A[k].quant_estoque = T[j].quant_estoque;
            A[k].estoque_minimo = T[j].estoque_minimo;
            A[k].estoque_maximo = T[j].estoque_maximo;
            j++;
        } else {
            A[k].codigo = S[i].codigo;
            A[k].descricao = S[i].descricao;
            A[k].quant_estoque = S[i].quant_estoque;
            A[k].estoque_minimo = S[i].estoque_minimo;
            A[k].estoque_maximo = S[i].estoque_maximo;
            i++;
            j++;
        }}

    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].descricao = S[i].descricao;
        A[k].quant_estoque = S[i].quant_estoque;
        A[k].estoque_minimo = S[i].estoque_minimo;
        A[k].estoque_maximo = S[i].estoque_maximo;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].descricao = T[j].descricao;
        A[k].quant_estoque = T[j].quant_estoque;
        A[k].estoque_minimo = T[j].estoque_minimo;
        A[k].estoque_maximo = T[j].estoque_maximo;
        j++;
        k++;
    }
    contA = k;
}

void incluirGarcom(struct Garcom S[], int contS, struct Garcom T[], int contT, struct Garcom A[], int &contA) {
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
            A[k].nome = S[i].nome;
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


// 4. Escreva uma função para permitir a exclusão de registros da tabela de Produtos.

void removerProduto(Produto* produtos, int endIndexProdutos, int* codsProdutosExclusao, int endIndexExclusao, Produto* listaFinal, int &contFinal) {
    int i = 0;
    int j = 0;
    int k = 0;

    for (; j <= endIndexExclusao || i <= endIndexProdutos; i++) {
        if (produtos[i].codigo != codsProdutosExclusao[j]) {
            listaFinal[k] = produtos[i];
            k++;
        } else {
            j++;
        }
    }
    contFinal = k - 1;
}

//5. Escreva uma função para permitir o registro de um novo Pedido.
//5.1) Quando o usuário digitar o código do cliente, o programa deverá buscar este código na tabela de Clientes e exibir o nome do cliente.
//5.2) Quando o usuário digitar o código do garçom, o programa deverá buscar este código na tabela de Garçons e exibir o nome do garçom.
//5.3) O programa deverá permitir a inclusão de um único produto para cada pedido, conforme orientações do item 6.


Pedido createPedido(Cliente *clientes, int endIndexCliente, Garcom *garcons, int endIndexGarcom, Pedido *pedidos, int endIndexPedidos) {
    int idCliente = 0;
    int idGarcom = 0;
    Cliente c;
    Garcom g;
    Pedido p;

    cout << "\n<=====Adicionar novo pedido=====>" << endl;

    cout << "\n\nDigite o codigo do pedido: ";
    cin >> p.codigo;
    Pedido p2 = findPedido(pedidos, p.codigo, endIndexPedidos);

    if (p2.codigo == p.codigo) {
        cout << "\n\nCodigo repetido;" << endl;
    } else {
        cout << "\nDigite o codigo do Cliente: ";
        cin >> idCliente;
        c = findCliente(clientes, idCliente, endIndexCliente);
        cout << "\n\nNome do cliente: " << c.nome << endl;

        cout << "\nDigite o codigo do Garcom: ";
        cin >> idGarcom;
        g = findGarcom(garcons, idGarcom, endIndexGarcom);
        cout << "\n\nNome do garcom: " << g.nome << endl;

        cout <<"\n\nDigite a data[dd/mm/yyyy]: ";
        cin >> p.data;
        p.codigo_cliente = c.codigo;
        p.codigo_garcom = g.codigo;

        return p;
    }
    return p;
}

void inserirPedido(Pedido* pedidos, int endIndexPedido, Cliente *clientes, int endIndexCliente, Garcom *garcons, int endIndexGarcom, Pedido *pedidoResultado, int &endIndexResultado) {
    char confirma = 'S';
    do {
        Pedido p = createPedido(clientes, endIndexCliente, garcons, endIndexGarcom, pedidos, endIndexPedido);

        for (int i = 0; i < endIndexPedido; i++) {
            if (p.codigo > pedidos[i].codigo) {
                pedidoResultado[i] = pedidos[i];
                endIndexResultado++;
            }
            if (p.codigo < pedidos[i].codigo) {
                pedidoResultado[i] = p;
                endIndexResultado++;
            }
        }

        cout << "\n\nPedido Adicionado!!!";
        cout << "\nDeseja adicionar outro pedido?[S/N]: ";
        cin >> confirma;
    } while (confirma == 'S' || confirma == 's');
}

//6. Escreva uma função para permitir a inclusão de produtos em um pedido.
//6.1) Quando o usuário digitar o código do produto, o programa deverá buscar este código na tabela de Produtos e exibir a descrição e o preço unitário.
//6.2) Para cada produto selecionado, o programa deverá verificar na estrutura de Consumo de Ingredientes quais ingredientes são necessários.
//6.3) Para cada ingrediente necessário:
//     Mostrar a descrição do ingrediente
//     Verificar se a quantidade em estoque é suficiente
//     O programa não deverá permitir a inclusão do item caso algum ingrediente não tenha quantidade suficiente
//6.4) Caso seja possível preparar o produto, o programa deverá subtrair do estoque a quantidade necessária de cada ingrediente



ItensPedido inserirProdutoNoPedido(int pedido, int produto, int qtde) {
    ItensPedido i;
    i.codigo_pedido = pedido;
    i.codigo_produto = produto;
    i.quantidade = qtde;
    return i;
}

void incluirItensPedido(ItensPedido* ips, int &endIndexIps, ItensPedido ipIncluir) {
    ItensPedido ips2[100];
    int i = 0;
    int k = 0;
    int j = 0;

    for (; j <= endIndexIps && k == 0; i++) {
        if (ips[j].codigo_pedido < ipIncluir.codigo_pedido) {
            ips2[i].codigo_pedido = ips[j].codigo_pedido;
            ips2[i].codigo_produto = ips[j].codigo_produto;
            ips2[i].quantidade = ips[j].quantidade;
            j++;
        } else if (ips[j].codigo_pedido > ipIncluir.codigo_pedido) {
            ips2[i].codigo_produto = ipIncluir.codigo_produto;
            ips2[i].codigo_pedido = ipIncluir.codigo_pedido;
            ips2[i].quantidade = ipIncluir.quantidade;
            k++;
        } else {
            if (ips[j].codigo_produto < ipIncluir.codigo_produto) {
                ips2[i].codigo_pedido = ips[j].codigo_pedido;
                ips2[i].codigo_produto = ips[j].codigo_produto;
                ips2[i].quantidade = ips[j].quantidade;
                j++;
            } else {
                ips2[i].codigo_produto = ipIncluir.codigo_produto;
                ips2[i].codigo_pedido = ipIncluir.codigo_pedido;
                ips2[i].quantidade = ipIncluir.quantidade;
                k++;
            }
        }
    }
    while (j <= endIndexIps) {
        ips2[i].codigo_pedido = ips[j].codigo_pedido;
        ips2[i].codigo_produto = ips[j].codigo_produto;
        ips2[i].quantidade = ips[j].quantidade;
        i++;
        j++;
    }
    while (k == 0) {
        ips2[i].codigo_produto = ipIncluir.codigo_produto;
        ips2[i].codigo_pedido = ipIncluir.codigo_pedido;
        ips2[i].quantidade = ipIncluir.quantidade;
        i++;
        j++;
    }

    endIndexIps++;
    for (int u = 0; u <= endIndexIps; u++) {
        ips[u] = ips2[u];
    }
}

void consumirIngredientes(ConsumoIngredientes &ci, Ingrediente &in, bool &resultado, int qtde) {
    int quantConsumida = (ci.quantidade_necessaria * qtde);

    if (quantConsumida > in.quant_estoque) {
        cout << "Voce nao possui estoque suficiente nesse ingrediente." << endl;
        resultado = false;
    } else if ((in.quant_estoque - quantConsumida) <= in.estoque_minimo) {
        cout << "ATENCAO! Ingrediente abaixo do estoque minimo." << endl;
        in.quant_estoque = in.quant_estoque - quantConsumida;
    } else {
        in.quant_estoque = in.quant_estoque - quantConsumida;
    }
}


//7. Escreva uma função para permitir ao usuário consultar os dados de determinado ingrediente.
//7.1) Para cada ingrediente consultado, exibir:
//     Todos os seus dados
//     O valor total em estoque (quant_estoque × preço_unitario)

void consultarIngrediente(struct Ingrediente S[], int tamanho) {
    char confirma = 'S';
    do {
        int cod = 0;
        cout << "\nSelecione o codigo do ingrediente que deseja consultar:" << endl;
        for (int i = 0; i < tamanho; i++) {
            cout << S[i].codigo << " - " << S[i].descricao << endl;
        }
        cout << "Escolha: ";
        cin >> cod;
        Ingrediente ingredienteEncontrado = findIngrediente(S, cod, tamanho - 1);
        if (ingredienteEncontrado.codigo == cod) {
            cout << "\n--- DADOS DO INGREDIENTE ---" << endl;
            cout << "Codigo: " << ingredienteEncontrado.codigo << endl;
            cout << "Descricao: " << ingredienteEncontrado.descricao << endl;
            cout << "Quantidade estoque: " << ingredienteEncontrado.quant_estoque << endl;
            cout << "Estoque minimo: " << ingredienteEncontrado.estoque_minimo << endl;
            cout << "Estoque maximo: " << ingredienteEncontrado.estoque_maximo << endl;
            cout << "Preco unitario R$: " << ingredienteEncontrado.preco_unitario << endl;
            cout << "Valor total em estoque R$: " << (ingredienteEncontrado.quant_estoque * ingredienteEncontrado.preco_unitario) << endl;
            cout << "----------------------------\n" << endl;
        } else {
            cout << "\nIngrediente com codigo " << cod << " nao encontrado!\n" << endl;
        }

        cout << "Deseja consultar mais ingredientes? (S/N): ";
        cin >> confirma;

    } while (confirma == 's' || confirma == 'S');
}

//8. Escreva uma função para exibir todos os ingredientes que estejam com a quantidade em estoque abaixo do estoque mínimo.
//8.1) As seguintes informações devem ser exibidas: Código, Descrição, Quantidade em estoque, Estoque máximo, Quantidade a ser comprada, Valor da compra
//8.1.1) A quantidade a ser comprada é calculada pela diferença entre o estoque máximo e a quantidade em estoque
//8.2) Ao final, a função deverá exibir o valor total a ser gasto na reposição de ingredientes

void exibirMinimo(struct Ingrediente S[], int tamanho) {
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

void valorTotal(Pedido pedidos[], int contPedidos, ItensPedido itens[], int contItens, Produto produtos[], int contProdutos) {
    double totalGeral = 0;
    cout << "\n--- RELATORIO DE ARRECADACAO ---" << endl;

    for (int i = 0; i < contPedidos; i++) {
        double valorPedido = 0;
        for (int j = 0; j < contItens; j++) {
            if (itens[j].codigo_pedido == pedidos[i].codigo) {
                Produto prod = findProduto(produtos, itens[j].codigo_produto, contProdutos - 1);
                valorPedido += prod.preco_unitario * itens[j].quantidade;
            }
        }
        cout << "Pedido " << pedidos[i].codigo << " - Valor R$: " << valorPedido << endl;
        totalGeral += valorPedido;
    }

    cout << "--------------------------------" << endl;
    cout << "Valor total R$: " << totalGeral << endl;
}

// Telas

//TELAS 1, 2 E 3


void telaInserirCategoria(Categoria* categoriasPrincipais, int &endIndexCategorias) {
    Categoria categoriasNovos[1000];
    int endIndexNovos = -1;
    char confirma = 'S';

    do {
        cout << "\n\n<===================== NOVO CADASTRO CATEGORIA =====================>\n";

        lerCategoria(categoriasNovos, endIndexNovos);

        cout << "\n\nDeseja adicionar outra categoria? [S/N]: ";
        cin >> confirma;
    } while (confirma == 's' || confirma == 'S');


    if (endIndexNovos >= 0) {
        Categoria categoriasAtualizados[2000];
        int quantidadeAtualizados = 0;

        int quantPrincipais = endIndexCategorias + 1;
        int quantNovos = endIndexNovos + 1;

        incluirCategoria(categoriasPrincipais, quantPrincipais,
                       categoriasNovos, quantNovos,
                       categoriasAtualizados, quantidadeAtualizados);

        for (int i = 0; i < quantidadeAtualizados; i++) {
            categoriasPrincipais[i] = categoriasAtualizados[i];
        }

        endIndexCategorias = quantidadeAtualizados - 1;

        cout << "\n[Sucesso] " << quantNovos << " Categoria(s) adicionada(s) e ordenado(s) na base principal!" << endl;
    } else {
        cout << "\n[Aviso] Nenhuma categoria nova foi cadastrado." << endl;
    }
}

void telaInserirProduto(Produto* produtosPrincipais, int &endIndexProdutos) {
    Produto produtosNovos[1000];
    int endIndexNovos = -1;
    char confirma = 'S';

    do {
        cout << "\n\n<===================== NOVO CADASTRO PRODUTO =====================>\n";

        lerProduto(produtosNovos, endIndexNovos);

        cout << "\n\nDeseja adicionar outro produto? [S/N]: ";
        cin >> confirma;
    } while (confirma == 's' || confirma == 'S');


    if (endIndexNovos >= 0) {
        Produto produtosAtualizados[2000];
        int quantidadeAtualizados = 0;

        int quantPrincipais = endIndexProdutos + 1;
        int quantNovos = endIndexNovos + 1;

        incluirProduto(produtosPrincipais, quantPrincipais,
                       produtosNovos, quantNovos,
                       produtosAtualizados, quantidadeAtualizados);

        for (int i = 0; i < quantidadeAtualizados; i++) {
            produtosPrincipais[i] = produtosAtualizados[i];
        }

        endIndexProdutos = quantidadeAtualizados - 1;

        cout << "\n[Sucesso] " << quantNovos << " Produto(s) adicionado(s) e ordenado(s) na base principal!" << endl;
    } else {
        cout << "\n[Aviso] Nenhum produto novo foi cadastrado." << endl;
    }
}


void telaInserirIngrediente(Ingrediente* ingredientesPrincipais, int &endIndexIngredientes) {
    Ingrediente ingredientesNovos[1000];
    int endIndexNovos = -1;
    char confirma = 'S';

    do {
        cout << "\n\n<===================== NOVO CADASTRO INGREDIENTE =====================>\n";

        lerIngrediente(ingredientesNovos, endIndexNovos);

        cout << "\n\nDeseja adicionar outro ingrediente? [S/N]: ";
        cin >> confirma;
    } while (confirma == 's' || confirma == 'S');


    if (endIndexNovos >= 0) {
        Ingrediente ingredientesAtualizados[2000];
        int quantidadeAtualizados = 0;

        int quantPrincipais = endIndexIngredientes + 1;
        int quantNovos = endIndexNovos + 1;

        incluirIngrediente(ingredientesPrincipais, quantPrincipais,
                       ingredientesNovos, quantNovos,
                       ingredientesAtualizados, quantidadeAtualizados);

        for (int i = 0; i < quantidadeAtualizados; i++) {
            ingredientesPrincipais[i] = ingredientesAtualizados[i];
        }

        endIndexIngredientes = quantidadeAtualizados - 1;

        cout << "\n[Sucesso] " << quantNovos << " Ingrediente(s) adicionado(s) e ordenado(s) na base principal!" << endl;
    } else {
        cout << "\n[Aviso] Nenhum Ingrediente novo foi cadastrado." << endl;
    }
}


void telaInserirCliente(Cliente* clientesPrincipais, int &endIndexClientes) {
    Cliente clientesNovos[1000];
    int endIndexNovos = -1;
    char confirma = 'S';

    do {
        cout << "\n\n<===================== NOVO CADASTRO CLIENTE =====================>\n";

        lerCliente(clientesNovos, endIndexNovos);

        cout << "\n\nDeseja adicionar outro cliente? [S/N]: ";
        cin >> confirma;
    } while (confirma == 's' || confirma == 'S');


    if (endIndexNovos >= 0) {
        Cliente clientesAtualizados[2000];
        int quantidadeAtualizados = 0;

        int quantPrincipais = endIndexClientes + 1;
        int quantNovos = endIndexNovos + 1;

        incluirCliente(clientesPrincipais, quantPrincipais,
                       clientesNovos, quantNovos,
                       clientesAtualizados, quantidadeAtualizados);

        for (int i = 0; i < quantidadeAtualizados; i++) {
            clientesPrincipais[i] = clientesAtualizados[i];
        }

        endIndexClientes = quantidadeAtualizados - 1;

        cout << "\n[Sucesso] " << quantNovos << " cliente(s) adicionado(s) e ordenado(s) na base principal!" << endl;
    } else {
        cout << "\n[Aviso] Nenhum cliente novo foi cadastrado." << endl;
    }
}


void telaInserirGarcom(Garcom* garconsPrincipais, int &endIndexGarcoms) {
    Garcom garconsNovos[1000];
    int endIndexNovos = -1;
    char confirma = 'S';

    do {
        cout << "\n\n<===================== NOVO CADASTRO GARCOM =====================>\n";

        lerGarcom(garconsNovos, endIndexNovos);

        cout << "\n\nDeseja adicionar outro garçom? [S/N]: ";
        cin >> confirma;
    } while (confirma == 's' || confirma == 'S');


    if (endIndexNovos >= 0) {
        Garcom garconsAtualizados[2000];
        int quantidadeAtualizados = 0;

        int quantPrincipais = endIndexGarcoms + 1;
        int quantNovos = endIndexNovos + 1;

        incluirGarcom(garconsPrincipais, quantPrincipais,
                       garconsNovos, quantNovos,
                       garconsAtualizados, quantidadeAtualizados);

        for (int i = 0; i < quantidadeAtualizados; i++) {
            garconsPrincipais[i] = garconsAtualizados[i];
        }

        endIndexGarcoms = quantidadeAtualizados - 1;

        cout << "\n[Sucesso] " << quantNovos << " garçom(ns) adicionado(s) e ordenado(s) na base principal!" << endl;
    } else {
        cout << "\n[Aviso] Nenhum garçom novo foi cadastrado." << endl;
    }
}

//TELA 4

//TELA 5

//TELA 6
void telaInserirProdutoNoPedido(Produto *produtos, int endIndexProduto, Categoria *categorias, int endIndexCategorias, ItensPedido *ips, int &endIndexIps, ConsumoIngredientes *cis, int endIndexCis, Ingrediente *ingredientes, int endIndexIngredientes) {
    Produto *produtosIncluidos[100];
    int endIndexProdutoIncluidos = 0;
    Produto produtoIncluido;
    ItensPedido i;
    char confirma = 'S';
    int codPedido = 0;
    int codProduto = 0;

    do {
        int qtde = 0;

        cout << "\n\nDigite o codigo do Pedido: ";
        cin >> codPedido;
        cout << "\n\nDigite o codigo do Produto: ";
        cin >> codProduto;

        Produto p = findProduto(produtos, codProduto, endIndexProduto);

        cout << "\n\n<===========================Produto Adicionado===========================>\n";
        cout << "Codigo do produto: " << p.codigo << endl;
        cout << "Nome do produto: " << p.descricao << endl;

        Categoria c = findCategoria(categorias, p.codigo_categoria, endIndexCategorias);

        cout << "Categoria: " << c.descricao  << endl;
        cout << "Valor: " << p.preco_unitario << endl;

        cout << "\n\nDigite a quantidade de produtos no pedido: ";
        cin >> qtde;

        produtosIncluidos[endIndexProdutoIncluidos] = &p;
        endIndexProdutoIncluidos++;

        cout << "\n\n<===========================Ingrediente Adicionado===========================>\n\n";

        ConsumoIngredientes cisRetorno[100];
        int endIndexCisRetorno = 0;

        findCisByProdutos(cis, endIndexCis, p.codigo, cisRetorno, endIndexCisRetorno);

        bool resultado = true;
        int j = 0;
        for (int u = 0; u <= endIndexIngredientes && resultado != false; u++) {
            if (ingredientes[u].codigo == cisRetorno[j].codigo_ingrediente) {
                cout << "Ingrediente Consumido: " << ingredientes[u].descricao << endl;
                cout << "Estoque do ingrediente: " << ingredientes[u].quant_estoque << endl;
                cout << "Quantidade consumida: " << cisRetorno[j].quantidade_necessaria * qtde << endl;

                consumirIngredientes(cisRetorno[j], ingredientes[u], resultado, qtde);

                if (resultado == false) {
                    cout << "\nTente outro produto\n\n" << endl;
                } else {
                    cout << "\n\nProduto adicionado com sucesso" << endl;
                    i = inserirProdutoNoPedido(codPedido, codProduto, qtde);
                    incluirItensPedido(ips, endIndexIps, i);
                }
                j++;

                cout << "Estoque Final: " << ingredientes[u].quant_estoque << endl;
            }
        }

        cout << "\n\nDeseja adicionar outro produto a um pedido[S/N]: ";
        cin >> confirma;
    } while (confirma == 'S' || confirma == 's');

    cout << i.codigo_pedido << endl;
    cout << i.codigo_produto << endl;
}

// TELA 7 - não precisa, ja tem do-while
// TELA 8 - Não tem escolha, ele apenas exibe
