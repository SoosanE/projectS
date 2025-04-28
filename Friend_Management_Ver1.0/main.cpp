//���� #7, 12221487, ������
//main.cpp
#include<iostream>
#include<iomanip> //quoted�� setw������ؼ�	
#include<string>
#include<fstream>
#include"Friend.h" //Friend��� class �������
#include"BestFriend.h"//BestFriend��� class �������
using namespace std;
const int MAXNOS = 100;//ģ�� ������ ������ �� �ִ� �迭�� �ִ� ũ�� MAXNO�� 100���� �����ϱ����ؼ�

int readFile(ifstream&, Friend[]); //function prototype
void sorting(Friend[], int);
void outputArray(Friend[], int);

int main() {
	cout << "# of Friends before defining Friend Array= " << Friend::getCount() << endl; //��ü ���� ī���� :0
	Friend myFriends[MAXNOS];
	int noFriends;
	cout << "# of Friends after defining Friend Array= " << Friend::getCount() << endl; //��ü ���� ī����: 100
	cout << "Size of myFriends[] = " << sizeof(myFriends) << endl;
	//������ ���ؼ� ������ �Է�	
	ifstream inFile("testMydude.txt", ios::in);
	if (!inFile) {
		cout << "�Է� ���� ����";
		exit(1);
	}

	noFriends = readFile(inFile, myFriends);
	sorting(myFriends, noFriends);
	//cout << endl << "<< ���� ������ ������ ��� >>" << endl;
	//outputArray(myFriends, noFriends);

	//Friend firstF, secondF, thirdF;
	//firstF = myFriends[0];
	//Friend lastF(myFriends[noFriends - 1]);

	/*cout << "\n�������� �׸� �����Ͽ� �� ���ο� 2���� ģ�� ������ �Է��ϼ���!" << endl;
	cin >> secondF >> thirdF;
	cout << "\n\n ������� �Է��� 2���� ģ�� ���� \n\n" << secondF << thirdF << endl;
	cout << "���ĵ� �迭�� ù ģ���� ������ ģ�� ���� \n\n" << firstF << lastF << endl;
	cout << "# of Friends at the end of main()= " << lastF.getCount() << endl;*/

	BestFriend bF1, bF2;
	cout << "\n�������� �׸� �����Ͽ� 2���� BestFriend ������ �Է��ϼ���! " << endl;
	cin >> bF1 >> bF2;
	cout << "\n\n��� ���� �Է��� 2���� BestFriend ����\n\n" << bF1<<bF2<<endl;

	bF1 = bF2;
	cout << "\n\n������ �θ��� BestFriend ���� \n\n" << bF1 << bF2 << endl;
	cout << "# of Best Friends at the end of main() = " << BestFriend::getBestFriendCount() << endl;
	return 0;
}


int readFile(ifstream& inFile, Friend myFriends[]) {
	int count = 0;
	string name; //�̸� ����
	int age; //���� ����
	float gpa; //gpa ����
	string pnumber; //�޴��� ��ȣ ����
	while (inFile >> name >> age >> gpa >> pnumber) { //���Ϸκ��� ������ �Է¹޴´�.
		myFriends[count].setName(name); //�迭[index]�� �̸� ��ȯ
		myFriends[count].setAge(age);
		myFriends[count].setGPA(gpa);
		myFriends[count].setPnumber(pnumber);
		cout << left << name << ", " << age << ", " << gpa << ", " << pnumber << endl; //�������� �� �������� ���̵��� ���
		count++; //�� array�� �ִ� ���� ������ŭ ���Ͽ��� ������ �д´�.
	}
	return count;
}
//�迭�� �ִ� ������ ���, count�� totalFriends�� ����
void outputArray(Friend myFriends[], int totalFriends) {
	for (int i = 0; i < totalFriends; i++) {
		cout << myFriends[i].getName() << "  ";
		cout << myFriends[i].getAge() << "  ";
		cout << myFriends[i].getGPA() << "  ";
		cout << myFriends[i].getPnumber() << endl;
	}
}
void sorting(Friend myFriends[], int totalFriends) { //���� ���� �Լ�
	Friend curFriend;
	int moveIndex;

	for (int i = 1; i < totalFriends; i++) {
		curFriend = myFriends[i];
		moveIndex = i;
		while ((moveIndex > 0) && (myFriends[moveIndex - 1].getAge() > curFriend.getAge())) {
			myFriends[moveIndex] = myFriends[moveIndex - 1];
			moveIndex--;
		}
		myFriends[moveIndex] = curFriend;
	}
}



