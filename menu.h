#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"

using namespace std;

class Menu {
	private:
		unsigned history_index;
		vector<Command*> history;

	public:
		Menu() {
			//Base constructor to set up all necessary members
			history_index = 0;
		}
		void execute() {
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
			if(	history.empty()){
			    cout << "0" << endl;
			    return;
			}
			cout << history.at(history_index - 1)->execute() << endl;
		}
		bool initialized() {
			//Return true if the history has been primed with a single op instruciton
			//This is necessary because that is the base of a calculation
			if(history_index > 0){
			    return true;
			}
			
			return false;
		}
		void add_command(Command* cmd) {
			//Adds a command to history in the appropriate posiiton (based on history_index)
			if(history_index < history.size()){
    			history.resize(history_index);
		    }
		    history.push_back(cmd);
    		history_index += 1;
		}
		Command* get_command() {
			return (history.at(history_index - 1));
			//Returns the command in history we are currently referring to (based on history_index)
		}
		void undo() {
			//Moves to the last command in history (if possibl)e
			if(history_index > 1){
			    history_index -= 1;
			    history.at(history_index)->execute();
			}
			
		}
		void redo() {
			//Moves to the next command in history (if possible)
			if(history_index < history.size())
			{
				history_index += 1;
				history.at(history_index - 1)->execute();
			}
		}
};

#endif //__MENU_CLASS__
