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

using namespace std;

struct item {
    int id;
    string nome;
    string dono;
    string propriedade_magica;
    int raridade;
    
};
void inserir_item(item itens[], int &quantidade) {
    if (quantidade >= 100) {
        cout << "Inventário cheio!" << endl;
        return;
    }
    item novo;
    novo.id = quantidade + 1;
    cout << "Nome: "; cin >> novo.nome;
    cout << "Dono: "; cin >> novo.dono;
    cout << "Raridade: "; cin >> novo.raridade;
    cout << "Propriedade: "; cin >> novo.propriedade_magica;
    itens[quantidade++] = novo;
    cout << "Item inserido com sucesso!" << endl;
}
void cadastrar_similaridade() {
    cout << "Função em construção" << endl;
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
    setlocale(LC_ALL, "pt_BR.UTF-8");
    string inicio = "Olá! Bem vindo ao sistema de gerenciamento de itens mágicos! Escolha uma opção:\na. Inserir item;\nb. Cadastrar similaridade entre itens;\nc. Buscar itens similares;\nd. Verificar a existência de um item;\ne. Listar itens (ordem alfabética de nome);\nf. Listar itens (ordem decrescente de raridade);\ng. Contar itens com mesma propriedade mágica;\nh. Remover itens menos raros;\nx. Sair do programa.\nEscolha: ";
    while(cout << inicio && cin >> cmd) {
        switch (cmd) {
            case 'a':
                inserir_item(itens, quantidade);
                break;
            case 'b':
                cadastrar_similaridade();
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