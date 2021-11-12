/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 223                                                       *
* Programming Assignment: PA 1 - Learning Linux Commands Matching Game  *
*                                and C++ Review                         *
* Date: 8/30/2021                                                       *
* Description: This program is a matching game to learn Linux commands. *
************************************************************************/

#include "header.h"

/****************************************************************
* Class Function: Profile()                                     *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: A constructor                                    *
* Input parameters: string, int                                 *
* Returns: Nothing                                              *
* Preconditions: string, int                                    *
* Postconditions: An object has been initialized                *
*****************************************************************/
Profile::Profile(string name, int points) {
    this->name = name;
    this->points = points;
}

/****************************************************************
* Class Function: ~Profile()                                    *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: A destructor                                     *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
Profile::~Profile() {

}

/****************************************************************
* Class Function: getName()                                     *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Returns name                                     *
* Input parameters: None                                        *
* Returns: string                                               *
* Preconditions: None                                           *
* Postconditions: Name has been returned                        *
*****************************************************************/
string Profile::getName() {
    return name;
}

/****************************************************************
* Class Function: getPoints()                                   *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Returns points                                   *
* Input parameters: None                                        *
* Returns: int                                                  *
* Preconditions: None                                           *
* Postconditions: Points have been returned                     *
*****************************************************************/
int Profile::getPoints() {
    return points;
}

/****************************************************************
* Class Function: setName()                                     *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Modifies name                                    *
* Input parameters: string                                      *
* Returns: Nothing                                              *
* Preconditions: string                                         *
* Postconditions: The name has been modified                    *
*****************************************************************/
void Profile::setName(string name) {
    this->name = name;
}

/****************************************************************
* Class Function: setPoints()                                   *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Modifies points                                  *
* Input parameters: int                                         *
* Returns: Nothing                                              *
* Preconditions: int                                            *
* Postconditions: The points have been modified                 *
*****************************************************************/
void Profile::setPoints(int points) {
    this->points = points;
}