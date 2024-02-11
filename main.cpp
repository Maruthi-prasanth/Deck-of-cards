#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>
#include <conio.h>
#include <fstream>

using namespace std;

class deck
{
	//intializing varaiables
	int i,q,j=1,players;
	//creating an array using string to store cards
	string a[100]={"R-2","R-3","R-4","R-5","R-6","R-7","R-8","R-9","R-10","R-JACK","R-QUEEN","R-KING","R-ACE",
					"B-2","B-3","B-4","B-5","B-6","B-7","B-8","B-9","B-10","B-JACK","B-QUEEN","B-KING","B-ACE",
					"P-2","P-3","P-4","P-5","P-6","P-7","P-8","P-9","P-10","P-JACK","P-QUEEN","P-KING","P-ACE",
					"O-2","O-3","O-4","O-5","O-6","O-7","O-8","O-9","O-10","O-JACK","O-QUEEN","O-KING","O-ACE"};
	public:
		void shuffle();
		void display();
		void display2();
	void shuffle1()
	{
	cout<<"Number of time you want to Shuffle : ";
    cin>>q;
    K:
	for(i=0;i<52;i++)
	{ 
		int random=i+(rand()%52-i);
		swap(a[i],a[random]);
	}
	cout<<"Cards are successfully shuffled....";
	}
void multishuffle_display()
{
    system("cls");
    shuffle();
    while(q)
    {
            for (i=0;i<52;i++)
            {
                if(i % 13 == 0) // Prints only 13 cards in a row
                {
                    cout<<"\n";
                }
                cout<<"   "<<a[i];

            }
            cout<<"\n\n\n";
            q--;

    }
    fflush(stdin);
    getchar();
            
}
};

void deck::shuffle()
{
	//loops runs between 0 and 52 till all cards are shuffled
	for(i=0;i<52;i++)
	{
		//storing index of randomly shuffled card 
		int random=i+(rand()%52-i);
		//swapping random card with a[i]
		swap(a[i],a[random]);
	}
	cout<<"\n\n Number of players to play (2-4) : ";
	cin>>players;
	//srand () sets the speed for rand fucntion
	srand(time(0));//time(0) 
	//if players are between 2 and 4 condition works
	if(players>=2 && players<=4)
	{
		for(i=0;i<52-(52-(players*11));i++)
		{
			//distributing 13 cards to each player
			if(i%13==0)
			{
				cout<<"\n\n"<<"Players:"<<j<<"  ";
				j++;
			}
			cout<<a[i]<<" ";
		}
	}
	else
	{
		cout<<"\nMinimum required number of players are 2,3 or 4..."<<endl;
		cout<<"\nso, please select minimum players..."<<endl;
	}
}

//displaying cards distributed to players
void deck::display()
{
	for(i=0;i<52;i++)
	{
		if(i%13==0)
		{
			cout<<"\n\n";
		}
		cout<<a[i]<<" ";
	}
}
//displaying before shuffling
void deck::display2()
{ 
	for(i=0;i<53;i++)
	{
		cout<<a[i]<<"\t";
	}
}

class card
{
	int comp[10],ind;
	//strring card ranks in an varaiable
	int val[10]={2,3,4,5,6,7,8,9,10},ace=1,king=10,queen=10,jack=10,index;
	int rank,i,j,n,m,points,suit,tot[4]={0,0,0,0},total[4]={0,0,0,0};
	char colour[10],color;
	float balance[100],bet[100];
	string name[100],name1[100];
	string p_rank[100],p_colour[100],p_card[10];
	public:
		card(){
			//getting random ranks and suits
			srand(time(NULL));
			rank=(1+(rand()%(int)(13)));
			suit=(1+(rand()%(int)(4)));
		}
     	int get_rank() {
     		return rank;
		}
		//returning ranks 
    string get_rank_string() {
      if (rank == 1) return "ACE";
      if (rank == 2) return "2";
      if (rank == 3) return "3";
      if (rank == 4) return "4";
      if (rank == 5) return "5";
      if (rank == 6) return "6";
      if (rank == 7) return "7";
      if (rank == 8) return "8";
      if (rank == 9) return "9";
      if (rank == 10) return "10";
      if (rank == 11) return "JACK";
      if (rank == 12) return "QUEEN";
      if (rank == 13) return "KING";
      else return "Uknown rank";
    }

    int get_suit() {
      return suit;
    }
	//returning suits
    string get_suit_string() {
      if (suit == 1) return "R";
      if (suit == 2) return "B";
      if (suit == 3) return "P";
      if (suit == 4) return "O";
      else return "Unknown suit";
    }

