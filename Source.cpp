#include "BinaryTree.h"
#include<memory>
#include<stdio.h>

/*
Aplicatia 8.1.
Se cere sa se implementeze următorii operatorii definiti peste TDA Arbore binar ordonat:
Creaza, Cauta, Insereaza, SupriMin şi Suprima. Pentru implementare se va
utiliza metoda bazata pe pointeri

Am realizat programul in C++ pentru o mai buna structurare a tipurilor de date si usurinta de a lucra cu fiecare obiect.

Operatorul "Creeaza" l-am implementat in functia de insertie, pentru a fi mai usor de lucrat cu programul.

*/



bool binaryTree::dataIsFound=false;
int binaryTree::searchedNumber = 0;


int main()
{
	unique_ptr <binaryTree> binaryTree1 = make_unique<binaryTree>();

	int optiune = 0;

	do
	{	
		system("cls");
		cout<<"\n\n1.Inserare.\n";
		cout<<"2.Afisare.\n";
		cout<<"3.Cauta.\n";
		cout<<"4.SuprimaMin\n";
		cout<<"5.Suprima.\n";
		cout << "0.Exit.\n";
		

		cin >> optiune;


		switch (optiune)
		{
		case 0:
			printf("Exiting...\n\n\n");
			break;
			

		case 1:
			binaryTree1->insertNode();
			break;

		case 2:
			cout <<"\nArborele contine: \n";
			binaryTree1->printBinaryTree(binaryTree1->getRoot());
			break;

		case 3:
			binaryTree1->setSearchedNumber();

			binaryTree1->searchNode(binaryTree1->getRoot());

			if (binaryTree1->getDataIsFound())
			{
				cout << "Succes! Numarul "<<binaryTree1->getSearchedNumber()<<" a fost gasit in arbore\n";
			}
			else
			{
				cout << "Eroare! Numarul " << binaryTree1->getSearchedNumber() << " nu a fost gasit in arbore\n";
			}
			break;

		case 4:
		//	binaryTree1->SupriMin();
			break;

		case 5:
		//	 binaryTree1->Suprima();
			break;

		default:
			printf("\nWrong option selected.\n");
			break;
		}

		system("pause");
	} while (optiune != 0);


	return 0;
}