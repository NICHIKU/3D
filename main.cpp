#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <iomanip> 
#include "Sommet.h"
#include "Face.h"
#include "Maillage.h"

using namespace std;

int main() {
    try {
        
        Maillage maillage("maillages_exemple/01_cube.ply"); 
        maillage.homotethie(2.0);
        maillage.sauvegarderEnPLY("output.ply"); 
        cout << "Maillage charge et sauvegarde avec succes !" << endl;
    } catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
    }

    return 0;
}
