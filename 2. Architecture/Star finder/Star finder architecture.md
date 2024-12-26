# Декомпозиция задач
### Задачи:
1. Обработать входные данные:
    - Обработать (декодировать) параметры запуска.
    - Обработать изображение:
        - Загрузить его из файла.
        - Декодировать его.
1. Выделить все звёзды на изображении:
    - Способ 1:
        - Применить цветовой фильтр (Какой? Скорее всего, серый), преобразовать контрастность (Это лучше сделать до или после цветового фильтра?).
        - Применить медианный фильтр (если надо).
        - Применить фильтр Гаусса.
        - Применить фильтр Собеля.
        - Если надо, построить компоненты связности (система непересекающихся множеств).
        - Распознать, в каких местах изображения остались яркие маленькие кружочки.
    - Способ 2:
        - Применить цветовой фильтр (Какой? Скорее всего, серый. А может быть, вообще никакой), преобразовать контрастность (это лучше сделать до или после цветового фильтра? Или вообще не делать, если мы не применяем цветовой фильтр?).
        - Применить фильтр Гаусса.
        - Выделить компоненты связности (это можно делать и на цветной картинке).
        - Распознать, какие компоненты связности отвечают за звёзды.
1. Получить информацию о звёздах (из обработанного изображения или компонент связности).
1. Получить результирующее изображение, используя информацию о звёздах (или наоборот).
1. Сохранить обработанное изображение в файл:
    - Закодировать изображение.
    - Сохранить закодированное изображение в файл.
1. Сохранить информацию о звёздах в файл:
    - Закодировать её в строку нужного формата.
    - Сохранить строку в файл.
1. Вернуть результат вызывающей стороне:
    - Так как результат составной, удобнее будет сделать доступ к разным частям результата через отдельные поля/методы класса.
    - Можно для каждой части результата создать свой класс, имеющий необходимые функции преобразования к другому типу.

# Архитектура системы
**Используем подход MVP (Model-View-Presenter).**

MVP: https://habr.com/ru/articles/343438/

### Пространства имён:
1. model
    - base
1. view
1. presenter
1. operation_system
1. errors
1. filters
1. data_structures
1. config
1. iterators

### Интерфейсы:
1. В пространстве имён model:
    - Pixel
        - Поля:
            - red
            - green
            - blue
            - alpha
    - Image
        - Поля:
            - size_t size
        - Функции:
            - outline_star(Coordinates center)
            - operator[size_t][size_t] (TODO - если получится красиво реализовать)
            - operator[Coordinates]
            - begin (const and non-const)
            - end (const and non-const)
    - ImageIterator
        - Функции:
            - T& operator*
            - ImageIterator& operator++
            - bool operator!=
            - get_coordinates
    - Star
        - Поля:
            - coordinates
            - radius
    - Stars
        - Поля:
            - size
        - Функции:
            - operator[size_t]
            - begin (const and non-const)
            - end (const and non-const)
    - StarsIterator
        - Функции:
            - T& operator*
            - StarsIterator& operator++
            - bool operator!=
            - get_index
    - Params:
        - Поля:
            - source_image
        - Функции:
            - new_image (наследники создают конкретный image, который будет возвращён из StarFinder'а)
            - new_stars (наследники определяют, экземпляры какого класса Stars создать)
    - StarFinder
        - Функции:
            - find_stars
            - get_image
            - get_stars
1. В пространстве имён view:
    - Application
        - Функции:
            - run
1. В пространстве имён operation_system:
    - FileSystem
        - Функции:
            - load_image(path)
            - save_image(image, path)
            - load_text(path)
            - save_text(text: string, path)
    - Console
        - Функции:
            - write
            - write_line
            - read_char
            - read_number(format)
            - read_line
    - CommandLine
        - TODO
1. В пространстве имён config:
    - Config
        - Функции:
            - load
            - save
1. В пространстве имён iterators:
    - Iterator<T>
        - Функции:
            - operator*
            - operator++
            - operator++(int)
            - operator==
            - operator!=
            - copy

### Классы
1. В пространстве имён model::base:
    - BaseImageIterator
    - BaseImage
    - BaseStarsIterator
    - BaseStars
    - BaseStarFinder
1. В пространстве имён view:
    - ConsoleApplication
    - GraphicApplication
    - CommandLineApplication
1. В пространстве имён presenter:
    - ConsolePresenter
    - GraphicPresenter
    - CommandLinePresenter
1. В пространстве имён operation_system:
    - WindowsFileSystem
    - WindowsConsole (TODO)
    - CommandLine (TODO)
1. В пространстве имён errors:
    - BaseError
        - FileError
            - FileLoadError
            - FileReadError
            - FileSaveError
1. В пространстве имён iterators:
    - IteratorWrapper<T>

### Структуры данных
1. В пространстве имён model::base:
    - BasePixel
    - BaseStar
    - BaseParams
1. В пространстве имён data_structures:
    - DisjointUnionSet

### Функции
1. В пространстве имён filters:
    - gray_color_filter (TODO - если понадобится; если понадобится несколько - можно их объединить в класс/в иерархию классов)
    - contrast_filter (TODO - если понадобится)
    - median_filter
    - gaussian_filter
    - sobel_filter

# Примерная реализация
```cpp
int main(argc, argv) {
    Application* application = new ConcreteApplication(); // Console, cmd, library, graphic...
    application.run();
    return 0;
}
```

# Аргументация принятых решений
Было принято решение реализовать публичные функции get_x(), get_y(), get_index() у итераторов, так как они, скорее всего, всё равно будут хранить соответствующие поля для итерации, и эти функции - просто инлайны. А с точки зрения оптимизации гораздо выгоднее написать один цикл через итератор, и поля брать у итератора, чем цикл с переменными i,j. С таким интерфейсом можно, при необходимости, реализовать отдельно итераторы по строке/столбцу/любого другого доступа и не запутаться, на что указывает итератор.

# Возможные приёмы конструирования
Скорее всего, в одном и том же пространстве имён будут разные классы под разные задачи, каждый класс в своём файле, т.е. общий .h, много .cpp, один интерфейс, много реализаций.

TODO
Если сделать максимально абстрактный интерфейс, то контроллеру придется вызывать cast для преобразования абстрактного StarFinder (у которого считай один конструктор в интерфейсе, и возможно функии get_image()) в конкретный, который выдаст набор звёзд, отсортированных по яркости (если будем создавать наследника интерфейса, который их отсортирует); в самом StarFinder придется вызывать cast, чтобы прочитать необходимые ему поля (а это еще и в конструкторе, а если нам подсунули некорректные данные - то throw из конструктора делать) и т.д.

Чтобы не throw из конструктора, можно сделать функцию init(). В конструкторе все поля в nullptr, в init - задавать им значения или throw error.
Хотя, концепция кинуть ошибку из конструктора вроде лучше.

https://stackoverflow.com/questions/810839/throwing-exceptions-from-constructors

Когда кидаем ошибку из конструктора, деструктор не вызывается (очевидно):

https://stackoverflow.com/questions/810839/throwing-exceptions-from-constructors#:~:text=the%20destructors%20are%20not%20called%2C%20so%20if%20a%20exception%20need%20to%20be%20thrown%20in%20a%20constructor%2C%20a%20lot%20of%20stuff(e.g.%20clean%20up%3F)%20to%20do.
