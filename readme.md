# Урок 9, Работа с сетью. UDP клиент

Инструкция к заданию

- Скачать проект с прекодом.
- Добавить в CMakeList.txt модуль для работы с сетью.
- Добавить на главную форму виджет для ввода текста и кнопку "Отправить Датаграмму"
- Изменить существующие или добавить новые методы, необходимые для выполнения задания.

## Задание 1

Доработать представленное приложение, чтобы появился функционал отправки и приема пользовательских датаграмм.

1. В текущее приложение добавить:
- виджет для ввода текста;
- кнопку "Отправить датаграмму".
2. При нажатии на кнопку "Отправить датаграмму" приложение должно отправить введенный пользователем текст при помощи объекта класса QUdpSocket на адрес 127.0.0.1 (localhost)
3. Приложение должно принять эту датаграмму и отобразить в виджете "Принятые данные" сообщение вида: "Принято сооьбщение от адрес отправителя, размер сообщения(байт) Х
- Х - размер введенного в виджет текста
- Адрес отправителя - адрес с которого была осуществлена отправка датаграммы

CPP-07
08.10.2023
[@J1n4ed](https://github.com/J1n4ed)
