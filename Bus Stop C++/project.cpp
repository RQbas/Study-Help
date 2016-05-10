#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>


using namespace std;

class full_plan //class containing all basic informations about bus stops, (2 tables for path and for value(Floyd algotrithm)
{
    private:
    int fconnections;
    public:
    double **ftab_value;
    int **ftab_destination;
    string *fncities; //names of cities
        full_plan(int fsize) //constructor
        {
        fncities= new string[fsize];
        string *ncities; //names of cities
        ftab_value=new double *[fsize];
        ftab_destination=new int *[fsize];
        for(int i=0; i<fsize; i++) //creating dynamic arrays with constructor
            {ftab_value[i] = new double[fsize];
            ftab_destination[i] = new int[fsize];
            }
        fconnections=fsize;
        }
    	~full_plan() //destructor
        {
            delete[]fncities;
            for(int i=0; i<fconnections; i++)
                {delete[] ftab_value[i];
                delete[] ftab_destination[i];
                }
                delete[]ftab_destination;
                delete[]ftab_value;
}
void filling(int tsize, string *basic, string *destination); //class methods
void tabp_fill(int tsize, int **tab); //initial path filling
void tabv_fill(int tsize, double **tab); //initial value filling
void drawptab(int tsize, int **tab); //methods used in testing- shows 2d arrays
void drawvtab(int tsize, double **tab); //similar but for values
};

int counter(int tsize, string *names) //function counting duplicates
{
        int j=0;
        for(int i=0; i<tsize; i++)
        {
            if(names[i]==names[i+1])
            {
                j++;
            }

        }
    return j;
    }
void cleaners(int tsize, string *names) //procedure cleaning array of string
{
    for(int i=0; i<tsize; i++)
        names[i]="";
}
void cleanerd(int tsize, double *tab) //procedure cleaning double array
{
    for(int i=0; i<tsize; i++)
        tab[i]=0;
}

void repeat(int tsize, string *names, string *fncities) //procedure detecting and deleting duplicates in bus stop connections
    {
        int j=0;
        for(int i=0; i<tsize; i++)
        {
            if(names[i]!=names[i+1])
            {
                fncities[i-j]=names[i];
            }
            else
            {
            j++;
            }

        }

    }
void pathfill(int tsize, string *dictionary, string first, string input, int **tab) //filling path array with possible connections
{
    int k=0;
    for(int i=0; i<tsize; i++)
    {
     if(first==dictionary[i])
     {
        k=i; //saving index of position
     }
    }
    for(int j=0; j<tsize; j++)
    {
            if(input==dictionary[j])
            {
                tab[k][j]=k; //comes from floyd warshall algorithm (path table section)

            }
    }


}

void valuefill(int tsize, string *dictionary, string first, string input, double source, double **tab) //procedure fillin' array with values (in our case hours)
{
     int k=0;
     int x=0;
    for(int i=0; i<tsize; i++)
    {
     if(first==dictionary[i])
     {
        k=i;
     }
    }

    for(int j=0; j<tsize; j++)
    {
            if(input==dictionary[j])
            {
                tab[k][j]=source;
                x++;

            }
    }
}

void full_plan::filling(int tsize, string *basic, string *destination)// putting names of bus stops into object
    {
        for(int i=0; i<tsize;i++)
            {
                destination[i]=basic[i];

            }
    }
