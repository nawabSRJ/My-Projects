#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

// through a Doubly Linked List
struct node
{
    char song_name[50];
    char lyrics[100];
    struct node *next;
    struct node *prev;
};
struct node *newnode;
struct node *front = NULL;
struct node *rear = NULL;
struct node *temp = NULL;
struct node *link = NULL;

void insert_song();
void display();
void search_song(struct node *front);

class LYP
{
public:
    void insert_song();
    void display();   //to display all songs

    void song_search();  //display selected
};

void LYP ::insert_song()
{
    FILE *fp;
    newnode = (struct node *)malloc(sizeof(struct node));
    fflush(stdin);
    cout << "Enter the song name :\n";
    gets(newnode->song_name);
    newnode->next = NULL;
    newnode->prev = NULL;

    if (front == NULL)
    {
        front = newnode;
        link = newnode;
    }
    else
    {
        link->next = newnode;
        newnode->prev = link;
        link = newnode;
    }
    fflush(stdin);
    cout << "Enter the Lyrics :\n";
    gets(newnode->lyrics);

    fp = fopen("songs.txt", "a+");
    if (fp == NULL)
    {
        cout << "File Could not be Opened!!!";
    }
    fflush(stdin);

    fprintf(fp, "|%s\n", newnode->song_name);
    cout << "\n";

    fprintf(fp, "%s\n\n\n", newnode->lyrics);

    cout << "\n\n\n";
    fclose(fp);
}

void LYP ::display()
{
    FILE *fp;
    char c;
    fp = fopen("songs.txt", "r");
    if (fp == NULL)
    {
        printf("File could not be opened!");
        return;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }

    fclose(fp);
}


void LYP ::song_search()
{
    FILE *fp;
    char search_req[50];
    char line[100];
    char lyrics[1000];
    int found = 0;

    fflush(stdin);
    printf("Enter the name of the song:\n");
    gets(search_req);

    fp = fopen("songs.txt", "r");
    if (fp == NULL)
    {
        printf("File could not be opened!");
        return;
    }

    while (fgets(line, 100, fp) != NULL)  //reading each line of the file to find :
    {
        if (strstr(line, search_req) != NULL) // substring of search request
        {
            printf("Song found!\n");
            found = 1;
            break;
        }
    }

    if (found)
    {
        fgets(lyrics, 1000, fp);
        printf("%s", lyrics);
    }
    else 
    {
        printf("Song Not Found!\n");
    }


    fclose(fp);
}

int main()
{
    LYP obj;
    int choose;
    printf("\n\t\t<<-------LYRIC PLAYER------->>\n");
    while (1)
    {
        printf("\n\n1:Add Song\n2:Display All Songs\n3:Search to Play\n4:Exit\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            obj.insert_song();
            break;

        case 2:
            obj.display();
            break;

        case 3:
            obj.song_search();
            break;

        case 4:
            exit(0);
        }
    }
    return 0;
}
