#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
	char studentName[256];
	float mathGrade;
	float englishGrade;
	float historyGrade;
public:
	const char* GetStudentName() const;
	float GetMathGrade() const;
	float GetEnglishGrade() const;
	float GetHistoryGrade() const;
	float ComputeAverage() const;
	void SetStudentName(const char* nameValue);
	void SetMathGrade(float gradeValue);
	void SetEnglishGrade(float gradeValue);
	void SetHistoryGrade(float gradeValue);
};

#endif // !STUDENT_H