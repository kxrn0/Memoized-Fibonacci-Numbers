#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <string>

std::vector<unsigned long long> uvFibos;

unsigned long long mem_fibo(unsigned uPos) {
  if (uPos > uvFibos.size() - 1) {
    uvFibos.push_back(mem_fibo(uPos - 1) + mem_fibo(uPos - 2));
  }
  return uvFibos[uPos];
}

unsigned long long fibo(unsigned uPos) {
  return mem_fibo(uPos);
}

unsigned enter_number(const std::string& sMessage) {
  unsigned uNum;
  while (!(std::cin >> uNum)) {
    std::cout << sMessage;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return uNum;
}

int main() {
  uvFibos.push_back(1);
  uvFibos.push_back(1);

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
