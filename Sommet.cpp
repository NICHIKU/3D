#include "Sommet.h"
#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;

Sommet::Sommet() : x(0), y(0), z(0) {}

Sommet::Sommet(int x, int y, int z) : x(x), y(y), z(z) {}

void Sommet::setSommet(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Sommet::setX(int x) {
    this->x = x;
}

void Sommet::setY(int y) {
    this->y = y;
}

void Sommet::setZ(int z) {
    this->z = z;
}

int Sommet::getX() const {
    return x;
}

int Sommet::getY() const {
    return y;
}

int Sommet::getZ() const {
    return z;
}

void Sommet::display() const {
    cout << "X : " << x << " Y : " << y << " Z : " << z << endl;
}

void Sommet::ajouterVoisin(int indice) {
    if (find(voisins.begin(), voisins.end(), indice) == voisins.end()) {
        voisins.push_back(indice);
    }
}

Sommet::~Sommet() {
    
}
