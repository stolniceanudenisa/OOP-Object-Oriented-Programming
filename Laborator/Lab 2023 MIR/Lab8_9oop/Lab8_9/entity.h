#pragma once
#include <string>

using namespace std;


/*
    Clasa pentru gestionarea entitatilor (medicamentelor)
*/
class entity{
    private:
        string name;
        float price;
        string manufacturer;
        string substance;
        unsigned int code;
    public:
        //Constructor de medicament
        entity(string d, float p, string prod, string subst);
        //Copy constructor
        entity(const entity& copy);

        //return med's name
        string getName () const;  

        //return med's price
        float getPrice () const;

        //return med's manufacturer
        string getManufacturer () const;

        //return med's active substance
        string getSubstance () const;

        //returns the code of the medicine
        unsigned int getCode() const;

        //sets a new code for the medicine
        void setCode(unsigned int attr);
        //sets a new name for the medicine
        void setName (const string attr);      

        //sets a new price for the medicine
        void setPrice (const float attr);

        //sets a new manufacturer for the medicine
        void setManufacturer (const string attr);   

        //sets a new active substance for the medicine     
        void setSubstance (const string attr);

        bool operator==(const entity& a);
        bool operator!=(const entity& a);
        entity& operator=(const entity& a);

        const string getAfis() const;

        const string getCSVFormat() const;
};


