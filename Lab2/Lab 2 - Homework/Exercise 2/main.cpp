#include <iostream>
#include "Student.h"
#include "functions.h"

void displayStudentStats(Student s);
void compareStudents(Student s1, Student s2);

int main() {
	Student s1, s2;
	s1.SetStudentName("Ion Popescu");
	s1.SetEnglishGrade(10);
	s1.SetHistoryGrade(7);
	s1.SetMathGrade(9);
	displayStudentStats(s1);
	s2.SetStudentName("Mihai Georgescu");
	s2.SetEnglishGrade(7);
	s2.SetMathGrade(9);
	s2.SetHistoryGrade(10);
	displayStudentStats(s2);
	compareStudents(s1, s2);
}

void displayStudentStats(Student s) {
	printf("\n===== Student Stats ===== \n");
	printf("Name: %s\n", s.GetStudentName());
	printf("Math Grade: %.2f\n", s.GetMathGrade());
	printf("English Grade: %.2f\n", s.GetEnglishGrade());
	printf("History: %.2f\n", s.GetHistoryGrade());
	printf("Average: %.2f\n", s.ComputeAverage());
}

void compareStudents(Student s1, Student s2) {
	printf("\n===== Comparison Stats ===== \n");
	int studentNamesComparison = CompareStudentsNames(s1, s2);
	int mathComparison = CompareStudentsMathGrades(s1, s2);
	int historyComparison = CompareStudentsHistoryGrades(s1, s2);
	int englishComparison = CompareStudentsEnglishGrades(s1, s2);
	int avgComparison = CompareStudentsGradesAverage(s1, s2);

	printf("Names: ");
	if (studentNamesComparison == 0)
		printf("Both students have the same name\n");
	else if (studentNamesComparison == 1)
		printf("%s is higher in order\n", s1.GetStudentName());
	else
		printf("%s is higher in order\n", s2.GetStudentName());

	printf("Math: ");
	if (mathComparison == 0)
		printf("Both students have the same grades\n");
	else if (mathComparison == 1)
		printf("%s\n", s1.GetStudentName());
	else
		printf("%s\n", s2.GetStudentName());

	printf("English: ");
	if (englishComparison == 0)
		printf("Both students have the same grades\n");
	else if (englishComparison == 1)
		printf("%s\n", s1.GetStudentName());
	else
		printf("%s\n", s2.GetStudentName());
	
	printf("History: ");
	if (historyComparison == 0)
		printf("Both students have the same grades\n");
	else if (historyComparison == 1)
		printf("%s\n", s1.GetStudentName());
	else
		printf("%s\n", s2.GetStudentName());

	printf("Grades Average: ");
	if (avgComparison == 0)
		printf("Both students have the same average grade\n");
	else if (avgComparison == 1)
		printf("%s\n", s1.GetStudentName());
	else
		printf("%s\n", s2.GetStudentName());
}
