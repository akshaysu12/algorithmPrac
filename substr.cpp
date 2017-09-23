#include <iostream>
#include <string>

std::string longestPalindrome(std::string s) {
  //set length variable
  int length = s.length();

  //create O(n^2) space complexity table
  int table[length][length];

  //initialize base cases - all 1 and 2 letter palindromes (all 1 letter are true, some 2 letter are true)
  for(int i = 0; i < length; i++) {
      table[i][i] = 1;
      if (s[i] == s[i+1] && i != (length - 1)) {
        table[i][i+1] = 1;
      }
  }

  //var to store length of longest palindromic substring so we only have to check substrings of this length later
  int maxLength = 1;

  //loop through different size substrings checking if they are palindromes - start with length 3
  for (int subLength = 2; subLength < length; subLength++) {
      for(int i = 0; i + subLength < length; i++) {
          int j = i+subLength;
          if (s[j] == s[i] && table[i+1][j-1] == 1) {
              table[i][j] = 1;
              maxLength = subLength;

          }
          else {
              table[i][j] = 0;
          }
      }
  }
  //loop through all of the substrings of maxLength and return first true
  for(int i = 0; i + maxLength < length; i++) {
    if (table[i][i+maxLength] == 1) {
      return s.substr(i,(maxLength+1));
    }
  }
  //if no palindromes return empty string
  return "";
}

int main() {
  std::string s = "lazecdef";
  std::string result = longestPalindrome(s);
  if (result.size() == 0) {
    std::cout << "no palindromes" << std::endl;
  }
  else {
    std::cout << "Final result is: " << result << std::endl;
  }
}
