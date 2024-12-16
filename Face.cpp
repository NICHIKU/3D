#include <iostream>
#include <vector>
#include <algorithm>
#include "Face.h"
#include "Sommet.h"

using namespace std;

// Constructeur 
Face::Face(int s1, int s2, int s3) : 
    s1(s1), s2(s2), s3(s3) {}
    
// Getter 
int Face::getS1() const {
    return s1;
}

int Face::getS2() const {
    return s2;
}

int Face::getS3() const {
    return s3;
}

// Affichage des sommets d'une face
void Face::afficher() const {
    cout << "Face : [" << s1 << ", " << s2 << ", " << s3 << "]" << endl;
}

// Comparaison entre 2 faces 
bool Face::operator==(const Face& other) const {
    vector<int> f1 = {s1, s2, s3};
    vector<int> f2 = {other.s1, other.s2, other.s3};
    sort(f1.begin(), f1.end());
    sort(f2.begin(), f2.end());
    return f1 == f2;
}
