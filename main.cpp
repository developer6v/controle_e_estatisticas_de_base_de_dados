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

        case 3: {
            string finalidadeBuscada;
            int valorMin, valorMax;

            cout << "Digite a finalidade (aluguel / temporada / venda): ";
            cin >> finalidadeBuscada;
            cout << "Digite o valor minimo (R$): ";
            cin >> valorMin;
            cout << "Digite o valor maximo (R$): ";
            cin >> valorMax;

            ifstream arqBusca("imoveis.txt");
            if (!arqBusca.is_open()) {
                cout << "Erro ao abrir o arquivo para leitura." << endl;
                break;
            }

            string linha;
            bool encontrou = false;
         while (arqBusca >> temp.tipo >> temp.finalidade >> temp.endereco >> temp.bairro >> temp.cidade
                         >> temp.piso >> temp.conservacao >> temp.area >> temp.valor >> temp.IPTU
                         >> temp.quartos >> temp.suites >> temp.banheiros >> temp.vagas
                         >> temp.cozinha >> temp.sala >> temp.varanda >> temp.area_de_servico
                         >> temp.armarios >> temp.arcondicionado >> temp.aquecedor >> temp.ventilador
            ) {
                if (temp.finalidade == finalidadeBuscada &&
                    temp.valor >= valorMin &&
                    temp.valor <= valorMax) {

                    encontrou = true;
                    cout << "---------------------------" << endl;
                    cout << "Endereco: " << temp.endereco << endl;
                    cout << "Bairro: " << temp.bairro << endl;
                    cout << "Cidade: " << temp.cidade << endl;
                    cout << "Valor: R$ " << temp.valor << endl;
                    cout << "Finalidade: " << temp.finalidade << endl;
                    cout << "Tipo: " << temp.tipo << endl;
                    cout << "Quartos: " << temp.quartos << ", Suites: " << temp.suites << endl;
                }
            }

            if (!encontrou) {
                cout << "Nenhum imovel encontrado nessa faixa de valores e finalidade." << endl;
            }

            arqBusca.close();
            break;
        }

                case 4: {
            int arm, ar, aq, vent;
            cout << "Deseja que o imovel tenha armarios embutidos? (1-sim / 0-nao): ";
            cin >> arm;
            cout << "Deseja que o imovel tenha ar-condicionado? (1-sim / 0-nao): ";
            cin >> ar;
            cout << "Deseja que o imovel tenha aquecedor? (1-sim / 0-nao): ";
            cin >> aq;
            cout << "Deseja que o imovel tenha ventilador? (1-sim / 0-nao): ";
            cin >> vent;

            ifstream arq("imoveis.txt");
            if (!arq.is_open()) {
                cout << "Erro ao abrir o arquivo." << endl;
                break;
            }

            locacao temp;
            bool encontrou = false;

            while (
                arq >> temp.tipo >> temp.finalidade >> temp.endereco >> temp.bairro >> temp.cidade
                    >> temp.piso >> temp.conservacao >> temp.area >> temp.valor >> temp.IPTU
                    >> temp.quartos >> temp.suites >> temp.banheiros >> temp.vagas
                    >> temp.cozinha >> temp.sala >> temp.varanda >> temp.area_de_servico
                    >> temp.armarios >> temp.arcondicionado >> temp.aquecedor >> temp.ventilador
            ) {
                if (temp.armarios == arm &&
                    temp.arcondicionado == ar &&
                    temp.aquecedor == aq &&
                    temp.ventilador == vent) {

                    encontrou = true;
                    cout << "---------------------------" << endl;
                    cout << "Endereco: " << temp.endereco << endl;
                    cout << "Bairro: " << temp.bairro << endl;
                    cout << "Cidade: " << temp.cidade << endl;
                    cout << "Valor: R$ " << temp.valor << endl;
                    cout << "Finalidade: " << temp.finalidade << endl;
                    cout << "Tipo: " << temp.tipo << endl;
                    cout << "Quartos: " << temp.quartos << ", Suites: " << temp.suites << endl;
                }
            }

            if (!encontrou) {
                cout << "Nenhum imovel encontrado com essas caracteristicas." << endl;
            }

            arq.close();
            break;
        }

                case 5: {
            int minQuartos, minSuites;

            cout << "Digite o numero minimo de quartos: ";
            cin >> minQuartos;
            cout << "Digite o numero minimo de suites: ";
            cin >> minSuites;

            ifstream arq("imoveis.txt");
            if (!arq.is_open()) {
                cout << "Erro ao abrir o arquivo." << endl;
                break;
            }

            locacao temp;
            bool encontrou = false;

            while (
                arq >> temp.tipo >> temp.finalidade >> temp.endereco >> temp.bairro >> temp.cidade
                    >> temp.piso >> temp.conservacao >> temp.area >> temp.valor >> temp.IPTU
                    >> temp.quartos >> temp.suites >> temp.banheiros >> temp.vagas
                    >> temp.cozinha >> temp.sala >> temp.varanda >> temp.area_de_servico
                    >> temp.armarios >> temp.arcondicionado >> temp.aquecedor >> temp.ventilador
            ) {
                if (temp.quartos >= minQuartos && temp.suites >= minSuites) {
                    encontrou = true;
                    cout << "---------------------------" << endl;
                    cout << "Endereco: " << temp.endereco << endl;
                    cout << "Bairro: " << temp.bairro << endl;
                    cout << "Cidade: " << temp.cidade << endl;
                    cout << "Quartos: " << temp.quartos << " | Suites: " << temp.suites << endl;
                    cout << "Valor: R$ " << temp.valor << " | Finalidade: " << temp.finalidade << endl;
                    cout << "Tipo: " << temp.tipo << endl;
                }
            }

            if (!encontrou) {
                cout << "Nenhum imovel encontrado com essa quantidade de quartos/suites." << endl;
            }

            arq.close();
            break;
        }



        }

        
        


        


     
    return 0;
}