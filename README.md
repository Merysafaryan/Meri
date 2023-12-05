# Library Management System 

**Abstract**

A Library Management System is software used by libraries to manage and organize their resources, including books. The system will helps librarians in tasks like cataloging, borrowing and returning for book.

**Introduction**

Traditionally, libraries have been vital hubs for learning and research, acting as gatekeepers to a vast array of knowledge. With the advent of technology, the need for an automated and user-friendly system to manage library resources has become increasingly apparent. This project is motivated by the desire to modernize library operations, reducing manual efforts and enhancing user experience.The motivation behind this project also stems from the growing demand for efficiency in managing library tasks, such as book issuance, returns, and user records. 

Develop a user-friendly interface for both librarians and patrons, facilitating seamless processes for book issuance, returns, and user record management. Provide a digital platform that allows users to access the library's resources remotely, fostering a more inclusive learning environment.Real-time data collection and analysis are crucial in the context of library management for several reasons:Real-time data allows librarians to understand user behavior and preferences, enabling them to tailor services to meet the specific needs and expectations of library patrons.

# 1.Project setup and Planning

**1.1 Project Scope Definition**

The project's scope encompasses a detailed description of a selected manufacturing process, elucidating its intricacies and functionalities. The chosen process was selected after careful consideration of its alignment with project objectives, aiming to enhance production efficiency and streamline workflows. The decision to adopt this specific manufacturing process reflects its potential to meet project goals and contribute to the optimization of manufacturing operations, ensuring the attainment of desired outcomes in the realm of production and efficiency.

**1.2 Hardware and Software Setup**
1. C programming language
2. C libraries:
   - stdio.h
   - stdlib.h
   - string.h
   - time.h
The provided code appears to be a simple implementation of a library management system in C. Below is a brief overview of the key components and functionalities:

**1.3 Data Collection Plan**

Book Structure (struct Book):
  - Attributes: name, author, id, next (a pointer to the next book).
  Student Structure (struct Student)
  - Attributes: name, id, next (a pointer to the next student).
Functions:
- File Handling Functions:
  - openFile: Opens a file with a specified mode.
  - saveToFile: Saves data to a file.
  - getCurrentDateTime: Gets the current date and time in a specified format.
  - saveToFileWithTimestamp: Saves data to a file with a timestamp.

 Library Management Functions:
  - initializeLibrary: Initializes the library with some default books.
  - addBook: Adds a book to the library.
  - addStudent: Adds a student to the library.
  - removeBook: Removes a book from the library by ID.

  User Interaction Functions:
  - displayUserMenu: Displays the user menu.
  - displayAdminMenu: Displays the admin menu.
  - userMenu: Handles user menu options issuing and returning books.
  - adminMenu: adding books, removing books, displaying student records.

  Library Transactions:
  - issueBook: The process of issuing a book to a student.
  - returnBook: The process of returning a book by a student.
  - displayStudents: Displays the records of students in the library.

  Memory Management:
  - freeMemory: Frees memory allocated for books and students.

  Main Function:
  - The main function initiates the library management system, provides a welcome message, and allows users to choose their role (user, admin, or exit).

Importance of Data Points:
- The code manages crucial data points such as book details (name, author, ID), student details (name, ID), and transaction logs (timestamped events like issuing and returning books).
- The book and student structures serve as fundamental data structures for organizing information.
- The file handling functions and transaction logs are essential for maintaining a record of library activities.

# 2. Data Collection,Integration, and Analysis

