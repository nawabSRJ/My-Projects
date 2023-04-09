#include <stdio.h>
#include <stdlib.h>
int match(int);
void absent();
struct BCA
{
    int id;
    char name[30];
    char At;
};
int uid;
  struct BCA stu[71] = {{1,"Anshika Nagbanshi",},{2,"Aisha",},{3,"Mahima",},{4,"Maalav",},{5,"Saad_M",},{6,"Sparsh",},{7,"Sumati",},{8,"Pratham",},{9,"Pari",},{10,"Aakansha",},{11,"Shrey",},{12,"Raksha",},{13,"Disha_T",},{14,"Harshit",},{15,"NoNAME",},{16,"Ansh_M",},{17,"Priyanshu",},{18,"Khushi_K",},{19,"Vaibhav",},{20,"Prerna",},{21,"Divyanshi",},{22,"Disha_P",},{23,"Rishab",},{24,"Sumit",},{25,"Mansi",},{26,"Geetika",},{27,"Utkarsh",},{28,"Ashwani",},{29, "Rishita"},{30,"Sanskar",},{31, "Dhruv"},{32,"Ananya",},{33,"Archita",},{34,"Vatan",},{35,"Srajan",},{36,"Khushi_M",},{37,"NoNAME",},{38,"Vaishnavi",},{39,"Anand",},{40,"Prince",},{41,"Anchal",},{42,"Aryan",},{43,"Krishanshu",},{44,"Ayushi",},{45,"Aparna",},{46,"Maivish",},{47,"Shashi",},{48,"Khushi_N",},{49,"Vanshika",},{50,"Shruti",},{51,"Shaheen",},{52,"Lakshya",},{53,"Arpit",},{54,"Shatakshi",},{55,"NoNAME",},{56,"Ashmit",},{57,"Ansh_T",},{58,"Ayush",},{59,"Aditya",},{60,"Saad_B",},{61,"Ananya",},{62,"Vishal",},{63,"Vishakha",},{64,"Garima",},{65,"Apurva",},{66,"Vishakha",},{67,"Aditi",},{68,"Prathit",},{69,"Maitri",},{70,"Riya",},{71,"Kanishka",}};
int main()
{
    FILE *fp;
    int j,i,k,choose,ac=0,pc=0;

    label_1:
    printf("\n\n\t\t<-------DE-PROX ATTENDANCE------->\n\n");
    printf("\tChoose :\n(1).MARK ATTENDANCE\n(2).END ATTENDANCE\n(3).Show Today's Attendance\n(4).Put Attendance\n");
    scanf("%d", &choose);
   
    switch (choose)
    {
        
        case 1: 
  
      for (j = 0; j < 71; j++)
      { 
        reallot:
        printf("\n\nEnter your id to mark attendance:\nPress 0 to Stop attendance\t");
        scanf("%d", &uid);

        match(uid);
         for (k = 0; k < 71; k++)
        { 
          absent(uid);
        }
       if(uid>71)
       {
        printf("\n\t\tALERT!!!\nInvalid Id...you have to enter again enter again!!!\n");
        goto reallot;
       }
        else if(uid==0)
        {
          goto label_1;
       }
       
       
    }

    case 2:
        printf("\n\t\tThank You for Marking Attendance with DE-PROX\n\n");
        printf("\t\t       <-----created by nawabSRJ----->");
        break;

    case 3:
        printf("Today's Class Strength:\n");
        printf("ID\t  Name\t    Attendance\n");
        for (i = 0; i < 71; i++)
        {
           
            if(stu[i].At == 'P')
            {
              pc++;
            printf("%d  \t  %s  \t  %c\n", stu[i].id, stu[i].name, stu[i].At);
            }
        }
          printf("\nThe List Of Absentees is:\n");
          printf("ID\t  Name\t    Attendance\n");
          for (i = 0; i < 71; i++)
        {
          if(stu[i].At == 'A')
          {
            ac++;
            printf("%d  \t  %s  \t  %c\n", stu[i].id, stu[i].name, stu[i].At);
          }
        
        }
        printf("\n\n\t--> Present : %d\n",pc);
        printf("\n\n\t--> Absent : %d\n",ac);
        goto label_1;

        case 4:
        
        // fp=fopen("19FEB3.csv","w");
        fp=fopen("test24-3-23.xls","w");
        fprintf(fp,"ID\t    Name\t    Attendance\n");
          for (i = 0; i < 71; i++) 
          {
            fprintf(fp,"%d    \t    %s  \t     %c\n", stu[i].id, stu[i].name, stu[i].At);
          }
          fclose(fp);
          printf("\n\n<-----DATA ENTERED----->\n\n");
        printf("\n\t\tThank You for Marking Attendance with DE-PROX\n\n");
        printf("\t\t    <-----created by nawabSRJ----->");
   }
}

int match(int n)
{
    int j;
    for(j=0;j<71;j++)
    {
      if(n==stu[j].id)
      {
      stu[j].At = 'P';
      }
    }
}
void absent()
{
    int i;
    for(i=0;i<71;i++)
    {
    if(stu[i].At != 'P')
    {
        stu[i].At = 'A';
    }
    }
}