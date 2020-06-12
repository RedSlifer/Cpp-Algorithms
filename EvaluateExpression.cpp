#include <bits/stdc++.h>

// Function to find precedence of operators
int precedence_of_operators (char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/' || op == '%')
    {
        return 2;
    }
    else if (op == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

// Function to perform arithmetic operations
int apply_operation (int a, int b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else if (op == '*')
    {
        return a * b;
    }
    else if (op == '/')
    {
        return a / b;
    }
    else if (op == '^')
    {
        return std::pow(a, b);
    }
    else
    {
        return a % b;
    }
}

// Function that returns value of expression after evaluation
int evaluate_expression (std::string expression)
{
    int i;
    std::stack<int> operands; // stack to store integer values
    std::stack<char> operators; // stack to store operators

    for (i = 0; i < expression.length(); i++)
    {

        //If current token is a whitespace, skip it
        if (expression[i] == ' ')
        {
            continue;
        }
        //If current token is an left brace, push it to operators stack
        else if (expression[i] == '(')
        {
            operators.push(expression[i]);
        }
        //If current token is a number, push it to operands stack
        else if (isdigit(expression[i]))
        {
            int value = 0;

            //There may be more than one digits in number
            while (i < expression.length() && isdigit(expression[i]))
            {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }
            operands.push(value);
        }
        // If right brace encountered, solve left brace
        else if (expression[i] == ')')
        {
            //int first_operand, second_operand;

            while (!operators.empty() && operators.top() != '(')
            {
                int first_operand = operands.top();
                operands.pop();

                int second_operand = operands.top();
                operands.pop();

                operands.push(apply_operation(second_operand, first_operand, operators.top()));
                operators.pop();
            }
            // Pop left brace
            if (!operators.empty())
            {
                operators.pop();
            }
        }
        // If current token is an operator
        else
        {
            /*
            While top of 'operators' has same or greater precedence to current token, which is an operator.
            Apply operator on top of 'operators' to top two elements in operands stack
            */
            //int first_operand, second_operand;

            while (!operators.empty() && precedence_of_operators(operators.top()) >= precedence_of_operators(expression[i]))
            {
                int first_operand = operands.top();
                operands.pop();

                int second_operand = operands.top();
                operands.pop();

                operands.push(apply_operation(second_operand, first_operand, operators.top()));
                operators.pop();
            }

            // Push current token to 'operators'
            operators.push(expression[i]);
        }
    }
    // Entire expression has been parsed at this point, apply remaining operators to remaining operands
    while (!operators.empty())
    {
        int first_operand = operands.top();
        operands.pop();

        int second_operand = operands.top();
        operands.pop();

        operands.push(apply_operation(second_operand, first_operand, operators.top()));
        operators.pop();
    }
    // Top of 'operands' contains result, return it
    return operands.top();
}

int main()
{
    std::cout << evaluate_expression("10 + 2 * 6") << std::endl;
    std::cout << evaluate_expression("100 * 2 + 12") << std::endl;
    std::cout << evaluate_expression("100 * ( 2 + 12 )") << std::endl;
    std::cout << evaluate_expression("100 * ( 2 + 12 ) / 14") << std::endl;
    std::cout << evaluate_expression("( 13 + 2 ) * 4 - 3") << std::endl;
    std::cout << evaluate_expression("( 5 * 2 ^ 3 + 2 * 3 % 2 ) * 4") << std::endl;
    return 0;
}
