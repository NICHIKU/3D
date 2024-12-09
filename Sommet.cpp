#include <iostream>
#include <string>

using namespace std;

class Sommet{

    private:
        int x;

    public:
    Sommet();
    Sommet(int x);

    void setSommet(int x);
    int getSommet() const;

    void display() const;

    ~Sommet(); 

};


Sommet::Sommet() :
    x(0) {}

Sommet::Sommet(int x) :
    x(x){}

void Sommet::setSommet(int x){
    this->x = x;
}

int Sommet::getSommet() const{
    return x;
}

void Sommet::display() const{
    cout<<"X : "<<x<<endl;
}

Sommet::~Sommet(){
    cout<< "Destruction X :" << x<<endl;
}

int main() {
    Sommet s1;
    s1.display();

    s1.setSommet(3);
    s1.display();

    Sommet s2(4);

    s2.display();

    return 0;
}