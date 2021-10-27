#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <string>

unsigned long long fibo(unsigned uPos) {
  static std::vector<unsigned long long> vFibos;
  if (!vFibos.size()) {
    vFibos.push_back(1);
    vFibos.push_back(1);
  }

  if (uPos > vFibos.size() - 1) {
    vFibos.push_back(fibo(uPos - 1) + fibo(uPos - 2));
  }
  return vFibos[uPos];
}

int enter_number(const std::string& sMessage) {
  int nNum;
  do {
    while (!(std::cin >> nNum)) {
      std::cout << sMessage;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (nNum < 0)
      std::cout << "Please enter a positive number : ";
  } while (nNum < 0);
  return nNum;
}

int main() {
  bool bExit = false;
  while (!bExit) {
    int nPos;
    std::cout << "\nEnter the position of the Fibonacci number(start from 0) : ";
    nPos = enter_number("Please enter a valid number : ");
    std::cout << "The Fibonacci number at position " << nPos << " is " << fibo(nPos) << '\n';

    std::cout << "exit / continue : ";
    std::string sContExt;
    bool bCex = false;
    while (!bCex) {
      std::cin >> sContExt;
      sContExt = ([](const std::string& sStr) {
        std::string sCapped = "";
        for (char c : sStr)
          sCapped += toupper(c);
        return sCapped;
      })(sContExt);
      if (sContExt == "EXIT" || sContExt == "CONTINUE")
        bCex = true;
      else
        std::cout << "Please enter a valid option : ";
    }
    if (sContExt == "EXIT")
      bExit = true;
  }
}
