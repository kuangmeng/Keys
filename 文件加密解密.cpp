#include <iostream>
#include <string.h>
#include<cmath>
#include<fstream>
#include<stack>
#include<iomanip> 
#define Max 5
#define MAXLENGTH 1000
using namespace std;
ofstream out("output.txt",ios::app);
char MorseCode[][Max] = {
	".-","-...","-.-.","-..",".","..-.","--.",
	"....","..",".---","-.-","-..","--","-.",
	"---",".--.","--.-",".-.","...","-","..-",
	"...-",".--","-..-","-.--","--.."
};
char CharRate[26] = { 'e','t','a','o','i','n','r','s','h','d','c','l','m','p','u','f','g','w','y','b','k','j','v','x','q','z' };
int GetIndex(int CharNum[][2],char chr) {
	for (int i = 0; i < 26; i++) {
		if (chr - 97 == CharNum[i][0]) return i;
	}
	return -1;
}
int GetIndex(char CharRate[], char chr) {
	for (int i = 0; i < 26; i++){
		if (chr== CharRate[i]) return i;
	}
	return -1;
}
//Ƶ�ʷ�����
void FrequencyCode(char OriginalCode[]){
	char  DecryptCode[MAXLENGTH];
	cout << "\n**************************************************\n";
	cout << "***         ��ӭʹ��Ƶ�ʷ������ܳ���           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         ��ӭʹ��Ƶ�ʷ������ܳ���           ***" << endl;
	out << "**************************************************\n";
	int num = strlen(OriginalCode);
	int CharFrequency[26] = {0};
	int CharNum[26][2];
	for (int i = 0; i < num; i++) {
		CharFrequency[OriginalCode[i] - 97]++;
	}
	for (int j = 0; j < 26; j++) {
		CharNum[j][1] = CharFrequency[0];
		CharNum[j][0] = 0;
		for (int i = 0; i < 26; i++){
			if (CharFrequency[i] > CharNum[j][1]) {
				CharNum[j][1] = CharFrequency[i];
				CharNum[j][0] = i;
			}
		}
		CharFrequency[CharNum[j][0]] = 0;
	}
	cout << "���ܺ����Ϊ��";
	out << "���ܺ����Ϊ��";
	for (int i = 0; i < num; i++){
		if ((OriginalCode[i] >= 'a' &&OriginalCode[i] <= 'z') || (OriginalCode[i] >= 'A' && OriginalCode[i] <= 'Z')) {
			cout << CharRate[GetIndex(CharNum, OriginalCode[i])];
			out << CharRate[GetIndex(CharNum, OriginalCode[i])];
			OriginalCode[i] = CharRate[GetIndex(CharNum, OriginalCode[i])];
		}
		else {
			cout << OriginalCode[i];
			out << OriginalCode[i];
			OriginalCode[i] = OriginalCode[i];
		}
	}
	cout << "\n**************************************************\n";
	cout << "���½��ܺ���룺";
	out << "\n**************************************************\n";
	out << "���½��ܺ���룺";
	for (int i = 0; i < num; i++) {
		if ((OriginalCode[i] >= 'a' &&OriginalCode[i] <= 'z')) {
			cout << (char)(CharNum[GetIndex(CharRate, OriginalCode[i])][0]+97);
			out << (char)(CharNum[GetIndex(CharRate, OriginalCode[i])][0] + 97);
		}
		else {
			cout << OriginalCode[i];
			out << OriginalCode[i];
		}
	}
	cout << "\n**************************************************\n";
	out << "\n**************************************************\n";
}
//դ����λ��
void FenceCode(char OriginalCode[]) {
	char ObjectiveCode[MAXLENGTH];
	cout << "\n**************************************************\n";
	cout << "***         ��ӭʹ��դ����λ���ܳ���           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         ��ӭʹ��դ����λ���ܳ���           ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	int center;
	if (num % 2 == 0) center = num / 2;
	else center = num / 2 + 1;
	for (int i = 0; i < num; i++) {
		if (i % 2 == 0) 	ObjectiveCode[i] = OriginalCode[i / 2];
		else ObjectiveCode[i] = OriginalCode[center + i / 2];
	}
	cout << "���ܺ����Ϊ��";
	out << "���ܺ����Ϊ��";
	for (int i = 0; i < num; i++) {
		OriginalCode[i] = ObjectiveCode[i];
		cout << ObjectiveCode[i];
		out << ObjectiveCode[i];
	}
	cout<< "\n**************************************************\n";
	cout << "���ܺ����Ϊ��";
	out << "\n**************************************************\n";
	out << "���ܺ����Ϊ��";
	for (int i = 0; i < num; i++) {
		if (i % 2 == 0) {
			cout << OriginalCode[i];
			out << OriginalCode[i];
		}
	}
	for (int i = 0; i < num; i++) {
		if (i % 2 != 0) {
			cout << OriginalCode[i];
			out << OriginalCode[i];
		}
	}
	cout << "\n**************************************************\n";
	out << "\n**************************************************\n";
}
//��������
void CaesarCode(char OriginalCode[]){
	char  DecryptCode[MAXLENGTH];
	int key;
	cout << "\n**************************************************\n";
	cout << "***         ��ӭʹ�ÿ���������ܳ���           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         ��ӭʹ�ÿ���������ܳ���           ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	cout << "��������Կ��";
	cin >> key;
	out << "�������Կ��"<<key<<endl;
	cout << "**************************************************\n";
	out << "**************************************************\n";
	key %= 26;
	for (int t = 0; t < num; t++){
		if((OriginalCode[t]>='a' && OriginalCode[t]<='z'))
		         OriginalCode[t] = (OriginalCode[t] - 'a' + key) % 26 + 'a';
	}
	cout << "���ܺ��ı���";
	out << "���ܺ��ı���";
	for (int i = 0; i < num; i++) {
		cout<<OriginalCode[i];
		out << OriginalCode[i];
	}
	cout << "\n**************************************************\n";
	out << "\n**************************************************\n";
	for (int t = 0; t< num; t++){
		if ((OriginalCode[t] >= 'a' && OriginalCode[t]<='z')) {
			if (OriginalCode[t] - 'a' - key < 0) {
				DecryptCode[t] = OriginalCode[t] - key + 26;
			}
			else {
				DecryptCode[t] = OriginalCode[t] - key;
			}
		}
		else  DecryptCode[t] = OriginalCode[t];
	}
	cout << "���½��ܺ��ı���";
	out << "���½��ܺ��ı���";
	for (int i = 0; i < num; i++) {
		cout << DecryptCode[i];
		out << DecryptCode[i];
	}
	cout << "\n**************************************************\n";
	out << "\n**************************************************\n";
}
void ViolenceCaesarCode(char OriginalCode[]) {
	char  DecryptCode[MAXLENGTH];
	int key=0;
	cout << "\n**************************************************\n";
	cout << "***         ��ӭʹ�ÿ����������ܳ���           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         ��ӭʹ�ÿ����������ܳ���           ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	cout << "���ܺ��ı���" << endl;
	out << "���ܺ��ı���" << endl;
	for (int i = 0; i<26; i++) {
		for (int t = 0; t<num; t++) {
			if ((OriginalCode[t] >= 'a' && OriginalCode[t]<='z') || (OriginalCode[t]>='A' && OriginalCode[t] <= 'Z'))
			      DecryptCode[t] = (OriginalCode[t] - 'a' + i % 26) % 26 + 'a';
			else  DecryptCode[t] = OriginalCode[t];
		}
		key++;
		cout<<" No."<<setw(3)<<key<<" ���ƽ����Ϊ��";
		out << " No." << setw(3) << key << " ���ƽ����Ϊ��";
		for (int j = 0; j < num; j++) {
			cout << DecryptCode[j];
			out << DecryptCode[j];
		}
		cout << endl;
		out << endl;
	}
	cout << "\n**************************************************\n";
	out << "\n**************************************************\n";
}
void CaesarCodeUpgrand(char OriginalCode[]) {
	char Code[MAXLENGTH];
	char ObjectiveCode[MAXLENGTH];
	int key[26];
	cout << "\n**************************************************\n";
	cout << "***         ��ӭʹ�������������ܳ���           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         ��ӭʹ�������������ܳ���           ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	cout << "������ÿ����ĸ��Ӧ����Կ��";
	out << "ÿ����ĸ��Ӧ����Կ��";
	for (int i = 0; i < 26; i++) {
		cin >> key[i];
		out << setw(3)<<key[i];
		key[i] %= 26;
	}
	cout << "\n**************************************************\n";
	out << "**************************************************\n";
	for (int t = 0; t < num; t++){
		ObjectiveCode[t] = OriginalCode[t];
		if ((OriginalCode[t]>='a' && OriginalCode[t]<='z'))
			OriginalCode[t] = (OriginalCode[t] - 'a' + key[OriginalCode[t]-'a']) % 26 + 'a';
	}
	cout << "���ܺ��ı�Ϊ��";
	out << "���ܺ��ı�Ϊ��";
	for (int i = 0; i < num; i++) {
		cout << OriginalCode[i];
		out << OriginalCode[i];
	}
	cout << "\n**************************************************\n";
	out << "\n**************************************************\n";
	for (int t = 0; t< num; t++) {
		if ((OriginalCode[t] >= 'a' && OriginalCode[t]<='z')) {
			if (OriginalCode[t] - 'a' - key[ObjectiveCode[t]-'a'] < 0){
				Code[t] = OriginalCode[t] - key[ObjectiveCode[t]-'a'] + 26;
			}
			else {
				Code[t] = OriginalCode[t] - key[ObjectiveCode[t]-'a'];
			}
		}
		else  Code[t] = OriginalCode[t];
	}
	cout << "�ٴν��ܺ��ı�Ϊ��";
	out << "�ٴν��ܺ��ı�Ϊ��";
	for (int i = 0; i < num; i++){
		cout << Code[i];
		out << Code[i];
	}
	cout << "\n**************************************************\n";
	out << "\n**************************************************\n";
}
//Ħ��˹����
void MorseEncrypt(char OriginalCode[]){
	cout << "\n**************************************************\n";
	cout << "***          ��ӭʹ��Ħ��˹���ܳ���            ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***          ��ӭʹ��Ħ��˹���ܳ���            ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	cout << "���ܺ����Ϊ��"<<endl;
	out << "���ܺ����Ϊ��" << endl;
	for (int t = 0; t < num; t++) {
		if ((OriginalCode[t] >= 'a' && OriginalCode[t]<='z') || (OriginalCode[t]>='A' && OriginalCode[t] <= 'Z')){
			for (int i = 0; i < 5; i++) {
				cout << MorseCode[OriginalCode[t] - 97][i];
				out << MorseCode[OriginalCode[t] - 97][i];
			}
		}
		else {
			cout << "\"" << OriginalCode[t] << "\"";
			out << "\"" << OriginalCode[t] << "\"";
		}
		cout <<"  ";
		out << "  ";
	}
	cout << "\n**************************************************\n";
	out << "\n**************************************************\n";
}
//����ת������
void HexChangeCode(char  OriginalCode[]){
	int  ObjectiveCode[MAXLENGTH];
	int key;
	int numsize[Max];
	cout << "\n**************************************************\n";
	cout << "***         ��ӭʹ�ý���ת�����ܳ���           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         ��ӭʹ�ý���ת�����ܳ���           ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	cout << "��������ת���Ľ��ƣ�";
	out << "��ת���Ľ��ƣ�";
	cin >> key;
	out << key<<endl;
	cout << "**************************************************\n";
	cout << "���ܺ����Ϊ��";
	out << "**************************************************\n";
	out << "���ܺ����Ϊ��";
	for (int i = 0; i < num; i++){
		if (OriginalCode[i] >= 'a' && OriginalCode[i] <= 'z') {
			int char2num = (int)(OriginalCode[i] - 97);
			ObjectiveCode[i] = char2num;
			int t = 0;
			while (char2num != 0){
				numsize[t] = char2num%key;
				char2num /= key;
				t++;
			}
			for (int j = t - 1; j >= 0; j--) {
				if (numsize[j] < 10) {
					cout << numsize[j];
					out << numsize[j];
				}
				else {
					cout << (char)(numsize[j] - 10 + 'A');
					out << (char)(numsize[j] - 10 + 'A');
				}
			}
		}
		else {
			ObjectiveCode[i] = (int)OriginalCode[i]-97;
			cout << "\"" << OriginalCode[i]<< "\"";
			out << "\"" << OriginalCode[i] << "\"";
		}
		cout << "  ";
		out << "  ";
	}
	cout << "\n**************************************************\n";
	cout << "���½��ܺ����Ϊ��";
	out << "\n**************************************************\n";
	out << "���½��ܺ����Ϊ��";
	for (int i = 0; i < num; i++) {
		cout << (char)(ObjectiveCode[i]+97);
		out << (char)(ObjectiveCode[i] + 97);
	}
	cout << "\n**************************************************\n";
	out << "\n**************************************************\n";
}
int main(const int avgc,const char ** argv){
	char OriginalCode[MAXLENGTH];
	//ifstream in("input.txt");
	cout << "**************************************************\n";
	cout << "**                                              **" << endl;
	cout << "**               ******************             **" << endl;
	cout << "**               **���ߣ�������**               **" << endl;
	cout << "**               ******************             **" << endl;
	cout << "**                                              **" << endl;
	cout << "**************************************************\n";
	cout << "**   �����ܣ�                                 **" << endl;
	cout << "**                   1����������                **" << endl;
	cout << "**                   2���Ľ��Ŀ�����            **" << endl;
	cout << "**                   3����������ı����ƽ�      **" << endl;
	cout << "**                   4��դ����λ����            **" << endl;
	cout << "**                   5������ת������            **" << endl;
	cout << "**                   6��Ħ��˹����              **" << endl;
	cout << "**                   7��Ƶ�ʷ�������            **" << endl;
	cout << "**                   ������룡                 **" << endl;
	cout << "**************************************************\n";
	cout << "������������ı���";
	out << "**************************************************\n";
	out << "**                                              **" << endl;
	out << "**               ******************             **" << endl;
	out << "**               **���ߣ�������**               **" << endl;
	out << "**               ******************             **" << endl;
	out << "**                                              **" << endl;
	out << "**************************************************\n";
	out << "**   �����ܣ�                                 **" << endl;
	out << "**                   1����������                **" << endl;
	out << "**                   2���Ľ��Ŀ�����            **" << endl;
	out << "**                   3����������ı����ƽ�      **" << endl;
	out << "**                   4��դ����λ����            **" << endl;
	out << "**                   5������ת������            **" << endl;
	out << "**                   6��Ħ��˹����              **" << endl;
	out << "**                   7��Ƶ�ʷ�������            **" << endl;
	out << "**                   ������룡                 **" << endl;
	out << "**************************************************\n";
	out << "�������ı���";
	gets(OriginalCode);
	int num2 = strlen(OriginalCode);
	for (int i = 0; i < num2; i++) {
		out << OriginalCode[i];
	}
	out << endl;
	cout << "��ѡ�������������";
	out << "ѡ��������������";
	int num;
	cin >> num;
	out << num;
	getchar();
	stack<int> heap;
	int i = 0;
	while (num > 0){
		heap.push(num % 10);
		i++;
		num /= 10;
	}
	for (int j = 0; j <i; j++) {
		num += heap.top()*pow(10, j);
		heap.pop();
	}
	while (num > 0) {
		switch (num%10){
		case 1:
			CaesarCode(OriginalCode);
			break;
		case 2:
			CaesarCodeUpgrand(OriginalCode);
			break;
		case 3:
			ViolenceCaesarCode(OriginalCode);
			break;
		case 4:
			FenceCode(OriginalCode);
			break;
		case 5:
			HexChangeCode(OriginalCode);
			break;
		case 6:
			MorseEncrypt(OriginalCode);
			break;
		case 7:
			FrequencyCode(OriginalCode);
			break;
		default:
			break;
		}
		num /= 10;
	}
	system("pause");
	return 0;
}



