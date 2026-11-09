# Color checker

## Description
At this stage of the program the user is able to check color combinations for Deuteranope. The program asks the user to select 2 colors and then the program checks if the color comonation is pre made set. If the pair is in the list it will flag the user. If the combination is not in the list it will let the user know the combo is ok.
**version 1.0**


## Developer
Raquel Beas-Gonzalez


## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Welcome to the blindess checker!
Please select from the following options: 
1.) Deuteranope
1
We'll be checking color combinations for Deuteranope color blindness
1.) Red      2.) Orange
3.) Yellow   4.) Green
5.) Blue     6.) Indigo
7.) Violet
Enter your first color: 
1
Enter your second color: 
4
This is not a good color combination for someone with Deuteranope color blindness
```