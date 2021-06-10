# Slicer

### Пролог

Данная программа - мой первый опыт в создании _Окнного приложения_, в рамках курсовой работы, как студента 1-го курса Программной инженерии.

Потому, данная программа _НЕ ДОЛЖНА_ служить пример по написанию таких приложений.

Приложение написано на C++, используя Qt6 в интегрированной среде QtCreator.

### Цели программы

**"Slicer"** - программа, прелседующая _обучающие_ цели, с такими функциями как:
- Выдавать пользователю лекцию, которую он загружает через интерфейс программы (*.txt, *.slc файлы). 
- Выдавать пользователю тест на основе лекции, который также загружается через интерфейс программы.
- Показывать визуализацию умножения матриц методом Штрассена и Винограда.
- Сохранений результатов теста.

### Гайд по пользованию

## 1. Установить *инсталятор* и скачать программу 

![screenshot](https://github.com/dacsson/Slicer/blob/main/backg.jpg)

## 2.Первый шаг - назажть на кнопку _Настройки_ и загрузить свой "{}.slc" ( или {}.txt ) со структурой, которая будет описана ниже. 
Продолжать работу можно только с .slc файлом (.slc - зашифрованный файл с определённым синатксисом; его можно создать в редакторе программы, также можно загрузить .txt файл, перейти в редактор где будет представленно содержимое .txt файла, чтобы его можно было сохранить как .slc файл)

![screenshot](https://github.com/dacsson/Slicer/blob/main/settings.png)

![screenshot](https://github.com/dacsson/Slicer/blob/main/editor.png)



Можно вписать личный индентификатор (Вариант, Фамилию), который будет записан в файле с результатами тестирования. Затем кликнуть "Применить".

# Синтаксис документа

Загружаемый документ содержит как _лекцию_, так и _тест_ и придерживается следующего синтаксиса:

- В начало документа необходимо написать «|0|», затем с новой строки пишется первая страница теоретического материала.
- Далее в конец каждой страницы с новой строчки пишется: "|{номер страницы}|" ; пример: "|4|" – четвёртая страница.
- Номера страниц идут по порядку без повторений.
- После ввода номера последней страницы :"|{номер последней страницы}|" с новой строки вводятся правильные ответы на вопросы тестовой части: "[0]:{верный ответ на 1 вопрос}{ верный ответ на 2 вопрос }…"; пример: "[0]:1435" - 4 верных ответа на 4 вопроса.
- Затем с новой строки идут вопросы тестовой части и варианты ответа. Начало вопроса отмечается: "?{номер вопроса}?"; пример: "?2?" – начало второго вопроса;
- Затем с новой строки следует содержание самого вопроса.
- Затем с новой строки идут варианты ответа в одну строку: "!1{первый вариант}!2{второй вариант}!3{третий вариант}...!5"; пример: "!1Me!2Nobody!3Richard Stallman!4Based, not cringe!5".
- Варианты ответы всегда должны кончаться отметкой: "!5".
- Конец вопроса отмечается: ".{номер вопроса}."; пример: ".7." – конец 7 вопроса.
- После данной метки не рекомендуется вставлять любые другие символы.

![screenshot](https://github.com/dacsson/Slicer/blob/main/help.png)

В окне настроек есть кнопка, вызывающая сводку о синтаксисе.

## 3. Окно вывода лекции

Необходимо нажать кнопку "Старт" сверху документа, чтобы инициализировать считывание документа.

![screenshot](https://github.com/dacsson/Slicer/blob/main/start.jpg)

Навигация в лекционном материале происходит посредством стрелочек внизу экрана

Положение пользователя в документе показывает линия прогресса в самом низу окна, когда она подойдёт к 100%, нажав на стрелочку вправо начнётся визуализация.

## 4. Процесс визуализации

Во время визуализации программа будет выводить сообщения в соответствующем окне сверху. 
Изначально потребуется ввести 2 матрицы, программа покажет процессы, которые произойдут с ними и промежуточные вычисления (для метода Штрассена и Винограда).

![screenshot](https://github.com/dacsson/Slicer/blob/main/visual1.png)

![screenshot](https://github.com/dacsson/Slicer/blob/main/visual2.png)

![screenshot](https://github.com/dacsson/Slicer/blob/main/visual3.png)

![screenshot](https://github.com/dacsson/Slicer/blob/main/visual4.png)

Визуализация разбита на шаги, для перехода от одного к следующему следует нажать "Далее".

По окончанию визуализации (вывода результата-матрицы по методу Винограда) программа вернётся в главный экран и линия прогресса сдвинется к тесту.

## 4. Тестирование

Во время тестирования выводятся вопросы из загруженного документа и 4 варианта ответа к каждому. Верный только один, при его выборе засчитывается 1 балл, иначе 0 баллов по данному вопросу.

![screenshot](https://github.com/dacsson/Slicer/blob/main/question.png)

Прогресс пользователя, кто бы мог подумать, показывает линия прогресса в самом низу окна.
На последнем вопросе появится кнопка "Применить", по нажатию который откроется окно Результатов.

## 5. Реузльтаты

На экран выводятся: номер вопроса, ответ пользователя и верный ответ на вопрос, если пользователь ответил неверно.

![screenshot](https://github.com/dacsson/Slicer/blob/main/results.png)

Также, можно сохранить результат, либо выйти из программы.

При выходе на главном меню появится кнопка "Обновить", позволяющая повторить процесс работы с программой.

### Epilogue

Каждая иконка, изображение были выполнены мной в графическом редакторе GIMP.

В файлах прикреплён экземпляр входного документа (в расширении .slc).

P.S. В результате защиты данного курсового проекта я получил не только крутой *опыт*, но и оценку *отлично* :).