**2.1 Data Collection Implementation**
Generating Random Numbers:
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() { 
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        int randomNumber = rand() % 100;  // Generates a random number between 0 and 99
        printf("Random Number %d: %d\n", i + 1, randomNumber);
    }

    return 0;
}
```
Simulating Sensor Data
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    for (int i = 0; i < 5; ++i) {
        double sensorReading = (double)rand() / RAND_MAX * 10.0; 
        printf("Sensor Reading %d: %.2f\n", i + 1, sensorReading);
    }

    return 0;
}
```
Collecting User Input
```c
#include <stdio.h>

int main() {

    // Collecting static data from user input
    int userAge;
    printf("Enter your age: ");
    scanf("%d", &userAge);
    printf("User Age: %d\n", userAge);

    return 0;
}
```
Static Data Initialization:
```c
#include <stdio.h>

int main() {

    // Static data initialization
    int staticArray[] = {1, 2, 3, 4, 5};
    printf("Static Array Elements: ");
    for (int i = 0; i < sizeof(staticArray) / sizeof(staticArray[0]); ++i) {
        printf("%d ", staticArray[i]);
    }
    printf("\n");

    return 0;
}
```
**2.2 Data Integration**
In the provided C code for the library management system, two main data structures are used to store and manage collected data: `struct Book` and `struct Student`. Let's discuss these structures and the justification for choosing them.

 1.struct Book

```c
struct Book {
    char name[30];
    char author[30];
    int id;
    struct Book* next;
};
```
Explanation:
- struct Book is designed to represent a book in the library.
- It contains fields for the name of the book (name), the author of the book (author), a unique identifier for the book (id), and a pointer to the next book in the linked list (next).
- This structure is used to create a linked list of books in the library.

Justification:
- Linked lists are chosen to manage the collection of books dynamically. This allows for efficient memory usage as the size of the library can grow or shrink during runtime.
- The `struct Book` encapsulates related information about a book in a single unit, making it easy to manage and manipulate book data.
  
 2. struct Student

```c
struct Student {
    char name[30];
    int id;
    struct Student* next;
};
```

Explanation:
- struct Student represents a student in the library.
- It includes fields for the student's name (name), a unique identifier for the student (id), and a pointer to the next student in the linked list (next).
- Similar to struct Book, this structure is used to create a linked list of students who have borrowed books.

Justification:
- Using a linked list for students provides a dynamic and efficient way to manage student records. Students can be added or removed from the system without the need for a fixed-size array.
- The structure contains the necessary information about a student, and the linked list allows for easy traversal and manipulation of student records.

Overall Justification:
 Both data structures use linked lists, which are well-suited for scenarios where the size of the data can change dynamically. This is crucial in a library management system where books and student records can be added or removed. Linked lists allow for efficient memory usage as memory is allocated as needed. This is more memory-friendly compared to using static arrays, especially when the size of the library or the number of students is unknown in advance. Linked lists provide flexibility, making it easier to insert, delete, or modify elements in the collection. This is beneficial for managing a library where books are checked in and out, and student records may change over time.

**2.3 Data Analysis**
```c 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the mean of an array
double calculateMean(int arr[], int size) {
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}

// Function to calculate the median of an array
double calculateMedian(int arr[], int size) {
    // Sort the array
    qsort(arr, size, sizeof(int), compare);

    // If the size is odd, return the middle element
    if (size % 2 != 0) {
        return arr[size / 2];
    }
    // If the size is even, return the average of the two middle elements
    else {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
}

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to calculate the mode of an array
int calculateMode(int arr[], int size) {
    // Sort the array
    qsort(arr, size, sizeof(int), compare);

    int currentNum = arr[0];
    int currentCount = 1;
    int maxCount = 1;
    int mode = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] == currentNum) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                mode = currentNum;
            }

            currentNum = arr[i];
            currentCount = 1;
        }
    }

    return mode;
}

// Function to calculate the standard deviation of an array
double calculateStandardDeviation(int arr[], int size) {
    double mean = calculateMean(arr, size);
    double sumSquaredDiff = 0.0;

    for (int i = 0; i < size; i++) {
        sumSquaredDiff += pow(arr[i] - mean, 2);
    }

    return sqrt(sumSquaredDiff / size);
}

int main() {
    int data[] = {5, 2, 7, 4, 8, 6, 1, 3};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Mean: %.2f\n", calculateMean(data, size));
    printf("Median: %.2f\n", calculateMedian(data, size));
    printf("Mode: %d\n", calculateMode(data, size));
    printf("Standard Deviation: %.2f\n", calculateStandardDeviation(data, size));

    return 0;
}
```
# 3. Testing, Documentation, and Presentation

