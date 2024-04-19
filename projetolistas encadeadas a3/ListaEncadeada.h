#pragma once
#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <algorithm>
#include <cctype>
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <string>

using namespace std;

string toUpper(string str);

struct Paciente {
    string nome;
    int posicao;

    Paciente(string nome, int posicao);
};

struct Node {
    Paciente paciente;
    Node* next;

    Node(Paciente paciente);
};

class ListaEncadeada {
private:
    Node* head;

public:
    ListaEncadeada();

    void inserirPaciente(string nome, int posicao);
    void exibirPacientes();
    int tamanho();
    bool verificarPaciente(string nome);
    void moverPacienteEntreListas(ListaEncadeada& listaOrigem, ListaEncadeada& listaDestino, string nomePaciente);
    void removerPacienteNaLista(ListaEncadeada& lista, string nome);
    void buscarPacienteNasListas(ListaEncadeada& listaV, ListaEncadeada& listaA, string nome);
};

#endif // LISTA_ENCADEADA_H
