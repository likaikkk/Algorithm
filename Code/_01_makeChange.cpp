#include<iostream>
#include<vector>
#include<algorithm> //Used for sorting
using namespace std;

//Define a function, taking the amount to be made (amount) and an array of coin denominations (coins) as input
vector<int> makeChange(int amount, vector<int>& coins) {
    vector<int> change; //Store the coins for change
    int n = coins.size(); //Get the number of coin denomination

    //First, sort the coin denominations in descending order to start with larger denominations
    sort(coins.rbegin(), coins.rend());

    for (int i = 0;i < n;++i) { //Loop through the array of coin denominations
        while (amount >= coins[i]) { //As long as the amount is greater than or equal to the current coin denominations,continue using that coin
            change.push_back(coins[i]); //Add the current coin to the change result
            amount -= coins[i]; //Subtract the used coin denomination from the remaining amount
        }
    }
    return change; //Return the array of coins for change
}

int main() {
    int amount = 68; //The desired amount to make change for
    vector<int> coins = { 50,25,10,5,1 }; //Different coin denomination;
    vector<int>change = makeChange(amount, coins); //Call the function to compute change

    cout << "Minimum number of coins needed: " << change.size() << endl;
    cout << "Coins used: ";

    for (int coin : change) {
        cout << coin << " ";
    }
}