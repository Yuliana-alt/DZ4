# 15. Удалить вершины, которые смежны с заданным ребром, и отсортировать оставшиеся по убыванию степени вершины (сортировка вставками)
## Алгоритм:
- Удаление вершин, смежных с заданным ребром
```c
 for (int i = 0; i < n; i++) {
            a[b][i] = 0;
            a[c][i] = 0;
            a[i][b] = 0;
            a[i][c] = 0;
        }
```        
- Подсчет количеств степеней и запись во вспомогательный массив
```c
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {
                    if (i == j) {
                        a1[j] = a1[j] + 2;
                    }
                    else {
                    a1[j]++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            a2[i] = a1[i];
```
- Сортировка вставками
```c
       for (int i = 0; i < n; i++) {
            x = a1[i];
            j = i;
            while ((j > 0) && (a1[j - 1] < x)) {
                a1[j] = a1[j - 1];
                j = j - 1;
            }
            a1[j] = x;
```
- вывод отсортированного массива
```c
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (a1[j] == a2[i]) {
                    printf("%d ", i + 1);
                    a2[i] = -1;
                }
            }
        }
```
## Структурная схема алгоритма:
![alt-текст](https://github.com/Yuliana-alt/DZ4/blob/main/schema.png)
## Результат работы:
![alt-текст](https://github.com/Yuliana-alt/DZ4/blob/main/term.png)
## Отображение графа:
![alt-текст](https://github.com/Yuliana-alt/DZ4/blob/main/test.png)
