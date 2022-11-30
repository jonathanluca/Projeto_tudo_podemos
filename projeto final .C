
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define nome 50
typedef struct
{
    int cod_projeto;
    char gerente[nome];
    char cliente[nome];
    float receita_projeto;
}projeto;
typedef struct
{
    float salario_devs;
    float vl_he;
    float vl_desloc;
    float outros_gastos;
}gastos_projeto;
typedef struct
{
    int dia;
    int mes;
    int ano;
}data;
int apresentacao_inicial()
{
    int escolha;
    printf("\nBem vindo(a) ao menu software gerenciador da Tudo Podemos.\n\nVerifique as opcoes abaixo:");
    fflush(stdout);
    printf("\n\n\t1 - Lucro total dos projetos em andamento\n\n\t2 - Quantidade de projetos atrasados\n\n\t3 - Projeto com maior gasto em horas extras\n\n\t4 - Projeto com maior gasto total\n\n\t5 - Busca Gerente X Projeto(s)\n\n\t6 - Busca Cliente X Projeto(s)");
    fflush(stdout);
    printf("\n\nDigite a opcao pretendida: ");
    fflush(stdout);
    scanf("%d",&escolha);
    fflush(stdin);
    while(escolha<=0 || escolha>6)
    {
        printf("\n\n\t<---- ERRO - Opcao invalida [fora de alcance(1-6)], tente novamente abaixo; ---->");
        fflush(stdout);
        printf("\n\nVerifique as opcoes abaixo:");
        fflush(stdout);
        printf("\n\n\t1 - Lucro total dos projetos em andamento\n\n\t2 - Quantidade de projetos atrasados\n\n\t3 - Projeto com maior gasto em horas extras\n\n\t4 - Projeto com maior gasto total\n\n\t5 - Busca Gerente X Projeto(s)\n\n\t6 - Busca Cliente X Projeto(s)");
        fflush(stdout);
        printf("\n\nDigite a opcao pretendida: ");
        fflush(stdout);
        scanf("%d",&escolha);
        fflush(stdin);
    }
    return escolha;
}
int quantidade_projetos()
{
    int qtd_proj;
    printf("\tBem-vindo ao software da Tudo Podemos Inc.\n\nCadastre alguns projetos para obter acesso as metricas\n\n\tOBS: Limite de 15 projetos\n\nDigite a quantidade de projetos a serem inseridos: ");
    fflush(stdout);
    scanf("%d",&qtd_proj);
    fflush(stdin);
    while(qtd_proj>15 || qtd_proj<=0)
    {
        printf("\n\n\t<---- ERRO - Quantidade invalida (fora de alcance[1-15]), tente novamente abaixo; ---->");
        fflush(stdout);
        printf("\n\nDigite a quantidade de projetos a serem inseridos: ");
        fflush(stdout);
        scanf("%d",&qtd_proj);
        fflush(stdin);
    }
    return qtd_proj;
}
void aloca_vetores(projeto *proj[], gastos_projeto *gts[], data *dt[], int qtd_proj)
{
    *proj = malloc(qtd_proj * sizeof(projeto));
    if(*proj == NULL)
    {
        printf("\n\nErro de alocacao de memoria");
        exit(1);
    }
    *gts = malloc(qtd_proj * sizeof(gastos_projeto));
    if(*gts == NULL)
    {
        printf("\n\nErro de alocacao de memoria");
        exit(1);
    }
    *dt = malloc(qtd_proj * sizeof(data));
    if(*dt == NULL)
    {
        printf("\n\nErro de alocacao de memoria");
        exit(1);
    }
}
void cadastra_projeto(projeto *proj[], gastos_projeto *gts[], data *dt[], int qtd_proj)
{
    srand(time(NULL));
    // pegando data atual
    printf("\n\n\tDigite abaixo a data de hoje:\n\n\tDia: ");
    fflush(stdout);
    scanf("%d",&(*dt)[0].dia);
    fflush(stdin);
    while((*dt)[0].dia > 31 || (*dt)[0].dia <= 0)
    {
        printf("\n\n\t<---- ERRO - Data invalida (fora de alcance), tente novamente abaixo; ---->");
        fflush(stdout);
        printf("\n\n\tDia: ");
        fflush(stdout);
        scanf("%d",&(*dt)[0].dia);
        fflush(stdin);
    }
    printf("\n\tMes: ");
    fflush(stdout);
    scanf("%d",&(*dt)[0].mes);
    fflush(stdin);
    while((*dt)[0].mes > 12 || (*dt)[0].mes <= 0)
    {
        printf("\n\n\t<---- ERRO - Data invalida (fora de alcance), tente novamente abaixo; ---->");
        fflush(stdout);
        printf("\n\n\tMes: ");
        fflush(stdout);
        scanf("%d",&(*dt)[0].mes);
        fflush(stdin);
    }
    printf("\n\tAno: ");
    fflush(stdout);
    scanf("%d",&(*dt)[0].ano);
    fflush(stdin);
    while((*dt)[0].ano <= 0)
    {
        printf("\n\n\t<---- ERRO - Data invalida (fora de alcance), tente novamente abaixo; ---->");
        fflush(stdout);
        printf("\n\n\tAno: ");
        fflush(stdout);
        scanf("%d",&(*dt)[0].ano);
        fflush(stdin);
    }
    for(int j=0;j<qtd_proj;j++)
    {
        system("cls");
        // pegando nome do cliente
        (*proj)[j].cod_projeto = rand() % 100;
        printf("\n\t----Projeto Nro: %d----",(*proj)[j].cod_projeto);
        printf("\n\nDigite o nome do cliente: ");
        fflush(stdout);
        gets((*proj)[j].cliente);
        fflush(stdin);
        // pegando nome do gerente
        printf("\n\nDigite o nome do Gerente: ");
        fflush(stdout);
        gets((*proj)[j].gerente);
        fflush(stdin);
        // pegando salario dos devs
        printf("\n\nInforme o custo com salario dos desenvolvedores: R$ ");
        fflush(stdout);
        scanf("%f",&(*gts)[j].salario_devs);
        fflush(stdin);
        // pegando receita do proj
        printf("\n\nInforme a receita total do projeto: R$ ");
        fflush(stdout);
        scanf("%f",&(*proj)[j].receita_projeto);
        fflush(stdin);
        // pegando valor deslocamento
        printf("\n\nInforme o valor gasto em deslocamento(s) neste projeto: R$ ");
        fflush(stdout);
        scanf("%f",&(*gts)[j].vl_desloc);
        fflush(stdin);
        // pegando valor he
        printf("\n\nInforme o valor gasto em hora-exta(s) neste projeto: R$ ");
        fflush(stdout);
        scanf("%f",&(*gts)[j].vl_he);
        fflush(stdin);
        // pegando outros gastos
        printf("\n\nInforme o valor gasto em outro(s) gasto(s) neste projeto: R$ ");
        fflush(stdout);
        scanf("%f",&(*gts)[j].outros_gastos);
        fflush(stdin);
        // pegando prazo
        printf("\n\nInforme abaixo a data de entrega do projeto.\n\n\tDia: ");
        fflush(stdout);
        scanf("%d",&(*dt)[j+1].dia);
        fflush(stdin);
        while((*dt)[j+1].dia > 31 || (*dt)[j+1].dia<=0)
        {
            printf("\n\n\t<---- ERRO - Data invalida (fora de alcance), tente novamente abaixo; ---->");
            fflush(stdout);
            printf("\n\n\tDia: ");
            fflush(stdout);
            scanf("%d",&(*dt)[j+1].dia);
            fflush(stdin);
        }
        printf("\n\tMes: ");
        fflush(stdout);
        scanf("%d",&(*dt)[j+1].mes);
        fflush(stdin);
        while((*dt)[j+1].mes > 12 || (*dt)[j+1].mes <= 0)
        {
            printf("\n\n\t<---- ERRO - Data invalida (fora de alcance), tente novamente abaixo; ---->");
            fflush(stdout);
            printf("\n\n\tMes: ");
            fflush(stdout);
            scanf("%d",&(*dt)[j+1].mes);
            fflush(stdin);
        }
        printf("\n\tAno: ");
        fflush(stdout);
        scanf("%d",&(*dt)[j+1].ano);
        fflush(stdin);
        while((*dt)[j+1].ano <= 0)
        {
            printf("\n\n\t<---- ERRO - Data invalida (fora de alcance), tente novamente abaixo; ---->");
            fflush(stdout);
            printf("\n\n\tAno: ");
            fflush(stdout);
            scanf("%d",&(*dt)[j+1].ano);
            fflush(stdin);
        }
    };
}
void lucro_total(projeto *proj[], gastos_projeto *gts[], data *dt[], int qtd_proj)
{
    float soma=0;
    int desativados=0;
    for(int i=0;i<qtd_proj;i++)
    {
        if((*dt)[0].ano == (*dt)[i+1].ano)
        {
            if((*dt)[0].mes < (*dt)[i+1].mes)
            {
                printf("\n\n\t---- Projeto nro: %d ----\n\t---- Cliente: %s ----\n\t---- Receita: R$ %.2f ----",(*proj)[i].cod_projeto,(*proj)[i].cliente,(*proj)[i].receita_projeto);
                fflush(stdout);
                soma = soma + (*proj)[i].receita_projeto;
            }
            if((*dt)[0].mes == (*dt)[i+1].mes)
            {
                if((*dt)[0].dia <= (*dt)[i+1].dia)
                {
                    printf("\n\n\t---- Projeto nro: %d ----\n\t---- Cliente: %s ----\n\t---- Receita: R$ %.2f ----",(*proj)[i].cod_projeto,(*proj)[i].cliente,(*proj)[i].receita_projeto);
                    fflush(stdout);
                    soma = soma + (*proj)[i].receita_projeto;
                }
            }
        }
        if((*dt)[0].ano < (*dt)[i+1].ano)
        {
            printf("\n\n\t---- Projeto nro: %d ----\n\t---- Cliente: %s ----\n\t---- Receita: R$ %.2f ----",(*proj)[i].cod_projeto,(*proj)[i].cliente,(*proj)[i].receita_projeto);
            fflush(stdout);
            soma = soma + (*proj)[i].receita_projeto;
        }
    }
    printf("\n\n\t---- Valor total: R$ %.2f ----",soma);
    fflush(stdout);
}
void projetos_atrasados(projeto *proj[], data *dt[], int qtd_proj)
{
    int qtd_atrasados=0;
    for(int i=0;i<qtd_proj;i++)
    {
        if((*dt)[0].ano > (*dt)[i+1].ano)
        {
            printf("\n\n\t---- Projeto nro: %d ----\n\t---- Cliente: %s ----\n\t---- Receita: R$ %.2f -------- Data do vencimento: %d/%d/%d ----",(*proj)[i].cod_projeto,(*proj)[i].cliente,(*proj)[i].receita_projeto,(*dt)[i+1].dia,(*dt)[i+1].mes,(*dt)[i+1].ano);
            fflush(stdout);
            qtd_atrasados = qtd_atrasados + 1;
        }
        if((*dt)[0].ano == (*dt)[i+1].ano)
        {
            if((*dt)[0].mes > (*dt)[i+1].mes)
            {
                printf("\n\n\t---- Projeto nro: %d ----\n\t---- Cliente: %s ----\n\t---- Receita: R$ %.2f ----\n\t---- Data do vencimento: %d/%d/%d ----",(*proj)[i].cod_projeto,(*proj)[i].cliente,(*proj)[i].receita_projeto,(*dt)[i+1].dia,(*dt)[i+1].mes,(*dt)[i+1].ano);
                fflush(stdout);
                qtd_atrasados = qtd_atrasados + 1;
            }
            if((*dt)[0].mes == (*dt)[i+1].mes)
                if((*dt)[0].dia > (*dt)[i+1].dia)
                {
                    printf("\n\n\t---- Projeto nro: %d ----\n\t---- Cliente: %s ----\n\t---- Receita: R$ %.2f ----\n\t---- Data do vencimento: %d/%d/%d ----",(*proj)[i].cod_projeto,(*proj)[i].cliente,(*proj)[i].receita_projeto,(*dt)[i+1].dia,(*dt)[i+1].mes,(*dt)[i+1].ano);
                    fflush(stdout);
                    qtd_atrasados = qtd_atrasados + 1;
                }
        }
    }
    printf("\n\n\t---- Quantidade de projetos em atraso: %d ----",qtd_atrasados);
    fflush(stdout);
}
void busca_gerente_projetos(projeto *proj[], data *dt[], int qtd_proj, gastos_projeto *gts[])
{
    char nome_gerente[nome];
    int qtd_projetos=0;
    float total_gerente=0,custos_projeto=0,lucro_projeto=0;
    printf("\n\n\tDigite o nome do gerente em questao: ");
    fflush(stdout);
    gets(nome_gerente);
    fflush(stdin);
    for(int i=0;i<qtd_proj;i++)
    {
        if((*proj)[i].gerente[i] == nome_gerente[i])
        {
            custos_projeto = (*gts)[i].outros_gastos + (*gts)[i].salario_devs + (*gts)[i].vl_desloc + (*gts)[i].vl_he;
            lucro_projeto = (*proj)[i].receita_projeto - custos_projeto;
            printf("\n\n\t---- Projeto Nro: %d ----\n\t---- Cliente: %s ----\n\t---- Data entrega (prevista): %d/%d/%d\n\t---- Lucro: R$ %.2f ----",(*proj)[i].cod_projeto,(*proj)[i].cliente,(*dt)[i+1].dia,(*dt)[i+1].mes,(*dt)[i+1].ano,lucro_projeto);
            fflush(stdout);
            qtd_projetos++;
            total_gerente = total_gerente + lucro_projeto;
        }
    }
    printf("\n\n\tForam achados %d projetos envolvendo o gerente %s.\n\tLucro total: R$ %.2f",qtd_projetos,nome_gerente,total_gerente);
    fflush(stdout);
}
void busca_cliente_projetos(projeto *proj[], data *dt[], int qtd_proj, gastos_projeto *gts[])
{
    char nome_cliente[nome];
    int qtd_projetos=0;
    float total_cliente=0,custos_projeto=0;
    printf("\n\n\tDigite o nome do cliente em questao: ");
    fflush(stdout);
    gets(nome_cliente);
    fflush(stdin);
    for(int i=0;i<qtd_proj;i++)
    {
        if((*proj)[i].cliente[i] == nome_cliente[i])
        {
            custos_projeto = (*gts)[i].outros_gastos + (*gts)[i].salario_devs + (*gts)[i].vl_desloc + (*gts)[i].vl_he;
            printf("\n\n\t---- Projeto Nro: %d ----\n\t---- Gerente: %s ----\n\t---- Data entrega (prevista): %d/%d/%d\n\t---- Custo: R$ %.2f ----",(*proj)[i].cod_projeto,(*proj)[i].gerente,(*dt)[i+1].dia,(*dt)[i+1].mes,(*dt)[i+1].ano,custos_projeto);
            fflush(stdout);
            qtd_projetos++;
            total_cliente = total_cliente + custos_projeto;
        }
    }
    printf("\n\n\tForam achados %d projetos envolvendo o cliente %s.\n\tCusto total: R$ %.2f",qtd_projetos,nome_cliente,total_cliente);
    fflush(stdout);
}

