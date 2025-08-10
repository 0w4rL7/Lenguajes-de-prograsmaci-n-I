#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Diccionario de palabras prohibidas
const std::vector<std::string> palabrasProhibidas = {
    "PENE", "POPO", "PUTO", "CACA", "PUTA", "CJNG", "JOTO", "PITO"
};

// Verificar y modificar palabras prohibidas del diccionario
std::string corregirRFC(const std::string& rfc) {
    for (const std::string& palabra : palabrasProhibidas) {
        if (rfc == palabra) {
            return rfc.substr(0, 3) + "X"; // Reemplaza la última letra por 'X'
        }
    }
    return rfc;
}

// Función para obtener la primera vocal interna del apellido paterno
char obtenerPrimeraVocalInterna(const std::string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = toupper(str[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return c;
    }
    return 'X'; // Si no se encuentra vocal interna
}

// Función principal para calcular el RFC
std::string calcularRFC(std::string nombre, std::string apellidoPaterno, std::string apellidoMaterno,
                        int dia, int mes, int anio) {
    // Convertir todos los strings a mayúsculas
    std::transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);
    std::transform(apellidoPaterno.begin(), apellidoPaterno.end(), apellidoPaterno.begin(), ::toupper);
    std::transform(apellidoMaterno.begin(), apellidoMaterno.end(), apellidoMaterno.begin(), ::toupper);

    std::string rfc = "";

    // Agrega la primera letra del apellido paterno
    rfc += apellidoPaterno[0];

    // Agrega la primera vocal interna del apellido paterno
    rfc += obtenerPrimeraVocalInterna(apellidoPaterno);

    // Agrega la primera letra del apellido materno o 'X' si no hay
    rfc += (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';

    // Agrega la primera letra del nombre
    rfc += nombre[0];

    // Verificar si es una palabra prohibida
    rfc = corregirRFC(rfc);

    // Formatear fecha: últimos 2 dígitos del año, mes y día
    char fecha[7];
    sprintf(fecha, "%02d%02d%02d", anio % 100, mes, dia);

    rfc += fecha;

    return rfc;
}

int main() {
    std::string nombre, apellidoPaterno, apellidoMaterno;
    int dia, mes, anio;

    std::cout << "Calculo de RFC" << std::endl;
    std::cout << "Introduce tu nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Introduce tu apellido paterno: ";
    std::getline(std::cin, apellidoPaterno);

    std::cout << "Introduce tu apellido materno (si no tienes, presiona Enter): ";
    std::getline(std::cin, apellidoMaterno);

    std::cout << "Fecha de nacimiento (solo numeros)" << std::endl;
    std::cout << "Dia: ";
    std::cin >> dia;
    std::cout << "Mes: ";
    std::cin >> mes;
    std::cout << "Año: ";
    std::cin >> anio;

    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, dia, mes, anio);

    std::cout << "El RFC sin homoclave es: " << rfc << std::endl;

    return 0;
}