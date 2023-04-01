//Bibliotecas
#include<stdio.h>
#include <windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#include "LaraPet.h"

void incluir_Agendamento();
//Variavéis Globais
	//Variavéis Auxiliar para o cadastro
char cpf_F[30];
char DataN_F[30];
char nome_F[50];
char funcao[30];
char codigo[30];
//Contato
char rua[30];
char bairro[30];
char cidade[30];
char uf[3];
char cep[30];
char teleF[30];
//Cliente
char cpf_C[30];
char DataN_C[30];
char nome_C[50];
char teleC[30];
//Pet
char nome_Pet[30];
char dataN_Pet[30];
char raca[30];
char cor[30];
char sexo[30];
char especie[30];
char microchip[30];
char castrado[30];
char Obs[30];

//Agendamnto
char DataA_C[6];
char HoraA[6];
char ObsA[30];
	
//Struct de Cadatro do Funcionario
typedef struct {
	char cpf_F[30];
	char DataN_F[30];
	char nome_F[30];
	char teleF[30];
	char funcao[30];
	char codigo[30];
}Dados_pessoais_funcionario;

//Struct de Funcionario, e para Cliente
typedef struct endereco{
	char rua[30];
	char bairro[30];
	char cidade[30];
	char uf[3];
	char cep[30];
}Endereco;

//Struct do cadastro do funcionaria
typedef struct{
	Dados_pessoais_funcionario  D_P_F; 
	Endereco D_E_F;
}Cadastro_F;

       //Struct de cadastro de cliente

//Dono
typedef struct cadatro_cliente{
	char cpf_C[30];
	char DataN_C[30];
	char nome_C[50];
	char teleC[30];
}dados_dono_cliente;

typedef struct Agendamento{
	char DataN_C[30];
	char Hora[6];
	char Obs[30];
}dados_Agendamento;


//Pet
typedef struct{
	char nome_Pet[30];
	char dataN_Pet[30];
	char raca[30];
	char cor[30];
	char sexo[30];
	char especie[30];
	char microchip[30];
	char castrado[30];
	char Obs[30];
}dados_pet;

typedef struct{
	dados_dono_cliente D_P_C;
	dados_pet  D_A_C;
	Endereco  D_E_C;
	dados_Agendamento D_M_C; 
}Cadastro_C;

typedef struct{
	int codigo;
    char nome[30];
    int quantidade;
    float preco;
}Vendas;

//variaveis globais
Vendas v;
Cadastro_F F;
Cadastro_C C;

//desenha qualquer tipo de caixa do ponto x,y inicial, até o comprimento e altura indicadas
void caixaJ(int a,int x1,int y1,int comp,int alt){
	//colunas
	int x;
	textcolor(a);
	for(x=y1; x<=y1+alt; x++){
		gotoXY(x,x1-1);
		printf("%c", 220);
		gotoXY(x,x1+comp);
		printf("%c", 220);
	}
	//linhas
	for(x=x1;x<=x1+comp;x++){
		gotoXY(y1,x);
		printf("%c", 219);
		gotoXY(y1+alt,x);
		printf("%c", 219);
	}
}
void caixa1L(int c, int dy, int cy, int ey, int by){
		int i;
		// direita
		for(i = 0; i <=2; i++){
			gotoXY(80,dy);
			textcolor(c);
			printf("%c", 219);
			dy++;
			}
		// cima
		for(i = 24; i < 80; i++){
			gotoXY(i,cy);
			textcolor(c);
			printf("%c", 223);
		}
		//esquerda
		for(i = 8; i<=10; i++){
			gotoXY(24,ey);
			textcolor(c);
			printf("%c", 219);
			gotoXY(24,ey++);
			textcolor(c);
			printf("%c", 219);
		}
		//baixo
		for(i = 50; i < 105; i++, by++){
			gotoXY(i,by++);
			textcolor(c);
			printf("%c", 220);
		}
}
//Caixinha para Cpf
void caixa2L(int c, int dy, int cy, int ey, int by){
		int i;
		// direita
		for(i = 0; i <=2; i++){
			gotoXY(51,dy);
			textcolor(c);
			printf("%c", 219);
			dy++;
			}
		// cima
		for(i = 24; i < 51; i++){
			gotoXY(i,cy);
			textcolor(c);
			printf("%c", 223);
		}
		//esquerda
		for(i = 8; i<=10; i++){
			gotoXY(24,ey++);
			textcolor(c);
			printf("%c", 219);
		}
		//baixo
		for(i = 50; i < 76; i++, by++){
			gotoXY(i,by++);
			textcolor(c);
			printf("%c", 220);
		}
}
void caixa2LB(int c, int dy, int cy, int ey, int by){
		int i;
		// direita
		for(i = 0; i <=2; i++){
			gotoXY(80,dy);
			textcolor(c);
			printf("%c", 219);
			dy++;
			}
		// cima
		for(i = 54; i < 80; i++){
			gotoXY(i,cy);
			textcolor(c);
			printf("%c", 223);
		}
		//esquerda
		for(i = 8; i<=10; i++){
			gotoXY(54,ey++);
			textcolor(c);
			printf("%c", 219);
		}
		//baixo
		for(i = 80; i < 105; i++, by++){
			gotoXY(i,by++);
			textcolor(c);
			printf("%c", 220);
		}
}

//Função principal (main).
	//A função main serve como o ponto de partida para a execução do programa.
int main(){
	
    system("mode 110, 40");
    tela_principal1();
    escolha2(1);
	return 0;
}
void telaDadosPessoais(int a1,int a2,int a3,int a4,int a5,int a6){
	caixa1L(a1, 7, 7, 7, 53);//NOME
	caixa2L(a2, 12, 12, 12, 53);//CPF
	caixa2LB(a3, 12, 12, 12, 53);//CARGO
	caixa1L(a4, 17, 17, 17, 53);//DATA DE NASCIMENTO
	caixa1L(a5, 22, 22, 22, 53);//CÓDIGO
	caixaJ(a6, 28, 68, 2, 12);//CONT.
} 

void telaEndereco(int a1,int a2,int a3,int a4,int a5,int a6,int a7){
	caixa1L(a1, 7, 7, 7, 53);//RUA
	caixa1L(a2, 12, 12, 12, 53);//BAIRRO
	caixa2L(a3, 17, 17, 17, 53);//CIDADE
	caixa2LB(a4, 17, 17, 17, 53);//TELEFONE
	caixa2L(a5, 22 ,22, 22, 53);//CEP
	caixaJ(a6, 22, 54, 2, 20);//UF
	caixaJ(a7, 28, 68, 2, 12);//CONT.
}
void TelaDados_Cliente_Pet_Inter(int a1,int a2,int a3,int a4,int a5){
		
	caixa1L(a1, 7, 7, 7, 53);//NOME DO CLIENTE  e Microchip do pet
	caixa2L(a2, 12, 12, 12, 53);//CPF DO CLIENTE e Especie do pet
	caixa1L(a3, 17, 17, 17, 53);//DATA DE NASCIMENTO do CLIENTE E Data de nascimento DO PET
	caixa1L(a4, 22, 22, 22, 53);//NOME DO PET E Raça
	caixaJ(a5, 28, 68, 2, 12);//CONT.
} 
void TelaDados_Animal_Inter(int a1,int a2,int a3,int a4,int a5){
	caixa2L(a1, 7, 7, 7, 53);//COR DO PET
	caixa2LB(a2, 7, 7, 7, 53);//SEXO DO PET
	caixa1L(a3, 12, 12, 12, 53);//CASTRADO DO PET
	caixa1L(a4, 17, 17, 17, 53);//OBS DO PET
	caixaJ(a5, 28, 68, 2, 12);//CONT.
}
void TelaDados_Agenadmento_Inter(int a1,int a2,int a3,int a4){
	caixa2L(a1, 7, 7, 7, 53);//DATA DO PET
	caixa2LB(a2, 7, 7, 7, 53);//HORARIO DO PET
	caixa1L(a3, 12, 12, 12, 53);//OBS DO PET
	caixaJ(a4, 28, 68, 2, 12);//CONT.
}
void enderecoInter(){
	bordas();
	caixa_branca(31,32,31);
	gotoXY(41,4);
	textcolor(2);
	printf(" E  N  D  E  R  E  C  O");
	gotoXY(26,8);
	textcolor(7);
	printf("Rua:");
	gotoXY(26,13);
	textcolor(7);
	printf("Bairro:");
	gotoXY(26,18);
	textcolor(7);
	printf("Cidade:");
	gotoXY(56,18);
	textcolor(7);
	printf("Telefone:");
	gotoXY(26,23);
	textcolor(7);
	printf("CEP:");
	gotoXY(56,23);
	textcolor(7);
	printf("UF:");
	gotoXY(70,29)
    ;
	textcolor(7);
	printf("Continuar");
}
void DadosPessoaisInter(){ 
    bordas();
    caixa_branca(31,32,31);
	gotoXY(40,4);
	textcolor(2);
	printf("D A D O S   P E S S O A I S");
	gotoXY(26,8);
	textcolor(7);
	printf("Nome:");
	gotoXY(26,13);
	textcolor(7);
	printf("CPF:");
	gotoXY(56,13);
	textcolor(7);
	printf("Cargo:");
	gotoXY(26,18);
	textcolor(7);
	printf("Data de nascimento:",135,198);
	gotoXY(26,23);
	textcolor(7);
	printf("C%cdigo de Acesso:",162);
	gotoXY(70,29);
	textcolor(7);
	printf("CONTINUAR");
}
void DadosProfissionaisInter(){
		gotoXY(70,29);
		textcolor(7);
		printf("CONTINUAR");
} 
void Dados_Cliente_Pet_Inter(){
		bordas();
    	caixa_branca(31,32,31);
		gotoXY(45,4);
		textcolor(2);
		printf("DADOS DO DONO");
		gotoXY(26,8);
		textcolor(7);
		printf("Nome:");
		gotoXY(26,13);
		textcolor(7);
		printf("CPF:");
		gotoXY(26,18);
		textcolor(7);
		printf("Data de nascimento:");
		gotoXY(26,23);
		textcolor(7);
		printf("Nome do Pet:");
		gotoXY(70,29);
		textcolor(7);
		printf("CONTINUAR");
}
void Dados_Animal_Inter(){
	bordas();
    caixa_branca(31,32,31);
	gotoXY(45,4);
	textcolor(2);
	printf("DADOS DO ANIMAL");
	gotoXY(26,8);
	textcolor(7);
	printf("Microchip *Se Tiver*:");
	gotoXY(26,13);
	textcolor(7);
	printf("Especie: ");
	gotoXY(26,18);
	textcolor(7);
	printf("Data de Nascimento:");
	gotoXY(26,23);
	textcolor(7);
	printf("Ra%ca:",135);
	gotoXY(70,29);
	textcolor(7);
	printf("CONTINUAR");
}
void Dados_Pet_Inter(){
	bordas();
    caixa_branca(31,32,31);
	gotoXY(45,4);
	textcolor(2);
	printf("DADOS DO ANIMAL");
	gotoXY(26,8);
	textcolor(7);
	printf("Cor:");
	gotoXY(56,8);
	textcolor(7);
	printf("Sexo:");
	gotoXY(26,13);
	textcolor(7);
	printf("Castrado:");
	gotoXY(26,18);
	textcolor(7);
	printf("Observa%c%co sobre o pet:",135,198);
	gotoXY(70,29);
	textcolor(7);
	printf("CONTINUAR");
}
void Dados_Agendamento_Inter(){
	bordas();
    caixa_branca(31,32,31);
	gotoXY(45,4);
	textcolor(2);
	printf("DADOS DO AGENDAMENTO");
	gotoXY(26,8);
	textcolor(7);
	printf("Data:");
	gotoXY(56,8);
	textcolor(7);
	printf("Horario:");
	gotoXY(26,13);
	textcolor(7);
	printf("Observa%c%co sobre o pet:",135,198);
	gotoXY(70,29);
	textcolor(7);
	printf("CONTINUAR");
}

// Seta para Dados pessoais do funcionario
// Função para Dados Cliente

int verifica_entradas(char campo[], int tam1)
{
	//Função que verifica se foi digitado letra ou numero
    int i;
    int aux;
   
    //LAÇO PARA VERIFICAR A QUANTIDADE DE CARACTERES
    for(i=0;i<tam1;i++){
        aux=campo[i];
		if(isalnum(aux)){
    	    //RETORNA 1 SE FOR CARECTERE
    	    return 1;   
		}else
		//RETORNA PARA 0 SE FOR NÚMERO
		return 0;
	}
}

//................................................................
//Verifica se é número
int verifica_1(char *campo, int tam1){
//Função que verifica se foi digitado letra ou numero
    int i;
    int aux;
   
    //LAÇO PARA VERIFICAR A QUANTIDADE DE CARACTERES
    for(i=0;i<tam1;i++){
        aux=campo[i];
		if(isdigit(aux)){
        //RETORNA 1 SE FOR CARECTERE
        return 1;
	}else
	//RETORNA PARA 0 SE FOR NÚMERO
	return 0;
	}
}
//.........................................................
int verifica_2(char *campo, int tam1){
//Função que verifica se foi digitado letra ou numero
    int i;
    int aux;
   
    //LAÇO PARA VERIFICAR A QUANTIDADE DE CARACTERES
    for(i=0;i<tam1;i++){
        aux=campo[i];
		if(isalpha(aux)){
        //RETORNA 1 SE FOR CARECTERE
        return 1;
	}else
	//RETORNA PARA 0 SE FOR NÚMERO
	return 0;
	}
}
//.........................................................
int verifica_3(char *campo, int tam1){
//Função que verifica se foi digitado letra ou numero
    int i;
    int aux;
   
    //LAÇO PARA VERIFICAR A QUANTIDADE DE CARACTERES
    for(i=0;i<tam1;i++){
        aux=campo[i];
		if(isalnum(aux)){
        //RETORNA 1 SE FOR CARECTERE
        return 1;
	}else
	//RETORNA PARA 0 SE FOR NÚMERO
	return 0;
	}
}
//.........................................................

//FUNÇÃO QUE PESQUISA SE O CODIGO INSERIDO EXISTE
void pesquisa_codigo(int x,int y ,int c, char *s, int tam){
	FILE *arqF;
	int tamanho;
    int aux;
    int encontrou=FALSE;
	char p[40];
    //ABRE O ARQUIVO PARA LEITURA 
    arqF=fopen("arquivoFuncio.txt","r");
   
    //CRIA UMA OUTRA VARIAVEL PARA FAZER AS DEVIDAS VERIFICAÇÕES
    Cadastro_F F2;
    do{    
    encontrou = FALSE;
    setbuf(stdin,NULL);
    textcolor(c);
    gotoXY(x,y);
    gets(p);
    setbuf(stdin,NULL);
    tamanho=strlen(p);
    aux=verifica_3(p, tam);
        //CONDIÇÃO PARA CASO O ARQUIVO NÃO FOR ABERTO
        if(arqF!=NULL){
    		rewind(arqF);
    		//LAÇO PARA FAZER A PESQUISA DO CODIGO
    		while(fread(&F2, sizeof(Cadastro_F),1, arqF)){
				if(strcmp(p,F2.D_P_F.codigo)==0){
					encontrou=TRUE;
					break;
				}
			}
		}
    setbuf(stdin, NULL);
    //CONDIÇÃO CASO O USUARIO NÃO DIGITAR NADA
        //CONDIÇÃO CASO NÃO FOR DIGITADO NADA
        if(p[0]=='\0'){
            gotoXY(x,y);
            printf("                                 ");
            textcolor(12);
            gotoXY(x ,y);
            printf("CAMPO OBRIGAT%cRIO", 224);
			getchar();
			setbuf(stdin,NULL);
    		textcolor(11);
    		gotoXY(x,y);
            printf("                                ");
        }
		setbuf(stdin, NULL);
        //CONDIÇÃO CASO A QUANTIDADE DE CARACTERES FOR MAIOR QUE O LIMITE DISPONÍVEL
        if(tamanho>tam){
            gotoXY(x ,y);
            printf("                                  ");
            textcolor(12);
            gotoXY(x ,y);
            printf("INV%cLIDO", 181);
			getchar();
			setbuf(stdin,NULL);
			textcolor(11);
       		gotoXY(x,y);
    		printf("                                  ");
    	}
        setbuf(stdin, NULL);
		//CONDIÇÃO CASO A VARIAVEL LOGICA RECEBER TRUE (SIGNIFICA QUE ENCONTROU O CODIGO EXISTENTE)
		if(encontrou==TRUE){
			gotoXY(x ,y);
            printf("                                  ");
            textcolor(12);
            gotoXY(x ,y);
            printf("CODIGO EXISTENTE");
			getchar();
			setbuf(stdin,NULL);
			textcolor(11);
       		gotoXY(x,y);
    		printf("                                    ");
		}
    }while(p[0]=='\0' || aux==0 || tamanho>tam ||encontrou==TRUE );
	//IMPRIME A VARIAVEL
	gotoXY(x,y);
	puts(p);
 	strcpy(s,p);
}//..........................................................................................
int verifnom( char *nom){
    int tamS=0, i, a=0;
    
    tamS = strlen(nom);
    for(i=0; i<tamS; i++){
             if(isalpha(nom[i]) || isspace(nom[i]))
                                a++;
    }
    if(a==tamS)
               return 1;
    else
        return 0;
}
//Verifica se é numero

int verifnum( char num[]){
    int tamS=0, i, a=0;
    
    tamS = strlen(num);
    for(i=0; i<tamS; i++){
             if(isdigit(num[i])||(num[i]== '/')|| (num[i]== '-'))
                                a++;
    }
    if(a==tamS)
               return 1;
    else
        return 0;
}

//Verifica se é numero é float

int veriffloat( char num[]){
    int tamS=0, i, a=0;
    
    tamS = strlen(num);
    for(i=0; i<tamS; i++){
             if(isdigit(num[i])||(num[i]== '.'))
                                a++;
    }
    if(a==tamS)
               return 1;
    else
        return 0;
}
void larapet3();
void telaCadastroProduto(){
	system("cls");
	larapet3();
	hidecursor();
	caixaJ(7, 10, 18, 25,71);
	bordas();
	textcolor(7);
	gotoXY(33,15);
	printf("CODIGO:");
	gotoXY(33,20);
	printf("PRODUTO:");
	gotoXY(33,25);
	printf("QUANTIDADE:              PRECO:");
	gotoXY(47,30);
	printf("CADASTRAR");
}
void CadastroProduto(int a1, int a2, int a3, int a4, int a5, int a6, int a7){    
	hidecursor();
    caixaJ(a1, 14, 31, 2, 42);
	caixaJ(a2, 19, 31, 2, 42);
	caixaJ(a3, 24, 31, 2, 23);
	caixaJ(a4, 24, 56, 2, 17);
	caixaJ(a5, 29, 45, 2, 13);
	textcolor(a6);
    gotoXY(95,34);
	printf("CONTINUAR >>");
	textcolor(a7);
    gotoXY(6,34);
	printf("<< VOLTAR");
}
void telaVisualizarProduto(){
	system("cls");
	larapet3();
	bordas();
	caixaJ(7, 10, 18, 25,71);
	gotoXY(34,15);
	textcolor(7);
	printf("CODIGO:");
	gotoXY(34,21);
	printf("NOME:");
	gotoXY(34,25);
	printf("QUANTIDADE:");
	gotoXY(34,29);
	printf("PRECO:");
    caixaJ(7, 19, 32, 11, 42);
}

void VisualizarProduto(int a1, int a2, int a3){
	caixaJ(a1, 13, 32, 2, 42);
	textcolor(a2);
    gotoXY(95,34);
	printf("CONTINUAR >>");
	textcolor(a3);
    gotoXY(6,34);
	printf("<< VOLTAR");
}
void telaExcluirProduto(int a1){
	gotoXY(48,34);
	textcolor(7);
	printf("EXCLUIR");
	caixaJ(a1, 32, 43, 2, 16);
}
void vendasInter(){
    int x=45, y=4;
    letreiroLoja();
    textcolor(7);
    gotoXY(31,9);y++;
    printf("CODIGO:");
    gotoXY(31,14);y++;
    printf("PRODUTO:");
    gotoXY(31,19);y++;
    printf("QUANTIDADE:              PRECO:");
}

