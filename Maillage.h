#ifndef MAILLAGE_H
#define MAILLAGE_H

#include <vector>
#include <string>
#include "Sommet.h"
#include "Face.h"

class Maillage {
public:
    std::vector<Sommet> sommets;
    std::vector<Face> faces;

    // Constructeur à partir d'un fichier PLY
    Maillage(const std::string& cheminFichier);

    // Méthode pour sauvegarder le maillage dans un fichier PLY
    void sauvegarderEnPLY(const std::string& cheminFichier);

    // Affichage des informations du maillage
    void afficher() const;
};

#endif // MAILLAGE_H
