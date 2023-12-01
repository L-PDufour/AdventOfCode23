/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:23:10 by ldufour           #+#    #+#             */
/*   Updated: 2023/12/01 09:56:11 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <fstream>
#include <iostream>

int findFirstDigit(const std::string &text) {
  for (char c : text) {
    if (std::isdigit(c)) {
      return (c - '0');
    }
  }
  return -1;
}

int findLastDigit(const std::string &text) {
  for (auto it = text.rbegin(); it != text.rend(); ++it) {
    if (std::isdigit(*it)) {
      return (*it - '0');
    }
  }
  return -1;
}

int main() {
  std::string filename;

  std::cout << "Enter the filename: ";
  std::cin >> filename;

  std::ifstream file(filename);

  if (!file.is_open()) {
  std:
    std::cerr << "Error opening file." << std::endl;
    return 1;
  }
  static int sum = 0;
  int sumALL = 0;
  std::string line;
  while (std::getline(file, line)) {
    int firstDigit = findFirstDigit(line) * 10;
    int lastDigit = findLastDigit(line);
    if (firstDigit != -1 && lastDigit != -1) {
      sum = firstDigit + lastDigit;
      sumALL = sumALL + sum;
    }
  }

  std::cout << "\nSum is: " << sumALL << std::endl;
  file.close();
  return 0;
}
