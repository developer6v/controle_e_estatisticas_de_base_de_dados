/*
Controle e Estatísticas de Base de Dados
Objetivo: adquirir conhecimentos de manipulação de registros em vetores e construção de estatísticas com variáveis simples em estruturas de controle.


Integrantes: Adauclever Pacheco, Otávio de Oliveira 020
*/




// Bibliotecas
#include <iostream>
#include <fstream>

using namespace std;


// Tipagem
typedef struct {
    string tipo;
    string finalidade;
    string endereco;
    string bairro;
    string cidade;
    
    float area;
    string valor;    
    float IPTU;

    int quartos;
    int suites;
    int banheiros;
    int vagas;

    string cozinha;
    string sala;
    string varanda;
    string area_de_servico;
    string armarios;
    string arcondicionado;
    string aquecedor;
    string ventilador;

    string piso;
    string conservacao;
} Imoveis;


void imprime_imovel(Imoveis imovel);


int main(){

    // Variáveis
    const int tam = 200;
    int resposta, qtd = 0, auxint, auxint2;
    bool auxbool, continuar = true;
    string rua, aux, aux2, aux3, aux4;
    Imoveis imoveis [tam];


    // Abertura e verificação do arquivo imoveis.txt
    ifstream arquivo("imoveis.txt");
    if (!arquivo.is_open()) {
        cout << "WARNING: O arquivo não foi encontrado ou não pode ser aberto. Exiting..." << endl;
        return 0;
    }

    arquivo >> aux;
    // Preenchimento do vetor
    while (aux != "fim") {
        imoveis[qtd].tipo = aux;
        arquivo >> imoveis[qtd].finalidade;
        arquivo >> imoveis[qtd].endereco;
        arquivo >> imoveis[qtd].bairro;
        arquivo >> imoveis[qtd].cidade;
        arquivo >> imoveis[qtd].area;
        arquivo >> imoveis[qtd].valor;
        arquivo >> imoveis[qtd].IPTU;
        arquivo >> imoveis[qtd].quartos;
        arquivo >> imoveis[qtd].suites;
        arquivo >> imoveis[qtd].banheiros;
        arquivo >> imoveis[qtd].vagas;
        arquivo >> imoveis[qtd].cozinha;
        arquivo >> imoveis[qtd].sala;
        arquivo >> imoveis[qtd].varanda;
        arquivo >> imoveis[qtd].area_de_servico;
        arquivo >> imoveis[qtd].piso;
        arquivo >> imoveis[qtd].conservacao;
        arquivo >> imoveis[qtd].armarios;
        arquivo >> imoveis[qtd].arcondicionado;
        arquivo >> imoveis[qtd].aquecedor;
        arquivo >> imoveis[qtd].ventilador;
        qtd++;
        arquivo >> aux;
    }
    arquivo.close();
    

    // Repetição do menu de opções
    while (continuar) {
        cout << "           Menu de Opções - Controle e Estatísticas de Base de Dados           " << endl;
        cout << "===============================================================================" << endl << endl;
        cout << "1) Inclusao de um novo imovel na base de dados" << endl;
        cout << "2) Busca de um imovel pela rua, e se encontrado, permitir a exclusao da base de dados"<< endl;
        cout << "3) Busca de imóveis por uma faixa de valores para locação, aluguel  ou  temporada" << endl;
        cout << "4) Busca de imoveis pelas caracteristicas: armarios, ar-condicionado, aquecedor e ventilador" << endl;
        cout << "5) Busca de imoveis pelo numero de quartos e suites" << endl;
        cout << "6) Relatorio de estatisticas:porcentagens de imoveis por finalidade, porcentagens de casas com suites, porcentagem de pisos com ceramica nas salas comerciais" << endl;
        cout << "7) Listagem de todos os imoveis disponíveis" << endl;
        cout << "0) Sair" << endl << endl;
        cout << "- Informe a opção desejada: " ;
        cin >> resposta;

        if (resposta > 7 || resposta < 0) {
            cout << "WARNING: Resposta Inválida. Exiting...";
            return 0;
        }

        cout << endl << endl << "-------------------------------------------------" << endl << endl;

        // Switch que verifica qual opção o usuário deseja
        switch (resposta) {

            // Saída do Loop
            case 0:
                cout << "Você saiu. Exiting...";
                continuar = false;
                break;

            // Inclusão de imóvel, se o banco não estiver cheio
            case 1:
                if (qtd != tam) {
                    
                    cout << "Adicionando novo imóvel..." << endl;
                    cout << "Informe o tipo: ";
                    cin >> imoveis[qtd].tipo;
                    cout << "Informe a finalidade: ";
                    cin >> imoveis[qtd].finalidade;
                    cout << "Informe o endereco: ";
                    cin >> imoveis[qtd].endereco;
                    cout << "Informe o bairro: ";
                    cin >> imoveis[qtd].bairro;
                    cout << "Informe a cidade: ";
                    cin >> imoveis[qtd].cidade;
                    cout << "Informe a área: ";
                    cin >> imoveis[qtd].area;
                    cout << "Informe o valor: ";
                    cin >> imoveis[qtd].valor;
                    cout << "Informe o IPTU: ";
                    cin >> imoveis[qtd].IPTU;
                    cout << "Informe a quantidade de quartos: ";
                    cin >> imoveis[qtd].quartos;
                    cout << "Informe a quantidade de suítes: ";
                    cin >> imoveis[qtd].suites;
                    cout << "Informe a quantidade de banheiros: ";
                    cin >> imoveis[qtd].banheiros;
                    cout << "Informe a quantidade de vagas: ";
                    cin >> imoveis[qtd].vagas;

                    // Pede o usuário se tem cozinha, sendo válidos apenas "sim" ou "não"
                    cout << "Informe se tem cozinha (sim/não): ";
                    cin >> aux;
                    if (aux != "sim" && aux != "não") {
                        cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                        break;
                    }
                    imoveis[qtd].cozinha = aux;


                    // Pede o usuário se tem sala, sendo válidos apenas "sim" ou "não"
                    cout << "Informe se tem sala (sim/não): ";
                    cin >> aux;
                    if (aux != "sim" && aux != "não") {
                        cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                        break;
                    }
                    imoveis[qtd].sala = aux;

                    // Pede o usuário se tem varanda, sendo válidos apenas "sim" ou "não"
                    cout << "Informe se tem varanda (sim/não): ";
                    cin >> aux;
                        if (aux != "sim" && aux != "não") {
                        cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                        break;
                    }
                    imoveis[qtd].varanda = aux;

                    // Pede o usuário se tem área de serviço, sendo válidos apenas "sim" ou "não"
                    cout << "Informe se tem área de serviço (sim/não): ";
                    cin >> aux;
                        if (aux != "sim" && aux != "não") {
                        cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                        break;
                    }
                    imoveis[qtd].area_de_servico = aux;

            
                    cout << "Informe o piso: ";
                    cin >> imoveis[qtd].piso;


                    cout << "Informe a conservação: ";
                    cin >> imoveis[qtd].conservacao;

                    
     
                    // Pede o usuário se tem armários, sendo válidos apenas "sim" ou "não"
                    cout << "Informe se tem armários (sim/não): ";
                    cin >> aux;
                    if (aux != "sim" && aux != "não") {
                        cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                        break;
                    }
                    imoveis[qtd].armarios = aux;


                    // Pede o usuário se tem ar condicionado, sendo válidos apenas "sim" ou "não"
                    cout << "Informe se tem ar condicionado (sim/não): ";
                    cin >> aux;
                        if (aux != "sim" && aux != "não") {
                        cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                        break;
                    }
                    imoveis[qtd].arcondicionado = aux;


                    // Pede o usuário se tem aquecedor, sendo válidos apenas "sim" ou "não"
                    cout << "Informe se tem aquecedor (sim/não): ";
                    cin >> aux;
                        if (aux != "sim" && aux != "não") {
                        cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                        break;
                    }
                    imoveis[qtd].aquecedor = aux;


                    // Pede o usuário se tem ventilador, sendo válidos apenas "sim" ou "não"
                    cout << "Informe se tem ventilador (sim/não): ";
                    cin >> aux;
                        if (aux != "sim" && aux != "não") {
                        cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                        break;
                    }
                    imoveis[qtd].ventilador = aux;
                    qtd = qtd+1;


                } else {
                    cout << "WARNING: O vetor está cheio, remova um imóvel e tente novamente.";
                }

                break;


            // Busca de um imovel pela rua, e se encontrado, permitir a exclusao da base de dados
            case 2:
                cout << "Informe a rua do imóvel que deseja buscar: ";
                cin >> aux;
                for (int i = 0; i< qtd; i++) {
                    if (imoveis[i].endereco == aux) {
                        imprime_imovel(imoveis[i]);

                        cout << endl << "Deseja excluir? (sim/não): ";
                        cin >> aux;
                        if (aux != "sim" && aux != "não") {
                            cout << "WARNING: Opção Inválida, deve ser 'sim' ou 'não'";
                            break;
                        }

                        if (aux == "sim") {
                            qtd --;
                            for (int j = i; j < qtd; j++) {
                                imoveis[j] = imoveis[j+1];
                            }
                            cout << endl << "Item exluído com sucesso!";
                        }
                        break;

                    }
                }
                break;


            // Busca de imóveis por uma faixa de valores para locação, aluguel  ou  temporada 
            case 3:
                cout << "Informe o valor: ";
                cin >> aux;
                auxbool = false;
                for (int i = 0; i< qtd; i++) {
                     if ((imoveis[i].finalidade == "aluguel" || imoveis[i].finalidade == "temporada" || imoveis[i].finalidade == "locação") && imoveis[i].valor == aux) {
                        if (!auxbool) {
                            cout << "Tipo       | Finalidade   | Endereço       | Bairro        | Cidade        | Área     | Valor     | IPTU      | Quartos | Suítes | Banheiros | Vagas | Cozinha | Sala | Varanda | Área de Serviço | Piso       | Conservação | Armários | Ar-condicionado | Aquecedor | Ventilador" << endl << endl;
                            auxbool = true;
                        }
                        imprime_imovel(imoveis[i]);
                    }
                }
                break;



            // Busca de imoveis pelas caracteristicas: armarios, ar-condicionado, aquecedor e ventilador
            case 4:
                cout << "Informe se tem armários (sim/não): ";
                cin >> aux;
                cout << "Você digitou: " << aux << " (tamanho: " << aux.length() << ")" << endl;

                if (aux != "sim" && aux != "não" && aux != "nao") {
                    cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                    break;
                }

                cout << "Informe se tem ar condicionado (sim/não): ";
                cin >> aux2;
                if (aux2 != "sim" && aux2 != "não") {
                    cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                    break;
                }

                cout << "Informe se tem aquecedor (sim/não): ";
                cin >> aux3;
                if (aux3 != "sim" && aux3 != "não") {
                    cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                    break;
                }

                cout << "Informe se tem ventilador (sim/não): ";
                cin >> aux4;
                if (aux4 != "sim" && aux4 != "não") {
                    cout << "WARNING: Resposta Inválida, deve ser 'sim' ou 'não'";
                    break;
                }

                auxbool = false;
                for (int i = 0; i < qtd; i++) {
                    if (imoveis[i].armarios == aux && imoveis[i].arcondicionado == aux2 && imoveis[i].aquecedor == aux3 && imoveis[i].ventilador == aux4 ) {
                        if (!auxbool) {
                            cout << "Tipo       | Finalidade   | Endereço       | Bairro        | Cidade        | Área     | Valor     | IPTU      | Quartos | Suítes | Banheiros | Vagas | Cozinha | Sala | Varanda | Área de Serviço | Piso       | Conservação | Armários | Ar-condicionado | Aquecedor | Ventilador" << endl << endl;
                            auxbool = true;
                        }
                        imprime_imovel(imoveis[i]);
                    }
                }

                

                break;
            
            
            // Busca de imoveis pelo numero de quartos e suites
            case 5:
                cout << "Informe o número de quartos: ";
                cin >> auxint;
                cout << "Informe o número de suítes: ";
                cin >> auxint2;
                auxbool = false;

                for (int i = 0; i < qtd; i++) {
                    if (imoveis[i].quartos == auxint && imoveis[i].suites == auxint2) {
                        if (!auxbool) {
                            cout << "Tipo       | Finalidade   | Endereço       | Bairro        | Cidade        | Área     | Valor     | IPTU      | Quartos | Suítes | Banheiros | Vagas | Cozinha | Sala | Varanda | Área de Serviço | Piso       | Conservação | Armários | Ar-condicionado | Aquecedor | Ventilador" << endl << endl;
                            auxbool = true;
                        }
                        imprime_imovel(imoveis[i]);
                    }
                }
                break;


        


            // Relatorio de estatisticas:porcentagens de imoveis por finalidade, porcentagens de casas com suites, porcentagem de pisos com ceramica nas salas comerciais
            case 6:

                
                cout << endl << endl << "               Relatório de Estatísticas           " << endl << endl;
            

                // Calcula a porcentagem da finalidade venda
                auxint = 0;
                for (int i = 0; i < qtd; i++) {
                    if (imoveis[i].finalidade == "venda") {
                        auxint++;
                    }
                }    
                cout << "- Porcentagem de imóveis com a finalidade de venda: " << (auxint * 100.00)/qtd<< " %" << endl;

                // Calcula a porcentagem da finalidade aluguel
                auxint = 0;
                for (int i = 0; i < qtd; i++) {
                    if (imoveis[i].finalidade == "aluguel") {
                        auxint++;
                    }
                }    
                cout << "- Porcentagem de imóveis com a finalidade de aluguel: " << (auxint * 100.00)/qtd<< " %" << endl;

            
                // Calcula a porcentagem da finalidade temporada
                auxint = 0;
                for (int i = 0; i < qtd; i++) {
                    if (imoveis[i].finalidade == "temporada") {
                        auxint++;
                    }
                }    
                cout << "- Porcentagem de imóveis com a finalidade de temporada: " << (auxint * 100.00)/qtd<< " %" << endl;


                // Calcula a porcentagem das casas que tem suíte
                auxint = 0;
                auxint2 = 0;
                for (int i = 0; i < qtd; i++) {
                    if (imoveis[i].tipo == "casa") {
                        if (imoveis[i].suites > 0) {
                            auxint2++;
                        }
                        auxint++;
                    }
                }    
                cout << "- Porcentagem de casas com suítes: " << (auxint2 * 100.00)/auxint<< " %" << endl;
                
                
                // Calcula a porcentagem das salas comerciais que tem o piso de cerâmica
                auxint = 0;
                auxint2 = 0;
                for (int i = 0; i < qtd; i++) {
                    if (imoveis[i].tipo == "sala_comercial") {
                        if (imoveis[i].piso == "cerâmica") {
                            auxint2++;
                        }
                        auxint++;
                    }
                }    

                cout << "- Porcentagem de pisos com cerâmica nas salas comerciais: " << (auxint2 * 100.00)/auxint<< " %";
            
                break;


            // Listagem de todos os imoveis disponíveis        
            case 7:
                cout << "Tipo       | Finalidade   | Endereço       | Bairro        | Cidade        | Área     | Valor     | IPTU      | Quartos | Suítes | Banheiros | Vagas | Cozinha | Sala | Varanda | Área de Serviço | Piso       | Conservação | Armários | Ar-condicionado | Aquecedor | Ventilador" << endl << endl;
                for (int i = 0; i< qtd; i++) {
                    imprime_imovel(imoveis[i]);
                    cout << endl << endl;
                }
                break;

        }


        cout << endl << endl << "-------------------------------------------------" << endl << endl;


    }
        



    // Abre o arquivo, verifica a disponibilidade e coloca o novo vetor dentro dele
    ofstream arquivofechar("imoveis.txt");
    if (!arquivofechar.is_open()) {
        cout << "WARNING: O arquivo não foi encontrado ou não pode ser aberto. Exiting..." << endl;
        return 0;
    }

    for (int i =0; i< qtd; i++) {

        arquivofechar << imoveis[i].tipo << " ";
        arquivofechar << imoveis[i].finalidade << " ";
        arquivofechar << imoveis[i].endereco << " ";
        arquivofechar << imoveis[i].bairro << " ";
        arquivofechar << imoveis[i].cidade << " ";
        arquivofechar << imoveis[i].area << " ";
        arquivofechar << imoveis[i].valor << " ";
        arquivofechar << imoveis[i].IPTU << " ";
        arquivofechar << imoveis[i].quartos << " ";
        arquivofechar << imoveis[i].suites << " ";
        arquivofechar << imoveis[i].banheiros << " ";
        arquivofechar << imoveis[i].vagas << " ";
        arquivofechar << imoveis[i].cozinha << " ";
        arquivofechar << imoveis[i].sala << " ";
        arquivofechar << imoveis[i].varanda << " ";
        arquivofechar << imoveis[i].area_de_servico << " ";
        arquivofechar << imoveis[i].piso << " ";
        arquivofechar << imoveis[i].conservacao << " ";
        arquivofechar << imoveis[i].armarios << " ";
        arquivofechar << imoveis[i].arcondicionado << " ";
        arquivofechar << imoveis[i].aquecedor << " ";
        arquivofechar << imoveis[i].ventilador << " " << endl;
    }
    arquivofechar << "fim";


    arquivofechar.close();
     
    return 0;
}





// Função para imprimir um imóvel
void imprime_imovel(Imoveis imovel) {
    cout << imovel.tipo << " | "
         << imovel.finalidade << " | "
         << imovel.endereco << " | "
         << imovel.bairro << " | "
         << imovel.cidade << " | "
         << imovel.area << " | "
         << imovel.valor << " | "
         << imovel.IPTU << " | "
         << imovel.quartos << " | "
         << imovel.suites << " | "
         << imovel.banheiros << " | "
         << imovel.vagas << " | "
         << imovel.cozinha << " | "
         << imovel.sala << " | "
         << imovel.varanda << " | "
         << imovel.area_de_servico << " | "
         << imovel.piso << " | "
         << imovel.conservacao << " | "
         << imovel.armarios << " | "
         << imovel.arcondicionado << " | "
         << imovel.aquecedor << " | "
         << imovel.ventilador
         << endl << endl;
}