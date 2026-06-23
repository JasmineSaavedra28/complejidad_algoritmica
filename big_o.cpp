#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// --- Declaración de funciones ---
void ejercicio1(int n); // O(N)
void ejercicio2(int n); // O(N)
void ejercicio3(int n); // O(N^2)
void ejercicio4();      // O(N*M)
void ejercicio5(int n); // O(log N)
void ejercicio6(int n); // O(N log N)
void ejercicio7();      // O(1)

// Función auxiliar para limpiar el buffer de entrada en C++ (equivalente al try/except)
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int opcion = 0;
    int n = 0;

    while (true) {
        cout << "\n--- MENU DE COMPLEJIDAD (BIG O) ---" << endl;
        cout << "1 - Ejercicio 1 (O(N))" << endl;
        cout << "2 - Ejercicio 2 (O(N))" << endl;
        cout << "3 - Ejercicio 3 (O(N^2))" << endl;
        cout << "4 - Ejercicio 4 (O(N*M))" << endl;
        cout << "5 - Ejercicio 5 (O(log N))" << endl;
        cout << "6 - Ejercicio 6 (O(N log N))" << endl;
        cout << "7 - Ejercicio 7 (O(1))" << endl;
        cout << "0 - Salir" << endl;
        cout << "Elegi un caso: ";

        if (!(cin >> opcion)) {
            cout << "Ingresá un número válido." << endl;
            limpiarBuffer();
            continue;
        }

        if (opcion == 0) {
            cout << "Saliendo..." << endl;
            break;
        }

        // Los ejercicios 4 y 7 no necesitan 'n' porque usan tamaños fijos
        if (opcion != 4 && opcion != 7) {
            cout << "Ingresá n: ";
            if (!(cin >> n) || n < 0) {
                cout << "n debe ser un número entero positivo." << endl;
                limpiarBuffer();
                continue;
            }
        }

        cout << "\n--- Resultado ---" << endl;
        
        // Equivalente al match/case de Python es el switch en C++
        switch (opcion) {
            case 1: ejercicio1(n); break;
            case 2: ejercicio2(n); break;
            case 3: ejercicio3(n); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(n); break;
            case 6: ejercicio6(n); break;
            case 7: ejercicio7(); break;
            default: cout << "Opción inválida." << endl; break;
        }
    }

    return 0;
}

// --- IMPLEMENTACIÓN DE EJERCICIOS ---

// Código 1: Bucle simple. O(N)
void ejercicio1(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;
}

// Código 2: Dos bucles secuenciales. O(N) + O(N) = O(2N) -> O(N)
void ejercicio2(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;
}

// Código 3: Bucles anidados (j va de i a N). O(N^2)
void ejercicio3(int n) {
    for (int i = 0; i < n; i++) {
        // El interno depende del externo, empieza en 'i'
        for (int j = i; j < n; j++) { 
            cout << "(" << i << "," << j << ") ";
        }
    }
    cout << endl;
}

// Código 4: Bucles anidados con dos entradas (Arreglos). O(N*M)
void ejercicio4() {
    // En C++ usamos std::vector en lugar de listas de Python
    vector<int> A = {1, 2, 3};
    vector<int> B = {10, 20};
    
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            cout << A[i] << "," << B[j] << " ";
        }
    }
    cout << endl;
}

// Código 5: Bucle con multiplicación. O(log N)
void ejercicio5(int n) {
    // i se multiplica por 2 en cada iteración
    for (int i = 1; i < n; i = i * 2) {
        cout << i << " ";
    }
    cout << endl;
}

// Código 6: Bucle anidado con while logarítmico. O(N log N)
void ejercicio6(int n) {
    for (int i = 0; i < n; i++) {       // Externo: O(N)
        for (int j = 1; j < n; j = j * 2) { // Interno: O(log N)
            cout << j << " ";
        }
        cout << "| "; // Separador visual por cada vuelta del bucle externo
    }
    cout << endl;
}

// Código 7: Condicional con valor fijo. O(1)
void ejercicio7() {
    int N = 1000; // Valor fijo, no depende de la entrada del usuario
    if (N % 2 == 0) {
        cout << "par" << endl;
    } else {
        cout << "impar" << endl;
    }
}