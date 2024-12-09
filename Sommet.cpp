#include <iostream>
#include <string>

using namespace std;

class Sommet{

    private:
        int x;
        int y;

    public:
        Sommet();
        Sommet(int x,int y);

        void setSommet(int x, int y);
        void setX(int x);
        void setY(int y);

        int getX() const;
        int getY() const;

        void display() const;

        ~Sommet(); 

};


Sommet::Sommet():
    x(0),y(0) {}

Sommet::Sommet(int x,int y) :
    x(x), y(y){}

void Sommet::setSommet(int x, int y){
    this->x = x;
    this->y = y;
}

void Sommet::setX(int x){
    this->x = x;
}

void Sommet::setY(int y){
    this->y = y;
}

int Sommet::getX() const{
    return x;
}

int Sommet::getY() const{
    return y;
}

void Sommet::display() const{
    cout<<"X : "<<x<<" Y : "<<y<<endl;
}

Sommet::~Sommet(){
    cout<< "Destruction du sommet : " << x << " "<< y <<endl;
}

int main() {
    Sommet s1;
    s1.display();

    s1.setSommet(1,2);
    s1.display();

    Sommet s2(4,5);
    s2.display();
    s2.setX(3);
    s2.setY(6);

    return 0;
}