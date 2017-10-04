#include <iostream>
#include <string>
#include <vector>

void recurseParentheses(std::vector<std::string> &combos, std::string parenth, int leftParenths, int rightParenths, int n) {
  if (parenth.length() == n*2) {
    combos.push_back(parenth);
    return;
  }

  if (leftParenths == n) {
    parenth += ")";
    rightParenths++;
    recurseParentheses(combos, parenth, leftParenths, rightParenths, n);
  }

  else {
    for (size_t i = 0; i < 2; i++) {
      if (i == 0) {
        std::string newString = parenth + "(";
        recurseParentheses(combos, newString, leftParenths+1, rightParenths, n);
      }
      else {
        if (rightParenths < leftParenths) {
          std::string newString = parenth + ")";
          recurseParentheses(combos, newString, leftParenths, rightParenths+1, n);
        }
      }
    }
  }
}

std::vector<std::string> generateParentheses(int n) {
 std::string parenth = "(";
  int leftParenths = 1;
  int rightParenths = 0;
  std::vector<std::string> combos;
  recurseParentheses(combos, parenth, leftParenths, rightParenths, n);
  return combos;
}

int main() {
  std::vector<std::string> combos;
  combos = generateParentheses(4);
  for (int i = 0; i < combos.size(); i++) {
    std::cout << combos[i] << std::endl;
  }
}
