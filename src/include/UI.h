#include <iostream>
/*
This preprocessor directive checks if the macro UI_H is defined.
If it is not defined, then the preprocessor will continue processing
the code that follows.
*/
#ifndef UI_H
/*
This preprocessor directive defines the macro UI_H. Once this macro is defined,
the preprocessor will skip the rest of the code that is enclosed within the
#ifndef and #endif preprocessor directives.
*/
#define UI_H

class UI
{
public:
  void displayWelcomeMessage();
  void promptForVIN();
  void promptForModelYear();
  void promptForOdometerReading();
  void displayValidationResult(bool isOriginalMileage);

private:
  void readUserInput(std::string &input);
};

/*
This preprocessor directive marks the end of the code that is conditional
upon the macro UI_H being defined.
*/
#endif