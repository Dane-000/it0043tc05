#include <iostream>
#include <stack>
#include <string>

int minReplacementsForBalancedString(const std::string& str) {
    std::stack<char> stk;
    int replacements = 0;

    for (char c : str) {
        if (c == '{') {
            stk.push(c);
        } else if (c == '}' && !stk.empty() && stk.top() == '{') {
            stk.pop();
        } else {
            ++replacements;
        }
    }

    return replacements + (stk.size() / 2);
}

int main() {
    std::string str;
    std::cout << "Enter the string of braces: ";
    std::cin >> str;

    int replacements = minReplacementsForBalancedString(str);
    std::cout << "Minimum replacements required to make the string balanced: " << replacements << std::endl;

    return 0;
}
