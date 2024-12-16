#ifndef SOMMET_H
#define SOMMET_H
#include <vector>

class Sommet {
private:
    int x, y, z;
    std::vector<int> voisins;

public:
    Sommet();  // Constructeur par défaut
    Sommet(int x, int y, int z);  // Constructeur avec paramètres

    void setSommet(int x, int y, int z);
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    int getX() const;
    int getY() const;
    int getZ() const;
    void display() const;
    void ajouterVoisin(int index);
    ~Sommet(); // Destructeur
};

#endif // SOMMET_H
