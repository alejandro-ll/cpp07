// #include <iostream>
// #include <cstdlib>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

#include <iostream>
#include <string>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
#include "Array.hpp"

using std::cout;
using std::endl;

// 👇 Defínelo fuera de main (ámbito de fichero)
struct Punto {
    int x, y;
};

template<typename T>
void printArray(const Array<T>& arr, const std::string& name)
{
    cout << name << " (size=" << arr.size() << "): ";
    for (unsigned int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    std::srand(std::time(NULL));  // semilla aleatoria

    // 1) Array vacío
    Array<int> vacio;
    cout << "Array vacío creado. size = " << vacio.size() << endl;
    try {
        vacio[0] = 5; // debe lanzar excepción
    } catch (const std::exception& e) {
        cout << "Excepción esperada: " << e.what() << endl;
    }

    cout << "---------------------------------------------\n";

    // 2) Array de enteros
    Array<int> numeros(5);
    for (unsigned int i = 0; i < numeros.size(); ++i)
        numeros[i] = std::rand() % 100;

    printArray(numeros, "numeros");

    cout << "---------------------------------------------\n";

    // 3) Copia profunda (ctor copia)
    Array<int> copia(numeros);
    copia[0] = 9999; // no debe afectar a 'numeros'
    printArray(numeros, "numeros original");
    printArray(copia, "copia modificada");

    cout << "---------------------------------------------\n";

    // 4) Asignación (operator=)
    Array<int> asignado;
    asignado = numeros;
    asignado[1] = 7777;
    printArray(numeros, "numeros original");
    printArray(asignado, "asignado modificado");

    cout << "---------------------------------------------\n";

    // 5) Array de strings
    Array<std::string> palabras(3);
    palabras[0] = "Hola";
    palabras[1] = "módulo";
    palabras[2] = "CPP07";
    printArray(palabras, "palabras");

    Array<std::string> copiaPalabras = palabras;
    copiaPalabras[2] = "ex02";
    printArray(palabras, "palabras original");
    printArray(copiaPalabras, "copiaPalabras modificada");

    cout << "---------------------------------------------\n";

    // 6) Acceso fuera de rango
    try {
        cout << palabras[5] << endl;
    } catch (const std::exception& e) {
        cout << "Excepción esperada (fuera de rango): " << e.what() << endl;
    }

    cout << "---------------------------------------------\n";

    // 7) Array de tipo compuesto (struct)
    Array<Punto> puntos(2);
    puntos[0].x = 10; puntos[0].y = 20;
    puntos[1].x = -5; puntos[1].y = 42;

    cout << "puntos (size=" << puntos.size() << "): ";
    for (unsigned int i = 0; i < puntos.size(); ++i)
        cout << "(" << puntos[i].x << "," << puntos[i].y << ") ";
    cout << endl;

    cout << "---------------------------------------------\n";
    cout << "✅ Todas las pruebas completadas.\n";
    return 0;
}
