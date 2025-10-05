#include "poscode.hpp"

Poscode::Poscode():data(""){
        
}
Poscode::Poscode(std::string _data) : data(_data){

}
char Poscode::getValue(size_t i) const {
    return data[i];
}
const std::string &Poscode::getData(){
    return data;
}
bool Poscode::operator==(const Poscode& other) const {
    return data == other.data;
}
bool Poscode::operator!=(const Poscode& other) const {
    return data != other.data;
}