    //game 1 player details
    void player_details()
    {
    	//rules
    	cout<<"\n----->RULES OF THIS GAME<-----";
    	cout<<"\n\n1. Players count should be between 2 and 4";
    	cout<<"\n2. Your bidding amount should be less than or equal to your balance";
    	cout<<"\n3. After bidding the amount you need to select a card of your wish from deck\n";
    	op:
    	cout<<"\nEnter with number of players you want to play : ";
    	cin>>n;
    	if(n>=2 && n<=4)
    	{
    		for(i=1;i<=n;i++)
    		{
    			cout<<"\nEnter player-"<<i<<" name : ";
    			cin>>name[i];
    			cout<<"Enter your balance : ";
    			cin>>balance[i];
    			bett:
    			cout<<"Enter amount you want to bet : ";
    			cin>>bet[i];
    			if(bet[i]<=balance[i])
				{
					oh:
    				cout<<"Enter which colour do you want to choose : ";
    				cin>>p_colour[i];
    				cout<<"Enter card you want to choose : ";
    				cin>>p_rank[i];
				}
    			else
				{
    				cout<<"\nSelect sufficient bet...";
    				goto bett;
				}
    		}
    	}
    	else
    	{
    		cout<<"\nSelect players betweem 2 and 4 only....";
    		goto op;
		}

	}
	//game 2 player details
	void player_details1()
	{
		//rules
		cout<<"\n----->RULES OF THIS GAME<-----";
		cout<<"\n\n1. Players count should be between 2 and 4";
		cout<<"\n2. You need to select colour of card";
		cout<<"\n\t P-Purple\n\t B-Black\n\t O-Orange\n\t R-Red\n";
		op1:
		cout<<"\nEnter the number of players you want to play : ";
    	cin>>m;
    	if(m>=2 && m<=4)
    	{
    		for(i=0;i<m;i++)
    		{
    			total[i]=0;
    			cout<<"\nEnter player - "<<i+1<<" name : ";
    			cin>>name1[i];
    			co:
    			cout<<"Enter colour you want to choose : ";
    			cin>>colour[i];
    			//compares colours given and colours present
    			if(colour[i]=='p' || colour[i]=='P' || colour[i]=='r' || colour[i]=='R' || colour[i]=='o' || colour[i]=='O' || colour[i]=='b' || colour[i]=='B')
				{
					color=colour[i];
					//distributing 3 random cards
    				cout<<"\nYour random cards are...\n";
    				for(j=0;j<3;j++)
    				{
    					tot[j]=0;
    					index=rand()%9;
    					cout<<"\n"<<color<<" - "<<val[index];
    					tot[j]=tot[j]+val[index];
    					total[i]+=tot[j];
					}
					cout<<"\nYour total points are : "<<total[i]<<"\n";
					comp[i]=total[i];
				}
				else
				{
					cout<<"\nSelect appropriate colour...";
					goto co;
				}
			}
		}
		else
		{
    		cout<<"\nSelect players betweem 2 and 4 only....";
    		goto op1;
		}
	}
	//comparing game 1 results
	void compare()
	{
		for(i=1;i<=n;i++){
			if(p_colour[i] == get_suit_string()  && p_rank[i] == get_rank_string())
			{
				cout<<"\nPlayer -"<<name[i]<<" Wow!!! You win..";
				balance[i]=balance[i]+(2*bet[i]);
				cout<<"\nYour total balance is : "<<balance[i];
			}
			else
			{
				cout<<"\nPlayer - "<<name[i]<<" You loose";
				balance[i]=balance[i]-bet[i];
				cout<<"\nYour total balance is : "<<balance[i]<<"\n";
			}
		}
	}
	//comparing game 2 results
	void compare1()
	{
		int max=0,pos=0;
		for(i=0;i<m;i++)
		{
			if(comp[i]>max)
			{
				max=comp[i];
				pos=i;
			}
		}
		cout<<"\nMax points scored by are "<<max;
		cout<<"\nCongratulations...!!\nWinner of this game is "<<name1[pos];	
	}
};
int main()
{
	system("Color 8");
	Main:
	cout<<"\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
    cout<<"\t\t\t\t\xdb                                               \xdb\n";
    cout<<"\t\t\t\t\xdb       =============================           \xdb\n";
    cout<<"\t\t\t\t\xdb               A DECK OF CARDS		        \xdb\n";
    cout<<"\t\t\t\t\xdb       =============================           \xdb\n";
	cout<<"\t\t\t\t\xdb                                               \xdb\n";
    cout<<"\t\t\t\t\xdb                                               \xdb\n";
    cout<<"\t\t\t\t\xdb                                               \xdb";
    cout<<"\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n";
	deck d;
	card c;
	int choice;
        Menu:
        cout<<"\n\n1 Display before shuffling";
        cout<<"\n2 Shuffle and distribute";
        cout<<"\n3 shuffle";
        cout<<"\n4 Display after shuffling";
        cout<<"\n5 Games";
        cout<<"\n6 Exit";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        	case 1:
        		d.display();
        		goto Menu;
        	case 2:
        		d.shuffle();
        		goto Menu;
        	case 3:
        		d.shuffle1();
        		goto Menu;
        	case 4:
        		d.multishuffle_display();
        		goto Menu;
        	case 5:
        		int ch;
        		CM:
        		cout<<"\n1 Game:1";
        		cout<<"\n2 Game:2";
        		cout<<"\nEnter your choice : ";
        		cin>>ch;
        		switch(ch)
        		{
        			case 1:
        				c.player_details();
        				cout<<"\nRandom card is : "<<c.get_suit_string()<<"-";
        				cout<<c.get_rank_string()<<"\n";
        				c.compare();
        				getch();
        				system("CLS");
        				goto Main;
        				break;
        			case 2:
        				c.player_details1();
        				c.compare1();
        				getch();
        				system("CLS");
						goto Main;
						break;
					default:
						cout<<"\nEnter valid choice..."<<endl;
						goto CM;
						break;
				}

			case 6:
				cout<<"\nThank You Visit Again..";
				exit(0);
        	default:
        		cout<<"Enter valid choice..."<<endl;
        		goto Menu;
		}
    return 0;
}

