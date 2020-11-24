#pragma once
#include "NodeLibrary.h"


//cream structura de date al arborelui
class binaryTree
{
private:

	  shared_ptr<node> root;
	  shared_ptr<node> actual;
	  bool dataIsFound;
	  int searchedNumber;
	

public:


	//-------------------FUNCTIILE ARBORELUI---------------------------
	void insertNode();
	void insertNodeParam(int);
	void searchNode(shared_ptr<node>);
	void SupriMin();
	void printBinaryTree(shared_ptr<node> actual);//functia de afisare a nodului prin metoda inordine - vom afisa toate nodurile crescator(proiectia nodurilor), am creat aceasta functie pentru verificare chiar daca nu este in cerintele problemei
	shared_ptr<node> deleteNode(shared_ptr<node> actual);
	//-----------------------------------------------------------------


	shared_ptr<node> cautaMinim(shared_ptr<node>);//functie care sa returneze cel mai mic nod din arbore - getMinimum()

	shared_ptr<node> getRoot() { return this->root; }

	//functionalitatile de mai jos sunt necesare pentru implementarea functiei de cautare.
	void setSearchedNumber(int searchedNum) { this->searchedNumber = searchedNum; }
	int getSearchedNumber() { return this->searchedNumber; }
	void setDataIsFound()   { this->dataIsFound = true; }
	void resetDataIsFound() { this->dataIsFound = false; }
	bool getDataIsFound()   { return dataIsFound; }


	//constructor pentru a initializa radacina si nodul actual la null 
	binaryTree()
	{

		this->searchedNumber = 0;
		this->dataIsFound = false;
		this->root = nullptr;
		this->actual = nullptr;

	}

};


//functia de afisare a arborelui, vom folosi recursivitate pentru a intra in adancimea arborelui, vom folosi tehnica de traversare inordine
void binaryTree::printBinaryTree(shared_ptr<node> actual)
{
	

	if (this->root == nullptr)
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


		if (actual->getLeft() != nullptr)
		{

			this->printBinaryTree(actual->getLeft());

		}

		cout << actual->getData()<<"\t";

		if (actual->getRight() != nullptr)
		{

			this->printBinaryTree(actual->getRight());

		}

	}

}


