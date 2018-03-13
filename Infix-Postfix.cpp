#include<iostream>
using namespace std;
#define max 255

class stack{
	char data[max], top;
public:
	stack(){
		top = -1;
	}
	char gettop(){
		if (top>-1){
			return data[top];
		}
	}
	void push(char input){
		if (!isfull()){
			top++;
			data[top] = input;
		}
	}
	void pop(){
		if (!isempty()){
			cout << data[top];
			top--;
		}
	}
	bool isempty(){
		if (top == -1)
			return true;
		else return false;
	}
	bool isfull(){
		if (top == max-1)
			return true;
		else return false;
	}
	int re(int pos){
		if (pos>=0&&pos<=top)
		return data[pos];
	}
};

void main(){
	stack opr;
	char in[max];
	cin >> in;
	int c=0;
	while (in[c] != '\0'){
		if (in[c] >= 65 && in[c] <= 91){
			cout << in[c];
		}
		else if (in[c]=='^'){
			if (opr.gettop() == '^'){
				while (opr.gettop() != '(' && opr.isempty())
					opr.pop();
				if (opr.gettop() == '(')
					opr.hapus();
				opr.push(in[c]);
			}
			else if (opr.gettop() == '^'){
				opr.pop();
				opr.push(in[c]);
			}
			else
				opr.push(in[c]);
		}
		else if (in[c] == '*'){
			if (opr.gettop()=='+'||opr.gettop()=='-')
				opr.push(in[c]);
			else if (opr.gettop() == '*' || opr.gettop() == '/'){
				opr.pop();
				opr.push(in[c]);
			}
			else {
				while (opr.gettop() != '(' && !opr.isempty())
					opr.pop();
				if (opr.gettop() == '(')
					opr.hapus();
				opr.push(in[c]);
			}
		}
		else if (in[c] == '/'){
			if (opr.gettop() == '+' || opr.gettop() == '-')
				opr.push(in[c]);
			else if (opr.gettop() == '*' || opr.gettop() == '/'){
				opr.pop();
				opr.push(in[c]);
			}
			else {
				while (opr.gettop() != '(' && !opr.isempty())
					opr.pop();
				if (opr.gettop() == '(')
					opr.hapus();
				opr.push(in[c]);
			}
		}
		else if (in[c] == '+'){
			if(opr.isempty() || opr.gettop()=='(')
					opr.push(in[c]);
			else {
				while (opr.gettop() != '(' && !opr.isempty())
					opr.pop();
				if (opr.gettop() == '(')
					opr.hapus();
				opr.push(in[c]);
			}
		}
		else if (in[c] == '-'){
			if (opr.isempty() || opr.gettop() == '(')
				opr.push(in[c]);
			else {
				while (opr.gettop() != '(' && !opr.isempty())
					opr.pop();
				if (opr.gettop() == '(')
					opr.hapus();
				opr.push(in[c]);
			}
		}
		else if (in[c] == '(')
			opr.push(in[c]);
		else if (in[c] == ')'){
			while (opr.gettop() != '(' && !opr.isempty())
				opr.pop();
			if (opr.gettop() == '(')
				opr.hapus();
		}
		c++;
	}
	while (!opr.isempty()){
		opr.pop();
	}
	puts("");
}
