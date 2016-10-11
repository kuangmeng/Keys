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
//频率分析法
void FrequencyCode(char OriginalCode[]){
	char  DecryptCode[MAXLENGTH];
	cout << "\n**************************************************\n";
	cout << "***         欢迎使用频率分析加密程序           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         欢迎使用频率分析加密程序           ***" << endl;
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
	cout << "加密后编码为：";
	out << "加密后编码为：";
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
	cout << "重新解密后编码：";
	out << "\n**************************************************\n";
	out << "重新解密后编码：";
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
//栅栏移位法
void FenceCode(char OriginalCode[]) {
	char ObjectiveCode[MAXLENGTH];
	cout << "\n**************************************************\n";
	cout << "***         欢迎使用栅栏移位加密程序           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         欢迎使用栅栏移位加密程序           ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	int center;
	if (num % 2 == 0) center = num / 2;
	else center = num / 2 + 1;
	for (int i = 0; i < num; i++) {
		if (i % 2 == 0) 	ObjectiveCode[i] = OriginalCode[i / 2];
		else ObjectiveCode[i] = OriginalCode[center + i / 2];
	}
	cout << "加密后编码为：";
	out << "加密后编码为：";
	for (int i = 0; i < num; i++) {
		OriginalCode[i] = ObjectiveCode[i];
		cout << ObjectiveCode[i];
		out << ObjectiveCode[i];
	}
	cout<< "\n**************************************************\n";
	cout << "解密后编码为：";
	out << "\n**************************************************\n";
	out << "解密后编码为：";
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
//凯撒密码
void CaesarCode(char OriginalCode[]){
	char  DecryptCode[MAXLENGTH];
	int key;
	cout << "\n**************************************************\n";
	cout << "***         欢迎使用凯撒密码加密程序           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         欢迎使用凯撒密码加密程序           ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	cout << "请输入秘钥：";
	cin >> key;
	out << "输入的秘钥："<<key<<endl;
	cout << "**************************************************\n";
	out << "**************************************************\n";
	key %= 26;
	for (int t = 0; t < num; t++){
		if((OriginalCode[t]>='a' && OriginalCode[t]<='z'))
		         OriginalCode[t] = (OriginalCode[t] - 'a' + key) % 26 + 'a';
	}
	cout << "加密后文本：";
	out << "加密后文本：";
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
	cout << "重新解密后文本：";
	out << "重新解密后文本：";
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
	cout << "***         欢迎使用凯撒暴力解密程序           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         欢迎使用凯撒暴力解密程序           ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	cout << "加密后文本：" << endl;
	out << "加密后文本：" << endl;
	for (int i = 0; i<26; i++) {
		for (int t = 0; t<num; t++) {
			if ((OriginalCode[t] >= 'a' && OriginalCode[t]<='z') || (OriginalCode[t]>='A' && OriginalCode[t] <= 'Z'))
			      DecryptCode[t] = (OriginalCode[t] - 'a' + i % 26) % 26 + 'a';
			else  DecryptCode[t] = OriginalCode[t];
		}
		key++;
		cout<<" No."<<setw(3)<<key<<" 种破解代码为：";
		out << " No." << setw(3) << key << " 种破解代码为：";
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
	cout << "***         欢迎使用升级凯撒加密程序           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         欢迎使用升级凯撒加密程序           ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	cout << "请输入每个字母对应的秘钥：";
	out << "每个字母对应的秘钥：";
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
	cout << "加密后文本为：";
	out << "加密后文本为：";
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
	cout << "再次解密后文本为：";
	out << "再次解密后文本为：";
	for (int i = 0; i < num; i++){
		cout << Code[i];
		out << Code[i];
	}
	cout << "\n**************************************************\n";
	out << "\n**************************************************\n";
}
//摩尔斯密码
void MorseEncrypt(char OriginalCode[]){
	cout << "\n**************************************************\n";
	cout << "***          欢迎使用摩尔斯加密程序            ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***          欢迎使用摩尔斯加密程序            ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	cout << "加密后编码为："<<endl;
	out << "加密后编码为：" << endl;
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
//进制转化密码
void HexChangeCode(char  OriginalCode[]){
	int  ObjectiveCode[MAXLENGTH];
	int key;
	int numsize[Max];
	cout << "\n**************************************************\n";
	cout << "***         欢迎使用进制转化加密程序           ***" << endl;
	cout << "**************************************************\n";
	out << "\n**************************************************\n";
	out << "***         欢迎使用进制转化加密程序           ***" << endl;
	out << "**************************************************\n";
	int num = (int)strlen(OriginalCode);
	cout << "请输入想转化的进制：";
	out << "想转化的进制：";
	cin >> key;
	out << key<<endl;
	cout << "**************************************************\n";
	cout << "加密后编码为：";
	out << "**************************************************\n";
	out << "加密后编码为：";
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
	cout << "重新解密后编码为：";
	out << "\n**************************************************\n";
	out << "重新解密后编码为：";
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
	cout << "**               **作者：匡盟盟**               **" << endl;
	cout << "**               ******************             **" << endl;
	cout << "**                                              **" << endl;
	cout << "**************************************************\n";
	cout << "**   程序功能：                                 **" << endl;
	cout << "**                   1、凯撒密码                **" << endl;
	cout << "**                   2、改进的凯撒密            **" << endl;
	cout << "**                   3、凯撒密码的暴力破解      **" << endl;
	cout << "**                   4、栅栏移位密码            **" << endl;
	cout << "**                   5、进制转化密码            **" << endl;
	cout << "**                   6、摩尔斯密码              **" << endl;
	cout << "**                   7、频率分析密码            **" << endl;
	cout << "**                   组合密码！                 **" << endl;
	cout << "**************************************************\n";
	cout << "请输入待加密文本：";
	out << "**************************************************\n";
	out << "**                                              **" << endl;
	out << "**               ******************             **" << endl;
	out << "**               **作者：匡盟盟**               **" << endl;
	out << "**               ******************             **" << endl;
	out << "**                                              **" << endl;
	out << "**************************************************\n";
	out << "**   程序功能：                                 **" << endl;
	out << "**                   1、凯撒密码                **" << endl;
	out << "**                   2、改进的凯撒密            **" << endl;
	out << "**                   3、凯撒密码的暴力破解      **" << endl;
	out << "**                   4、栅栏移位密码            **" << endl;
	out << "**                   5、进制转化密码            **" << endl;
	out << "**                   6、摩尔斯密码              **" << endl;
	out << "**                   7、频率分析密码            **" << endl;
	out << "**                   组合密码！                 **" << endl;
	out << "**************************************************\n";
	out << "待加密文本：";
	gets(OriginalCode);
	int num2 = strlen(OriginalCode);
	for (int i = 0; i < num2; i++) {
		out << OriginalCode[i];
	}
	out << endl;
	cout << "请选择生成密码程序：";
	out << "选择的生成密码程序：";
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



