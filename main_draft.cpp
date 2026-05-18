#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"

using namespace std;

#define MAX_SHAPES 10

int main()
{
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    cout << "===== TEST GERARCHIA SHAPE =====" << endl;

    // 1. Creazione figure
    shapes[nShapes++] = new Rectangle(0, 0, 10, 5);
    shapes[nShapes++] = new Rhombus(2, 2, 10, 6);
    shapes[nShapes++] = new RightTriangle(1, 1, 5, 6);
    shapes[nShapes++] = new RightTriangle();




    // 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");
    shapes[2]->SetText("triangolo rettangolo");


    // 3. Dump polimorfico
    cout << endl << "===== DUMP POLIMORFICO =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }


    cout << endl << "===== TEST SCALE =====" << endl;

    shapes[0]->Scale(0.8);
    shapes[0]->Dump();

    shapes[1]->Scale(-0.5);
    shapes[1]->Dump();


    cout << endl << "===== TEST OPERATORI =====" << endl;

    /*Rectangle *r = dynamic_cast<Rectangle*>(shapes[0]); 
    if (r != nullptr) {
        shapes[4] = new Rectangle(*r);
    }
    shapes[4]->Dump();*/

    shapes[nShapes++] = new Rhombus(*(Rhombus*)shapes[1]);
    shapes[4]->Dump();

    if (*shapes[4] == *shapes[1]) cout << endl << "le 2 figura sono uguali" << endl;
    else cout << endl << "le figure non sono uguali" << endl;



    cout << endl << "===== TEST DISTRUTTORI =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        delete shapes[i];
    }
    

    cout << endl << "===== FINE TEST =====" << endl;

    return 0;
}