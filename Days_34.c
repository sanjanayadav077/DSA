#include <stdio.h>
#include <ctype.h>
int calculate(char *s) {
    int result = 0;
    int current_number = 0;
    int last_number = 0;
    char operation = '+';
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            current_number = current_number * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || s[i + 1] == '\0') {
            if (operation == '+') {
                result += last_number;
                last_number = current_number;
            } 
            else if (operation == '-') {
                result += last_number;
                last_number = -current_number;
            } 
            else if (operation == '*') {
                last_number = last_number * current_number;
            } 
            else if (operation == '/') {
                last_number = last_number / current_number; // truncates toward zero
            }

            operation = s[i];
            current_number = 0;
        }
    }
    result += last_number;
    return result;
}
int main() {
    char s[100];
    printf("Enter expression: ");
    fgets(s, sizeof(s), stdin);
    int result = calculate(s);
    printf("Result = %d\n", result);
    return 0;
}