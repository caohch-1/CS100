#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <time.h>
#include <functional>

using namespace std;

#define MAX_ROWS 3
#define MAX_COLS 10
#define MAX_STUDENTS 30

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define NOTHING 0
#define APPLEPIE 1
#define BEEF 2
#define CURRY 3


typedef int MEALTYPE;

class Fmart; // this line is used to identify Fmart as a type name, since class Player and class Student have pointers to Fmart.

// ------------------------------Helper functions--------------------------------------//
int randInt(int min, int max)
{
    if (max < min)
		swap(max, min);
    return rand() % (max - min + 1) + min;
}
// -----------------------------Class Declarations-------------------------------------//
class Player 
{
public:

    //constructor
    Player(Fmart* fp);
    
    //destructor
    ~Player();

    //accessors
    int row() const;            
    int col() const;            
    int lives() const;          
    int score() const;
    MEALTYPE mealInHand() const;

    //mutators
    void pickup(MEALTYPE meal);
    void move(int dir);

    void deliver();
    void decLife();

private:
    int m_row;
    int m_col;
    int m_lives;
    int m_score;
    MEALTYPE m_mealInHand;
    Fmart* m_fp;
};

class Student{
public:
    //constructor
    Student(Fmart* fp, int row, int col);

    //destructor
    ~Student();

    //accessors
    int row() const;
    int col() const;
    MEALTYPE typeWanted() const;

    //mutators
    void moveForward();   

private:
int m_row;
int m_col;
MEALTYPE m_mealWant;
Fmart* m_fp;
    // TODO: add private members for Student class.
};

class Fmart{
public:
    //constructor
    Fmart();
    
    //destructor
    ~Fmart();

    //accessors
    Player* getPlayer() const;
    int numberOfStudents() const;
    bool studentAt(int row, int col) const;
    Student* getStudent(int row,int col) const;

    //mutators
    bool addStudent();
    bool deleteStudent(int row, int col);
    void display();
    void play();
    
private:
    Player* m_player;
    Student* m_students[MAX_STUDENTS];
    int m_numStudents;
};

//---------------------------Implementions of Fmart-------------------------------------//

Fmart::Fmart()  
{
    m_player= new Player(this);
    *m_students=NULL;
    m_numStudents=0;
    // This constructor:
    // (1) adds a new player
    // (2) initializes m_students to be NULL (or nullptr)
    // (3) initializes the number of students to be 0.
    // TODO: finish the implementation.
}

Fmart::~Fmart()
{
    // TODO: delete everything you dynamically created.
}


Player* Fmart::getPlayer() const
{
    // This function returns a pointer to the player.
    // TODO: finish the implementation.
    return m_player; // This line is only for the program to compile.
}

int Fmart::numberOfStudents() const
{
    // This function returns the number of students.
    // TODO: finish the implementation.
    return m_numStudents; // This line is only for the program to compile.
}

bool Fmart::studentAt(int row, int col) const
{
    for(int i=0;i<m_numStudents;i++){
        if(m_students[i]->col()==col && m_students[i]->row()==row){
            return true;
        }
    }
    // TODO: check if there is a student at (row, col), if so, return true, else return false.
    return false; // This line is only for the program to compile.
}

Student* Fmart::getStudent(int row, int col) const
{
    for(int i=0;i<m_numStudents;i++){
        if(m_students[i]->col()==col && m_students[i]->row()==row){
            return m_students[i];
        }
    }
    return NULL;
}

bool Fmart::addStudent()
{
    if(m_numStudents<MAX_STUDENTS){
        m_students[m_numStudents]=new Student(this,randInt(1,3),10);
        m_numStudents++;
        return true;
    }
    else{
        return false;
    }
    // TODO: add a new student at the rightmost column. 
    // If Student number is greater than MAX_STUDENTS, just do nothing and return false.
    // If you added a student successfully, return true.
    // You will need randInt() to get a random number.
    // This line is only for the program to compile.
}

