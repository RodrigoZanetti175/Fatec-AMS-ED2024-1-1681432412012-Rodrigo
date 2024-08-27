
# ATIVIDADE B3-2

## Códigos fornecidos

### Busca Linear
```
i = 1 // t
while(i<=n){ // tn
    if(A[i]==x) // 2tn
        return i // t
    i=i+1 // 2tn
}
return -1 // t
```

### Busca Linear em Ordem

```
 i = 1 // t
 while(i<=n && x>=A[i]){ // 4tn
    if(A[i]==x) // 2tn
        return i // t
    i=i+1 // 2tn
 }
 return -1 // t
```

### Busca Binária
```
esq = 1 // t
dir = n // t
while(esq<=dir){ // tn
    meio=floor((esq+dir)/2) // Assumindo floor() como 1t -> 4tn
    if(A[meio]==x) // 2tn
        return meio // t
    else if(x>A[meio]) // 2tn
        esq=meio+1 // 2tn
    else
        dir=meio-1 // 2tn
}
return -1 // t
```

## Tabela de complexidade de tempo

|  | Busca Linear | Busca Linear em Ordem | Busca Binária |
|----------|:----------:|:----------:|:----------:|
| x ∈ A |   t + tpx + 2t(px-1)  |   2t + 6tpx + 2t(px-1)  |   3t + 7tpx + 4t(px-1)  |
| x = A[1] |   5t  |   8t  |   10t  |
|   x = A[n]  |  2t + 3tn + 2t(n-1)  |   2t + 6tn + 2t(n-1)  |   11t(n-1) + 10t  |
|   x ∉ A  |   6tn + 2t   |   12tn + 2t   |   12tn + 3t  |

**OBS:** *Assumi que A[1] significa o melhor caso de cada busca e não necessariamente o primeiro índice*