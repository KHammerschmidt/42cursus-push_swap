<h1 align="center">
  <img  width="90" src="https://user-images.githubusercontent.com/19689770/129336866-169b0dc7-ea41-47d4-b50a-d466508031af.png">
  
	🧰 push_swap
 </img>

</h1>
</br>

<p align="center">
	<b> Algorithmic project - sorting data on a stack with limited set of instructions </b></br>
	Start date: 09/november/2021 </br>
	<sub> Project status: completed 88/100 points </sub>
</p>

<p align="center">
	<img alt="Github repo size" src="https://img.shields.io/github/repo-size/KHammerschmidt/42cursus-get_next_line?color=red"/>
	<img alt="Number of lines in code" src="https://img.shields.io/tokei/lines/github/KHammerschmidt/42cursus-get_next_line?color=blueviolet"/>
	<img alt="Languages used in repo" src="https://img.shields.io/github/languages/count/KHammerschmidt/42cursus-get_next_line?color=silver"/>
	<img alt="Top used progamming language" src="https://img.shields.io/github/languages/top/KHammerschmidt/42cursus-get_next_line?color=gold"/>	
</p>


## 💡 About the project
> The task is to write a sorting algorithm that sorts a stack, formatted as a list of integers, with the smallest list of instructions as possible. The program should output the list of instructions separated by '\n'. The stack may varies in size and consists of positive and/or negative intergers.
During the evaluation the number of operations will be compared against a limit, the maximum number of 
operations tolerated. When finished, the smallest number should be at the top of stack a. 
</br>


**Requirements** </br>
- The program is composed of 2 stacks named a and b </br>
- At the beginning, stack b is empty and a contains a random number of positive and negative numbers without any duplicates </br>
- Only specific operations are allowed (see below)
- 3 random numbers must be sorted with a maximum of 2 instructions, 5 random numbers with maximum 12 instructions.
</br>

#### 🌐 Radix Sort
The sorting algorithm applied to this project is radix sort, which is the process of sorting numbers on the stack by their bits rather than their true values. These operations are called bitwise operations and operate through bit manipulation.
While there are more efficient sorting algorithms that would have needed less instructions, Radix sort required to get familiar with bitwise shifting and performed decently enough to pass the project.
The bitwise operators used include ```>>```, ```&``` and ```>>=```. </br>
</br>


#### ```Bitwise AND & operator```
It performs logical conjunction of the bits in each position of a number in its binary form, this means when comparing 
two values it returns 1 if both elements in the comparison are 1 otherwise 0.

Examples: 
```
0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1
```

```
  11001000
& 10111000
__________
= 10001000
```
</br>

#### ```Right shift >> operator```
Right-shifts a number to the right by a certain amount of bytes. It requires two operands, e.g. ``` 350 >> 2 ```, which will shift the bits of the number 350 by 2 places to the right.  
Undefined behaviour arises with negative numbers or numbers that are >= to the total number of bits. This is why all numbers from a stack were first assigned an index ranging from 0 - number of integers on stack by which they are sorted by.
The bits are being shifted to the right and empty spaces on the left side are filled with zeroes. 
The program push_swap will then compare the rightmost value and pushes only those number to the other stack
that when compared with bitwise & result in 1.

Example:
```
int temp = 114 
operation: 114 > 1    

temp before operation: 01110010 
temp after operation:  00111001
```
</br>

#### ```Bitwise assignment operators >>=```
Performs binary operation by the value of right operand on left operand and stores the result in the left operand.

Example:
```
  save >>= 1
```
</br>


**Key learning points**
  - Bit shifting operators
  - basic algorithms
  - working with linked lists
  - using visualisers to see performance of program
</br>


##  :octocat: Sorting operations overview
The following operations were allowed when sorting the stack:
|     Operation    |   What is does                                                |
|------------------|---------------------------------------------------------------|
|[`sa`]            | swap first two elements of stack a                            |
|[`sb`]            | swap first two elements of stack b                            |
|[`ss`]            | perform sa and sb simultaneously                              | 
|[`pa`]            | push first element of a to top of stack b                     |
|[`pb`]            | push first element of b to top of stack a                     |
|[`ra`]            | shifts up all elements on stack a by 1.                       |
|[`rb`]            | shift up all elements on stack b by 1.                        |
|[`rr`]            | performs ra and rb simultaneously                             |
|[`rra`]           | reverse rotate stack a (shift down by 1)                      |
|[`rrb`]           | reverse rotate stack b (shift down by 1)                      |
|[`rrr`]           | performs rra and rrb simultaneously                           |
</br>


## 🛠️ **Usage**

clone the repository:
```bash
git clone https://github.com/KHammerschmidt/42cursus-push_swap &&
cd 42cursus-push_swap
```

to compile the project:
```bash
make
```

to launch the program with a set of numbers:
```bash
$ ./push_swap "3 4 -200 13 55"
```

</br>
