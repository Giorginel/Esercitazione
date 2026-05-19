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


void viewPoli(Shape* shapes[], int &nShapes);
void modifyPoli();
void movePoli();
void newPoli(Shape* shapes[], int &nShapes);
void deletePoli(Shape* shapes[], int &nShapes);
void deleteAllPolis();

int getChoisePoli();
int getChoiseMenu();
void getUserParametri(float &px, float &py, float &w, float &h);
void getUserText(char* string);

int main()
{
    
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    int choise = 99;

    while (choise != 0)
    {
        choise = getChoiseMenu(); 
        switch (choise)
        {
        case 1:
            viewPoli(shapes, nShapes);
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            newPoli(shapes, nShapes); 
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
    
}

void viewPoli(Shape* shapes[], int &nShapes){
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
void modifyPoli();
void movePoli();
void newPoli(Shape* shapes[], int &nShapes){

    int choise = getChoisePoli(); 

    float px = 0.0;
    float py = 0.0;
    float h = 0.0; 
    float w = 0.0;

    getUserParametri(px, py, w, h);
    
    
    char* text = new char[TEXTSIZE];
    getUserText(text);
    
    

    switch (choise)
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
void deletePoli(Shape* shapes[], int &nShapes){

}
void deleteAllPolis();

int getChoisePoli(){
    
    int scelta = 0;

    while (scelta < 1 || scelta > 3) //da aggiustare
    {
        cout << endl << "Scegli una figura tra quelle valide:" << endl;
        
        cout << endl << "1 - Rettangolo";
        cout << endl << "2 - Rombo";
        cout << endl << "3 - Triangolo rettangolo"<< endl;

        cin >> scelta;
    }
    return scelta;     
}
int getChoiseMenu(){
    
    int scelta = 0;

    while (scelta < 1 || scelta > 6) //da aggiustare
    {
        cout << endl << "Scegli funzione:" << endl;
        
        cout << endl << "1. Visualizzazione dei poligoni esistenti";
        cout << endl << "2. Modifica delle proprietà di un poligono";
        cout << endl << "3. Spostamento di un poligono sulla griglia";
        cout << endl << "4. Inserimento di un nuovo poligono";
        cout << endl << "5. Cancellazione di un poligono ";
        cout << endl << "6. Cancellazione di tutti i poligoni"<< endl;
        

        cin >> scelta;
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