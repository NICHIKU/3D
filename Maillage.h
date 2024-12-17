#ifndef MAILLAGE_H
#define MAILLAGE_H

#include <vector>
#include <string>
#include "Sommet.h"
#include "Face.h"
using namespace std;

class Maillage {
public:
    vector<Sommet> sommets;
    vector<Face> faces;

    // Constructeur à partir d'un fichier PLY
    Maillage(const std::string& cheminFichier);

    // Fonction pour sauvegarder le maillage dans un autre fichier PLY
    void sauvegarderEnPLY(const std::string& cheminFichier);

    
    void homotethie(double facteur);
    
    void afficher() const;
};

#endif 
