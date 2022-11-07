# CMake-шаблон

Шаблон для разработки и тестирования программ на С++

* Build system: cmake (https://ps-group.github.io/cxx/cmake_cheatsheet)
* Tests: gtest
* Code style check: cpplint

## Сборка проекта

Вызвать командную строку из созданной папки **build**, выполнить команду

```cmake -G "Visual Studio 17 2022" ..```

```cmake -G "Visual Studio 16 2019" ..```

```cmake -G "Visual Studio 15 2017" ..```

для сброки проекта под вашу версию Visual Studio.

## Основные команды для GitHub и git

```git clone ссылка-до-ВАШЕГО-репозитория```

```git branch имя-рабочей-ветки```

```git checkout имя-рабочей-ветки```

```git add .```

```git add -u .```

```git status```

```git commit –m "fix problem with magic numbers, add comments"```

```git push origin имя-рабочей-ветки```
или
```git push –u origin имя-рабочей-ветки```

**Замечание.** Если сделать git push ветки без ключа -u, git не свяжет локальную ветку с веткой удалённого репозитория. Смысл использовать ключ -u есть только при пуше новых веток, для существующих (связанных с удалёнными) веток каждый раз перезаписывать связку необязательно.

## Ссылки на материалы по исключениям

**Исключение**  - это ситуация, которая не предусмотрена стандартным поведением программы.

Полезная статья с примерами - https://evileg.com/ru/post/289/

**Assert** — это специальная конструкция, позволяющая проверять предположения о значениях произвольных данных в произвольном месте программы.

Полезная статья с примерами - http://cppstudio.com/post/946/

* Документация по исключениям
https://en.cppreference.com/w/cpp/error/exception

* Документация по функции сообщения об ошибке
https://en.cppreference.com/w/cpp/error/assert

* Статья на подумать - "Выбор правильной стратегии обработки ошибок (части 1 и 2)"
https://habr.com/ru/company/vk/blog/322416/

## Краткие описания лабораторных работ

### Лабораторная работа МАТРИЦЫ

Для реализации работы подготовлен шаблон классов на C++, также подготовлен к реализации набор тестов.

Требования:

	* сделать FORK репозитория,
	* создать рабочую ветку,
	* реализовать классы Вектор и Матрица
	  (реализация методов должна быть вынесена из классов),
	* реализовать предложенный набор тестов,
	* написать демонстрационное приложение,
	* пофиксить оформление кода,
	* сделать pull request из рабочей ветки в master/main.

Дополнительные задания (можно выполнить при желании):

	* реализовать верхне / нижнетреугольные матрицы (использовать наследование),
	* написать оболочку (интерфейс) аналог реализованного класса, но на базе std::vector.
	