void inclusao(){
     telaCadastroProduto();
	char cod[6], qunt[6], prec[7];
	int c=0;
	CadastroProduto(11, 7, 7, 7, 7, 7, 7);
	entradas(41, 15, 7, cod, 6, 2);
    c=atoi(cod);
    FILE *arquivoVendas = fopen("./vendas.txt","r");
	//Verifica se o arquivo existe ou está aberto
	if(arquivoVendas != NULL){
		rewind(arquivoVendas);
    	while(fread(&v, sizeof(Vendas), 1, arquivoVendas)){
    		if(v.codigo==c){
                            gotoXY(41, 15);
                            printf("          ");
                            textcolor(12);
                            gotoXY(41, 15);
                            printf("J%c EXISTE", 181);
                            getch();
                            gotoXY(41, 15);
                            printf("          ");
	                        fclose(arquivoVendas);
    		                inclusao();
                     }		
	}
	}
    FILE *ptr = fopen("./vendas.txt","a");
	setbuf(stdin, NULL);
	v.codigo=c;
	CadastroProduto(7, 11, 7, 7, 7, 7, 7);
	entradas(42, 20, 7, v.nome, 30, 1);
	setbuf(stdin, NULL);
	
	CadastroProduto(7, 7, 11, 7, 7, 7, 7);
	entradas(46, 25, 7, qunt, 6, 2);
    v.quantidade=atoi(qunt);
	setbuf(stdin, NULL);
	
	CadastroProduto(7, 7, 7, 11, 7, 7, 7);
	entradas(65, 25, 7, prec, 7, 4);	
	setbuf(stdin, NULL);
	
    v.preco=atof(prec);
    
    hidecursor();
    CadastroProduto(7, 7, 7, 7, 11, 7, 7);
    char a;
    do{
         a = toupper(getch());
    }while(a!=ENTER);
	
	//Função que escreve no arquivo o conteudo armazenado na variavel v
	fwrite(&v, sizeof(Vendas), 1, ptr);
	
	//Função para fechar o arquivo
	fclose(ptr);
	CadastroProduto(7, 7, 7, 7, 7, 11, 7);
    int x=103;
          hidecursor();
          do{
            a = toupper(getch());
            switch(a){
                     case ESQUERDA:
                          x=6;
                          CadastroProduto(7, 7, 7, 7, 7, 7, 11);
                     break;
                     case DIREITA:
                          x=103;
                          CadastroProduto(7, 7, 7, 7, 7, 11, 7);
                     break;
                     case ENTER:
                          if(x==6)
                             posMenu_vendas(1);
                          else
                               inclusao();
                     break;
          }
    }while(1);
}

int op(){
         VisualizarProduto(7, 11, 7);
          int x=103;
          char a;
          hidecursor();
          do{
            a = toupper(getch());
            switch(a){
                     case ESQUERDA:
                          x=6;
                          VisualizarProduto(7, 7, 11);
                     break;
                     case DIREITA:
                          x=103;
                          VisualizarProduto(7, 11, 7);
                     break;
                     case ENTER:
                          return x;
                     break;
          }
          }while(a!=ENTER);
}
//funcao de consulta dos dados no arquivo
void consulta(){
	telaVisualizarProduto();
	int encontrou = FALSE;
    char cod[6];
    int c;
    char a;
    VisualizarProduto(11, 7, 7);
    gotoXY(34,14);
	textcolor(7);
	printf("Codigo:");
    entradas(41, 14, 7, cod, 6, 2);
    c=atoi(cod);
    setbuf(stdin, NULL);
    
    //Declaracao e inicializacao do arquivo
    FILE* arquivoVendas = fopen("./vendas.txt","r");
    
    //Verifica se o arquivo existe
    if(arquivoVendas == NULL){
    	printf("erro\n");
    	exit(1);
    }
    else{
    	//Executa a operação de pesquisa
    	rewind(arquivoVendas);
    	while(fread(&v, sizeof(Vendas), 1, arquivoVendas)){
    		if(v.codigo==c){
                            encontrou = TRUE;
    		                break;
                     }		
    	}
    	if(!encontrou){   
            gotoXY(42, 15);
            printf("           ");
            textcolor(12);
            gotoXY(42, 15);
            printf("N%cO EXISTE", 199);
            getch();
            gotoXY(42, 15);
            printf("           ");
            consulta();
        }else{
              gotoXY(40, 21); printf("%s", v.nome);
              gotoXY(47, 25); printf("%d", v.quantidade);
              gotoXY(41, 29); printf("%.2f", v.preco);
              int u=op();
              if(u==6)
                     posMenu_vendas(1);
              else 
                   consulta();
        }
        }
}

//funcao de alteracao de dados do arquivo
void alteracao(){
	telaVisualizarProduto();
	VisualizarProduto(11, 7, 7);
	int encontrou = FALSE;
    char cod[6];
    int c;
    
    gotoXY(34,14);
	textcolor(7);
	printf("Codigo:");
    entradas(41, 14, 7, cod, 6, 2);
	c=atoi(cod);
	setbuf(stdin, NULL);

	//Declaracao e inicializacao do arquivo
	FILE* arquivoVendas = fopen("./vendas.txt","r");
	
	//Verifica se o arquivo existe
	if(arquivoVendas == NULL){
		printf("erro\n");
		exit(1);
	}
	else{
		//Executa a operação de pesquisa
		rewind(arquivoVendas);
		while(fread(&v, sizeof(Vendas), 1, arquivoVendas)){
			if(v.codigo==c){
                            encontrou = TRUE;
			                break;
                     }		
		}
		if(!encontrou){   
            gotoXY(42, 15);
            printf("           ");
            textcolor(12);
            gotoXY(42, 15);
            printf("N%cO EXISTE", 199);
            getch();
            gotoXY(42, 15);
            printf("           ");
            alteracao();
        }else{
              char qunt[6], prec[7];            	
       	      entradas(40, 21, 7, v.nome, 30, 1);
       	      setbuf(stdin, NULL);
       	      hidecursor();
       	      
       	      entradas(46, 25, 7, qunt, 6, 2);
              v.quantidade=atoi(qunt);
       	      setbuf(stdin, NULL);
       	      hidecursor();
            	
       	      entradas(41, 29, 7, prec, 7, 4);
       	      setbuf(stdin, NULL);
              v.preco=atof(prec);
       	      hidecursor();
       	      
              FILE* arquivoVendasAux = fopen("./vendasAux.txt","a");
	          rewind(arquivoVendas);
              if(arquivoVendas == NULL || arquivoVendasAux == NULL){
		                       printf("erro\n");
              }else{
    		  //Executa a operação de pesquisa
    		  fwrite(&v,sizeof(Vendas),1,arquivoVendasAux);
    		  while(fread(&v,sizeof(Vendas),1,arquivoVendas)){
    				     fwrite(&v,sizeof(Vendas),1,arquivoVendasAux);
              }
              //Fecha o arquivo
        	fclose(arquivoVendas);
        	fclose(arquivoVendasAux);
        	
        	//Remove o arquivo
        	remove("./vendas.txt");
        	rename("./vendasAux.txt","./vendas.txt");
            int u=op();
              if(u==6)
                     posMenu_vendas(1);
              else
                  alteracao();
    		}
        }
	}
	
	getch();
	system("cls");
}

//funcao de excluir dados do arquivo
void exclusao(){
	telaVisualizarProduto();
	VisualizarProduto(11, 7, 7);
    telaExcluirProduto(7);
	int encontrou = FALSE;
    char cod[6];
    int c;
    gotoXY(34, 14);
    textcolor(7);
    printf("Codigo: ");
	entradas(41, 14, 7, cod, 6, 2);
	c=atoi(cod);
	setbuf(stdin, NULL);
    
	//Declaracao e inicializacao do arquivo
	FILE* arquivoVendas = fopen("./vendas.txt","r");
	rewind(arquivoVendas);
	//Verifica se o arquivo existe
	if(arquivoVendas == NULL){
		printf("erro\n");
		exit(1);
	}
	else{
		//Executa a operação de pesquisa
		while(fread(&v, sizeof(Vendas), 1, arquivoVendas)){
			if(v.codigo==c){
                encontrou = TRUE;
                break;
            }		
		}
		if(!encontrou){   
            gotoXY(42, 15);
            printf("           ");
            textcolor(12);
            gotoXY(42, 15);
            printf("N%cO EXISTE", 199);
            getch();
            gotoXY(42, 15);
            printf("           ");
            exclusao();
        }else{
              gotoXY(40, 21); printf("%s", v.nome);
              gotoXY(47, 25); printf("%d", v.quantidade);
              gotoXY(41, 29); printf("%.2f", v.preco);
    
              FILE* arquivoVendasAux = fopen("./vendasAux.txt","a");
	          rewind(arquivoVendas);
              if(arquivoVendas == NULL || arquivoVendasAux == NULL){
		                       printf("erro\n");
              }else{
    		  //Executa a operação de pesquisa
	    		while(fread(&v,sizeof(Vendas),1,arquivoVendas)){
	                if(c!= v.codigo)
					    fwrite(&v,sizeof(Vendas),1,arquivoVendasAux);
				}
              	//Fecha o arquivo
	        	fclose(arquivoVendas);
	        	fclose(arquivoVendasAux);
	        	
	        	//Remove o arquivo
	        	remove("./vendas.txt");
	        	rename("./vendasAux.txt","./vendas.txt");
	        	
	          	hidecursor();
	          	telaExcluirProduto(11);
	          	char a;
	          	
	            do{
	            	a = toupper(getch());
	            }while(a!=ENTER);
	            
	            int u=op();
	            
	            if(u==6)
	                    posMenu_vendas(1);
	            else
	                exclusao();
    		}
        }
    }
}

void entradas(int x,int y ,int c, char *s, int tam, int l){
	char p[40];
	int tamanho,aux, v=1;
	do{
		v=1;
		setbuf(stdin,NULL);
		gotoXY(x,y);
		textcolor(c);
		showcursor();
		gets(p);
		setbuf(stdin,NULL);
		tamanho=strlen(p);
        aux=verifica_entradas(p, tam);
       switch(l){
                 case 1:
                 	v=verifnom(p);
                      if(v==0){     
                        gotoXY(x,y);
                        printf("                     ");
                        textcolor(12);
                        gotoXY(x ,y);
                        hidecursor();
                        printf("INV%cLIDO", 181);
                      }
                 break;
                 case 2:
                 	v = verifnum(p);
                      if(v==0){     
                        gotoXY(x,y);
                        printf("                     ");
                        textcolor(12);
                        gotoXY(x ,y);
                        hidecursor();
                        printf("INV%cLIDO", 181);
                      }
                 break;
                 case 3:
                 	strupr(p);
                 	if((strcmp(p,"GERENTE")!=0)&&(strcmp(p,"ATENDENTE")!=0)){ 
					 	v=0;
						gotoXY(x,y);
                        printf("                     ");
                        textcolor(12);
                        gotoXY(x ,y);
                        hidecursor();
                        printf("INV%cLIDO", 181);
                        getchar();
                        gotoXY(x ,y);
                        hidecursor();
                        printf("             ", 181);
					}
				break;   
				case 4:
                      v = veriffloat(p);
                      if(v==0){     
                        gotoXY(x,y);
                        printf("                     ");
                        textcolor(12);
                        gotoXY(x ,y);
                        hidecursor();
                        printf("INV%cLIDO", 181);
                      }
                 break;
                 case 0:
                 	v=1;
                 	break;
       }
        //CONDIÇÃO CASO NÃO FOR DIGITADO NADA
        if(p[0]=='\0'){
            gotoXY(x,y);
            printf("                     ");
            textcolor(12);
            gotoXY(x ,y);
            hidecursor();
            printf("CAMPO OBRIGAT%cRIO", 224);
			getchar();
			setbuf(stdin,NULL);
    		textcolor(11);
    		gotoXY(x,y);
            printf("                     ");
        }
        //CONDIÇÃO CASO A QUANTIDADE DE CARACTERES FOR MAIOR QUE O LIMITE DISPONÍVEL
        if(tamanho>tam){
            gotoXY(x ,y);
            hidecursor();
            printf("                      ");
            textcolor(12);
            gotoXY(x ,y);
            printf("INV%cLIDO", 181);
			getchar();
			setbuf(stdin,NULL);
			textcolor(11);
       		gotoXY(x,y);
    		printf("                       ");
    	}
    }while(p[0]=='\0'  || tamanho>tam ||v==0  );
	//IMPRIME A VARIAVEL
	gotoXY(x,y);
	puts(p);
	strcpy(s,p);
}
	
