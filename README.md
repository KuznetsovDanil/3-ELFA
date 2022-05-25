Для добавления в проект необходимо скопировать папку math, и подключить файл #include "math/function.h"

Описание файловой структуры библиотеки:
|Файл        |Описание                                                                                                    |
|:----------:|:-----------------------------------------------------------------------------------------------------------|
|function.h  |Главный заголовочный файл с классом Function                                                                |
|function.cpp|Описание методов, не относящихся к вычислению ДУ, также в нем содеражатся готовые ДУ для демонстрации работы|
|methods.cpp |Описание функций численных методов                                                                          |

Создание объекта:
```C++
Function Name(type, a, b, x0, u0);
```
|Название|Описание                                          |
|:------:|:-------------------------------------------------|
|type    |Тип ДУ                                            |
|a,b     |Промежуток построения Интеграла ДУ и аппроксимации|
|x0,u0   |Точка, через которую должен проходить Интеграл ДУ |

Доступные ДУ:
|type|y'           |
|:--:|:-----------:|
|0   |(-x^2-xy+y)/x|

Методы:
|Название                 |Описание                                                                                 |
|:-----------------------:|:----------------------------------------------------------------------------------------|
|answer_grafic(tay);      |Возвращает двойной указатель на массив точек Интеграла ДУ                                |
|diff_methods(method,tay);|Возвращает двойной указатель на массив точек Аппроксимации, вычисленной указанным методом|
|get_n();                 |Возвращает количество точек которые хранит объект в данный момент                        |
|get_c();                 |Возвращает константу Интеграла ДУ                                                        |
|clear_data();            |Очищает массив точек                                                                     |
|get_mass_dots();         |Возвращает указатель на массив точек                                                     |

*tay - шаг построения

Доступные численные методы:
|method|Название                      |
|:----:|:----------------------------:|
|0     |Метод Эйлера (метода ломанных)|

Особенности использования класса и доп. возможности:
1. Ограничения на входные данные:
b > a > 0
tay > 0
x0 > 0
(x0,u0) принадлежит Интегралу ДУ
2. Отрезок [a;b] и x0 не зависят друг от друга
3. Интеграл ДУ и Аппроксимацию можно считать с разным шагом
4. Получение доступа к массиву объекта:
