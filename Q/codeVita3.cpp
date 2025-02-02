#include <iostream>
#include <vector>
#include <string>
using namespace std;

void executeCommands(vector<vector<int>>& commands, vector<string>& printStatements) {
    for (size_t i = 0; i < commands.size(); i++) {
        vector<int> command = commands[i];

        if (command[0] == 1) { // 'for'
            int times = command[1];
            for (int j = 1; j <= times; j++) {
                bool loopBroken = false;

                for (size_t k = i + 1; k < commands.size(); k++) {
                    vector<int> subCommand = commands[k];

                    if (subCommand[0] == 2 && j == subCommand[1]) { // 'break N'
                        loopBroken = true;
                        break;
                    }

                    if (subCommand[0] == 3 && j == subCommand[1]) { // 'continue N'
                        break; // Skip remaining commands for this iteration
                    }

                    if (subCommand[0] == 4) { // 'print'
                        cout << printStatements[subCommand[1]] << endl;
                    }

                    if (subCommand[0] == 5) { // Nested loop
                        vector<vector<int>> nestedCommands(commands.begin() + k + 1, commands.end());
                        executeCommands(nestedCommands, printStatements);
                    }

                    if (subCommand[0] == 0) { // 'done'
                        break;
                    }
                }

                if (loopBroken) {
                    break; // Exit the current loop entirely
                }
            }
        }
    }
}

int main() {
    // Example usage
    vector<vector<int>> commands = {
        {1, 3},       // for loop 3 times
        {4, 0},       // print statement at index 0
        {2, 2},       // break when loop variable equals 2
        {0}           // done
    };
    vector<string> printStatements = {"Hello, World!"};

    executeCommands(commands, printStatements);

    return 0;
}
