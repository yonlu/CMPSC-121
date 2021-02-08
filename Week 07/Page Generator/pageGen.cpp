#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // User info
    string name;
    string age;
    string description;


    // Prompt user info through terminal.
    cout << "What is your name? ";
    getline(cin, name);

    cout << "How old are you? ";
    getline(cin, age);

    cout << "Tell me a little bit about yourself: ";
    getline(cin, description);

    // file stream object, create/rewrite a new file called pageGen.html.
    ofstream outputFile;
    outputFile.open("pageGen.html");

    if (!outputFile) {
        cout << "Connection to file failed, please try again." << endl;
        return 0;
    } else {
        // HTML template
        string htmlTemplate = "<html>\n\t<head><title>" + name +
                              "'s Page</title></head>\n<body>\n\t<center><h1>" + name + " - "  + age +
                              "</h1></center>\n\t<hr />\n\t\t" + description +
                              "\n\t<hr />\n</body>\n</html>";

        // Output html template lines to the file.
        outputFile << htmlTemplate;
    }

    // Close the current connection.
    outputFile.close();

    return 0;
}
