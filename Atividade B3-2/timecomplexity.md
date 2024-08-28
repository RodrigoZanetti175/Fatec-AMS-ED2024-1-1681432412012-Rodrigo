
# ATIVIDADE B3-2

## Códigos fornecidos

### Busca Linear
```c
i = 1; // t
while(i<=n){ // tn
    if(A[i]==x) // 2tn
        return i; // t
    i=i+1; // 2tn
}
return -1; // t
```

### Busca Linear em Ordem

```c
 i = 1; // t
 while(i<=n && x>=A[i]){ // 4tn
    if(A[i]==x) // 2tn
        return i; // t
    i=i+1; // 2tn
 }
 return -1; // t
```

### Busca Binária
```c
esq = 1; // t
dir = n; // t
while(esq<=dir){ // t(log n)
    meio=floor((esq+dir)/2); // Assumindo floor() como 1t -> 4t(log n)
    if(A[meio]==x) // 2t(log n)
        retur(log n) meio; // t
    else if(x>A[meio]) // 2t(log n)
        esq=meio+1; // 2t(log n)
    else
        dir=meio-1; // 2t(log n)
}
return -1; // t
```

## Tabela de complexidade de tempo

|  | Busca Linear | Busca Linear em Ordem | Busca Binária |
|----------|:----------:|:----------:|:----------:|
| x ∈ A |   t + tpx + 2t(px-1)  |   2t + 6tpx + 2t(px-1)  |   3t + 7t(log px) + 4t(log(px-1))  |
| x = A[1] |   5t  |   8t  |   7t(log n) + 4t(log (n-1)) + 3t  |
|   x = A[n]  |  2t + 3tn + 2t(n-1)  |   2t + 6tn + 2t(n-1)  |   7t(log n) + 4t(log (n-1)) + 3t  |
|   x ∉ A  |   6tn + 2t   |   12tn + 2t   |   12t(log n) + 3t  |


**OBS:** *Os casos de x=A[1] e x=A[n] na busca binária se tratam do mesmo caso, já que ambos precisam percorrer até a extremidade do array, assim, a única diferença se trata da direção que eles precisam percorrer*
