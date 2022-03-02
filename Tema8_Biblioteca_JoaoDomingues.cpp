//===================================================
//Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> //Fun��o para manipular informa��es de datas e horas (relat�rio 1 [4][1])
#include<locale.h>
#define max 100 //Limite do vetor (valor arbitr�rio)

//===================================================
//Estrutura de datas
struct DATA
{
	int DIA, MES, ANO;
};

//===================================================
//Estrutura dos usu�rios
struct USUARIOS
{
	char CPF[15], NOME[50], RUA[30],NRO[5], CEP[11], MAIL[50], FONE[15], PROF[35];
	DATA NASC;
};

//===================================================
//Estrutura dos livros
struct LIVROS
{
	char ISBN[20], TITULO[50], GENERO[30], AUTORES[5][50];
	int NRO_PAG, CONT_AUTORES;
};

//===================================================
//Estrutura dos empr�stimos
struct EMPRESTIMOS
{
	char CPF[15], ISBN[20];
	DATA RETIRADA, DEVOLUCAO;
	float MULTA;
};

//===================================================
//Definindo exemplos de usu�rios
void criar_exemplos_usuarios(USUARIOS *user, int *cont)
{
//Exemplo 1
	strcpy(user[*cont].CPF, "001");
	strcpy(user[*cont].NOME, "Bernardo Rodrigues Faria");
	strcpy(user[*cont].RUA, "Durvalino Gon�alves");
	strcpy(user[*cont].NRO, "37");
	strcpy(user[*cont].CEP, "13567-000");
	strcpy(user[*cont].MAIL, "bernardo.adm@terra.com.br");
	strcpy(user[*cont].FONE, "(16)98265-7841");
	user[*cont].NASC.DIA=02;
	user[*cont].NASC.MES=02;
	user[*cont].NASC.ANO=1993;
	strcpy(user[*cont].PROF, "Administrador");
	(*cont)++;
	
//Exemplo 2
	strcpy(user[*cont].CPF, "002");
	strcpy(user[*cont].NOME, "Aniela Martinez Silveira");
	strcpy(user[*cont].RUA, "Oiapoc");
	strcpy(user[*cont].NRO, "1015");
	strcpy(user[*cont].CEP, "15500-007");
	strcpy(user[*cont].MAIL, "aniela.martinez@yahoo.com.br");
	strcpy(user[*cont].FONE, "(17)3421-7854");
	user[*cont].NASC.DIA=9;
	user[*cont].NASC.MES=10;
	user[*cont].NASC.ANO=1989;
	strcpy(user[*cont].PROF, "Funcion�ria p�blica");
	(*cont)++;

//Exemplo 3
	strcpy(user[*cont].CPF, "003");
	strcpy(user[*cont].NOME, "Carlos Eduardo Ramos");
	strcpy(user[*cont].RUA, "Alagoas");
	strcpy(user[*cont].NRO, "3561");
	strcpy(user[*cont].CEP, "15500-222");
	strcpy(user[*cont].MAIL, "ceramos@uol.com.br");
	strcpy(user[*cont].FONE, "(18)97410-4698");
	user[*cont].NASC.DIA=19;
	user[*cont].NASC.MES=05;
	user[*cont].NASC.ANO=1986;
	strcpy(user[*cont].PROF, "Dentista");
	(*cont)++;
}

//===================================================
//Definindo exemplos de livros
void criar_exemplos_livros(LIVROS *book, int *cont)
{
//Exemplo 1
	strcpy(book[*cont].ISBN, "0-7475-3269-9");
	strcpy(book[*cont].TITULO, "Harry Potter e a Pedra Filosofal");
	strcpy(book[*cont].GENERO, "Literatura fant�stica");
	strcpy(book[*cont].AUTORES[0], "Joanne Rowling");
	book[*cont].NRO_PAG=223;
	book[*cont].CONT_AUTORES=1;
	(*cont)++;

//Exemplo 2
	strcpy(book[*cont].ISBN, "9788535285185");
	strcpy(book[*cont].TITULO, "Programa��o de Sistemas Embarcados");
	strcpy(book[*cont].GENERO, "Computa��o");
	strcpy(book[*cont].AUTORES[0], "Rodrigo de Almeida");
	strcpy(book[*cont].AUTORES[1], "Carlos Henrique de Moraes");
	strcpy(book[*cont].AUTORES[2], "Thatyana Seraphim");
	book[*cont].NRO_PAG=488;
	book[*cont].CONT_AUTORES=3;
	(*cont)++;

//Exemplo 3
	strcpy(book[*cont].ISBN, "9789727221561");
	strcpy(book[*cont].TITULO, "Linguagem C");
	strcpy(book[*cont].GENERO, "Programa��o");
	strcpy(book[*cont].AUTORES[0], "Lu�s Damas");
	book[*cont].NRO_PAG=384;
	book[*cont].CONT_AUTORES=1;
	(*cont)++;
}

//===================================================
//Definindo exemplos de empr�stimos
void criar_exemplos_emprestimos(EMPRESTIMOS *loan, int *cont)
{
//Exemplo 1
	strcpy(loan[*cont].CPF, "002");
	strcpy(loan[*cont].ISBN, "9788535285185");
	loan[*cont].RETIRADA.DIA=02;
	loan[*cont].RETIRADA.MES=12;
	loan[*cont].RETIRADA.ANO=2020;
	loan[*cont].DEVOLUCAO.DIA=12;
	loan[*cont].DEVOLUCAO.MES=12;
	loan[*cont].DEVOLUCAO.ANO=2020;
	loan[*cont].MULTA=2.3;
	(*cont)++;

//Exemplo 2
	strcpy(loan[*cont].CPF, "001");
	strcpy(loan[*cont].ISBN, "9789727221561");
	loan[*cont].RETIRADA.DIA=21;
	loan[*cont].RETIRADA.MES=11;
	loan[*cont].RETIRADA.ANO=2020;
	loan[*cont].DEVOLUCAO.DIA=28;
	loan[*cont].DEVOLUCAO.MES=11;
	loan[*cont].DEVOLUCAO.ANO=2020;
	loan[*cont].MULTA=2;
	(*cont)++;

//Exemplo 3
	strcpy(loan[*cont].CPF, "003");
	strcpy(loan[*cont].ISBN, "0-7475-3269-9");
	loan[*cont].RETIRADA.DIA=20;
	loan[*cont].RETIRADA.MES=10;
	loan[*cont].RETIRADA.ANO=2020;
	loan[*cont].DEVOLUCAO.DIA=03;
	loan[*cont].DEVOLUCAO.MES=11;
	loan[*cont].DEVOLUCAO.ANO=2020;
	loan[*cont].MULTA=1.5;
	(*cont)++;
}

