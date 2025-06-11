Projeto: Controle e Estatísticas de Base de Dados de Imóveis  
Autores: Adauclever Pacheco, Otávio de Oliveira 020  
Linguagem: C++  
Arquivo principal: main.cpp  
Arquivo de dados: imoveis.txt

Descrição:
-----------
Este programa foi desenvolvido para gerenciar um banco de dados de imóveis, permitindo a inclusão, busca, exclusão e geração de estatísticas com base nas informações armazenadas. 

Funcionalidades:
----------------
Ao executar o programa, será exibido um menu com as seguintes opções:

1. inclusão de um novo imóvel na base de dados;
2. busca de um imóvel pela rua, e se encontrado, permitir a exclusão da base de dados;
3. busca de imóveis por uma faixa de valores para locação, aluguel  ou  temporada;
4. busca de imóveis pelas características: armários, ar-condicionado, aquecedor e ventilador;
5. busca de imóveis pelo número de quartos e suítes;
6. relatório de estatísticas: porcentagens de imóveis por finalidade, porcentagens de casas com suítes, porcentagem de pisos com cerâmica nas salas comerciais;
7. listagem de todos os imóveis disponíveis.
0. Sair do programa

Formato do Arquivo de Dados (imoveis.txt):
------------------------------------------
Cada imóvel ocupa uma linha com as informações nessa ordem:

- Tipo Finalidade Endereço Bairro Cidade Área Valor IPTU Quartos Suítes Banheiros Vagas Cozinha Sala Varanda Área_de_Serviço Piso Conservação Armários Ar-condicionado Aquecedor Ventilador

e no seguinte formato:

- casa temporada Rua_do_Ribeirão Bairro_Campos_Elíseos Alfenas 185 340/dia 0 4 1 3 3 sim sim sim sim porcelanato novo sim sim sim sim 


No fim da execução, o vetor alterado a partir das modificações feitas pelo usuário é impresso no arquivo imoveis.txt, simulando um banco de dados
