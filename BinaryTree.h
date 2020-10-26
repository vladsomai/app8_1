#pragma once
#include "NodeLibrary.h"


//cream structura de date al arborelui
class binaryTree
{
private:

	 shared_ptr<node> root = make_shared<node>();
	 shared_ptr<node> actual = make_shared<node>();
	 static bool dataIsFound;
	 static int searchedNumber;
	

public:


	void insertNode();

	void searchNode(shared_ptr<node> actual);

	//void SupriMin();

	//void Suprima();

	//functia de afisare a nodului prin metoda inordine - vom afisa toate nodurile crescator(proiectia nodurilor), am creat aceasta functie pentru verificare chiar daca nu este in cerintele problemei
	void printBinaryTree(shared_ptr<node> actual);


	shared_ptr<node> getRoot() { return this->root; }

	void setSearchedNumber();
	int getSearchedNumber();

	void setDataIsFound() { this->dataIsFound = true; }
	bool getDataIsFound() { return dataIsFound; }

	//constructor pentru a initializa radacina si nodul actual la null 
	binaryTree()
	{
		this->searchedNumber = 0;
		this->dataIsFound = false;
		this->root = nullptr;
		this->actual = nullptr;
	}
};

void binaryTree::setSearchedNumber()
{
	cout << "Introduceti numarul cautat: ";
	cin >> this->searchedNumber;

}


int binaryTree::getSearchedNumber()
{
	return this->searchedNumber;

}
//functia de afisare a arborelui, vom folosi recursivitate pentru a intra in adancimea arborelui, vom folosi tehnica de traversare inordine
void binaryTree::printBinaryTree(shared_ptr<node> actual)
{
	

	if (this->root == NULL)
	{
		printf("\nArborele este gol!\tIntroduceti un nod.\n");
		return;

	}
	else
	{
		/*daca nodul din stanga / dreapta are atasat un nod, vom intra in el sa verificam toate nodurile
		din stanga si dreapta pana la nullptr, cand am ajuns la null putem afisa nodul parinte al "nodului null"la care am ajuns, dupa care trecem la partea dreapta

		Exemplu : introducem numerele 11 5 3 7 9
		arborele nostru arata asa(pentru claritate am adaugat n - nullptr):
			    11
		   5         n
		 3     7
	   n  n   n  9

		 -> verificam daca nodul 11 are nod in stanga
		 -> avem nodul 5 la care verificam si la el nodul din stanga
		 -> avem nodul 3 care are nodul din stanga null, il afisam pe 3 dupa care verificam daca nodul 3 are nod in dreapta, nod din dreapta este tot null
		 -> revenim cu pointerul de pe stack la memoria unde se executa verificarea nodului 5, care se si afiseaza deoarece am verificat nodurile din stanga
		 -> nodul 5 are nodul 7 in dreapta
		 -> verificam daca nodul 7 are nod atasat in stanga, acesta este null
		 -> afisam nodul 7
		 -> verificam daca nodul 7 are atasat nod in dreapta, avem nodul 9
		 -> la nodul 9 verificam staga- este null
		 -> afisam 9
		 -> verificam daca nodul 9 are atasat un nod in dreapta, acesta e null
		 -> revenim cu pointerul de pe stack la radacina si o afisam
		 -> verificam daca radacina are nod in dreapta, acesta este null

		 deci vom afisa : 3 5 7 9 11
		*/


		if (actual->getLeft() != NULL)
		{
			this->printBinaryTree(actual->getLeft());
		}


		cout << actual->getData()<<"\t";

		if (actual->getRight() != NULL)
		{
			this->printBinaryTree(actual->getRight());
		}
	}


}