//===================================================
//Fun��o para apresentar o menu de op��es
void menu()
{
	printf("\n\n\t=== MENU DE OP��ES ===\n\n[1] Submenu de Usu�rios\n[2] Submenu de Livros");
	printf("\n[3] Submenu de Empr�stimos\n[4] Submenu de Relat�rios\n[5] Sair\n");
}

//===================================================
//[1]
//Fun��o para apresentar o submenu de usu�rios
void menu_usuario()
{
	system("cls");
	printf("\t=== SUBMENU DE OP��ES - USU�RIOS ===\n\n[1] Listar todos\n[2] Listar por CPF");
	printf("\n[3] Incluir\n[4] Alterar\n[5] Excluir\n");
}

//===================================================
//Fun��o para verificar a exist�ncia de um CPF
int buscar_cpf(USUARIOS *user, char *cpf, int *cont)
{
	int i, verif=0;
	for(i=0; i<*cont && verif==0; i++)
	{
		if(strcmp(user[i].CPF, cpf)==0)
		{
			verif=1;
			return i;
		}
	}
	return -1;
}

//===================================================
//[1][1]
//Fun��o para listar todos os usu�rios
void listar_usuarios(USUARIOS *user, int *cont)
{
	int i;
	for(i=0; i<*cont; i++)
	{
		printf("\nNome: %s", user[i].NOME);
		printf("\nCPF: %s", user[i].CPF);
		printf("\nRua: %s", user[i].RUA);
		printf("\tn� %s", user[i].NRO);
		printf("\nCEP: %s", user[i].CEP);
		printf("\nE-mail: %s", user[i].MAIL);	
		printf("\nTelefone: %s", user[i].FONE);
		printf("\nData de Nascimento: %d/%d/%d", user[i].NASC.DIA,user[i].NASC.MES, user[i].NASC.ANO);
		printf("\nProfiss�o: %s", user[i].PROF);
		printf("\n\n-------------------------------");
	}
}

//===================================================
//[1][2]
//Fun��o para listar os dados de um usu�rio de acordo com seu CPF
void listar_cpf(USUARIOS *user, int *cont)
{
	int pos=-1;
	char cpf[15];
	fflush(stdin);
	printf("\nDeseja listar o cadastro de qual CPF [incluir pontua��o]: ");
	gets(cpf);
	pos=buscar_cpf(user, cpf, cont);
	if(pos!=-1)
	{
		printf("\nNome: %s", user[pos].NOME);
		printf("\nCPF: %s", user[pos].CPF);
		printf("\nRua: %s", user[pos].RUA);
		printf("\tn� %s", user[pos].NRO);
		printf("\nCEP: %s", user[pos].CEP);
		printf("\nE-mail: %s", user[pos].MAIL);	
		printf("\nTelefone: %s", user[pos].FONE);
		printf("\nData de Nascimento: %d/%d/%d", user[pos].NASC.DIA,user[pos].NASC.MES, user[pos].NASC.ANO);
		printf("\nProfiss�o: %s", user[pos].PROF);
		printf("\n\n-------------------------------");
	}
	else
		printf("\nCPF %s n�o encontrado!", cpf);
}

//===================================================
//[1][3]
//Fun��o para cadastrar um usu�rio
void incluir_usuario(USUARIOS *user, int *cont)
{
	int pos=0;
	char cpf[15];
	fflush(stdin);
	while(pos!=-1)
	{
		printf("\nCPF [incluir pontua��o]: ");
		gets(cpf);
		pos=buscar_cpf(user, cpf, cont);
		if(pos!=-1)
			printf("\n\t*** ATEN��O! ***\nCPF EXISTENTE. Tente novamente\n\t****************\n");
	}
	strcpy(user[*cont].CPF, cpf);
	printf("Nome: ");
	gets(user[*cont].NOME);
	printf("Rua: ");
	gets(user[*cont].RUA);
	printf("n� ");
	gets(user[*cont].NRO);
	printf("CEP: ");
	gets(user[*cont].CEP);
	fflush(stdin);
	printf("E-mail: ");
	gets(user[*cont].MAIL);
	printf("Telefone: ");
	gets(user[*cont].FONE);
	fflush(stdin);
	printf("DATA DE NASCIMENTO");
	printf("\nDia [dd]: ");
	scanf("%d", &user[*cont].NASC.DIA);
	printf("M�s [mm]: ");
	scanf("%d", &user[*cont].NASC.MES);
	printf("Ano [aaaa]: ");
	scanf("%d", &user[*cont].NASC.ANO);
	fflush(stdin);
	printf("Profiss�o: ");
	gets(user[*cont].PROF);
	(*cont)++;
}

