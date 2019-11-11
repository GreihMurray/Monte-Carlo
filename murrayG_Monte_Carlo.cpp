/* Monte Carlo simulator program. Generates a specified number of random 'dart throws' and then does the appropriate math to estimate pi. Greih Murray, 11/16/2017*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

//declaring other functions
void getRandomXY(float &x, float &y);
bool insideCircle(float x, float y);
int getInput();

int main(void){
    srand(time(NULL));
    int iter = getInput();
    float randX;
    float randY;
    float in = 0;
    float out = 0;
    float piEst = 0;

    //runs the specified number of times and calls each function appropriately.
    for(int i = 0; i < iter; i++){
        //gets random numbers for the coordinates
        getRandomXY(randX, randY);
        //runs function to make sure its in circle
        bool inCirc = insideCircle(randX, randY);

        //increments variable according to whether it was in or not
        if(inCirc == false){
            out++;
        }
        else if(inCirc == true){
            in++;
        }
    }

    //estimates pi
    piEst = ((4* in) / iter);

    cout << "Predicted value of pi: " << setprecision(5) << piEst;

}
/*Gets appropriate input from user
 *@return   desired number of iterations for use in calculation
 */
int getInput(){
    int iter = 0;
    while(true){
        cout << "Please enter a whole number: ";
        cin >> iter;

        if(!cin.fail() && iter > 0){
            return iter;
        }

        cin.clear();
        cin.ignore(200, '\n');
    }
}

/*Description of function
*@param randX   variable for first random number
*@param randY   variable for second random number
*/

void getRandomXY(float &x, float &y){
    x = ((float)rand() / RAND_MAX) * 2;
    y = ((float)rand() / RAND_MAX) * 2;
    return;
}

/*Description of function
*@param     randX    prevously generated random number
*@param     randY    previously generated random number 2
*@return    in       whether or not it was within the circle
*/

bool insideCircle(float x, float y){
    bool in = false;

    float dist = sqrt(pow(x - 1, 2) + pow(y - 1, 2));

    if(dist <= 1){
        in = true;
    }
    return in;
}
