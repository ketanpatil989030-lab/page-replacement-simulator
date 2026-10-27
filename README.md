# Page Replacement Simulator

A simple C++ console project that compares two Operating Systems page replacement algorithms:

- **FIFO (First-In, First-Out):** replaces the page that entered memory first.
- **LRU (Least Recently Used):** replaces the page that has not been accessed for the longest time.

The program takes a page-reference sequence and the number of available memory frames, then displays the total page faults for each algorithm.

## Requirements

- A C++ compiler such as `g++` (GCC), Code::Blocks, or Visual Studio.
- Windows, Linux, or macOS.

## Compile and run

### Windows (MinGW/GCC)

Open Command Prompt or the terminal in VS Code in this folder:

```bash
g++ main.cpp -o page_replacement
.\page_replacement.exe
```

### Linux or macOS

```bash
g++ main.cpp -o page_replacement
./page_replacement
```

## Sample run

Input:

```text
Enter number of page references: 12
Enter page reference string: 1 2 3 1 4 5 2 1 2 3 4 5
Enter number of frames: 3
```

Output:

```text
FIFO page faults: 10
LRU page faults: 10
```

Results depend on the page-reference sequence and frame count.

## How it works

1. The program reads the number of page references.
2. It reads the page-reference sequence and the frame count.
3. FIFO and LRU process the same sequence independently.
4. The program prints the total page faults for each algorithm.

## Project limitations

- Console-based; no graphical interface.
- Reports total page faults only; it does not display each frame after every reference.
- Implements FIFO and LRU only.
- Educational simulation; it does not control a real operating system's memory manager.

## Possible improvements

- Add Optimal Page Replacement.
- Display frame contents and hit/fault status for each page.
- Calculate hit ratio and fault ratio.
- Add a graphical interface and charts.

## Repository structure

```text
page-replacement-simulator/
├── main.cpp
├── README.md
├── sample_input.txt
├── .gitignore
└── LICENSE
```

## Academic note

Use this repository as a learning project. Review the code, run it yourself, and update the README with your own explanation and screenshots if required by your instructor.
