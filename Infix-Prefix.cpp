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
		if (!isempty()){
			return data[top];
		}
	}
	void push(char input){
		if (!isfull()){
			top++;
			data[top] = input;
		}
	}
	char pop(){
		if (!isempty()){
			top--;
			return data[top+1];
		}
	}
	void hapus(){
		if (!isempty()){
			top--;
		}
	}
	bool isempty(){
		if (top == -1)
			return true;
		else return false;
	}
	bool isfull(){
		if (top == max - 1)
			return true;
		else return false;
	}
	int re(int pos){
		if (pos >= 0 && pos <= top)
			return data[pos];
	}
};

void main(){
	stack opr;
	char in[max], rev[max];
	cin >> in;
	int c = strlen(in) - 1, r = 0;
	while (in[c] >= 0){
		if (in[c] == '^'){
			if (opr.gettop() == '^'){
				while (opr.gettop() != ')' && opr.isempty()){
					rev[r] = opr.pop();
					r++;
				}
				opr.push(in[c]);
			}
			else if (opr.gettop() == '^'){
				rev[r] = opr.pop();
				r++;
				opr.push(in[c]);
			}
			else
				opr.push(in[c]);
		}
		if (in[c] == '*'){
			if (opr.gettop() == '+' || opr.gettop() == '-' || opr.gettop() == '*' || opr.gettop() == '/')
				opr.push(in[c]);
			else {
				while (opr.gettop() != ')' && !opr.isempty())
				if (opr.gettop() == '^'){
					rev[r] = opr.pop();
					r++;
				}
				else
					break;
				if (opr.gettop() == ')')
					opr.hapus();
				opr.push(in[c]);
			}
		}
		if (in[c] == '/'){
			if (opr.gettop() == '+' || opr.gettop() == '-' || opr.gettop() == '*' || opr.gettop() == '/'){
				opr.push(in[c]);
			}
			else {
				while (opr.gettop() != ')' && !opr.isempty())
				if (opr.gettop() == '^'){
					rev[r] = opr.pop();
					r++;
				}
				else
					break;
				if (opr.gettop() == ')')
					opr.hapus();
				opr.push(in[c]);
			}
		}
		if (in[c] == '+'){
			if (opr.isempty() || opr.gettop() == ')' || opr.gettop() == '+' || opr.gettop() == '-')
				opr.push(in[c]);
			else {
				while (opr.gettop() != ')' && !opr.isempty())
				if (opr.gettop() == '*' || opr.gettop() == '/' || opr.gettop() == '^'){
					rev[r] = opr.pop();
					r++;
				}
				else
					break;
				opr.push(in[c]);
			}
		}
		if (in[c] == '-'){
			if (opr.isempty() || opr.gettop() == ')' || opr.gettop() == '+' || opr.gettop() == '-')
				opr.push(in[c]);
			else {
				while (opr.gettop() != ')' && !opr.isempty())
				if (opr.gettop() == '*' || opr.gettop() == '/' || opr.gettop() == '^'){
					rev[r] = opr.pop();
					r++;
				}
				else
					break;
				opr.push(in[c]);
			}
		}
		if (in[c] == ')')
			opr.push(in[c]);
		if (in[c] == '('){
			while (opr.gettop() != ')' && !opr.isempty()){
				rev[r] = opr.pop();
				r++;
			}
			if (opr.gettop() == ')')
				opr.hapus();
		}
		if (in[c] >= 65 && in[c] <= 91){
			rev[r] = in[c];
			r++;
		}
		c--;
	}
	while (!opr.isempty()){
		rev[r] = opr.pop();
		r++;
	}
	rev[r] = '\0';
	strrev(rev);
	cout << rev;
	puts("");
}