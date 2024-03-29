#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void createMatrix(int arr[][4]) {
    int n=15;
    int num[n],i,j;
    for(i=0;i<15;i++)
        num[i]=i+1;

    srand(time(NULL));

    int lastIndex=n-1,index;

    for(i=0;i<4;i++)
        for(j=0;j<4;j++) {
            if(lastIndex>=0) {
                index=rand()%(lastIndex+1);
                arr[i][j]=num[index];
                num[index]=num[lastIndex--];
            }
        }
    arr[i-1][j-1]=0;
}

void showMatrix(int arr[][4]) {
    int i,j;
    cout << "----------------------" << endl;
    for(i=0;i<4;i++) {
        cout << "༏  ";
        for(j=0;j<4;j++) {
            if(arr[i][j]!=0)
                cout << arr[i][j] << " ༏ ";
            else
                cout << "   ༏ ";
        }
        cout << endl;
    }
    cout << "----------------------" << endl;
}

int winner(int arr[][4]) {
    int i,j,k=1;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++,k++)
            if(arr[i][j]!=k && k!=16)
                break;
        if(j<4)
            break;
    }
    if(j<4)
        return 0;
    return 1;
}

void swap(int &x, int &y) {
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "\a\a\a";
}

int readEnteredKey() {
    char c;
    cin >> c;
    return c;
}

int shiftUp(int arr[][4]) {
    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
                break;
        if(j<4)
            break;
    }
    if(i==3)
        return 0;
    swap(arr[i][j],arr[i+1][j]);
    return 1;
}

int shiftDown(int arr[][4]) {
    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
                break;
        if(j<4)
            break;
    }
    if(i==0)
        return 0;
    swap(arr[i][j],arr[i-1][j]);
    return 1;
}

int shiftRight(int arr[][4]) {
    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
                break;
        if(j<4)
            break;
    }
    if(j==0)
        return 0;
    swap(arr[i][j],arr[i][j-1]);
    return 1;
}

int shiftLeft(int arr[][4]) {
    int i,j;
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
                break;
        if(j<4)
            break;
    }
    if(j==3)
        return 0;
    swap(arr[i][j],arr[i][j+1]);
    return 1;
}

void gameRule(int arr[][4]) {
    system("clear");
    int x=readEnteredKey();
    int i,j,k=1;
    cout << "                 RULE OF THIS GAME                 \n";
    cout << "\n1.You can move only 1 step at a time by arrow key ";
    cout << "\nMove Up   : by Up arrow key ";
    cout << "\nMove Down : by Down arrow key";
    cout << "\nMove Left : by Left arrow key";
    cout << "\nMove Right: by Right arrow key";

    cout << "\n2.You can move number at empty position only ";
    cout << "\n";
    cout << "\n3.For each valid move : your total number of move will decreased by 1 \n";
    cout << "4.Wining situation : ";
    cout << "number in a 4*4 matrix should be in order from 1 to 15 ";
    cout << "\n\n            winning situation:         \n";

    cout << "----------------------" << endl;
    for(i=0;i<4;i++) {
        cout << "༏  ";
        for(j=0;j<4;j++) {
            if(arr[i][j]!=0)
                cout << 4*i+j+1 << " ༏ ";
            else
                cout << "   ༏ ";
        }
        cout << endl;
    }
    cout << "----------------------" << endl;
    cout << "\n5.You can exit the game at any time by pressing 'E' or 'e' ";
    cout << "\nSo Try to win in minimum no of move \n";
    cout << "\n         Happy gaming , Good Luck\n";
    cout << "\nEnter any key to start.....  🆗 : ";
    x=readEnteredKey();
}

int main() {
    int arr[4][4];
    int maxTry=400;
    char name[20];
    system("clear");

    cout << "Enter Your Good Name: ";
    cin >> name;

    while(1) {
        createMatrix(arr);
        gameRule(arr);

        while(!winner(arr)) {
            system("clear");
            if(!maxTry)
                break;

            cout << "\n\n  welcome  " << name << "  ,  Move remaining : " << maxTry << "\n\n";
            showMatrix(arr);

            int key=readEnteredKey();

            switch(key) {
                case 69:
                case 101:
                    cout << "\a\a\a\a\a\a\n     Thanks for Playing ! \n\a";
                    cout << "\nHit 'Enter' to exit the game \n";
                    key=readEnteredKey();
                    exit(0);

                case 65:
                    if(shiftUp(arr))
                        maxTry--;
                    break;
                case 66:
                    if(shiftDown(arr))
                        maxTry--;
                    break;
                case 67:
                    if(shiftRight(arr))
                        maxTry--;
                    break;
                case 68:
                    if(shiftLeft(arr))
                        maxTry--;
                    break;
                default:
                    cout << "\n\n      \a\a❌ Not Allowed \a\a\a\a";
            }
        }
        if(!maxTry)
            cout << "\n\a          YOU LOSE !          \a\a\n";
        else
        {
            cout << "\n\a!!!!!!!!!!!!!Congratualization !!!!!!!!!!!!!\n\a";
            cout << "\a               You have Won      \a\a\a ";
        }
        char check;
        cout << "\nwant to play again ? \n";
        cout << "enter 'y' to play again:  ";
        cin >> check;
        if(check!='y' && check!='Y')
            break;
        maxTry=400;
    }
    return 0;
}
