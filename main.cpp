#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GetLineNotWS(string& inpString)
{
   getline(cin, inpString);
   if (inpString.find_first_not_of(" \t") == std::string::npos)
   {
      getline(cin, inpString);
   }
}

int main()
{
  string userInput;

  cout << "**Bread and Cakes Bakery**" << endl << endl;

  do
  {

    cout << "Enter sub-order (enter \"done\" to finish)" << endl;
    GetLineNotWS(userInput);

  }
  while(userInput != "done");
  return 0;
}
