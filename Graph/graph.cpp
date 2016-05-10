

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



#include <SFML/Graphics.hpp>
#include <vector>


#define C4996
#define SFML_STATIC
using namespace std;

class graph //class of our graph
{
private:
    int size;
public:
    int **tab; //matrix neighbours
        graph(int length) //constructor
        {
        tab=new int *[length];
        for(int i=0; i<length; i++)
            tab[i] = new int[length];
            size=length;
        }
    	~graph() //destructor
        {
            for(int i=0; i<size; i++)
                delete[] tab[i];

                delete[]tab;

        }
        //Few methods
        void print(); //showing matrix of neighbours
        void set_zero(); //setting all entrances as 0
        void show_direction(); //better version of print();
        void edge_set(int x, int y);
        int degree(int vx); //showing degree of vertex (not used)
};
        void graph::print()
             {
                for(int i=0; i<size; i++)
                    {
                        for(int j=0; j<size; j++)
                            {
                                cout<<tab[i][j] ;
                            }
                            cout<<"\n";
                    }

            }
        void graph::set_zero()
            {
                for(int i=0; i<size; i++)
                    {
                        for(int j=0; j<size; j++)
                            {
                                tab[i][j]=0;
                            }
                    }

            }
        void graph::edge_set(int x, int y)
        {
                tab[x][y]=1;
        }
        int graph::degree(int vx)
        {
            int deg=0;
            for(int i=0; i<size; i++)
                deg+=tab[vx-1][i];

                    return deg;
        }


           void graph::show_direction()
             {
                for(int i=0; i<size; i++)
                    {
                        cout<<i+1<<":  ";
                        for(int j=0; j<size; j++)
                            {

                                if(tab[i][j])
                                    cout<<j+1<<" ";
                            }
                            cout<<endl;
                    }

            }




int main()
{       //FILE OPERATORS
        fstream graph_def;
        graph_def.open("graph_def.txt");
        //INT FOR ROW COUNTING
        int LineNumb=0;
        //String to get vertices
        string line_buf;
        //Getting number of connection one by one
        string token;
        int buf;

        //Using highest number to determine number of vertices
        int VecNumb=0;
        int guard=0;
    if(graph_def.good())
    {
            //COUNTING LINE NUMBER
        while(!graph_def.eof()) //while file is not ended
        {
                        getline(graph_def, line_buf); //getting line from file
                        LineNumb++; //increasing integer which represents number of line
                        istringstream iss(line_buf);
                                        while (getline(iss, token, ' '))
                                        {
                                            buf=atoi(token.c_str());
                                                if(buf==0)
                                                    {
                                                    guard=1;  //variable used to check if number of vertex starts with 0 or with 1
                                                    }
                                                if(buf>VecNumb)
                                                    VecNumb=buf; //We know what is the number pf vertices

                                        }
        }
        //Creating object in class
            graph basic(VecNumb);
            basic.set_zero();

        //Rewind of file
            graph_def.seekg(0);

        int counter=0;
        int whichvertex;

         while(!graph_def.eof())
        {
                        getline(graph_def, line_buf);
                        istringstream iss(line_buf);
                                        while (getline(iss, token, ' '))
                                        {
                                            buf=atoi(token.c_str());
                                                if(counter==0)
                                            {
                                                    whichvertex=buf;
                                                    counter++;

                                                }

                                        switch(guard)
                                                    {case 0:
                                                        basic.edge_set(whichvertex-1, buf-1);

                                                        break;
                                                     case 1:
                                                        basic.edge_set(whichvertex, buf);

                                                        break;
                                                    }
                                        }
                counter=0;

        }
        basic.show_direction();

        basic.print();
   //GRAPHIC
        //texture for vertix
        sf::Texture vtexture;
        vtexture.loadFromFile("texture.png");
        //Coordinates of vertix
        int randposX;
        int randposY;
            srand(time(NULL));
//VERTEX


vector <sf::CircleShape> vertices; //creating container for circle shapes
vector <sf::Text> numbers;   //creating container for numbers
vector <sf::VertexArray> connect;  //creating container for connections
stringstream ss;   //string buffer
        int **positionstab=new int*[3];
            for(int i=0; i<2; i++)
                positionstab[i]=new int[VecNumb+1];  //creating array to save positions of vertices

//loading font for numbers
sf::Font font;
        font.loadFromFile("arial.ttf"); //loading
        sf::Text mytext;


        for(int i=0; i<VecNumb; i++)
            {   randposX=(int)(rand() / (RAND_MAX + 1.0) * 950);
                randposY=(int)(rand() / (RAND_MAX + 1.0) * 750);
                    positionstab[0][i]=randposX;
                    positionstab[1][i]=randposY;


            //DRAWING VERTICES
            //parameters for circles
            sf::CircleShape vcircle(120);
            vcircle.setTexture(&vtexture);
            vcircle.setScale(0.1, 0.1);
            vcircle.setPosition(randposX, randposY);
            vertices.push_back(vcircle);
            //DRAWING NUMBERS ON VERTICES

                    ss<<i+1;
                        //Parameters for text
                        mytext.setFont(font);
                        mytext.setCharacterSize(15);
                        mytext.setStyle(sf::Text::Bold);
                        mytext.setColor(sf::Color::Black);
                        mytext.setPosition(randposX+5, randposY+5);
                        mytext.setString(ss.str());
                        numbers.push_back(mytext);
                                ss.str("");


    }
        for(int i=0; i<VecNumb; i++)
       cout<<positionstab[0][i]<<" "<<positionstab[1][i]<<endl;

       sf::VertexArray lines(sf::Lines, 2);

            for(int i=0; i<VecNumb; i++)
                {
                    for(int j=0; j<VecNumb; j++)
                        {
                            if(basic.tab[j][i] && j!=i)
                            {
                                lines[0].position = sf::Vector2f((positionstab[0][i]+5), (positionstab[1][i]+5));
                                lines[1].position = sf::Vector2f((positionstab[0][j]+5), (positionstab[1][j]+5));
                                connect.push_back(lines);
                                    //creating connections
                            }


                        }
                }



 sf::RenderWindow window(sf::VideoMode(1000, 800), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)

                window.close();

        }

        // clear the window with black color
        window.clear(sf::Color(62, 62, 62));

          for(int i=0; i<LineNumb; i++)
       {
           window.draw(connect[i]); //drawing connections
       }

       for(int i=0; i<VecNumb; i++)
       {
           window.draw(vertices[i]); //drawing vertices
           window.draw(numbers[i]); //drawing numbers

       }


        window.display();
    }
    exit(0);

    //Free memory
for(int i=0; i<VecNumb; i++)
        {
            delete[] positionstab[i];
        }
            delete[]positionstab;

        connect.clear();
        numbers.clear();
        vertices.clear();
        graph_def.close();






    }
    else
    {
     cout<<"FILE DOESN'T WORK";
    }





return 0;

}