void binaryTree::insertNode()
{

	int data;//variabila locala pentru a captura data nodului.

	//in cazul in care radacina arborelui nu este definita, o cream si introducem un numar
	if (this->root == nullptr)
	{
		printf("Arborele este gol, introduceti radacina: \n");

		//alocam memorie pentru radacina folosind make_shared() in care se apeleaza si constructorul care initializeaza variabilele obiectului cu 0 si nullptr(data, left, right)
		this->root = make_shared<node>();
		cin >> data;
		this->root->setData(data);//setam data(cheia) radacinii cu numarul introdus din obiectul "cin".
	}

	//in cazul in care radacina este deja definita o vom folosii pentru a crea ramurile si frunzele arborelui 
	else
	{
		printf("\nIntroduceti un numar in arbore: ");


		//cream un nou nod prin alocarea memoriei dinamic folosind make_shared() si ii atribuim o valoare in variabila "data"
		shared_ptr<node> newNode = make_shared<node>();
		cin >> data;
		newNode->setData(data);


		//dupa crearea nodului urmeaza linkuirea cu radacina sau arborele deja existent


		//pornim intotdeauna de la radacina
		actual = this->root;


		//vom itera nodurile pana cand gasim locuri disponibile pentru insertie, in cazul in care am ajuns la un nod null, ne oprim pentru ca am ajuns la capatul arborelui
		while (actual != nullptr)
		{


			//inseram nodul in stanga daca numarul introdus este mai mic sau egal cu cel existent
			if ( newNode->getData() <= actual->getData() )
			{

				//verificam daca insertia noului nod poate avea loc, daca nu poate avea loc, vom lua nodul actual si il vom itera pana cand gasim un nod cu loc liber
				if (actual->getLeft() == nullptr)
				{
					//asignam nodul nou in arbore si iesim din functie.
					actual->setLeft(newNode);
					return;
				}
				else
				{
					//punem nodul actual la noua adresa nenula  (iteram in arbore)
					actual = actual->getLeft();
				}


			}
			//inseram nodul in dreapta daca numarul introdus este strict mai mare cu cel existent
			else if ( newNode->getData() > actual->getData() )
			{
				//verificam daca insertia noului nod poate avea loc, daca nu poate avea loc, vom lua nodul actual si il vom itera pana cand gasim un nod cu loc liber
				if (actual->getRight() == nullptr)
				{
					//asignam nodul nou in arbore si iesim din functie.
					actual->setRight(newNode);
					return;
				}
				else
				{
					actual = actual->getRight();
				}


			}

		}

	}

}



/*
Functia de cautare functioneaza la fel ca si functia de afisare,
in cazul in care am ajuns la un nod cu numarul pe care il cautam,
vom seta un flag global cu numarul de la nod si il vom afisa din main

*/
void binaryTree::searchNode(shared_ptr<node> actual)
{



	if (this->root == NULL)
	{
		printf("\nArborele este gol!\tIntroduceti un nod.\n");
		return;

	}
	else
	{



		if (actual->getLeft() != NULL)
		{
			this->printBinaryTree(actual->getLeft());
		}


		if (actual->getData() == this->searchedNumber)
		{
			this->dataIsFound = true;
		}

		if (actual->getRight() != NULL)
		{
			this->printBinaryTree(actual->getRight());
		}
	}


}


/*
pentru a suprima un nod din arbore, va trebui sa cautam nodul dupa care executam stergerea doar daca nodul nu impacteaza ABO.


struct node* suprima(struct node* root, int searchedNumber)
{


	if (root == NULL)
	{
		printf("\nArborele / nodul este gol!\n");
		return root;
	}

	if (root->left != NULL)
	{
		suprima(root->left, searchedNumber);
	}



	if (root->data == searchedNumber)
	{

		printf("Am gasit numarul in arbore: %d.\tVom efectua stergerea... ", searchedNumber);


		//daca unul din fi este nul, putem efectua stergerea(XOR)

		//operatia de xor pentru a afla daca unul in fi este null
		if ((root->left == NULL) && (root->right == NULL))
		{
			printf("Nodul nu are fii\n");
			root = NULL;
			return root;
		}


		if ((root->left != NULL) != (root->right != NULL))
		{


			if (root->left != NULL)
			{
				root = root->left;
				return root;
			}
			if (root->right != NULL)
			{
				root = root->right;
				return root;
			}

		}

		//searchFlag = root->data;
	}



	if (root->right != NULL)
	{
		suprima(root->right, searchedNumber);
	}


}

void supriMin(struct node* root)
{


}
*/