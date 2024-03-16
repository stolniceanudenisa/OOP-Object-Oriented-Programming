#include "generator.h"


string generator::genString(){
    
    char alpha[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"; // NOLINT
    string gen = "";
    for(int i=0;i<SIZE;++i){
        gen += alpha[(int)(rand() % 51)]; // NOLINT
    }

    return gen;
}

float generator::genFloat(){
    return (float)(rand() % 1000);
}


entity generator::genEntity(){
    string name = genString();
    float price = genFloat();
    string manufacturer = genString();
    string substance = genString();

    
    entity a(name, price, manufacturer, substance);

    return a;
}