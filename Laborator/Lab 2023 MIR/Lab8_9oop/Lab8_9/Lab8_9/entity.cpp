#include "entity.h"

using namespace std;

entity::entity(string d, float p, string prod, string subst):
name{d},price{p},manufacturer{prod},substance{subst}{
    code = 0;
};

entity::entity(const entity& copy):
    name{copy.getName()},price{copy.getPrice()},
    manufacturer{copy.getManufacturer()},
    substance{copy.getSubstance()},
    code{copy.getCode()}{}


string entity::getName () const{
    return name;
}
float entity::getPrice () const{
    return price;
}
string entity::getManufacturer () const{
    return manufacturer;
}
string entity::getSubstance () const{
    return substance;
}

void entity::setName (const string attr){
    name = attr;
}
void entity::setPrice (const float attr){
    price = attr;
}
void entity::setManufacturer (const string attr){
    manufacturer = attr;
}
void entity::setSubstance (const string attr){
    substance = attr;
}

bool entity::operator==(const entity& a){
    return name == a.getName() && manufacturer == a.getManufacturer();
}

bool entity::operator!=(const entity& a){
    return !(*(this)==a);
}

entity& entity::operator=(const entity& a){
    name = a.getName();
    price = a.getPrice();
    manufacturer = a.getManufacturer();
    substance = a.getSubstance();

    return *this;
}

const string entity::getAfis() const{
    string afis;
    afis += "-----> Medicamentul #";
    afis += to_string(code);
    afis += '\n';
    afis += "Numele medicamentului este: ";
    afis += name;
    afis += '\n';
    afis += "Pretul medicamentului este: ";
    afis += to_string(price);
    afis += '\n';
    afis += "Producatorul medicamentului este: ";
    afis += manufacturer;
    afis += '\n';
    afis += "Substanta activa a medicamentului este: ";
    afis += substance;
    afis += '\n';
    
    return afis;
}

const string entity::getCSVFormat() const{
    string CSV;
    CSV += name;
    CSV += ",";
    CSV += to_string(price);
    CSV += ",";
    CSV += manufacturer;
    CSV += ",";
    CSV += substance;
    CSV += "\n";

    return CSV; 
}

unsigned int entity::getCode() const{
    return code;
}

void entity::setCode(unsigned int attr){
    code = attr;
}