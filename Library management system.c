#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @struct Book
 * Structure to represent a book in the library.
 */
struct Book {
    char name[30];
    char author[30];
    int id;
    struct Book* next;
};

/**
 * @struct Student
 * Structure to represent a student in the library.
 */
struct Student {
    char name[30];
    int id;
    struct Student* next;
};

struct Book* library = NULL;
struct Student* students = NULL;

// Function prototypes
void displayUserMenu();
void displayAdminMenu();
void userMenu();
void adminMenu();
void initializeLibrary();
void issueBook();
void returnBook();
void displayStudents();
void addBook(char name[], char author[], int id);
void addStudent(char name[], int id);
void removeBook(int id);
void saveToFile(char fileName[], char data[]);
void getCurrentDateTime(char dateTime[]);

/**
 * @brief Frees memory allocated for books and students.
 */
void freeMemory() {
    struct Book* currentBook = library;
    while (currentBook != NULL) {
        struct Book* temp = currentBook;
        currentBook = currentBook->next;
        free(temp);
    }

    struct Student* currentStudent = students;
    while (currentStudent != NULL) {
        struct Student* temp = currentStudent;
        currentStudent = currentStudent->next;
        free(temp);
    }
}

/**
 * @brief Opens a file with a specified mode.
 * @param fileName The name of the file.
 * @param mode The mode in which to open the file.
 * @return A pointer to the opened file.
 */
FILE* openFile(char fileName[], char mode[]) {
    FILE* file = fopen(fileName, mode);
    if (file == NULL) {
        printf("Error opening file %s.\n", fileName);
        exit(1);
    }
    return file;
}

/**
 * @brief Saves data to a file.
 * @param fileName The name of the file.
 * @param data The data to be saved.
 */
void saveToFile(char fileName[], char data[]) {
    FILE* file = openFile(fileName, "a");
    fprintf(file, "%s\n", data);
    fclose(file);
}

/**
 * @brief Gets the current date and time in the specified format.
 * @param dateTime Buffer to store the date and time.
 */
void getCurrentDateTime(char dateTime[]) {
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(dateTime, 20, "%Y-%m-%d %H:%M:%S", timeinfo);
}

/**
 * @brief Saves data to a file with a timestamp.
 * @param fileName The name of the file.
 * @param data The data to be saved.
 */
void saveToFileWithTimestamp(char fileName[], char data[]) {
    char dateTime[20];
    getCurrentDateTime(dateTime);

    FILE* file = openFile(fileName, "a");
    fprintf(file, "[%s] %s\n", dateTime, data);
    fclose(file);
}

/**
 * @brief Displays the user menu.
 */
void displayUserMenu() {
    printf("\nUser Menu\n");
    printf("1. Issue a Book\n");
    printf("2. Return a Book\n");
    printf("3. Exit\n");
}

/**
 * @brief Displays the admin menu.
 */
void displayAdminMenu() {
    printf("\nAdmin Menu\n");
    printf("1. Add Book\n");
    printf("2. Remove Book\n");
    printf("3. Display Student Records\n");
    printf("4. Exit\n");
}

/**
 * @brief user menu options.
 */
