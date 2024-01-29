#include "RPN.hpp"

// int check_(std::string str){
	
// 	if (str[0] != ' ' && !isdigit(str[0]) && str[0] != '*'
// 		&& str[0] != '+' && str[0] != '-' && str[0] != '/')
// 			return 0;
// }
int calcul(int a, int b, char c){
	if (c == '*')
		return (a * b);
	else if (c == '+')
		return (a + b);
	else if (c == '/')
		return (a / b);
	else if (c == '-')
		return (a - b);
	return 0;
}
void rpn(std::string s){
	std::stack <int> stk;
	std::istringstream inp(s);
	std::string str;
	while(inp >> str){
		if(str.length() != 1)
			throw std::runtime_error("Error");
		if (!isdigit(str[0]) && str[0] != '*'
			&& str[0] != '+' && str[0] != '-' && str[0] != '/')
				throw std::runtime_error("Error");
		if (str[0] != '*' && str[0] != '+' && str[0] != '-' && str[0] != '/')
			stk.push(std::atoi(str.c_str()));
		else{
			if(stk.size() > 1){
				int top1 = stk.top();
				stk.pop();
				int top2 = stk.top();
				stk.pop();
				// std::cout << top1 << "****"<< top2 << std::endl;
				stk.push(calcul(top2, top1, str[0]));
			}
		}
	}
	if(stk.size() > 1)
		throw std::runtime_error("Error");
	std::cout << stk.top() << std::endl;
}