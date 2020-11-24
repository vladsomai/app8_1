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
La rularea programului vom insera automat noduri pentru verificari rapide.

*/

shared_ptr<binaryTree> CreateBinTree();


int main()
{
	shared_ptr<binaryTree> binaryTree1 = CreateBinTree();
	int searched = 0;
	int toDelete = 0;
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
			cout << endl;
			break;

		case 3:
			//dam un numar pentru cautare
			cout << "Introduceti numarul cautat: "; cin >> searched;
			binaryTree1->setSearchedNumber(searched);

			binaryTree1->searchNode(binaryTree1->getRoot());

			//daca variabila "DataIsFound" a fost setata pe true atunci am gasit numarul
			if (binaryTree1->getDataIsFound())
			{
				cout << "Succes! Numarul "<<binaryTree1->getSearchedNumber()<<" a fost gasit in arbore\n";
			}
			else
			{
				cout << "Eroare! Numarul " << binaryTree1->getSearchedNumber() << " nu a fost gasit in arbore\n";
			}

			//dupa ce am apelat functia de cautare, resetam variabila.
			binaryTree1->resetDataIsFound();
			break;

		case 4:
			binaryTree1->SupriMin();
			break;

		case 5:
			
			cout << "Introduceti numarul cautat: "; cin >> toDelete;
		    binaryTree1->setSearchedNumber(toDelete);
		    binaryTree1->deleteNode(binaryTree1->getRoot());


			//daca variabila "DataIsFound" a fost setata pe true atunci am gasit numarul
			if (binaryTree1->getDataIsFound())
			{
				cout << "Succes! Numarul " << toDelete << " a fost sters din arbore\n";
			}
			else
			{
				cout << "Eroare! Numarul " << toDelete << " nu a fost gasit in arbore, stergerea nu poate avea loc\n";
			}

			//dupa ce am apelat functia de stergere, resetam variabila.
			binaryTree1->resetDataIsFound();

			break;

		default:
			printf("\nWrong option selected.\n");
			break;
		}

		system("pause");
	} while (optiune != 0);


	return 0;
}


shared_ptr<binaryTree> CreateBinTree()
{
	unique_ptr <binaryTree> binaryTree1 = make_unique<binaryTree>();

	binaryTree1->insertNodeParam(2);
	binaryTree1->insertNodeParam(5);
	binaryTree1->insertNodeParam(6);
	binaryTree1->insertNodeParam(7);
	binaryTree1->insertNodeParam(9);
	binaryTree1->insertNodeParam(10);
	binaryTree1->insertNodeParam(13);

	return binaryTree1;

}