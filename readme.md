```markdown
# GraphoDro4

Консольное приложение для работы с графами на C++.

## Возможности

- Генерация графов 14 типов: полный, двудольный, дерево, звезда, цикл, путь, колесо, случайный, кубический, с заданным числом компонент связности, мостов, точек сочленения, 2-мостов, Халина.
- Загрузка из файлов в форматах: список рёбер, матрица смежности, DIMACS, SNAP.
- Вычисление метрик: плотность, диаметр, транзитивность, компоненты связности, точки сочленения, мосты, двудольность, верхняя оценка хроматического числа.
- Сохранение в форматах: GraphViz (.dot) и .edges (для programforyou.ru).

## Требования

- CMake 3.10 или выше
- Компилятор с поддержкой C++17 (GCC 7+, Clang 5+, MSVC 2017+)
- Git (для клонирования репозитория)

## Сборка и запуск

### 1. Клонирование репозитория

```bash
git clone https://github.com/daria0021/GraphoDro4.git
cd GraphoDro4
```

### 2. Сборка с помощью CMake

#### Windows (командная строка)

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

После сборки исполняемые файлы появятся в папке `build/Release` (или `build/Debug`, если указан Debug).

#### Linux / macOS

```bash
mkdir build
cd build
cmake ..
make
```

Исполняемые файлы появятся в папке `build`.

#### Альтернатива: использование CLion

- Откройте папку с проектом в CLion.
- Нажмите `File -> Reload CMake Project`.
- Выберите конфигурацию `GraphoDro4` и нажмите кнопку сборки (зелёный молоток).
- Запустите приложение, нажав кнопку `Run` (зелёный треугольник).

### 3. Запуск приложения

#### Windows

```bash
cd build\Release
GraphoDro4.exe
```

#### Linux / macOS

```bash
cd build
./GraphoDro4
```

После запуска откроется интерактивная консоль с приглашением `>`.

## Использование

### Команды

- **generate <тип> [параметры]** – сгенерировать граф
- **load <файл> <формат>** – загрузить граф
- **save <файл> <формат>** – сохранить граф
- **metric <имя>** – вычислить метрику
- **help** – справка
- **quit** – выход

### Типы генерации

| Тип | Параметры | Пример |
|-----|-----------|--------|
| complete | n | `generate complete 5` |
| complete_bipartite | n m | `generate complete_bipartite 3 4` |
| tree | n | `generate tree 10` |
| star | n | `generate star 8` |
| cycle | n | `generate cycle 6` |
| path | n | `generate path 7` |
| wheel | n | `generate wheel 6` |
| random | n p% | `generate random 20 30` |
| cubic | n (чётное ≥4) | `generate cubic 6` |
| components | n comp | `generate components 10 2` |
| bridges | n bridges | `generate bridges 10 3` |
| articulation | n ap | `generate articulation 10 2` |
| two_bridges | n twoBridges | `generate two_bridges 12 2` |
| halin | n | `generate halin 4` |

### Форматы загрузки

- `edgelist` – список рёбер (каждая строка `u v`)
- `adjmatrix` – матрица смежности (целые числа через пробел)
- `dimacs` – формат DIMACS (файлы раскраски)
- `snap` – формат SNAP (два числа на строку)

### Форматы сохранения

- `dot` – для Graphviz (визуализация)
- `edges` – для programforyou.ru (нумерация вершин с 1)

### Доступные метрики

- `density` – плотность
- `diameter` – диаметр
- `transitivity` – транзитивность (отношение треугольников к триадам)
- `components` – количество компонент связности
- `articulation` – количество точек сочленения
- `bridges` – количество мостов
- `bipartite` – проверка на двудольность
- `chromatic` – верхняя оценка хроматического числа (жадная раскраска)

## Примеры сессий

### Создать полный граф K5 и вычислить плотность

```
> generate complete 5
Graph generated: complete
> metric density
Density: 1
> metric diameter
Diameter: 1
```

### Сохранить граф в формате dot и открыть в GraphvizOnline

```
> generate random 20 15
Graph generated: random
> save graph.dot dot
Graph saved to graph.dot
```
Загрузите файл `graph.dot` на сайт [GraphvizOnline](https://dreampuf.github.io/GraphvizOnline/) для визуализации.

### Сохранить граф для programforyou.ru

```
> save graph.edges edges
Graph saved to graph.edges
```
Полученный файл можно открыть на [programforyou.ru/graph-redactor](https://programforyou.ru/graph-redactor).

## Тестирование

После сборки выполните:

```bash
./tests        # Linux/macOS
tests.exe      # Windows
```

Тесты проверяют базовую функциональность графа, метрик и генераторов.


```
