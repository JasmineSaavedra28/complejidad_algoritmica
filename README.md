# Programa de complejidad - big_o.cpp

Breve guía para compilar, ejecutar y las respuestas de Big O asociadas a los ejercicios incluidos en `big_o.cpp`.

**Compilar**

PowerShell (Windows):
```powershell
g++ -std=c++17 -O2 big_o.cpp -o big_o.exe
```

Bash / WSL / macOS / Linux:
```bash
g++ -std=c++17 -O2 big_o.cpp -o big_o
```

**Ejecutar**

PowerShell:
```powershell
.\big_o.exe
```

Bash / WSL / macOS / Linux:
```bash
./big_o
```

El programa mostrará un menú interactivo. Respuestas rápidas de ejemplo:
- Opción `7` → no pide `n` y muestra `par` o `impar`.
- Opción `5` → pide `Ingresá n:`; prueba con `32` para ver la progresión logarítmica.
- Opción `0` → salir.

**Consigna (respuestas Big O)**

- **Código 1 (Bucle simple):** `O(N)`. Un único bucle que itera de 0 a N; operación interna constante.
- **Código 2 (Dos bucles secuenciales):** `O(N)`. Dos bucles uno tras otro: `O(N) + O(N) = O(2N)` → `O(N)`.
- **Código 3 (Bucles anidados - j desde i hasta N):** `O(N^2)`. El interno depende del externo, produce cuadrática.
- **Código 4 (Anidados con dos entradas A y B):** `O(N·M)`. Complejidad proporcional a `length(A) × length(B)`.
 - **Código 5 (Bucle con multiplicación - centro derecha):** La variable de control i se multiplica por 2 en cada iteración (i = i * 2). Resultado: O(logN).
- **Código 6 (Bucle externo `O(N)` y bucle interno `O(log N)`):** `O(N log N)`. Producto de ambas componentes.
- **Código 7 (Condicional con valor fijo `N = 1000`):** `O(1)`. Tiempo constante, no depende de la entrada del usuario.

**Cambios clave**

1. **Ajustes teóricos aplicados en el código**:
   - En Ejercicio 3 el bucle interno inicia en `j = i`, generando la progresión `N + (N-1) + ... + 1` → `O(N^2)`.
   - En Ejercicio 7 se fija `N = 1000` dentro de la función para que el tiempo sea constante `O(1)`.