void maior_he(projeto *proj[], int qtd_proj, gastos_projeto *gts[])
{
    float maior_vl_he=0;
    int posicao=0;
    maior_vl_he = (*gts)[0].vl_he;
    for(int i=0;i<qtd_proj;i++)
    {
        if((*gts)[i].vl_he > maior_vl_he)
        {
            maior_vl_he = 0;
            maior_vl_he = (*gts)[i].vl_he;
            posicao = i;
        }
    }
    printf("\n\n\t---- Projeto Nro: %d ----\n\t---- Cliente: %s ----\n\t---- Gerente: %s ----\n\t---- Custo com horas extras: R$ %.2f ----",(*proj)[posicao].cod_projeto,(*proj)[posicao].cliente,(*proj)[posicao].gerente,maior_vl_he);
    fflush(stdout);
}

void maior_gt_total(projeto *proj[], int qtd_proj, gastos_projeto *gts[])
{
    float maior_gasto=0;
    int posicao=0;
    maior_gasto = (*gts)[0].outros_gastos + (*gts)[0].salario_devs + (*gts)[0].vl_desloc + (*gts)[0].vl_he;
    for(int i=0;i<qtd_proj;i++)
    {
        if(((*gts)[i].outros_gastos + (*gts)[i].salario_devs + (*gts)[i].vl_desloc + (*gts)[i].vl_he) > maior_gasto)
        {
            maior_gasto=0;
            maior_gasto = (*gts)[i].outros_gastos + (*gts)[i].salario_devs + (*gts)[i].vl_desloc + (*gts)[i].vl_he;
            posicao = i;
        }
    }
    printf("\n\n\t---- Projeto Nro: %d ----\n\t---- Cliente: %s ----\n\t---- Gerente: %s ----\n\t---- Custo total: R$ %.2f ----",(*proj)[posicao].cod_projeto,(*proj)[posicao].cliente,(*proj)[posicao].gerente,maior_gasto);
    fflush(stdout);
}

