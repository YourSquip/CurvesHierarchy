
#include <iostream>
#include <vector>
#include <algorithm> 
#include <time.h>
#include "Circle.h"
#include "Elipse.h"
#include "Helix.h"
using namespace std;
bool compare(Curve* c1, Curve* c2)
{
    return (c1->GetRadius() < c2->GetRadius());
}

int main()
{
    srand(time(NULL));
    vector<Curve*> container;

    int a = 10, b = 100;
    int aStep = 0, bStep = 6;

    Curve* circle1 = new Circle(a + rand() % (b - a));
    Curve* circle2 = new Circle(a + rand() % (b - a));
    Curve* circle3 = new Circle(a + rand() % (b - a));
    Curve* elipse1 = new Elipse(a + rand() % (b - a), a + rand() % (b - a));
    Curve* helix1 = new Helix(a + rand() % (b - a), aStep + rand() % (bStep - aStep));

    container.push_back(circle1);
    container.push_back(circle2);
    container.push_back(circle3);
    container.push_back(elipse1);
    container.push_back(helix1);

    for (int i = 0; i < container.size(); i++)
    {
        container[i]->GetPoint(PI / 4).print();
        container[i]->GetFirstDerivativePoint(PI / 4).print();
        cout << endl;
    }


    vector<Curve*> container1;
    //vector<Circle> container;
    for (int i = 0; i < container.size(); i++)
    {
        if (container[i]->Info() == "Circle") container1.push_back(container[i]);
    }

    sort(container1.begin(), container1.end(), compare);

    for (int i = 0; i < container1.size(); i++)
    {
        cout << container1[i]->GetRadius() << ' ';
    }
    cout << endl;

    double sumOfRadiuses = 0;
    for (int i = 0; i < container1.size(); i++)
    {
        sumOfRadiuses +=container1[i]->GetRadius();
    }
    cout << sumOfRadiuses;

}


