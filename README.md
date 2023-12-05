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

#include <stdio.h>

int main() {

    // Collecting static data from user input
    int userAge;
    printf("Enter your age: ");
    scanf("%d", &userAge);
    printf("User Age: %d\n", userAge);

    return 0;
}

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

**2.2 Data Integration**

