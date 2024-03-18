#include <cstring>
#include "Student.h"

const char* Student::GetStudentName() const {
	return studentName;
}

void Student::SetStudentName(const char* nameValue) {
	strcpy_s(studentName, nameValue);
}

float Student::GetMathGrade() const {
	return mathGrade;
}

void Student::SetMathGrade(float gradeValue) {
	if (gradeValue >= 1.0f && gradeValue <= 10.0f) {
		mathGrade = gradeValue;
	}
}

float Student::GetEnglishGrade() const {
	return englishGrade;
}

void Student::SetEnglishGrade(float gradeValue) {
	if (gradeValue >= 1.0f && gradeValue <= 10.0f) {
		englishGrade = gradeValue;
	}
}

float Student::GetHistoryGrade() const {
	return historyGrade;
}

void Student::SetHistoryGrade(float gradeValue) {
	if (gradeValue >= 1.0f && gradeValue <= 10.0f) {
		historyGrade = gradeValue;
	}
}

float Student::ComputeAverage() const {
	return (mathGrade + englishGrade + historyGrade) / 3.0f;
}