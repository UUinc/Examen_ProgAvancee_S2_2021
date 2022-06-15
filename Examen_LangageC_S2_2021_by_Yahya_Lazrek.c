/*
Examen : Session normale
2020/2021
Niveau : 2AP
----- by :  Yahya Lazrek -----
*/

//Questions de cours (6 Points) :

// 1)   La différence entre pile et file est que la pile utilise 
//    la méthode LIFO (dernier entré, premier sorti) pour ajouter 
//    et accéder aux éléments de données, tandis que la file utilise 
//    la méthode FIFO (premier entré, premier sorti) pour ajouter 
//    et accéder aux éléments de données.

// 2) Listes chainees:
//      a) Listes simplement chaînée
//      b) Listes doublement chaînées
//      c) Listes simplement chaînée circulaire 
//      d) Listes doublement chaînée circulaire

// la difference entre simplement et doublement est dans le type de liste 
// simplement ont une seule pointeur de suivant au contraire de doublement 
// qui a deux pointeur suivant est precedent.

// la difference entre circulaire et linéaire est dans le derniere pointeur
// de suivant qui point sur la debut de chaine et le premier pointeur precedent
// qui point sur la derniere noeud dans la chaine
// the contrairie dans la chaine lineaire qui point toujours sur null.

// 3) 
//      │        │
//      │────────│
//      │   35   │
//      │────────│
//      │   6    │
//      │────────│
//      │  -10   │
//      │────────│
//      │    3   │
//      │────────│
//      │    1   │
//      └────────┘

//Exercice : (14 Points)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structures
typedef struct Date
{
    int j;
    int m;
    int a;
} Date;

typedef struct TP
{
    int numero;
    char matiere[50];
    Date dateDebut;
    Date dateRemise;
} TP;

typedef struct node
{
    TP value;
    struct node* next;
    struct node* prev;
} node;

//Functions
node* Initialiser(node* _node)
{
    _node = (node*) malloc(sizeof(node));
    _node->next = _node;
    _node->prev = _node;

    return _node;
}
void AjouterFin(node* _node, TP _value)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->value = _value;

    newNode->next = _node;
    newNode->prev = _node->prev;
    _node->prev->next = newNode;
    _node->prev = newNode;
}
void Afficher(node* _node)
{
    node* _tmpNode = _node;

    while(_tmpNode->next != _node)
    {
        _tmpNode = _tmpNode->next;

        printf("TP : %d\n", _tmpNode->value.numero);
        printf(" matiere : %s\n", _tmpNode->value.matiere);
        printf(" la date de debut  : %d/%d/%d\n", _tmpNode->value.dateDebut.j, _tmpNode->value.dateDebut.m, _tmpNode->value.dateDebut.a);
        printf(" la date de remise : %d/%d/%d\n", _tmpNode->value.dateRemise.j, _tmpNode->value.dateRemise.m, _tmpNode->value.dateRemise.a);
    }
}
int TpParMatiere(node* _node, char* _matiere)
{
    int counter=0;
    node* _tmpNode = _node;

    while(_tmpNode->next != _node)
    {
        _tmpNode = _tmpNode->next;

        if(strcmp(_tmpNode->value.matiere, _matiere) == 0)
        {
            counter++;
        }
    }

    return counter;
}
void AjouterTete(node* _node, TP _value)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->value = _value;

    newNode->next = _node->next;
    newNode->prev = _node;
    _node->next->prev = newNode;
    _node->next = newNode;
}
int Rechercher(node* _node, int _numero)
{
    node* _tmpNode = _node;

    while(_tmpNode->next != _node)
    {
        _tmpNode = _tmpNode->next;
        if(_tmpNode->value.numero == _numero)
        {
            return 1;
        }
    }

    return 0;
}
void SupprimerPosition(node* _node, int _position)
{
    int counter=1;
    node* _tmpNode = _node;

    while(_tmpNode->next != _node)
    {
        _tmpNode = _tmpNode->next;
        if(counter == _position)
        {
            _tmpNode->prev->next = _tmpNode->next;
            _tmpNode->next->prev = _tmpNode->prev;
            free(_tmpNode);
        }
        counter++;
    }
}

//Main
int main()
{
    node* liste;
    TP tp1, tp2;

    //Remplir information TP
    //tp1
    tp1.numero = 123;
    strcpy(tp1.matiere, "langage C");
    //date debut
    tp1.dateDebut.j = 10;
    tp1.dateDebut.m = 5;
    tp1.dateDebut.a = 2022;
    //date remise
    tp1.dateRemise.j = 16;
    tp1.dateRemise.m = 6;
    tp1.dateRemise.a = 2022;
    //tp2
    tp2.numero = 124;
    strcpy(tp2.matiere, "Base de donnees");
    //date debut
    tp2.dateDebut.j = 1;
    tp2.dateDebut.m = 2;
    tp2.dateDebut.a = 2022;
    //date remise
    tp2.dateRemise.j = 8;
    tp2.dateRemise.m = 4;
    tp2.dateRemise.a = 2022;

    //-------------------

    //tester fonctions et procédures
    liste = Initialiser(liste);
    AjouterFin(liste, tp1);
    Afficher(liste);

    printf("le nombre de TPs de langage C : %d\n", TpParMatiere(liste, "langage C"));

    AjouterTete(liste, tp2);
    Afficher(liste);

    printf("le TP n123 existe : %d\n", Rechercher(liste, 123));

    SupprimerPosition(liste, 1);
    Afficher(liste);

    return 0;
}

//Check out
// github:   https://github.com/UUinc
// twitter:  https://twitter.com/yahya_lz
// linkedin: https://www.linkedin.com/in/yahyalazrek/