//===================================================
//[1][4]
//Fun��o para alterar um usu�rio
void alterar_usuario(USUARIOS *user, int *cont)
{
	int pos;
	char cpf[15];
	fflush(stdin);
	printf("\nCPF [incluir pontua��o]: ");
	gets(cpf);
	pos=buscar_cpf(user, cpf, cont);
	if(pos!=-1)
	{
		printf("Nome: ");
		gets(user[pos].NOME);
		printf("Rua: ");
		gets(user[pos].RUA);
		printf("n� ");
		gets(user[pos].NRO);
		printf("CEP: ");
		gets(user[pos].CEP);
		fflush(stdin);
		printf("E-mail: ");
		gets(user[pos].MAIL);
		printf("Telefone: ");
		gets(user[pos].FONE);
		fflush(stdin);
		printf("Data de Nascimento [dd/mm/aaaa]");
		printf("\nDia: ");
		scanf("%d", &user[*cont].NASC.DIA);
		printf("M�s: ");
		scanf("%d", &user[*cont].NASC.MES);
		printf("\nAno: ");
		scanf("%d", &user[*cont].NASC.ANO);
		printf("Profiss�o: ");
		gets(user[pos].PROF);
		printf("\nUsu�rio alterado com sucesso.");
	}
	else
		printf("\nCPF %s n�o encontrado!", cpf);
}

//===================================================
//[1][5]
//Fun��o para excluir um usu�rio
void excluir_usuario(USUARIOS *user, int *cont)
{
	int pos, i;
	char cpf[15];
	fflush(stdin);
	printf("\nCPF [incluir pontua��o]: ");
	gets(cpf);
	pos=buscar_cpf(user, cpf, cont);
	if(pos!=-1)
	{
		for(i=pos; i<*cont-1; i++)
			user[i]=user[i+1];
		printf("\nUsu�rio removido com sucesso!\n\n");
		(*cont)--;
	}
	else
		printf("\nCPF %s n�o encontrado!", cpf);
}

//===================================================
//[2]
//Fun��o para apresentar o submenu de livros
void menu_livro()
{
	system("cls");
	printf("\t=== SUBMENU DE OP��ES - LIVROS ===\n\n[1] Listar todos\n[2] Listar por ISBN");
	printf("\n[3] Incluir\n[4] Alterar\n[5] Excluir\n");
}

//===================================================
//Fun��o para verificar a exist�ncia de um ISBN
int buscar_isbn(LIVROS *book, char *isbn, int *cont)
{
	int i, verif=0;
	for(i=0; i<*cont && verif==0; i++)
	{
		if(strcmp(book[i].ISBN, isbn)==0)
		{
			verif=1;
			return i;
		}
	}
	return -1;
}

//===================================================
//[2][1]
//Fun��o para listar todos os livros
void listar_livros(LIVROS *book, int *cont)
{
	int i, j, *pont_autores;
	for(i=0; i<*cont; i++)
	{
		pont_autores=&book[i].CONT_AUTORES;
		printf("\nT�tulo: %s", book[i].TITULO);
		printf("\nISBN: %s", book[i].ISBN);
		printf("\nG�nero: %s", book[i].GENERO);
		printf("\nAutor(es):");
		for(j=0; j<*pont_autores; j++)
			printf("\n\t%s", book[i].AUTORES[j]);
		printf("\nN�mero de p�ginas: %d", book[i].NRO_PAG);
		printf("\n\n-------------------------------");
	}
}

//===================================================
//[2][2]
//Fun��o para listar os dados de um livro de acordo com seu ISBN
void listar_isbn(LIVROS *book, int *cont)
{
	int pos=-1, j, *pont_autores;;
	char isbn[20];
	fflush(stdin);
	printf("\nDeseja listar o cadastro de qual ISBN [incluir pontua��o]: ");
	gets(isbn);
	pos=buscar_isbn(book, isbn, cont);
	if(pos!=-1)
	{
		printf("\nT�tulo: %s", book[pos].TITULO);
		printf("\nISBN: %s", book[pos].ISBN);
		printf("\nG�nero: %s", book[pos].GENERO);
		printf("\nAutor(es):");
		pont_autores=&book[pos].CONT_AUTORES;
		for(j=0; j<*pont_autores; j++)
			printf("\n\t%s", book[pos].AUTORES[j]);
		printf("\nN�mero de p�ginas: %d", book[pos].NRO_PAG);
		printf("\n\n-------------------------------");
	}
	else
		printf("\nISBN %s n�o encontrado!", isbn);
}

//===================================================
//[2][3]
//Fun��o para cadastrar um livro
void incluir_livro(LIVROS *book, int *cont)
{
	int pos=0, *pont_autores=0;
	char isbn[20], resp;
	pont_autores=&book[*cont].CONT_AUTORES;
	fflush(stdin);
	while(pos!=-1)
	{
		printf("\nISBN [incluir pontua��o]: ");
		gets(isbn);
		pos=buscar_isbn(book, isbn, cont);
		if(pos!=-1)
			printf("\n\t*** ATEN��O! ***\nISBN EXISTENTE. Tente novamente\n\t****************\n");
	}
	strcpy(book[*cont].ISBN, isbn);
	printf("T�tulo: ");
	gets(book[*cont].TITULO);
	printf("G�nero: ");
	gets(book[*cont].GENERO);
	printf("Autor(a) %d: ", *pont_autores+1);
	gets(book[*cont].AUTORES[*pont_autores]);
	(*pont_autores)++;
	printf("Voc� ainda pode adicionar %d autores. ", 5-*pont_autores);
	printf("Deseja adicionar outro(a) autor(a) [S/N]: ");
	scanf("%c", &resp);
	while(resp=='S' || resp=='s' && *pont_autores<5) //O Inteiro 5 � devido ao tamanho do vetor bidimensional pr�-definido
	{
		fflush(stdin);
		printf("Autor(a) %d: ", *pont_autores+1);
		gets(book[*cont].AUTORES[*pont_autores]);
		(*pont_autores)++;
		if(*pont_autores<5)
		{
			fflush(stdin);
			printf("Voc� ainda pode adicionar %d autores. ", 5-*pont_autores);
			printf("Deseja adicionar outro(a) autor(a) [S/N]: ");
			scanf("%c", &resp);
		}
	}
	printf("N�mero de p�ginas: ");
	scanf("%d", &book[*cont].NRO_PAG);
	(*cont)++;
}

