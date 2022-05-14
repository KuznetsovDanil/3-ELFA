Проект по Математическому Анализу 2й семестр

Руководитель:

Семёнкина Мария Евгеньевна

Участники проекта:

Коренев Матвей Сергеевич
Шейников Дмитрий Александрович
Рыгузин Владислав Игоревич

### Adding a student: `student -a`
<details><summary>Adds a student to the students list.</summary>

Format: `student -a -n NAME [-c CONTACT] [-em EMAIL] [-s DAY/STARTTIME/ENDTIME]?`

* Adds a student with the specified `NAME`
* `-a` refers to the add command
* Commands in `[ ]` are optional
* `DAY` takes in the following inputs: `MON TUE WED THU FRI SAT SUN` while `STARTTIME` and `ENDTIME` takes in the time in 24 hour format, for example 0800 for 8am.


Examples:
* `student -a -n John -c 12345678 -em john@mail.com -s TUE/1600/1800`<br>
  adds a student with the name John, contact number 12345678, email john@mail.com and a lesson every tuesday from 4pm to 6pm
* `student -a -n Barbara -c 12344321`<br>
  adds a student with the name Barbara and contact number 12344321

</details>