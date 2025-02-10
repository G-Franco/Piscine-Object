/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:29:39 by gacorrei          #+#    #+#             */
/*   Updated: 2025/02/10 15:41:25 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Worker.hpp"
#include "../include/Shovel.hpp"
#include "../include/Hammer.hpp"

int tool_tester(int tool_type, int uses) {
  try {
    if (tool_type == 0) {
      Shovel shovel(uses);
    }
    else if (tool_type == 1) {
      Hammer hammer(uses);
    }
  }
  catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
  return 0;
}

int main() {
  {
    std::cout << "Basic tests (Workers, Tools and Workshops are created)\n";
    Worker worker1;
    Workshop workshop1;
    Shovel shovel1;
    Hammer hammer1;
  }
  {
    std::cout << "\nTool creation test cases\n";
    tool_tester(0, -1);
    tool_tester(1, -1);
    tool_tester(0, 101);
    tool_tester(1, 151);
    tool_tester(0, 100);
    tool_tester(1, 150);
  }
  {
    std::cout << "\nTrying to use workshop with NULL worker\n";
    Workshop workshop1;
    workshop1.add_worker(NULL);
    workshop1.remove_worker(NULL);
  }
  {
    std::cout << "\nWorker interactions with tools and workshops\n";
    Worker worker1;
    Workshop workshop1;
    Shovel shovel1;
    Shovel shovel2;
    Hammer hammer1;
    worker1.give_tool(NULL);
    worker1.give_tool(&shovel1);
    worker1.give_tool(&shovel1);
    worker1.give_tool(&shovel2);
    worker1.remove_tool("Hammer");
    worker1.sign_up_workshop(NULL);
    worker1.leave_workshop(NULL);
    worker1.sign_up_workshop(&workshop1);
    worker1.sign_up_workshop(&workshop1);
  }
  {
    std::cout << "\nWhen worker is deleted the tool can't be deleted\n"
              << "Tools can be added and removed from the worker\n";
    Shovel shovel1;
    Hammer hammer1;
    {
      Worker worker1;
      worker1.give_tool(&shovel1);
      worker1.give_tool(&hammer1);
      worker1.remove_tool("Shovel");
      worker1.remove_tool("Hammer");
      worker1.give_tool(&shovel1);
    }
    std::cout << "Worker is deleted, tools are not\n";
    shovel1.use();
    hammer1.use();
  }
  {
  std::cout << "\nTools owned by a worker that are given to another worker\n"
            << "need to be removed from the first worker\n";
    Shovel shovel1;
    Hammer hammer1;
    Worker worker1;
    Worker worker2;
    worker1.give_tool(&shovel1);
    worker1.give_tool(&hammer1);
    worker1.work("Shovel");
    worker1.work("Hammer");
    worker2.give_tool(&shovel1);
    worker2.give_tool(&hammer1);
    worker2.work("Shovel");
    worker2.work("Hammer");
    worker1.work("Shovel");
    worker1.work("Hammer");
  }
  {
    std::cout << "\nTools need to be identified by type (call get_type() on the tool)\n";
    Shovel shovel1;
    std::cout << "Shovel type: " << shovel1.get_type() << "\n";
    Hammer hammer1;
    std::cout << "Hammer type: " << hammer1.get_type() << "\n";
  }
  {
    std::cout << "\nWorker can sign up for a workshop and leave it\n";
    Workshop workshop1;
    Worker worker1;
    Shovel shovel1;
    worker1.give_tool(&shovel1);
    worker1.sign_up_workshop(&workshop1);
    worker1.leave_workshop(&workshop1);
  }
  {
    std::cout << "\nWorker can register at several workshops and leave them\n";
    Workshop workshop1;
    Workshop workshop2;
    Worker worker1;
    Shovel shovel1;
    worker1.give_tool(&shovel1);
    worker1.sign_up_workshop(&workshop1);
    worker1.sign_up_workshop(&workshop2);
    worker1.leave_workshop(&workshop1);
    worker1.leave_workshop(&workshop2);
  }
  {
    std::cout << "\nWorker can work and use the tools in the workshop\n";
    Workshop workshop1("Hammer");
    Worker worker1;
    Hammer hammer1;
    worker1.give_tool(&hammer1);
    worker1.sign_up_workshop(&workshop1);
    workshop1.executeWorkDay();
  }
  {
    std::cout << "\nWorkshops can start a workday for all their workers\n";
    Workshop workshop1("Hammer");
    Worker worker1;
    Worker worker2;
    Hammer hammer1;
    Hammer hammer2;
    worker1.give_tool(&hammer1);
    worker2.give_tool(&hammer2);
    worker1.sign_up_workshop(&workshop1);
    worker2.sign_up_workshop(&workshop1);
    workshop1.executeWorkDay();
  }
  {
  std::cout << "\nWorkshops only accept workers with the required tool\n";
    Workshop workshop1("Hammer");
    Worker worker1;
    Worker worker2;
    Shovel shovel1;
    Hammer hammer1;
    worker1.give_tool(&hammer1);
    worker2.give_tool(&shovel1);
    worker1.sign_up_workshop(&workshop1);
    worker2.sign_up_workshop(&workshop1);
  }
  {
    std::cout << "\nWorkers are released from a workshop when the required tool breaks\n";
    Workshop workshop1("Hammer");
    Worker worker1;
    Hammer hammer1(1);
    worker1.give_tool(&hammer1);
    worker1.sign_up_workshop(&workshop1);
    workshop1.executeWorkDay();
    workshop1.executeWorkDay();
  }
}