bool Fmart::deleteStudent(int row, int col)
{
    int delete_index;
    for(int i=0;i<m_numStudents;i++){
        if(m_students[i]->col()==col && m_students[i]->row()==row){
            delete_index=i;
            break;
        }
        if(i==m_numStudents-1){
            return false;
        }
    }
    m_numStudents--;

    for(int i=0;i<m_numStudents;i++){
        if(i>=delete_index){
            m_students[i]=m_students[i+1];
        }
    }

    /*for(int i=0;i<m_numStudents;i++){
        if(m_students[i]->row()==row && m_students[i]->col()>col){
            m_students[i]->moveForward();
        }
    }*/
    
    
    // TODO: delete a student at position (row, col) from m_students.
    // If no student is at this position, return false.
    // If there is a student, delete the student, and shift all students after it to the left.
    // Maybe there are extra things to deal with?
    // YOUR CODE HERE
    return true; // This line is only for the program to compile.
}

/** Display the game grid
 * It will display grids, players and students.
 * There are a few blanks for you to fill in.
 */
void Fmart::display()
{
    char** disp = new char* [3];
    for (int i = 0; i < 3; i++)
    {
        disp[i] = new char[10];
        for (int j = 0; j < 10; j++){
            disp[i][j] ='.';
            if(i+1==m_player->row() && j+1==1){
                disp[i][j]='P';
            }
        }
    }

    // TODO: Visit each student and:
    // (Assume this student is at (r, c))
    // If this student wants the meal the player is atholding, change disp[r-1][c-1] to '@'.
    // If this student doesn't want the meal, change disp[r-1][c-1] to 'S'.
    for(int i=0;i<m_numStudents;i++){
        if(m_player->mealInHand()==m_students[i]->typeWanted()){
            disp[m_students[i]->row()-1][m_students[i]->col()-1]='@';
        }
        else{
            disp[m_students[i]->row()-1][m_students[i]->col()-1]='S';
        }
    }   
    
    // TODO: Check the type of meal the player is holding.
    // (Assume the player is at (r, c))
    // If it is APPLEPIE, change disp[r-1][c-1] to 'A';
    // If it is BEEF, change disp[r-1][c-1] to 'B';
    // If it is CURRY, change disp[r-1][c-1] to 'C';
    // If it is NOTHING, change disp[r-1][c-1] to 'P';
    if(m_player->mealInHand()==APPLEPIE){
        disp[m_player->row()-1][m_player->col()-1]='A';
    }
    else if(m_player->mealInHand()==BEEF){
        disp[m_player->row()-1][m_player->col()-1]='B';
    }
    else if(m_player->mealInHand()==CURRY){
        disp[m_player->row()-1][m_player->col()-1]='C';
    }
    else if(m_player->mealInHand()==NOTHING){
        disp[m_player->row()-1][m_player->col()-1]='P';
    }


    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 10; j++)
            cout << disp[i][j];
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
        delete[] disp[i];
    delete[] disp;
}

void Fmart::play()
{
    addStudent(); //Adds the first student.
    while (m_player->lives() > 0)
    {
        display();
        cout << "You have " <<m_player->lives() <<" lives, and your score is " <<m_player->score()<<"."<<endl;
        cout << "make a move (a, b, c, u, d, g): " << endl;
        string input;
		getline(cin, input);
        cout << endl << endl << endl;

        char option = input[0]; //Here, option is 'a', 'b', 'c', 'u', 'd', or 'g'.
        

        if(option=='u'){
            m_player->move(UP);
        }
        else if(option=='d'){
            m_player->move(DOWN);
        }
        else if(option=='a'){
            m_player->pickup(APPLEPIE);
        }
        else if(option=='b'){
            m_player->pickup(BEEF);
        }
        else if(option=='c'){
            m_player->pickup(CURRY);
        }
        else if(option=='g'){
            m_player->deliver();
        }
          
        // TODO: Let your player behave according to 'option'.
        // You should call member functions of class Player.


        // Moves all students forward
        if(option=='a' || option=='b' || option=='c' || option=='u' || option=='d' || option=='g'){
            for (int i = 0; i < m_numStudents; i++){
                int detector = m_numStudents; // Detect whether a student has reached col 1 and is deleted.
                m_students[i]->moveForward();
                if(m_numStudents != detector)
                    i--;                      // If so, move back 1 iteration.
            }
        }

        // A 30% chance for adding a new student
        if(randInt(1,10) <= 3)
            addStudent();
    }
    cout << "You lose. Your score is " << m_player->score() <<". Press any key to quit." << endl;
    getchar();
}

