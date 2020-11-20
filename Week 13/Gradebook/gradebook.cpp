#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Assignment {
  std::string name;
  double pointsWorth;
  double pointsEarned;
};

void showGrades(Assignment&);

int main() {
  std::vector<Assignment> assignmentList;
  bool flagTriggered = false;
  bool isGradeAcceptable;

  do {
    Assignment newAssignment;

    std::cout << "What is the assignment name? ";
    getline(std::cin, newAssignment.name);

    if (newAssignment.name == "stop") {
      flagTriggered = true;
      break;
    }

    std::cout << "How many points is it worth? ";
    std::cin >> newAssignment.pointsWorth;

    do {
      if (newAssignment.pointsWorth <= 0) {
        std::cout << "Please enter a value bigger than 0: "; 
        std::cin >> newAssignment.pointsWorth;
        isGradeAcceptable = false; 
      } else {
        isGradeAcceptable = true;
      }
    } while(!isGradeAcceptable);

    isGradeAcceptable = false;

    std::cout << "How many points were earned? ";
    std::cin >> newAssignment.pointsEarned;

    do {
      if (newAssignment.pointsEarned > newAssignment.pointsWorth || newAssignment.pointsEarned < 0) {
        std::cout << "Please enter a value between 0 and " << newAssignment.pointsWorth << std::endl;
        std::cin >> newAssignment.pointsEarned;
        isGradeAcceptable = false; 
      } else {
        isGradeAcceptable = true;
      }
    } while(!isGradeAcceptable);

    assignmentList.push_back(newAssignment);

    // Clear buffer to not mess up next iteration.
    std::cin.ignore();
  } while (!flagTriggered);

  double sum = 0;
  double limit = 0;

  std::cout << "\nGRADES\n" << std::endl;

  for (Assignment assignment : assignmentList) {
    std::cout << assignment.name << std::setw(7) << assignment.pointsEarned << " / " << assignment.pointsWorth << std::endl;
    sum += assignment.pointsEarned; 
    limit += assignment.pointsWorth;
  }

  std::cout << "-----------------------" << std::endl;
  std::cout << "AVG\t\t" << sum << " / " << limit << " (" << (sum / limit)*100 << ")" << std::endl;

  return 0;
}

void showGrades(const Assignment &assignment) {
  std::cout << assignment.name << std::endl;
  std::cout << assignment.pointsWorth << std::endl;
  std::cout << assignment.pointsEarned << std::endl;

  return;
}