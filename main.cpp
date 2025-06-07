// Adauclever Pacheco
// Otavio de oliveira 020
#include <iostream>
#include <fstream>
using namespace std;

struct locacao{
    string tipo, finalidade, endereco, bairro, cidade, piso, conservacao;
    int area, valor, IPTU, quartos, suites, banheiros, vagas;
    bool cozinha, sala, varanda, area_de_servico, armarios, arcondicionado, aquecedor, ventilador;
};
int main(){
    const int tam = 200;
    int resposta;
    string rua;
    locacao imoveis [tam];

    ifstream arquivo("imoveis.txt");
    if (!arquivo.is_open()) {
        cout << "O arquivo nao foi aberto" << endl;
        return 1;
    }

    cout << "1) Inclusao de um novo imovel na base de dados" << endl;
    cout << "2) Busca de um imovel pela rua, e se encontrado, permitir a exclusao da base de dados"<< endl;
    cout << "3) Busca de imóveis por uma faixa de valores para locação, aluguel  ou  temporada" << endl;
    cout << "4) Busca de imoveis pelas caracteristicas: armarios, ar-condicionado, aquecedor e ventilador" << endl;
    cout << "5) Busca de imoveis pelo numero de quartos e suites" << endl;
    cout << "6) Relatorio de estatisticas:porcentagens de imoveis por finalidade, porcentagens de casas com suites, porcentagem de pisos com ceramica nas salas comerciais" << endl;
    cout << "7) Listagem de todos os imoveis disponíveis" << endl;
    cout << "0) Sair" << endl;
    cout << "Qual opcao voce deseja? " << endl;
    cin >> resposta;

        switch (resposta){
        case 0:
            cout << "voce saiu. ";
            return 0;
        break;
        
        case 1:
        ofstream saida("imoveis.txt", ios::app);
            if(!saida.is_open()){
                cout << "Erro ao abrir o arquivo para a escrita";
                break;
            }
            locacao novo;
            cout << "Digite o tipo do imovel: ";
            cin >> novo.tipo;
            cout << "Finalidade (aluguel / temporada / venda): ";
            cin >> novo.finalidade;
            cout << "Endereco: ";
            cin >> novo.endereco;
            cout << "Bairro: ";
            cin >> novo.bairro;
            cout << "Cidade: ";
            cin >> novo.cidade;
            cout << "Piso: ";
            cin >> novo.piso;
            cout << "Estado de conservacao: ";
            cin >> novo.conservacao;
            cout << "Area (m2): ";
            cin >> novo.area;
            cout << "Valor (R$): ";
            cin >> novo.valor;
            cout << "IPTU (R$): ";
            cin >> novo.IPTU;
            cout << "Quartos: ";
            cin >> novo.quartos;
            cout << "Suites: ";
            cin >> novo.suites;
            cout << "Banheiros: ";
            cin >> novo.banheiros;
            cout << "Vagas de garagem: ";
            cin >> novo.vagas;
            cout << "Tem cozinha (1 - sim / 0 - nao): ";
            cin >> novo.cozinha;
            cout << "Tem sala: ";
            cin >> novo.sala;
            cout << "Tem varanda: ";
            cin >> novo.varanda;
            cout << "Tem area de servico: ";
            cin >> novo.area_de_servico;
            cout << "Tem armarios: ";
            cin >> novo.armarios;
            cout << "Tem ar-condicionado: ";
            cin >> novo.arcondicionado;
            cout << "Tem aquecedor: ";
            cin >> novo.aquecedor;
            cout << "Tem ventilador: ";
            cin >> novo.ventilador;
            
            break;
        
        case 2: 
        ifstream entrada("imoveis.txt");
            if (!entrada.is_open()) {
                 cout << "Erro ao abrir o arquivo para leitura." << endl;
            break;
        }
        
        cout << "Digite o nome da rua (endereco)para buscar: ";
        cin >> rua;
        
        bool encontrado = false;

        
        


        


    }   
    return 0;
}