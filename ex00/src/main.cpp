/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:12 by gacorrei          #+#    #+#             */
/*   Updated: 2024/11/07 11:17:27 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bank.hpp"

int main () {
  std::cout << "Test account opening\n";
  {
    Bank bank(std::numeric_limits<long>::max() - std::numeric_limits<int>::max() + 1);
    std::cout << "Negative value\n";
    bank.open_account(-1);
    std::cout << "Zero value\n";
    bank.open_account(0);
    std::cout << "Positive value below threshold\n";
    bank.open_account(10);
    std::cout << "Positive value that overflows liquidity\n";
    bank.open_account(std::numeric_limits<int>::max());
    std::cout << "Exceeds max accounts limits (needs test mode to work)\n";
    for (int i = 0; i < 6; i++) {
      bank.open_account(i + 1000);
    }
    std::cout << "Remaining are ok\n";
    std::cout << bank << "\n";
  }
  std::cout << "\nTest account closing\n";
  {
    Bank bank(1000);
    std::cout << "Closing non-existent account\n";
    bank.close_account(0);
    std::cout << "Closing account with debt\n";
    bank.open_account(1000);
    bank.loan(1, 100);
    bank.close_account(1);
    std::cout << "Closing account without debt\n";
    bank.open_account(1000);
    bank.close_account(2);
    std::cout << bank << "\n";
  }
  std::cout << "\nTest deposit\n";
  {
    Bank bank(1000);
    std::cout << "Depositing in non-existent account\n";
    bank.deposit(0, 100);
    std::cout << "Depositing negative value\n";
    bank.open_account(1000);
    bank.deposit(1, -100);
    std::cout << "Depositing positive value below threshold\n";
    bank.deposit(1, 10);
    std::cout << "Depositing value that overflows account\n";
    bank.deposit(1, std::numeric_limits<int>::max());
    std::cout << "Depositing ok value\n";
    bank.deposit(1, 100);
    std::cout << bank << "\n";
  }
  std::cout << "\nTest withdrawal\n";
  {
    Bank bank(1000);
    std::cout << "Withdrawing from non-existent account\n";
    bank.withdrawal(0, 100);
    std::cout << "Withdrawing negative value\n";
    bank.open_account(1000);
    bank.withdrawal(1, -100);
    std::cout << "Withdrawing value that exceeds account\n";
    bank.withdrawal(1, 1000);
    std::cout << "Withdrawing ok value\n";
    bank.withdrawal(1, 100);
    std::cout << bank << "\n";
  }
  std::cout << "\nTest loan\n";
  {
    Bank bank(1000);
    std::cout << "Loan from non-existent account\n";
    bank.loan(0, 100);
    std::cout << "Loan negative value\n";
    bank.open_account(1000);
    bank.loan(1, -100);
    std::cout << "Loan value below threshold\n";
    bank.loan(1, 10);
    std::cout << "Loan value that exceeds bank liquidity\n";
    bank.loan(1, std::numeric_limits<int>::max());
    bank.open_account(std::numeric_limits<int>::max());
    std::cout << "Loan value that exceeds account max value\n";
    bank.loan(1, std::numeric_limits<int>::max());
    std::cout << "Loan ok value\n";
    bank.loan(1, 100);
    std::cout << bank << "\n";
  }
  std::cout << "\nTest repay loan\n";
  {
    Bank bank(1000);
    std::cout << "Repay loan from non-existent account\n";
    bank.repay_loan(0, 100);
    std::cout << "Repay negative value\n";
    bank.open_account(1000);
    bank.repay_loan(1, -100);
    std::cout << "Repay value that exceeds debt\n";
    bank.loan(1, 100);
    bank.repay_loan(1, 1000);
    std::cout << "Repay ok value\n";
    bank.repay_loan(1, 100);
    std::cout << bank << "\n";
  }
  std::cout << "\nTest reusing account IDs\n";
  {
    Bank bank(1000);
    int id1 = bank.open_account(100);
    bank.open_account(200);
    bank.close_account(id1);
    int id3 = bank.open_account(300);
    std::cout << "Reused ID: " << id3 << " (should be the same as " << id1 << ")\n";
    std::cout << bank << "\n";
  }
  std::cout << "\nTest edge cases\n";
  {
    Bank bank(1000);
    bank.open_account(std::numeric_limits<int>::max());
    bank.deposit(1, std::numeric_limits<int>::max());
    bank.withdrawal(1, std::numeric_limits<int>::max());
    bank.loan(1, std::numeric_limits<int>::max());
    bank.repay_loan(1, std::numeric_limits<int>::max());
    std::cout << bank << "\n";
  }
  std::cout << "\nTest interest calculation\n";
  {
    Bank bank(1000);
    int id = bank.open_account(1000);
    int loan_value = 100;
    bank.loan(id, loan_value);
    bank.repay_loan(id, loan_value * INTEREST);
    std::cout << bank << "\n";
  }
  std::cout << "\nTest commission calculation\n";
  {
    Bank bank(1000);
    int id = bank.open_account(100);
    bank.withdrawal(id, 50);
    bank.withdrawal(id, 50);
    std::cout << bank << "\n";
  }
  return 0;
}