void full_plan::tabv_fill(int tsize, double **tab) //filling value 2d array with initial data
{

    for(int i=0; i<tsize; i++)
    {
        for(int j=0; j<tsize; j++)
            {
                if(i==j)
                {
                    tab[i][j]=0;
                }
                else
                {
                    tab[i][j]=UINT_MAX; //infinity representation

                }
            }
    }
}
void full_plan::tabp_fill(int tsize, int **tab)
{
for(int i=0; i<tsize; i++)
    {
        for(int j=0; j<tsize; j++)
            {

                tab[i][j]=-1;
            }
    }
}
void full_plan::drawptab(int tsize, int **tab) //drawing path table
{
    for(int i=0; i<tsize; i++)
    {
        for(int j=0; j<tsize; j++)
            {

                cout<<tab[i][j]<<"  ";
            }
        cout<<'\n';
    }
}
void full_plan::drawvtab(int tsize, double **tab) //drawing value table, both used by me to see if it works correctly
{
    for(int i=0; i<tsize; i++)
    {
        for(int j=0; j<tsize; j++)
            {
                if(tab[i][j]==UINT_MAX)
                    cout<<"#"<<"  ";
                else
                    cout<<tab[i][j]<<"  ";
            }
        cout<<'\n';
    }
}
void previouspath(int i, int j, int **tab, string *base, double **tabv) // procedure in floyd warshall algoritm to investigate whole needed
//combination of bus stops using path array 2d
{
  if(i == j) cout <<base[i]<<" ";
  else if(tab[i][j] == -1) cout << "NO PATH";
  else
  {
    previouspath(i,tab[i][j], tab, base, tabv); //recursion, calling same procedure with different parameters by itself
cout << " -("<<tabv[tab[i][j]][j]<<")-> ";
cout << base[j];
  }
}

void copying(int tsize, double **tab1, double **tab2) //procedure of copying from 1 double array to the different one
{
    for(int i=0; i<tsize; i++)
        for(int j=0; j<tsize; j++)
    {
        tab1[i][j]=tab2[i][j];
    }
}


