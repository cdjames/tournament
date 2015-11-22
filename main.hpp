/*********************************************************************
** Author: Collin James
** Date: 11/21/15
** Description: Program to test Tournament, Team, and updated Creature
**
** Function descriptions
*********************************************************************/

/*********************************************************************
** Description: 
** Asks player to choose a fighter. Checks for bad input and loops 
** until it gets good input.
*********************************************************************/
int mainMenu(int player);

/*********************************************************************
** Description: 
** Generic function for accepting integer input. Pass int to store
** info (reference) and a message to append to "Please enter "
*********************************************************************/
void intakeInt(int &num_items, std::string message);

/*********************************************************************
** Description: 
** A utility function to test for cin.fail(). Useful for detecting 
** erroneous input in menu functions. Returns true or false.
*********************************************************************/
bool cinFail();

/*********************************************************************
** Description: 
** Utility function combining cin.clear() and cin.ignore(). Useful 
** when using cin.getline() after cin >>
*********************************************************************/
void clearCin();

/*********************************************************************
** Description: 
** Calls Team::addMember() based on value in type. 1 = Goblin, etc.
*********************************************************************/
void addCreature(int type, Team* team);

void printTheStandings(Tournament* tourney);

int printMenu();

/*********************************************************************
** Description: 
** For posterity. See how I tested my classes as I was creating them.
*********************************************************************/
void initialTesting();