**3.1 Testing and Validation**
Testing a library management system with simulated data involves executing various functionalities and ensuring that they produce the expected results. In the case of the provided code, you can simulate user and admin interactions to test the system. Here's an example of how you might test and validate the system:

1. Test User Interactions:
   - Choose the user role (option 1).
   - Issue a book (option 1).
   - Return a book (option 2).
   - Exit the user menu (option 3).

2. Test Admin Interactions:
   - Choose the admin role (option 2).
   - Add a book (option 1).
   - Remove a book (option 2).
   - Display student records (option 3).
   - Exit the admin menu (option 4).

3. Test Edge Cases:
   - Try issuing a book that doesn't exist.
   - Try returning a book that hasn't been issued.
   - Try removing a book that doesn't exist.
   - Try displaying student records when there are none.

4. Validate Output:
   - Check if the issued and returned books are logged in the `library_log.txt` file.
   - Verify that books are added and removed correctly.
   - Ensure that the displayed information (such as student records) is accurate.

5. Error Handling:
   - Input invalid data to check if the program handles errors appropriately (e.g., entering a string when a number is expected).

6. Memory Management:
   - Check if memory is correctly allocated and freed.
   - Test the program with a large number of books and students to see if it handles memory efficiently.

7. File Operations:
   - Ensure that the log file (`library_log.txt`) is updated correctly with timestamps and relevant information.

8. Boundary Testing:
   - Test the system with the maximum number of books and students it can handle.
   - Check if the system gracefully handles cases where memory allocation fails.

9. Performance Testing:
   - Measure the performance of the system with a large dataset to ensure it responds within acceptable time limits.

10. User Experience:
    - Evaluate the overall user experience and interface during interactions.


**3.2 Documentation and Code Explanation**

Documentation
How to Run the Project:

1.Compile the Code:
   - Use a C compiler  to compile the code.
   ```bash
   gcc library_management_system.c -o library_management_system
   ```

2. Run the Executable:
   - Execute the compiled binary.
   ```bash
   ./library_management_system
   ```
   - Follow the on-screen prompts to interact with the library management system.

Code Structure and Organization:
The code is organized into several sections:

1. Struct Definitions:
   - Defines two structures (`Book` and `Student`) to represent books and students in the library.

2. Global Variables:
   - Declares global variables for the library and students.

3. Function Prototypes:
   - Declares prototypes for various functions used in the program.

4. Memory Management Functions:
   - `freeMemory`: Frees memory allocated for books and students.
   - `openFile`: Opens a file with a specified mode.

5. File Handling Functions:
   - `saveToFile`: Saves data to a file.
   - `getCurrentDateTime`: Gets the current date and time.
   - `saveToFileWithTimestamp`: Saves data to a file with a timestamp.

6. Menu Display Functions:
   - `displayUserMenu`: Displays the user menu.
   - `displayAdminMenu`: Displays the admin menu.
     
7.Library Initialization Function:
   -initializeLibrary: Adds default books to the library.

8. User and Admin Functions:
   - `userMenu`: Handles user menu options.
   - `adminMenu`: Handles admin menu options.

9. Library Initialization Function:
   - `initializeLibrary`: Initializes the library with default books.

10. Book and Student Management Functions:
   - `addBook`: Adds a book to the library.
   - `addStudent`: Adds a student to the library.
   - `issueBook`: Manages the process of issuing a book to a student.
   - `returnBook`: Manages the process of returning a book by a student.
   - `removeBook`: Removes a book from the library by ID.
   - `displayStudents`: Displays student records.

