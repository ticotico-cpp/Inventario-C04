/*
Tiago Santiago Bustamante Abreu - 2336
Lucas Vasconcelos Castro - 747
Lucas Caixeta Generoso - 669
Lucas Kazue da Silva Hokari - 2309
Luigi Galina Di Lazzaro - 2317
Bruno Fonseca - 2276
*/
#include <iostream>
#include <string>
#include <clocale>
#include <list>

using namespace std;


struct item {
    int id;
    string nome;
    string dono;
    string propriedade_magica;
    int raridade;
};
struct node{
  item item;
  struct node * left;
  struct node * right;
};
struct Aresta {
    int origem, destino, similaridade;
};
node * root = NULL;
void insert_abb(node * & current, item newItem){
    if(current == NULL){
        current = new node;
        current->item = newItem;
        current->left = NULL;
        current->right = NULL;
    } else if( newItem.nome < current->item.nome ){
        insert_abb(current->left, newItem);
    } else {
        insert_abb(current->right, newItem);
    }
}
node * find_less_save_right(node * & current) {
  if(current->left != NULL) {
    return find_less_save_right(current->left);
  } else {
    node * copy = current;
    current = current->right;
    return copy;
  }
}
bool remove_abb(node * & current, item data){
  if(current == NULL){
    return false;
  } else if(data.id == current->item.id){
    node * temp = current;
    if (current->right == NULL) {
      current = current->left;
    } else if (current->left == NULL) {
      current = current->right;
    } else {
      temp = find_less_save_right(current->right);
      current->item = temp->item;
    }
    delete(temp);
    return true;
  } else {
    if(data.id < current->item.id){
      return remove_abb(current->left, data);
    } else {
      return remove_abb(current->right, data);
    }
  }
}
node * search_abb(node * current, string nome){

    if(current == NULL){
        return NULL;
    } else if(nome == current->item.nome){
        return current;
    } else {
        if(nome < current->item.nome){
        return search_abb(current->left, nome);
        } else {
        return search_abb(current->right, nome);
        }
    }
}
void inserir_item(item itens[], int &quantidade) {
    if (quantidade >= 100) {
        cout << "Inventário cheio!" << endl;
        return;
    }
    item novo;
    novo.id = quantidade;
    cout << "\nItem ID " << novo.id << ":" << endl;
    cout << "Nome: "; getline(cin>>ws, novo.nome);
    cout << "Dono: "; getline(cin>>ws, novo.dono);
    cout << "Raridade: "; cin >> novo.raridade;
    cout << "Propriedade: "; getline(cin>>ws, novo.propriedade_magica);
    itens[quantidade++] = novo;
    insert_abb(root, novo);
    cout << "\nItem inserido com sucesso!\n";
}
void cadastrar_similaridade(list<Aresta> grafo[], int quantidade, item itens[]) {
    Aresta novo;
    cout << "\nID | Nome | Dono | Raridade | Propriedade" << endl;
    if (quantidade == 0) {
        cout << "\nNenhum item cadastrado.\n";
        return;
    }
    for(int i=0; i<quantidade; i++) {
        cout << "-------------------------------------------------------------" << endl;
        cout << itens[i].id << " | " << itens[i].nome << " | " << itens[i].dono << " | " << itens[i].raridade << " | " << itens[i].propriedade_magica << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << "\nItem 1: "; cin >> novo.origem;
    cout << "Item 2: "; cin >> novo.destino;
    cout << "Similaridade: "; cin >> novo.similaridade;
    grafo[novo.origem].push_back(novo);
    grafo[novo.destino].push_back({novo.destino, novo.origem, novo.similaridade});
    cout << "Similaridade adicionada com sucesso!" << endl;
}
void buscar_itens_similares(list<Aresta> grafo[], int quantidade, item itens[]) {
    int codigo, x;
    string jogador;
    bool encontrou = false;

    if (quantidade == 0) {
        cout << "\nNenhum item cadastrado.\n";
        return;
    }

    cout << "\nDigite o código do item de referência: ";
    cin >> codigo;

    if (codigo < 0 || codigo >= quantidade) {
        cout << "Código inválido!\n";
        return;
    }

    cout << "Digite o nome do jogador que deve ser ignorado: ";
    getline(cin >> ws, jogador);

    cout << "Digite o valor mínimo de similaridade X: ";
    cin >> x;

    cout << "\nItens similares ao item " << codigo
         << " com similaridade maior que " << x
         << " e que nao pertencem a " << jogador << ":\n";

    for (list<Aresta>::iterator it = grafo[codigo].begin(); it != grafo[codigo].end(); it++) {
        int destino = it->destino;

        if (it->similaridade > x && itens[destino].dono != jogador) {
            cout << "----------------------------------------\n";
            cout << "ID: " << itens[destino].id << endl;
            cout << "Nome: " << itens[destino].nome << endl;
            cout << "Dono: " << itens[destino].dono << endl;
            cout << "Raridade: " << itens[destino].raridade << endl;
            cout << "Propriedade: " << itens[destino].propriedade_magica << endl;
            cout << "Similaridade: " << it->similaridade << endl;
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "Nenhum item encontrado com esses critérios.\n";
    }
}
void verificar_existencia_item(string nome) {
    node * resultado = search_abb(root, nome);
    if (resultado != NULL) {
        cout << "\nItem encontrado!" << endl;
        cout << "ID: " << resultado->item.id << endl;
        cout << "Nome: " << resultado->item.nome << endl;
        cout << "Dono: " << resultado->item.dono << endl;
        cout << "Raridade: " << resultado->item.raridade << endl;
        cout << "Propriedade: " << resultado->item.propriedade_magica << endl;
    } else {
        cout << "\nItem não encontrado!" << endl;
    }
}
void listar_itens(node * current) {
  if (current != NULL) {
    if (current->left != NULL) {
      listar_itens(current->left);
    }
    cout << "\nID: " << current->item.id << ", nome: " << current->item.nome << "\nDono: " << current->item.dono << "\nRaridade: " << current->item.raridade << " Propriedade: " << current->item.propriedade_magica << endl;
    if (current->right != NULL) {
      listar_itens(current->right);
    }
  }
}

void listar_itens_raridade() {
    cout << "Função em construção" << endl;
}
void contar_itens_propriedade() {
    cout << "Função em construção" << endl;
}
void remover_itens_raros() {
    cout << "Função em construção" << endl;
}

int main() {
    char cmd;
    string nome;
    item itens[100];
    int quantidade = 0;
    list<Aresta> grafo[100];
    setlocale(LC_ALL, "pt_BR.UTF-8");
    string inicio = "\n\nOlá! Bem vindo ao sistema de gerenciamento de itens mágicos! Escolha uma opção:\na. Inserir item;\nb. Cadastrar similaridade entre itens;\nc. Buscar itens similares;\nd. Verificar a existência de um item;\ne. Listar itens (ordem alfabética de nome);\nf. Listar itens (ordem decrescente de raridade);\ng. Contar itens com mesma propriedade mágica;\nh. Remover itens menos raros;\nx. Sair do programa.\nEscolha: ";
    cout << endl;
    while(cout << inicio && cin >> cmd) {
        switch (cmd) {
            case 'a':
                inserir_item(itens, quantidade);
                break;
            case 'b':
                cadastrar_similaridade(grafo, quantidade, itens);
                break;
            case 'c':
                buscar_itens_similares(grafo, quantidade, itens);
                break;
            case 'd':
                cout << "\nDigite o nome do item a ser verificado: ";
                getline(cin >> ws, nome);
                verificar_existencia_item(nome);
                break;
            case 'e':
                listar_itens(root);
                break;
            case 'f':
                listar_itens_raridade();
                break;
            case 'g':
                contar_itens_propriedade();
                break;
            case 'h':
                remover_itens_raros();
                break;
            case 'x':
                cout << endl << "Saindo do programa..." << endl << endl;
                return 0;
            default:
                cout << endl << "Digite um comando válido!" << endl << endl;
                break;
        }
    }
    return 0;
}