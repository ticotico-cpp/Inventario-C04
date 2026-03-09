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

int main() {
    char cmd;
    setlocale(LC_ALL, "pt_BR.UTF-8");
    string inicio = "Olá! Bem vindo ao sistema de gerenciamento de itens mágicos! Escolha uma opção:\na. Inserir item;\nb. Cadastrar similaridade entre itens;\nc. Buscar itens similares;\nd. Verificar a existência de um item;\ne. Listar itens (ordem alfabética de nome);\nf. Listar itens (ordem decrescente de raridade);\ng. Contar itens com mesma propriedade mágica;\nh. Remover itens menos raros;\nx. Sair do programa.\nEscolha: ";
    while(cout << inicio && cin >> cmd) {
        switch (cmd) {
            case 'a':
                cout << endl << "Função em construção" << endl << endl;
                break;
            case 'b':
                cout << endl << "Função em construção" << endl << endl;
                break;
            case 'c':
                cout << endl << "Função em construção" << endl << endl;
                break;
            case 'd':
                cout << endl << "Função em construção" << endl << endl;
                break;
            case 'e':
                cout << endl << "Função em construção" << endl << endl;
                break;
            case 'f':
                cout << endl << "Função em construção" << endl << endl;
                break;
            case 'g':
                cout << endl << "Função em construção" << endl << endl;
                break;
            case 'h':
                cout << endl << "Função em construção" << endl << endl;
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