//---------------------------Implementions of Student -------------------------------------//
Student::Student(Fmart* fp, int row, int col)
{
    m_row=row;
    m_col=col;
    m_fp=fp;
    int judge=randInt(1,3);
    if(judge==1){
        m_mealWant=APPLEPIE;
    }
    else if(judge==2){
        m_mealWant=BEEF;
    }
    else if(judge==3){
        m_mealWant=CURRY;
    }
    // TODO: this constructor initializes a student, at (row, col).
    // You should randomly choose 1 meal type, and store it in the student object.
    // fp is a pointer to the Fmart this student is in.
}

Student::~Student()
{
    // TODO: delete everything you dynamically created.
}

int Student::row() const
{
    // TODO: return the row number.
    return m_row; // This line is only for the program to compile.
}

int Student::col() const
{
    // TODO: return the column number.
    return m_col; // This line is only for the program to compile.
}

MEALTYPE Student::typeWanted() const
{
    // TODO: return the type of meal this student wants.
    return m_mealWant; // This line is only for the program to compile.
}

void Student::moveForward()
{
    m_col--;
    if(m_col==1){
        m_fp->getPlayer()->decLife();
        m_fp->deleteStudent(m_row,1);
    }
    // TODO: 
    // Move the student forward for one step.
    // If this student reaches the first column, player's lives will be decreased by 1, and this student will be deleted.
    // YOUR CODE HERE
    return; // This line is only for the program to compile.
}

//---------------------------Implementions of Player -------------------------------------//

Player::Player(Fmart* fp)
{
    m_row=2;
    m_col=1;
    m_lives=3;
    m_score=0;
    m_mealInHand=NOTHING;
    m_fp=fp;
    // TODO: this constructor initializes the player.
    // For example, the player should be at (2, 1), have 3 lives, and have 0 score.
    // Please consider other parameters to initialize.
}
    

Player::~Player()
{
    // TODO: delete everything you dynamically created.
}

int Player::row() const
{
    // TODO: return the row number.
    return m_row; // This line is only for the program to compile.
}     
int Player::col() const
{
    // TODO: return the column number.
    return m_col; // This line is only for the program to compile.
}
   

int Player::lives() const
{
    // TODO: return the number of lives.
    return m_lives; // This line is only for the program to compile.
}          

int Player::score() const
{
    // TODO: return the score.
    return m_score; // This line is only for the program to compile.
}

MEALTYPE Player::mealInHand() const
{
    // TODO: return the type of meal in player's hand.
    return m_mealInHand; // This line is only for the program to compile.
}

void Player::pickup(MEALTYPE meal)
{
    m_mealInHand=meal;
    // TODO: pick up a box meal of type 'meal'.
    return ; // This line is only for the program to compile.
}

void Player::move(int dir) 
{
    if(m_row!=1 && dir==1){
        m_row--;
    }
    else if(m_row!=3 && dir==2){
        m_row++;
    }
    
    // TODO: Move the player upwards of downwards.
    // dir will be either UP or DOWN.
    return; // This line is only for the program to compile.
}

void Player::deliver()
{
    for(int i=0;i<10;i++){
        if(m_fp->studentAt(m_row,i+1) && m_mealInHand==m_fp->getStudent(m_row,i+1)->typeWanted()){
        m_fp->deleteStudent(m_row,i+1);
        m_score=m_score+10;
        m_mealInHand=NOTHING;
        break;    
        }
    }
    // TODO:
    // Send the meal to left-most student in that row.
    // If (1) He/She doesn't want this meal 
    //    (2) No student at this row
    //    (3) Player has no meal in hand
    // just do nothing and returns.
    // If success, delete the student, increment m_score by 10, and set player's hand to NOTHING
    return; // This line is only for the program to compile.
}

void Player::decLife()
{
    m_lives--;
    // TODO: decrease player's life by 1.
    return; // This line is only for the program to compile.
}
// ------------------------------Main function--------------------------------------//
int main()
{
    srand(time(NULL));
    Fmart f;
    f.play();
}