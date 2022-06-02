#ifndef DATASET_H
#define DATASET_H
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <utility>
#include <functional>
#include "userprofile.h"

using namespace std;

class DataSet{
private:
    string fileName = "users.csv";
public:

    string sanitizeString( string inputString) {
        std::replace( inputString.begin(), inputString.end(), ',', ' ' );
        return inputString;
    }

    void addUser( userprofile usr ) {

        vector<vector<string>> dataset;
        std::vector<string> userVector = { sanitizeString(usr.name),
                                           sanitizeString(usr.surname),
                                           sanitizeString(to_string(usr.age)),
                                           sanitizeString(usr.sex),
                                           sanitizeString(usr.effect),
                                           sanitizeString(usr.vaccine)};
        dataset.push_back(userVector);

        std::ofstream myFile;
        myFile.open(fileName, std::ios_base::app);

        // Send data to the stream
        for(int i = 0; i < dataset.size(); ++i) {
            for(int j = 0; j < dataset.at(i).size(); ++j) {
                myFile << dataset.at(i).at(j);
                if(j != dataset.at(i).size()) myFile << ","; // No comma at end of line
            }
            myFile << "\n";
        }
        // Close the file
        myFile.close();
    }

    userprofile get_lastUser() {
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<vector<string>> result;

    // Create an input filestream
    std::ifstream myFile(fileName);

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line;
    string val;

    // Read data, line by line
    while(std::getline(myFile, line))
    {
        // Create a stringstream of the current line
        std::stringstream ss(line);
        std::vector<string> userVector;

        // Extract each value
        while(ss >> val){
            std::string delimiter = ",";
            std::string word;
            size_t pos = 0;
            while ((pos = val.find(delimiter)) != std::string::npos) {
                word = val.substr(0, pos);
                //std::cout << word << std::endl;

                userVector.push_back(word);

                val.erase(0, pos + delimiter.length());
            }
        }
        result.push_back(userVector);
    }

    // Close file
    myFile.close();

    vector<string> latestUser = result.at(result.size()-1);
    userprofile usr;

    usr.name = latestUser.at(0);
    usr.surname = latestUser.at(1);
    usr.age = stoi(latestUser.at(2));
    usr.sex = latestUser.at(3);
    usr.effect = latestUser.at(4);
    usr.vaccine = latestUser.at(5);

    //std::vector<string> userVector = {usr.name, usr.surname, to_string(usr.age), usr.sex, usr.effect, usr.vaccine};
    return usr;
    }

    int get_avgUserAge() {

        // Reads a CSV file into a vector of <string, vector<int>> pairs where
        // each pair represents <column name, column values>

        // Create a vector of <string, int vector> pairs to store the result
        std::vector<vector<string>> result;

        // Create an input filestream
        std::ifstream myFile(fileName);

        // Make sure the file is open
        if(!myFile.is_open()) throw std::runtime_error("Could not open file");

        // Helper vars
        std::string line;
        string val;

        // Read data, line by line
        while(std::getline(myFile, line))
        {
            // Create a stringstream of the current line
            std::stringstream ss(line);

            std::vector<string> userVector;

            // Extract each value
            while(ss >> val){
                std::string delimiter = ",";
                std::string word;
                size_t pos = 0;
                while ((pos = val.find(delimiter)) != std::string::npos) {
                    word = val.substr(0, pos);
                    //std::cout << word << std::endl;

                    userVector.push_back(word);

                    val.erase(0, pos + delimiter.length());
                }

                // If the next word is a comma, ignore it and move on
                //if(ss.peek() == ',') ss.ignore();



            }

            result.push_back(userVector);

        }

        myFile.close();
        float sumAge = 0;
        float averageAge = 0.0;

        for( int i = 0 ; i < (result.size() ); i++ ) {
            std::vector<string> userVector;
            userVector = result.at( i );
            sumAge = sumAge + stoi(userVector.at(2));
        }

        int divider = result.size();
        averageAge = sumAge/divider;

        return averageAge;
    }

