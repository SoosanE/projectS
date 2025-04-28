//���� #7, 12221487, ������
//Friend.cpp
#include <iostream>
#include<string>
using namespace std;
#include "Friend.h" //������ϰ� ����, can access the class name "Friend"

int Friend::count = 0;
int Friend::getCount() { //count ��ȯ
	return count;
}

Friend::Friend(const string& n, int a, float g, const string& p):name(n),pnumber(p) { //������, string ��ü�� has-a�ϴ� ����
	//setName(n); //��ȿ���˻�
	setAge(a);
	setGPA(g);
	//setPnumber(p);
	setAgeGraph(a);
	count++;
}
Friend::~Friend() { //�Ҹ���
	delete[] bar; //�޸� ��ȯ
	count--;
}
Friend::Friend(const Friend& c) { //���� ������ //age��ŭ�� ������ ��� deep copy
	name = c.name;
	age = c.age;
	gpa = c.gpa;
	pnumber = c.pnumber;
	bar = new char[age + 1];
	for (int i = 0; i <= age; i++) { //deep copy
		bar[i] = c.bar[i];
	}
	count++;
}
void Friend::setName(const string& n) { //modifies private data
	name = (n.length() >= 1 && n.length() <= 10) ? n : "xxx"; //��ȿ�� �˻�
}
string Friend::getName() const{ //access private data
	return name;
}
void Friend::setAge(int a) { //age��ȿ���˻� 
	if (a >= 3 && a <= 40) { //age ��ȿ�� �˻縦 ����ϸ�
		age = a;
		setAgeGraph(a); //���̿� ���� ����׷��� 
	}
	else {
		//cout << "��ȿ�� ���� ������ 20�쿡�� 30���Դϴ�\n";
	}
}
void Friend::setAgeGraph(int a) { //for loop�� ���� ���̸�ŭ *��� 
	age = a;
	bar = new char[age + 1];
	for (int i = 0; i < age; i++) {
		bar[i] = '*';
	}
	bar[age] = '\0';
}
int Friend::getAge() const {
	return age;
}

void Friend::setGPA(float g) {
	gpa = (g >= 0.0 && g <= 4.5) ? g : 0; //��ȿ�� �˻�
}
float Friend::getGPA() const{
	return gpa;
}
void Friend::setPnumber(const string& p) {
	pnumber = (p.length() >= 1 && p.length() <= 11) ? p : "010_0000_0000"; //��ȿ�� �˻�
}
string Friend::getPnumber() const{
	return pnumber;
}
const Friend& Friend::operator=(const Friend& a) { //���� ������
	if (this != &a) { //�ߺ� ����
		delete[] bar;
		age = a.age; //��� ���� ����
		name = a.name;
		gpa = a.gpa;
		pnumber = a.pnumber;
		bar = new char[age + 1]; //�޸� �Ҵ� �� ���빰 ����
		for (int i = 0; i <= age; i++)
			bar[i] = a.bar[i];
	}
	return *this;
}
ostream& operator<<(ostream& out, const Friend& copied) { //��� ������ �����ε�
	out << copied.name << " "; //Friend Ŭ���� ��� ���� ���
	out << copied.age << " ";
	out << copied.gpa << " ";
	out << copied.pnumber << endl;
	for (int i = 0; i < copied.age; i++) { //���̿� ���� ���� �׷��� ���
		out << copied.bar[i];
	}
	out << endl;
	return out;
}
istream& operator>>(istream& in, Friend& copied) { //�Է� ������ �����ε�
	string n; //�⺭ ���� �Է�
	int ag;
	float g;
	string p;
	in >> n >> ag >> g >> p;
	copied.setName(n);
	copied.setAge(ag);
	copied.setGPA(g);
	copied.setPnumber(p);
	return in;
}