#include <iostream>
#include <set>
#include <fstream>
#include <vector>

using namespace std;

struct ColorPair {
    string lColor;
    string rColor;
    bool operator == (ColorPair rval) const {
        return (lColor == rval.lColor && rColor == rval.rColor)
            || (lColor == rval.rColor && rColor == rval.lColor);
    }
};

bool Deuteranope(string color1, string color2, vector<ColorPair>& badCombos) {

    ColorPair userCombo = {color1, color2};

    for (int i = 0; i < badCombos.size(); i++) {
        if (userCombo == badCombos[i]) {
            return false;
        }
    }

    return true;
}

string getColor() {
    string color;

    while (true) {
        cin >> color;

        if (color.empty()) {
            cout << "Invalid entry. Try again." << endl;
            continue;
        }

        return color;
    }
}



void colorChecker(int ColorBlindnessType, vector<ColorPair>& badCombos) {

    string color1;
    string color2;
    bool comboClear;

    switch (ColorBlindnessType) {
        case 1:
            cout << "We'll be checking color combinations for Deuteranope color blindness" << endl;

            while (true) {
                cout << "Enter your first color: " << endl;
                color1 = getColor();

                cout << "Enter your second color: " << endl;
                color2 = getColor();

                if (color1 == color2) {
                    cout << "You entered identical colors. Please try again." << endl;
                    continue;
                }

                break;
            }

            comboClear = Deuteranope(color1, color2, badCombos);

            if (comboClear == false) {
                cout << "This is not a good color combination for someone with Deuteranope color blindness" << endl;
            }
            else {
                cout << "This is a valid color combo" << endl;
            }

            break;
    }
}

int getColorBlindnessType(){

    int ColorBlindnessType;

    while(true){
        cin >> ColorBlindnessType;
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "This is not a not a valid entry try again" << endl;
            continue; // Restart the loop to try again

        }
        if(ColorBlindnessType != 1){
            cout << "This is not a not a valid entry try again" << endl;
            continue;
        }
        
        return ColorBlindnessType;
   }
   
}

void greeting (){
    cout << "Welcome to the blindess checker!" << endl;
    cout << "Please select from the following options: " << endl;
    cout << "1.) Deuteranope" << endl;

}

vector<ColorPair> getFileInfo(ifstream& file) {
    vector<ColorPair> badCombos;
    ColorPair currentPair;

    while (file >> currentPair.lColor >> currentPair.rColor) {
        badCombos.push_back(currentPair);
    }

    return badCombos;
}

int main() {

    ifstream file("colors.txt");

    if (!file.is_open()) {
        cout << "Could not open colors.txt" << endl;
        return 1;
    }

    vector<ColorPair> badCombos = getFileInfo(file);

    file.close();

    greeting();

    int ColorBlindnessType = getColorBlindnessType();

    colorChecker(ColorBlindnessType, badCombos);

    return 0;
}

