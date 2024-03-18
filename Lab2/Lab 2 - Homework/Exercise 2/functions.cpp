#include <cstring>
#include "Student.h"
#include "functions.h"

int CompareStudentsNames(Student s1, Student s2)
{
	int comparison = strcmp(s1.GetStudentName(), s2.GetStudentName());
	if (comparison == 0) { // Students' names are equal
		return comparison;
	}
	else if (comparison > 0) { // Student s1's name is higher in order (lexicographically)
		return 1;
	} 
	else { // Student s2's name is higher in order
		return -1;
	}
}

int CompareStudentsMathGrades(Student s1, Student s2) {
	float grade1 = s1.GetMathGrade();
	float grade2 = s2.GetMathGrade();
	if (grade1 == grade2) {
		return 0;
	}
	else if (grade1 > grade2) {
		return 1;
	}
	else {
		return -1;
	}
}

int CompareStudentsHistoryGrades(Student s1, Student s2) {
	float grade1 = s1.GetHistoryGrade();
	float grade2 = s2.GetHistoryGrade();
	if (grade1 == grade2) {
		return 0;
	}
	else if (grade1 > grade2) {
		return 1;
	}
	else {
		return -1;
	}
}

int CompareStudentsEnglishGrades(Student s1, Student s2) {
	float grade1 = s1.GetEnglishGrade();
	float grade2 = s2.GetEnglishGrade();
	if (grade1 == grade2) {
		return 0;
	}
	else if (grade1 > grade2) {
		return 1;
	}
	else {
		return -1;
	}
}

int CompareStudentsGradesAverage(Student s1, Student s2) {
	float grade1 = s1.ComputeAverage();
	float grade2 = s2.ComputeAverage();
	if (grade1 == grade2) {
		return 0;
	}
	else if (grade1 > grade2) {
		return 1;
	}
	else {
		return -1;
	}
}