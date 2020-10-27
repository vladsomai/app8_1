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
	void searchNode(shared_ptr<node>);
	//void SupriMin();
	void Suprima(shared_ptr<node>);
	void printBinaryTree(shared_ptr<node> actual);//functia de afisare a nodului prin metoda inordine - vom afisa toate nodurile crescator(proiectia nodurilor), am creat aceasta functie pentru verificare chiar daca nu este in cerintele problemei
	//-----------------------------------------------------------------



	shared_ptr<node> getRoot() { return this->root; }


	//functionalitatile de mai jos sunt necesare pentru implementarea functiei de cautare.
	void setSearchedNumber() { cout << "Introduceti numarul cautat: "; cin >> this->searchedNumber; }
	int getSearchedNumber() { return this->searchedNumber; }

	void setDataIsFound() { this->dataIsFound = true; }
	void resetDataIsFound() { this->dataIsFound = false; }
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

void binaryTree::Suprima(shared_ptr<node> actual)
{

	if (this->root == nullptr)
	{
		printf("\nArborele este gol!\tIntroduceti radacina.\n");
		return;

	}
	else
	{

		if (actual->getLeft() != nullptr)
		{

			this->Suprima(actual->getLeft());

		}

	
		//daca am ajuns la nodul cu numarul pe care dorim sa il stergem
		if (actual->getData() == this->searchedNumber)
		{
			this->dataIsFound = true;


			//------------------------implementare caz1 si caz2 pentru radacina arborelui------------------------------
            //caz1 verificam daca ambele noduri din dreapta / stanga sunt null
			if (this->root->getLeft() == nullptr && this->root->getRight() == nullptr)
			{

				cout << "\nRadacina are ambii fii nullptr, stergem radacina" << endl;
				this->root = nullptr;
				return;

			}



			//caz2 verificam daca stanga sau dreapta este null
			if (this->root->getLeft() == nullptr)
			{

				//daca nodul din stanga este null - > inseamna ca nodul din dreapta poate fi linkuit la arborele existent
				cout << "\nNodul are fiul stang nullptr" << endl;
				this->root = this->root->getRight();
				return;

			}
			if (this->root->getRight() == nullptr)
			{

				cout << "\nNodul are fiul drept nullptr" << endl;
				this->root = this->root->getLeft();
				return;

			}



			//------------------------implementare caz1 si caz2 pentru un nod oarecare din arbore------------------------------

			//caz1 verificam daca ambele noduri din dreapta / stanga sunt null
			if (actual->getLeft() == nullptr || actual->getRight() == nullptr)
			{
			
				cout << "\nNodul are ambii fii nullptr" << endl;
				actual = nullptr;
				return;

			}



			//caz2 verificam daca stanga sau dreapta este null
			if (actual->getLeft() == nullptr)
			{

				//daca nodul din stanga este null - > inseamna ca nodul din dreapta poate fi linkuit la arborele existent
				cout << "\nNodul are fiul stang nullptr" << endl;
				actual = actual->getRight();
				return;

			}
			if (actual->getRight() == nullptr)
			{

				cout << "\nNodul are fiul drept nullptr" << endl;
				actual = actual->getLeft();
				return;

			}








			shared_ptr<node> greatestNodeInLeftSubtree = make_shared<node>();
			shared_ptr<node> smallestNodeInRightSubtree = make_shared<node>();
			shared_ptr<node> temporary = make_shared<node>();


			//caz3 - ambii fii sunt diferiti de null
			if (actual->getLeft() != nullptr && actual->getRight() != nullptr)
			{



				//cautam cel mai mare nod din subarborele stang
				if (actual->getLeft()->getRight() != nullptr)
				{

					greatestNodeInLeftSubtree = actual->getLeft()->getRight();


					while (greatestNodeInLeftSubtree != nullptr)
					{

						greatestNodeInLeftSubtree = greatestNodeInLeftSubtree->getRight();

					}

					//daca cel mai mare nod din subarborele stang are un nod atasat in stanga lui vom renunta la el
					if (greatestNodeInLeftSubtree->getLeft() != nullptr)
					{

						cout << "\nInlocuirea cu cel mai mare nod din subarborele stang nu poate avea loc deoarece arborele nu va ramane binary ordonat...\t Vom incepe verificarea cu subarborele drept\n";

					}
					else
					{
						//in cazul in care nodul cel mai mare este fezabil(are nodul stang null), il vom pune in locul nodului ce trebuie sters

						if (actual == root)//pentru radacina
						{
							root->setData(greatestNodeInLeftSubtree->getData()); //inlocuim cheia din radacina cu cea mai mare valoare gasita.
							cout << "Am schimbat radacina cu " << root->getData() << endl;
							greatestNodeInLeftSubtree = nullptr; // stergem nodul cel mai mare
							return;
						}
						else //pentru un nod oarecare
						{

							actual->setData(greatestNodeInLeftSubtree->getData());
							cout << "Am schimbat nodul cu " << actual->getData() << endl;

							greatestNodeInLeftSubtree = nullptr;
							return;
						}
					}

				}
				else
				{

					//daca ajungem aici inseamna ca nodul fezabil pentru inlocuire este posibil sa fie cel din stanga, doar in cazul in care acesta nu are nod in dreapta
					if (actual->getLeft()->getRight() == nullptr)
					{

						temporary = actual->getRight();//nod temporar care sa retina adresa subarborelui din dreapta

					   if (actual == root)
					   {
					    	root = root->getLeft();
							root->setRight(temporary);
							cout << "Am schimbat radacina cu " << root->getData() << endl;

							return;

					   }
					   else
					   {

						   actual = actual->getLeft();
						   actual->setRight(temporary);
						   cout << "Am schimbat nodul cu " << actual->getData() << endl;

						   return;

					   }

					}

				}






				//-----------------------------------------------------------------------------------------------


			    //cautam cel mai mic nod din subarborele drept
				if (actual->getRight()->getLeft() != nullptr)
				{

					smallestNodeInRightSubtree = actual->getRight()->getLeft();


					while (smallestNodeInRightSubtree != nullptr)
					{

						smallestNodeInRightSubtree = smallestNodeInRightSubtree->getLeft();

					}

					//daca cel mai mic nod din subarborele drep are un nod atasat in dreapta lui, vom renunta la el
					if (smallestNodeInRightSubtree->getRight() != nullptr)
					{

						cout << "\nInlocuirea cu cel mai mic nod din subarborele drept nu poate avea loc deoarece arborele nu va ramane binary ordonat...\t vom renunta la stergrea acestui nod.\n";
						return;
					}
					else
					{
						//in cazul in care nodul cel mai mic este fezabil(are nodul drept null), il vom pune in locul nodului ce trebuie sters

						if (actual == root)//pentru radacina
						{
							root->setData(smallestNodeInRightSubtree->getData()); //inlocuim cheia din radacina cu cea mai mare valoare gasita.

							cout << "Am schimbat radacina cu " << root->getData() << endl;
							smallestNodeInRightSubtree = nullptr; // stergem nodul cel mai mare
							return;
						}
						else //pentru un nod oarecare
						{

							actual->setData(smallestNodeInRightSubtree->getData());
							smallestNodeInRightSubtree = nullptr;
							cout << "Am schimbat nodul cu " << actual->getData() << endl;

							return;
						}
					}

				}
				else
				{
					
					//daca ajungem aici inseamna ca nodul fezabil pentru inlocuire este posibil sa fie cel din dreapta, doar in cazul in care acesta nu are nod in stanga
					if (actual->getRight()->getLeft() == nullptr)
					{

						temporary = actual->getLeft();//nod temporar care sa retina adresa subarborelui din stanga

						if (actual == root)
						{

							root = root->getRight();
							root->setLeft(temporary);
							cout << "Am schimbat radacina cu " << root->getData() << endl;
							return;

						}
						else
						{

							actual = actual->getRight();
							actual->setLeft(temporary);

							cout << "Am schimbat nodul cu " << actual->getData() << endl;

							return;

						}

					}

				}


				//in cazul in care ajungem cu executia aici, inseamna ca nu am gasit nici un nod valid pentru inlocuirea celui ce trebuie sters
				cout << "\nNu am gasit nici un nod disponibil pentru al inlocui pe cel sters.\n";

			}

		}


		if (actual->getRight() != nullptr)
		{

			this->Suprima(actual->getRight());

		}

	}

}




/*
void supriMin(struct node* root)
{


}
*/




