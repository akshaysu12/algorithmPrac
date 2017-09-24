#include <iostream>
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
  std::unordered_map<char, int> map;
  int length = s.length();
  int maxLength = 0;

  int i = 0;  //left side of substring currently being checked

  //for loop (j) controls right side of substring
  for (int j = 0; j < length; j++) {
    //non-duplicate - char not in hashmap
    if (map.find(s[j]) == map.end()) {
      std::cout << "new char: " << s[j] << std::endl;
      map[s[j]] = j;
      int currLength = j - i + 1;
      if (currLength > maxLength) {
        maxLength = currLength;
      }
      std::cout << "i, j, current length, max length: " << i << "," << j << "," << currLength << "," << maxLength << std::endl;
    }

    //duplicate - char already in hashmap
    else {
      std::cout << "duplicate char: " << s[j] << std::endl;
      //find length of substring and see if it is longest found so far

      //get position of the repeated char
      int pos = map[s[j]];

      //if i is at start move i up, else move i to repeat
      if (i == pos) {
        i++;
      }
      else if (pos > i) {
        i = pos + 1;
      }

      //update the most recent location of the duplicated char
      map[s[j]] = j;

      int currLength = j - i + 1;
      if (currLength > maxLength) {
        maxLength = currLength;
      }

      std::cout << "i, j, current length, max length: " << i << "," << j << "," << currLength << "," << maxLength << std::endl;
    }
  }

  return maxLength;
}

int main() {
  std::string s = "abba";
  int length = lengthOfLongestSubstring(s);
  std::cout << "length of substring is: " << length << std::endl;
}
