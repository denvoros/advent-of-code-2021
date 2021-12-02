#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/**
 * This function divides up a line of text into a vector
 *
 */
std::vector<std::string> getWords(std::string singleLine) {
  std::string delimiter = " ";
  std::vector<std::string> words;

  int pos = 0;

  while ((pos = singleLine.find(delimiter)) != std::string::npos) {
    words.push_back(singleLine.substr(0, pos));
    singleLine.erase(0, pos + delimiter.length());
  }

  // also need to add the last one for some reason
  words.push_back(singleLine);

  return words;
}

/**
 * Solution for part 1 only!
 *
 * This only compares the current measurement with the last.
 */
void part1(char *filename) {
  // various variable initialization for the solution
  std::string line;
  int horizontal = 0;
  int depth = 0;

  int amountMove = 0;

  std::ifstream myfile(filename);

  if (myfile.is_open()) {
    while (std::getline(myfile, line)) {
      std::cout << line;

      // so now our first one is the direction and second is value
      std::vector<std::string> directions = getWords(line);

      // now we go ahead and convert line to a number
      std::stringstream valuestream(directions[1]);
      valuestream >> amountMove;

      if (directions[0].compare("forward") == 0) {
        horizontal += amountMove;
      } else if (directions[0].compare("down") == 0) {
        depth += amountMove;
      } else if (directions[0].compare("up") == 0) {
        depth -= amountMove;
      }

      std::cout << ": current position: h=" << horizontal << " d=" << depth
                << std::endl;
    }

    myfile.close();
  } else {
    std::cout << "Unable to open file!" << std::endl;
  }

  std::cout << "Final position: h=" << horizontal << " d=" << depth
            << std::endl;
  std::cout << "Horizontal times depth is: " << horizontal * depth << std::endl;
}

void part2(char *filename) {
  // various variable initialization for the solution
  std::string line;
  int horizontal = 0;
  int depth = 0;
  int aim = 0;

  int amountMove = 0;

  std::ifstream myfile(filename);

  if (myfile.is_open()) {
    while (std::getline(myfile, line)) {
      std::cout << line;

      // so now our first one is the direction and second is value
      std::vector<std::string> directions = getWords(line);

      // now we go ahead and convert line to a number
      std::stringstream valuestream(directions[1]);
      valuestream >> amountMove;

      if (directions[0].compare("forward") == 0) {
        horizontal += amountMove;
        depth += aim * amountMove;
      } else if (directions[0].compare("down") == 0) {
        aim += amountMove;
      } else if (directions[0].compare("up") == 0) {
        aim -= amountMove;
      }

      std::cout << ": current position: h=" << horizontal << " d=" << depth
                << " a=" << aim << std::endl;
    }

    myfile.close();
  } else {
    std::cout << "Unable to open file!" << std::endl;
  }

  std::cout << "Final position: h=" << horizontal << " d=" << depth
            << std::endl;
  std::cout << "Horizontal times depth is: " << horizontal * depth << std::endl;
}

int main(int argc, char **argv) {

  if (argc < 3) {
    std::cout << "No file given or part number as input!" << std::endl;
    return 0;
  }

  if (argv[2][0] == '1') {
    part1(argv[1]);
  } else if (argv[2][0] == '2') {
    part2(argv[1]);
  } else {
    std::cout << "Invalid part selected!" << std::endl;
  }

  return 0;
}