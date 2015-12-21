#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <getopt.h>
#include <allegro.h>

struct cards
{
    int card_value[10];
    char card_name[10];
    char card_suit[10];
    int card_tally;
    BITMAP *card_pic[10];
};

struct cards hand[2];
short decks=1;
short cards_used[14]= {0};
int player_cash = 500;


void endgame()
{
    if (player_cash < 1)
        alert("You lost it all big guy! Better luck next time!", NULL, NULL, "&Ok", NULL, 'o', 'k');

    else if (player_cash < 501)
        alert("Game Over: Not enough cards to continue",
              "In the end, you didn't win a dime but at least",
              "you still have the shirt on your back",
              "&Ok", NULL, 'o', 'k');

    else
    {
        char cash[100];
        snprintf(cash, sizeof(cash), "You are leaving with $%d", player_cash);
        alert("Amazing! You beat the house!", cash, NULL, "&Ok", NULL, 'o', 'k');
    }
    exit(EXIT_SUCCESS);
}


void tally (int a)
{
    int x=0, y=0;
    for (x=0; x<10; x++)
    {
        y = y + hand[a].card_value[x];
    }
    hand[a].card_tally = y;
}

void check_for_ace (int a)
{
    int x;
    for (x=0; x<10; x++)
    {   if (hand[a].card_name[x] =='A')
        {
            int y;
            int z = 10;
            for (y=0; y<10; y++)
                z = z + hand[a].card_value[y];
            if (z < 22)
                hand[a].card_value[x]=11;
            else
                hand[a].card_value[x]=1;
        }
    }
}

void draw_card (int a)
{
    short z = 1 + rand () % 13;
    short x=0;
    short safe_guard=0;
    short y= 1 + rand () % 4;
    char card_suit = 'd';

    while (hand[a].card_value[x] !=  0)
        x++;

    while ((cards_used[z] > (decks * 4)) && (safe_guard < 50))
    {
        z = 1 + rand () % 13;
        safe_guard++;
    }

    if (safe_guard > 49)
        endgame();

    cards_used[z] = cards_used[z] + 1;
    safe_guard=0;

    /*Now Assign Values and Names to the Cards*/

    if ((z > 1) && (z < 10))
    {
        hand[a].card_value[x]=z;
        hand[a].card_name[x]=((char) '0' + z);
    }
    else if (z == 10)
    {
        hand[a].card_value[x]=z;
        hand[a].card_name[x]='T';
    }
    else if (z == 11)
    {
        hand[a].card_value[x]=10;
        hand[a].card_name[x]='J';
    }
    else if (z == 12)
    {
        hand[a].card_value[x]=10;
        hand[a].card_name[x]='Q';
    }
    else if (z == 13)
    {
        hand[a].card_value[x]=10;
        hand[a].card_name[x]='K';
    }
    else if (z == 1)
    {
        /*Function 'check_for_ace' deals with this more properly*/
        hand[a].card_value[x]=1;
        hand[a].card_name[x]='A';
    }

    /*Assign Suits Randomly*/
    if (y == 1)
        card_suit='c';
    if (y == 2)
        card_suit='d';
    if (y == 3)
        card_suit='h';
    if (y == 4)
        card_suit='s';

    check_for_ace(a);

    /*Link the Picture*/
    char pic[20];
    snprintf(pic, sizeof(pic), "card/%c%c.bmp", hand[a].card_name[x], card_suit);
    hand[a].card_pic[x]=load_bmp(pic, NULL);

    tally(a);
}

void display_hands ()
{
    int x;
    int y=10;

    clear_bitmap(screen);

    /*Dealer hand*/
    for (x=0; hand[0].card_name[x]!=0; x++)
    {
        blit(hand[0].card_pic[x], screen, 0,0,y,10,73,97);
        y=y+75;
    }

    /*Player Hand, displayed on bottom of screen*/
    y=10;

    for (x=0; hand[1].card_name[x]!=0; x++)
    {
        blit(hand[1].card_pic[x], screen, 0,0,y,300,73,97);
        y=y+75;
    }

    textprintf_ex(screen, font, 335, 2, makecol(0, 0, 0), makecol(248, 248, 230), "         ");
    textprintf_ex(screen, font, 335, 10, makecol(0, 0, 0), makecol(248, 248, 230), "  Cash   ");
    textprintf_ex(screen, font, 335, 18, makecol(0, 0, 0), makecol(248, 248, 230), "   %d    ", player_cash);
    textprintf_ex(screen, font, 335, 26, makecol(0, 0, 0), makecol(248, 248, 230), "         ");
}




void dealer_turn()
{
    while (hand[0].card_tally < 17)
    {
        draw_card(0);
        display_hands();
    }
    if (hand[0].card_tally > 21)
    {
        hand[0].card_tally = 0;
        alert("Dealer Busts!", NULL, NULL, "&Ok", NULL, 'o', 'k');
    }
}


void player_turn()
{
    int action=1;

    while (action != 2 && hand[1].card_tally < 21)
    {
        action=alert("What will you do?", NULL, NULL, "&Hit", "&Stand", 'h', 's');
        if (action == 1)
            draw_card(1);
        display_hands();
        tally(1);
    }

    if (hand[1].card_tally > 21)
        alert("Player Busts!", NULL, NULL, "&Ok", NULL, 'o', 'k');

}

int main(int argc, char **argv)
{

    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 400,400,0,0);

    argc -= optind;
    argv += optind;
    if (argv[0])
        decks = atoi (argv[0]);


    srand(time(NULL));


    int x=0;
    while (x != -1)
    {
        display_hands();
        int bet = 50;
        int alert_val = alert3("Please place your bet", NULL, NULL, "&50", "&100", "15&0", '5', '1', '0');
        bet = alert_val * 50;
        player_cash=player_cash - bet;
        display_hands();
        draw_card(0);
        draw_card(1);
        draw_card(1);
        display_hands();
        player_turn();
        if (hand[1].card_tally < 22)
        {
            dealer_turn();
            display_hands();
        }
        if ((hand[0].card_tally > hand[1].card_tally) || (hand[0].card_tally == hand[1].card_tally
                || hand[1].card_tally > 21))
        {
            alert("Dealer wins!", NULL, NULL, "&Ok", NULL, 'o', 'k');
        }
        else
        {
            alert("Player wins!", NULL, NULL, "&Ok", NULL, 'o', 'k');
            player_cash = player_cash + (bet * 2);
            display_hands();
        }


        if (player_cash < 1)
            endgame();
        int i;
        for (i=0; i < 2; i++)
        {
            for (x=0; x < 10; x++)
            {
                hand[i].card_name[x] = 0;
                hand[i].card_suit[x] = 0;
                hand[i].card_value[x] = 0;
            }
            hand[i].card_tally = 0;
        }

        if (alert("Continue or Quit?", NULL, NULL, "&Continue", "&Quit", 'c', 'q') == 2)
            exit(EXIT_SUCCESS);
    }


    int loop=0;
    for (loop=0; loop < 11; loop++)
    {
        destroy_bitmap(hand[0].card_pic[loop]);
        destroy_bitmap(hand[1].card_pic[loop]);
    }



    return 0;
}
END_OF_MAIN();
