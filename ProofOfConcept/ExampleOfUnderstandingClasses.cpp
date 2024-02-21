//
//  
// 
// Created By Cody Bentlage
//  
//
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class BaseballPlayer
{


private:
    
    string firstName;
    string lastName;
    int gamesPlayed;
    int gamesStarted;
    double VORP; // Value over replacement player:
    double winsAboveReplacement; // Number of wins over a "replacement-level player"
    double PWA; // increase or decrease team's chances of winning a specific game
    //Updated with the 7 new stats
    double StrikeOutToWalkRatio;
    double FlyBallRate;
    int RunsCreated;
    int HitsPerNineInnings;
    int WalkRate;
    int PopUpRate;
    int GroundBallRate;
    

public:
    

    void print();
    void inputKeyboard();//Made this function functional
    void save(ofstream& outFile);//Letting the function know it will be passing a file through it later
    void setPlayer(string Name1, string Name2, int playedGames, int startedGames, double VORP_score, double WAR_score, double PWA_score, double STW_score, double FBR_score, int RC_score, int HPNI_score, int WR_score, int PUR_score, int GBR_score);//Updated with the 7 new stats
    void specificPlayer();//New function to change a specific player
    void printSpecificPlayer();//New function to print a specific player
    BaseballPlayer(); //Default constructor
    BaseballPlayer(string Name1, string Name2, int playedGames, int startedGames, double VORP_score, double WAR_score, double PWA_score, double STW_score, double FBR_score, int RC_score, int HPNI_score, int WR_score, int PUR_score, int GBR_score); //Constructor with values, updated with the 7 new stats
    //Updated with seven new stats

    ~BaseballPlayer(){}; //Inline Default Destructor
};

class BaseBallTeam
{
    private:
    BaseballPlayer Team[9];//Made it 9 instead of 3
    
    
    public:
    void print();
    void inputFile();
    void inputKeyboard();
    void save();
    void specificPlayer();
    void printSpecificPlayer();
    
    BaseBallTeam(); //Default Constructor
    ~BaseBallTeam(); //Default Destructor
    
    
};

void BaseBallTeam::print()//This function works in two parts. Since the scope of BaseBallTeam doesn't recognize individual players stats, here we will choose a player from BaseBallTeam, and pass it into a function with the same name but under the scope of BaseballPlayer so each players information can be properly accessed.
{   
    int player = 1;
    for(int i = 0; i < 9; i++)
    {
        cout << "Player "<< player++ << "\n";//Putting "++" after player is important here, if it was put before, it would show player 1 as player 2 and so on. Putting it after player means that 1 is added to player, after player has already been printed.
        Team[i].print();
        cout << endl;
        
    }
}

void BaseBallTeam::printSpecificPlayer()//This function works in two parts. Since the scope of BaseBallTeam doesn't recognize individual players stats, here we will choose a player from BaseBallTeam, and pass it into a function with the same name but under the scope of BaseballPlayer so each players information can be properly accessed.
{
    int user_choice;
    cout << "Which numbered players stats would you like to see?(1-9)\n\n";
    cin >> user_choice;
    cout << "Player " << user_choice << "\n";
    Team[--user_choice].printSpecificPlayer();//Putting "--" before user_choice here is very important. Arrays start at 0 so when the user wants to see the first player, the array needs to be accessed as 0 not 1.
}

void BaseBallTeam::specificPlayer()//This function works in two parts. Since the scope of BaseBallTeam doesn't recognize individual players stats, here we will choose a player from BaseBallTeam, and pass it into a function with the same name but under the scope of BaseballPlayer so each players information can be properly accessed.
{
    int user_choice;
    cout << "Which numbered player (1-9) would you like to change?\n\n";
    cin >> user_choice;
    Team[--user_choice].specificPlayer();//Putting "--" before user_choice here is very important. Arrays start at 0 so when the user wants to see the first player, the array needs to be accessed as 0 not 1. 
}

void BaseBallTeam::inputKeyboard()//This function works in two parts. Since the scope of BaseBallTeam doesn't recognize individual players stats, here we will choose a player from BaseBallTeam, and pass it into a function with the same name but under the scope of BaseballPlayer so each players information can be properly accessed.
{   
    int player = 1;
    for(int i = 0; i < 9; i++)
    {
        cout << "Player "<< player++ << "\n";//Putting "++" after player is important here, if it was put before, it would show player 1 as player 2 and so on. Putting it after player means that 1 is added to player, after player has already been printed.
        Team[i].inputKeyboard();
        cout << endl;
    }
}

