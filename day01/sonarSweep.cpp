#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/**
 * Solution for part 1 only!
 * 
 * This only compares the current measurement with the last.
 */
void part1(char *filename) {
  // various variable initialization for the solution
  std::string line;
  int current_num = 0;
  int prev_num = 99999999;
  int total_increased = 0;

  std::ifstream myfile(filename);

  if (myfile.is_open()) {
    while (std::getline(myfile, line)) {
      std::cout << line;

      // now we go ahead and convert line to a number
      std::stringstream linestream(line);
      linestream >> current_num;

      if (current_num > prev_num) {
        total_increased++;
        std::cout << "  (increased!)\n";
      } else {
        std::cout << "  (decreased/stayed the same)\n";
      }

      prev_num = current_num;
    }

    myfile.close();
  } else {
    std::cout << "Unable to open file!" << std::endl;
  }

  std::cout << "Total number of increased depths: " << total_increased
            << std::endl;
}

/**
 * Solution for part 2 only!
 * 
 * This is the "sliding window" version that keeps track of things.
 */
void part2(char *filename) {
  // various variable initialization
  std::string line;
  int linenum = 0;
  int current_num, current_sum = 0;
  int prev_sum = 99999999;
  int win1, win2 = 0;
  int total_increased = 0;

  std::ifstream myfile(filename);

  if (myfile.is_open()) {
    while (std::getline(myfile, line)) {

      // now we go ahead and convert line to a number
      std::stringstream linestream(line);
      linestream >> current_num;

      // only sum them together if our line number is past 0 and 1
      if (linenum > 1) {

        // now we need to add the pieces together
        current_sum = win1 + win2 + current_num;

        std::cout << "Window " << linenum - 2 << "  " << current_sum << ":";

        if (current_sum > prev_sum) {
          total_increased++;
          std::cout << "  (increased!)\n";
        } else {
          std::cout << "  (decreased/stayed the same)\n";
        }
        // update the previous sum
        prev_sum = current_sum;
      }

      // now we shuffle the pieces around
      // win1 receives win2
      win1 = win2;
      // win 2 receives current number
      win2 = current_num;
      
      linenum++;
    }

    myfile.close();
  } else {
    std::cout << "Unable to open file!" << std::endl;
  }

  std::cout << "Total number of increased depths: " << total_increased
            << std::endl;
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