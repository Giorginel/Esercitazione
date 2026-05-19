/*! \file CMenu.cpp
    \brief Declaration of the base class Menu
	\author Giorgio Cirjan, Adama Diakhite
*/

#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"

using namespace std;

#define MAX_SHAPES 10
#define PIXELS_DIMENSIONS 100


void viewAllShapes(Shape* shapes[], int &nShapes);
void modifyShapes();
void moveShapes();
void newShapes(Shape* shapes[], int &nShapes);
void deleteShapes(Shape* shapes[], int &nShapes);
void deleteAllShapes();

int getChoiceShape();
int getChoiceMenu();
void getUserParametri(float &px, float &py, float &w, float &h);
void getUserText(char* string);

int main()
{
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    int choice = 99;

    while (choice != 0)
    {
        choice = getChoiceMenu(); 
        switch (choice)
        {
        case 1:
            viewAllShapes(shapes, nShapes);
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            newShapes(shapes, nShapes); 
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 0:
            cout << endl << "Uscita in corso..." << endl;
            break;
        default:
            cout << endl << "Scelta non disponibile" << endl;
            break;
        }
    }
    


    cout << endl << "Fine programma" << endl;
}

void viewAllShapes(Shape* shapes[], int &nShapes){
    if (nShapes == 0)
    {
        cout << endl << "Attualmente non ci sono figure" << endl;
        return;
    }
    
    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        cout << "------------------------> " << i;
        shapes[i]->Dump();
    }
    
}
void modifyShapes();
void moveShapes();
void newShapes(Shape* shapes[], int &nShapes){

    int choice = getChoiceShape(); 

    float px = 0.0;
    float py = 0.0;
    float h = 0.0; 
    float w = 0.0;

    getUserParametri(px, py, w, h);
    
    
    char* text = new char[TEXTSIZE];
    getUserText(text);
    
    

    switch (choice)
    {
    case 1:
        shapes[nShapes] = new Rectangle(px, py, w, h);
        shapes[nShapes]->SetText(text);
        break;
        
    case 2:
        shapes[nShapes] = new Rhombus(px, py, w, h);
        shapes[nShapes]->SetText(text);
        break;
    
    case 3:
        shapes[nShapes] = new RightTriangle(px, py, w, h);
        shapes[nShapes]->SetText(text);
        break;

    }

    nShapes++;
    
}
void deleteShapes(Shape* shapes[], int &nShapes){

}
void deleteAllShapes(){

}

int getChoiceShape(){
    
    int scelta = 0;

    while (true)
    {
        cout << endl << "Scegli una figura tra quelle valide:" << endl;
        cout << endl << "1 - Rettangolo";
        cout << endl << "2 - Rombo";
        cout << endl << "3 - Triangolo rettangolo"<< endl;

        cin >> scelta;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input non valido"<< endl;
            continue;
        }

        if (scelta >= 1 && scelta <= 3)
            return scelta;

        cout << "Figura non valida\n";
    }
 
}
int getChoiceMenu(){
    
    int scelta;

    cout << endl << "Scegli una funzione fra queste:" << endl;
    
    cout << endl << "1. Visualizzazione delle figure esistenti";
    cout << endl << "2. Modifica delle proprietà di una figura";
    cout << endl << "3. Spostamento una figura sulla griglia";
    cout << endl << "4. Inserimento di una nuova figura";
    cout << endl << "5. Cancellazione di una figura ";
    cout << endl << "6. Cancellazione di tutti i poligoni";
    cout << endl << "0. Exit" << endl;
    
    cin >> scelta;
    if (cin.fail()) {               //errore di cin
        cin.clear();                // reset stato errore
        cin.ignore(1000, '\n');     // svuota buffer
        scelta= 99;                 //cosi quando tornaimo nello switch attiviamo il caso dafault
    }

    return scelta;     
}
void getUserParametri(float &px, float &py, float &w, float &h){

    cout << endl << "Scegli il punto iniziale della figura:" << endl;
    cout << endl << "Inserisci x: ";
    cin >> px;
    cout << endl << "Inserisci y: ";
    cin >> py;
    cout << endl << "Inserisci altezza: ";
    cin >> h;
    cout << endl << "Inserisci larghezza: ";
    cin >> w;

}

void getUserText(char* string){

    cout << endl << "Inserisci il testo della figura:"<< endl;
    cin >> string;
}

/*
1 - Visualizza tutti i poligoni
2 - Modifica le proprietà di un poligono
3 - Sposta un poligono sulla griglia
4 - Inserisci un nuovo poligono
5 - Cancella un poligono
6 - Cancella tutti i poligoni
0 - Esci
*/