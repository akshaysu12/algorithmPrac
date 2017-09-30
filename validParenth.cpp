#include <iostream>
#include <string>
#include <vector>

bool isValid(std::string s) {
    std::vector<char> stack;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack.push_back(s[i]);
        }

        else {
            if (stack.size() == 0) {
                return false;
            }
            if (s[i] == ')' && stack.back() != '(') {
                return false;
            }
            else if (s[i] == '}' && stack.back() != '{') {
                return false;
            }
            else if (s[i] == ']' && stack.back() != '[') {
                return false;
            }
            else {
                stack.pop_back();
            }
        }
    }
    if (stack.size() != 0) {
        return false;
    }
    return true;
}

int main() {
  std::string s = "()";
  std::cout << isValid(s) << std::endl;
}