//Validação de CPF
void entradasCPF(int x,int y ,int c, char *s, int tam){
	int i, j, digito1 = 0, digito2 = 0,tamanho,a=0;
    char p[12];
	for(i=0;i<11;i++){
			p[i]='\0';
		}
	do{
		a=0;
		digito1 = 0;
		digito2 = 0;
		gotoXY(x,y);
		textcolor(c);
		setbuf(stdin,NULL);
		gets(p);
		gotoXY(x,y+2);
		textcolor(c);
        //CONDIÇÃO CASO NÃO FOR DIGITADO NADA
        if(p[0]=='\0'){
            
			gotoXY(x,y);
			printf("                     ");     
            textcolor(12);
            gotoXY(x ,y);
            printf("CAMPO OBRIGAT%cRIO", 224);
			getchar();
			for(i=0;i<11;i++){
				p[i]='\0';
			}
			setbuf(stdin,NULL);
    		textcolor(11);
    		gotoXY(x,y);
            printf("                     ");
            a=1;
        }
        else{
			if((strcmp(p,"00000000000") == 0) || (strcmp(p,"11111111111") == 0) || (strcmp(p,"22222222222") == 0) ||
        	(strcmp(p,"33333333333") == 0) || (strcmp(p,"44444444444") == 0) || (strcmp(p,"55555555555") == 0) ||
            (strcmp(p,"66666666666") == 0) || (strcmp(p,"77777777777") == 0) || (strcmp(p,"88888888888") == 0) ||
            (strcmp(p,"99999999999") == 0)){
        		gotoXY(x,y);
            	printf("                     ");
            	textcolor(12);
            	gotoXY(x ,y);
            	printf(" CPF INV%cLIDO", 181);
    			getchar();
				setbuf(stdin,NULL);
    			for(i=0;i<11;i++){
					p[i]='\0';
				}
				gotoXY(x,y);
            	printf("                     ");
				a= 1 ; //se o p tiver todos os números iguais ele é inválido.
    		}else
    			{
        		///digito 1---------------------------------------------------
        		for(i = 0, j = 10; i < strlen(p)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            	digito1 += (p[i]-48) * j;
        			digito1 %= 11;
        		if(digito1 < 2)
            	digito1 = 0;
        		else
            		digito1 = 11 - digito1;
        		if((p[9]-48) != digito1){
        				gotoXY(x,y);
            			printf("                     ");
            			textcolor(12);
            			gotoXY(x ,y);
            			printf("CPF INV%cLIDO", 181);
    					getchar();
    					for(i=0;i<11;i++){
							p[i]='\0';
						}
						setbuf(stdin,NULL);
    					gotoXY(x,y);
            			printf("                     ");
    					textcolor(11);
						a = 1 ;
				}
        		else
       			 ///digito 2--------------------------------------------------
        			{
           			for(i = 0, j = 11; i < strlen(p)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    	digito2 += (p[i]-48) * j;
        			digito2 %= 11;
        			if(digito2 < 2)
         			   digito2 = 0;
      			  	else
            			digito2 = 11 - digito2;
        			if((p[10]-48) != digito2){
        					textcolor(12);
            				gotoXY(x ,y);
            				printf(" CPF INV%cLIDO", 181);
    						getchar();
    						for(i=0;i<11;i++){
								p[i]='\0';
							}
							gotoXY(x,y);
            				printf("                     ");
    						textcolor(11);
							a = 1 ;
						}
        			}
    			}	
    	}
	}while( a == 1 || p[0]=='\0');
	strcpy(s,p);
}

void entradasCPFF(int x,int y ,int c, char *s, int tam){
//FUNÇÃO QUE PESQUISA SE O CODIGO INSERIDO EXISTE
	FILE *arqF;
	int tamanho;
    int aux;
    int i, j, digito1 = 0, digito2 = 0,a=0;
    int encontrou=FALSE;
	char p[12];
	for(i=0;i<11;i++){
			p[i]='\0';
		}
    //ABRE O ARQUIVO PARA LEITURA 
    arqF=fopen("arquivoFuncio.txt","r");
   
    //CRIA UMA OUTRA VARIAVEL PARA FAZER AS DEVIDAS VERIFICAÇÕES
    Cadastro_F F2;
    do{    
    a=0;
	digito1 = 0;
	digito2 = 0;
    encontrou = FALSE;
    setbuf(stdin,NULL);
    textcolor(c);
    gotoXY(x,y);
    gets(p);
    gotoXY(x,y+2);
	textcolor(c);    
    setbuf(stdin,NULL);
    tamanho=strlen(p);
    aux=verifica_3(p, tam);
        //CONDIÇÃO PARA CASO O ARQUIVO NÃO FOR ABERTO
        if(arqF!=NULL){
    		rewind(arqF);
    		//LAÇO PARA FAZER A PESQUISA DO CODIGO
    		while(fread(&F2, sizeof(Cadastro_F),1, arqF)){
				if(strcmp(p,F2.D_P_F.cpf_F)==0){
					encontrou=TRUE;
					break;
				}
			}
		}
    setbuf(stdin, NULL);
    //CONDIÇÃO CASO O USUARIO NÃO DIGITAR NADA
        //CONDIÇÃO CASO NÃO FOR DIGITADO NADA
        if(p[0]=='\0'){
            gotoXY(x,y);
            printf("                  ");
            textcolor(12);
            gotoXY(x ,y);
            printf("CAMPO OBRIGAT%cRIO", 224);
			getchar();
			setbuf(stdin,NULL);
    		textcolor(11);
    		gotoXY(x,y);
            printf("                    ");
        }
        setbuf(stdin, NULL);
		//CONDIÇÃO CASO A VARIAVEL LOGICA RECEBER TRUE (SIGNIFICA QUE ENCONTROU O CODIGO EXISTENTE)
		if(encontrou==TRUE){
			gotoXY(x ,y);
            printf("                ");
            textcolor(12);
            gotoXY(x ,y);
            printf("CPF EXISTENTE");
			getchar();
			setbuf(stdin,NULL);
			textcolor(11);
       		gotoXY(x,y);
    		printf("                 ");
		}
		else{
			if((strcmp(p,"00000000000") == 0) || (strcmp(p,"11111111111") == 0) || (strcmp(p,"22222222222") == 0) ||
        	(strcmp(p,"33333333333") == 0) || (strcmp(p,"44444444444") == 0) || (strcmp(p,"55555555555") == 0) ||
            (strcmp(p,"66666666666") == 0) || (strcmp(p,"77777777777") == 0) || (strcmp(p,"88888888888") == 0) ||
            (strcmp(p,"99999999999") == 0)){
        		gotoXY(x,y);
            	printf("               ");
            	textcolor(12);
            	gotoXY(x ,y);
            	printf(" CPF INV%cLIDO", 181);
    			getchar();
				setbuf(stdin,NULL);
    			for(i=0;i<11;i++){
					p[i]='\0';
				}
				gotoXY(x,y);
            	printf("                ");
				a= 1 ; //se o p tiver todos os números iguais ele é inválido.
    		}
			else
    			{
        		///digito 1---------------------------------------------------
        		for(i = 0, j = 10; i < strlen(p)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            	digito1 += (p[i]-48) * j;
        			digito1 %= 11;
        		if(digito1 < 2)
            	digito1 = 0;
        		else
            		digito1 = 11 - digito1;
        		if((p[9]-48) != digito1){
        				gotoXY(x,y);
            			printf("               ");
            			textcolor(12);
            			gotoXY(x ,y);
            			printf("CPF INV%cLIDO", 181);
    					getchar();
    					for(i=0;i<11;i++){
							p[i]='\0';
						}
						setbuf(stdin,NULL);
    					gotoXY(x,y);
            			printf("               ");
    					textcolor(11);
						a = 1 ;
				}
        		else
       			 ///digito 2--------------------------------------------------
        			{
           			for(i = 0, j = 11; i < strlen(p)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    	digito2 += (p[i]-48) * j;
        			digito2 %= 11;
        			if(digito2 < 2)
         			   digito2 = 0;
      			  	else
            			digito2 = 11 - digito2;
        			if((p[10]-48) != digito2){
        					textcolor(12);
            				gotoXY(x ,y);
            				printf(" CPF INV%cLIDO", 181);
    						getchar();
    						for(i=0;i<11;i++){
								p[i]='\0';
							}
							gotoXY(x,y);
            				printf("               ");
    						textcolor(11);
							a = 1 ;
						}
        			}
    			}	
    	}
    }while(p[0]=='\0' || aux==0 || tamanho>tam ||encontrou==TRUE );
	//IMPRIME A VARIAVEL
	gotoXY(x,y);
	puts(p);
 	strcpy(s,p);
}
//..........................................................................................
void mensagem1(){
	int x=44, y=10;
	textcolor(12);
	gotoXY(x,y);y++;printf("\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB   X        X   \xDB");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB      \x5C___/     \xDB ");
	gotoXY(x,y);y++;printf("\xDB                \xDB      ");
	gotoXY(x,y);y++;printf("\xDB                \xDB      ");
	gotoXY(x,y);y+=3;printf("\xDB                     ");
	gotoXY(38,y);y+=4;printf("OPERA%c%cO REALIZADA COM SUCESSO!",128,199);
	getch();
}

void mensagem2(){
	int x=45, y=9;
	textcolor(12);
	gotoXY(x,y);y++;printf("\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB   X        X   \xDB");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB                \xDB");
	gotoXY(x,y);y++;printf("\xDB      ____      \xDB ");
	gotoXY(x,y);y++;printf("\xDB     /    \x5C     \xDB      ");
	gotoXY(x,y);y++;printf("\xDB                \xDB      ");
	gotoXY(x,y);y++;printf("\xDB                     ");
	gotoXY(x,y);y+=4;printf("     E R R O R ");
	
}

//Posiciona na tela de Execursão, como um plano cartesiano
void gotoXY(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Esconde o cursor
void hidecursor()
{
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

//Escreve o menu na tela
void menuXY(int x, int y, char *t)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x,y};
    SetConsoleCursorPosition(hStdout, position);
    printf("%s", t);
}

//Exibe o cursor
void showcursor()
{
  CONSOLE_CURSOR_INFO cursor = {1, TRUE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

//Muda a cor do texto
void textcolor(int i)
{ 
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	BOOL b = GetConsoleScreenBufferInfo(h1, &bufferInfo);
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute (h1, bufferInfo.wAttributes |= i);
}

//Função de Desenho da Tela Principal

void barra(){
	int i;
	// cima esquerda
    for(i =19; i < 44; i++){
       gotoXY(i,4);
       textcolor(7);
       printf("%c", 220);
	}
	//cima direita
	for(i =61; i < 85; i++){
       gotoXY(i,4);
       textcolor(7);
       printf("%c", 220);
	}
	// direita
    for(i = 5; i <= 31; i++){
       gotoXY(84,i);
       textcolor(7);
       printf("%c", 219);
    }
    //esquerda
    for(i = 5; i< 32; i++){
       gotoXY(19,i);
       textcolor(7);
       printf("%c", 219);
    }
    //baixo
    for(i = 20; i < 84; i++){
       gotoXY(i,31);
       textcolor(7);
       printf("%c", 220);
    }
}

void barraD(){
		int i;
		// cima esquerda
		for(i =19; i < 42; i++){
			gotoXY(i,4);
			textcolor(7);
			printf("%c", 220);
		}
		//cima direita
		for(i =61; i < 85; i++){
			gotoXY(i,4);
			textcolor(7);
			printf("%c", 220);
		}
		// direita
		for(i = 5; i <= 31; i++){
			gotoXY(84,i);
			textcolor(7);
			printf("%c", 219);
		}
		//esquerda
		for(i = 5; i< 32; i++){
			gotoXY(19,i);
			textcolor(7);
			printf("%c", 219);
		}
		//baixo
		for(i = 20; i < 84; i++){
			gotoXY(i,31);
			textcolor(7);
			printf("%c", 220);
		}
}
void caixa(int cx, int bx, int ey, int dy, int dx){
     int i, acm=0, ex=0;
    // baixo
    for(i = 10; i <= 40; i++, bx++){
       gotoXY(bx,28);
       printf("%c", 223);
    }
    
    // cima
    for(i = 60; i < 90; i++, cx++){
       gotoXY(cx,8);
       printf("%c", 223);
    }
    //esquerda
    ex=ey;
    for(i = 8; i< 29; i++){
       gotoXY(ex,i);
       printf("%c", 223);
    }
    
    //direita
    for(i = 8; i < 28; i++){
       gotoXY(dx, i);
       printf("%c", 223);
    }
}

void cabeca(){
	
     int x=45, y=2;
     //18 linhas
     
    gotoXY(x,y);y++;
    textcolor(7);
	printf("      \xDC\xDC\xDC");
	gotoXY(x,y);y++;
	printf("     \xDB   \xDB");
	gotoXY(x,y);y++;
	printf("    \xDB     \xDB");
	gotoXY(x,y);y++;
	printf("    \xDB     \xDB");
	gotoXY(x,y);y++;
	printf("     \xDB   \xDB");
	gotoXY(x,y);y++;
	printf("      \xDC\xDC\xDC");
	gotoXY(x,y);y++;
	printf("");
	gotoXY(x,y);y++;
	printf("    \xDC\xDB   \xDB\xDC");
	gotoXY(x,y);y++;
	printf("   \xDB       \xDB");
	gotoXY(x,y);y++;
	printf("   \xDB       \xDB");
}
void caixa_branca1(int dy, int ey, int by){
	
	//bordas da caixa
	int i;
	// cima esquerda
    for(i =19; i < 85; i++){
       gotoXY(i,8);
       textcolor(7);
       printf("%c", 223);
	}
	
	// direita
    for(i = 8; i <= dy; i++){
       gotoXY(84,i);
       textcolor(7);
       printf("%c", 219);
    }
    //esquerda
    for(i = 8; i< ey; i++){
       gotoXY(19,i);
       textcolor(7);
       printf("%c", 219);
    }
    //baixo
    for(i = 20; i < 84; i++){
       gotoXY(i,by);
       textcolor(7);
       printf("%c", 220);
    }
}
void caixa_branca2(int dy, int ey, int by){
	
	//bordas da caixa
	int i;
	// cima esquerda
    for(i =19; i < 85; i++){
       gotoXY(i,8);
       textcolor(7);
       printf("%c", 223);
	}
	
	// direita
    for(i = 8; i <= dy; i++){
       gotoXY(84,i);
       textcolor(7);
       printf("%c", 219);
    }
    //esquerda
    for(i = 8; i< ey; i++){
       gotoXY(19,i);
       textcolor(7);
       printf("%c", 219);
    }
    //baixo
    for(i = 20; i < 84; i++){
       gotoXY(i,by);
       textcolor(7);
       printf("%c", 220);
    }
}
void caixa_branca(int dy, int ey, int by){
	
	//bordas da caixa
	int i;
	// cima esquerda
    for(i =20; i < 38; i++){
       gotoXY(i,4);
       textcolor(7);
       printf("%c", 219);
	}
	//cima direita
	for(i =68; i < 84; i++){
       gotoXY(i,4);
       textcolor(7);
       printf("%c", 219);
	}
	// direita
    for(i = 4; i <= dy; i++){
       gotoXY(84,i);
       textcolor(7);
       printf("%c", 219);
    }
    //esquerda
    for(i = 5; i< ey; i++){
       gotoXY(20,i);
       textcolor(7);
       printf("%c", 219);
    }
    //baixo
    for(i = 20 ; i < 85; i++){
       gotoXY(i,by+1);
       textcolor(7);
       printf("%c", 219);
    }
}
void caixa1(int a, int dy, int cx, int cy, int ey, int by){
    int i;
    textcolor(a);
    // direita
    for(i = 15; i <= 17; dy++,i++){
       gotoXY(72,dy);
       printf("%c", 219);
    }
    
    // cima
    for(i = 32; i < 73; cx++,i++){
       gotoXY(cx,cy);
       printf("%c", 220);
    }
    //esquerda
    for(i = 15; i< 18; ey++, i++){
       gotoXY(32,ey);
       printf("%c", 219);
    }
    
    //baixo
    for(i = 57; i < 96; by++, i++){
       gotoXY(53,by);
       printf("%c", 220);
    }
}
void caixaV(){
    int i;
    // direita
    for(i = 13; i <= 26; i++){
    gotoXY(70,i);
    textcolor(7);
    printf("%c", 219);
    }
    // cima
    for(i = 29; i < 71; i++){
    gotoXY(i,12);
    textcolor(7);
    printf("%c", 220);
    }
    //esquerda
    for(i = 13; i< 27; i++){
    gotoXY(29,i);
    textcolor(7);
    printf("%c", 219);
    }
    //baixo
    for(i = 52; i < 92; i++){
    gotoXY(50,i);
    textcolor(7);
    printf("%c", 220);
    }
}

void back(int a){
     //Voltar
     int i;
     textcolor(a);
    //esquerda
    for(i = 33; i< 35; i++){
       gotoXY(94,i);
       printf("%c", 219);
    }
    
    // direita
    for(i = 33; i <= 34; i++){
       gotoXY(103,i);
       printf("%c", 219);
    }
    // cima
    for(i = 94; i < 104;i++){
       gotoXY(i,32);
       printf("%c", 220);
    }
    //baixo
    for(i = 94; i < 104; i++){
       gotoXY(i,35);
       printf("%c", 223);
    }
}

void caixa2(int dx, int cx, int ex, int by){
    int i;
    // direita
    for(i = 26; i <= 29; i++){
       gotoXY(dx,i);
       textcolor(3);
       printf("%c", 219);
    }
    
    // cima
    for(i = 32; i < 51; i++, cx++){
       gotoXY(cx,26);
       textcolor(3);
       printf("%c", 220);
    }
    //esquerda
    for(i = 27; i< 30; i++){
       gotoXY(ex,i);
       textcolor(3);
       printf("%c", 219);
    }
    
    //baixo
    for(i =79; i < 96; i++, by++){
       gotoXY(53,by);
       textcolor(3);
       printf("%c", 220);
    }
}
//Botões de voltar e login/LOGIN
int troca_botao(){
     char a;
     caixaJ(11, 26, 65, 2, 15);
     int b=1;
     do{
          a = toupper(getch());
          switch(a){
                    case ESQUERDA:
                        
						 caixaJ(11, 26, 24, 2, 16);
                         caixaJ(7, 26, 65, 2, 15);
                         b=0;
                    break;
                    case DIREITA:
                         caixaJ(7, 26, 24, 2, 16);
                         caixaJ(11, 26, 65, 2, 15);
                         b=1;
                    break;
                    case ENTER:
                         if(b==1)
                               return 1;
                         else
                             return 0;
                    break;
          } 
     }while(a!=ENTER);
}
//Login 2 Op.
void login_funcionario(){
	int x=26, y=16;
	int encontrado=FALSE;
	system("cls");
	FILE *arqF;
	char cpf_A[12];
	char codigo_A[9];
	//ABRE O ARQUIVO EM MODO LEITURA
	arqF = fopen("arquivoFuncio.txt","r");
	
	//VERIFICAÇÃO ARQUIVO
	if(arqF==NULL){
		mensagem2();
		textcolor(12);
		gotoXY(40,24);
		printf("  Nenhum cadastro realizado!\n");
		getchar();
		system("cls");
		escolha2(1);
	}
	system("cls");
	bordas();
	cabeca();
	caixa_branca(31,32,31);
	caixaJ(7,  14, 24, 2, 56);
	caixaJ(7,  19, 24, 2, 56);
	caixaJ(7, 26, 24, 2, 16);
    caixaJ(7, 26, 65, 2, 15);
    
	//COLETA A SENHA INSERIDA
	setbuf(stdin,NULL);
	gotoXY(x,y-1);
	textcolor(7);
	printf("C%cdigo de acesso:",162);
	gotoXY(x,y+4);
	textcolor(7);
	printf("CPF:");
	gotoXY(27,27);
	textcolor(7);
	printf("V o l t a r");
	gotoXY(68,27);
	textcolor(7);
	printf("L o g i n ");
	
	
	caixaJ(11,  14, 24, 2, 56);
	
	gotoXY(x+17,y-1);
	textcolor(7);
	setbuf(stdin,NULL);
	gets(codigo_A);
	setbuf(stdin,NULL);
	
	
	hidecursor();
    caixaJ(7,  14, 24, 2, 56);
	caixaJ(11,  19, 24, 2, 56);
	gotoXY(x+4,y+4);
	textcolor(7);
	setbuf(stdin,NULL);
	gets(cpf_A);
	setbuf(stdin,NULL);
	caixaJ(7,  19, 24, 2, 56);
		
	//LAÇO PARA VERIFICAR A SENHA NO ARQUIVO
	while(fread(&F, sizeof(Cadastro_F), 1, arqF)){
		if((strcmp(F.D_P_F.codigo,codigo_A)==0) && (strcmp(F.D_P_F.cpf_F,cpf_A)==0)) {
			encontrado=TRUE;
			fclose(arqF);
			break;
		}
	}

	setbuf(stdin, NULL);
	//	Seta 
	int a;
    a = troca_botao();	
    
    if(a==0){
             system("cls");
             escolha2(1);//Munu
    }    
	if((strcmp(F.D_P_F.funcao,"GERENTE")==0)){
    		system("cls");
    		posMenu_vendas(2);//GERENTE
	}
	else{
		if((strcmp(F.D_P_F.funcao,"ATENDENTE")==0)){
    		system("cls");
    		escolha2(2);
		}
	}
	
	//CONDIÇÃO CASO NÃO FOR ENCONTRADO
	if(!encontrado){
		system("cls");
		mensagem2();
		textcolor(12);
		gotoXY(42,24);
		printf("  Acesso n%co encontrado!" ,198);
		getchar();
		system("cls");
		escolha2(1);
		
	}
	
}

void menuVendas(){
     hidecursor();
     system("cls");
	caixa_branca(36, 37, 36);
    bordas();
    //menu
    letreiroLoja();
    textcolor(7);
    gotoXY(44,11);printf("CADASTRAR PRODUTO");
    
    gotoXY(44,16);printf("VIZUALIZAR PRODUTO");
    
    gotoXY(44,21);printf("ATUALIZAR PRODUTO");
    
    gotoXY(45,26);printf("EXCLUIR PRODUTO");
    gotoXY(27,32);printf("VOLTAR");
}
void menuFuncio(){
	system("cls");
    caixa_branca(36, 37, 36);
    //menu
    textcolor(7);
    gotoXY(43,13);printf("Lista de Funcion%crios",160);
    gotoXY(39,19);printf("Editar cadastro de funcion%crio",160);
    gotoXY(43,25);printf("Excluir Funcion%crio",160);
    gotoXY(23,32);printf("Voltar");
}
void menuGerente(){
	system("cls");
	bordas();
    caixa_branca(36, 37, 36);
	gotoXY(41,4);
	textcolor(2);
	printf("G   E   R   E   N   T  E");
    //menu
    textcolor(7);
    gotoXY(43,11);printf("A  g  e  n  d  a  ");
	gotoXY(42,16);printf("C  l  i  e  n  t  e");
    gotoXY(36,21);printf("F  u  n  c  i  o  n  %c  r  i  o  ", 160);
    gotoXY(47,26);printf("L  o  j  a");
    gotoXY(27,32);printf("V o l t a r ");
}
void menuAtend(){
	system("cls");
    caixa_branca(36, 37, 36);
    
	gotoXY(41,4);
	textcolor(2);
	printf("A  T  E  N  D  E  N  T  E");
    //menu
    textcolor(7);
    gotoXY(45,13);printf("Agendar");
    gotoXY(45,19);printf("Cliente");
    gotoXY(46,25);printf("Loja");
    gotoXY(23,34);printf("Voltar");
}
void desenha_caixa2(int a1,int a2, int a3, int a4){
     caixa1(a1, 12, 32, 11, 12, 52);
     caixa1(a2, 18, 32, 17, 18, 52);
     caixa1(a3, 24, 32, 23, 24, 52);
     caixaJ(7, 34, 24, 2, 16);
}  
void menuAgend(){
	system("cls");
    caixa_branca(36, 37, 36);
    
	gotoXY(41,4);
	textcolor(2);
	printf("A  T  E  N  D  E  N  T  E");
    //menu
    textcolor(7);
    gotoXY(43,13);printf("Agendar");
    gotoXY(39,21);printf("Cancelar Agendamento");
    gotoXY(23,32);printf("Voltar");
}
void menuCli(){
     system("cls");
    caixa_branca(36, 37, 36);
    
	gotoXY(41,4);
	textcolor(2);
	printf("G   E   R   E   N   T  E");
    //menu
    textcolor(7);
    gotoXY(43,13);printf("Lista de Clientes");
    gotoXY(39,19);printf("Editar cadastro de Clientes");
    gotoXY(43,25);printf("Excluir Clientes");
    gotoXY(23,32);printf("Voltar");
}
void posMenu_vendasEsp(int b){
     char a;
     int posY=12,i;
     switch(b){
               case 4:
                    menuFuncio();
               break;
               case 5:
                    menuCli();
               break;
               case 6:
                    menuAtend();
               break;
     }
    desenha_caixa2(11, 7, 7, 7);
    textcolor(12);
	 gotoXY(29,12);
	 printf("\xDB");
	 gotoXY(28,13);
	 printf("\xDB");
	 gotoXY(29,14);
	 printf("\xDB");
     gotoXY(75,12);
	 printf("\xDB");
	 gotoXY(76,13);
	 printf("\xDB");
	 gotoXY(75,14);
	 printf("\xDB");
	 
    do{      
        a = toupper(getch());
           
        switch(a)
        {
            case 'H':
                if (posY > 12){
                   switch(posY){
                                case 18:
                                     posY-=6;
                                     desenha_caixa2(11, 7, 7, 7);
									for(i=0;i<3;i++){
									 gotoXY(25,18+i);
									 printf("      ");
									 gotoXY(75,18+i);
									 printf("    ");
									}
									 textcolor(12);
									 gotoXY(29,12);
									 printf("\xDB");
									 gotoXY(28,13);
									 printf("\xDB");
									 gotoXY(29,14);
									 printf("\xDB");
                                     gotoXY(75,12);
									 printf("\xDB");
									 gotoXY(76,13);
									 printf("\xDB");
									 gotoXY(75,14);
									 printf("\xDB");
									 break;
                                case 24:
                                     posY-=6;
									 desenha_caixa2(7, 11, 7, 7);
									for(i=0;i<3;i++){
									 gotoXY(25,24+i);
									 printf("      ");
									 gotoXY(75,24+i);
									 printf("     ");
									}
									textcolor(12);
									 gotoXY(29,18);
									 printf("\xDB");
									 gotoXY(28,19);
									 printf("\xDB");
									 gotoXY(29,20);
									 printf("\xDB");
                                     gotoXY(75,18);
									 printf("\xDB");
									 gotoXY(76,19);
									 printf("\xDB");
									 gotoXY(75,20);
									 printf("\xDB");
                                     break;
                                case 34:     
                                     posY-=10; 
                                     desenha_caixa2(7, 7, 11, 7);
									 textcolor(12);
									 gotoXY(29,24);
									 printf("\xDB");
									 gotoXY(28,25);
									 printf("\xDB");
									 gotoXY(29,26);
									 printf("\xDB");
                                     gotoXY(75,24);
									 printf("\xDB");
									 gotoXY(76,25);
									 printf("\xDB");
									 gotoXY(75,26);
									 printf("\xDB");
                                     break;
                    } 
                }
            break;
           
            case 'P':
                if (posY <=30){
                         switch(posY){
                                case 12:
                                     posY+=6;
                                     desenha_caixa2(7, 11, 7, 7);
                                     for(i=0;i<3;i++){
									 gotoXY(27,12+i);
									 printf("    ");
									 gotoXY(75,12+i);
									 printf("    ");
									}
									 textcolor(12);
									 gotoXY(29,18);
									 printf("\xDB");
									 gotoXY(28,19);
									 printf("\xDB");
									 gotoXY(29,20);
									 printf("\xDB");
                                     gotoXY(75,18);
									 printf("\xDB");
									 gotoXY(76,19);
									 printf("\xDB");
									 gotoXY(75,20);
									 printf("\xDB");
									 break;
                                case 18:
                                     posY+=6;
                                     desenha_caixa2(7, 7, 11, 7);
                                     for(i=0;i<3;i++){
									 gotoXY(27,18+i);
									 printf("    ");
									 gotoXY(75,18+i);
									 printf("    ");
									}
									 textcolor(12);
									 gotoXY(29,24);
									 printf("\xDB");
									 gotoXY(28,25);
									 printf("\xDB");
									 gotoXY(29,26);
									 printf("\xDB");
                                     gotoXY(75,24);
									 printf("\xDB");
									 gotoXY(76,25);
									 printf("\xDB");
									 gotoXY(75,26);
									 printf("\xDB");
									 break;
                                case 24:
                                     posY+=10;
                                     desenha_caixa2(7, 7, 7, 11);
                                     for(i=0;i<3;i++){
									 gotoXY(27,24+i);
									 printf("      ");
									 gotoXY(75,24+i);
									 printf("        ");
									}
									 break;
                         }         
                    }
            break;
            case 13:
            	trocaCor(b, posY);
           	break;
    }
   
    }while(a!=13);
}
void desenha_caixa3(int a1,int a2, int a3){
     caixa1(a1, 12, 32, 11, 12, 52);
     caixa1(a2, 20, 32, 17, 20, 52);
     caixaJ(a3, 34, 24, 2, 16);
}  
void posMenu_vendasEspEsp(int b){
     char a;
     int posY=12,i;
     switch(b){
               case 7:
                    menuAgend();
               break; 
     }
    desenha_caixa3(11, 7, 7);
    textcolor(12);
	 gotoXY(29,12);
	 printf("\xDB");
	 gotoXY(28,13);
	 printf("\xDB");
	 gotoXY(29,14);
	 printf("\xDB");
     gotoXY(75,12);
	 printf("\xDB");
	 gotoXY(76,13);
	 printf("\xDB");
	 gotoXY(75,14);
	 printf("\xDB");
	 
    do{      
        a = toupper(getch());
           
        switch(a)
        {
            case 'H':
                if (posY > 12){
                   switch(posY){
                                case 18:
                                     posY-=6;
                                     desenha_caixa3(11, 7, 7);
									for(i=0;i<3;i++){
									 gotoXY(25,18+i);
									 printf("      ");
									 gotoXY(75,18+i);
									 printf("    ");
									}
									 textcolor(12);
									 gotoXY(29,12);
									 printf("\xDB");
									 gotoXY(28,13);
									 printf("\xDB");
									 gotoXY(29,14);
									 printf("\xDB");
                                     gotoXY(75,12);
									 printf("\xDB");
									 gotoXY(76,13);
									 printf("\xDB");
									 gotoXY(75,14);
									 printf("\xDB");
									 break;
                                case 34:     
                                     posY-=16; 
                                     desenha_caixa3(7, 11, 7);
									 textcolor(12);
									 gotoXY(29,18);
									 printf("\xDB");
									 gotoXY(28,19);
									 printf("\xDB");
									 gotoXY(29,20);
									 printf("\xDB");
                                     gotoXY(75,18);
									 printf("\xDB");
									 gotoXY(76,19);
									 printf("\xDB");
									 gotoXY(75,20);
									 printf("\xDB");
                                     break;
                    } 
                }
            break;
           
            case 'P':
                if (posY <=18){
                         switch(posY){
                                case 12:
                                     posY+=6;
                                     desenha_caixa3(7, 11, 7);
                                     for(i=0;i<3;i++){
									 gotoXY(27,12+i);
									 printf("    ");
									 gotoXY(75,12+i);
									 printf("    ");
									}
									 textcolor(12);
									 gotoXY(29,18);
									 printf("\xDB");
									 gotoXY(28,19);
									 printf("\xDB");
									 gotoXY(29,20);
									 printf("\xDB");
                                     gotoXY(75,18);
									 printf("\xDB");
									 gotoXY(76,19);
									 printf("\xDB");
									 gotoXY(75,20);
									 printf("\xDB");
									 break;
                                case 18:
                                     posY+=16;
                                     desenha_caixa3(7, 7, 11);
                                     for(i=0;i<3;i++){
									 gotoXY(27,18+i);
									 printf("    ");
									 gotoXY(75,18+i);
									 printf("    ");
									}
									 break;
                         }         
                    }
            break;
            case 13:
            	trocaCor(b, posY);
           	break;
    }
   
    }while(a!=13);
}
void busca_Agendamento();
void gerente_func(int posY){//Menu Gerente
	switch(posY){
	    case 12:
	     	system("cls");
	     	busca_Agendamento();//Visualiza agenda
	    break;
	    case 18:
	    	system("cls");
            posMenu_vendasEsp(5);//Clientes
	    break;
	    case 24:
	    	system("cls");
            posMenu_vendasEsp(4);//ATENDENTEs
	    break; 
		case 30:
	    	system("cls");
	    	posMenu_vendas(1);//Loja
	    break;
	    case 34:
             system("cls");
             escolha2(1);
        break;
	}
}

void vendas_func(int posY){
              switch(posY){
	    case 12:    //Cadastrar Produto
      		system("cls");
            inclusao();
	    break;
	    case 18:    //Vizualizar Produto
    	     consulta();
	    break;
	    case 24:    //Alterar Produto
    	     system("cls");
             alteracao();
	    break; 
		case 30:    //Excluir Produto
                system("cls");
                exclusao();
	    break;
	    case 34:
             system("cls");
             escolha2(2);
        break;
	}
}

void Funcio_func(int posY){
	switch(posY){
	    case 12:
	     	system("cls");
			busca_Funcionario();
	    break;
	    case 18:
	    	system("cls");
            altera_Funcionario();
	    break;
	    case 24:
	    	system("cls");
            excluir_Funcionario();
	    break; 
	    case 34:
             system("cls");
             posMenu_vendas(2);
        break;
	}
}

void atend_func(int posY){
	switch(posY){
	    case 12:
	     	system("cls");
			posMenu_vendasEspEsp(7);
	    break;
	    case 18:
	    	system("cls");
            incluir_Cliente();
	    break;
	    case 24:
	    	system("cls");
	    break; 
	    case 34:
             system("cls");
             posMenu_vendas(2);
        break;
	}
}

void cli_func(int posY){
	switch(posY){
	    case 12:
	     	system("cls");
	     	 incluir_Cliente();
	    break;
	    case 18:
	    	system("cls");
          	busca_Cliente();
	    break;
	    case 24:
	    	system("cls");
            altera_Cliente();
	    break; 
		case 30:
	    	system("cls");
	    break;
	    case 34:
             system("cls");
             posMenu_vendas(2);
        break;
	}
}
Cadastro_C dadosCliente;

void aaaa(posY){
	switch(posY){
	    case 12:
	     	system("cls");
	     	Agendamento1();
	    break;
	    case 18:
	    	system("cls");
	    break;
	    case 34:
             system("cls");
             posMenu_vendasEsp(6);
        break;
	}
}
void trocaCor(int i, int posY){
	 switch(i){
                case 1:
                	vendas_func(posY);
                break;
                case 2:
                    gerente_func(posY);
                break;
                case 3:
                break;
                case 4:
                     Funcio_func(posY);
                break;
                case 6:
                	atend_func(posY);
                case 7:
                	aaaa(posY);
                break;
            }
} 
//Caixa do Menu-Opcões
void desenha_caixa(int a1,int a2, int a3, int a4, int a5){
	caixa1L(a1, 10, 10, 10, 53);
    caixa1L(a2, 15, 15, 15, 53);
    caixa1L(a3, 20, 20, 20, 53);
    caixa1L(a4, 25, 25, 25, 53);
    caixaJ(a5, 31, 24, 2, 16);
} 

void tela_principal1(){
	int x=10, y=5, i=0, b=8;
	hidecursor();
	textcolor(10);
    do{	    
    //20 linhas
    	x+=3, y=5;
        menuXY(x,y, "                             @t~@"       );y++;
        menuXY(x,y, "                        @@@  @t~~@"      );y++;
        menuXY(x,y, "                      @^^^^% @t(~@"      );y++;
        menuXY(x,y, "                      @^//^s@tt((@"      );y++;
        menuXY(x,y, "                      @////s@tt(@"       );y++;
        menuXY(x,y, "                      @^/^^s@Ctt@"       );y++;
        menuXY(x,y, "                      @s^stt@CCC@"       );y++;
        menuXY(x,y, "          @@@@@@     @@tstt%@CC~O@"      );y++;
        menuXY(x,y, "       @//~~~(/      ^/((((///   O@"     );y++;
        menuXY(x,y, "     @///~~~~~       ^(((@@@(//   O@"    );y++;
        menuXY(x,y, "    @/////~~~        ^(((@@ @(/  ^O@"    );y++;
        menuXY(x,y, "   @///~/~~~         ^/(((@@@(/^^^^@"    );y++;
        menuXY(x,y, "  @/(t/~~(~          ^^/((((((   ^^@"    );y++;
        menuXY(x,y, " @@((t/~~((           ^^/((((   ^  @"    );y++;
        menuXY(x,y, "@(@((t/t~~((            ^^^^^   s @"     );y++;
        menuXY(x,y, "@C@C((ttt%~t(              %%@"          );y++;
        menuXY(x,y, " @@C((((tt%%(            s%  @"          );y++;
        menuXY(x,y, "   @%%((%((((@@@@@@@@@      t @"         );y++;
        menuXY(x,y, "    @%%%(%%@@@          @@  @ @"         );y++;
        menuXY(x,y, "    @%%%%%%%%OO@@@        @@ @"          );y++;
        menuXY(x,y, "       @@@@@@@@@@@"                      );y++;
        
        
    	 Sleep(120);
        system("cls");
        x+=14, y=6;
    	//19 linhas
    	menuXY(x,y, "                               #(/#"       );y++;
        menuXY(x,y, "                         @  t@ #(//#"      );y++;
        menuXY(x,y, "                        @    t @(~/#"      );y++;
        menuXY(x,y, "         ##@@@          @ // C@((~~#"      );y++;
        menuXY(x,y, "       #/////////s#     @ // C@%((#"       );y++;
        menuXY(x,y, "      #////////~/  @    @ /  C@%((#"       );y++;
        menuXY(x,y, "    #///~///////      @ @C C((@%%%#"       );y++;
        menuXY(x,y, "    #//////////         //((~s@(  C#"      );y++;
        menuXY(x,y, "   #/~(////////         /~~~~///   C#"     );y++;
        menuXY(x,y, "@/@#~~(///////          ~~~@@@~//   C@"    );y++;
        menuXY(x,y, "@%~#%~t((t//~           ~~~@@@@~/    @"    );y++;
        menuXY(x,y, " @%#%~~(((t(~           /~~~@@@~/    @"    );y++;
        menuXY(x,y, "    #tt~~~~(/(~          /~~~~~~     @"    );y++;
        menuXY(x,y, "     @t~~~tt%~@@@@@@/      /~~/  ///#"     );y++;
        menuXY(x,y, "     @ttttt@@@      @             C #"     );y++;
        menuXY(x,y, "     @%t@tt@           @      tt#"     	  );y++;
        menuXY(x,y, "     @  @@              @   tt  #"         );y++;
        menuXY(x,y, "     @  @                 @    (  #"        );y++;
        menuXY(x,y, "                           ######"          );y++;
        Sleep(120);
    	system("cls");
    	
    	x+=8, y=6;
    	//19 linhas
        menuXY(x,y, "                            @@"       );y++;
        menuXY(x,y, "                      @@@  @t~~@"      );y++;
        menuXY(x,y, "                     @^^%@ @t~~@"      );y++;
        menuXY(x,y, "                    @^/^^%@@t(~@"      );y++;
        menuXY(x,y, "                    @////s@tt(@"       );y++;
        menuXY(x,y, "                    @^//^s@Ctt@"       );y++;
        menuXY(x,y, "          @@@@@@    @s/^st@CCt@"       );y++;
        menuXY(x,y, "       @//~~~(/   @@tstt%@CC~O@"       );y++;
        menuXY(x,y, "      @///~~~~     ^//tt(G@t  O@"      );y++;
        menuXY(x,y, "     @/////~~~     ^(((((((/   O@"     );y++;
        menuXY(x,y, "   @///~/~~~       ^(((@@ @(/  ^O@"    );y++;
        menuXY(x,y, "   @///~//~        ^(((@@@@(/^^^^@"    );y++;
        menuXY(x,y, " @@((t/~~((        ^/((((((((^^^^@"    );y++;
        menuXY(x,y, "@~@((t/t~~((        ^^/((((   ^  @"    );y++;
        menuXY(x,y, "@~@C(%tt%~~(         ^^/((/  ///@"     );y++;
        menuXY(x,y, "  @C((((tt%%(             %O@@@@ "     );y++;
        menuXY(x,y, "   @%%%%%(((((         s%  @"          );y++;
        menuXY(x,y, "    @%%%%%%((((@@@@@    %%  @"         );y++;
        menuXY(x,y, "     @OOOOOOOOO    @ @     @@@"        );y++;
        Sleep(120);
        i++;
    	system("cls");
	}while(i<2);
	coelhinho_inter();//Continuação do coelinho,mas a parte final.Pinta o coelinho na tela inicial
}
//Continuação do coelinho,mas a parte final;
//Pinta o coelinho na tela inicial
void coelhinho_inter(){
	//19 linhas 
    int x=63, y=5;
    menuXY(x,y, "   @~t@                      "        );y++; 
    menuXY(x,y, "  @~~t@  @@@"                         );y++;
    menuXY(x,y, "  @~(t@ %^^^^@"                       );y++;
    menuXY(x,y, "  @((tt@s^//^@"                       );y++;
    menuXY(x,y, "   @(tt@s////@"                       );y++;
    menuXY(x,y, "   @ttC@s^^/^@"                       );y++;
    menuXY(x,y, "   @CCC@tts^s@ @@@G/////@@"           );y++;
    menuXY(x,y, "  @O~CC@ttst@@     /(~~~//@"          );y++;
    menuXY(x,y, " @O   ///((((/^     ~~~~~///@"        );y++;
    menuXY(x,y, "@O   //(@@@(((^       ~~//(///@"      );y++;
    menuXY(x,y, "@O^  /(@ @@(((^       ~~~/~///@"      );y++;
    menuXY(x,y, "@^^^^/(@@@(((/^        ~(~~/t(/@"     );y++;
    menuXY(x,y, "@^^   ((((((/^^        (~~~/t((@(@"   );y++;
    menuXY(x,y, "@  ^   ((((/^^        ((~~t/t((@(@"   );y++;
    menuXY(x,y, " @ s                 (t~%ttt((C@@ "   );y++;
    menuXY(x,y, "      @%%            ((((((%%%@"      );y++;
    menuXY(x,y, "      @  %s         (((((%%%%%@"      );y++;
    menuXY(x,y, "    @  t     @ @  OO%%%%%%%%@"        );y++;
    menuXY(x,y, "      @@@@@@  @@@@@@@@@@@@@@@"        );y++;
	bordas();
	barrinha();
	bCarreg();
}


//Funcao que desenha Quadrado na borda da tela
void bordas(){
    int i;
    // cima e baixo
	textcolor(12);
	
    gotoXY(0,39);
    printf("%c",200);
    for(i = 1; i <= 108; i++){
       gotoXY(i,39);
       printf("%c",205);
       gotoXY(i,1);
       printf("%c",205);
    }
    gotoXY(109,39);
    printf("%c",188);
    
    gotoXY(0,0);
    printf("%c",201);
    
    gotoXY(109,0);
    printf("%c",187);
    //esquerda e direita
    for(i = 1; i< 38; i++){
       gotoXY(0,i);
       printf("%c",186);
       gotoXY(109,i);
       printf("%c",186);
    }
}


//As duas barrinhas que fica em cima do "Lara Pet"
void barrinha(){
	textcolor(11);    
	 int i, j, x1=10, x2=55;
     for(i=0; i<46; i++){
              gotoXY(x1,5);
              printf("%c", 220);
              gotoXY(x2,22);
              printf("%c",220);
              x1++;
              x2--;
     }
     larapet();
}

//desenho da letra Lara Pet
void larapet(){
	textcolor(12);
	int x=10, y=8, i=0;
	
	//19 linhas
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBB      \xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB   \xDB\xDB\xDB\xDB\xDB\xBB");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBA     \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBA     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA \xDB\xDB\xDB\xDB\xDB\xDB\xCD\xBC \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBA     \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xBA  \xDB\xDB\xBA \xDB\xDB\xBA  \xDB\xDB\xBA \xDB\xDB\xBA  \xDB\xDB\xBA");
	gotoXY(x,y);y+=2;printf(" \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xBC  \xC8\xCD\xBC \xC8\xCD\xBC  \xC8\xCD\xBC \xC8\xCD\xBC  \xC8\xCD\xBC");
	gotoXY(x,y);y++;printf("                      \xDB\xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB");
	gotoXY(x,y);y++;printf("                      \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xBB\xDB\xDB\xC9\xCD\xBC");
	gotoXY(x,y);y++;printf("                      \xDB\xDB\xDB\xDB\xDB\xDB\xC9\xBC\xDB\xDB\xDB\xDB\xDB\xBB    \xBA\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf("                      \xDB\xDB\xC9\xCD\xCD\xCD\xBC \xDB\xDB\xC9\xCD\xCD\xBC    \xBA\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf("                      \xDB\xDB\xBA     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB  \xBA\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf("                      \xC8\xCD\xBC     \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC  \xC8\xCD\xCD\xBC");
    gotoXY(22,34);
    textcolor(11);
    printf("_________________________________________________________________");
    gotoXY(35,36);
    textcolor(7);
    printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR\n");
    getch();
}

//desenho da letra Lara Pet
void larapet2(){
	textcolor(14);
	int x=20, y=3;
	system("cls");
	
	//19 linhas
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBB      \xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB   \xDB\xDB\xDB\xDB\xDB\xBB");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBA     \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBA     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA \xDB\xDB\xDB\xDB\xDB\xDB\xCD\xBC \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBA     \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xBA  \xDB\xDB\xBA \xDB\xDB\xBA  \xDB\xDB\xBA \xDB\xDB\xBA  \xDB\xDB\xBA");
	gotoXY(x,y);y=3;x+=40;printf(" \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xBC  \xC8\xCD\xBC \xC8\xCD\xBC  \xC8\xCD\xBC \xC8\xCD\xBC  \xC8\xCD\xBC");
	gotoXY(x,y);y++;printf("\xDB\xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB");
	gotoXY(x,y);y++;printf("\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xBB\xDB\xDB\xC9\xCD\xBC");
	gotoXY(x,y);y++;printf("\xDB\xDB\xDB\xDB\xDB\xDB\xC9\xBC\xDB\xDB\xDB\xDB\xDB\xBB    \xBA\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf("\xDB\xDB\xC9\xCD\xCD\xCD\xBC \xDB\xDB\xC9\xCD\xCD\xBC    \xBA\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf("\xDB\xDB\xBA     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB  \xBA\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf("\xC8\xCD\xBC     \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC  \xC8\xCD\xCD\xBC");
    gotoXY(20,34);
    textcolor(11);
    printf("_________________________________________________________________");
	int i,j;
    x = 20;
	for(j=0;j<7;j++){
		for(i=0;i<4;i++){
			Pata(x, 31);
			gotoXY(x-1, 30);
			printf("  ");
			gotoXY(x-1, 31);
			printf("  ");
			gotoXY(x-1, 32);
			printf("  ");
			gotoXY(x-1, 33);
			printf("  ");
			x += 2;
			Sleep(30);
		}
		switch(j){
			case 0:
				gotoXY(22,33);
				printf("P");
			break;
			case 1:
				gotoXY(30,33);
				printf("E");
			break;
			case 2:
				gotoXY(38,33);
				printf("T");
			break;
			case 3:
				gotoXY(50,33);
				printf("S");
			break;
			case 4:
				gotoXY(58,33);
				printf("H");
			break;
			case 5:
				gotoXY(66,33);
				printf("O");
			break;
			case 6:
				gotoXY(74,33);
				printf("P");
			break;	
		}    
	}
	gotoXY(75,33);
    textcolor(7);
	printf("          ");
	gotoXY(72,32);
    textcolor(7);
	printf("              ");
	gotoXY(72,31);
    textcolor(7);
	printf("              ");
}
//desenho da letra Lara Pet
void larapet3(){
	textcolor(14);
	int x=20, y=3;
	system("cls");
	
	//19 linhas
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBB      \xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB   \xDB\xDB\xDB\xDB\xDB\xBB");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBA     \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBA     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA \xDB\xDB\xDB\xDB\xDB\xDB\xCD\xBC \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xBA     \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xBA  \xDB\xDB\xBA \xDB\xDB\xBA  \xDB\xDB\xBA \xDB\xDB\xBA  \xDB\xDB\xBA");
	gotoXY(x,y);y=3;x+=40;printf(" \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xBC  \xC8\xCD\xBC \xC8\xCD\xBC  \xC8\xCD\xBC \xC8\xCD\xBC  \xC8\xCD\xBC");
	gotoXY(x,y);y++;printf("\xDB\xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB");
	gotoXY(x,y);y++;printf("\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xBB\xDB\xDB\xC9\xCD\xBC");
	gotoXY(x,y);y++;printf("\xDB\xDB\xDB\xDB\xDB\xDB\xC9\xBC\xDB\xDB\xDB\xDB\xDB\xBB    \xBA\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf("\xDB\xDB\xC9\xCD\xCD\xCD\xBC \xDB\xDB\xC9\xCD\xCD\xBC    \xBA\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf("\xDB\xDB\xBA     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB  \xBA\xDB\xDB\xBA");
	gotoXY(x,y);y++;printf("\xC8\xCD\xBC     \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC  \xC8\xCD\xCD\xBC");
}
//printa o carrinho na tela da "tela_principal"
void Pata(int x,int y){
     gotoXY(x,y++);
    textcolor(11);
    printf("  __");
    gotoXY(x,y++);
    textcolor(11);
    printf("    %c",92);
    textcolor(10);
    printf("%c%c%c%c%c",223,223,223,223,223);
	textcolor(11);
    printf("|");
	gotoXY(x,y++);
    textcolor(11);
    printf("     o");
	textcolor(10);
	printf("%c%c%c%c",223,223,223,223);
    textcolor(11);
    printf("o",223,223,223);
    
}

//"movimenta" o carrinho na tela da "tela_principal",e pinta as letras "Pet shop"
void bCarreg(){
//Função que imprime o carrinho em movimento na tela
    int i,j;
    int x = 20;
	for(j=0;j<7;j++){
		for(i=0;i<4;i++){
			Pata(x, 31);
			gotoXY(x-1, 30);
			printf("  ");
			gotoXY(x-1, 31);
			printf("  ");
			gotoXY(x-1, 32);
			printf("  ");
			gotoXY(x-1, 33);
			printf("  ");
			x += 2;
			Sleep(30);
		}
		switch(j){
			case 0:
				gotoXY(22,33);
				printf("P");
			break;
			case 1:
				gotoXY(30,33);
				printf("E");
			break;
			case 2:
				gotoXY(38,33);
				printf("T");
			break;
			case 3:
				gotoXY(50,33);
				printf("S");
			break;
			case 4:
				gotoXY(58,33);
				printf("H");
			break;
			case 5:
				gotoXY(66,33);
				printf("O");
			break;
			case 6:
				gotoXY(74,33);
				printf("P");
			break;	
		}    
	}
	gotoXY(38,36);
    textcolor(7);
    getch();
}

//Setinha do gato ,e gato na caixa.Imp/rime uma tela com duas opções (CADASTRE-SE OU LOGAR)
void escolha2(int a1){
    system("cls");
    hidecursor();
    char a;
    bordas();
    int x=60, y=15;
    int i=7, j=11, k=7;
    color2(i, j, k, a1, x, a);
    do{
    	a = toupper(getch());
    	switch (a) {
    		case ESQUERDA:
    			switch(x){
    				case 60: //icon da direita - cabeça passa a seta para a da gravata
    						x=30;
			    			i=11, j=7, k=7;
            		break;
                 	case 94: //icon da extrema direita - voltar passa a seta para a da cabeça
                           x=60;
                           i=7, j=11, k=7;
                    break;
            	}
            	color2(i, j, k, a1, x, a);
    		break;		
    		case DIREITA:
    			switch(x){
    				case 30: //icon da direita
    						x=60;
			    			i=7, j=11, k=7;
			    	break;
                 	case 60:
                           x=94;
                           i=7, j=7, k=12;
                    break;
            	}
            	color2(i, j, k, a1, x, a);
    		break;
    		case 13:
                 color2(i, j, k, a1, x, a);
  		}
   	}while (a != 13);
   	system("cls");
}
//Escolha de telas.(Cadatre-se ou login)
void color2(int a1, int a2, int cor3, int a3, int posX, int a){
    switch(a3){
	    case 1:
	     	gerente_escolhas(a1,a2,cor3, posX, a);
	    break;
	    case 2:
	        aten_loja(a1,a2,cor3, posX, a);	     
	    break;
	}
}

void caixa1La(){
		int i;
		// direita
		for(i = 8; i <= 10; i++){
			gotoXY(70,i);
			textcolor(7);
			printf("%c", 219);
		}
		// cima
		for(i = 29; i < 71; i++){
			gotoXY(i,7);
			textcolor(7);
			printf("%c", 220);
		}
		//esquerda
		for(i = 8; i< 11; i++){
			gotoXY(29,i);
			textcolor(7);
			printf("%c", 219);
		}
		//baixo
		for(i = 52; i < 92; i++){
			gotoXY(50,i);
			textcolor(7);
			printf("%c", 220);
		}
}
void voltar(int a){
     //Voltar
     int i;
     textcolor(a);
    //esquerda
    for(i = 33; i< 36; i++){
       gotoXY(21,i);
       printf("%c", 219);
    }
    
    // direita
    for(i = 33; i <= 35; i++){
       gotoXY(30,i);
       printf("%c", 219);
    }
    // cima
    for(i = 21; i < 31;i++){
       gotoXY(i,32);
       printf("%c", 220);
    }
    //baixo
    for(i = 22; i < 30; i++){
       gotoXY(i,35);
       printf("%c", 220);
    }
}



void letreiroLoja(){
     textcolor(11);
	int x=42,y=2;
	gotoXY(x,y);y++;printf("                  ");
	gotoXY(x,y);y++;printf("%c%c%c    %c%c%c%c%c    %c %c%c%c%c",201,205,187,201,205,205,205,187,203,201,205,205,187,203);
	gotoXY(x,y);y++;printf("%c %c    %c   %c    %c %c  %c",186,186,186,186,186,186,186);
	gotoXY(x,y);y++;printf("%C %c    %c   %c    %c %c%c%c%c  ",186,186,186,186,186,204,205,205,185);
	gotoXY(x,y);y++;printf("%c %c%c%c%c%c%c   %c%c   %c %c  %c  ",186,200,205,205,205,187,186,186,201,186,186,186);
	gotoXY(x,y);y++;printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c  %c",200,205,205,205,205,205,188,200,205,205,205,188,200,205,205,205,188,202,202);
}
//Pinta na tela escolha2 (Os desenho dos gatinhos)
void gerente_escolhas(int a1, int a2, int a3, int posX, int a){
    hidecursor();
	textcolor(a1);
    int x=16, y=12;
    gotoXY(25,30);
    printf("CADASTRE-SE");
    caixa(15, 15, 15, 15, 45);
    gotoXY(x,y);y++;printf("                         ,");
    gotoXY(x,y);y++;printf("  ,-.       _,---._ __  / \\");
    gotoXY(x,y);y++;printf(" /  )    .-'       `./ /   \\");
    gotoXY(x,y);y++;printf("(  (   ,'            `/    /|");
	gotoXY(x,y);y++;printf(" %c  `-´             %c%c'%c%c / |", 92, 92, 92, 92, 92);
    gotoXY(x,y);y++;printf("  `.              ,  \\ \\ /  |");
    gotoXY(x,y);y++;printf("   /`.          ,'-`----Y   |");
    gotoXY(x,y);y++;printf("  (            ;        |   |");
    gotoXY(x,y);y++;printf("  |  ,-.    ,-'         |  /");
    gotoXY(x,y);y++;printf("  |  | (   |            | / ");
    gotoXY(x,y);y++;printf("  )  |  %c  `.___________|/ ", 92);
    gotoXY(x,y);y++;printf("  `--'   `--'               ");
	 
	textcolor(a2);
	caixa(55, 55, 55, 55, 85);
	x=58, y=11;

    gotoXY(x,y);y++;printf(" _ " );              
    gotoXY(x,y);y++;printf(" %c`*-. ", 92);            
    gotoXY(x,y);y++;printf("  )  _`-.");           
    gotoXY(x,y);y++;printf(" .  : `. . ");           
    gotoXY(x,y);y++;printf(" : _   '  %c ", 92);          
    gotoXY(x,y);y++;printf(" ; *` _.   `*-._ ");        
    gotoXY(x,y);y++;printf(" `-.-'          `-. ");   
    gotoXY(x,y);y++;printf("   ;       `       `. ");  
    gotoXY(x,y);y++;printf("   :.       .       %c ", 92);
    gotoXY(x,y);y++;printf("   . %c  .   :   .-'   . ", 92);
    gotoXY(x,y);y++;printf("   '  `+.;  ;  '      : ");
    gotoXY(x,y);y++;printf("   :  '  |    ;       ;-. ");
    gotoXY(x,y);y++;printf("   ; '   : :`-:     _.`* ; ");
    gotoXY(x,y);y++;printf(".*' /  .*' ; .*`- +'  `*' ");
    gotoXY(x,y);y++;printf("`*-*   `*-*  `*-*'        ");

   gotoXY(65,30);
   printf(" LOGIN", 181);
   back(a3);
	textcolor(a3);
    gotoXY(96,34);
    printf("S a i r");
   
   if(a==13){
        if(posX==30){
            incluir_Funcionario();
    		}
    	if(posX==60){
    		login_funcionario();
    		}
	    if(posX==94){
	    	system("cls");
	    	textcolor(15);
	    	exit(1);
		}
   
    }
}
//funcao de inclusao dos dados no arquivo
void incluir_Funcionario(){
	FILE *arqF;
	//ABRE O ARQUIVO EM ADIÇÃO TEXTO
	arqF = fopen("arquivoFuncio.txt", "a+");
	//VERIFICAÇÃO DE ABERTURA
	if(arqF==NULL){
		mensagem2();
		textcolor(12);
		gotoXY(37,19);
		printf("P  A  G  E    N  O  T    F  O  U  N  D ");
		getchar();
		system("cls");
		escolha2(1);
	}
	//COLETA OS DADOS DO USUÁRIO
	system("cls");
	//Menu
	DadosPessoaisInter();
	//______________________ DADOS PESSOAIS_______________________________________________________________________________ 
	
	hidecursor();
	telaDadosPessoais(11,7,7,7,7,7);
    entradas(31,8,7,nome_F,50, 1);
	setbuf(stdin, NULL);
	strcpy(F.D_P_F.nome_F,nome_F);
	setbuf(stdin, NULL);
	
		
	hidecursor();	
	telaDadosPessoais(7,11,7,7,7,7);
	entradasCPFF(30,13,7,cpf_F,11);
	setbuf(stdin, NULL);
	strcpy(F.D_P_F.cpf_F,cpf_F);
	setbuf(stdin, NULL);
	
	//______________________ DADOS PROFISSIONAIS_______________________________________________________________________________ 
	
	hidecursor();
	telaDadosPessoais(7,7,11,7,7,7);
	entradas(62,13,7,funcao,10,3);
	setbuf(stdin, NULL);
	strcpy(F.D_P_F.funcao,funcao);
	setbuf(stdin, NULL);			
		
	//______________________ DADOS PESSOAIS_______________________________________________________________________________ 
		
	hidecursor();
	telaDadosPessoais(7,7,7,11,7,7);
	entradas(45,18,7,DataN_F,10, 2);
	setbuf(stdin, NULL);
	strcpy(F.D_P_F.DataN_F,DataN_F);
	setbuf(stdin, NULL);
	
	//______________________ DADOS PROFISSIONAIS_______________________________________________________________________________ 
	
	hidecursor();
	telaDadosPessoais(7,7,7,7,11,7);
	pesquisa_codigo(43,23,7,codigo,6);
	setbuf(stdin, NULL);
	strcpy(F.D_P_F.codigo,codigo);
	setbuf(stdin, NULL);
	
	hidecursor();

	//	Seta 
	telaDadosPessoais(7,7,7,7,7,11);
	int a;
	do{
		a = getch();
	}while(a!=13);

	//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
	system("cls");
	setbuf(stdin, NULL);
	enderecoInter();
	hidecursor();
	telaEndereco(11,7,7,7,7,7,7);
	entradas(30,8,7,rua,30, 0);
	setbuf(stdin, NULL);
	strcpy(F.D_E_F.rua,rua);
	setbuf(stdin, NULL);

	hidecursor();
	telaEndereco(7,11,7,7,7,7,7);
	entradas(33,13,7,bairro,30,0);
	setbuf(stdin, NULL);
	strcpy(F.D_E_F.bairro,bairro);
	setbuf(stdin, NULL);

	hidecursor();
	telaEndereco(7,7,11,7,7,7,7);
	entradas(33,18,7,cidade,11,1);
	setbuf(stdin, NULL);
	strcpy(F.D_E_F.cidade,cidade);
	setbuf(stdin, NULL);

	hidecursor();
	telaEndereco(7,7,7,11,7,7,7);
	entradas(65,18,7,teleF,10,2);
	setbuf(stdin, NULL);
	strcpy(F.D_P_F.teleF,teleF);
	
	hidecursor();
	telaEndereco(7,7,7,7,11,7,7);
	entradas(30,23,7,cep,9,2);	
	setbuf(stdin, NULL);
	strcpy(F.D_E_F.cep,cep);
	setbuf(stdin, NULL);
	
	hidecursor();
	telaEndereco(7,7,7,7,7,11,7);
	entradas(59,23,7,uf,2,1);	
	setbuf(stdin, NULL);
	strcpy(F.D_E_F.uf,uf);
	setbuf(stdin, NULL);
	
	hidecursor();
	telaEndereco(7,7,7,7,7,7,11);
	do{
	   a = getch();
	}while(a!=13);
	
	system("cls");
	setbuf(stdin, NULL);
	//Função que escreve no arquivo o conteudo armazenado na variavel F
	fwrite(&F, sizeof(Cadastro_F), 1, arqF);
	//Função para fechar o arquivo

	fclose(arqF);
	system("cls");
	mensagem1();
	
	if((strcmp(F.D_P_F.funcao,"GERENTE")==0)){
		system("cls");
		posMenu_vendas(2);
	}
	else{
		if((strcmp(F.D_P_F.funcao,"ATENDENTE")==0)){
			system("cls");
			escolha2(2);
		}
	}
}
//funcao de busca de dados do arquivo
void busca_Funcionario(){
	int x=0,y=0;
	//Função que faz a consulta dos funcionarios
	system("cls");
	//Declaracao e inicializacao do arquivo
	FILE *arqF;
	arqF = fopen("arquivoFuncio.txt","r");
	
	if(arqF==NULL){
		mensagem2();
		textcolor(12);
		gotoXY(40,24);
		printf("  Nenhum cadastro realizado!\n");
		getchar();
		system("cls");
		escolha2(1);
	}
	else{
		int total = 0;
   		int cont = 1;
   		//caixinha para ir ao pedido anterior
   		while(fread(&F,sizeof(Cadastro_F),1,arqF)) total++;
			rewind(arqF);
		while(fread(&F, sizeof(Cadastro_F), 1, arqF)){
			system("cls");
		   	//imprimir dados
			larapet2();
	   		caixa_branca1(24,25,24);
			gotoXY(89,28);
	        textcolor(11);
	        printf(">>");
	        gotoXY(85,29);
	        textcolor(11);
	        printf(" Proximo");
			//Exibe as informações do funcionario	
		gotoXY(45,9);
		textcolor(2);
		printf("DADOS CADASTRAIS ");
		gotoXY(21,11);
		textcolor(2);
		printf("Nome:");
		gotoXY(26,11);
		textcolor(11);
		puts(F.D_P_F.nome_F);
		setbuf(stdin, NULL);
		
		gotoXY(21,12);
		textcolor(2);
		printf("CPF:");
		textcolor(11);
		gotoXY(25,12);
		puts(F.D_P_F.cpf_F);
		setbuf(stdin, NULL);
			
		gotoXY(21,13);
		textcolor(2);
		printf("Data de nascimento:");
		textcolor(11);
		gotoXY(41,13);
		puts(F.D_P_F.DataN_F);
		setbuf(stdin, NULL);
			
		gotoXY(21,14);
		textcolor(2);
		printf("Telefone:");
		textcolor(11);
		gotoXY(30,14);
		puts(F.D_P_F.teleF);
		//______________________TELA DE DADOS PROFISSIONAIS_____________________________________________________________________________________________________________________________________________________________________________________________________________ 
		
		gotoXY(21,16);
		textcolor(2);
		printf("C%cdigo de acesso:",162);
		textcolor(11);
		gotoXY(38,16);y++;
		puts(F.D_P_F.codigo);
		setbuf(stdin, NULL);
		
		gotoXY(21,17);
		textcolor(2);
		printf("Cargo:");
		textcolor(11);
		gotoXY(27,17);
		puts(F.D_P_F.funcao);
		setbuf(stdin, NULL);
		
			//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
		
		
		gotoXY(21,19);
		textcolor(2);
		printf("Rua:");
		textcolor(11);
		gotoXY(25,19);
		puts(F.D_E_F.rua);
		setbuf(stdin, NULL);
		
		gotoXY(21,20);
		textcolor(2);
		printf("Bairro:");
		textcolor(11);
		gotoXY(28,20);
		puts(F.D_E_F.bairro);
		setbuf(stdin, NULL);
		
		gotoXY(21,21);
		textcolor(2);
		printf("Cidade:");
		textcolor(11);
		gotoXY(28,21);y++;
		puts(F.D_E_F.cidade);
		setbuf(stdin, NULL);
		
		gotoXY(21,22);
		textcolor(2);
		printf("UF:");
		textcolor(11);
		gotoXY(24,22);y++;
		puts(F.D_E_F.uf);	
		setbuf(stdin, NULL);
		
		
		gotoXY(21,23);
		textcolor(2);
		printf("Cep:");
		textcolor(11);
		gotoXY(25,23);
		puts(F.D_E_F.cep);	
		setbuf(stdin, NULL);
		
		gotoXY(76,10);
		textcolor(7);
		printf("%.2d / %.2d", cont, total);
		if(total==cont){
			gotoXY(89,28);
	        textcolor(11);
	        printf("   ");
	        gotoXY(85,29);
	        textcolor(11);
	        printf("        ");
			
			gotoXY(41,35);
	        textcolor(7);
	  		printf("                                      \n");
			gotoXY(42,35);
	        textcolor(7);
	  		printf("PRESSIONE ESC PARA SAIR \n");
		}
		int tecla;
        do {
            tecla = getch();
			if (tecla == ESC) {
                fclose(arqF);
                system("cls");
				mensagem1();
				system("cls");
				posMenu_vendas(2);
            } 
			else{
				if (tecla == DIREITA && cont < total) {
        			cont++; // Só pra contar a quantidade de pedidos.
    			} 
				else{
                	tecla = ENTER;
                }
            }
        }while (tecla == ENTER);
		int i=0;
		for(i=11;i<27;i++){
			x=21;
			gotoXY(x, i);
	        printf("                                                                                  ");
		}
	}
	}

	fclose(arqF);
	setbuf(stdin, NULL);
	getch();
	posMenu_vendas(2);

}
void gravata(){
     caixa_branca(31,32,31);
	caixaJ(7,  14, 24, 2, 56);
	caixaJ(7,  19, 24, 2, 56);
	int x=47, y=2;
	setbuf(stdin, NULL);
	textcolor(7);
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	textcolor(4);
	gotoXY(x,y);y++;printf("   \xDB\xDB\xDB");
	gotoXY(x,y);y++;printf("   \xDB\xDB\xDB");
	textcolor(7);
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf("\xDB       \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	gotoXY(x,y);y++;printf("    \xDB");
}
//------------------------------------------------------
void altera_Funcionario(){
	//FUNÇÃO QUE ALTERA OS DADOS DO USUARIO
	system("cls");
	
	FILE *arqAUX_F;  //arquivo auxiliar
	FILE *arqF;		//arquivo principal
	int encontrado=FALSE; //variavel para indicar se foi encontrado
	char cpf_f[11],codigo_f[10];
	
	//Abertura do arquivo principal
	arqF = fopen("arquivoFuncio.txt","r");
	
	if(arqF==NULL){
		mensagem2();
		textcolor(12);
		gotoXY(37,19);
		printf("P  A  G  E    N  O  T    F  O  U  N  D ");
		getchar();
		system("cls");
		escolha2(1);
	}
	
	//Recebendo dados de login para comparar
	system("cls");
	gravata();
	textcolor(7);
	gotoXY(26,16); 
	printf("Digite o codigo de acesso da conta: ");
	gotoXY(26,21); 
	printf("CPF:");
	gotoXY(61,16);
	gets(codigo_f);
	gotoXY(30,21); 
	gets(cpf_f);
	//Loop para ler todos os dados do arquivo e pesquisa
	while(fread(&F, sizeof(Cadastro_F), 1, arqF)){
		if((strcmp(F.D_P_F.codigo, codigo_f)==0)&&(strcmp(F.D_P_F.cpf_F, cpf_f)==0)){ //pesquise se esse codigo de acesso existe e o //pesquise se esse CPF existe
			encontrado=TRUE;
		break; //para tudo parsa
		}
	}
	system("cls");
	setbuf(stdin, NULL);
	//Condição caso não seja encontrado
	if(!encontrado){
		fclose(arqF);
		mensagem2();
		textcolor(12);
		gotoXY(42,24);
		printf("Cadastro n%co encontrado!\n",198);
		getch();
		setbuf(stdin, NULL);
		system("cls");
		posMenu_vendas(2);
		
	}	
	//Exibe as informações do funcionario

	//imprimir dados/
	system("cls");	
	larapet2();
	caixa_branca1(24, 25,24);
	//Exibe as informações do funcionario	
	gotoXY(45,9);
	textcolor(2);
	printf("DADOS CADASTRAIS ");
	gotoXY(21,11);
	textcolor(2);
	printf("Nome: ");
	gotoXY(26,11);
	textcolor(11);
	puts(F.D_P_F.nome_F);
	setbuf(stdin, NULL);
	
	gotoXY(21,12);
	textcolor(2);
	printf("CPF:");
	textcolor(11);
	gotoXY(25,12);
	puts(F.D_P_F.cpf_F);
	setbuf(stdin, NULL);
		
	gotoXY(21,13);
	textcolor(2);
	printf("Data de nascimento:");
	textcolor(11);
	gotoXY(41,13);
	puts(F.D_P_F.DataN_F);
	setbuf(stdin, NULL);
		
	gotoXY(21,14);
	textcolor(2);
	printf("Telefone:");
	textcolor(11);
	gotoXY(30,14);
	puts(F.D_P_F.teleF);
	//______________________TELA DE DADOS PROFISSIONAIS_____________________________________________________________________________________________________________________________________________________________________________________________________________ 
	
	gotoXY(21,16);
	textcolor(2);
	printf("C%cdigo de acesso:",162);
	textcolor(11);
	gotoXY(38,16);
	puts(F.D_P_F.codigo);
	setbuf(stdin, NULL);
	
	gotoXY(21,17);
	textcolor(2);
	printf("Cargo:");
	textcolor(11);
	gotoXY(27,17);
	puts(F.D_P_F.funcao);
	setbuf(stdin, NULL);
	
		//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
	
	
	gotoXY(21,19);
	textcolor(2);
	printf("Rua:");
	textcolor(11);
	gotoXY(25,19);
	puts(F.D_E_F.rua);
	setbuf(stdin, NULL);
	
	gotoXY(21,20);
	textcolor(2);
	printf("Bairro:");
	textcolor(11);
	gotoXY(28,20);
	puts(F.D_E_F.bairro);
	setbuf(stdin, NULL);
	
	gotoXY(21,21);
	textcolor(2);
	printf("Cidade:");
	textcolor(11);
	gotoXY(28,21);
	puts(F.D_E_F.cidade);
	setbuf(stdin, NULL);
	
	gotoXY(21,22);
	textcolor(2);
	printf("UF:");
	textcolor(11);
	gotoXY(24,22);
	puts(F.D_E_F.uf);	
	setbuf(stdin, NULL);
	
	
	gotoXY(21,23);
	textcolor(2);
	printf("Cep:");
	textcolor(11);
	gotoXY(25,23);
	puts(F.D_E_F.cep);	
	setbuf(stdin, NULL);

	gotoXY(40,36);
	textcolor(7);
	printf("PRESSIONE ENTER PARA ALTERAR\n");
	
	getch();
	system("cls");
	setbuf(stdin, NULL);
	
	//COLETA OS DADOS DO USUÁRIO PARA ALTERAR
	DadosPessoaisInter();
	//______________________ DADOS PESSOAIS_______________________________________________________________________________ 
	
	hidecursor();
	telaDadosPessoais(11,7,7,7,7,7);
	gotoXY(31,8);
	textcolor(7);
	setbuf(stdin, NULL);
	fgets(F.D_P_F.nome_F,50,stdin);
	setbuf(stdin, NULL);
	
	hidecursor();
	telaDadosPessoais(7,11,7,7,7,7);
	gotoXY(30,13);
	textcolor(7);
	setbuf(stdin, NULL);
	fgets(F.D_P_F.cpf_F,12,stdin);
	setbuf(stdin, NULL);
	
	
	//______________________ DADOS PROFISSIONAIS_______________________________________________________________________________ 
	
	hidecursor();
	telaDadosPessoais(7,7,11,7,7,7);
	gotoXY(62,13);
	textcolor(7);
	setbuf(stdin, NULL);
	gets(funcao);
	strupr(funcao);
	strcpy(F.D_P_F.funcao,funcao);
	setbuf(stdin, NULL);
	
		
	//______________________ DADOS PESSOAIS_______________________________________________________________________________ 
	
	hidecursor();
	telaDadosPessoais(7,7,7,11,7,7);
	gotoXY(45,18);
	textcolor(7);
	setbuf(stdin, NULL);
	fgets(F.D_P_F.DataN_F,10,stdin);
	setbuf(stdin, NULL);
		
	
	//______________________ DADOS PROFISSIONAIS_______________________________________________________________________________ 
	getchar();
	hidecursor();
	telaDadosPessoais(7,7,7,7,11,7);
	gotoXY(43,23);
	textcolor(7);
	setbuf(stdin, NULL);
	fgets(F.D_P_F.codigo,9,stdin);
	setbuf(stdin, NULL);
	
	hidecursor();

	//	Seta 
	telaDadosPessoais(7,7,7,7,7,11);
	int a;
	do{
		a = getch();
	}while(a!=13);

	//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
	system("cls");
	setbuf(stdin, NULL);
	enderecoInter();
	
	hidecursor();
	telaEndereco(11,7,7,7,7,7,7);
	gotoXY(30,8);
	textcolor(7);
	setbuf(stdin, NULL);
	fgets(F.D_E_F.rua,30,stdin);
	setbuf(stdin, NULL);
	

	hidecursor();
	telaEndereco(7,11,7,7,7,7,7);
	gotoXY(33,13);
	textcolor(7);
	setbuf(stdin, NULL);
	fgets(F.D_E_F.bairro,30,stdin);
	setbuf(stdin, NULL);
	
	
	hidecursor();
	telaEndereco(7,7,11,7,7,7,7);
	gotoXY(33,18);
	textcolor(7);
	setbuf(stdin, NULL);
	fgets(cidade,30,stdin);
	setbuf(stdin, NULL);
	
	
	hidecursor();
	telaEndereco(7,7,7,11,7,7,7);
	gotoXY(65,18);
	textcolor(7);
	setbuf(stdin, NULL);
	fgets(F.D_P_F.teleF,10,stdin);
	setbuf(stdin, NULL);
	

	hidecursor();
	telaEndereco(7,7,7,7,11,7,7);
	gotoXY(30,23);
	textcolor(7);
	setbuf(stdin, NULL);
	fgets(F.D_E_F.cep,9,stdin);
	setbuf(stdin, NULL);
	
	
	hidecursor();
	telaEndereco(7,7,7,7,7,11,7);
	gotoXY(65,23);
	textcolor(7);
	setbuf(stdin, NULL);
	fgets(F.D_E_F.uf,3,stdin);
	setbuf(stdin, NULL);
	
	hidecursor();
	telaEndereco(7,7,7,7,7,7,11);
	do{
	   a = getch();
	}while(a!=13);
	system("cls");
	mensagem1();
	getchar();
	system("cls");

	rewind(arqF);//Volta o indicador de posição do fluxo para a posição inicial. Isto é, o começo do arquivo
	if(arqF==NULL){
		fclose(arqF);
		mensagem2();
		textcolor(12);
		gotoXY(37,19);
		printf("P  A  G  E    N  O  T    F  O  U  N  D ");
		getch();
		system("cls");
		posMenu_vendas(2);
	}
	//Else para verificar se existe login um login igual a este
	else{
		Cadastro_F F_AUX;
		while(fread(&F_AUX, sizeof(Cadastro_F), 1,arqF)){
			if(strcmp(F.D_P_F.codigo,codigo_f)==0  && strcmp(F.D_P_F.codigo,codigo_f)!=0 ){
				fclose(arqF);
				system("cls");
				mensagem2();
				textcolor(12);
				gotoXY(37,19);
				printf("L O G I N     E X  I S T E N T E !");
				getch();
				system("cls");
				posMenu_vendas(2);
			}
		}
	}	
	fclose(arqF);
	
	arqAUX_F = fopen("arquivoFuncioAux.txt","a+");; //abre arquivo auxiliar em adição
	arqF = fopen("arquivoFuncio.txt","r+");   //abre arquivo principal em leitura
	rewind(arqF);
	//Verifica se arquivo foi aberto
	if(arqAUX_F ==NULL && arqF==NULL){
		fclose(arqF);
		mensagem2();
		textcolor(12);
		gotoXY(37,19);
		printf("P  A  G  E    N  O  T    F  O  U  N  D ");
		getch();
		system("cls");
		posMenu_vendas(2);

	}
	else{
		//Pega os dados alterados e passa para o arquivo auxiliar
		fwrite(&F, sizeof(Cadastro_F), 1, arqAUX_F);
		while(fread(&F, sizeof(Cadastro_F), 1, arqF)){
			if(strcmp(F.D_P_F.codigo,codigo_f)!= 0){
				fwrite(&F, sizeof(Cadastro_F), 1, arqAUX_F);
			}
		}
	}
	//Fecha o arquivo
	fclose(arqF);
	fclose(arqAUX_F);
	
	//Renomeia 
	remove("arquivoFuncio.txt");//
	rename("arquivoFuncioAux.txt", "arquivoFuncio.txt");//
 	system("cls");
	posMenu_vendas(2);
}
//------------------------------------------------------
void excluir_Funcionario(){
	//FUNÇÃO QUE ALTERA OS DADOS DO USUARIO
	FILE *arqAUX_F;  
	FILE *arqF;
	int encontrado=FALSE; //variavel para indicar se foi encontrado
	int a=0;
	char cpf_f[11],codigo_f[10];
	//Abertura do arquivo principal
	arqF = fopen("arquivoFuncio.txt","r");
	
	//Recebendo dados de login para comparar
	gravata();
	gotoXY(61,16);
	gets(codigo_f);
	gotoXY(30,21); 
	gets(cpf_f);
	//Loop para ler todos os dados do arquivo e pesquisa
	while(fread(&F, sizeof(Cadastro_F), 1, arqF)){
		if((strcmp(F.D_P_F.codigo, codigo_f)==0)&&(strcmp(F.D_P_F.cpf_F, cpf_f)==0)){ //pesquise se esse codigo de acesso existe e o //pesquise se esse CPF existe
			encontrado=TRUE;
		break; //para tudo parsa
		}
	}

	system("cls");
	setbuf(stdin, NULL);
	//Condição caso não seja encontrado
	if(!encontrado){
		gotoXY(42,11);
		textcolor(12);
		printf("Usu%crio n%co encontrado!\n",160,198);
		gotoXY(50,13);
		getchar();
		system("cls");
		fclose(arqF);
	//Retorna para munu do gerente 
	escolha2(1);
	}	
	//Exibe as informações do funcionario	
	system("cls");	
	larapet2();
	caixa_branca1(24, 25,24);
	gotoXY(45,9);
    textcolor(2);
	printf("DADOS CADASTRAIS ");
	gotoXY(21,11);
	textcolor(2);
	printf("Nome: ");
	gotoXY(26,11);
	textcolor(11);
	puts(F.D_P_F.nome_F);
	setbuf(stdin, NULL);
	
	gotoXY(21,12);
	textcolor(2);
	printf("CPF:");
	textcolor(11);
	gotoXY(25,12);
	puts(F.D_P_F.cpf_F);
 	setbuf(stdin, NULL);
		
	gotoXY(21,13);
	textcolor(2);
	printf("Data de nascimento:");
	textcolor(11);
	gotoXY(41,13);
	puts(F.D_P_F.DataN_F);
 	setbuf(stdin, NULL);
 		
	gotoXY(21,14);
	textcolor(2);
	printf("Telefone:");
	textcolor(11);
	gotoXY(30,14);
	puts(F.D_P_F.teleF);
	//______________________TELA DE DADOS PROFISSIONAIS_____________________________________________________________________________________________________________________________________________________________________________________________________________ 
	
	gotoXY(21,16);
	textcolor(2);
	printf("C%cdigo de acesso:",162);
	textcolor(11);
	gotoXY(38,16);
	puts(F.D_P_F.codigo);
	setbuf(stdin, NULL);

	gotoXY(21,17);
	textcolor(2);
	printf("Cargo:");
	textcolor(11);
	gotoXY(27,17);
	puts(F.D_P_F.funcao);
	setbuf(stdin, NULL);

		//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________

	
	gotoXY(21,19);
	textcolor(2);
	printf("Rua:");
	textcolor(11);
	gotoXY(25,19);
	puts(F.D_E_F.rua);
	setbuf(stdin, NULL);
	
	gotoXY(21,20);
	textcolor(2);
	printf("Bairro:");
	textcolor(11);
	gotoXY(28,20);
	puts(F.D_E_F.bairro);
	setbuf(stdin, NULL);
	
	gotoXY(21,21);
	textcolor(2);
	printf("Cidade:");
	textcolor(11);
	gotoXY(28,21);
	puts(F.D_E_F.cidade);
	setbuf(stdin, NULL);
	
	gotoXY(21,22);
	textcolor(2);
	printf("UF:");
	textcolor(11);
	gotoXY(24,22);
	puts(F.D_E_F.uf);	
	setbuf(stdin, NULL);
	
	
	gotoXY(21,23);
	textcolor(2);
	printf("Cep:");
	textcolor(11);
	gotoXY(25,23);
	puts(F.D_E_F.cep);	
	
	gotoXY(55,35);
	textcolor(7);
	printf("Pressione enter para desativar esta conta\n");
	getchar();
	system("cls");
	setbuf(stdin, NULL);
	
	
	arqAUX_F = fopen("arquivoFuncioAux.txt","r+");; //abre arquivo auxiliar em adição
	arqF = fopen("arquivoFuncio.txt","r");   //abre arquivo principal em leitura
	
	//Verifica se arquivo foi aberto
	if(arqAUX_F ==NULL && arqF==NULL){
		printf("Erro na abertura do arquivo\n");
		setbuf(stdin, NULL);
		Sleep(1000);
		posMenu_vendas(2);
	}
	else{
		while(fread(&F, sizeof(Cadastro_F), 1, arqF)){
			if(strcmp(F.D_P_F.codigo,codigo)!=0){
				fwrite(&F, sizeof(Cadastro_F), 1, arqAUX_F);
			}
		}
	}
	//Fecha os arquivos
	fclose(arqF);
	fclose(arqAUX_F);

	//Renomeia 

	remove("arquivoFuncio.txt");
	rename("arquivoFuncioAux.txt" ,"arquivoFuncio.txt"); // Renomeia
	
	system("cls");
	printf("Conta excluinda com sucesso !");
	getchar();
	posMenu_vendas(2);
}

void aten_loja(int a1,int a2, int a3, int posX, int a){
	textcolor(a1);
	int i, j;
     caixa(15, 15, 15, 15, 45);
     int x, y=9;
     int x1, x2;
     for(i=0; i<5; i++){
              x1=27;
              for(j=0;j<7;j++, x1++){
                  gotoXY(x1,y);
                  printf("\xDB");
              }
              y++;
     }
     for(i=0; i<5; i++){
              x=18;
              for(j=0;j<25;j++, x++){
                  gotoXY(x,y);
                  printf("\xDB");
              }
              y++;
     }
     for(i=0; i<9; i++){
              x2=27;
              for(j=0;j<7;j++, x2++){
                  gotoXY(x2,y);
                  printf("\xDB");
              }
              y++;
     }
    gotoXY(24,30);
    printf("ATENDIMENTO");
    
     textcolor(a2);
    x=62, y=9;
	caixa(55, 55, 55, 55, 85);
	
	//19 linhas
gotoXY(x,y);y++;
	printf("       \xDC\xDC\xDC\xDC\xDC      ");
	gotoXY(x,y);y++;
	printf("       \xDB\xDB\xDB\xDB\xDB      ");
    gotoXY(x,y);y++;
	printf("   \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB ");
	gotoXY(x,y);y++;
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoXY(x,y);y++;
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoXY(x,y);y++;
	printf("\xDB\xDB\xDB\xDB\xDB\xDB       \xDB\xDB\xDB\xDB\xDB");
	gotoXY(x,y);y++;
	printf("\xDB\xDB\xDB\xDB\xDB\xDB            ");
	gotoXY(x,y);y++;
	printf("\xDB\xDB\xDB\xDB\xDB\xDB            ");
    gotoXY(x,y);y++;
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB ");
	gotoXY(x,y);y++;
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB   ");
    gotoXY(x,y);y++;
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  ");
	gotoXY(x,y);y++;
	printf("   \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoXY(x,y);y++;
	printf("            \xDB\xDB\xDB\xDB\xDB\xDB");
	gotoXY(x,y);y++;
	printf("            \xDB\xDB\xDB\xDB\xDB\xDB");
	gotoXY(x,y);y++;
	printf("\xDB\xDB\xDB\xDB\xDB       \xDB\xDB\xDB\xDB\xDB\xDB");
	gotoXY(x,y);y++;
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoXY(x,y);y++;
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB ");
	gotoXY(x,y);y++;
	printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB   ");
    gotoXY(x,y);y++;
	printf("      \xDB\xDB\xDB\xDB\xDB       ");
    
    gotoXY(68,30);
    printf("LOJA");
    
    back(a3);
    textcolor(a3);
    gotoXY(97,34);
    printf("VOLTAR");
    if(a==13){
              if(posX==30){
                 system("cls");
                 posMenu_vendasEsp(6);
				}
	          if(posX==60){
                 system("cls");
                 //realizar compra
				}
              if(posX==22){
                escolha2(1);
     }   
    }
}
void posMenu_vendas(int i){ //Setinha de CRUD
    char a;
    int posX = 28, posY = 12;
        switch(i){//Escolhe qual menu aparece
                case 1:
                     system("cls");
                	menuVendas();
                break;
                case 2:
					menuGerente();
                break;
                case 3:
                	menuAtend();
                break;
            }
    desenha_caixa(11, 7, 7, 7, 7);
    do{      
        a = toupper(getch());
           
        switch(a)
        {
            case 'H':
                if (posY > 12){
                   switch(posY){
                                case 18:
                                     posY-=6;
                                     desenha_caixa(11, 7, 7, 7, 7);
                                     break;
                                case 24:
                                     posY-=6;
									 desenha_caixa(7, 11, 7, 7, 7);
                                     break;
                                case 30:
                                     posY-=6;
                                     desenha_caixa(7, 7, 11, 7, 7);
                                     break;
                                case 34:     
                                     posY-=4; 
									 desenha_caixa(7, 7, 7, 11, 7);
                                     break;
                    } 
                }
            break;
           
            case 'P':
                if (posY <=30){
                         switch(posY){
                                case 12:
                                     posY+=6;
                                     desenha_caixa(7, 11, 7, 7, 7);
                                     break;
                                case 18:
                                     posY+=6;
                                     desenha_caixa(7, 7, 11, 7, 7);
                                     break;
                                case 24:
                                     posY+=6;
                                     desenha_caixa(7, 7, 7, 11, 7);
                                     break;
                                case 30:
                                     posY+=4;
                                     desenha_caixa(7, 7, 7, 7, 11);
                                     break;
                         }         
                    }
            break;
            case 13:
            	trocaCor(i, posY);
           	break;
    }
   
    }while(a!=13);
}
//funcao de inclusao dos dados no arquivo
void incluir_Cliente(){
	FILE *arqC;
	int a=0;
	//ABRE O ARQUIVO EM ADIÇÃO TEXTO
	arqC = fopen("arquivoCliente.txt", "a+");
	if(arqC==NULL){
		mensagem2();
		textcolor(12);
		gotoXY(37,19);
		printf("P  A  G  E    N  O  T    F  O  U  N  D ");
		getchar();
		system("cls");
		escolha2(1);
	}
	//COLETA OS DADOS DO USUÁRIO
		system("cls");
		//Menu
		Dados_Cliente_Pet_Inter();
		//______________________ DADOS PESSOAIS_______________________________________________________________________________ 
		
		hidecursor();
		TelaDados_Cliente_Pet_Inter(11,7,7,7,7);
        entradas(31,8,7,nome_C,34, 1);
		setbuf(stdin, NULL);
		strcpy(C.D_P_C.nome_C,nome_C);
		setbuf(stdin, NULL);
		
		hidecursor();	
		TelaDados_Cliente_Pet_Inter(7,11,7,7,7);
		entradasCPF(30,13,7,cpf_C,11);
		setbuf(stdin, NULL);
		strcpy(C.D_P_C.cpf_C,cpf_C);
		setbuf(stdin, NULL);
		
		hidecursor();
		TelaDados_Cliente_Pet_Inter(7,7,11,7,7);
		entradas(45,18,7,DataN_C,10, 2);
		setbuf(stdin, NULL);
		strcpy(C.D_P_C.DataN_C,DataN_C); 
		setbuf(stdin, NULL);
		//______________________ DADOS PET _______________________________________________________________________________ 
		
		hidecursor();
		TelaDados_Cliente_Pet_Inter(7,7,7,11,7);
		entradas(38,23,7,nome_Pet,34,1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.nome_Pet,nome_Pet);
		setbuf(stdin, NULL);
		
		hidecursor();	
		//	Seta 
		TelaDados_Cliente_Pet_Inter(7,7,7,7,11);
		do{
		a = getch();
		}while(a!=13);
		
		system("cls");
		Dados_Animal_Inter();
		hidecursor();
		TelaDados_Cliente_Pet_Inter(11,7,7,7,7);
        entradas(47,8,7,microchip,19,0);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.microchip,microchip);
		setbuf(stdin, NULL);
		
		hidecursor();	
		TelaDados_Cliente_Pet_Inter(7,11,7,7,7);
		entradas(34,13,7,especie,19,1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.especie,especie);
		setbuf(stdin, NULL);
		
		hidecursor();
		TelaDados_Cliente_Pet_Inter(7,7,11,7,7);
		entradas(45,18,7,dataN_Pet,10,2);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.dataN_Pet,dataN_Pet); 
		setbuf(stdin, NULL);
		
		hidecursor();
		TelaDados_Cliente_Pet_Inter(7,7,7,11,7);
		entradas(31,23,7,raca,9,1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.raca,raca);
		setbuf(stdin, NULL);
		
		hidecursor();	
		//	Seta 
		TelaDados_Cliente_Pet_Inter(7,7,7,7,11);
		do{
		a = getch();
		}while(a!=13);
		
		system("cls");
		setbuf(stdin,NULL);
		Dados_Pet_Inter();
		hidecursor();
		TelaDados_Animal_Inter(11,7,7,7,7);
        entradas(30,8,7,cor,19, 1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.cor,cor);
		setbuf(stdin, NULL);
		
		hidecursor();	
		TelaDados_Animal_Inter(7,11,7,7,7);
		entradas(61,8,7,sexo,7,1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.sexo,sexo);
		setbuf(stdin, NULL);
		
		hidecursor();
		TelaDados_Animal_Inter(7,7,11,7,7);
		entradas(35,13,7,castrado,9, 1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.castrado,castrado); 
		setbuf(stdin, NULL);
		
		hidecursor();
		TelaDados_Animal_Inter(7,7,7,11,7);
		entradas(49,18,7,Obs,29,0);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.Obs,Obs);
		setbuf(stdin, NULL);
		TelaDados_Animal_Inter(7,7,7,7,11);
		do{
		a = getch();
		}while(a!=13);
	//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
		system("cls");
		setbuf(stdin,NULL);
		enderecoInter();
		hidecursor();
		telaEndereco(11,7,7,7,7,7,7);
		entradas(30,8,7,rua,25, 0);
		setbuf(stdin, NULL);
		strcpy(C.D_E_C.rua,rua);
		setbuf(stdin, NULL);

		hidecursor();
		telaEndereco(7,11,7,7,7,7,7);
		entradas(33,13,7,bairro,29,0);
		setbuf(stdin, NULL);
		strcpy(C.D_E_C.bairro,bairro);
		setbuf(stdin, NULL);

		hidecursor();
		telaEndereco(7,7,11,7,7,7,7);
		entradas(33,18,7,cidade,11,1);
		setbuf(stdin, NULL);
		strcpy(C.D_E_C.cidade,cidade);
		setbuf(stdin, NULL);

		hidecursor();
		telaEndereco(7,7,7,11,7,7,7);
		entradas(65,18,7,teleC,10,2);
		setbuf(stdin, NULL);
		strcpy(C.D_P_C.teleC,teleC);
		
		hidecursor();
		telaEndereco(7,7,7,7,11,7,7);
		entradas(30,23,7,cep,9,2);	
		setbuf(stdin, NULL);
		strcpy(C.D_E_C.cep,cep);
		setbuf(stdin, NULL);
		
		hidecursor();
		telaEndereco(7,7,7,7,7,11,7);
		entradas(65,23,7,uf,2,1);	
		setbuf(stdin, NULL);
		strcpy(C.D_E_C.uf,uf);
		setbuf(stdin, NULL);
		
		hidecursor();
		telaEndereco(7,7,7,7,7,7,11);
		do{
		   a = getch();
		}while(a!=13);
		
		system("cls");
		fflush(stdin);
		//Função que escreve no arquivo o conteudo armazenado na variavel F
		fwrite(&C, sizeof(Cadastro_C), 1, arqC);
		//Função para fechar o arquivo
	
		fclose(arqC);
		system("cls");
		printf("Cadastro Salvo com sucesso!");
}
//funcao de busca de dados do arquivo
void busca_Cliente(){
	int x=0,y=0;
	//Função que faz a consulta dos funcionarios
	system("cls");
	//Declaracao e inicializacao do arquivo
	FILE *arqC;
	
	arqC = fopen("arquivoCliente.txt","r");
	
	if(arqC==NULL){
		mensagem2();
		textcolor(12);
		gotoXY(40,24);
		printf("  Nenhum cadastro realizado!\n");
		getchar();
		system("cls");
		escolha2(1);
	}
	else{
		int total = 0;
   		int cont = 1;
   		//caixinha para ir ao pedido anterior
   		while(fread(&C,sizeof(Cadastro_C),1,arqC)) total++;
		rewind(arqC);
		while(fread(&C, sizeof(Cadastro_C), 1, arqC)){
			larapet2();
	   		caixa_branca2(27, 28 ,27);
			gotoXY(41,35);
	        textcolor(7);
	  		printf("PRESSIONE ENTER PARA O PR%cXIMO \n", 224);
	  		gotoXY(13,28);
	        textcolor(11);
	        printf("<<");
	        gotoXY(9,29);
	        textcolor(11);
	        printf(" Anterior");
	        gotoXY(89,28);
	        textcolor(11);
	        printf(">>");
	        gotoXY(85,29);
	        textcolor(11);
	        printf(" Proximo");
			x=21;y=11;
			gotoXY(40,9);
		    textcolor(2);
			printf("DADOS CADASTRAIS CLEINTE/PET ");
			gotoXY(x,y);
			textcolor(2);
			printf("Nome:");
			gotoXY(x+5,y);y++;
        	textcolor(11);
			puts(C.D_P_C.nome_C);
			setbuf(stdin, NULL);
			
			gotoXY(x,y);
			textcolor(2);
			printf("CPF:");
			textcolor(11);
			gotoXY(x+4,y);y++;
			puts(C.D_P_C.cpf_C);
		 	setbuf(stdin, NULL);
				
			gotoXY(x,y);
			textcolor(2);
			printf("Data de nascimento:");
			textcolor(11);
			gotoXY(x+19,y);y+=2;
			puts(C.D_P_C.DataN_C);
		 	setbuf(stdin, NULL);
		 	
			gotoXY(x,y);
			textcolor(2);
			printf("Nome do Pet:");
			textcolor(11);
			gotoXY(x+12,y);y++;
			puts(C.D_A_C.nome_Pet);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Microchip:");
			textcolor(11);
			gotoXY(x+10,y);
			puts(C.D_A_C.microchip);
			
			gotoXY(x+23,y);
			textcolor(2);
			printf("Especie:");
			textcolor(11);
			gotoXY(x+31,y);
			puts(C.D_A_C.especie);
			
			gotoXY(x+45,y);
			textcolor(2);
			printf("Ra%ca:",135);
			textcolor(11);
			gotoXY(x+50,y);y++;
			puts(C.D_A_C.raca);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Data de nascimento do pet:");
			textcolor(11);
			gotoXY(x+26,y);y++;
			puts(C.D_A_C.dataN_Pet);
			
			
			gotoXY(x,y);
			textcolor(2);
			printf("Cor:");
			textcolor(11);
			gotoXY(x+4,y);
			puts(C.D_A_C.cor);
			
			gotoXY(x+15,y);
			textcolor(2);
			printf("Sexo:");
			textcolor(11);
			gotoXY(x+20,y);
			puts(C.D_A_C.sexo);
			
			gotoXY(x+27,y);
			textcolor(2);
			printf("Castrado:");
			textcolor(11);
			gotoXY(x+37,y);y++;
			puts(C.D_A_C.castrado);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Obs sobre o pet:");
			textcolor(11);
			gotoXY(x+15,y);y+=2;
			puts(C.D_A_C.Obs);	
			setbuf(stdin, NULL);
			
			gotoXY(x,y);
			textcolor(2);
			printf("TELEFONE:");
			textcolor(11);
			gotoXY(x+9,y);y++;
			puts(F.D_P_F.teleF);
			
	//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
		
			
			gotoXY(x,y);
			textcolor(2);
			printf("RUA:");
			textcolor(11);
			gotoXY(x+4,y);y++;
			puts(C.D_E_C.rua);
			setbuf(stdin, NULL);
			
			gotoXY(x,y);
			textcolor(2);
			printf("BAIRRO:");
			textcolor(11);
			gotoXY(x+7,y);y++;
			puts(C.D_E_C.bairro);
			setbuf(stdin, NULL);
			
			gotoXY(x,y);
			textcolor(2);
			printf("CIDADE:");
			textcolor(11);
			gotoXY(x+7,y);
			puts(C.D_E_C.cidade);
			setbuf(stdin, NULL);
			
			gotoXY(x+17,y);
			textcolor(2);
			printf("UF:");
			textcolor(11);
			gotoXY(x+20,y);y++;
			puts(C.D_E_C.uf);	
			setbuf(stdin, NULL);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Cep:");
			textcolor(11);
			gotoXY(x+4,y);y++;
			puts(C.D_E_C.cep);	
			setbuf(stdin, NULL);
			
			gotoXY(76,10);
    		textcolor(7);
			printf("%.2d / %.2d", cont, total);
			int tecla;
             do {
                tecla = getch();

                if (tecla == ESC) {
                    fclose(arqC);
                    escolha2(1);
                } 
				else
					if (tecla == ESQUERDA && cont > 1) {
                    	cont--; // Só pra contar a quantidade de pedidos.
                    	fseek(arqC,-sizeof(Cadastro_C) * 2, SEEK_CUR); // Isso aqui é o que faz voltar.
                	}	 
					else
						if (tecla == DIREITA && cont < total) {
                    			cont++; // Só pra contar a quantidade de pedidos.
                		} 
						else 
                    		tecla = ENTER;
            }while (tecla == ENTER);
			int i=0;
			for(i=11;i<27;i++){
				x=21;
				gotoXY(x, i);
		        printf("                                                                                  ");
			}
		}
	}
	fclose(arqC);
	escolha2(1);
	
}

//------------------------------------------------------
void altera_Cliente(){
	//FUNÇÃO QUE ALTERA OS DADOS DO USUARIO
	FILE *arqAUX_C;  //arquivo auxiliar
	FILE *arqC;
	int encontrado=FALSE; //variavel para indicar se foi encontrado
	
	//Abertura do arquivo principal
	arqC = fopen("arquivoCliente.txt","r");
	
	//Recebendo dados de login para comparar
    gravata();
	textcolor(7);
	gotoXY(26,16); 
	showcursor();
	printf("Digite o CPF do Cliente: ");
	gotoXY(26,21); 
	printf("Nome do Pet: ");
	gotoXY(51,16);
	gets(cpf_C);
	gotoXY(39,21); 
	gets(nome_Pet);
	//Loop para ler todos os dados do arquivo e pesquisa
	while(fread(&C, sizeof(Cadastro_C), 1, arqC)){
		if((strcmp(C.D_P_C.cpf_C, cpf_C)==0)&&(strcmp(C.D_A_C.nome_Pet,nome_Pet)==0)){ //pesquise se esse codigo de acesso existe e o //pesquise se esse CPF existe
			encontrado=TRUE;
		break; //para tudo parsa
		}
	}

	system("cls");
	setbuf(stdin, NULL);
	//Condição caso não seja encontrado
	if(!encontrado){
		gotoXY(42,11);
		textcolor(12);
		printf("Usu%crio n%co encontrado!\n",160,198);
		gotoXY(50,13);
		getchar();
		system("cls");
		fclose(arqC);
	//Retorna para munu do gerente 
	escolha2(2);
	}	
	system("cls");

	//Exibe as informações do funcionario

	//imprimir dados
		larapet2();
   		caixa_branca2(27, 28,27);
		int x=21,y=11;
		gotoXY(40,9);
	    textcolor(2);
		printf("DADOS CADASTRAIS CLEINTE/PET ");
		gotoXY(x,y);
		textcolor(2);
		printf("Nome:");
		gotoXY(x+5,y);y++;
    	textcolor(11);
		puts(C.D_P_C.nome_C);
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("CPF:");
		textcolor(11);
		gotoXY(x+4,y);y++;
		puts(C.D_P_C.cpf_C);
	 	setbuf(stdin, NULL);
			
		gotoXY(x,y);
		textcolor(2);
		printf("Data de nascimento:");
		textcolor(11);
		gotoXY(x+19,y);y+=2;
		puts(C.D_P_C.DataN_C);
	 	setbuf(stdin, NULL);
	 	
		gotoXY(x,y);
		textcolor(2);
		printf("Nome do Pet:");
		textcolor(11);
		gotoXY(x+12,y);y++;
		puts(C.D_A_C.nome_Pet);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Microchip:");
		textcolor(11);
		gotoXY(x+10,y);
		puts(C.D_A_C.microchip);
		
		gotoXY(x+23,y);
		textcolor(2);
		printf("Especie:");
		textcolor(11);
		gotoXY(x+31,y);
		puts(C.D_A_C.especie);
		
		gotoXY(x+45,y);
		textcolor(2);
		printf("Ra%ca:",135);
		textcolor(11);
		gotoXY(x+50,y);y++;
		puts(C.D_A_C.raca);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Data de nascimento do pet:");
		textcolor(11);
		gotoXY(x+26,y);y++;
		puts(C.D_A_C.dataN_Pet);
		
		
		gotoXY(x,y);
		textcolor(2);
		printf("Cor:");
		textcolor(11);
		gotoXY(x+4,y);
		puts(C.D_A_C.cor);
		
		gotoXY(x+15,y);
		textcolor(2);
		printf("Sexo:");
		textcolor(11);
		gotoXY(x+20,y);
		puts(C.D_A_C.sexo);
		
		gotoXY(x+27,y);
		textcolor(2);
		printf("Castrado:");
		textcolor(11);
		gotoXY(x+37,y);y++;
		puts(C.D_A_C.castrado);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Obs sobre o pet:");
		textcolor(11);
		gotoXY(x+15,y);y+=2;
		puts(C.D_A_C.Obs);	
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("TELEFONE:");
		textcolor(11);
		gotoXY(x+9,y);y++;
		puts(F.D_P_F.teleF);
		
//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
	
		
		gotoXY(x,y);
		textcolor(2);
		printf("RUA:");
		textcolor(11);
		gotoXY(x+4,y);y++;
		puts(C.D_E_C.rua);
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("BAIRRO:");
		textcolor(11);
		gotoXY(x+7,y);y++;
		puts(C.D_E_C.bairro);
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("CIDADE:");
		textcolor(11);
		gotoXY(x+7,y);
		puts(C.D_E_C.cidade);
		setbuf(stdin, NULL);
		
		gotoXY(x+17,y);
		textcolor(2);
		printf("UF:");
		textcolor(11);
		gotoXY(x+20,y);y++;
		puts(C.D_E_C.uf);	
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Cep:");
		textcolor(11);
		gotoXY(x+4,y);y++;
		puts(C.D_E_C.cep);	
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Cep:");
		textcolor(11);
		gotoXY(x+4,y);y++;
		puts(F.D_E_F.cep);	
		setbuf(stdin, NULL);
		
		gotoXY(41,35);
		textcolor(7);
		printf("PRESSIONE ENTER PARA ALTERAR\n");
		getchar();
		system("cls");
		setbuf(stdin, NULL);
		
		//COLETA OS DADOS DO USUÁRIO
		system("cls");
		//Menu
		Dados_Cliente_Pet_Inter();
		//______________________ DADOS PESSOAIS_______________________________________________________________________________ 
		
		hidecursor();
		TelaDados_Cliente_Pet_Inter(11,7,7,7,7);
        entradas(31,8,7,nome_C,34, 1);
		setbuf(stdin, NULL);
		strcpy(C.D_P_C.nome_C,nome_C);
		setbuf(stdin, NULL);
		
		hidecursor();	
		TelaDados_Cliente_Pet_Inter(7,11,7,7,7);
		entradasCPF(30,13,7,cpf_C,11);
		setbuf(stdin, NULL);
		strcpy(C.D_P_C.cpf_C,cpf_C);
		setbuf(stdin, NULL);
		
		hidecursor();
		TelaDados_Cliente_Pet_Inter(7,7,11,7,7);
		entradas(45,18,7,DataN_C,10, 2);
		setbuf(stdin, NULL);
		strcpy(C.D_P_C.DataN_C,DataN_C); 
		setbuf(stdin, NULL);
			//______________________ DADOS PET _______________________________________________________________________________ 
		
		hidecursor();
		TelaDados_Cliente_Pet_Inter(7,7,7,11,7);
		entradas(38,23,7,nome_Pet,34,1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.nome_Pet,nome_Pet);
		setbuf(stdin, NULL);
		
		hidecursor();	
		//	Seta 
		int a;
		TelaDados_Cliente_Pet_Inter(7,7,7,7,11);
		do{
		a = getch();
		}while(a!=13);
		
		system("cls");
		Dados_Animal_Inter();
		hidecursor();
		TelaDados_Cliente_Pet_Inter(11,7,7,7,7);
        entradas(47,8,7,microchip,19,0);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.microchip,microchip);
		setbuf(stdin, NULL);
		
		hidecursor();	
		TelaDados_Cliente_Pet_Inter(7,11,7,7,7);
		entradas(34,13,7,especie,19,1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.especie,especie);
		setbuf(stdin, NULL);
		
		hidecursor();
		TelaDados_Cliente_Pet_Inter(7,7,11,7,7);
		entradas(45,18,7,dataN_Pet,10,2);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.dataN_Pet,dataN_Pet); 
		setbuf(stdin, NULL);
		
		hidecursor();
		TelaDados_Cliente_Pet_Inter(7,7,7,11,7);
		entradas(31,23,7,raca,9,1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.raca,raca);
		setbuf(stdin, NULL);
		
		hidecursor();	
		//	Seta 
		TelaDados_Cliente_Pet_Inter(7,7,7,7,11);
		do{
		a = getch();
		}while(a!=13);
		
		system("cls");
		setbuf(stdin,NULL);
		Dados_Pet_Inter();
		hidecursor();
		TelaDados_Animal_Inter(11,7,7,7,7);
        entradas(30,8,7,cor,19, 1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.cor,cor);
		setbuf(stdin, NULL);
		
		hidecursor();	
		TelaDados_Animal_Inter(7,11,7,7,7);
		entradas(61,8,7,sexo,7,1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.sexo,sexo);
		setbuf(stdin, NULL);
		
		hidecursor();
		TelaDados_Animal_Inter(7,7,11,7,7);
		entradas(35,13,7,castrado,9, 1);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.castrado,castrado); 
		setbuf(stdin, NULL);
		
		hidecursor();
		TelaDados_Animal_Inter(7,7,7,11,7);
		entradas(49,18,7,Obs,29,0);
		setbuf(stdin, NULL);
		strcpy(C.D_A_C.Obs,Obs);
		setbuf(stdin, NULL);
		TelaDados_Animal_Inter(7,7,7,7,11);
		do{
		a = getch();
		}while(a!=13);
		//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
		system("cls");
		setbuf(stdin,NULL);
		enderecoInter();
		hidecursor();
		telaEndereco(11,7,7,7,7,7,7);
		entradas(30,8,7,rua,25, 0);
		setbuf(stdin, NULL);
		strcpy(C.D_E_C.rua,rua);
		setbuf(stdin, NULL);

		hidecursor();
		telaEndereco(7,11,7,7,7,7,7);
		entradas(33,13,7,bairro,11,0);
		setbuf(stdin, NULL);
		strcpy(C.D_E_C.bairro,bairro);
		setbuf(stdin, NULL);

		hidecursor();
		telaEndereco(7,7,11,7,7,7,7);
		entradas(33,18,7,cidade,11,1);
		setbuf(stdin, NULL);
		strcpy(C.D_E_C.cidade,cidade);
		setbuf(stdin, NULL);

		hidecursor();
		telaEndereco(7,7,7,11,7,7,7);
		entradas(65,18,7,teleC,10,2);
		setbuf(stdin, NULL);
		strcpy(C.D_P_C.teleC,teleC);
		
		hidecursor();
		telaEndereco(7,7,7,7,11,7,7);
		entradas(30,23,7,cep,9,2);	
		setbuf(stdin, NULL);
		strcpy(C.D_E_C.cep,cep);
		setbuf(stdin, NULL);
		
		hidecursor();
		telaEndereco(7,7,7,7,7,11,7);
		entradas(65,23,7,uf,2,1);	
		setbuf(stdin, NULL);
		strcpy(C.D_E_C.uf,uf);
		setbuf(stdin, NULL);
		
		hidecursor();
		telaEndereco(7,7,7,7,7,7,11);
		do{
		   a = getch();
		}while(a!=13);
	fclose(arqC);
	
	arqAUX_C = fopen("arquivoClinteAux.txt","a+"); //abre arquivo auxiliar em adição
	arqC = fopen("arquivoClinte.txt","r");   //abre arquivo principal em leitura
	//Verifica se arquivo foi aberto
	if(arqAUX_C ==NULL && arqC==NULL){
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}
	else{

		//Pega os dados alterados e passa para o arquivo auxiliar
		fwrite(&C, sizeof(Cadastro_C), 1, arqAUX_C);
		while(fread(&C, sizeof(Cadastro_C), 1, arqC)){
			if((strcmp(C.D_P_C.cpf_C,cpf_C)!=0) && (strcmp(C.D_A_C.nome_Pet,nome_Pet)!=0)){
				fwrite(&C, sizeof(Cadastro_C), 1, arqAUX_C);
			}
		}
	}
	//Fecha o arquivo
	fclose(arqC);
	fclose(arqAUX_C);
	
	//Renomeia 
	remove("arquivoClinte.txt");//
	rename("arquivoClinteAux.txt", "arquivoClinte.txt");//
 	escolha2(1);
 	system("cls");
	fflush(stdin);
	gotoXY(44,11);
	textcolor(12);
	printf("  Altera%c%co concluida!\n", 135,198);
	getch();
	system("cls");
	
	
}
/*//------------------------------------------------------
void excluir_Funcionario(){
	//FUNÇÃO QUE ALTERA OS DADOS DO USUARIO
	FILE *arqAUX_F;  //arquivo auxiliar
	FILE *arqF;
	int encontrado=FALSE; //variavel para indicar se foi encontrado
	int a=0;
	//Abertura do arquivo principal
	arqF = fopen("arquivoFuncio.txt","r");
	
	//Recebendo dados de login para comparar
	system("cls");
	caixa_branca(31,32,31);
	int x=47, y=2;
	setbuf(stdin, NULL);
	textcolor(7);
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	textcolor(4);
	gotoXY(x,y);y++;printf("   \xDB\xDB\xDB");
	gotoXY(x,y);y++;printf("   \xDB\xDB\xDB");
	textcolor(7);
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf("\xDB       \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	gotoXY(x,y);y++;printf("    \xDB");
	textcolor(7);
	gotoXY(34,16); 
	printf("Digite o codigo de acesso da sua conta: ");
	gets(codigo);
	gotoXY(34,22); 
	printf("CPF: ");
	gets(cpf_F);
	//Loop para ler todos os dados do arquivo e pesquisa
	while(fread(&F, sizeof(Cadastro_F), 1, arqF)){
		if((strcmp(F.D_P_F.codigo, codigo)==0)&&(strcmp(F.D_P_F.cpf_F, cpf_F)==0)){ //pesquise se esse codigo de acesso existe e o //pesquise se esse CPF existe
			encontrado=TRUE;
		break; //para tudo parsa
		}
	}

	system("cls");
	setbuf(stdin, NULL);
	//Condição caso não seja encontrado
	if(!encontrado){
		gotoXY(42,11);
		textcolor(12);
		printf("Usu%crio n%co encontrado!\n",160,198);
		gotoXY(50,13);
		getchar();
		system("cls");
		fclose(arqF);
	//Retorna para munu do gerente 
	escolha2(1);
	}	
	system("cls");

	//Exibe as informações do funcionario

	//imprimir dados
		larapet2();
		caixa_branca1(30, 31,30);
		x=45;y=13;
		gotoXY(x,y);y++;
		gotoXY(45,9);
	    textcolor(2);
		printf("DADOS CADASTRAIS ");
		gotoXY(21,11);
		textcolor(2);
		printf("Nome: ");
		gotoXY(26,11);
		textcolor(11);
		puts(F.D_P_F.nome_F);
		setbuf(stdin, NULL);
		
		gotoXY(21,12);
		textcolor(2);
		printf("CPF:");
		textcolor(11);
		puts(F.D_P_F.cpf_F);
	 	setbuf(stdin, NULL);
			
		gotoXY(21,13);
		textcolor(2);
		printf("Data de Nascimento:");
		textcolor(11);
		puts(F.D_P_F.DataN_F);
	 	setbuf(stdin, NULL);
	 		
		gotoXY(21,14);
		textcolor(2);
		printf("Telefone:");
		textcolor(11);
		puts(F.D_P_F.teleF);
		//______________________TELA DE DADOS PROFISSIONAIS_____________________________________________________________________________________________________________________________________________________________________________________________________________ 
		
		gotoXY(26,25);
		textcolor(2);
		printf("Codigo:");
		textcolor(11);
		puts(F.D_P_F.codigo);
		setbuf(stdin, NULL);
	
		gotoXY(x,y);y++;
		puts(F.D_P_F.funcao);
		setbuf(stdin, NULL);
	
			//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
	
		gotoXY(x,y);y++;
		puts(F.D_E_F.rua);
		setbuf(stdin, NULL);
		
		gotoXY(x,y);y++;
		puts(F.D_E_F.bairro);
		setbuf(stdin, NULL);
		
		gotoXY(x,y);y++;
		puts(F.D_E_F.cidade);
		setbuf(stdin, NULL);
		
		gotoXY(x,y);y++;
		puts(F.D_E_F.uf);	
		setbuf(stdin, NULL);
		
		gotoXY(x,y);y++;
		puts(F.D_E_F.cep);	
		setbuf(stdin, NULL);
		
		gotoXY(41,35);
		textcolor(7);
		printf("Pressione enter para desativar esta conta\n");
		getchar();
		system("cls");
		setbuf(stdin, NULL);
		do{
		   a = getch();
		}while(a!=13);
		
		
	arqAUX_F = fopen("arquivoFuncioAux.txt","a+");; //abre arquivo auxiliar em adição
	arqF = fopen("arquivoFuncio.txt","a+");   //abre arquivo principal em leitura
	
	//Verifica se arquivo foi aberto
	if(arqAUX_F ==NULL && arqF==NULL){
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}
	else{
		//Pega os dados alterados e passa para o arquivo auxiliar
		
		while(fread(&F, sizeof(Cadastro_F), 1, arqF)){
			if(strcmp(F.D_P_F.codigo,codigo)!=0){
				fwrite(&F, sizeof(Cadastro_F), 1, arqAUX_F);
			}
		}
	}
	//Fecha o arquivo
	fclose(arqF);
	fclose(arqAUX_F);

	//Renomeia 

	remove("arquivoFuncio.txt");
	rename("arquivoFuncioAux.txt", "arquivoFuncio.txt");
	
	system("cls");
	escolha2(1);

}
*/

//FUNÇÕES DE AGENDAMENTO
//.....................................................................................
//.....................................................................................
void Agendamento1(){
	
	system("cls");
	
	FILE *arqC;
	Cadastro_C AC;
	char cpf_C[13],pet[30];
	int encontrou=FALSE;
	//Recebendo dados de login para comparar
	system("cls");
	caixa_branca(31,32,31);
	caixa1L(7, 15, 15, 15, 53);
	caixa1L(7, 20, 20, 20, 53);
	int x=47, y=2;
	setbuf(stdin, NULL);
	textcolor(7);
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	textcolor(4);
	gotoXY(x,y);y++;printf("   \xDB\xDB\xDB");
	gotoXY(x,y);y++;printf("   \xDB\xDB\xDB");
	textcolor(7);
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf("\xDB       \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	gotoXY(x,y);y++;printf("    \xDB");
	
	textcolor(7);
	gotoXY(26,16); 
	printf("Digite o CPF do Cliente: ");
	
	gotoXY(26,21); 
	printf("Microchip do Pet: ");
	
	gotoXY(50,16);
	gets(cpf_C);
	
	gotoXY(43,21); 
	gets(pet);
	
	//Abertura do arquivo principal
	arqC = fopen("arquivoCliente.txt","r");
	
	//VERIFICAÇÃO DE ABERTURA
	if(arqC==NULL){
		mensagem2();
		textcolor(12);
		gotoXY(37,19);
		printf("P  A  G  E    N  O  T    F  O  U  N  D ");
		getchar();
		system("cls");
		escolha2(1);
	}
	while(fread(&AC,sizeof(Cadastro_C),1,arqC)){
		if((strcmp(AC.D_P_C.cpf_C, cpf_C)==0)&&(strcmp(AC.D_A_C.microchip,pet)==0)){ //pesquise se esse codigo de acesso existe e o //pesquise se esse CPF existe
			fclose(arqC);
			incluir_Agendamento(AC);
			encontrou=TRUE;
					break;
			}
		}
	system("cls");
	setbuf(stdin, NULL);
	//Condição caso não seja encontrado
	if(!encontrou){
	fclose(arqC);
	mensagem2();
	textcolor(12);
	gotoXY(42,24);
	printf("Cadastro n%co encontrado!\n",198);
	getch();
	setbuf(stdin, NULL);
	system("cls");
	//Retorna para munu principal
	escolha2(1);
	}	
	
}
void incluir_Agendamento(Cadastro_C dadosCliente){
	system("cls");
	FILE *arqC_Agenda;  
	
	Cadastro_C marcar;
	
	//Abertura do arquivo para Agendamento
	arqC_Agenda = fopen("arquivoAgenda.txt","a+");
	
	//COLETA OS DADOS DO USUÁRIO
	//______________________ DADOS PESSOAIS_______________________________________________________________________________ 
	
    strcpy(marcar.D_P_C.nome_C,dadosCliente.D_P_C.nome_C);

	strcpy(marcar.D_P_C.cpf_C,dadosCliente.D_P_C.cpf_C);
	
	strcpy(marcar.D_P_C.DataN_C,dadosCliente.D_P_C.DataN_C);
	
	//____________________ DADOS PET _______________________________________________________________________________ 
	strcpy(marcar.D_A_C.nome_Pet,dadosCliente.D_A_C.nome_Pet);
	
	strcpy(marcar.D_A_C.microchip,dadosCliente.D_A_C.microchip);
	
	strcpy(marcar.D_A_C.especie,dadosCliente.D_A_C.especie);
	
	strcpy(marcar.D_A_C.dataN_Pet,dadosCliente.D_A_C.dataN_Pet);
	
	strcpy(marcar.D_A_C.raca,dadosCliente.D_A_C.raca);
	
	strcpy(marcar.D_A_C.cor,dadosCliente.D_A_C.cor);
	
	strcpy(marcar.D_A_C.sexo,dadosCliente.D_A_C.sexo);
	
	strcpy(marcar.D_A_C.castrado,dadosCliente.D_A_C.castrado);
	
	strcpy(marcar.D_A_C.Obs,dadosCliente.D_A_C.Obs);
	
	strcpy(marcar.D_E_C.rua,dadosCliente.D_E_C.rua);
	
	strcpy(marcar.D_E_C.bairro,dadosCliente.D_E_C.bairro);
	
	strcpy(marcar.D_E_C.cidade,dadosCliente.D_E_C.cidade);
	
	strcpy(marcar.D_P_C.teleC,dadosCliente.D_P_C.teleC);
	
	strcpy(marcar.D_E_C.cep,dadosCliente.D_E_C.cep);
	
	strcpy(marcar.D_E_C.uf,dadosCliente.D_E_C.uf);

	Dados_Agendamento_Inter();

	hidecursor();
	TelaDados_Agenadmento_Inter(11,7,7,7);
	gotoXY(31,8);
	textcolor(7);
	setbuf(stdin, NULL);
	gets(marcar.D_M_C.DataN_C);
	gotoXY(31,8);
	printf("                                            ");
	gotoXY(31,8);
	puts(marcar.D_M_C.DataN_C);
	
	hidecursor();
	TelaDados_Agenadmento_Inter(7,11,7,7);
	gotoXY(64,8);
	textcolor(7);
	setbuf(stdin, NULL);
	gets(marcar.D_M_C.Hora);
	gotoXY(64,8);
	printf("                                            ");
	gotoXY(64,8);
	puts(marcar.D_M_C.Hora);
	
	hidecursor();
	TelaDados_Agenadmento_Inter(7,7,11,7);
	gotoXY(49,13);
	textcolor(7);
	setbuf(stdin, NULL);
	gets(marcar.D_M_C.Obs);
	gotoXY(49,13);
	printf("                                            ");
	gotoXY(64,8);
	puts(C.D_M_C.Obs);
	
	fwrite(&marcar,sizeof(Cadastro_C),1,arqC_Agenda);
	
	fclose(arqC_Agenda);

	system("cls");
	mensagem1();
	gotoXY(44,11);
	textcolor(12);
	printf("  Agendamento marcado com sucesso!\n", 135,198);
	getch();
	system("cls");
}
/////////////////

//funcao de busca de dados do arquivo
void busca_Agendamento(){
	int x=0,y=0;
	//Função que faz a consulta dos funcionarios
	system("cls");
	//Declaracao e inicializacao do arquivo
	FILE *arqC_Agenda;
	
	arqC_Agenda = fopen("arquivoAgenda.txt","r");
	
	if(arqC_Agenda==NULL){
		mensagem2();
		textcolor(12);
		gotoXY(37,19);
		printf("P  A  G  E    N  O  T    F  O  U  N  D ");
		getchar();
		system("cls");
		escolha2(1);
	}
	else{
		int total = 0;
   		int cont = 1;
   		//caixinha para ir ao pedido anterior
   		while(fread(&C,sizeof(Cadastro_C),1,arqC_Agenda)) total++;
		rewind(arqC_Agenda);
		while(fread(&C, sizeof(Cadastro_C), 1, arqC_Agenda)){
			larapet2();
	   		caixa_branca2(27, 28 ,27);
			gotoXY(41,35);
	        textcolor(7);
	  		printf("PRESSIONE ESC PARA SAIR \n");
	  		gotoXY(13,28);
	        textcolor(11);
	        printf("<<");
	        gotoXY(9,29);
	        textcolor(11);
	        printf(" Anterior");
	        gotoXY(89,28);
	        textcolor(11);
	        printf(">>");
	        gotoXY(85,29);
	        textcolor(11);
	        printf(" Proximo");
			x=21;y=11;
			gotoXY(40,9);
		    textcolor(2);
			printf("DADOS CADASTRAIS CLEINTE/PET ");
			gotoXY(x,y);
			textcolor(2);
			printf("Nome:");
			gotoXY(x+5,y);y++;
        	textcolor(11);
			puts(C.D_P_C.nome_C);
			setbuf(stdin, NULL);
			
			gotoXY(x,y);
			textcolor(2);
			printf("CPF:");
			textcolor(11);
			gotoXY(x+4,y);y++;
			puts(C.D_P_C.cpf_C);
		 	setbuf(stdin, NULL);
				
			gotoXY(x,y);
			textcolor(2);
			printf("Data de nascimento:");
			textcolor(11);
			gotoXY(x+19,y);y+=2;
			puts(C.D_P_C.DataN_C);
		 	setbuf(stdin, NULL);
		 	
			gotoXY(x,y);
			textcolor(2);
			printf("Nome do Pet:");
			textcolor(11);
			gotoXY(x+12,y);y++;
			puts(C.D_A_C.nome_Pet);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Microchip:");
			textcolor(11);
			gotoXY(x+10,y);
			puts(C.D_A_C.microchip);
			
			gotoXY(x+23,y);
			textcolor(2);
			printf("Especie:");
			textcolor(11);
			gotoXY(x+31,y);
			puts(C.D_A_C.especie);
			
			gotoXY(x+45,y);
			textcolor(2);
			printf("Ra%ca:",135);
			textcolor(11);
			gotoXY(x+50,y);y++;
			puts(C.D_A_C.raca);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Data de nascimento do pet:");
			textcolor(11);
			gotoXY(x+26,y);y++;
			puts(C.D_A_C.dataN_Pet);
			
			
			gotoXY(x,y);
			textcolor(2);
			printf("Cor:");
			textcolor(11);
			gotoXY(x+4,y);
			puts(C.D_A_C.cor);
			
			gotoXY(x+23,y);
			textcolor(2);
			printf("Sexo:");
			textcolor(11);
			gotoXY(x+28,y);
			puts(C.D_A_C.sexo);
			
			gotoXY(x+45,y);
			textcolor(2);
			printf("Castrado:");
			textcolor(11);
			gotoXY(x+54,y);y++;
			puts(C.D_A_C.castrado);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Obs sobre o pet:");
			textcolor(11);
			gotoXY(x+15,y);y+=2;
			puts(C.D_A_C.Obs);	
			setbuf(stdin, NULL);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Telefone:");
			textcolor(11);
			gotoXY(x+9,y);y++;
			puts(C.D_P_C.teleC);
			
	//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
		
			
			gotoXY(x,y);
			textcolor(2);
			printf("Rua:");
			textcolor(11);
			gotoXY(x+4,y);y++;
			puts(C.D_E_C.rua);
			setbuf(stdin, NULL);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Bairro:");
			textcolor(11);
			gotoXY(x+7,y);y++;
			puts(C.D_E_C.bairro);
			setbuf(stdin, NULL);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Cidade:");
			textcolor(11);
			gotoXY(x+7,y);
			puts(C.D_E_C.cidade);
			setbuf(stdin, NULL);
			
			gotoXY(x+17,y);
			textcolor(2);
			printf("UF:");
			textcolor(11);
			gotoXY(x+20,y);y++;
			puts(C.D_M_C.DataN_C);	
			setbuf(stdin, NULL);
			
			gotoXY(x,y);
			textcolor(2);
			printf("Cep:");
			textcolor(11);
			gotoXY(x+4,y);y++;
			puts(C.D_M_C.Hora);	
			setbuf(stdin, NULL);
			
			gotoXY(76,10);
    		textcolor(7);
			printf("%.2d / %.2d", cont, total);
			int tecla;
            do {
                tecla = getch();

                if (tecla == ESC) {
                    fclose(arqC_Agenda);
                	system("cls");
					mensagem1();
					system("cls");
					getchar();
                    escolha2(1);
                } 
				else
					if (tecla == ESQUERDA && cont > 1) {
                    	cont--; 
                    	fseek(arqC_Agenda,-sizeof(Cadastro_C) * 2, SEEK_CUR); 
                	}	 
					else
						if (tecla == DIREITA && cont < total) {
                    			cont++; 
                		} 
						else 
                    		tecla = ENTER;
            }while (tecla == ENTER);
			int i=0;
			for(i=11;i<27;i++){
				x=21;
				gotoXY(x, i);
		        printf("                                                                                  ");
			}
		}
	}
	fclose(arqC_Agenda);
	escolha2(1);
}

///////////////////////

void excluir_Agendamento(){
	//FUNÇÃO QUE ALTERA OS DADOS DO USUARIO
	FILE *arqC_Agenda;
	int encontrado=FALSE; //variavel para indicar se foi encontrado
	int a=0;
	char hora[6],data[13];
	//Abertura do arquivo principal
	arqC_Agenda = fopen("arquivoAgenda.txt","r");
	
	//VERIFICAÇÃO DE ABERTURA
	if(arqC_Agenda==NULL){
		mensagem2();
		textcolor(12);
		gotoXY(37,19);
		printf("P  A  G  E    N  O  T    F  O  U  N  D ");
		getchar();
		system("cls");
		escolha2(1);
	}
	//Recebendo dados de login para comparar
	system("cls");
	caixa_branca(31,32,31);
	caixa1L(7, 15, 15, 15, 53);
	caixa1L(7, 20, 20, 20, 53);
	int x=47, y=2;
	setbuf(stdin, NULL);
	textcolor(7);
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	textcolor(4);
	gotoXY(x,y);y++;printf("   \xDB\xDB\xDB");
	gotoXY(x,y);y++;printf("   \xDB\xDB\xDB");
	textcolor(7);
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf("\xDB       \xDB");
	gotoXY(x,y);y++;printf(" \xDB     \xDB");
	gotoXY(x,y);y++;printf("  \xDB   \xDB");
	gotoXY(x,y);y++;printf("    \xDB");
	
	textcolor(7);
	gotoXY(26,16); 
	printf("Data: ");
	
	gotoXY(26,21); 
	printf("Hora: ");
	
	gotoXY(31,16);
	gets(data);
	
	gotoXY(31,21); 
	gets(hora);
	
	//Loop para ler todos os dados do arquivo e pesquisa
	while(fread(&C, sizeof(Cadastro_C), 1, arqC_Agenda)){
		if((strcmp(C.D_M_C.Hora, hora)==0)&&(strcmp(C.D_M_C.DataN_C,data)==0)){ //pesquise se esse codigo de acesso existe e o //pesquise se esse CPF existe
			encontrado=TRUE;
		break; //para tudo parsa
		}
	}

	system("cls");
	setbuf(stdin, NULL);
	//Condição caso não seja encontrado
	if(!encontrado){
		fclose(arqC_Agenda);
		mensagem2();
		textcolor(12);
		gotoXY(42,24);
		printf("Agendamento n%co encontrado!\n",198);
		getch();
		setbuf(stdin, NULL);
		system("cls");
		//Retorna para munu principal
		escolha2(2);
	}	
		system("cls");

		//Exibe as informações do funcionario

		//imprimir dados
		larapet2();
   		caixa_branca2(27, 28,27);
		x=21;y=11;
		gotoXY(40,9);
	    textcolor(2);
		printf("DADOS CADASTRAIS CLEINTE/PET ");
		gotoXY(x,y);
		textcolor(2);
		printf("Nome:");
		gotoXY(x+5,y);y++;
    	textcolor(11);
		puts(C.D_P_C.nome_C);
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("CPF:");
		textcolor(11);
		gotoXY(x+4,y);y++;
		puts(C.D_P_C.cpf_C);
	 	setbuf(stdin, NULL);
			
		gotoXY(x,y);
		textcolor(2);
		printf("Data de nascimento:");
		textcolor(11);
		gotoXY(x+19,y);y+=2;
		puts(C.D_P_C.DataN_C);
	 	setbuf(stdin, NULL);
	 	
		gotoXY(x,y);
		textcolor(2);
		printf("Nome do Pet:");
		textcolor(11);
		gotoXY(x+12,y);y++;
		puts(C.D_A_C.nome_Pet);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Microchip:");
		textcolor(11);
		gotoXY(x+10,y);
		puts(C.D_A_C.microchip);
		
		gotoXY(x+23,y);
		textcolor(2);
		printf("Especie:");
		textcolor(11);
		gotoXY(x+31,y);
		puts(C.D_A_C.especie);
		
		gotoXY(x+45,y);
		textcolor(2);
		printf("Ra%ca:",135);
		textcolor(11);
		gotoXY(x+50,y);y++;
		puts(C.D_A_C.raca);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Data de nascimento do pet:");
		textcolor(11);
		gotoXY(x+27,y);y++;
		puts(C.D_A_C.dataN_Pet);
		
		
		gotoXY(x,y);
		textcolor(2);
		printf("Cor:");
		textcolor(11);
		gotoXY(x+4,y);
		puts(C.D_A_C.cor);
		
		gotoXY(x+23,y);
		textcolor(2);
		printf("Sexo:");
		textcolor(11);
		gotoXY(x+28,y);
		puts(C.D_A_C.sexo);
		
		gotoXY(x+45,y);
		textcolor(2);
		printf("Castrado:");
		textcolor(11);
		gotoXY(x+54,y);y++;
		puts(C.D_A_C.castrado);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Obs sobre o pet:");
		textcolor(11);
		gotoXY(x+15,y);y+=2;
		puts(C.D_A_C.Obs);	
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Telefone:");
		textcolor(11);
		gotoXY(x+9,y);y++;
		puts(C.D_P_C.teleC);
		
//______________________TELA DE DADOS ENDEREÇO_____________________________________________________________________________________________________________________________________________________________________
	
		
		gotoXY(x,y);
		textcolor(2);
		printf("Rua:");
		textcolor(11);
		gotoXY(x+4,y);y++;
		puts(C.D_E_C.rua);
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Bairro:");
		textcolor(11);
		gotoXY(x+7,y);y++;
		puts(C.D_E_C.bairro);
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Cidade:");
		textcolor(11);
		gotoXY(x+7,y);
		puts(C.D_E_C.cidade);
		setbuf(stdin, NULL);
		
		gotoXY(x+17,y);
		textcolor(2);
		printf("UF:");
		textcolor(11);
		gotoXY(x+20,y);y++;
		puts(C.D_E_C.uf);	
		setbuf(stdin, NULL);
		
		gotoXY(x,y);
		textcolor(2);
		printf("Cep:");
		textcolor(11);
		gotoXY(x+4,y);y++;
		puts(C.D_E_C.cep);	
		setbuf(stdin, NULL);
	
		gotoXY(41,35);
		textcolor(7);
		printf("PRESSIONE ENTER PARA ECLUIR ESTE AGENDAMENTO\n");
		getch();
		system("cls");
		setbuf(stdin, NULL);
		
		
	//Declaracao e inicializacao do arquivo
	FILE* arqAUX_CA = fopen("arquivoAgendaAux.txt","w");//abre arquivo auxiliar em adição
	
	//Retorna ao começo do arquivo
	rewind(arqC_Agenda);
	
	//Verifica se arquivo foi aberto
	if(arqAUX_CA ==NULL && arqC_Agenda==NULL){
		mensagem2();
		textcolor(12);
		gotoXY(37,19);
		printf("P  A  G  E    N  O  T    F  O  U  N  D ");
		getch();
		system("cls");
		exit(1);	}
	else{
		while(fread(&C, sizeof(Cadastro_C), 1, arqC_Agenda)){
			if((strcmp(C.D_M_C.DataN_C,data)!=0)&&(strcmp(C.D_M_C.Hora,hora)!=0)){
				fwrite(&C, sizeof(Cadastro_C), 1, arqAUX_CA);
			}
		}
	}
	//Fecha os arquivos
	fclose(arqC_Agenda);
	fclose(arqAUX_CA);
    
    arqC_Agenda=fopen("arquivoAgenda.txt","w"); //abre arquivo auxiliar em adição
    arqAUX_CA=fopen("arquivoAgendaAux.txt","r"); //abre arquivo auxiliar em adição	
	while(fread(&C, sizeof(Cadastro_C), 1, arqAUX_CA)){
			if((strcmp(C.D_M_C.DataN_C,data)!=0)&&(strcmp(C.D_M_C.Hora,hora)!=0)){
					fwrite(&C, sizeof(Cadastro_C), 1, arqC_Agenda);
			}
		}
		
	//Fecha os arquivos
	fclose(arqC_Agenda);
	fclose(arqAUX_CA);

	remove("arquivoAgenda.txt");
	
	rename("arquivoAgendaAux.txt" ,"arquivoAgenda.txt"); // Renomeia
	
	system("cls");
	mensagem1();
	system("cls");
	getchar();
	system("cls");
	posMenu_vendas(1);
}