11. Main Function:
    - `main`: The main function that serves as the entry point of the program.
    - Initiates the library, displays the main menu, and routes to user or admin menus based on user input.

Detailed Code Explanation

1. Struct Definitions:
   - Defines `Book` and `Student` structures to encapsulate book and student information.

2. Global Variables:
   - `library` and `students` are pointers to linked lists representing the books and students in the library.

3. Memory Management Functions:
   - `freeMemory`: Frees memory allocated for books and students.
   - `openFile`: Opens a file with error handling.

4. File Handling Functions:
   - `saveToFile`: Appends data to a file.
   - `getCurrentDateTime`: Retrieves the current date and time.
   - `saveToFileWithTimestamp`: Appends data to a file with a timestamp.

5. Menu Display Functions:
   - `displayUserMenu`: Prints the user menu.
   - `displayAdminMenu`: Prints the admin menu.

6. User and Admin Functions:
   - `userMenu`: Handles user interactions (issuing/returning books).
   - `adminMenu`: Handles admin interactions (adding/removing books, displaying student records).

7. Library Initialization Function:
   - `initializeLibrary`: Adds default books to the library.

8. Book and Student Management Functions:
   - `addBook`: Allocates memory for a new book and adds it to the library.
   - `addStudent`: Allocates memory for a new student and adds it to the students list.
   - `issueBook`: Handles the process of issuing a book to a student.
   - `returnBook`: Handles the process of returning a book by a student.
   - `removeBook`: Removes a book from the library by ID.
   - `displayStudents`: Prints student records.

9. Main Function:
   - `main`: Initiates the library, presents the main menu, and directs the program flow based on user input.

# Conclusion

**Summary of Key Findings and Achievements**

The library management system project was successfully implemented, providing a functional and interactive system for managing books and student records. Key findings and achievements include:

1. Functionality:The system allows users and administrators to perform various operations such as issuing and returning books, adding and removing books, and displaying student records.

2. Structured Code: The code is well-organized with clear structure and modular functions. The use of linked lists efficiently manages the dynamic nature of book and student records.

3. User-Friendly Interface: The system incorporates user-friendly menus, making it easy for both users and administrators to interact with the library management functionalities.

4. Logging and Timestamps: The program logs transactions to a file with timestamps, providing a record of activities within the library. This can be useful for tracking and auditing purposes.

**Lessons Learned from the Project**

1. Data Structures: Implementing linked lists for managing books and students enhances the efficiency of operations, especially when dealing with dynamic data.

2. User Input Handling: The project involved robust handling of user inputs, ensuring that the program gracefully handles various scenarios and prevents unintended errors.

3. File Handling: The use of file handling functions to save data and log transactions adds a layer of persistence to the system, allowing data to be retained between different program executions.

4. Menu-Driven Programs: Building a menu-driven program provides a structured and intuitive way for users to interact with the system. This can be extended to other projects requiring user interfaces.

**Discussion of Outcomes and Achievements in Optimizing the Chosen Manufacturing Process**

While the library management system is not directly related to manufacturing processes, the project does demonstrate effective software engineering principles and practices. The optimization in this context lies in the efficient management of library resources (books and student records) using linked lists, modular design, and user-friendly interfaces.

The use of linked lists for book and student management optimizes the process of adding, removing, and displaying records. It allows for dynamic memory allocation and efficient utilization of resources. The logging of transactions with timestamps contributes to accountability and tracking of system activities.

In a broader sense, the project showcases the importance of thoughtful design and implementation, even in non-manufacturing contexts. Lessons learned from this project, such as effective data structure usage, user input handling, and modular code organization, can be applied to optimize processes in various domains, including manufacturing systems.

In conclusion, the library management system project serves as a practical exercise in software development, emphasizing the significance of structured code, user interfaces, and efficient data management. The outcomes and lessons learned contribute to a foundation for future projects, including those involving manufacturing processes and optimization.





