#include <iostream>
#include <string>

using namespace std;

class Sommet{

    private:
        int x;
        int y;
        int z;
    

    public:
        Sommet();
        Sommet(int x,int y,int z);

        void setSommet(int x, int y, int z);
        
        void setX(int x);
        void setY(int y);
        void setZ(int z);

        int getX() const;
        int getY() const;
        int getZ() const;

        void display() const;

        ~Sommet(); 

};


Sommet::Sommet():
    x(0),y(0),z(0) {}

Sommet::Sommet(int x,int y,int z) :
    x(x), y(y),z(z){}

void Sommet::setSommet(int x, int y,int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void Sommet::setX(int x){
    this->x = x;
}

void Sommet::setY(int y){
    this->y = y;
}

void Sommet::setZ(int z){
    this->z = z;
}

int Sommet::getX() const{
    return x;
}

int Sommet::getY() const{
    return y;
}

int Sommet::getZ() const{
    return z;
}

void Sommet::display() const{
    cout<<"X : "<<x<<" Y : "<<y<< " Z : " << z<<endl;
}

Sommet::~Sommet(){
    cout<< "Destruction du sommet : " << x << " "<< y <<" "<< z << endl;
}

int main() {
    Sommet s1;
    s1.display();

    s1.setSommet(1,2,3);
    s1.display();

    Sommet s2(4,5,6);
    s2.display();
    s2.setX(5);
    s2.setY(6);
    s2.setZ(7);

    return 0;
}