void BaseBallTeam::save()//This function works in two parts. Since the scope of BaseBallTeam doesn't recognize individual players stats, here we will choose a player from BaseBallTeam, and pass it into a function with the same name but under the scope of BaseballPlayer so each players information can be properly accessed.
{   
    ofstream outFile;//Output stream variable
    outFile.open("SaveData.txt");//Opening the save file *OUTSIDE OF THE FOR LOOP*...
    if(outFile.is_open())
    {
    for(int i = 0; i < 9; i ++)
    {
        Team[i].save(outFile);//Passing the opened file into the function so I don't keep overriding the same file.
    } 
    }
    outFile.close();
    cout << "\n\nYour data has been saved.\n\n";
}

void BaseBallTeam::inputFile() //Input Team data from a file
{

        string firstName = "A";
        string lastName = "B";
        int stat1 = 1;
        int stat2 = 2;
        double stat3 = 3;
        double stat4 = 4;
        double stat5 = 5;
         //Add 7 more of these
        double stat6 = 6;
        double stat7 = 7;
        int    stat8 = 8;
        int    stat9 = 9;
        int    stat10 = 10;
        int    stat11 = 11;
        int    stat12 = 12;
        
        ifstream inFile; //input file stream variable
        inFile.open("SaveData.txt");
        
        for(int fileLine = 0; fileLine < 9; fileLine++)
        {
            inFile >> firstName;
            inFile >> lastName;
            inFile >> stat1;
            inFile >> stat2;
            inFile >> stat3;
            inFile >> stat4;
            inFile >> stat5;
            //Add 7 more of these
            inFile >> stat6;
            inFile >> stat7;
            inFile >> stat8;
            inFile >> stat9;
            inFile >> stat10;
            inFile >> stat11;
            inFile >> stat12;
            
            Team[fileLine].setPlayer(firstName, lastName, stat1, stat2, stat3, stat4, stat5, stat6, stat7, stat8, stat9, stat10, stat11, stat12);
            
        }
        
        
        inFile.close();
    }

void BaseballPlayer::inputKeyboard()
{   
    cout << "Build your character\n";
    cout << "Name: \n";
    cin >> firstName; 
    cout << endl;
    cout << "Last name: \n";
    cin >> lastName;
    cout << endl;
    cout << "Games Played: \n";
    cin >> gamesPlayed;
    cout << endl;
    cout << "Games Started: \n";
    cin >> gamesStarted;
    cout << endl;
    cout << "Value over replacement player (VORP): \n";
    cin >> VORP;
    cout << endl;
    cout << "Number of wins over replacement player (WAR): \n"; 
    cin >> winsAboveReplacement;
    cout << endl;
    cout << "Increase or decrease team's chances of winning a specific game (PWA): \n";
    cin >> PWA;
    cout << endl;   
    cout << "Strike-out to walk ratio: \n";
    cin >> StrikeOutToWalkRatio;
    cout << endl;
    cout << "Fly-ball ratio: \n";
    cin >> FlyBallRate;
    cout << endl;
    cout << "Runs created: \n";
    cin >> RunsCreated;
    cout << endl;
    cout << "Hits per nine innings: \n";
    cin >> HitsPerNineInnings;
    cout << endl;
    cout << "Walk rate: \n";
    cin >> WalkRate;
    cout << endl;
    cout << "Pop-up rate: \n";
    cin >> PopUpRate;
    cout << endl;
    cout << "Ground-ball rate: \n";
    cin >> GroundBallRate;
    cout << endl;
}

void BaseballPlayer::specificPlayer()
{
     cout << "Build your character\n";
    cout << "Name: \n";
    cin >> firstName; 
    cout << endl;
    cout << "Last name: \n";
    cin >> lastName;
    cout << endl;
    cout << "Games Played: \n";
    cin >> gamesPlayed;
    cout << endl;
    cout << "Games Started: \n";
    cin >> gamesStarted;
    cout << endl;
    cout << "Value over replacement player (VORP): \n";
    cin >> VORP;
    cout << endl;
    cout << "Number of wins over replacement player (WAR): \n"; 
    cin >> winsAboveReplacement;
    cout << endl;
    cout << "Increase or decrease team's chances of winning a specific game (PWA): \n";
    cin >> PWA;
    cout << endl;   
    cout << "Strike-out to walk ratio: \n";
    cin >> StrikeOutToWalkRatio;
    cout << endl;
    cout << "Fly-ball ratio: \n";
    cin >> FlyBallRate;
    cout << endl;
    cout << "Runs created: \n";
    cin >> RunsCreated;
    cout << endl;
    cout << "Hits per nine innings: \n";
    cin >> HitsPerNineInnings;
    cout << endl;
    cout << "Walk rate: \n";
    cin >> WalkRate;
    cout << endl;
    cout << "Pop-up rate: \n";
    cin >> PopUpRate;
    cout << endl;
    cout << "Ground-ball rate: \n";
    cin >> GroundBallRate;
    cout << endl;
}