int main()
{       //FILE OPERATORS
        fstream timetab; //creating steam
        timetab.open("timetable.txt"); //opening source file

        //string used in program
        string buff_line;
        string tkn;
        string star="*"; //sign of ending bus stop list
        string buff;
        // variables used in program, most of them used operation on file, to obtain data properly
        double buffor=0;
        int linenumber=0; //number of lines
        int busnumb=0; //number of bus stops
        int divider=0; //first kind of variable which segregates if it's string or double
        int add_divider=0; //used to put values into array properly (without empty cells)
        int connections=0; //number of connections for 1 bus stop
        int cnt_tabd=0; //used to put bus stop names into array properly (without empty cells)
        int indp_bustp=0; //number of all possible bus stops (without duplicates)
        int q=0; //occurs in loop only


        bool guard=true; //guard used for recognising main bus stop (on which connections are based)





        if(timetab.good()) //if source file was opened correctly
    {


while(!timetab.eof()) //till it's not end of file
{
            getline(timetab, buff_line); //take line from a file and put it into string buffor
            linenumber++; //increase number of lines
            istringstream iss(buff_line); //putting into buffor
             if (!buff_line.compare(star)) //if there is star
                    {
                        busnumb++; //number of bus stops
                    }
}



            timetab.seekg(0); //refreshing stream


        string *namestab= new string[linenumber*10]; //array with city names
        string *namestab_rep= new string[linenumber*10]; //array with city names after deleting duplicates
        double *hourtab= new double[linenumber*10]; //array of hours per connections
        double *fhourtab= new double[linenumber*10]; //full array of hours
        while(!timetab.eof())
        { //whole procedure is based on dividing strings from double variables using simple properties of odd/even variable divider
                 getline(timetab, buff_line);
                    if (buff_line.compare(star))
                    {
                        connections++; //increase connections if there is star in txt file
                        istringstream iss(buff_line);
                            while(getline(iss, tkn, ' ')) //dividing into tokens
                            {
                                if(guard)
                                {
                                namestab[cnt_tabd]=tkn;
                                cnt_tabd++;
                                guard=false;
                                }
                                else
                                {
                                    if(divider%2)
                                    {
                                        buffor=atof(tkn.c_str());
                                        fhourtab[add_divider]=buffor;
                                        add_divider++;
                                        divider++;
                                    }
                                    else
                                    {
                                        divider++;
                                        namestab[cnt_tabd]=tkn;
                                        cnt_tabd++;
                                    }
                                }

                            }

                    }
                    else
                    {
                        guard=true;
                       // divider=0;
                        //add_divider=0;
                        //connections=0;
                    }
            };

full_plan base(connections); //creating object of class
//SORTING INPUT
connections=0;
divider=0;
add_divider=0;
cnt_tabd=0;
//sorting bus stops names
for(int i=0; i<linenumber-busnumb; i++)
{
 for(int j=0; j<linenumber-busnumb; j++)
            {
                if(namestab[i]<namestab[j])
                    {
                        buff_line= namestab[j];
                        namestab[j]= namestab[i];
                        namestab[i]= buff_line;

                    }
            }
            }
            indp_bustp=linenumber-(busnumb+counter(linenumber-busnumb, namestab)); //number of whole bus stops
//works
            repeat(linenumber-busnumb, namestab, namestab_rep); //deleting duplicates
            base.filling(linenumber-busnumb, namestab_rep, base.fncities);//works- putting names of bus stops into object
            base.tabp_fill(indp_bustp, base.ftab_destination);//filling path array
            base.tabv_fill(indp_bustp, base.ftab_value); //filling value array
           // base.drawptab(indp_bustp, base.ftab_destination);
          // base.drawvtab(indp_bustp, base.ftab_value);






timetab.seekg(0);
while(!timetab.eof())
        {
                 getline(timetab, buff_line);
                    if (buff_line.compare(star))
                    {
                        connections++;
                        istringstream iss(buff_line);
                            while(getline(iss, tkn, ' '))
                            {
                                if(guard)
                                {
                                namestab[cnt_tabd]=tkn;
                                cnt_tabd++;
                                guard=false;
                                }
                                else
                                {
                                    if(divider%2)
                                    {
                                        buffor=atof(tkn.c_str());
                                        hourtab[add_divider]=buffor;
                                        add_divider++;
                                        divider++;

                                    }
                                    else
                                    {
                                        divider++;
                                        namestab[cnt_tabd]=tkn;
                                        cnt_tabd++;

                                    }




                                }

                            }

                    }
                    else
                    {
                        guard=true;
                        for(int i=1; i<connections; i++)
                        {
                            pathfill(indp_bustp, base.fncities, namestab[0], namestab[i], base.ftab_destination); //filling path array
                            valuefill(indp_bustp, base.fncities, namestab[0], namestab[i], hourtab[q], base.ftab_value); //filling value array
                            q++;
                        }
                        divider=0;
                        cnt_tabd=0;
                        add_divider=0;
                        connections=0;
                        q=0;
                    }

            };
//base.drawptab(indp_bustp, base.ftab_destination);
//base.drawvtab(indp_bustp, base.ftab_value);
        double **copy_vtab=new double*[indp_bustp]; //copying value to other array to save initial positions
        for(int i=0; i<indp_bustp; i++)
            copy_vtab[i]= new double[indp_bustp];
        copying(indp_bustp, copy_vtab, base.ftab_value);//copying from value array to our new made one
//Floyd_warshall procedure
for(int k=0; k<indp_bustp; k++)
{
    for(int i=0; i<indp_bustp; i++)
    {
        for(int j=0; j<indp_bustp; j++)
        {
            if(base.ftab_value[i][k]==UINT_MAX || base.ftab_value[k][j]==UINT_MAX)
                continue;
            if(base.ftab_value[i][j]>base.ftab_value[i][k]+base.ftab_value[k][j])
            {
                base.ftab_value[i][j]=base.ftab_value[i][k]+base.ftab_value[k][j];
                base.ftab_destination[i][j]=base.ftab_destination[k][j];
            }
        }
    }
}


//If someones wants to see how it works
//base.drawptab(indp_bustp, base.ftab_destination);

//base.drawvtab(indp_bustp, base.ftab_value);

    //User initial interface
    string user_bus_start;
    string user_bus_finish;
    cout<<"Enter your bus stop"<<'\n';
    cin>>user_bus_start;
    cout<<"Enter your finish bus stop"<<'\n';
    cin>>user_bus_finish;
    int xstart=0;
    int xfinish=0;

    for(int i=0; i<indp_bustp; i++) //getting bus stops names
    {
        if(base.fncities[i]==user_bus_start)
        {
            xstart=i;
        }
        if(base.fncities[i]==user_bus_finish)
        {
            xfinish=i;
        }
    }
       previouspath(xstart, xfinish, base.ftab_destination, base.fncities, copy_vtab); //recursion algorithm for path directions
    }
    cout<<'\n';
    system("pause");
}