int main()
{
    int qtd_projetos;
    qtd_projetos = quantidade_projetos();
    projeto *proje;
    gastos_projeto *gastos_proj;
    data *dat;
    aloca_vetores(&proje,&gastos_proj,&dat,qtd_projetos);
    char do_while;
    cadastra_projeto(&proje,&gastos_proj,&dat,qtd_projetos);
    do
    {
        int escolha_menu;
        escolha_menu = apresentacao_inicial();
        switch (escolha_menu)
        {
            case 1:
                printf("\n\n\t---- Lucro com Projetos em Andamento ----");
                fflush(stdout);
                lucro_total(&proje,&gastos_proj,&dat,qtd_projetos);
                break;
            case 2:
                printf("\n\n\t---- Projetos Atrasados ----");
                fflush(stdout);
                projetos_atrasados(&proje,&dat,qtd_projetos);
                break;
            case 3:
                printf("\n\n----Maior gasto em horas extras----");
                printf("\n\n\t----Maior gasto em horas extras----");
                fflush(stdout);
                maior_he(&proje,qtd_projetos,&gastos_proj);
                break;
            case 4:
                printf("\n\n----Pojeto com maior gasto total----");
                fflush(stdout);
                maior_gt_total(&proje,qtd_projetos,&gastos_proj);
                break;
            case 5:
                printf("\n\n\t----Busca Gerente X Projeto----");
                fflush(stdout);
                busca_gerente_projetos(&proje,&dat,qtd_projetos,&gastos_proj);
                break;
            case 6:
                printf("\n\n\t----Busca Cliente X Projeto----");
                fflush(stdout);
                busca_cliente_projetos(&proje,&dat,qtd_projetos,&gastos_proj);
                break;
            default:
                printf("\n\n\tFora de alcance");
        }
        printf("\n\n\tDeseja retornar ao menu? [ S / N ]: ");
        fflush(stdout);
        scanf("%c",&do_while);
        fflush(stdin);
        if(do_while == 'N' || do_while == 'n')
        {
            printf("\n\nObrigado por utilizar nosso programa!\n\n\n");
            fflush(stdout);
            return 0;
        }
    }while(do_while == 'S' || do_while == 's');
    free(proje);
    free(gastos_proj);
    free(dat);
    return 0;
    system("pause");
}
