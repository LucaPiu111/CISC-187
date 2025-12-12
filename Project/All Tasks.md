# Task 1

    #include <iostream>
    #include <vector>
    #include <unordered_set>
    using namespace std;
    
    struct Player {
        string first_name;
        string last_name;
        string team;
    };
    
    vector<string> find_dual_sport_players(const vector<Player>& players1, const vector<Player>& players2) {
        unordered_set<string> names_set;
        vector<string> dual_players;
    
        for (const auto& player : players1) {
            names_set.insert(player.first_name + " " + player.last_name);
        }
    
        for (const auto& player : players2) {
            string full_name = player.first_name + " " + player.last_name;
            if (names_set.count(full_name)) {
                dual_players.push_back(full_name);
                names_set.erase(full_name);
            }
        }
    
        return dual_players;
    }
    
    int main() {
        vector<Player> basketball = {
            {"Jill", "Huang", "Gators"},
            {"Janko", "Barton", "Sharks"},
            {"Wanda", "Vakulskas", "Sharks"},
            {"Jill", "Moloney", "Gators"},
            {"Luuk", "Watkins", "Gators"}
        };
    
        vector<Player> football = {
            {"Hanzla", "Radosti", "32ers"},
            {"Tina", "Watkins", "Barleycorns"},
            {"Alex", "Patel", "32ers"},
            {"Jill", "Huang", "Barleycorns"},
            {"Wanda", "Vakulskas", "Barleycorns"}
        };
    
        vector<string> result = find_dual_sport_players(basketball, football);
    
        cout << "Players that play both basketball and football:\n";
        for (const string& name : result) {
            cout << "- " << name << "\n";
        }
    
        return 0;
    }