void BaseballPlayer::printSpecificPlayer()
{
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Games Played: " << gamesPlayed << endl;
    cout << "Games Started: " << gamesStarted << endl;
    cout << "Value over replacement player (VORP): " << VORP << endl;
    cout << "Number of wins over replacement player (WAR): " << winsAboveReplacement << endl;
    cout << "Increase or decrease team's chances of winning a specific game (PWA): " << PWA << endl;
    cout << "Strike-out to walk ratio is: " << StrikeOutToWalkRatio << endl;
    cout << "Fly-Ball rate is: " << FlyBallRate << endl;
    cout << "Runs Created: " << RunsCreated << endl;
    cout << "Hits per nine innings: " << HitsPerNineInnings << endl;
    cout << "Walk Rate: " << WalkRate << endl;
    cout << "Pop-up rate: " << PopUpRate << endl;
    cout << "Ground-ball rate: " << GroundBallRate <<"\n\n\n";
}

void BaseballPlayer::save(ofstream& outFile)//Wrote an outFile function (This was so hard to figure out. Very Proud of this.)
{

    /*Since I opened the save file outside of this function, I won't override the 
    file over and over again. If I open the save file inside of this function, every time
    I use this function (i.e. anytime I pass a new character through which is a neccessary step)
    it would override the previous outfile and only save one character.*/
        outFile << firstName; 
        outFile << " ";
        outFile << lastName;
        outFile << " ";
        outFile << gamesPlayed;
        outFile << " ";
        outFile << gamesStarted;
        outFile << " ";
        outFile << VORP;
        outFile << " ";
        outFile << winsAboveReplacement;
        outFile << " ";
        outFile << PWA;
        outFile << " ";
        outFile << StrikeOutToWalkRatio;
        outFile << " ";
        outFile << FlyBallRate;
        outFile << " ";
        outFile << RunsCreated;
        outFile << " ";
        outFile << HitsPerNineInnings;
        outFile << " ";
        outFile << WalkRate;
        outFile << " ";
        outFile << PopUpRate;
        outFile << " ";
        outFile << GroundBallRate;
        outFile << " ";
        outFile << endl;
    
}
    
//void BaseBallTeam::inputKeyboard(){}
BaseBallTeam::BaseBallTeam() {}
BaseBallTeam::~BaseBallTeam() {}//Desctructor 

//Print the class variables
void BaseballPlayer::print()
{
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Games Played: " << gamesPlayed << endl;
    cout << "Games Started: " << gamesStarted << endl;
    cout << "Value over replacement player (VORP): " << VORP << endl;
    cout << "Number of wins over replacement player (WAR): " << winsAboveReplacement << endl;
    cout << "Increase or decrease team's chances of winning a specific game (PWA): " << PWA << endl;
    //Wrote the 7 new stats
    cout << "Strike-out to walk ratio is: " << StrikeOutToWalkRatio << endl;
    cout << "Fly-Ball rate is: " << FlyBallRate << endl;
    cout << "Runs Created: " << RunsCreated << endl;
    cout << "Hits per nine innings: " << HitsPerNineInnings << endl;
    cout << "Walk Rate: " << WalkRate << endl;
    cout << "Pop-up rate: " << PopUpRate << endl;
    cout << "Ground-ball rate: " << GroundBallRate <<"\n\n\n";
}


//Constructor with values
BaseballPlayer::BaseballPlayer(string Name1, string Name2, int playedGames, int startedGames, double VORP_score, double WAR_score, double PWA_score, double STW_score, double FBR_score, int RC_score, int HPNI_score, int WR_score, int PUR_score, int GBR_score)
{
    firstName = Name1;
    lastName = Name2;
    gamesPlayed = playedGames;
    gamesStarted = startedGames;
    VORP = VORP_score;
    winsAboveReplacement = WAR_score;
    PWA = PWA_score;
    //Added seven more of these
    StrikeOutToWalkRatio = STW_score;
    FlyBallRate = FBR_score;
    RunsCreated = RC_score;
    HitsPerNineInnings = HPNI_score;
    WalkRate = WR_score;
    PopUpRate = PUR_score;
    GroundBallRate = GBR_score;
}

