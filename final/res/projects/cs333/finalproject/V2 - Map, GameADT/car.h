#ifndef CAR_H
#define CAR_H

struct Car
{
    int carNum;
    bool computer;
    int maxSpeed;
    int xPos;
    int yPos;

    void moveCar(int num, int num2);

    void takeDamage();

    Car(int spot, int carNm, bool isComp);
};

#endif