//===================================================
//[2][4]
//Fun��o para alterar um livro
void alterar_livro(LIVROS *book, int *cont)
{
	int pos, *pont_autores;
	char isbn[20], resp;
	fflush(stdin);
	printf("\nISBN [incluir pontua��o]: ");
	gets(isbn);
	pos=buscar_isbn(book, isbn, cont);
	pont_autores=&book[pos].CONT_AUTORES;
	if(pos!=-1)
	{
		*pont_autores=0;
		printf("T�tulo: ");
		gets(book[pos].TITULO);
		printf("G�nero: ");
		gets(book[pos].GENERO);
		printf("Autor(a) %d: ", *pont_autores+1);
		gets(book[pos].AUTORES[*pont_autores]);
		(*pont_autores)++;
		printf("Voc� ainda pode adicionar %d autores. ", 5-*pont_autores);
		printf("Deseja adicionar outro(a) autor(a) [S/N]: ");
		scanf("%c", &resp);
		while(resp=='S' || resp=='s' && *pont_autores<5) //O Inteiro 5 � devido ao tamanho do vetor bidimensional pr�-definido
		{
			fflush(stdin);
			printf("Autor(a) %d: ", *pont_autores+1);
			gets(book[pos].AUTORES[*pont_autores]);
			(*pont_autores)++;
			if(*pont_autores<5)
			{
				fflush(stdin);
				printf("Voc� ainda pode adicionar %d autores. ", 5-*pont_autores);
				printf("Deseja adicionar outro(a) autor(a) [S/N]: ");
				scanf("%c", &resp);
			}
		}
	printf("N�mero de p�ginas: ");
	scanf("%d", &book[pos].NRO_PAG);
	printf("\nLivro alterado com sucesso.");
	}
	else
		printf("\nISBN %s n�o encontrado!", isbn);
}

//===================================================
//[2][5]
//Fun��o para excluir um livro
void excluir_livro(LIVROS *book, int *cont)
{
	int pos, i;
	char isbn[20];
	fflush(stdin);
	printf("\nISBN [incluir pontua��o]: ");
	gets(isbn);
	pos=buscar_isbn(book, isbn, cont);
	if(pos!=-1)
	{
		for(i=pos; i<*cont-1; i++)
			book[i]=book[i+1];
		printf("\nLivro removido com sucesso!\n\n");
		(*cont)--;
	}
	else
		printf("\nISBN %s n�o encontrado!", isbn);
}

//===================================================
//[3]
//Fun��o para apresentar o submenu de empr�stimos
void menu_emprestimo()
{
	system("cls");
	printf("\t=== SUBMENU DE OP��ES - EMPR�STIMOS ===\n\n[1] Listar todos\n[2] Listar por CPF, ISBN e Data");
	printf("\n[3] Incluir\n[4] Alterar\n[5] Excluir\n");
}

//===================================================
//Fun��o para verificar a exist�ncia da data de retirada de um empr�stimo
int buscar_emprestimo(EMPRESTIMOS *loan, char *cpf, char *isbn, int *d, int *m, int *a, int *cont)
{
	int i, verif=0;
	for(i=0; i<*cont && verif==0; i++)
	{
		if(strcmp(loan[i].CPF, cpf)==0 && strcmp(loan[i].ISBN, isbn)==0 && loan[i].RETIRADA.DIA==*d && loan[i].RETIRADA.MES==*m && loan[i].RETIRADA.ANO==*a)
		{
			verif=1;
			return i;
		}
	}
	return -1;
}

//===================================================
//[3][1]
//Fun��o para listar todos os empr�stimos
void listar_emprestimos(USUARIOS *user, LIVROS *book, EMPRESTIMOS *loan, int *cont_user, int *cont_book, int *cont_loan)
{
	int i, pos_cpf, pos_isbn;
	for(i=0; i<*cont_loan; i++)
	{
		pos_cpf=buscar_cpf(user, loan[i].CPF, cont_user);
		pos_isbn=buscar_isbn(book, loan[i].ISBN, cont_book);
		printf("\nNome: %s", user[pos_cpf].NOME);
		printf("\nCPF: %s", loan[i].CPF);
		printf("\nT�tulo: %s", book[pos_isbn].TITULO);
		printf("\nISBN: %s", loan[i].ISBN);
		printf("\nData de Retirada: %d/%d/%d", loan[i].RETIRADA.DIA, loan[i].RETIRADA.MES, loan[i].RETIRADA.ANO);
		printf("\nData de Devolu��o: %d/%d/%d", loan[i].DEVOLUCAO.DIA, loan[i].DEVOLUCAO.MES, loan[i].DEVOLUCAO.ANO);
		printf("\nMulta: R$%.2f/dia", loan[i].MULTA);
		printf("\n\n-------------------------------");
	}
}