//Initilize all values
void BaseballPlayer::setPlayer(string Name1, string Name2, int playedGames, int startedGames, double VORP_score, double WAR_score, double PWA_score, double STW_score, double FBR_score, int RC_score, int HPNI_score, int WR_score, int PUR_score, int GBR_score)
{
    firstName = Name1;
    lastName = Name2;
    gamesPlayed = playedGames;
    gamesStarted = startedGames;
    VORP = VORP_score;
    winsAboveReplacement = WAR_score;
    PWA = PWA_score;
    //Added seven more of these
    StrikeOutToWalkRatio = STW_score;
    FlyBallRate = FBR_score;
    RunsCreated = RC_score;
    HitsPerNineInnings = HPNI_score;
    WalkRate = WR_score;
    PopUpRate = PUR_score;
    GroundBallRate = GBR_score;
}

//Default constructor
BaseballPlayer::BaseballPlayer()
{
    firstName = "Jean";
    lastName = "Nygen";
    gamesPlayed = 100;
    gamesStarted = 99;
    VORP = 999;
    winsAboveReplacement = 666;
    PWA = 777;
    //Added 7 more 
    StrikeOutToWalkRatio = 44.4;
    FlyBallRate = 55.5;
    RunsCreated = 10;
    HitsPerNineInnings = 20;
    WalkRate = 30;
    PopUpRate = 40;
    GroundBallRate = 50;
}   

int main()//Main Function
{
    int loop = 1;
    int answer;
    BaseBallTeam TeamOne;  

    //Creating the default team.
    BaseballPlayer PlayerOne;
    BaseballPlayer PlayerTwo("Joe", "Dimaggio", 21, 42, 6.4, 3.5, 23.5, 22.2, 22.2, 22, 9, 111, 24, 12);
    BaseballPlayer PlayerThree("Jack", "Ryan", 7, 7, 7.77, 7.77, 7.77, 7.77, 7.77, 7, 7, 7, 7, 7);
    BaseballPlayer PlayerFour("Captain", "Kirk", 87, 89, 65.75, 37.00, 98.50, 99.99, 89.7, 44, 23, 45, 89, 43);
    BaseballPlayer PlayerFive("Mr", "Spock", 100, 100, 100.01, 102.11, 101.11, 104.5, 107.8, 400, 402, 211, 309, 324);
    BaseballPlayer PlayerSix("Doctor", "McCoy", 98, 99, 45.5, 42.2, 23.32, 43.5, 55.6, 88, 90, 103, 118, 127);
    BaseballPlayer PlayerSeven("Taylor", "Swift", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    BaseballPlayer PlayerEight("Darth", "Vader", 123, 234, 345, 456, 567, 678, 789, 890, 999, 10000, 11100, 12000);
    BaseballPlayer PlayerNine("Cody", "Bentlage", 777, 777, 777, 777, 777, 777, 444, 444, 444, 444, 444, 444);
    
    while(loop==1)
    {
    cout << "What would you like to do:\n\n1. See the default team\n\n2. See the last team created with this program\n\n3. Change a specific character\n\n4. Build your own team\n\n5. See a specific characters statistics\n\n6. Close program\n\n";
    cin >> answer;

    if(answer==1)
    {
    PlayerOne.print();
    PlayerTwo.print();
    PlayerThree.print();
    PlayerFour.print();
    PlayerFive.print();
    PlayerSix.print();
    PlayerSeven.print();
    PlayerEight.print();
    PlayerNine.print();
    }
    
    if(answer==2)
    {
    TeamOne.inputFile();
    TeamOne.print();
    }

    if(answer==3)
    {
        int save;
    TeamOne.inputFile();
    TeamOne.specificPlayer();
    TeamOne.print();
    cout << "Would you like to save this data?\n\n1. Yes\n2. No\n\n";
    cin >> save;
    if(save==1){
    TeamOne.save();
    }
    else{cout << "Your data was not saved.\n\n";}
    }

    if(answer==4)
    {
        int save;
    TeamOne.inputKeyboard();
    TeamOne.print();
    cout << "Would you like to save this data?\n\n1. Yes\n2. No\n\n";
    cin >> save;
    if(save==1)
    {
    TeamOne.save();
    }
    else{cout << "Your data was not saved.\n\n";}
    }

    if(answer==5)
    {
    TeamOne.inputFile();
    TeamOne.printSpecificPlayer();
    }

    if(answer==6)
    {
        return 0;
    }

    cout << "Would you like to return to the main menu?\n\n";
    cout << "Enter '1' to do so.\n\n";

    cin >> loop;
    }
    
    return 0;
}
