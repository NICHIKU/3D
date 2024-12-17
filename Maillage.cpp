#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "Maillage.h"
#include "Sommet.h"
#include "Face.h"

using namespace std;

// Constructeur 
Maillage::Maillage(const string& cheminFichier) {
    ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier PLY");
    }

    string ligne;
    int nombreSommets = 0, nombreFaces = 0;

    // Lecture de l'en-tête
    while (getline(fichier, ligne)) {
        if (ligne.substr(0, 14) == "element vertex") {
            nombreSommets = stoi(ligne.substr(15));
        } else if (ligne.substr(0, 12) == "element face") {
            nombreFaces = stoi(ligne.substr(13));
        } else if (ligne == "end_header") {
            break;
        }
    }

    // Lecture des sommets
    for (int i = 0; i < nombreSommets; ++i) {
        getline(fichier, ligne);
        istringstream iss(ligne);
        float x, y, z;
        iss >> x >> y >> z;
        sommets.emplace_back(x, y, z);
    }

    // Lecture des faces
    for (int i = 0; i < nombreFaces; ++i) {
        getline(fichier, ligne);
        istringstream iss(ligne);
        int nombrePoints, s1, s2, s3;
        iss >> nombrePoints >> s1 >> s2 >> s3;
        faces.emplace_back(s1, s2, s3);

        // MAJ des voisins
        sommets[s1].ajouterVoisin(s2);
        sommets[s1].ajouterVoisin(s3);
        sommets[s2].ajouterVoisin(s1);
        sommets[s2].ajouterVoisin(s3);
        sommets[s3].ajouterVoisin(s1);
        sommets[s3].ajouterVoisin(s2);
    }
}

// Méthode pour sauvegarder 
void Maillage::sauvegarderEnPLY(const string& cheminFichier) {
    ofstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        throw runtime_error("Impossible de créer le fichier PLY");
    }

    // Écriture de l'en-tête
    fichier << "ply\n";
    fichier << "format ascii 1.0\n";
    fichier << "element vertex " << sommets.size() << "\n";
    fichier << "property float x\n";
    fichier << "property float y\n";
    fichier << "property float z\n";
    fichier << "element face " << faces.size() << "\n";
    fichier << "property list uchar int vertex_indices\n";
    fichier << "end_header\n";

    // Écriture des sommets
    for (const auto& sommet : sommets) {
        fichier << fixed << setprecision(6) << sommet.getX() << " " << sommet.getY() << " " << sommet.getZ() << "\n";
    }

    // Écriture des faces
    for (const auto& face : faces) {
        fichier << "3 " << face.getS1() << " " << face.getS2() << " " << face.getS3() << "\n";
    }
}


void Maillage::homotethie(double facteur) {
    for (auto& sommet : sommets) {
        sommet.setX(sommet.getX() * facteur);
        sommet.setY(sommet.getY() * facteur);
        sommet.setZ(sommet.getZ() * facteur);
    }
}


// Affichage 
void Maillage::afficher() const {
    cout << "Maillage :\n";
    cout << "Nombre de sommets : " << sommets.size() << "\n";
    cout << "Nombre de faces : " << faces.size() << "\n";

    cout << "Sommets :\n";
    for (const auto& sommet : sommets) {
        sommet.display();
    }

    cout << "Faces :\n";
    for (const auto& face : faces) {
        face.afficher();
    }
}
