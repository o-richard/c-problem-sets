# C Problem Sets

> This is a collection of various problem sets solved by the C programming language.

# Repository Structure

The repository is organised into several folders. Each folder has a file solving a particular task/problem/challenge.

* [stack_queues](stack_queues)
> The challenge/problem/task is shown below.
```
The folder contains
- stacks.c - The program implements a stack abstract data type using arrays.
- queues.c - The program implements a queue abstract data type using arrays.

For both stacks and queues, basic operations are done:
    * Insterting a new item
    * Removing an item
    * Checking their current total size
    * Checking if they are empty or full
    * Checking their topmost element (Queue is FIFO - First In First Out while Stack is LIFO - Last In First Out)
```

* [abstract_data_types_sum](abstract_data_types_sum/sum.c)
> The challenge/problem/task is shown below.
```
The program allows a user to

1. Select the abstract data type they want to work with - Arrays, Matrices, Polynomials

2. For arrays (Implemented using arrays):
    - A user specifies the number of elements in the arrays in which they want to sum
    - A user specifies how many arrays they want to sum

3. For matrices (Implemented using arrays):
    - A user specifies the order of a 2D matrix that they want to sum
    - A user selects the number of matrices they want to sum

4. For polynomials (Implemented using arrays & linked lists):
    - A user specifies the number of polynomials they want to add
    - For each polynomial, they add the number of terms they wish to have until they wish to stop
```

* [grading](grading/grading.c)
> The challenge/problem/task is shown below.
```
Create a program that will enable the user to capture the students details. The student details should cointain the Reg No, Full Names, Admission Number and Marks  and codes for the five units. The marks should be declared as an array.

The program should cointain functions to

1.  Calculate the avarage mark of the students, 

2. Culculate the total marks

3. Display the unit with the highest  and lowest mark

4. Grade each unit mark

Provide a menu for the use to select the actions they want to perform as follows

1. Add student details

2. View student details

3. Culculate the total student marks

4. Culculate the avarage marks

5. Display the unit with the highest mark

6. Display the unit with the lowest mark

7. Exit



The program should enable the use to perform the actions above for more than one student. The program shouldonly terminate once the user selects the exit option.
```

* [math_game](math_game/math_game.c)
> The challenge/problem/task is shown below.
```
The game helps a person practice arithmetic using different operations and random numbers in different sets of numbers. You will choose how many number of times you want to play at first, and when your trials end, you may choose to add more tries.

The operations are +, -, *, /
The levels are divided into:
    - Low(Numbers in the range 1 to 10)
    - Middle(Numbers in the range 11 to 50)
    - High(Numbers in the range 51 to 100)
```

* [statistics](statistics/statistics.c)
> The challenge/problem/task is shown below.
```
Write a program that takes as input an array of numbers and uses functions to carry out the following operations

1. Sorts the array in descending order

2. Finds the minimum number in the array

3. Finds the maximum number in the array

4. Calculates the average of the array numbers

5. Calculates the standard deviation of the numbers



The function should have a a menu that the user can choose from the operation they want to do.
```

* [number_operations](number_operations/number_operations.c)
> The challenge/problem/task is shown below.
```
Create a menu driven program that has the following menus

1.      Get number

2.      Determine if Number is Even or Odd

3.      Determine if number is positive or negative

4.      Determine how many digits are in a number

5.      Exit

You must create the following functions

1.      Display menu: This function should display the menu above and asks the user to make their choice

2.      Get input-This function should get the number to be checked by other functions

3.      isEven-The function to check if the number is even or odd

4.      IsPos-The function to check if the number is positive or not

5.      NumDigit: This function should return the number of digits in the given number

Hint: To determine the number of digits in a number, divide it repeatedly by 10. When the number reaches 0, the number of divisions is the number of digits in the original number.
```

* [fibonnacci](fibonnacci/fibonnacci.c)
> The challenge/problem/task is shown below.
```
Create a program that culculates the fibonnacci sequence of a given number. Use recursive function to achieve this.
```

* [reverse](reverse/reverse.c)
> The challenge/problem/task is shown below.
```
Use the while loop to write a program that will print in reverse order the numbers preceding a given number starting with the given number and calculate the product of the numbers . For example if the given number is 5 the output should be 5,4,3,2,1.

The output should also indicate the product after each iteration.
```

* [triangular_number](triangular_number/triangular_number.c)
> The challenge/problem/task is shown below.
```
A triangular number is the sum of all the numbers up to that number. Write a program that calculates the sum up to the given number. Use scanf to get the given number.
```

* [factorial](factorial/factorial.c)
> The challenge/problem/task is shown below.
```
Create a program that calculates the factorial of a number
```

* [arithmetic](arithmetic/arithmetic.c)
> The challenge/problem/task is shown below.
```
Create a program that has two integer variables.Display the sum, division, multiplication, subtraction  of the two variables.

Display the result in the following format.
Addition: number 1 + number2 =Answer

Subtraction: number 1 - number2=Answer

Multiplication:  number 1 * number2=Answer

Division: number 1 / number2=Answer
```

* [money_conversion](money_conversion/money_conversion.c)
> The challenge/problem/task is shown below.
```
Create a program that will convert a given amount in Kshs to USD using today's exchange rate.

Have the user enter the amount to be converted from the keyboard.
```

* [prime_number](prime_number/prime_number.c)
> The challenge/problem/task is shown below.
```
Write a program that checks the number entered by a user to see if it is a prime number or not.
```

* [invoice](invoice/invoice.c)
> The challenge/problem/task is shown below.

```
Stores the details of customer invoices in a file
```


* [commission](commission/commission.c)
> The challenge/problem/task is shown below.

```
Create a program that will help a manager determine the amount of commission to pay their sales persons depending on the sales they have sold. The commission  percentages are as follows;

0-1000                              1%

Above 1000-5000           3%

Above 5000-10000         5%

Above 10,000                 10%

The program should allow the manager to enter the name, payroll number and the amount of sales the sales person has sold.

The program output should be able to display sales person name, payroll no, amount of sales, commission amount and the total salary.

The total salary is a sum of the commission and the retainer amount. The retainer amount for all the sales persons is Kshs.25,000.

The program should prompt the user to enter the number of sales people they want to capture their data. The program should only end when all the details of all the sales people have been entered.
```

* [area](area/area.c)
> The challenge/problem/task is shown below.
```
Write a program to calculate the area of triangle, circle or rectangle depending upon the user option
```

* [days](days/days.c)
> The challenge/problem/task is shown below.
```
Write a program to print the day of the week name using a switch case
```

* [birth_month](birth_month/birth_month.c)
> The challenge/problem/task is shown below.
```
Create a program that displays customized messages to the user depending on their month of birth using the switch case.
```

* [bmi](birth_month/birth_month.c)
> The challenge/problem/task is shown below.
```
Calculate a person's BMI.
```

# Built With
1. C programming language

# Author

The author of this project is Richard Odhiambo.

 You can find me here at:
[Github](https://github.com/o-richard)

# License

This project is licensed under the MIT License.