//===================================================
//[3][2]
//Fun��o para listar os dados de um empr�stimo de acordo com o CPF, ISBN e Data de Retirada
void listar_emprestimo_chave(USUARIOS *user, LIVROS *book, EMPRESTIMOS *loan, int *cont_user, int *cont_book, int *cont_loan)
{
	int pos_cpf, pos_isbn, pos_emprestimo, dia, mes, ano;
	char cpf[15], isbn[20], retirada[11];
	fflush(stdin);
	printf("\nDeseja listar o empr�stimo de qual CPF [incluir pontua��o]: ");
	gets(cpf);
	pos_cpf=buscar_cpf(user, cpf, cont_user);
	if(pos_cpf!=-1)
	{
		printf("Informe o ISBN do empr�stimo deseja consultar [incluir pontua��o]: ");
		gets(isbn);
		pos_isbn=buscar_isbn(book, isbn, cont_book);
		if(pos_isbn!=-1)
		{
			printf("\nDATA DE RETIRADA");
			printf("\nDia [dd]: ");
			scanf("%d", &dia);
			printf("M�s [mm]: ");
			scanf("%d", &mes);
			printf("Ano [aaaa]: ");
			scanf("%d", &ano);
			pos_emprestimo=buscar_emprestimo(loan, cpf, isbn, &dia, &mes, &ano, cont_loan);
			if(pos_emprestimo!=-1)
			{
				printf("\nNome: %s", user[pos_cpf].NOME);
				printf("\nCPF: %s", loan[pos_emprestimo].CPF);
				printf("\nT�tulo: %s", book[pos_isbn].TITULO);
				printf("\nISBN: %s", loan[pos_emprestimo].ISBN);
				printf("\nData de Retirada: %d/%d/%d", loan[pos_emprestimo].RETIRADA.DIA, loan[pos_emprestimo].RETIRADA.MES, loan[pos_emprestimo].RETIRADA.ANO);
				printf("\nData de Devolu��o: %d/%d/%d", loan[pos_emprestimo].DEVOLUCAO.DIA, loan[pos_emprestimo].DEVOLUCAO.MES, loan[pos_emprestimo].DEVOLUCAO.ANO);
				printf("\nMulta: R$%.2f/dia", loan[pos_emprestimo].MULTA);
				printf("\n\n-------------------------------");	
			}
			else
				printf("\nN�o h� empr�stimos com o CPF e o ISBN na data solicitada.");
		}
		else
			printf("\nISBN %s n�o encontrado!", isbn);
	}
	else
		printf("\nCPF %s n�o encontrado!", cpf);
}

//===================================================
//[3][3]
//Fun��o para cadastrar um empr�stimo
void incluir_emprestimo(USUARIOS *user, LIVROS *book, EMPRESTIMOS *loan, int *cont_user, int *cont_book, int *cont_loan)
{
	int pos_cpf, pos_isbn, pos_emprestimo, dia, mes, ano;
	char cpf[15], isbn[20], retirada[11];
	fflush(stdin);
	printf("\nCPF [incluir pontua��o]: ");
	gets(cpf);
	pos_cpf=buscar_cpf(user, cpf, cont_user);
	if(pos_cpf!=-1)
	{
		printf("Informe o ISBN do empr�stimo deseja consultar [incluir pontua��o]: ");
		gets(isbn);
		pos_isbn=buscar_isbn(book, isbn, cont_book);
		if(pos_isbn!=-1)
		{
			printf("\nDATA DE RETIRADA");
			printf("\nDia [dd]: ");
			scanf("%d", &dia);
			printf("M�s [mm]: ");
			scanf("%d", &mes);
			printf("Ano [aaaa]: ");
			scanf("%d", &ano);
			pos_emprestimo=buscar_emprestimo(loan, cpf, isbn, &dia, &mes, &ano, cont_loan);
			if(pos_emprestimo==-1)
			{
				strcpy(loan[*cont_loan].CPF, cpf);
				strcpy(loan[*cont_loan].ISBN, isbn);
				loan[*cont_loan].RETIRADA.DIA=dia;
				loan[*cont_loan].RETIRADA.MES=mes;
				loan[*cont_loan].RETIRADA.ANO=ano;
				printf("\nDATA DE DEVOLU��O");
				printf("\nDia [dd]: ");
				scanf("%d", &loan[*cont_loan].DEVOLUCAO.DIA);
				printf("M�s [mm]: ");
				scanf("%d", &loan[*cont_loan].DEVOLUCAO.MES);
				printf("Ano [aaaa]: ");
				scanf("%d", &loan[*cont_loan].DEVOLUCAO.ANO);
				printf("Valor da Multa: R$");
				scanf("%f", &loan[*cont_loan].MULTA);
				fflush(stdin);
				printf("\nEmpr�stimo cadastrado com sucesso.");
				(*cont_loan)++;
			}
			else
				printf("\n\t*** ATEN��O! ***\nJ� existem empr�stimos com o CPF e o ISBN na data solicitada. Tente novamente\n\t****************\n");
		}
		else
			printf("\n\t*** ATEN��O! ***\nISBN N�O ENCONTRADO. Tente novamente\n\t****************\n");
	}
	else
		printf("\n\t*** ATEN��O! ***\nCPF N�O ENCONTRADO. Tente novamente\n\t****************\n");
}

//===================================================
//[3][4]
//Fun��o para alterar um empr�stimo
void alterar_emprestimo(USUARIOS *user, LIVROS *book, EMPRESTIMOS *loan, int *cont_user, int *cont_book, int *cont_loan)
{
	int pos_cpf, pos_isbn, pos_emprestimo, dia, mes, ano;
	char cpf[15], isbn[20], retirada[11];
	fflush(stdin);
	printf("\nDeseja listar o empr�stimo de qual CPF [incluir pontua��o]: ");
	gets(cpf);
	pos_cpf=buscar_cpf(user, cpf, cont_user);
	if(pos_cpf!=-1)
	{
		printf("Informe o ISBN do empr�stimo deseja consultar [incluir pontua��o]: ");
		gets(isbn);
		pos_isbn=buscar_isbn(book, isbn, cont_book);
		if(pos_isbn!=-1)
		{
			printf("\nDATA DE RETIRADA");
			printf("\nDia [dd]: ");
			scanf("%d", &dia);
			printf("M�s [mm]: ");
			scanf("%d", &mes);
			printf("Ano [aaaa]: ");
			scanf("%d", &ano);
			pos_emprestimo=buscar_emprestimo(loan, cpf, isbn, &dia, &mes, &ano, cont_loan);
			if(pos_emprestimo!=-1)
			{
				printf("\nDATA DE DEVOLU��O");
				printf("\nDia [dd]: ");
				scanf("%d", &loan[pos_emprestimo].DEVOLUCAO.DIA);
				printf("M�s [mm]: ");
				scanf("%d", &loan[pos_emprestimo].DEVOLUCAO.MES);
				printf("Ano [aaaa]: ");
				scanf("%d", &loan[pos_emprestimo].DEVOLUCAO.ANO);
				printf("Valor da Multa: R$");
				scanf("%f", &loan[pos_emprestimo].MULTA);
				fflush(stdin);
				printf("\nEmpr�stimo alterado com sucesso.");			
			}
			else
				printf("\nN�o h� empr�stimos com o CPF e o ISBN na data solicitada.");
		}
		else
			printf("\nISBN %s n�o encontrado!", isbn);
	}
	else
		printf("\nCPF %s n�o encontrado!", cpf);
}

