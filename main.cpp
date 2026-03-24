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
struct Aresta {
    int origem, destino, similaridade;
};
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
    cout << "\nItem inserido com sucesso!\n";
}
void cadastrar_similaridade(list<Aresta> grafo[], int quantidade, item itens[]) {
    Aresta novo;
    cout << "\nID  Nome           Dono  Raridade  Propriedade" << endl;
    for(int i=0; i<quantidade; i++) {
        cout << "-------------------------------------------------------------" << endl;
        cout << itens[i].id << "   " << itens[i].nome << "   " << itens[i].dono << "  " << itens[i].raridade << "        " << itens[i].propriedade_magica << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << "\nItem 1: "; cin >> novo.origem;
    cout << "Item 2: "; cin >> novo.destino;
    cout << "Similaridade: "; cin >> novo.similaridade;
    grafo[novo.origem].push_back(novo);
    cout << "Similaridade adicionada com sucesso!" << endl;
}
void buscar_itens_similares() {
    cout << "Função em construção" << endl;
}
void verificar_existencia_item() {
    cout << "Função em construção" << endl;
}
void listar_itens() {
    cout << "Função em construção" << endl;
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
                buscar_itens_similares();
                break;
            case 'd':
                verificar_existencia_item();
                break;
            case 'e':
                listar_itens();
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