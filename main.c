// mariam turk , id :1211115 , sec :1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 1000

typedef struct tree_node *tree_ptr;
struct tree_node
{
  int stud_id;
    char stud_name[1000];
    char city[1000];
    int class_id;
    char enr_date[1000];
 tree_ptr left;
 tree_ptr right;
};




// function to insert the data of student in binary search tree by the id of the student
tree_ptr insert (tree_ptr T  , int stud_id ,  char stud_name[] ,char city[] ,int class_id ,char enr_date[]  ){

    if (T == NULL){ // the tree is empty ,make new root
        T=(struct tree_node*)malloc(sizeof(struct tree_node));
        T ->stud_id = stud_id;
        strcpy (T -> stud_name, stud_name);
        strcpy (T -> city, city);
        T ->class_id = class_id;
         strcpy (T -> enr_date, enr_date);
        T->left=NULL;
        T->right=NULL;
    }
    else if (stud_id < T ->stud_id){
       T -> left = insert(T -> left , stud_id, stud_name , city , class_id , enr_date) ;

    }
     else if (stud_id > T ->stud_id){
       T -> right = insert(T -> right , stud_id, stud_name , city , class_id , enr_date) ;

    }
    return T;
}

//FUNCTION TO SEARCH FOR STUDENT BY HIS / HER ID
tree_ptr Find_By_ID(tree_ptr T, int ID) {
    tree_ptr NEW_T = T;

    while (T != NULL) {
        if (ID == T->stud_id) {
            return T;
        }
        else if (ID < T->stud_id) {
            T = T->left;
        }
        else {
            T = T->right;
        }
    }

    return NULL;
}


// FUNCTION TO INSERT THE NAME IN BST , TO USE THIS FUNCTION IN FUNCTION
tree_ptr insert_by_name (tree_ptr T  ){
    char stud_name[1000];
int res;
res = strcmp (stud_name , T ->stud_name);
    if (T == NULL){ // the tree is empty ,make new root
        T=(struct tree_node*)malloc(sizeof(struct tree_node));
        strcpy (T -> stud_name, stud_name);
        T->left=NULL;
        T->right=NULL;
    }
    else if (res<0){
       T -> left = insert_by_name(T -> left ) ;

    }
     else if (res >0 ){
       T -> right = insert_by_name(T -> right ) ;

    }
    return T;
}

// FUNCTION TO TRAVERSE THE BINARY SEARCH TREE IN IN-ORDER
void in_order_traversal(tree_ptr T, void (*visit)(tree_ptr)) {
    if (T != NULL) {
        in_order_traversal(T->left, visit);
        visit(T);
        in_order_traversal(T->right, visit);
    }
}

// FUNCTION TO LIST ALL STUDENTS IN LEXICOGRAPHIC ORDER OF THEIR NAMES
void LIST_S_NAME(tree_ptr T) {
if (T == NULL) {
printf("No students in the list.\n");
return;
}
// Count the number of students in the list
int count = 0;
tree_ptr current = T;
while (current != NULL) {
    count++;
    current = current->right;
}

// Allocate an array to store the student names
char (*names)[MAX_NAME_LEN] = malloc(sizeof(char[MAX_NAME_LEN]) * count);

// Traverse the tree and copy the student names to the array
int index = 0;
void copy_name(tree_ptr node) {
    strcpy(names[index], node->stud_name);
    index++;
}
in_order_traversal(T, copy_name);

// Sort the array of student names in lexicographic order
qsort(names, count, MAX_NAME_LEN, strcmp); // name : first index in array , count : size of the array , MAX : byt of names , strcmp : to compare between two string , qsort : to sort the array

// Print the sorted list of student names
printf("List of students in lexicographic order of their names:\n");
for (int i = 0; i < count; i++) {
    printf("%s\n", names[i]);
}

// Free the memory allocated for the array of student names
free(names);
}
void  SEARCH_BY_CITY(tree_ptr T, char* city []) {

    if (T != NULL) {
         SEARCH_BY_CITY(T->left, city);
        if (strcmp(T->city, city) == 0) {

            printf("STUDENT ID : %d , STUDENT NAME : %s , CITY : %s , CLASS ID : %d , DATE : %s \n", T ->stud_id , T ->stud_name , T ->city , T->class_id , T ->enr_date);
        }
         SEARCH_BY_CITY(T->right, city);
    }

}

void LIST_BY_CLASS(tree_ptr T, int classID) {
    if (T != NULL) {
        LIST_BY_CLASS(T->left, classID);
        if (T ->class_id == classID) {
            printf("%s\n", T->stud_name);
        }
        LIST_BY_CLASS(T->right, classID);
    }
}

//FUNCTION TO FIND THE MINMUM NUMBER FROM THE RIGHT OF THE ROOT
tree_ptr MIN (tree_ptr T ){ //HER WE WELL INSERT JUST THE RIGHT OF THE ROOT
    if (T != NULL){ // TREE IS EMPTY
        return NULL;
    }
    else {
        if ( T -> left == NULL){ // FOUND THE MINMUM NUBER IN RIGHT
            return T;
        }
        else
            return (MIN ( T ->left));
    }
}

