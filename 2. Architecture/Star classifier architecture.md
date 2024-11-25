# Декомпозиция задач
### Задачи:
1. Обработать входные данные:
    - Обработать (декодировать) параметры запуска.
    - Обработать изображение:
        - Загрузить его из файла.
        - Декодировать его.
1. Выделить все звёзды на изображении:
    - Как вообще это делать?
1. Сохранить обработанное изображение в файл:
    - Закодировать изображение.
    - Сохранить закодированное изображение в файл.
1. Сохранить информацию о звёздах в файл:
    - Закодировать её в строку нужного формата.
    - Сохранить строку в файл.
1. Вернуть результат вызывающей стороне:
    - Так как результат составной, удобнее будет сделать доступ к разным частям результата через отдельные поля/методы класса.
    - Можно для каждой части результата создать свой класс, имеющий необходимые функции преобразования к другому типу.


Используем подход MVC (Model-View-Controller).

### Пространства имен:
1. Model (StarClassifier)
1. View
1. Controller
1. OS (operation system)
1. Errors
1. Config (если доживём)

#### Пример использования:

View: эй, контроллер, пользователь хочет сохранить результат в файл!

Контроллер: эй, Model, выдай мне результат в виде std::string, разбитого на строки в нужном формате! //// Эй, Model, выдай мне результат в виде int** array, а я его конвертирую в строку.
Предпочтительнее второй вариант???

Контроллер: эй, OS, вот тебе строка, запихай ее в файлик пж!



!!!\ !!!ДОЛЖНО БЫТЬ ЛЕГКО РЕАЛИЗУЕМО БЕЗ ИЗМЕНЕНИЙ СУЩЕСТВУЮЩЕГО КОДА!!!:
ДОБАВИТЬ НОВЫЙ ВИД ОБВОДКИ!
ДОБАВИТЬ НОВОЕ ПРЕДСТАВЛЕНИЕ (ФОРМАТ ВЫВОДА) - СКАЖЕМ, WEB ДОКУМЕНТ, TCP ПОТОК, etc.

TODO (и сверху, и снизу)

От 2 до 7 модулей на каждом иерархическом уровне

### Интерфейсы:
1. В пространстве имён Model:
    - StarClassifier (ну какой-то должен быть? А вдруг мы захотим другой класс, скажем, без свёрток???) TODO
1. В пространстве имён View:
    - ConsoleApplication
    - StaticLibraryApplication
    - GraphicApplication
    - CommandLineApplication
1. В пространстве имён Controller:
    - Controller (а как иначе?) TODO
1. В пространстве имён OS:
    - FileSystem
    - Console ??? TODO
    - CommandLine ??? TODO
1. В пространстве имён Errors:
    - По идее, тут интерфейсы не нужны, достаточно просто иерархии классов Errors


### Классы
1. В пространстве имён Model:
    - StarClassifier (основной)
    - Image (скорее всего, он будет классом) - TODO
    - Stars (возможно, это класс) - TODO
1. В пространстве имён View:
    - ConsoleApplication
    - StaticLibraryApplication
    - GraphicApplication
    - CommandLineApplication
1. В пространстве имён Controller:
    - Controller (основной)
1. В пространстве имён OS:
    - WindowsFileSystem
    - Console ??? TODO
    - CommandLine ??? TODO
1. В пространстве имён Errors:
    - BaseError
    - Дописываем сюда классы ошибок по мере появления новых ошибок, чё)))

### Структуры данных
1. Pixel
1. Image - это может быть классом
1. Star
1. Stars - это может быть классом