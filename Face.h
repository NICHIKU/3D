#ifndef FACE_H
#define FACE_H

class Face {
private:
    int s1, s2, s3;

public:
    Face(int s1, int s2, int s3);
    int getS1() const;
    int getS2() const;
    int getS3() const;
    void afficher() const;
    bool operator==(const Face& other) const;
};

#endif // FACE_H
