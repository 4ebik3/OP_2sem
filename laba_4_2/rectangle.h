#ifndef LABA_4_2_RECTANGLE_H
#define LABA_4_2_RECTANGLE_H
#include "object.h"

class [[maybe_unused]] rectangle: public BaseCObject, IGeoFig, IPhysObject, IPrintable, IDialogInitiable {
private:
    double side1 = 0, side2 = 0;
    CVector2D positionXY{};
    double massObj = 0;
    const char *name = "rectangle";

public:
    double square() override;

    double perimeter() override;

    [[nodiscard]] double mass() const override;

    CVector2D position() override;

    bool operator==(const IPhysObject& ob) const override;

    bool operator<(const IPhysObject& ob) const override;

    void draw() override;

    void initFromDialog() override;

    const char *classname() override;

    unsigned int size() override;
};

#endif //LABA_4_2_RECTANGLE_H
