#include "Userfile.h"
Userfile::Userfile() {

}

Userfile::Userfile(QString userName, QString userPass) {
	name = new QString(userName);
	password = new QString(userPass);
	filename = new QString(QString("./Data/") + name + QString(".txt"));//���·��
	userData = new QFile(*filename);
	input = new QTextStream(userData);
	output = new QTextStream(userData);

	for (int i = 0; i < ALL; i++) {
		score[i] = 0;
	}
}

Userfile::~Userfile() {

}

//�ӵ�¼�û��ļ���ȡ�û���
std::string Userfile::inputName() {
	userData->open(QIODevice::ReadOnly | QIODevice::Text);

	QString tempName;
	tempName = input->readLine();
	std::string inName(tempName.toLatin1());

	userData->close();

	return inName;
}

//�ӵ�¼�û��ļ���ȡ�û�����
std::string Userfile::inputPass() {
	QString tempPass;

	tempPass = input->readLine();
	std::string inPass(tempPass.toLatin1());

	userData->close();

	return inPass;
}

//��ע���û��ļ�����û���������
void Userfile::outputInfo() {
	userData->open(QIODevice::WriteOnly);

	*output << name << endl;
	*output << password << endl;
	userData->close();

}

int Userfile::getScore(int level) {
	QString temp;

	userData->open(QIODevice::ReadWrite);

	int i = 0;
	input->readLine();//���û���
	input->readLine();//������
	while (!input->atEnd()) {
		input->readLine();//�Ȱѹ�������
		temp = input->readLine();
		score[i] = temp.toInt();//ÿ�صķ���������
		i++;
	}

	userData->close();

	return score[level - 1];
}

void Userfile::saveScore(int level, int newScore) {//����Ҫ������һ��newScore

	QString temp;
	//levelList[level - 1] = level;
	int preBest = getScore(level);
	//if ((preBest != 0) && (preBest > newScore)) 
	if ((preBest == 0)||(preBest != 0) && (preBest > newScore))
	{   //��һ�����ʱ��preBest��0
		score[level - 1] = newScore;
		userData->open(QIODevice::WriteOnly|QIODevice::Text);//Textģʽ�Դ�����

		*output << *name << endl;
		*output << *password << endl;

		int i = 0;//newScore��ôд�룿
		while (score[i] > 0) {
			*output << QString(QString::number(i + 1)) << endl;//ÿ�ζ�����дһ��֮ǰ�����йأ���һ�д�level
			*output << QString(QString::number(score[i])) << endl;
			i++;
		}
		//userData->qclear();
		userData->close();
	}
}

int Userfile::getLevel() {
	userData->open(QIODevice::ReadOnly | QIODevice::Text);
	int level = 0;
	input->readLine();//���û���
	input->readLine();//������
	while (!input->atEnd()) {
		QString temp;
		temp=input->readLine();//����ÿ�����У�level+1���õ��ľ��ǵ�ǰ���level
		level = temp.toInt();
		input->readLine();
		//level++;
	}
	return (level);
}
	