//===================================================
//[3][5]
//Fun��o para excluir um empr�stimo
void excluir_emprestimo(USUARIOS *user, LIVROS *book, EMPRESTIMOS *loan, int *cont_user, int *cont_book, int *cont_loan)
{
	int pos_cpf, pos_isbn, pos_emprestimo, dia, mes, ano, i;
	char cpf[15], isbn[20], retirada[11];
	fflush(stdin);
	printf("\nDeseja listar o empr�stimo de qual CPF [incluir pontua��o]: ");
	gets(cpf);
	pos_cpf=buscar_cpf(user, cpf, cont_user);
	if(pos_cpf!=-1)
	{
		printf("Informe o ISBN do empr�stimo deseja consultar [incluir pontua��o]: ");
		gets(isbn);
		pos_isbn=buscar_isbn(book, isbn, cont_book);
		if(pos_isbn!=-1)
		{
			printf("\nDATA DE RETIRADA");
			printf("\nDia [dd]: ");
			scanf("%d", &dia);
			printf("M�s [mm]: ");
			scanf("%d", &mes);
			printf("Ano [aaaa]: ");
			scanf("%d", &ano);
			pos_emprestimo=buscar_emprestimo(loan, cpf, isbn, &dia, &mes, &ano, cont_loan);
			if(pos_emprestimo!=-1)
			{
				for(i=pos_emprestimo; i<*cont_loan-1; i++)
					loan[i]=loan[i+1];
				printf("\nUsu�rio removido com sucesso!\n\n");
					(*cont_loan)--;						
			}
			else
				printf("\nN�o h� empr�stimos com o CPF e o ISBN na data solicitada.");
		}
		else
			printf("\nISBN %s n�o encontrado!", isbn);
	}
	else
		printf("\nCPF %s n�o encontrado!", cpf);
}

//===================================================
//[4]
//Fun��o para apresentar o submenu de relat�rios
void menu_relatorio()
{
	system("cls");
	printf("\t=== SUBMENU DE OP��ES - RELAT�RIOS ===\n\n[1] Listar usu�rios por idade");
	printf("\n[2] Listar livros por n�mero de autores");
	printf("\n[3] Listar empr�stimos por per�odo de devolu��o\n");
}

//===================================================
//[4][1]
//Fun��o para listar o relat�rio dos usu�rios de acordo com sua idade
void listar_idade(USUARIOS *user, int *cont)
{
	int idade, total_idade, anos, i, verif=0;
	int dia_atual, mes_atual, ano_atual;
	printf("\nDeseja listar os usu�rios a partir de que idade? ");
	scanf("%d", &idade);
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    dia_atual=tm.tm_mday;
	mes_atual=tm.tm_mon+1;
	ano_atual=tm.tm_year+1900;
	system("cls");
	printf("\n\t=== LISTAR USU�RIOS - MAIORES QUE %d ANOS ===\n", idade);
	for(i=0; i<*cont; i++)
	{
		total_idade=365*ano_atual+30*mes_atual+dia_atual-365*user[i].NASC.ANO-30*user[i].NASC.MES-user[i].NASC.DIA;
		anos=total_idade/365;
		if(anos>=idade)
		{
			printf("\nNome: %s", user[i].NOME);
			printf("\nCPF: %s", user[i].CPF);
			printf("\nRua: %s", user[i].RUA);
			printf("\tn� %s", user[i].NRO);
			printf("\nCEP: %s", user[i].CEP);
			printf("\nE-mail: %s", user[i].MAIL);	
			printf("\nTelefone: %s", user[i].FONE);
			printf("\nData de Nascimento: %d/%d/%d", user[i].NASC.DIA,user[i].NASC.MES, user[i].NASC.ANO);
			printf("\tIdade: %d anos", anos);
			printf("\nProfiss�o: %s", user[i].PROF);
			printf("\n\n-------------------------------");
			verif=1;
		}
	}
	if(verif==0)
		printf("\nOs usu�rios cadastrados s�o menores que %d anos.", idade);
}

//===================================================
//[4][2]
//Fun��o para listar o relat�rio dos livros de acordo com o n�mero de autores
void listar_autores(LIVROS *book, int *cont)
{
	int autores, *pont_autores, i, j, verif=0;
	printf("\nDeseja listar os livros que possuem quantos (ou mais) autores? ");
	scanf("%d", &autores);
	system("cls");
	printf("\n\t=== LISTAR LIVROS - MAIS QUE %d AUTORES ===\n", autores);
	for(i=0; i<*cont; i++)
	{
		if(book[i].CONT_AUTORES>=autores)
		{
			printf("\nT�tulo: %s", book[i].TITULO);
			printf("\nISBN: %s", book[i].ISBN);
			printf("\nG�nero: %s", book[i].GENERO);
			printf("\nAutor(es):");
			pont_autores=&book[i].CONT_AUTORES;
			for(j=0; j<*pont_autores; j++)
				printf("\n\t%s", book[i].AUTORES[j]);
			printf("\nN�mero de p�ginas: %d", book[i].NRO_PAG);
			printf("\n\n-------------------------------");			
			verif=1;
		}
	}
	if(verif==0)
		printf("\nOs livros cadastrados possuem menos que %d autores.", autores);
}