//FUNCTION TO FIND THE MAXMUM NUMBER FROM THE LEFT OF THE ROOT
tree_ptr MAX (tree_ptr T ){ //HER WE WELL INSERT JUST THE LEFT OF THE ROOT

 if ( T == NULL ){
        return NULL;
    }
    else {
        if ( T -> right == NULL){ // FOUND THE MAXMUM NUBER IN LEFT
            return T;
        }
        else
            return (MAX ( T ->right));
    }
}

// FUNCTION TO DELETE THE STUDENT BY HIS / HER ID
tree_ptr DELETE_BY_ID ( tree_ptr T , int stud_id){
    tree_ptr cell , child;
    if ( T == NULL){
        printf("TREE IS EMPTY");
    }
    else if ( stud_id < T -> stud_id ){ // in case the node does not have children
        T -> left = DELETE_BY_ID ( T -> left , stud_id );
    }
    else if ( stud_id > T -> stud_id ){
        T -> right = DELETE_BY_ID ( T -> right , stud_id );
    }
    else if (T -> left && T -> right ){ // IF ( T -> left != NULL and T -> right != NULL)
        cell = MIN(T ->right);
        T -> stud_id = cell -> stud_id;
        T ->right = DELETE_BY_ID ( T -> right , T -> stud_id );
    }
    else{
        cell = T;
        if(T -> left == NULL){
            child = T -> right;
        }
        if (T -> right == NULL){
            child = T -> left;
        }
        free (cell);
        return child;
    }
    return T;
}




// FUNCTION TO SAVE ALL STUDENT IN FILE , TRAVERSAL (IN ORDER)
void traversal(tree_ptr T, FILE *fptr) {
    if (T == NULL)
        return;
    traversal(T->left, fptr);
    fprintf(fptr, "%d %s %s %d %s\n", T->stud_id, T->stud_name, T->city, T->class_id, T->enr_date);
    traversal(T->right, fptr);
}

// print the menu
void PRINT_MENU (){
    printf ("1- Insert a student with all its associated data. \n");
    printf("2- Find student by his / her student ID. \n ");
    printf ("3- List all student in lexicographic order of their names.\n");
    printf ("4- Search for a city and list all student from that city in lexicographic order of their names.\n");
    printf ("5- List all student by their class in lexicographic order of their name. \n");
    printf ("6- Delete a student given his / here student ID. \n");
    printf ("7- Save all student in file. \n");
    printf ("8- Exit. \n");
}

int main()
{
    tree_ptr T = NULL;
     int stud_id, class_id;
                char stud_name[1000], city[1000], enr_date[1000];

    while (1) {
        int choice;
        printf("Enter your choice:\n");
        PRINT_MENU();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {


                printf("Enter student ID: ");
                scanf("%d", &stud_id);
                printf("Enter student name: ");
                scanf("%s", stud_name);
                printf("Enter city: ");
                scanf("%s", city);
                printf("Enter class ID: ");
                scanf("%d", &class_id);
                printf("Enter enrollment date: ");
                scanf("%s", enr_date);

                T = insert(T, stud_id, stud_name, city, class_id, enr_date);
                printf("Student inserted successfully.\n");
                break;
            }
            case 2: {

                       int stud_id;
                printf("Enter student ID: ");
                scanf("%d", &stud_id);
                tree_ptr result = Find_By_ID(T, stud_id);
                if (result != NULL) {
                    printf("STUDENT ID : %d , STUDENT NAME : %s , CITY : %s , CLASS ID : %d , DATE : %s \n", result->stud_id, result->stud_name, result->city, result->class_id, result->enr_date);
                }
                else {
                    printf("Student not found\n");
                }


                break;
            }
            case 3: {
                printf("List of students in lexicographic order of their names:\n");
                LIST_S_NAME(T);
                break;
            }
            case 4: {
                printf("Search for a city and list all student from that city in lexicographic order of their names.\n");
                printf("Please enter the name of the city: ");
                scanf("%s", city);

                SEARCH_BY_CITY(T, city);
                break;
            }
            case 5: {
                printf("pleas enter the calss id \n");
                scanf("%d", class_id);
                LIST_BY_CLASS(T,class_id);
                break;
            }
            case 6: {
                int ID;
                printf("Enter student ID: ");
                scanf("%d", &ID);
                T = DELETE_BY_ID(T, ID);
                printf("Student deleted successfully.\n");
                break;
            }
            case 7: {
                FILE *INP;
                INP = fopen("students.txt", "w");
                if (INP == NULL) {
                    printf("Error opening file.\n");
                    return 1;
                }
                traversal(T, INP);
                fclose(INP);
                printf("All students saved in file successfully.\n");
                break;
            }
            case 8: {
                printf("Exiting program...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
