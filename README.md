# app8_1

Aplicaţia 8.1.
Se cere să se implementeze următorii operatorii definiţi peste TDA Arbore binar ordonat:
Creaza, Cauta, Insereaza, SupriMin şi Suprimă. Pentru implementare se va
utiliza metoda bazată pe pointeri 


Am implementat un arbore binar ordonat folosind C++.
 -pentru crearea arborelui si nodurilor am folosit smart pointers.
 -functia de "creaza" a fost implementat in functia de "inserare"
 -functia de "cautare" a fost implementata folosind metoda parcurgerii in-ordine
 -functiile de suprimare:
    caz1: nodul nu are fii
    caz2: nodul are doar un fiu
    caz3: nodul are 2 fii
    
    -in cazul 1 si 2 avem o implementare naturala, parcurgem arborele si inlocuim nodul cu null(caz1) sau cu nodul fiu(caz2)
    -in cazul 3 va trebui sa parcurgem subarborele nodului ce urmeaza a fi sters si decidem sa inlocuim nodul ce urmeaza a fi sters cu cel mai mare nod din partea stanga,
    se poate face implementarea si inlocuid cu cel mai mic nod din dreapta.