//===================================================
//Para realizar opera��es entre as datas ser� utilizado o c�lculo dos dias julianos
//Os dias julianos � um m�todo para contar os dias sequencialmente.
//S�o muito �teis porque facilitam a opera��o entre dias.
//Tais opera��es s�o mais dif�ceis no calend�rio padr�o (gregoriano), pois s�o
//agrupados em meses, podem conter um n�mero vari�vel de dias, al�m das complica��es dos anos bissextos.        
//DJ = D - 32075 + 1461*( A + 4800 + ( M - 14 ) / 12 ) / 4 + 367*( M - 2 - ( M - 14 ) / 12 * 12 ) / 12 - 3*( ( A + 4900 + ( M - 14 ) / 12 ) / 100 ) / 4
//DJ: dia juliano; A: ano; M: m�s; D: dia
//Exemplo: 01/01/1970 tem DJ = 2440588
//OBS: esta f�rmula � v�lida apenas entre os anos 1801 e 2099
int dia_juliano(int *D, int *M, int *A)
{
	int DJ;
	DJ=*D-32075+1461*(*A+4800+(*M-14)/12)/4+367*(*M-2-(*M-14)/12*12)/12-3*((*A+4900+(*M-14)/12)/100)/4;
    return DJ;
}

//===================================================
//[4][3]
//Fun��o para listar o relat�rio dos empr�stimos entre datas X e Y de devolu��o
void listar_data(USUARIOS *user, LIVROS *book, EMPRESTIMOS *loan, int *cont_user, int *cont_book, int *cont_loan)
{
	DATA dev_inicial, dev_final;
	int verif=0, i, pos_cpf, pos_isbn;
	int DJ_atual, DJ_inicial, DJ_final;
	printf("\nInforme o per�odo que deseja listar os empr�stimos\n\nData de devolu��o inicial");
	printf("\nDia [dd]: ");
	scanf("%d", &dev_inicial.DIA);
	printf("M�s [mm]: ");
	scanf("%d", &dev_inicial.MES);
	printf("Ano [aaaa]: ");
	scanf("%d", &dev_inicial.ANO);
	printf("\nData de devolu��o final");
	printf("\nDia [dd]: ");
	scanf("%d", &dev_final.DIA);
	printf("M�s [mm]: ");
	scanf("%d", &dev_final.MES);
	printf("Ano [aaaa]: ");
	scanf("%d", &dev_final.ANO);
	DJ_inicial=dia_juliano(&dev_inicial.DIA, &dev_inicial.MES, &dev_inicial.ANO);
	DJ_final=dia_juliano(&dev_final.DIA, &dev_final.MES, &dev_final.ANO);
	for(i=0; i<*cont_loan; i++)
	{
		DJ_atual=dia_juliano(&loan[i].DEVOLUCAO.DIA, &loan[i].DEVOLUCAO.MES, &loan[i].DEVOLUCAO.ANO);
		if(DJ_inicial<=DJ_atual && DJ_atual<=DJ_final)
		{
			pos_cpf=buscar_cpf(user, loan[i].CPF, cont_user);
			pos_isbn=buscar_isbn(book, loan[i].ISBN, cont_book);
			printf("\nNome: %s", user[pos_cpf].NOME);
			printf("\nCPF: %s", loan[i].CPF);
			printf("\nT�tulo: %s", book[pos_isbn].TITULO);
			printf("\nISBN: %s", loan[i].ISBN);
			printf("\nData de Retirada: %d/%d/%d", loan[i].RETIRADA.DIA, loan[i].RETIRADA.MES, loan[i].RETIRADA.ANO);
			printf("\nData de Devolu��o: %d/%d/%d", loan[i].DEVOLUCAO.DIA, loan[i].DEVOLUCAO.MES, loan[i].DEVOLUCAO.ANO);
			printf("\nMulta: R$%.2f/dia", loan[i].MULTA);
			printf("\n\n-------------------------------");
			verif=1;			
		}
	}
	if(verif==0)
		printf("\nN�o h� empr�stimos cadastrados  entre os dias %d/%d/%d e %d/%d/%d", dev_inicial.DIA, dev_inicial.MES, dev_inicial.ANO, dev_final.DIA, dev_final.MES, dev_final.ANO);
}

