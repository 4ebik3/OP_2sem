#ifndef LABA_4_2_OBJECT_H
#define LABA_4_2_OBJECT_H

class CVector2D{
public:
    double x, y;
};

class IGeoFig{
public:
    virtual double square() = 0;
    virtual double perimeter() = 0;
};

class IPhysObject{
public:
    [[nodiscard]] virtual double mass() const = 0;
    [[maybe_unused]] virtual CVector2D position() = 0;
    virtual bool operator == (const IPhysObject& ob) const = 0;
    virtual bool operator < (const IPhysObject& ob) const = 0;
};

class IPrintable{
public:
    [[maybe_unused]] virtual void draw() = 0;
};

class IDialogInitiable{
    [[maybe_unused]] virtual void initFromDialog() = 0;
};

class BaseCObject {
public:
    [[maybe_unused]] virtual const char *classname() = 0;
    [[maybe_unused]] virtual unsigned int size() = 0;
};


#endif //LABA_4_2_OBJECT_H