void binaryTree::insertNode()
{

	int data;//variabila locala pentru a captura data(cheia) nodului, o vom declara doar atunci cand dorim sa folosim functia de insertie.

	//in cazul in care radacina arborelui nu este definita, o cream si introducem un numar, aici este practic implementata functia de "creare", fara acest pas arborele nostru este null.
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


void binaryTree::insertNodeParam(int data)
{


	//in cazul in care radacina arborelui nu este definita, o cream si introducem un numar, aici este practic implementata functia de "creare", fara acest pas arborele nostru este null.
	if (this->root == nullptr)
	{

		printf("Arborele este gol, introduceti radacina: \n");

		//alocam memorie pentru radacina folosind make_shared() in care se apeleaza si constructorul care initializeaza variabilele obiectului cu 0 si nullptr(data, left, right)
		this->root = make_shared<node>();

		this->root->setData(data);//setam data(cheia) radacinii cu numarul introdus din obiectul "cin".

	}

	//in cazul in care radacina este deja definita o vom folosii pentru a crea ramurile si frunzele arborelui 
	else
	{

		printf("\nIntroduceti un numar in arbore: ");

		//cream un nou nod prin alocarea memoriei dinamic folosind make_shared() si ii atribuim o valoare in variabila "data"
		shared_ptr<node> newNode = make_shared<node>();
		newNode->setData(data);


		//dupa crearea nodului urmeaza linkuirea cu radacina sau arborele deja existent


		//pornim intotdeauna de la radacina
		actual = this->root;


		//vom itera nodurile pana cand gasim locuri disponibile pentru insertie, in cazul in care am ajuns la un nod null, ne oprim pentru ca am ajuns la capatul arborelui
		while (actual != nullptr)
		{

			//inseram nodul in stanga daca numarul introdus este mai mic sau egal cu cel existent
			if (newNode->getData() <= actual->getData())
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
			else if (newNode->getData() > actual->getData())
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


shared_ptr<node> binaryTree::cautaMinim(shared_ptr<node> actual)
{

	if (this->root == nullptr)
	{

		cout<<"Arborele este gol! Nu avem minim."<<endl;
		return actual;

	}
	else
	{

		//atata timp cat nodul din stanga este diferit de null, itereaza la stanga si returneaza adresa nodului la sfarsit
		while (actual->getLeft() != nullptr)
		{

			actual = actual->getLeft();

		}


	}

	return actual;

}


/*
Functia de cautare functioneaza la fel ca si functia de afisare,
in cazul in care am ajuns la un nod cu numarul pe care il cautam,
vom seta un flag global(al arborelui) si il vom afisa din main, pentru aceasta am folosit variabila "dataIsFound"

*/
void binaryTree::searchNode(shared_ptr<node> actual)
{

	if (this->root == nullptr)
	{

		printf("\nArborele este gol!\tIntroduceti un nod.\n");
		return;

	}
	else
	{

		if (actual->getLeft() != nullptr)
		{

			this->searchNode(actual->getLeft());

		}


		if (actual->getData() == this->searchedNumber)
		{

			this->dataIsFound = true;

		}

		if (actual->getRight() != nullptr)
		{

			this->searchNode(actual->getRight());

		}

	}

}


/*
pentru a suprima un nod din arbore, va trebui sa cautam nodul dupa care executam stergerea doar daca nodul nu impacteaza ABO.
*/
shared_ptr<node> binaryTree::deleteNode(shared_ptr<node> actual)
{

	if (actual == nullptr)//radacina null -> arbore gol
	{
		if (this->root == nullptr)//radacina nulla, arbore gol
		{

			return nullptr;

		}
		else
		{

			return  nullptr;//nodul este null, iesim din functie

		}
	}
	else if (this->searchedNumber < actual->getData())//intram in subarborele stang
	{

		cout << "\nNumarul cautat este mai mic, intram in stanga.\n";
		actual->setLeft(deleteNode(actual->getLeft()));

	}
	else if (this->searchedNumber > actual->getData())//intram in subarborele drept
	{

		cout << "\nNumarul cautat este mai mare, intram in dreapta.\n";
		actual->setRight(deleteNode(actual->getRight()));

	}
	else//in cazul in care am ajuns la numarul pe care dorim sa il stergem, adica this->searchedNumber == actual->getData()
	{
		this->setDataIsFound();//setam variabila de gasire.

		//caz 1 - ambii fii ai nodului sunt null -> stergem nodul
		if (actual->getLeft() == nullptr && actual->getRight() == nullptr)
		{

			if (this->root->getLeft() == nullptr && this->root->getRight() == nullptr)//pentru radacina
			{

				this->root = nullptr;
				
			}
			else//pentru nod actual
			{

				actual = nullptr;//setam adresa la null

			}

		}

		
		else if(actual->getLeft() == nullptr)//caz 2.1 daca nodul are nodul din stanga null, inseamna ca putem insera nodul in dreapta
		{
			
			if (this->root->getLeft() == nullptr)
			{

				this->root = this->root->getRight();//pentru radacina

			}
			else
			{

				actual = actual->getRight();//setam actual cu cel din dreapta, dupa care il vom returna si vom reintra in functie recursiv

			}

		}
		else if (actual->getRight() == nullptr)//caz 2.2 daca nodul are nodul din dreapta null, inseamna ca putem insera nodul in stanga
		{

			if (this->root->getRight() == nullptr)
			{

				this->root = this->root->getLeft();//pentru radacina

			}
			else
			{

				actual = actual->getLeft();//setam actual cu cel din stanga, dupa care il vom returna si vom reintra in functie recursiv

			}

		}
		
		else//caz 3 - ambii fii sunt diferiti de null
		{

			cout << "Caz 3 - Ambii fii sunt diferiti de nullptr." << endl;

			shared_ptr<node> smallestNodeInRightSubtree = make_shared<node>();//vom crea un nod care va retine valoare adresei celui mai mic nod din subarborele stang

			smallestNodeInRightSubtree = cautaMinim(actual->getRight()); //apelam functia de cautare a nodului minim din subarborele drept

			

			if (this->root->getData() == searchedNumber)//daca vrem sa sterge radacina
			{

				cout << "Vom inlocui radacina " << this->searchedNumber << " cu nodul " << smallestNodeInRightSubtree->getData() << endl;
				this->root->setData(smallestNodeInRightSubtree->getData());//setam cheia radacinei cu nodul mai mic din subarborele drept

				this->setSearchedNumber(smallestNodeInRightSubtree->getData());//setam nodul de cautare cu cel mai mic nod, pentru a efectua stergerea finala.
				this->root->setRight(deleteNode(this->root->getRight())); //stergem valoare minima pe care am introdus-o in linia de mai sus

			}
			else
			{

				cout << "Vom inlocui cheia nodului " << this->searchedNumber << " cu nodul " << smallestNodeInRightSubtree->getData() << endl;
				actual->setData(smallestNodeInRightSubtree->getData()); // setam cheia nodului actual cu cea a nodului cel mai mic din subarborele drept

				this->setSearchedNumber(smallestNodeInRightSubtree->getData());//setam nodul de cautare cu cel mai mic nod, pentru a efectua stergerea finala.
				actual->setRight(deleteNode(actual->getRight())); //stergem valoare minima pe care am introdus-o in linia de mai sus

			}

		}

	}

	return actual;

}


//apelam functia de stergere cu parametrul nodului cel mai mic din arbore
void binaryTree::SupriMin()
{

	shared_ptr<node> smallestNodeInTree = make_shared<node>();//vom crea un nod care va retine valoare adresei celui mai mic nod din arbore
	smallestNodeInTree = cautaMinim(this->root); //apelam functia de cautare a nodului minim din arbore
	cout << "Vom sterge cel mai mic nod din arbore: "<<smallestNodeInTree->getData() << endl;


	this->setSearchedNumber(smallestNodeInTree->getData());//setam nodul de cautare cu cel mai mic nod, pentru a efectua stergerea finala.
	deleteNode(this->cautaMinim(this->root));

}