//===================================================
//Fun��o principal
main()
{
	setlocale(LC_ALL, "Portuguese");
	USUARIOS usuario[max];
	LIVROS livro[max];
	EMPRESTIMOS emprestimo[max];
	int op;
	int cont_usuario=0, cont_livro=0, cont_emprestimo=0;

	printf("\t_____ BIBLIOTECA _____");
	criar_exemplos_usuarios(usuario, &cont_usuario);
	criar_exemplos_livros(livro, &cont_livro);
	criar_exemplos_emprestimos(emprestimo, &cont_emprestimo);
	do
	{
		menu();
		printf("\nOp��o desejada: ");
		scanf("%d", &op);
		
		switch(op) //Switch - MENU DE OP��ES
		{
			case 1: //SUBMENU DE USU�RIOS
				system("cls");
				menu_usuario();
				printf("\nOp��o desejada: ");
				scanf("%d", &op);
				
				switch(op) //Switch - SUBMENU DE USU�RIOS
				{
					case 1:
						printf("\n\t=== LISTAR TODOS USU�RIOS ===\n");
						listar_usuarios(usuario, &cont_usuario);
						break;
						
					case 2:
						printf("\n\t=== LISTAR USU�RIO - CPF ===\n");
						listar_cpf(usuario, &cont_usuario);
						break;
						
					case 3:
						if(cont_usuario<max)
						{
							printf("\n\t=== INCLUIR USU�RIO ===\n");
							incluir_usuario(usuario, &cont_usuario);
							printf("\nUsu�rio cadastrado com sucesso.");
						}
						else
							printf("\n\tN�o � poss�vel realizar novos cadastros!\nEntre em contato com o t�cnico respons�vel!\n");
						break;
						
					case 4:
						printf("\n\t=== ALTERAR USU�RIO ===\n");
						alterar_usuario(usuario, &cont_usuario);
						break;
						
					case 5:
						printf("\n\t=== EXCLUIR USU�RIO ===\n");
						excluir_usuario(usuario, &cont_usuario);
						op=0; //Necess�rio resetar para o programa n�o ser encerrado.
						break;
						
					default: //OP��ES INV�LIDAS (<1 OU >5) - SUBMENU DE USU�RIOS
						printf("\n\n\t*** ATEN��O! ***\nOp��o INV�LIDA. Tente novamente\n\t****************");
				}
				break;
				
			case 2: //SUBMENU DE LIVROS
				system("cls");
				menu_livro();
				printf("\nOp��o desejada: ");
				scanf("%d", &op);
			
				switch(op) //Switch - SUBMENU DE LIVROS
				{
					case 1:
						printf("\n\t=== LISTAR TODOS LIVROS ===\n");
						listar_livros(livro, &cont_livro);
						break;
						
					case 2:
						printf("\n\t=== LISTAR LIVRO - ISBN ===\n");
						listar_isbn(livro, &cont_livro);
						break;
						
					case 3:
						if(cont_livro<max)
						{
							printf("\n\t=== INCLUIR LIVRO ===\n");
							incluir_livro(livro, &cont_livro);
							printf("\nLivro cadastrado com sucesso.");
						}
						else
							printf("\n\tN�o � poss�vel realizar novos cadastros!\nEntre em contato com o t�cnico respons�vel!\n");
						break;
						
					case 4:
						printf("\n\t=== ALTERAR LIVRO ===\n");
						alterar_livro(livro, &cont_livro);
						break;
						
					case 5:
						printf("\n\t=== EXCLUIR LIVRO ===\n");
						excluir_livro(livro, &cont_livro);
						op=0; //Necess�rio resetar para o programa n�o ser encerrado.
						break;
						
					default: //OP��ES INV�LIDAS (<1 OU >5) - SUBMENU DE USU�RIOS
						printf("\n\n\t*** ATEN��O! ***\nOp��o INV�LIDA. Tente novamente\n\t****************");
				}
				break;
				
			case 3: //SUBMENU DE EMPR�STIMOS
				system("cls");
				menu_emprestimo();
				printf("\nOp��o desejada: ");
				scanf("%d", &op);
				
				switch(op) //Switch - SUBMENU DE EMPR�STIMOS
				{
					case 1:
						printf("\n\t=== LISTAR TODOS EMPR�STIMOS ===\n");
						listar_emprestimos(usuario, livro, emprestimo, &cont_usuario, &cont_livro, &cont_emprestimo);
						break;
						
					case 2:
						printf("\n\t=== LISTAR EMPR�STIMO - CPF, ISBN, DATA DE RETIRADA ===\n");
						listar_emprestimo_chave(usuario, livro, emprestimo, &cont_usuario, &cont_livro, &cont_emprestimo);
						//buscar_chave_emprestimo(usuario, livro, emprestimo, &cont_usuario, &cont_livro, &cont_emprestimo);
						break;
						
					case 3:
						if(cont_emprestimo<max)
						{
							printf("\n\t=== INCLUIR EMPR�STIMO ===\n");
							incluir_emprestimo(usuario, livro, emprestimo, &cont_usuario, &cont_livro, &cont_emprestimo);
						}
						else
							printf("\n\tN�o � poss�vel realizar novos cadastros!\nEntre em contato com o t�cnico respons�vel!\n");
						break;
						
					case 4:
						printf("\n\t=== ALTERAR EMPR�STIMO ===\n");
						alterar_emprestimo(usuario, livro, emprestimo, &cont_usuario, &cont_livro, &cont_emprestimo);
						break;
						
					case 5:
						printf("\n\t=== EXCLUIR EMPR�STIMO ===\n");
						excluir_emprestimo(usuario, livro, emprestimo, &cont_usuario, &cont_livro, &cont_emprestimo);
						op=0; //Necess�rio resetar para o programa n�o ser encerrado.
						break;
					
					default: //OP��ES INV�LIDAS (<1 OU >5) - SUBMENU DE EMPR�STIMOS
						printf("\n\n\t*** ATEN��O! ***\nOp��o INV�LIDA. Tente novamente\n\t****************");
				}
				break;
				
			case 4: //SUBMENU DE RELAT�RIOS
				system("cls");
				menu_relatorio();
				printf("\nOp��o desejada: ");
				scanf("%d", &op);
				
				switch(op) //Switch - SUBMENU DE RELAT�RIOS
				{
					case 1:
						listar_idade(usuario, &cont_usuario);
						break;
						
					case 2:
						listar_autores(livro, &cont_livro);
						break;
						
					case 3:
						listar_data(usuario, livro, emprestimo, &cont_usuario, &cont_livro, &cont_emprestimo);
						break;
						
					default: //OP��ES INV�LIDAS (<1 OU >5) - SUBMENU DE RELAT�RIOS
						printf("\n\n\t*** ATEN��O! ***\nOp��o INV�LIDA. Tente novamente\n\t****************");
						op=0; //Necess�rio resetar para o programa n�o ser encerrado caso o usu�rio pressionar 5.
				}
				break;
				
			case 5:
				printf("\nPrograma ENCERRADO. At� logo!\n");
				break;
				
			default: //OP��ES INV�LIDAS (<1 OU >5) - MENU DE OP��ES
				printf("\n\n\t*** ATEN��O! ***\nOp��o INV�LIDA. Tente novamente\n\t****************");
		}
	}
	
	while(op!=5);
}
