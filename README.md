# Task-2
Моя ідея полягала в тому, щоб створити загальний абстрактний батьківський клас Фігура і похідні йому абстрактні ПлоскіФігура і ПросторовіФігура (Хоча це не обов'язково, але логічно, бо і Плоскі і Просторові є фігурами). Реалізація класу плоскіФігури описана у попередньому завданні. А от над реалізацією Просторових я довго ламав голову. Спершу я думав зробити множинне спадкування (Н-д, щоб клас трикутна піраміда успадковував свій абстрактний і клас трикутник, для того щоб мати змогу виводити основу у консоль. Але це нісенітниця, бо не можна сказати що Трикутна Піраміда є Трикутником). Я став шукати інші методи отримати доступ в класі до іншого класу. І такий метод знайшовся - композиція. Кожен підклас ПросторовихФігур має мати 2 поля, тип даних першого - double - для висоти нашої фігури, тип даних другого - це об'єкт класу однойменного основі нашої фігури. За допомогою геттерів ми можемо доступитися до полів нашої основи, що значно спрощує обрахунки і реалізацію цілком. Також я думав за те, щоб зробити спільний клас для Пірамід, від якої будуть іти ТрикутнаПіраміда і ЧотирикутнаПіраміда. Цей клас мав би бути абстрактним, а , на мою думку, три абстрактні в ряд для такої програми це занадто (+зайва морока). Така реалізація хороша, бо можна створювати масиви і з просторових і з плоских фігур, але, водночас, має явний недолік (щоб оголосити об'єкт класу ПростороваФігура треба оголосити його основу - об'єкт класу ПлоскаФігура). Можливо це якось можна змінити через сеттери. Якраз, коли я пишу це, додумався як це зробити і в мене вийшло. Тобто явних недоліків я не бачу.
