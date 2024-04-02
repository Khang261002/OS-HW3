# OS-HW3

This script demonstrates memory management and address translation using a page/frame table. The program translates logical addresses to physical addresses and handles page faults appropriately.

## Usage

To execute the program, follow these steps:

1. Ensure you have a C++ compiler installed on your system.
2. Clone or download the repository containing the source code.
3. Navigate to the directory containing the source code in your terminal or command prompt.
4. Compile the code using the C++ compiler. For example:
```
g++ -o HW3 HW3.cpp
```
5. Run the compiled executable:
```
./HW3
```
6. The program will output the translated addresses along with page numbers and offsets.
7. Modify or add new values to the map table. For example: add the code to the cpp file
```cpp
page_frame_table.mapPageToFrame(0x12, 0x32);
```

## Functionality

The program provides the following functionality:

- **Translation of Logical Addresses**: It accurately translates logical addresses to physical addresses using the page/frame table.
- **Handling Page Faults**: The program handles page faults by loading pages from secondary storage into memory when necessary.
- **Efficient Page/Frame Table**: The page/frame table is implemented correctly and efficiently, ensuring proper mapping of logical page numbers to physical frame numbers.
- **Input and Output Handling**: The program accepts logical addresses as input and provides corresponding physical addresses, along with page numbers and offsets, as output.
- **Error Handling**: It robustly handles potential errors, such as invalid input addresses or insufficient memory, providing appropriate error messages or gracefully handling such cases.
