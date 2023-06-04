#ifndef LABA_4_2_ELLIPSE_H
#define LABA_4_2_ELLIPSE_H
#include "object.h"

class [[maybe_unused]] ellipse: public BaseCObject, IGeoFig, IPhysObject, IPrintable, IDialogInitiable {
private:
    double bigRadius = 0, smallRadius = 0;
    double massObj = 0;
    CVector2D positionXY{};
    const char *name = "ellipse";
public:
    double square() override;

    double perimeter() override;

    [[nodiscard]] double mass() const override;

    CVector2D position() override;

    bool operator==(const IPhysObject &ob) const override;

    bool operator<(const IPhysObject &ob) const override;

    void draw() override;

    void initFromDialog() override;

    const char *classname() override;

    unsigned int size() override;
};

#endif //LABA_4_2_ELLIPSE_H
