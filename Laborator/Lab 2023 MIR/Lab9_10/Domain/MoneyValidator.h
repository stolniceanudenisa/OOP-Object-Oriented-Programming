//
// Created by fabia on 5/18/2022.
//

#ifndef LAB9_10_MONEYVALIDATOR_H
#define LAB9_10_MONEYVALIDATOR_H

#include "InvalidMoneyValueException.h"

class MoneyValidator{
private:
    int firstValidValue;
    int secondValidValue;
    int thirdValidValue;
public:
    MoneyValidator(int firstValue, int secondValue, int thirdValue) : firstValidValue(firstValue),
    secondValidValue(secondValue), thirdValidValue(thirdValue){
    }

    void validate(int value){
        if (value != firstValidValue || value != secondValidValue || value != thirdValidValue)
            throw InvalidMoneyValueException("The given code must be natural number");
    }
};

#endif //LAB9_10_MONEYVALIDATOR_H
