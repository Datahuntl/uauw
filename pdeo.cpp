#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};

typedef treenode *treenodeptr;

void tInsere(treenodeptr &arvore, int x);
treenodeptr tPesq(treenodeptr p, int x);
void preOrdem (treenodeptr arvore);
void emOrdem (treenodeptr arvore);
void posOrdem (treenodeptr arvore);
int CompareOrdem(treenodeptr arvore, int num);
void PesqposOrdem (treenodeptr arvore, int &cont, int num);
void PesqpreOrdem (treenodeptr arvore, int &cont, int num);
void PesqemOrdem (treenodeptr arvore, int &cont, int num);

int main()
{
	treenodeptr arvore = NULL; //ponteiro para a raiz da arvore
	
	int aux; //valor para fazer entrada de cada informação de uma raiz
	
	int cont = 0;
	
	cin >> aux;
	
	while(aux != -1)
	{
		tInsere(arvore, aux);
		
		cin >> aux;
	}
	
	cin >> aux;
	
	PesqpreOrdem(arvore, cont, aux);
	cout << endl;
	cout << cont;
	//PesqemOrdem(arvore, cont, aux);
	cout << endl;
	//PesqposOrdem(arvore, cont, aux);
	
	return 0;
}

//essa função está aqui para criar uma árvore binária
void tInsere(treenodeptr &p, int x)
{
	if(p == NULL) //caso a raiz apontada esteja nula eu vou inserir o valor na informação dela
	{
		p = new treenode; //criando a bolinha da árvore
		p -> info = x; //inserindo o valor na informação da árvore
		p -> esq = NULL;
		p -> dir = NULL;
	}
	else
	{
		/*
		Caso o x seja menor que a informação da raiz ele vai jogar esse valor para
		o filho esquerdo da raiz para fazer a comparação denovo
		*/
		if(x < p -> info)
		{
			tInsere(p -> esq, x); //utilizando agora o filho esquerdo como arvore
		}
		/*
		Caso o x seja menor que a informação da raiz ele vai jogar esse valor para
		o filho direito da raiz para fazer a comparação denovo
		*/
		else
		{
			tInsere(p -> dir, x); //utilizando agora o filho direito como arvore
		}
	}
}

//essa função serve para pesquisar dentro da árvore alguma folha
treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento nao encontrado
		return NULL;
	else
	{
		if(x == p -> info) //elemento encontrado na raiz
			return p;
		else
		{
			if(x < p->info) // procura na sub árvore esquerda
				return tPesq(p -> esq, x);
			else
				return tPesq(p -> dir, x);
		}
	}
}

void preOrdem (treenodeptr arvore)
{
	if(arvore != NULL)
	{
		cout << arvore -> info << endl;
		preOrdem(arvore -> esq);
		preOrdem(arvore -> dir);
	}
}

void emOrdem (treenodeptr arvore)
{
	if(arvore != NULL)
	{
		emOrdem(arvore -> esq);
		cout << arvore -> info << endl;
		emOrdem(arvore -> dir);
	}
}

void posOrdem (treenodeptr arvore)
{
	if(arvore != NULL)
	{
		posOrdem(arvore -> esq);
		posOrdem(arvore -> dir);
		cout << arvore -> info << endl;
	}
}

int CompareOrdem(treenodeptr arvore, int num)
{
	int comparado;
	int cont = 0;
	int contPos, contPre, contEm;
	
	PesqposOrdem(arvore, cont, num);
	
	contPos = cont;
	
	cont = 0;
	
	PesqpreOrdem(arvore, cont, num);
	
	contPre = cont;
	
	cont = 0;
	
	PesqemOrdem(arvore, cont, num);
	
	contEm = cont;
	
	return contPre;
}

void PesqposOrdem (treenodeptr arvore, int &cont, int num)
{
	if(arvore != NULL)
	{
		PesqposOrdem(arvore -> esq, cont, num);
		PesqposOrdem(arvore -> dir, cont, num);
		
		cout << arvore -> info << " ";
		
		if(num == arvore -> info) //elemento encontrado na raiz
			cont++;
		else
			cont++;
	}
}

void PesqpreOrdem (treenodeptr arvore, int &cont, int num)
{
	if(arvore != NULL)
	{
		if(num == arvore -> info) //elemento encontrado na raiz
			cont++;
		
		else
		{
			cont++;
			
			cout << arvore -> info << " ";
			
			PesqpreOrdem(arvore -> esq, cont, num);
			PesqpreOrdem(arvore -> dir, cont, num);
		}
	}
}

void PesqemOrdem (treenodeptr arvore, int &cont, int num)
{
	if(arvore != NULL)
	{
		PesqpreOrdem(arvore -> esq, cont, num);
		
		if(num == arvore -> info) //elemento encontrado na raiz
		{
			cont++;
		
			goto main();
		}
		else
			cont++;
		
		cout << arvore -> info << " ";
		
		PesqpreOrdem(arvore -> dir, cont, num);
	}
}