void userMenu() {
    int userChoice;
    do {
        displayUserMenu();
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        switch (userChoice) {
            case 1:
                issueBook();
                break;
            case 2:
                returnBook();
                break;
            case 3:
                printf("Exiting user mode.\n");
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (1);
}

/**
 * @brief  admin menu options.
 */
void adminMenu() {
    int adminChoice;
    do {
        displayAdminMenu();
        printf("Enter your choice: ");
        scanf("%d", &adminChoice);

        switch (adminChoice) {
            case 1: {
                char name[30], author[30];
                int id;
                printf("Enter book details:\n");
                printf("Name: ");
                scanf("%29s", name);
                printf("Author: ");
                scanf("%29s", author);
                printf("ID: ");
                scanf("%29d", &id);
                addBook(name, author, id);
                printf("Book added successfully.\n");
                break;
            }
            case 2: {
                int bookId;
                printf("Enter the book ID you want to remove: ");
                scanf("%d", &bookId);
                removeBook(bookId);
                break;
            }
            case 3:
                displayStudents();
                break;
            case 4:
                printf("Exiting admin mode.\n");
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (1);
}

/**
 * @brief Initializes the library with some default books.
 */
void initializeLibrary() {
    addBook("A Tale Of Two Cities", "Charles Dickens", 101);
    addBook("The Devil's Diary", "Leonid Andreev", 102);
    addBook("The Black Obelisk", "Erich Maria Remarque", 103);
    addBook("Stone and Pain", "Karel Shoults", 104);
}

/**
 * @brief Adds a book to the library.
 * @param name The name of the book.
 * @param author The author of the book.
 * @param id The ID of the book.
 */
void addBook(char name[], char author[], int id) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->name, name);
    strcpy(newBook->author, author);
    newBook->id = id;
    newBook->next = library;
    library = newBook;
}

/**
 * @brief Adds a student to the library.
 * @param name The name of the student.
 * @param id The ID of the student.
 */
void addStudent(char name[], int id) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->next = students;
    students = newStudent;
}

/**
 * @brief  the process of issuing a book to a student.
 */
void issueBook() {
    char studentName[30];
    printf("Enter your name: ");
    scanf("%s", studentName);

    printf("Available Books:\n");

    struct Book* currentBook = library;
    while (currentBook != NULL) {
        printf("Book ID: %d, Book Name: %s, Author: %s\n", currentBook->id, currentBook->name, currentBook->author);
        currentBook = currentBook->next;
    }

    int bookId;
    printf("Enter the book ID you want to issue: ");
    scanf("%d", &bookId);

    currentBook = library;
    while (currentBook != NULL) {
        if (currentBook->id == bookId) {
            addStudent(studentName, bookId);

            char dateTime[20];
            getCurrentDateTime(dateTime);

            printf("Issued book: %s\n", currentBook->name);

            char data[100];
            sprintf(data, "[%s] Issued book: %s to %s", dateTime, currentBook->name, studentName);
            saveToFile("library_log.txt", data);

            removeBook(bookId);
            return;
        }
        currentBook = currentBook->next;
    }

    printf("Book not found with ID: %d\n", bookId);
}

/**
 * @brief the process of returning a book by a student.
 */
void returnBook() {
    int bookId;
    printf("Enter the book ID you want to return: ");
    scanf("%d", &bookId);

    struct Student* currentStudent = students;
    while (currentStudent != NULL) {
        if (currentStudent->id == bookId) {
            addBook("Book Name", "Book Author", bookId);
            printf("Returned book with ID: %d\n", bookId);

            char dateTime[20];
            getCurrentDateTime(dateTime);

            char data[100];
            sprintf(data, "[%s] Returned book with ID: %d", dateTime, bookId);
            saveToFile("library_log.txt", data);

            return;
        }
        currentStudent = currentStudent->next;
    }

    printf("Student with book ID: %d not found\n", bookId);
}

/**
 * @brief Displays the records of students in the library.
 */
void displayStudents() {
    struct Student* currentStudent = students;
    printf("Student Records:\n");
    while (currentStudent != NULL) {
        printf("Student Name: %s, Student ID: %d\n", currentStudent->name, currentStudent->id);
        currentStudent = currentStudent->next;
    }
}

/**
 * @brief Removes a book from the library by ID.
 * @param id The ID of the book to be removed.
 */
void removeBook(int id) {
    struct Book* currentBook = library;
    struct Book* previousBook = NULL;
    while (currentBook != NULL) {
        if (currentBook->id == id) {
            if (previousBook == NULL) {
                library = currentBook->next;
            } else {
                previousBook->next = currentBook->next;
            }
            free(currentBook);
            printf("Book removed successfully.\n");

            char dateTime[20];
            getCurrentDateTime(dateTime);

            char data[100];
            sprintf(data, "[%s] Removed book with ID: %d", dateTime, id);
            saveToFile("library_log.txt", data);

            return;
        }
        previousBook = currentBook;
        currentBook = currentBook->next;
    }
    printf("Book not found with ID: %d\n", id);
}

/**
 * @brief The main function of the library management system.
 * @return 0 upon successful execution.
 */
int main() {
    int roleChoice;
    initializeLibrary();

    printf("Welcome to the Library Management System!\n");

    do {
        printf("\nChoose your role:\n");
        printf("1. User\n");
        printf("2. Admin\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &roleChoice);

        switch (roleChoice) {
            case 1:
                userMenu();
                break;
            case 2:
                adminMenu();
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                freeMemory(); // Free allocated memory before exit
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (1);

    return 0;
}
