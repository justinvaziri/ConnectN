# ConnectN Game

The ConnectN game is an extended version of the classic Connect Four game. In this implementation, you can specify the number of rows, columns, and pieces in a row needed to win.

## How to Play

1. **Clone the repository or download the source files.**

2. **Compile the code using the provided Makefile:**

   Open your terminal and navigate to the project directory. Run the following command:
   
   ```bash
   make
   ```
   
This will compile the code and create an executable named connectn.out.

Run the compiled executable to start the game:
In the terminal, enter the following command:
   ```bash
   ./connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win
   ```

Replace 'num_rows', 'num_columns', and 'number_of_pieces_in_a_row_needed_to_win' with the desired values.

## Sample Gameplay

```plaintext
./connectn.out 4 4 2

  3  *  *  *  * 
  2  *  *  *  * 
  1  *  *  *  * 
  0  *  *  *  * 
     0  1  2  3 
Enter a column between 0 and 3 to play in: 0

  3  *  *  *  * 
  2  *  *  *  * 
  1  *  *  *  * 
  0  X  *  *  * 
     0  1  2  3 
Enter a column between 0 and 3 to play in: 2

  3  *  *  *  * 
  2  *  *  *  * 
  1  *  *  *  * 
  0  X  *  O  * 
     0  1  2  3 
Enter a column between 0 and 3 to play in: 1

  3  *  *  *  * 
  2  *  *  *  * 
  1  *  *  *  * 
  0  X  X  O  * 
     0  1  2  3 
Player 1 Won!
```
## License

This project is licensed under the [MIT License](https://opensource.org/license/mit/).

Feel free to use, modify, and distribute this code according to the terms of the license.

## Acknowledgments

This project was inspired by the classic Connect Four game and extends it to offer customizable dimensions and win conditions.