    string get_avgVaccine() {

        std::vector<vector<string>> result;
        std::ifstream myFile(fileName);
        if(!myFile.is_open()) throw std::runtime_error("Could not open file");
        std::string line;
        string val;
        // Read data, line by line
        while(std::getline(myFile, line))
        {
            // Create a stringstream of the current line
            std::stringstream ss(line);
            std::vector<string> userVector;
            // Extract each value
            while(ss >> val){
                std::string delimiter = ",";
                std::string word;
                size_t pos = 0;
                while ((pos = val.find(delimiter)) != std::string::npos) {
                    word = val.substr(0, pos);
                    //std::cout << word << std::endl;
                    userVector.push_back(word);
                    val.erase(0, pos + delimiter.length());
                }
            }
            result.push_back(userVector);
        }
        myFile.close();

        string mostCommonVaccine;
        int maxOccurrence = 0;
        int counter = 0;

        for ( int i = 0 ; i < (result.size() - 1) ; i++ ) {
            std::vector<string>userVector;
            userVector = result.at(i);
            counter = 0;
            for ( int t = 0 ; t < (result.size() - 1); t++ ) {
                std::vector<string>userVectorTemp;
                userVectorTemp = result.at(t);
                if ( userVector.at(5) == userVectorTemp.at(5) ) {
                    counter++;
                }
            }
            if ( counter > maxOccurrence ) {
                mostCommonVaccine = userVector.at(5);
                maxOccurrence = counter;
            }
        }
        if  ( maxOccurrence == 0 ) {
            std::vector<string>userVector;
            userVector = result.at(0);
            mostCommonVaccine = userVector.at(5);
        }
        return mostCommonVaccine;
    }

    string get_avgSex() {
        // Reads a CSV file into a vector of <string, vector<int>> pairs where
        // each pair represents <column name, column values>

        // Create a vector of <string, int vector> pairs to store the result
        std::vector<vector<string>> result;

        // Create an input filestream
        std::ifstream myFile(fileName);

        // Make sure the file is open
        if(!myFile.is_open()) throw std::runtime_error("Could not open file");

        // Helper vars
        std::string line;
        string val;

        // Read data, line by line
        while(std::getline(myFile, line))
        {
            // Create a stringstream of the current line
            std::stringstream ss(line);

            std::vector<string> userVector;

            // Extract each value
            while(ss >> val){
                std::string delimiter = ",";
                std::string word;
                size_t pos = 0;
                while ((pos = val.find(delimiter)) != std::string::npos) {
                    word = val.substr(0, pos);
                    //std::cout << word << std::endl;

                    userVector.push_back(word);

                    val.erase(0, pos + delimiter.length());
                }

            }

            result.push_back(userVector);
        }

        myFile.close();

        int male = 0, female = 0;

        for ( int i = 0 ; i < result.size() ; i++ ) {
              std::vector<string>userVector;
              userVector = result.at(i);
              if ( userVector.at(3) == "female" || userVector.at(3) == "Female" ) {
                  female++;
              }else if ( userVector.at(3) == "male" || userVector.at(3) == "Male" ){
                  male++;
              }

        }

        if ( male > female ) {
            return "Male";
        }else if ( male < female ) {
            return "Female";
        }else if ( male == female ) {
            return "Equal Number of Sexes";
        }
        return 0;
    }

