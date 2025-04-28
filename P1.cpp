#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;
public:
    Data() {
        dia = 1;
        mes = 1;
        ano = 2006;
    }

    Data(int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }

    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }
};

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato() {}

    Contato(string n, string e, string t, Data d) {
        nome = n;
        email = e;
        telefone = t;
        dtnasc = d;
    }

    string getNome() { return nome; }
    string getEmail() { return email; }
    string getTelefone() { return telefone; }
    Data getData() { return dtnasc; }

    void setNome(string n) { nome = n; }
    void setEmail(string e) { email = e; }
    void setTelefone(string t) { telefone = t; }
    void setData(Data d) { dtnasc = d; }

    int idade() {
        int anoAtual = 2025;
        return anoAtual - dtnasc.getAno(); // simples
    }
};

string paraMaiusculas(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = toupper(texto[i]);
    }
    return texto;
}

string formatarNomeCitacao(const string& nomeCompleto) {
    vector<string> partes;
    stringstream ss(nomeCompleto);
    string palavra;

    while (ss >> palavra) {
        partes.push_back(palavra);
    }

    if (partes.empty()) return "";

    string resultado;
    string sobrenome = paraMaiusculas(partes.back());
    resultado += sobrenome + ", ";

    for (int i = 0; i < partes.size() - 1; i++) {
        if (i == 0) {
            resultado += partes[i] + " ";
        } else {
            resultado += partes[i][0];
            resultado += ". ";
        }
    }

    return resultado;
}

int main() {
    Contato contatos[10];
    int somaIdades = 0;

    for (int i = 0; i < 10; i++) {
        string nome, email, telefone;
        int dia, mes, ano;

        cout << "Digite o nome do contato " << i + 1 << ": ";
        getline(cin, nome);

        cout << "Digite o email do contato " << i + 1 << ": ";
        getline(cin, email);

        cout << "Digite o telefone (com DDD) do contato " << i + 1 << ": ";
        getline(cin, telefone);

        cout << "Digite o dia de nascimento: ";
        cin >> dia;
        cout << "Digite o mês de nascimento: ";
        cin >> mes;
        cout << "Digite o ano de nascimento: ";
        cin >> ano;
        cin.ignore(); // limpa o \n pendente

        Data dtnasc(dia, mes, ano);
        contatos[i] = Contato(nome, email, telefone, dtnasc);
        somaIdades += contatos[i].idade();

        cout << endl;
    }

    double mediaIdades = somaIdades / 10;
    cout << "\n Média das idades dos contatos: " << mediaIdades << "\n";

    cout << "\nContatos com idade acima da média:\n";
    for (int i = 0; i < 10; i++) {
        if (contatos[i].idade() > mediaIdades) {
            cout << "- " << formatarNomeCitacao(contatos[i].getNome()) << endl;
        }
    }

    int maiores = 0;
    for (int i = 0; i < 10; i++) {
        if (contatos[i].idade() >= 18)
            maiores++;
    }
    cout << "\nQuantidade de contatos maiores de idade: " << maiores << endl;

    int idadeMax = 0;
    for (int i = 0; i < 10; i++) {
        if (contatos[i].idade() > idadeMax)
            idadeMax = contatos[i].idade();
    }

    cout << "\nContato(s) mais velho(s): (" << idadeMax << " anos)\n";
    for (int i = 0; i < 10; i++) {
        if (contatos[i].idade() == idadeMax) {
            cout << "- Nome: " << formatarNomeCitacao(contatos[i].getNome()) << endl;
            cout << "  Email: " << contatos[i].getEmail() << endl;
            cout << "  Telefone: " << contatos[i].getTelefone() << endl;
        }
    }

    cout << "---------------------------\n";
    return 0;
}
