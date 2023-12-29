/* ПЕРВОЕ Функция принимает basicOperation принимает три аргумента: оператор
(строка) и два операнда (числа); возвращает результат вычисления.
Допишите функцию, которая может принимать операторы +, -, *, /.*/

// let operator = prompt("Введите оператор (+, -, *, /):");
// if (
//     operator !== "+" &&
//     operator !== "-" &&
//     operator !== "*" &&
//     operator !== "/"
// ) 
// {
//     console.log("Недопустимый оператор");
// } 
// else 
// {
//     let value1 = parseFloat(prompt("Введите первое число:"));
//     let value2 = parseFloat(prompt("Введите второе число:"));
//     if (isNaN(value1) || isNaN(value2)) 
//     {
//         console.log("Операнды должны быть числами");
//     } 
//     else 
//     {
//         let res = basicOperation(operator, value1, value2);
//         document.write(res);
//     }
// }

// function basicOperation(operation, val, val2) 
// {
//     switch (operation) 
//     {
//         case "+":
//             return val + val2;
//         case "-":
//             return val - val2;
//         case "*":
//             return val * val2;
//         case "/":
//             if (val2 === 0) {
//                 return "Деление на ноль невозможно";
//             }
//             return val / val2;
//     }
// }


/*ВТОРОЕ Реализовать функцию, которая принимает число n и возвращает сумму
кубов всех чисел до n включительно.*/ 


// let x = parseFloat(prompt("Число n: "));
// let result = kyb(x);
// document.write(result);
// function kyb(n) 
// {
//     let i = 0, res = 0;
//     do{
//         res+=i*i*i;
//         i++;
//     }
//     while(i != n + 1)
//     return res;
// }


/*ТРЕТЬЕ Реализовать функцию, которая принимает один аргумент – массив
чисел и возвращает среднее арифметическое всех элементов массив.*/ 
// let arr = [];
// let size = parseFloat(prompt("Размер массива: "));
// for(let i = 0; i < size; i++)
// {
//     arr[i] = parseFloat(prompt("arr[" + i + "]"))
// }
// document.write("Массив: " + arr)
// let result = sum(arr);
// function sum(array)
//{
//     let summa = 0;
//     for(let k = 0; k < size; k++)  
//     {
//         summa+=array[k];
//     }  
//     return (summa / size);
// }
// document.write("Результат: " + result)

/*ЧЕТВЕТОЕ Реализовать функцию, которая получает строку str, переворачивает ее и
возвращает строку, состоящую только из символов английского алфавита.*/

// let str = prompt("Строка: ");
// function string(str1)
// {
//     let reverse = str1.replace(/[а-яё]/gi, '').split('').reverse().join('');
//     return reverse;
// }
// document.write(string(str));


/*ПЯТОЕ Напишите функцию, которая принимает целое число n и строку s в
качестве параметров и возвращает строку s, повторяющуюся ровно n раз.*/ 

// let s = prompt("Введите s: ");
// let n = parseFloat(prompt("Введите n: "));
// let strr = str(s, n);
// document.write(strr);
// function str(str, n)
// {
//     let str1 = str;
//     for(let i = 0; i < n - 1; i++)
//     {
//         str1 += str; 
//     }
//     return str1;
// }

// ШЕСТОЕ Напишите функцию, которая принимает два массива строк arr1 и arr2. 
// Функция возвращает массив arr3, которые содержит строки из arr1, но не входящие в arr2.

// function filterStrings(arr1,arr2)
// {
//     let arr3=arr1.filter(function (str)
//     {
//         console.log(!arr2.includes(str));
//     })
//     return arr3;
// }
// let arr1 = ['apple', 'banana', 'orange', 'kiwi'];
// let arr2 = ['banana', 'kiwi', 'grape'];
// let result = filterStrings(arr1, arr2);
// document.write(result);

function compare(arr1)
{
    if(arr1.includes(2))
    {
        console.log(true);
    }
    else
    {
        console.log(false);
    }
}
let arr1 = [1,2,7];
let result = compare(arr1);

for(let i of arr1)
{
    console.log(i);
}

arr1.forEach(i=>{
    console.log(i);
});

function compare1(arr2)
{
for(let index = 0; index < arr2.length; ++index)
{
    console.log(arr2[index]);
}
}
let arr2 = [2,4,5];
let res = compare1(arr2);































let arr3 = [2,6,8,5];
let arr4 = [8,5,3];

function F(arr3)
{
    for(let i = 0; i< arr3.length; i++)
    {
        if(arr3[i] == 8)
        {
            console.log(true);
        }
        else
        {
            console.log(false);
        }

    }
}

let res1 = F(arr3)
