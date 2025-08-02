#include <iostream>

int main()
{ 
    float numero1, numero2;
    std::cout << "Ingresa el primer numero: ";
    std::cin >> numero1;
    
    std::cout << "Ingresa el segundo numero: ";
    std::cin >> numero2;
    
    float suma = numero1 + numero2;
    float resta = numero1 - numero2;
    float multiplicacion = numero1 * numero2;
    float división = numero1 / numero2;
    
    std::cout << "La suma de ambos numeros es: " << suma << std::endl;
    
    std::cout << "La resta de ambos numeros es: " << resta << std::endl;
    
    std::cout << "La multiplicacion de ambos numeros es: " << multiplicacion << std::endl;
    
    std::cout << "La división de ambos numeros es: " << división << std::ends;
    
return 0;
}