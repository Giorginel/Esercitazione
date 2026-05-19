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

void viewAllShape(Shape* shapes[], int &nShapes);
void modifyShape(Shape* shapes[], int &nShapes);
void moveShape(Shape* shapes[], int &nShapes);
void newShapes(Shape* shapes[], int &nShapes); //da aggiungere controllo bounding box
void deleteShape(Shape* shapes[], int &nShapes);
void deleteAllShapes();

int getChoiceShape();
int getChoiceMenu();
void getUserParametri(float &px, float &py, float &w, float &h);
void getUserText(char* string);
bool checkBoundingBox(float px, float py, float w, float h);
int selectShape(Shape* shapes[], int &nShapes);
int controlloIntervallo(int min, int max, const string& messaggioErrore);

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
            modifyShape(shapes, nShapes);
            break;
        case 3:
            moveShape(shapes, nShapes);
            break;
        case 4:
            newShapes(shapes, nShapes); 
            break;
        case 5:
            deleteShape(shapes, nShapes);
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
        shapes[i]->Dump();
    }
    
}
void modifyShape(Shape* shapes[], int &nShapes){
    int scelta = selectShape(shapes, nShapes);

    if (scelta == -1) {
        cout << endl << "Non ci sono figure da modificare" << endl;
        return;
    }

    int w = 0.0;
    int h = 0.0;

    cout << endl << "Scegli le nuove dimensioni della figura:" << endl;
    cout << endl << "Inserisci larghezza: ";
    cin >> w;
    cout << endl << "Inserisci altezza: ";
    cin >> h;

    char text[TEXTSIZE];
    getUserText(text);

    if (checkBoundingBox(shapes[scelta]->GetX(), shapes[scelta]->GetY(), w, h) == false)
    {
        return;
    }

    shapes[scelta]->SetDim(w, h);
    shapes[scelta]->SetText(text);

    cout << endl << "Figura modificata con successo con le nuove dimensioni (" << w << ", " << h << ")" << endl;

}
void moveShape(Shape* shapes[], int &nShapes){
    int scelta = selectShape(shapes, nShapes);

    if (scelta == -1) {
        cout << endl << "Non ci sono figure da spostare" << endl;
        return;
    }

    int px = 0.0;
    int py = 0.0;

    cout << endl << "Scegli il nuovo punto iniziale della figura:" << endl;
    cout << endl << "Inserisci x: ";
    cin >> px;
    cout << endl << "Inserisci y: ";
    cin >> py;

    if (checkBoundingBox(px, py, shapes[scelta]->GetWidth(), shapes[scelta]->GetHeight()) == false)
    {
        return;
    }

    shapes[scelta]->SetPosition(px, py);

    cout << endl << "Figura spostata con successo nella posizione (" << px << ", " << py << ")" << endl;
}
void newShapes(Shape* shapes[], int &nShapes){

    int choice = getChoiceShape(); 

    float px = 0.0;
    float py = 0.0;
    float h = 0.0; 
    float w = 0.0;

    getUserParametri(px, py, w, h);
    if (checkBoundingBox(px, py, w, h) == false)
    {
        return;
    }

    //MODIFICARE AGGIUNTA TESTO SENZA NEW

    char text[TEXTSIZE];
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
void deleteShape(Shape* shapes[], int &nShapes){
    int scelta = selectShape(shapes, nShapes);

    if (scelta == -1) {
        cout << endl << "Non ci sono figure da eliminare" << endl;
        return;
    }
}
void deleteAllShapes(){}
int getChoiceShape(){
    
    cout << endl << "Scegli una figura tra quelle valide:" << endl;
    cout << endl << "1 - Rettangolo";
    cout << endl << "2 - Rombo";
    cout << endl << "3 - Triangolo rettangolo"<< endl;

    cout << endl << "Scelta: ";
    int scelta = controlloIntervallo(1, 3, "Errore! Inserisci un numero intero tra 1 e 3.");
    return scelta;     
}
int getChoiceMenu(){

    cout << endl << "Scegli funzione fra queste:" << endl;
    cout << endl << "1. Visualizzazione dei poligoni esistenti";
    cout << endl << "2. Modifica delle proprietà di un poligono";
    cout << endl << "3. Spostamento di un poligono sulla griglia";
    cout << endl << "4. Inserimento di un nuovo poligono";
    cout << endl << "5. Cancellazione di un poligono ";
    cout << endl << "6. Cancellazione di tutti i poligoni";
    cout << endl << "0. Esci"<< endl;
    
    cout << endl << "Scelta: ";
    int scelta = controlloIntervallo(0, 6, "Errore! Inserisci un numero intero tra 0 e 6.");
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
bool checkBoundingBox(float px, float py, float w, float h){
    if (px < 0 || py < 0 || w < 0 || h < 0)
    {
        cout << endl << "I parametri non possono essere negativi" << endl;
        return false;
    } 
    else if (px + w > PIXELS_DIMENSIONS || py + h > PIXELS_DIMENSIONS)
    {
        cout << endl << "La figura non deve uscire dalla griglia" << endl;
        return false;
    } 
    else 
    {
        return true;
    }
}
int selectShape(Shape* shapes[], int &nShapes){
    if (nShapes == 0) {
        return -1; // Nessuna figura disponibile
    } else {
        cout << endl << "Scegli un poligono tra quelli esistenti:" << endl;
        cout << endl;
        viewShape(shapes, nShapes);

        cout << "Inserisci l'indice del poligono: ";
        int choice = controlloIntervallo(0, nShapes - 1, "Errore! Indice non valido. Scegli uno dei numeri dell'elenco.");
        return choice;
    }
}
int controlloIntervallo(int min, int max, const string& messaggioErrore) {
    int input;
    while (true) {
        cin >> input;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << messaggioErrore << endl;
        } 
        else if (input < min || input > max) {
            cout << messaggioErrore << endl;
        } 
        else {
            cin.ignore(10000, '\n');
            return input;
        }
    }
}

/*
 Documents/Universita/2\ anno/Programmazione/Esercitazione/Esercitazione/
 g++  CShape.cpp CRectangle.cpp CRhombus.cpp CRightTriangle.cpp CMenu.cpp -o program
./program.exe
*/