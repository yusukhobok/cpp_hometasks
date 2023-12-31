ДЗ-05. Editor.

Цель:
В это самостоятельной работе применяем полученные знания про шаблоны, реализуем функционал вывода IP-адреса в общем виде, подключаем к своему проекту doxygen и генерируем документацию.


Описание/Пошаговая инструкция выполнения домашнего задания:
1. Выполнить задание описанное в 05.homework.pdf
2. На acm.timus.ru решить любые 3 задачи с уровнем сложности от 100 до 150.
Отсортированный по сложности список:
http://acm.timus.ru/problemset.aspx?space=1&page=all&skipac=False&sort=difficulty
Если выбрать сложно, есть ещё списки задач по темам (ближе к концу страницы):
http://acm.timus.ru/problemset.aspx
3. Выложить на ревью свои решения ДЗ-02, ДЗ-03 и ДЗ-04.
4. Сделать ревью решений ДЗ-02 двух коллег (которые его выполнили).
5. Отправить на проверку в "Чат с преподавателем":
   - ссылку на свой репозиторий на guthub.com с реализованным проектом и настроенным workflow для github actions с историей успешных сборок;
   - ссылку на аккаунт на acm.timus.ru со списком принятых задач
   - ссылки на выполненные ревью


# Основное задание
Спроектировать простейший графический векторный редактор. Подготовить макеты классов,
отражающих структуру будущего проекта.
Функционал для макетирования следующий:
- создание нового документа
- импорт документа из файла
- экспорт документа в файл
- создание графического примитива
- удаление графического примитива
  Основной упор сделать на шаблон контроллера (MVC) и полиморфизм. Функции, являющиеся
  обработчиками GUI, собрать в одном файле с функцией `main`.
  Внимание должно быть сосредоточено на декларациях, реализация только в крайнем случае для
  минимальной демонстрации необходимых вызовов. Проект должен компилироваться, все
  заголовки должны пройти стадию компиляции.
  Задание считается выполненным успешно, если все файлы прошли стадию компиляции, все классы
  охвачены диаграммами, код успешно прошел анализ.
## Дополнительные рекомендации
1. Заложить в интерфейсы использование умных указателей, тем самым решив вопрос
   владения объектами.
2. Помнить про принцип единственности ответственности, разделить код на логические
   модули (классы, функции).
3. Избегать дублирования кода.