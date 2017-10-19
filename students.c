/*
 * This is the file in which you will implement the functionality required by
 * the assignment.  Make sure to add your name and @oregonstate.edu email
 * address below:
 *
 * Name: adnan almarzooq  
 * Email: almaradn@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "students.h"


/*
 * This function should initialize a single student struct with name, ID, and
 * GPA data.
 *
 * Params:
 *   student - a pointer to the student struct to be initialized.  The memory
 *     for this student will already be allocated before the function is
 *     called.  You simply need to fill its values.  When the function returns,
 *     the fields of this student struct should contain the corresponding
 *     values passed in the other arguments.  Note that this function must
 *     allocate space for the name field and copy the value from name into the
 *     newly-allocated name field.  Make sure that if any of the fields of
 *     student already have memory on the heap allocated to them, you free that
 *     memory before overwriting it with new values.
 *   name - a string containing the student's name.  Note that you'll have to
 *     make a copy of this string to store in the student struct instead of
 *     storing this string directly.
 *   id - an integer ID for the student
 *   gpa - the student's GPA
 */
void init_student(struct student* student, char* name, int id, float gpa) {
	char * tempor = malloc(sizeof(char) * (strlen(name) + 1)); //initializing student allocation
	//copying name in temporary
    strcpy(tempor, name);
	//initializing student values
	student->name = tempor;
	student->id = id;
	student->gpa = gpa;
}




/*
 * This function should free the memory allocated by init_student() for a
 * single student.
 *
 * Params:
 *   student - a pointer to the student whose memory should be freed.  Note
 *     that only memory stored *within* this struct should be freed.  The
 *     struct itself should not be freed.
 */
void free_student(struct student* student) {
	//free student name, only dynamic memory array.
	free(student->name);
}



/*
 * This function should make a deep copy of a single student.  A deep copy is
 * a copy where pointer fields don't simply have their values (i.e. the memory
 * addresses they point to) copied, but the pointers are dereferenced and
 * copies made of the values themselves.  In other words, for each pointer
 * field in the object being copied, new memory is allocated for a copy of that
 * field to be created, and a pointer to this newly-allocated memory is stored
 * in the copied object.
 *
 * Params:
 *   student - a pointer to the student to be deep copied
 *
 * Return:
 *   Should return a pointer to a deep copy of student.  Memory for this copy
 *   should be allocated by this function.  This memory will have to be freed
 *   using a combination of free_student() and free().
 */
struct student* deep_copy_student(struct student* student) {
	//malloc student values to be idential with the other (copy) student value
	struct student* identical = malloc(sizeof(struct student));
    identical->name = NULL;
    init_student(identical, student->name, student->id, student->gpa);
	return identical;
}




/*
 * This function should allocate space for an array of student structs and
 * initialize their fields using the provided information.  In particular, you
 * should create an array of student structs where the i'th student has the
 * i'th name, the i'th ID, and the i'th GPA from the arrays provided as
 * arguments.  You should use your init_student() function to perform the
 * initialization of each student in the new array.
 *
 * Params:
 *   num_students - the number of students to be stored in the newly allocated
 *     array
 *   names - an array of the names of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *   ids - an array of the IDs of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *   gpas - an array of the GPAs of the students to be stored in the newly
 *     allocated array of student structs.  This array will have length
 *     num_students.
 *
 * Return:
 *   Should return a pointer to the newly allocated and initialized array of
 *   student structs.  The i'th student in this array should have the i'th
 *   name, the i'th ID, and the i'th GPA from the arrays provided as arguments.
 */
struct student* create_student_array(int num_students, char** names, int* ids,
	float* gpas) {
	struct student* student_array;
	int k;

	student_array = (struct student*)malloc(num_students * sizeof(struct student));

	for (k = 0; k < num_students; ++k)
	{init_student(&student_array[k], names[k], ids[k], gpas[k]);}//creating each student in the list.

	return student_array;

	}


