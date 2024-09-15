#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

    struct filme {
        char titulo[100];
        char diretor[100];
        char genero[100];
        char atores_principais[100];
        char avaliacao[6];
        int estado;
        int ano;
        int id;
    };

    struct filme film[MAX];

    int vet_all_filmes[2] = {0, MAX};

    void menu (void);
    void cadastrar (void); 
    void listar_cadastro (int quant_filmes);
    void listar_todos_filmes (void);
    int busca_id (int id_busca);
    void busca (void);
    void alterar_cadastro (int id_alt);
    int excluir (int id_exc);


    int main (){
        int opcao;
        int id_excluir;
        int id_alterar;
        int resultado_excluir = 1;
        int voltar_menu = 1;

        printf (".\n.\n");
        printf ("=========================================================\n");
        printf ("*********************************************************\n");
        printf ("           <<<<< BEM-VINDO A SUA FILMOTECA >>>>          \n");
        printf ("*********************************************************\n");
        printf ("=========================================================\n");
        printf (".\n.\n");
        
        do {
            if (voltar_menu == 1){
                menu();
                printf ("Escolha uma opcao: ");
                scanf ("%d", &opcao);
                printf (".\n.\n");
            }

            switch (opcao){
                case 1:
                    cadastrar ();
                    printf ("Voce quer voltar ao menu principal ( 1 para sim, 0 para nao )? \n");
                    scanf ("%d", &voltar_menu);
                break;
                case 2: 
                    busca ();
                    printf ("Voce quer voltar ao menu principal ( 1 para sim, 0 para nao )? \n");
                    scanf ("%d", &voltar_menu);
                break;
                case 3:
                    printf ("Digite o ID do filme que voce quer excluir: \n");
                    scanf ("%d", &id_excluir);
                    getchar();
                    printf (".\n.\n");

                    resultado_excluir = excluir (id_excluir);
                    if (resultado_excluir == 1){
                        printf("\n#####################################\n");
                        printf ("# O cadastro do filme foi excluido! #\n");
                        printf ("#####################################\n");
                        printf (".\n.\n");
                    }else if (resultado_excluir == 0){
                        printf("\n#####################################\n");
                        printf ("# Cadastro de filme nao encontrado! #\n");
                        printf ("#####################################\n");
                        printf (".\n.\n");
                    }

                    printf ("Voce quer voltar ao menu principal ( 1 para sim, 0 para nao )? \n");
                    scanf ("%d", &voltar_menu);
                break;
                case 4:
                    getchar();
                    printf ("Digite o id do filme que voce quer alterar: \n");
                    scanf ("%d", &id_alterar);
                    printf (".\n.\n");

                    busca_id (id_alterar);
                    alterar_cadastro (id_alterar);

                    printf ("Voce quer voltar ao menu principal ( 1 para sim, 0 para nao )? \n");
                    scanf ("%d", &voltar_menu);
                break;
                case 5: 
                    listar_todos_filmes ();

                    printf ("Voce quer voltar ao menu principal ( 1 para sim, 0 para nao )? \n");
                    scanf ("%d", &voltar_menu);
                break;
                case 0:
                    printf("\n#####################################\n");
                    printf ("Programa finalizado! \n");
                    printf ("#####################################\n");
                    printf (".\n.\n");
                break;
                default:
                    printf("\n#####################################\n");
                    printf("Opcao invalida!\n");
                    printf ("#####################################\n");
                    printf (".\n.\n");
                    printf ("Voce quer voltar ao menu principal ( 1 para sim, 0 para nao )? \n");
                    scanf ("%d", &voltar_menu);
                break;
            }
        } while (opcao != 0);

        system ("PAUSE");
        return 0;
    }

    void menu (void){
        printf ("\n=========================================================\n");
        printf ("                           MENU                          \n");
        printf ("=========================================================\n");
        printf ("1- CADASTRAR\n");
        printf ("2- BUSCAR\n");
        printf ("3- EXCLUIR\n");
        printf ("4- ALTERAR\n");
        printf ("5- LISTAR TODOS OS FILMES\n");
        printf ("0- SAIR\n");
        printf ("=========================================================\n");
    }

    void cadastrar (void){
        int qtd_filmes;
        int listar = 0;
        int q_filmes;

        printf("Quantos filmes voce quer cadastrar? \n");
        scanf("%d", &qtd_filmes);
        getchar();
        printf (".\n.\n");

        q_filmes = vet_all_filmes[0];

        if (q_filmes + qtd_filmes > vet_all_filmes[1]){
            printf("\n##########################################\n");
            printf("# Erro: limite maximo de filmes atingido. #\n");
            printf("###########################################\n");
            return; 
        }

        for (int i=q_filmes ; i<q_filmes + qtd_filmes; i++){
            int igual = 0;
            printf ("================= CADASTRO DE FILME ====================\n");
            printf ("Titulo: ");
            fgets (film[i].titulo, 100, stdin);
            printf ("\n");
            printf ("Genero: ");
            fgets (film[i].genero, 100, stdin);
            printf ("\n");

            for (int j=0; j<i; j++){
                if (strcmp(film[i].titulo, film[j].titulo) == 0 && strcmp(film[i].genero, film[j].genero) == 0){
                    igual = 1;
                    break;
                }
            }

            if (igual == 0){
                printf ("Diretor: ");
                fgets (film[i].diretor, 100, stdin);
                printf ("\n");
                printf ("Elenco: ");
                fgets (film[i].atores_principais, 100, stdin);
                printf ("\n");
                printf ("Estado (1 para assistido, 0 para nao assistido): ");
                scanf ("%d", &film[i].estado);
                getchar();
                printf ("\n");
                if (film[i].estado == 1){
                    getchar();
                    printf ("Avaliacao (minimo: * | maximo: *****): ");
                    fgets (film[i].avaliacao, 6, stdin);
                    printf ("\n");
                }
                printf ("Ano de lancamento: ");
                scanf ("%d", &film[i].ano);
                getchar();
                printf ("\n");
                printf ("========================================================\n");
                printf (".\n.\n");

                film[i].id = i + 1;

                printf ("###########################################\n");
                printf ("#  Filme cadastrado com sucesso!          #\n");
                printf ("#  ID do filme: %d                        #\n", film[i].id);
                printf ("###########################################\n");
                printf (".\n");
            }else{
                printf ("###########################################\n");
                printf ("#  Voce ja cadastrou um filme\ncom os mesmos titulos e generos!\nTente novamente!           #\n");
                printf ("###########################################\n");

                i--;
            }
        }

        vet_all_filmes[0] += qtd_filmes;

        printf ("Voce quer listar o/os filme/es cadastrado/os? (1 para sim, 0 para nao): \n");
        scanf ("%d", &listar);
        printf (".\n.\n");
        if (listar == 1){
            listar_cadastro (qtd_filmes);
        }
        
    }

    void listar_cadastro (int quant_filmes){ 
        int q_filmes = vet_all_filmes[0];

        for(int i=q_filmes - quant_filmes; i<q_filmes; i++){
            printf (":::::::::::::::::::::: FILME ::::::::::::::::::::::::::\n");
            printf ("# Titulo: %s\n", film[i].titulo);
            printf ("# Genero: %s\n", film[i].genero);
            printf ("# Diretor: %s\n", film[i].diretor);
            printf ("# Elenco: %s\n", film[i].atores_principais);
            if (film[i].estado == 1){
                printf ("# Estado: Assistido\n");
                printf ("# Avaliacao: %s\n", film[i].avaliacao);
            }else if (film[i].estado == 0){
                printf ("# Estado: Nao assistido\n");
            }
            printf ("# Ano de lancamento: %d\n", film[i].ano);
            printf ("# Id: %d\n", film[i].id);
            printf (":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf (".\n.\n");
        }
    }
    
    void listar_todos_filmes (void){
        int x = vet_all_filmes[0];

        if (x == 0){
            printf("\n#########################################\n");
            printf ("#        Nenhum filme cadastrado!       #\n");
            printf("##########################################\n");
            return;
        }

        for(int i=0; i<x; i++){
            if (film[i].id != -1){
                printf (":::::::::::::::::::::: FILME ::::::::::::::::::::::::::\n");
                printf ("# Titulo: %s\n", film[i].titulo);
                printf ("# Genero: %s\n", film[i].genero);
                printf ("# Diretor: %s\n", film[i].diretor);
                printf ("# Elenco: %s\n", film[i].atores_principais);
                if (film[i].estado == 1){
                    printf ("# Estado: Assistido\n");
                    printf ("# Avaliacao: %s\n", film[i].avaliacao);
                }else if (film[i].estado == 0){
                    printf ("# Estado: Nao assistido\n");
                }
                printf ("# Ano de lancamento: %d\n", film[i].ano);
                printf ("# Id: %d\n", film[i].id);
                printf (":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            }
        }

    }

    int busca_id (int id_busca){
        for (int i=0; i<vet_all_filmes[0]; i++){
            if (id_busca == film[i].id){
                   return i;  
            }
        }
        return -1;
    }

    void busca (void){
        int opcao_busca;
        int encontrado = 0;

        printf ("OPCOES DE BUSCA\n");
        printf ("1 - ID\n");
        printf ("2 - GENERO\n");
        printf ("3 - AVALIACAO\n");
        printf ("4 - ESTADO 'ASSISTIDO OU NAO ASSISTIDO'\n");
        scanf ("%d", &opcao_busca);
        printf (".\n.\n");

        getchar();

        if (opcao_busca == 1){
            int id_titulo;

            printf ("Digite o id do filme: \n");
            scanf ("%d", &id_titulo);
            printf (".\n.\n");

            for (int i=0; i<vet_all_filmes[0]; i++){
                if (film[i].id != -1){
                    if (id_titulo == film[i].id){
                        encontrado ++;
                        printf (":::::::::::::::::::::: FILME ::::::::::::::::::::::::::\n");
                        printf ("# Titulo: %s\n", film[i].titulo);
                        printf ("# Genero: %s\n", film[i].genero);
                        printf ("# Diretor: %s\n", film[i].diretor);
                        printf ("# Elenco: %s\n", film[i].atores_principais);
                        if (film[i].estado == 1){
                            printf ("# Estado: Assistido\n");
                            printf ("# Avaliacao: %s\n", film[i].avaliacao);
                        }else if (film[i].estado == 0){
                            printf ("# Estado: Nao assistido\n");
                        }   
                        printf ("# Ano de lancamento: %d\n", film[i].ano);
                        printf ("# Id: %d\n", film[i].id);
                        printf (":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                        printf (".\n.\n"); 
                    }
                }
            }
            
        }else if (opcao_busca == 2){
            char genero_busca[100]; 

            getchar();
            printf ("Digite o genero: \n");
            fgets (genero_busca, 100, stdin);
            printf (".\n.\n");

            for (int i=0; i<vet_all_filmes[0]; i++){
                if (film[i].id != -1){
                    if (strcmp(genero_busca, film[i].genero) == 0){
                        encontrado ++;
                        printf (":::::::::::::::::::::: FILME ::::::::::::::::::::::::::\n");
                        printf ("# Titulo: %s\n", film[i].titulo);
                        printf ("# Genero: %s\n", film[i].genero);
                        printf ("# Diretor: %s\n", film[i].diretor);
                        printf ("# Elenco: %s\n", film[i].atores_principais);
                        if (film[i].estado == 1){
                            printf ("# Estado: Assistido\n");
                            printf ("# Avaliacao: %s\n", film[i].avaliacao);
                        }else if (film[i].estado == 0){
                            printf ("# Estado: Nao assistido\n");
                        }   
                        printf ("# Ano de lancamento: %d\n", film[i].ano);
                        printf ("# Id: %d\n", film[i].id);
                        printf (":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"); 
                        printf (".\n.\n"); 
                    }
                }
            }

        }else if (opcao_busca == 3){
            char avaliacao_busca[6];

            getchar();
            printf ("Voce quer buscar filmes com que avaliacao?(De * a ******)\n");
            fgets (avaliacao_busca, 6, stdin);
            printf (".\n.\n");

            for (int i=0; i<vet_all_filmes[0]; i++){
                if (film[i].id != -1){
                    if (strcmp(avaliacao_busca, film[i].avaliacao) == 0){
                        encontrado ++;
                        printf ("# Titulo: %s\n", film[i].titulo);
                        printf ("# Genero: %s\n", film[i].genero);
                        printf ("# Diretor: %s\n", film[i].diretor);
                        printf ("# Elenco: %s\n", film[i].atores_principais);
                        if (film[i].estado == 1){
                            printf ("# Estado: Assistido\n");
                            printf ("# Avaliacao: %s\n", film[i].avaliacao);
                        }else if (film[i].estado == 0){
                            printf ("# Estado: Nao assistido\n");
                        }   
                        printf ("# Ano de lancamento: %d\n", film[i].ano);
                        printf ("# Id: %d\n", film[i].id);
                        printf (":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");  
                        printf (".\n.\n");
                    }
                }
            }
        }else if (opcao_busca == 4){
            int estado_busca; 

            printf ("Digite o estado do filme (1 para assistido e 0 para nao assistido): \n");
            scanf ("%d", &estado_busca);
            printf (".\n.\n");

            for (int i=0; i<vet_all_filmes[0]; i++){
                if (film[i].id != -1){
                    if (estado_busca == film[i].estado){
                        encontrado ++;
                        printf ("# Titulo: %s\n", film[i].titulo);
                        printf ("# Genero: %s\n", film[i].genero);
                        printf ("# Diretor: %s\n", film[i].diretor);
                        printf ("# Elenco: %s\n", film[i].atores_principais);
                        if (film[i].estado == 1){
                            printf ("# Estado: Assistido\n");
                            printf ("# Avaliacao: %s\n", film[i].avaliacao);
                        }else if (film[i].estado == 0){
                            printf ("# Estado: Nao assistido\n");
                        }   
                        printf ("# Ano de lancamento: %d\n", film[i].ano);
                        printf ("# Id: %d\n", film[i].id);
                        printf (":::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                    }
                }
            }
            
        }

        if (encontrado == 0){
            printf("\n################################################################\n");
            printf ("# Filme nao encontrado! Tente novamente ou confira se o cadastro\nbuscado foi excluido. #\n");
            printf("#################################################################\n");
        }

    }

    void alterar_cadastro (int id_alt){
        int posicao = busca_id (id_alt);

        if (posicao == -1){
            printf("\n###########################################\n");
            printf ("#           Filme nao encontrado!         #\n");
            printf ("###########################################\n");
        }else{
            printf (".\n.\n");
            printf ("================= ALTERACAO DE CADASTRO ================\n");
            getchar();

            printf ("Novo Titulo (atual: %s): ", film[posicao].titulo);
            fgets (film[posicao].titulo, 100, stdin);
            printf ("\n");
            printf ("Novo Genero (atual: %s): ", film[posicao].genero);
            fgets (film[posicao].genero, 100, stdin);
            printf ("\n");
            printf ("Novo Diretor (atual: %s): ", film[posicao].diretor);
            fgets (film[posicao].diretor, 100, stdin);
            printf ("\n");
            printf ("Novo Elenco (atual: %s): ", film[posicao].atores_principais);
            fgets (film[posicao].atores_principais, 100, stdin);
            printf ("\n");
            printf ("Novo Estado (Responda com '1 para assistido' ou\n'0 para nao assistido'): ");
            scanf ("%d", &film[posicao].estado);
            printf ("\n");
                if (film[posicao].estado == 1){
                    getchar();
                    printf ("Avaliacao (minimo: * | maximo: *****): ");
                    fgets (film[posicao].avaliacao, 6, stdin);
                    printf ("\n");
                }
            printf ("Novo Ano de Lancamento (atual: %d): ", film[posicao].ano);
            scanf ("%d", &film[posicao].ano);
            getchar();
            printf ("\n");
            printf ("-------------------------------------------------------\n");
            printf (".\n.\n");

            printf("\n############################################\n");
            printf("# Cadastro do filme atualizado com sucesso! #\n");
            printf("#############################################\n");
            printf (".\n.\n");
        }

    }

    int excluir (int id_exc){
        int id_excluir = busca_id(id_exc);

        if (id_excluir == -1){
            return 0;
        }

        film[id_excluir].id = -1;
        return 1;
    }