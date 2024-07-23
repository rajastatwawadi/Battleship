#include<bits/stdc++.h>
using namespace std;

class ship{
    public:
    int n;
    vector <pair<int,int>> v;

    ship(){};
};

class player{
    public:
    ship crusier;
    ship destroyer;
    ship battleship;
    char placedships[5][5];

    player(){};

    void reset_board(){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                placedships[i][j]='*';
            }
        }
    }

    void take_ip(){

        //Reset board
        reset_board();

        //For crusier
        pair<int,int> co1;
        char orint1;
        cout << "Enter start co-ordinates of Crusier and orientaion(eg, row no. colomn no. h/v) - ";
        cin >> co1.first >> co1.second >> orint1;
        crusier.n=2;
        if(orint1=='h'){
            for(int i=0; i<crusier.n; i++){
                placedships[co1.first-1][co1.second-1]='@';
                crusier.v.push_back(co1);
                co1.second++;
            }
        }
        else{
            for(int i=0; i<crusier.n; i++){
                placedships[co1.first-1][co1.second-1]='@';
                crusier.v.push_back(co1);
                co1.first++;
            }
        }

        //For destroyer
        pair<int,int> co2;
        char orint2;
        cout << "Enter start co-ordinates of Destroyer and orientaion(eg, row no. colomn no. h/v) - ";
        cin >> co2.first >> co2.second >> orint2;
        destroyer.n=3;
        if(orint2=='h'){
            for(int i=0; i<destroyer.n; i++){
                placedships[co2.first-1][co2.second-1]='@';
                destroyer.v.push_back(co2);
                co2.second++;
            }
        }
        else{
            for(int i=0; i<destroyer.n; i++){
                placedships[co2.first-1][co2.second-1]='@';
                crusier.v.push_back(co2);
                co2.first++;
            }
        }

        //For batteship
        pair<int,int> co3;
        char orint3;
        cout << "Enter start co-ordinates of Battleship and orientaion(eg, row no. colomn no. h/v) - ";
        cin >> co3.first >> co3.second >> orint3;
        battleship.n=4;
        if(orint3=='h'){
            for(int i=0; i<battleship.n; i++){
                placedships[co3.first-1][co3.second-1]='@';
                battleship.v.push_back(co3);
                co3.second++;
            }
        }
        else{
            for(int i=0; i<battleship.n; i++){
                placedships[co3.first-1][co3.second-1]='@';
                battleship.v.push_back(co3);
                co3.first++;
            }
        }
    }

    void display(){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                cout << placedships[i][j] << " ";
            }
            cout << endl;
        }
    }
    
};

void run_game(player p1, player p2);
void display_board(char arr[5][5]);
int main()
{
    //Taking input
    player p1,p2;
    cout << "For player 1 - " << endl;
    p1.take_ip();
    p1.display();
    cout << "--------------------------------\n";

    cout << "For player 2 - " << endl;
    p2.take_ip();
    p2.display();
    cout << "--------------------------------\n";

    run_game(p1,p2);

}

void dispay_board(char arr[5][5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void run_game(player p1, player p2){

    //Making the board
    char board1[5][5];
    char board2[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            board1[i][j]='*';
            board2[i][j]='*';
        }
    }

    //Initial print
    cout << "Lets begin guessing!\n";
    cout << "Enter the co-cordinates as - row no. colomn no.\n";
    cout << "*: Not known\n";
    cout << "@: Hit\n";
    cout << "#: Miss\n";
    cout << "-------------------------\n";

    // Main logic
    int pts1=0;
    int pts2=0;
    while(pts1!=9 && pts2!=9){

        //For player 1
        pair <int,int> guess1;
        bool hit1=true;
        while(hit1){
            cout << "Player 1's turn - \n";
            dispay_board(board1);
            cout << "Enter the co-ordinates - ";
            cin >> guess1.first >> guess1.second;

            auto itcrusier1 = find(p2.crusier.v.begin(),p2.crusier.v.end(),guess1);
            auto itdestroyer1 = find(p2.destroyer.v.begin(),p2.destroyer.v.end(),guess1);
            auto itbattleship1 = find(p2.battleship.v.begin(),p2.battleship.v.end(),guess1);
            if(itcrusier1 != p2.crusier.v.end()){
                p2.crusier.v.erase(itcrusier1);
                pts1++;
                board1[guess1.first-1][guess1.second-1]='@';
                cout << "It's a hit!\n";
            }
            else if(itdestroyer1 != p2.destroyer.v.end()){
                p2.destroyer.v.erase(itdestroyer1);
                pts1++;
                board1[guess1.first-1][guess1.second-1]='@';
                cout << "It's a hit!\n";
            }
            else if(itbattleship1 != p2.battleship.v.end()){
                p2.battleship.v.erase(itbattleship1);
                pts1++;
                board1[guess1.first-1][guess1.second-1]='@';
                cout << "It's a hit!\n";
            }
            else{
                cout << "It's a miss!\n";
                board1[guess1.first-1][guess1.second-1]='#';
                hit1=false;
            }

            int ship_sank1=int(p2.crusier.v.empty()) + int(p2.destroyer.v.empty()) + int(p2.battleship.v.empty());
            dispay_board(board1);
            cout << ship_sank1 << " ship sank!\n";
            cout << "Player 1 score - " << pts1 << endl;
            cout << "------------------------------\n";
            if(pts1==9){
                break;
            }
        }

        if(pts1==9){
            break;
        }
        
        //Player 2
        pair <int,int> guess2;
        bool hit2=true;
        while(hit2){
            cout << "Player 2's turn - \n";
            dispay_board(board2);
            cout << "Enter the co-ordinates - ";
            cin >> guess2.first >> guess2.second;

            auto itcrusier2 = find(p1.crusier.v.begin(),p1.crusier.v.end(),guess2);
            auto itdestroyer2 = find(p1.destroyer.v.begin(),p1.destroyer.v.end(),guess2);
            auto itbattleship2 = find(p1.battleship.v.begin(),p1.battleship.v.end(),guess2);
            if(itcrusier2 != p1.crusier.v.end()){
                p1.crusier.v.erase(itcrusier2);
                pts2++;
                board2[guess2.first-1][guess2.second-1]='@';
                cout << "It's a hit!\n";
            }
            else if(itdestroyer2 != p1.destroyer.v.end()){
                p1.destroyer.v.erase(itdestroyer2);
                pts2++;
                board2[guess2.first-1][guess2.second-1]='@';
                cout << "It's a hit!\n";
            }
            else if(itbattleship2 != p1.battleship.v.end()){
                p1.battleship.v.erase(itbattleship2);
                pts2++;
                board2[guess2.first-1][guess2.second-1]='@';
                cout << "It's a hit!\n";
            }
            else{
                cout << "It's a miss!\n";
                board2[guess2.first-1][guess2.second-1]='#';
                hit2=false;
            }

            int ship_sank2=int(p1.crusier.v.empty()) + int(p1.destroyer.v.empty()) + int(p1.battleship.v.empty());
            dispay_board(board2);
            cout << ship_sank2 << " ship sank!\n";
            cout << "Player 2 score - " << pts2 << endl;
            cout << "------------------------------\n";
            if(pts2==9){
                break;
            }
        }
        
    }

    //Final print
    if(pts1==9){
        cout << "Player 1 wins!\n";
    }
    else{
        cout << "Player 2 wins!\n";
    }
}