/*
 * This function should free all of the memory allocated to an array of
 * student structs, including the memory allocated to the array itself as
 * well as any memory allocated within the individual student structs.  You
 * should use free_student() to free the memory for each individual student.
 *
 * Params:
 *   students - a pointer to the array of student structs whose memory is to
 *     be freed
 *   num_students - the number of students in the array
 */
void destroy_student_array(struct student* students, int num_students) {
	int k; //k for the loop
	for (k=0; k < num_students; ++k) //loop removing all students.. [one by one]
	{//removes student
		free_student(&students[k]);
	}
	//destroy the whole list.
	free(students);
	
	
	
}


/*
 * This function should print the name, ID, and GPA of each student in an
 * array, one student per line.
 *
 * Params:
 *   students - the array of students to be printed
 *   num_students - the number of students in the array
 */
void print_students(struct student* students, int num_students) {
	int k;
	for(k = 0; k < num_students; ++k) {printf("%s||%d||%f\n", students[k].name, students[k].id, students[k].gpa); // for loop: printing students one by one

}}


/*
 * This function should return a pointer to the student in a given array with
 * the highest GPA.  The pointer returned should be an address within the
 * array itself.  You should not make a copy of the student being returned,
 * i.e. this function should not allocate any memory.
 *
 * Params:
 *   students - the array from which to find the student with the highest GPA
 *   num_students - the number of students in the array
 *
 * Return:
 *   Should return a pointer to the student in the array with the highest GPA.
 *   The pointer returned should be an address within the array itself.  You
 *   should not make a copy of the student being returned.
 */
struct student* find_max_gpa(struct student* students, int num_students) {
	int i;
	int maxi;
	maxi = 0;	
	for (i = 1; i < num_students; ++i) // looping throw all students
	{if (students[i].gpa > students[maxi].gpa)	 //f gpa is higher, takes its I value 
		{maxi = i;}
	}
	//then return student plus I address.
	return (students + maxi);
	
	}


/*
 * This function should return a pointer to the student in a given array with
 * the lowest GPA.  The pointer returned should be an address within the
 * array itself.  You should not make a copy of the student being returned,
 * i.e. this function should not allocate any memory.
 *
 * Params:
 *   students - the array from which to find the student with the lowest GPA
 *   num_students - the number of students in the array
 *
 * Return:
 *   Should return a pointer to the student in the array with the lowest GPA.
 *   The pointer returned should be an address within the array itself.  You
 *   should not make a copy of the student being returned.
 */
struct student* find_min_gpa(struct student* students, int num_students) {
	int mini;
	int i;
	mini = 0;
	for (i = 1; i < num_students; ++i) // looping throw all students
	{if (students[i].gpa < students[mini].gpa){ // same thing max gpa does, this functions does same
			mini = i;}}
	return (students + mini); // same outcome too
}


/*
 * This function should sort students by descending GPA (i.e. highest GPAs
 * at the beginning of the array).  You may implement any sorting algorithm
 * you want, with the following constraints:
 *   - You must sort in place, i.e. you can't allocate additional memory.
 *   - You may not use built-in sorting functions like qsort(), i.e. you must
 *     implement the sort yourself.
 *
 * Params:
 *   students - the array of students to be sorted; when the function returns,
 *     this array will be sorted by descending GPA
 *   num_students - the number of students in the array
 */
void sort_by_gpa(struct student* students, int num_students) { //bubble sort function for listing the 
	int k;
	int i;
	struct student rt;
	//bubble sort function for loop.
	for (i = 0; i < num_students; ++i) { //loops into all students and optimize their places depending on their gpa
		for (k = i + 1; k < num_students; ++k) {// if gpa is higher, put in temp variable struct student, move it up nd past the temp in the previous place
			if (students[k].gpa > students[i].gpa) {
					rt = students[i];
					students[i] = students[k];
					students[k] = rt;
					
		  }
		}
	  }
	}
