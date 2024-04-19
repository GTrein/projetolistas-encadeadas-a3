#include "ListaEncadeada.h"

ListaEncadeada listaUrgenciaV;
ListaEncadeada listaUrgenciaA;


void Executar();

int main() {
    setlocale(LC_ALL, "Portuguese");
    Executar();
    return 0;
}

void TrocarPacienteLista(string nome) {
    if (listaUrgenciaV.verificarPaciente(nome)) {
        listaUrgenciaV.moverPacienteEntreListas(listaUrgenciaV, listaUrgenciaA, nome);
    }
    else if (listaUrgenciaA.verificarPaciente(nome)) {
        listaUrgenciaA.moverPacienteEntreListas(listaUrgenciaA, listaUrgenciaV, nome);
    }
}

void TrocarListaDoPaciente() {
    string nomePaciente;
    cout << "Digite o nome do paciente que deseja trocar de lista: ";
    cin >> nomePaciente;
    TrocarPacienteLista(nomePaciente);
}

void AdicionarPacientes() {
    char escolha;
    string nome;
    cout << "Qual o nome do paciente?\n";
    cin >> nome;
    cout << "Qual o grau de urgencia?(A ou V)\n";
    cin >> escolha;
    switch (toupper(escolha)) {
    case 'V':
        listaUrgenciaV.inserirPaciente(nome, listaUrgenciaV.tamanho() + 1);
        break;
    case 'A':
        listaUrgenciaA.inserirPaciente(nome, listaUrgenciaA.tamanho() + 1);
        break;
    default:
        cout << "opcao invalida, o paciente nao foi adicionado.\n";
        return;
    }
    cout << "O Paciente " << nome << " adicionado com sucesso a lista " << escolha << endl;
}

void VerListasSeparadas() {
    char escolha;
    cout << "Qual lista voce quer ver?(A ou V)\n";
    cin >> escolha;
    switch (toupper(escolha)) {
    case 'V':
        cout << "Grau de urgencia leve(V):\n";
        listaUrgenciaV.exibirPacientes();
        break;
    case 'A':
        cout << "Grau de urgencia moderado(A):\n";
        listaUrgenciaA.exibirPacientes();
        break;
    default:
        cout << "Lista invalida.\n";
        return;
    }
}

void VerTamanhoLista() {
    char escolha;
    cout << "Qual fila voce quer ver o tamanho?(A ou V)\n";
    cin >> escolha;
    switch (toupper(escolha)) {
    case 'V':
        cout << "A fila V esta com " << listaUrgenciaV.tamanho() << " pacientes esperando.\n";
        break;
    case 'A':
        cout << "A fila A esta com " << listaUrgenciaA.tamanho() << " pacientes esperando.\n";
        break;
    default:
        cout << "Fila invalida.\n";
        return;
    }
}

void RemoverPaciente2() {
    string nome;
    cout << "Qual o nome do paciente que você deseja remover?\n";
    cin >> nome;
    listaUrgenciaV.removerPacienteNaLista(listaUrgenciaV, nome);
    cout << " verde.\n";
    listaUrgenciaA.removerPacienteNaLista(listaUrgenciaA, nome);
    cout << " amarela.\n";
}

void VerListas() {
    cout << "Grau de urgencia moderado(A):\n";
    listaUrgenciaA.exibirPacientes();
    cout << "Grau de urgencia leve(V):\n";
    listaUrgenciaV.exibirPacientes();
}

void BuscarPaciente() {
    string nomePaciente;
    cout << "Digite o nome do paciente que deseja buscar: ";
    cin >> nomePaciente;
    listaUrgenciaV.buscarPacienteNasListas(listaUrgenciaV, listaUrgenciaA, nomePaciente);
}

int MenuInicial() {
    int escolha;
    system("cls");
    cout << "===== Menu =====\n";
    cout << "1 - Cadastrar Paciente.\n";
    cout << "2 - Remover Paciente.\n";
    cout << "3 - Pesquisar Paciente.\n";
    cout << "4 - Ver as listas.\n";
    cout << "5 - Ver uma das listas.\n";
    cout << "6 - Tamanho da lista.\n";
    cout << "7 - Trocar paciente de lista.\n";
    cout << "8 - Sair.\n";
    cin >> escolha;
    return escolha;
}

void Executar() {
    int escolha;
    do {
        escolha = MenuInicial();

        switch (escolha) {
        case 1:
            //cadastrar paciente
            AdicionarPacientes();
            system("pause");
            break;
        case 2:
            //remover paciente
            RemoverPaciente2();
            system("pause");
            break;
        case 3:
            //procurar paciente
            BuscarPaciente();
            system("pause");
            break;
        case 4:
            //vizualisar as duas listas
            VerListas();
            system("pause");
            break;
        case 5:
            //ver lista unica
            VerListasSeparadas();
            system("pause");
            break;
        case 6:
            //consultar tamanho da lista
            VerTamanhoLista();
            system("pause");
            break;
        case 7:
            //alterar paciente
            TrocarListaDoPaciente();
            system("pause");
            break;
        case 8:
            //encerrar programa
            break;
        default:
            cout << "Escolha inválida.\n";
            Sleep(100);
            break;
        }
    } while (escolha != 8);
}
