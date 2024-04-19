#include "ListaEncadeada.h"

string toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { return toupper(c); });
    return str;
}

Paciente::Paciente(string nome, int posicao) : nome(nome), posicao(posicao) {}

Node::Node(Paciente paciente) : paciente(paciente), next(nullptr) {}

ListaEncadeada::ListaEncadeada() : head(nullptr) {}

void ListaEncadeada::inserirPaciente(string nome, int posicao) {
    Paciente novoPaciente(nome, posicao);
    Node* newNode = new Node(novoPaciente);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void ListaEncadeada::exibirPacientes() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->paciente.posicao << ": " << temp->paciente.nome << endl;
        temp = temp->next;
    }
}

int ListaEncadeada::tamanho() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool ListaEncadeada::verificarPaciente(string nome) {
    nome = toUpper(nome);
    Node* temp = head;
    while (temp != nullptr) {
        if (toUpper(temp->paciente.nome) == nome) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void ListaEncadeada::moverPacienteEntreListas(ListaEncadeada& listaOrigem, ListaEncadeada& listaDestino, string nomePaciente) {
    if (!listaOrigem.verificarPaciente(nomePaciente)) {
        cout << "Paciente " << nomePaciente << " não encontrado na lista de origem." << endl;
        return;
    }

    listaOrigem.removerPacienteNaLista(listaOrigem, nomePaciente);
    listaDestino.inserirPaciente(nomePaciente, listaDestino.tamanho() + 1);

    cout << "Paciente " << nomePaciente << " movido com sucesso para a lista de destino." << endl;
}

void ListaEncadeada::removerPacienteNaLista(ListaEncadeada& lista, string nome) {
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && toUpper(temp->paciente.nome) == toUpper(nome)) {
        head = temp->next;
        delete temp;
        cout << "Paciente " << nome << " removido com sucesso da lista ";
        return;
    }

    while (temp != nullptr && toUpper(temp->paciente.nome) != toUpper(nome)) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Paciente " << nome << " não encontrado na lista";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Paciente " << nome << " removido com sucesso da lista ";
}

void ListaEncadeada::buscarPacienteNasListas(ListaEncadeada& listaV, ListaEncadeada& listaA, string nome) {
    Node* tempV = listaV.head;
    Node* tempA = listaA.head;
    bool encontradoV = false;
    bool encontradoA = false;

    while (tempV != nullptr && !encontradoV) {
        if (toUpper(tempV->paciente.nome) == toUpper(nome)) {
            encontradoV = true;
        }
        tempV = tempV->next;
    }

    while (tempA != nullptr && !encontradoA) {
        if (toUpper(tempA->paciente.nome) == toUpper(nome)) {
            encontradoA = true;
        }
        tempA = tempA->next;
    }

    if (encontradoV) {
        cout << "Paciente " << nome << " encontrado na lista de grau de urgência leve (V)" << endl;
    }
    if (encontradoA) {
        cout << "Paciente " << nome << " encontrado na lista de grau de urgência moderado (A)" << endl;
    }

    if (!encontradoV && !encontradoA) {
        cout << "Paciente " << nome << " não encontrado em nenhuma das listas" << endl;
    }
}
