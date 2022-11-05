# Ejercicio 1

Algoritmos vistos en la teórica:

- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort

Complejidades si el arreglo está inversamente ordenado al querido:

- Selection sort. En cada iteración tiene que ir al final del arreglo a buscar el menor. Complejidad = $n(n+1) / 2 = O(n^2)$
- Insertion sort. A cada elemento lo va a tener que insertar i veces siendo i la posición del elemento en el arreglo. Complejidad = $O(n^2)$
- Merge Sort. Complejidad $=O(n.log(n))$ en todos los casos.
- Quick Sort. Como la complejidad depende de la elección del pivot. $=O(n.log(n))$

# Ejercicio 2

Si la cantidad de elementos de $s''$ es menor a la cantidad de elementos de $s'$ utilizaría insertion sort para aprovechar que el invariante de ciclo de este algoritmo contempla que los elementos en el rango $(0, i)$ se encuentran ordenados.

En caso contrario utilizaría merge sort dado que los elementos desordenados del arrgelo son mayores a los ordenados, logrando una complejidad de peor caso $O(n.log(n))$

# Ejercicio 3

```python
def ej3(arr, k):
    i = 0
    res = []
    for n in k:
        pos_min = find_min(arr)
        arr.borrar(pos_min)
    return res

def find_min(arr):
    pos = 0
    for i in len(arr):
        if arr[i] < arr[pos_min]:
            pos_min = i
    return pos_min

def borrar(arr, pos):
    nuevo = []
    for i in len(arr):
        if i != pos_min:
            nuevo.append(arr[i])
    return nuevo
```

Complejidad $= O(k.n)$

Por lo tanto conviene ordenar el arreglo para $k > log_{2}n$

# Ejercicio 4

Para cada secuencia del conjunto, tendría un puntero a la primera posición, y en cada iteración, busco el menor de todos ellos, lo agrego a un arrglo resultado y muevo el puntero al siguiente valor de la secuencia.

En el peor de los casos tengo un algoritmo $O(n.m)$ con $n$ la cantidad de secuencias en el conjunto y $m$ la cantidad de elementos en cada secuencia del conjunto.

Si juntara todas las secuencias en una y luego ordenara el arreglo resultante, tendría una complejidad de $O(n.m + n.m.log(n.m))$ con $n.m$ la cantidad total del elementos.

# Ejercicio 5

```python
def ordenar_por_frecuencia(arr):
    arr = mergeSort(arr)
    freq = diccLineal()
    for i in range(1, n):
        if (def(arr[i], freq)):
            aux = obtener(arr[i], freq)
            definir(freq, arr[i], aux + 1)
        else:
            definir(freq, arr[i], 1)
    res = []
    while (len(claves(freq)) > 0):
        c = max(freq)
        for i in range(1, obtener(c, freq)):
            res.append(c, res)
        borrar(c, freq)
    return res
```

Con complejidad $O(n^2)$

Visto en clase 19/10/2022

# Ejercicio 6

```python
def ej6(arr):
    escaleras = []
    inicio = 0
    fin = 0
    i = 0
    while i < len(arr) - 1:
        if arr[i+1] = arr[i] + 1:
            i += 1
        else:
            fin = i
            tup = (inicio, fin, longitud:fin-inicio+1, primero:arr[inicio])
            escaleras.append(tup)
            i += 1
            inicio = i
    insertionSort(escaleras, by=primero) # Ordenamiento estable
    insertionSort(escaleras, by=longitud) # Ordenamiento estable
    res = []
    for e in escaleras:
        i = e.inicio
        while i <= e.fin:
            res.append(arr[i])
            i += 1
    return res
```

Complejidad $=O(n^2)$

# Ejercicio 7

Se que todo los nodos a la izquierda de la raíz son menores a esta y los que están a la derecha son mayores a este.

Usando recursion

```python
def avl_sort(avl):
    if nil(avl):
        return []
    else:
        arbol_izq = avl_sort(izq(avl))
        arbol_der = avl_sort(der(avl))
        return arbol_izq + raiz(avl) + arbol_der
```

Puede funcionar así, pero no se calcular la complejidad de la recursión.

# Ejercicio 8

Se me ocurre buscar el máximo de $A$ en $O(n)$.

Luego armar un array $R$ de recuento de repeticiones en $O(n)$

$C'$ Al arreglo $B$ agregarle una sola repetición de cada index de $R$ en $O(n') \subseteq O(n)$

