#ifndef SOMMET_H
#define SOMMET_H
#include <vector>
using namespace std;

class Sommet {
private:
    int x, y, z;
    vector<int> voisins;

public:
    Sommet();  
    Sommet(int x, int y, int z);  

    void setSommet(int x, int y, int z);
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    int getX() const;
    int getY() const;
    int getZ() const;
    void display() const;
    void ajouterVoisin(int index);
    void translater(int dx, int dy, int dz);
    ~Sommet(); 
};

#endif 
