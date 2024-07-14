#include <iostream>
#include <stack>

int precedence_of_operators (char op);
std::string infix_to_postfix (std::string expression);

int main() {
    std::cout << infix_to_postfix("( 1 + 2 ) * 3") << std::endl;
    std::cout << infix_to_postfix("2 * ( 1 + 3 )") << std::endl;

    return 0;
}

int precedence_of_operators (char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/' || op == '%') {
        return 2;
    }
    else if (op == '^') {
        return 3;
    }
    else {
        return 0;
    }
}

std::string infix_to_postfix (std::string expression) {
    int i;
    std::string result_string;
    std::stack<int> operands; // stack to store integer values
    std::stack<char> operators; // stack to store operators

    for (i = 0; i < expression.length(); i++) {

        //If current token is a whitespace, skip it
        if (expression[i] == ' ') {
            continue;
        }

        //If current token is an left brace, push it to operators stack
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }

        //If current token is a number, push it to operands stack
        else if (isdigit(expression[i])) {
            int value = 0;

            //There may be more than one digits in number
            while (i < expression.length() && isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }
            result_string.append(std::to_string(value));
            result_string.append(" ");
        }

        // If right brace encountered, solve left brace
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result_string.push_back(operators.top());
                result_string.append(" ");
                operators.pop();
            }

            // Pop left brace
            if (!operators.empty()) {
                operators.pop();
            }
        }

        // If current token is an operator
        else {
            /*
            While top of 'operators' has same or greater precedence to current token, which is an operator.
            Apply operator on top of 'operators' to top two elements in operands stack
            */
            while (!operators.empty() && precedence_of_operators(operators.top()) >= precedence_of_operators(expression[i])) {
                result_string.push_back(operators.top());
                result_string.append(" ");
                operators.pop();
            }

            // Push current token to 'operators'
            operators.push(expression[i]);
        }
    }
    // Entire expression has been parsed at this point, apply remaining operators to remaining operands
    while (!operators.empty()) {
        result_string.push_back(operators.top());
        result_string.append(" ");
        operators.pop();
    }

    return result_string;
}