Ordenar el arreglo $C'$ usando merge Sort en $O((n' + m).log(n' + m))$

Hasta acá tengo un arrglo de $n' + m$ elementos, me falta agregar las repeticiones de los elementos de $A$ pero no se como hacerlo.

# Ejercicio 9

## Pregunta 1

```python
def ordenar_alumnos(arr):
    res = []
    arr = alumnos_ordenados_por_nota(arr)
    for x in arr:
        if x.genero == "fem":
            res.append(x)
    for x in arr:
        if x.genero == "masc":
            res.append(x)
    return res

def alumnos_ordenados_por_nota(arr):
    res = []
    for i in range(1, 11):
        for alumno in arr:
            if alumno.nota == i:
                res.append(alumno)
    return res
```

Complejidad $O(n)$

Visto en clase 19/10/2022

## Pregunta 2

```python
def ordenar_alumnos(arr):
    res = []
    arr = alumnos_ordenados_por_nota(arr)
    for g in GEN:
        for x in arr:
            if x.genero == g:
                res.append(x)
    return res
```

Complejidad $O(g.n)$ con $g$ cantidad de géneros y $n$ cantidad de alumnos.

## Pregunta 3

No lo contradice ya que el "lower bound" aplica a algoritmos que necesariamente ordenan los elementos del arreglo realizando comparaciones de entre todos los elementos del mismo.

Sin embargo en este caso, solo realizamos comparaciones entre un conjunto acotado de posibles valores que puede tomar un atributo del elemento a ordenar, y el elemento a ordenar.

# Ejercicio 10

## Pregunta 1

Usando el casi_sort armo las partes ordenadas, luego las junto todas y vuelvo a ordenar el arreglo.

```python
def sort_usando_casi(arr):
    partes = []
    while len(arr) != 1:
        n = len(arr)
        casi_sorteado = casi_sort(arr)
        ordenados = casi_sorteados[0:n/2]
        desordenados = casi_sorteados[n/2 + 1:]
        partes.append(ordenados)
        arr = desordenados
    res = []
    for parte in partes:
        res += parte
    mergeSort(res)
    return res
```

## Pregunta 2

Complejidad $O(n.log(n))$

## Pregunta 3

No se

# Ejercicio 11

```python

def counting_sort(arr, k):
    counts = [0] * k
    res = [0] * len(arr)
    for x in arr:
        counts[x] += 1
    for i in range(1, len(counts)):
        counts[x] += counts[x-1]
    for j in range(0, len(arr), -1):
        res[counts[arr[j]]] = arr[j]
        counts[arr[j]] -= 1
    return res
```

Complejidad $O(n)$

# Ejercicio 12

Armo un arreglo con los elementos entre 20 y 40. $O(n)$

Armo un arreglo de menores que 20 y otro de mayores de 40. $O(\sqrt{n})$

Ordeno los que están en el rango 20,40.

Ordeno los arreglo menores y mayores. $O(\sqrt{n} . log(\sqrt{n}))$

Concateno los tres arreglos. $O(n)$

```python
def ej12(arr):
    en_rango = []
    menores = []
    mayores = []
    for x in arr:
        if x < 20:
            menores.append(x)
        elif x > 40:
            mayores.append(x)
        else:
            en_rango.append(x)
    mergeSort(en_rango)
    mergeSort(menores)
    mergeSort(mayores)

    res = []
    for x in menores:
        res.append(x)
    for x in en_rango:
        res.append(x)
    for x in mayores:
        res.append(x)
```

Complejidad $O(n)$

# Ejercicio 13

## 13.1

```python
def ej13(arr):
    radix_sort(arr)
    merge_sort(arr)
```

Radix sort utiliza el método de ordenamiento estable `counting_sort` con complejidad $O(n+k)$

Complejidad `radix_sort` $O(l.(n+k))$ con $l$ longitud máxima de la palabra, $n$ cantidad de items en el array, $k$ cantidad de caracteres distintos que componen las palabras.

Complejidad `merge_sort` $O(n.log(n))$

Comlejidad `ej13` $O(ln + n.log(n))$

## 13.2

```python
def ej13_2(arr):
    radix_sort(arr)
    count_sort(arr)
```

Complejidad $O(ln + n) = O(ln)$

# Ejercicio 14

TODO

# Ejercicio 15

```python
def ej15(arr):
    maximo = arr[0]
    for x in arr:
        if x > maximo:
            maximo = x
    b = [0] * maximo
    for x in arr:
        b[x] += 1
    i = 0
    while i < len(b) and b[i] != 0:
        i += 1
    return i < len(b)
```

No se si cumple con la complejidad, me parece que esto es $O(max)$ con $max$ el elemento máximo del arreglo.