    string get_mostCommonSideEffect() {
        // Reads a CSV file into a vector of <string, vector<int>> pairs where
        // each pair represents <column name, column values>

        // Create a vector of <string, int vector> pairs to store the result
        std::vector<vector<string>> result;

        // Create an input filestream
        std::ifstream myFile(fileName);

        // Make sure the file is open
        if(!myFile.is_open()) throw std::runtime_error("Could not open file");

        // Helper vars
        std::string line;
        string val;

        // Read data, line by line
        while(std::getline(myFile, line))
        {
            // Create a stringstream of the current line
            std::stringstream ss(line);

            std::vector<string> userVector;

            // Extract each value
            while(ss >> val){
                std::string delimiter = ",";
                std::string word;
                size_t pos = 0;
                while ((pos = val.find(delimiter)) != std::string::npos) {
                    word = val.substr(0, pos);
                    userVector.push_back(word);
                    val.erase(0, pos + delimiter.length());
                }

            }
            result.push_back(userVector);
        }
        myFile.close();

        string highestSideEffect;
        int maxOccurrence = 0;
        int counter = 0;

        for ( int i = 0 ; i < (result.size() - 1) ; i++ ) {
            std::vector<string>userVector;
            userVector = result.at(i);
            counter = 0;
            for ( int t = 0 ; t < (result.size() - 1); t++ ) {
                std::vector<string>userVectorTemp;
                userVectorTemp = result.at(t);
                if ( userVector.at(4) == userVectorTemp.at(4) ) {
                    counter++;
                }
            }
            if ( counter > maxOccurrence ) {
                highestSideEffect = userVector.at(4);
                maxOccurrence = counter;
            }
        }
        if  ( maxOccurrence == 0 ) {
            std::vector<string>userVector;
           // highestSideEffect = userVector;
            userVector = result.at(0);
            highestSideEffect = userVector.at(4);
        }
        return highestSideEffect;

    }

    string get_leastCommonSideEffect() {
        // Reads a CSV file into a vector of <string, vector<int>> pairs where
        // each pair represents <column name, column values>

        // Create a vector of <string, int vector> pairs to store the result
        std::vector<vector<string>> result;

        // Create an input filestream
        std::ifstream myFile(fileName);

        // Make sure the file is open
        if(!myFile.is_open()) throw std::runtime_error("Could not open file");

        // Helper vars
        std::string line;
        string val;

        // Read data, line by line
        while(std::getline(myFile, line))
        {
            // Create a stringstream of the current line
            std::stringstream ss(line);

            std::vector<string> userVector;

            // Extract each value
            while(ss >> val){
                std::string delimiter = ",";
                std::string word;
                size_t pos = 0;
                while ((pos = val.find(delimiter)) != std::string::npos) {
                    word = val.substr(0, pos);
                    //std::cout << word << std::endl;

                    userVector.push_back(word);

                    val.erase(0, pos + delimiter.length());
                }
            }
            result.push_back(userVector);
        }
        myFile.close();

        string lowestSideEffect;
        int lowOccurrence = 2;
        int counter = 0;

        for ( int i = 0 ; i < (result.size() - 1) ; i++ ) {
            std::vector<string>userVector;
            userVector = result.at(i);
            counter = 0;
            for ( int t = 0 ; t < (result.size() - 1); t++ ) {
                std::vector<string>userVectorTemp;
                userVectorTemp = result.at(t);
                if ( userVector.at(4) == userVectorTemp.at(4) ) {
                    counter++;
                }
            }
            if ( counter < lowOccurrence ) {
                lowestSideEffect = userVector.at(4);
                lowOccurrence = counter;
            }
        }
        if  ( lowOccurrence == 2 ) {
            std::vector<string>userVector;
            userVector = result.at(0);
            lowestSideEffect = "Non";
        }
        return lowestSideEffect;
    }
    int get_amountofUsers() {
        // Reads a CSV file into a vector of <string, vector<int>> pairs where
        // each pair represents <column name, column values>

        // Create a vector of <string, int vector> pairs to store the result
        std::vector<vector<string>> result;

        // Create an input filestream
        std::ifstream myFile(fileName);

        // Make sure the file is open
        if(!myFile.is_open()) throw std::runtime_error("Could not open file");

        // Helper vars
        std::string line;
        string val;

        // Read data, line by line
        while(std::getline(myFile, line))
        {
            // Create a stringstream of the current line
            std::stringstream ss(line);

            std::vector<string> userVector;

            // Extract each value
            while(ss >> val){
                std::string delimiter = ",";
                std::string word;
                size_t pos = 0;
                while ((pos = val.find(delimiter)) != std::string::npos) {
                    word = val.substr(0, pos);
                    //std::cout << word << std::endl;

                    userVector.push_back(word);

                    val.erase(0, pos + delimiter.length());
                }
            }
            result.push_back(userVector);
        }
        myFile.close();

        int usersInDatabase = result.size();
        return usersInDatabase;
    }
};

#endif // DATASET_H
