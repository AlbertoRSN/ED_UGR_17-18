#include <iostream>

using namespace std;

/*************************************************************************/
std::ostream& bold_on(std::ostream& os){
    return os << "\e[1m";
}
/*************************************************************************/
std::ostream& bold_off(std::ostream& os){
    return os << "\e[0m";
}


int main(){

  cout<<  "\e[1m" << "Hola" << "\e[0m" << " " << "Hola" << endl;

  cout<< bold_on << "Hola" << bold_off << " " << "Hola" << endl;

}
