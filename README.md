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

## 2.The First step is to click _Settings_ icon and upload your "{}.txt" ( or {}.slc )file with lecture and test questions with the syntax i'll explain below 
## 2.Первый шаг - назажть на кнопку _Настройки_ и загрузить свой "{}.slc" ( или {}.txt ) со структурой, которая будет описана ниже. 
Продолжать работу можно только с .slc файлом (.slc - зашифрованный файл с определённым синатксисом; его можно создать в редакторе программы, также можно загрузить .txt файл, перейти в редактор где будет представленно содержимое .txt файла, чтобы его можно было сохранить как .slc файл)

![screenshot](https://github.com/dacsson/Slicer/blob/main/settings.jpg)

Можно вписать личный индентификатор (Вариант, Фамилию), который будет записан в файле с результатами тестирования. Затем кликнуть "Применить".

# Синтаксис документа

Загружаемый документ содержит как _лекцию_, так и _тест_ и придерживается следующего синтаксиса:

- pages marked by: "|{number of the page}|" (the beggining of the document should have |0| **before** lecture); for example: "|4|" - fourth page
- after the "|{number of the last page}|" and _enter_ should go anwsers to test questions: "[0]:{first question answer}{second question answer}"; for example: "[0]:1435" - 4 answers for 4 questions
- every question have 5 var. of answers 
- question beginning marked by: "?{number of question}?"; for example: "?2?" - second question
- after that and _enter_ comes the actual question (problem) 
- variants of answers marked by: "!1{first variant}!2{second variant}!3{third variant}...!5"; for example: !1Me!2Nobody!3Richard Stallman!4Based, not cringe!5
- variants of answers should **always** end with: "!5"
- question end marked by: ".{number of question}."; for example: ".7." - end of the 7th question
- do *not* put anything (event _enters_ or _spaces_) after the end of the last question (or between any _blocks_ such as lecture, right answers, questions)

## 3. Settings window will close and progress bar will move to _start_ button, which you should press to start reading lecture

You should press button at the top of that window to initiate showing of document.

![screenshot](https://github.com/dacsson/Slicer/blob/main/start.jpg)

User _right_ and _left_ arrows to move around the document.

Progress bar at the very bottom of the app will show you're progress. When it'll be at 100% you can press right arrow to complete that step.

## 4. Lecture window will close and progress bar will move to _test_ button, which you should press to start test 

You should choose one of the variants **every** question, even if the button is already look pressed.

![screenshot](https://github.com/dacsson/Slicer/blob/main/question.jpg)

Progress bar at the very bottom of the app will show you're progress.

## 5. Window with questions will close and the _results_ of the test will apear, you can press _save_ button to save you're results in "{}.txt" file 

![screenshot](https://github.com/dacsson/Slicer/blob/main/results.jpg)

Either way you can just close that window with button in the upper right corner (you can do it with every step)

## 6. Now you'll be back at the main menu and _reload_ button will apear so you can do all process again! 

![screenshot](https://github.com/dacsson/Slicer/blob/main/reboot.jpg)

### Epilogue

Every image in /resources is my own image made in Photoshop :).

There is document /resources/text.txt which is an example document.

Thank you for reading this introduction, hope you found that interesting enough and will check out the code/program itself!

Feel free to contact me if you will find any bugs.


