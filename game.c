#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#define EOF (-1)
int level(int*,int);
int check(char,int,int);


typedef struct
{
    char* name;
    char taken[3];
    int rollno, score, time;

}stud;
stud s1;
int total = 0;
void main()
{
    FILE *pt;
    //errno_t err;

    int i, j, diff = 0, ques_no, total = 0,corr,percent=0;
    int store[5][10], count[5] = { 0,0,0,0,0 }, marks = 0;
    char ans;
    int n1;
    s1.score = 0;
    //if ((err = fopen_s(&pt, "DATA.txt", "a+"))!=NULL) { exit(0); }
    fopen_s(&pt,"DATA.txt", "a+");
    if (pt == NULL)
    {
        printf("error\n");
        exit(0);
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            store[i][j] = 50;
        }
    }


    printf("Hello! Welcome to Level Up Quiz\n");
    printf("Enter Your Details\nName:");
    s1.name = (char*)malloc(50*sizeof(char));
    gets(s1.name);
    s1.name = (char*)realloc(s1.name, strlen(s1.name) + 1);
    printf("Roll Number:");
    scanf_s("%d", &s1.rollno);
    printf("To read the rules press 1.To start the quiz press 2\n");
    scanf_s("%d", &n1);
    if(n1==1)
    {
        printf("Level up quiz :-\n1.You will be given 10 questions to answer.\n2.Each question has four options of which one is correct.\n3.Each correct answer will increase the difficulty level of the next question.\n4.Each wrong answer will decrease the difficulty level of the next question.\n5.Marks increase with increase in difficulty level in increments of 10,15,20,25,30.\n6.Your score will be displayed at the end of the quiz along with the total marks of questions you have attempted.\n7.Every answer must be given in capital letter of its option.\n");
    }

    printf("The quiz will begin now\n");

    srand(time(0));


    for (i = 1; i <= 10; i++)
    {
        again:
        ques_no = (rand() % 10);
        //printf("|%d|\n",ques_no);
        for (j = 0; j < count[diff]; j++)
        {
            if (ques_no == store[diff][j])
            {
                goto again;
            }
        }

        store[diff][count[diff]] = ques_no;
        printf("\n\nQ%d : ", i);
        marks=level(&diff,ques_no);
        printf("\nEnter your answer.\n");
        scanf_s(" %c", &ans);
        corr=check(ans, diff, ques_no);
        if (corr == 1)
        {
            if (diff <= 3)
            {
                diff++;
            }

            s1.score = s1.score + marks;
            total = total + marks;
        }
        else
        {
            if (diff > 0)
            {
                diff--;
            }
            total = total + marks;
        }

        count[diff]++;

    }//End of i loop
    percent = (s1.score / total) * 100;
    printf("\n%d\n", &percent);
    fprintf(pt, "\n%s\t\t%d\t\t%d\t\t\t%d \t\t\t\t\t%d", s1.name, s1.rollno, s1.score, total,percent);

    fclose(pt);
    printf("You have completed your test\n");
    printf("\nYour result: %s\t%d\t%d\t%d\n", s1.name, s1.rollno, s1.score, total);


}
int level(int *pd, int ques)
{
    int marks=0;

    switch (*pd)
    {
        case 0:
            switch (ques)
            {
                case 0:
                    printf("If A + B means A is the mother of B; A - B means A is the brother B; A % B means A is the father of B and A x B means A is the sister of B, which of the following shows that P is the maternal uncle of Q?\t(Level 0)\n\nA]Q - N + M x P\nB]P + S x N - Q\nC]P - M + N x Q\nD]Q - S % P\n\n");
                    break;

                case 1:
                    printf("In the following questions choose the word which is the exact OPPOSITE of the given word :\n RELINQUISH\t(Level 0)\n\nA]Abdicate\nB]Renounce\nC]Possess\nD]Deny\n\n");
                    break;

                case 2:
                    printf("Alfred buys an old scooter for Rs. 4700 and spends Rs. 800 on its repairs. If he sells the scooter for Rs. 5800, his gain percent is:\t(Level 0)\n\nA]32/7 %\nB]60/11 %\nC]10 %\nD]12 %\n\n");
                    break;

                case 3:
                    printf("For which of the following disciplines is Nobel Prize awarded?\t(Level 0)\n\nA]Physics and Chemistry\nB]Physiology or Medicine\nC]Literature, Peace and Economics\nD]All of the above\n\n");
                    break;

                case 4:
                    printf("Hitler party which came into power in 1933 is known as :\t(Level 0)\n\nA]Labour Party\nB]Nazi Party\nC]Ku-Klux-Klan\nD]Democratic Party\n\n");
                    break;

                case 5:
                    printf("Friction can be reduced by changing from\t(Level 0)\n\nA]sliding to rolling\nB]rolling to sliding\nC]potential energy to kinetic energy\nD]dynamic to static\n\n");
                    break;

                case 6:
                    printf("A right triangle with sides 3 cm, 4 cm and 5 cm is rotated the side of 3 cm to form a cone. The volume of the cone so formed is:\t(Level 0)\n\nA]12pie cu. cm\nB]15pie cu. cm\nC]16pie cu. cm\nD]20pie cu. cm\n\n");
                    break;
                case 7:
                    printf("In a shower, 5 cm of rain falls. The volume of water that falls on 1.5 hectares of ground is:\t(Level 0)\n\nA]75 cu. m\nB]750 cu. m\nC]7500 cu. m\nD]75000 cu. m\n\n");
                    break;

                case 8:
                    printf("In the question below a sentence has been given in Active/Passive voice. From the given alternatives, choose the one which best expresses the given sentence in Passive/Active voice :\nAfter driving professor Kumar to the museum she dropped him at his hotel.\t(Level 0)\n\nA]After being driven to the museum, Professor Kumar was dropped at his hotel.\nB]Professor Kumar was being driven dropped at his hotel.\nC]After she had driven Professor Kumar to the museum she had dropped him at his hotel.\nD]After she was driven Professor Kumar to the museum she had dropped him at his hotel.\n\n");
                    break;

                case 9:
                    printf("The problem consists of three statements. Based on the first two statements, the third statement may be true, false, or uncertain.\nTanya is older than Eric\nCliff is older than Tanya\nEric is older than Cliff\nIf the first two statements are true, the third statement is\t(Level 0)\n\nA]true\nB]false\nC]uncertain\n\n");
                    break;
            }
            marks = 10;
            break;

        case 1:
            switch (ques)
            {
                case 0:printf("Father is aged three times more than his son Ronit. After 8 years, he would be two and a half times of Ronit's age. After further 8 years, how many times would he be of Ronit's age?\t(Level 1)\n\nA]2 times\nB]5/2 times\nC]11/4 times\nD]3 times\n\n",ques+1);
                    break;

                case 1:printf("Extreme old age when a man behaves like a fool\t(Level 1)\n\nA]Imbecility\nB]Senility\nC]Dotage\nD]Superannuation\n\n");
                    break;

                case 2:printf("In each question below is given a statement followed by two conclusions numbered I and II. You have to assume everything in the statement to be true, then consider the two conclusions together and decide which of them logically follows beyond a reasonable doubt from the information given in the statement\nStatements: In a one day cricket match, the total runs made by a team were 200. Out of these 160 runs were made by spinners.\nConclusions:\nI.\t80 PERCENT of the team consists of spinners\nII.\tThe opening batsmen were spinners.\t(Level 1)\n\nA]Only conclusion I follows\nB]Only conclusion II follows\nC]Either I or II follows\nD]Neither I nor II follows\nE]Both I and II follow\n\n");
                    break;

                case 3:printf("Which scientist discovered the radioactive element radium?\t(Level 1)\n\nA]Isaac Newton\nB]Albert Einstein\nC]Benjamin Franklin\nD]Marie Curie\n\n");
                    break;

                case 4:printf("A motorboat, whose speed in 15 km/hr in still water goes 30 km downstream and comes back in a total of 4 hours 30 minutes. The speed of the stream (in km/hr) is:\t(Level 1)\n\nA]4\nB]5\nC]6\nD]10\n\n");
                    break;

                case 5:printf("Brass gets discoloured in air because of the presence of which of the following gases in air?\t(Level 1)\n\nA]Oxygen\nB]Hydrogen sulphide\nC]Carbon dioxide\nD]Nitrogen\n\n");
                    break;

                case 6:printf("Which of the following is a non metal that remains liquid at room temperature?\t(Level 1)\n\nA]Phosphorous\nB]Bromine\nC]Chlorine\nD]Helium\n\n");
                    break;

                case 7:printf("An aeroplane covers a certain distance at a speed of 240 kmph in 5 hours. To cover the same distance in 1 hours, it must travel at a speed of:\t(Level 1)\n\nA]300 kmph\nB]360 kmph\nC]600 kmph\nD]720 kmph\n\n");
                    break;

                case 8:printf("66 cubic centimetres of silver is drawn into a wire 1 mm in diameter. The length of the wire in metres will be:\t(Level 1)\n\nA]84\nB]90\nC]168\nD]336\n\n");
                    break;

                case 9:printf("In the following the question choose the word which best expresses the meaning of the given word.\nCORPULENT\t(Level 1)\n\nA]Lean\nB]Gaunt\nC]Emaciated\nD]Obese\n\n");
                    break;
            }
            marks = 15;
            break;

        case 2:
            switch (ques)
            {
                case 0:printf("Statements: All bags are cakes. All lamps are cakes\nConclusions:\nI.\tSome lamps are bags\nII.\tNo lamp is bag.\t(Level 2)\n\nA]Only conclusion I follows\nB]Only conclusion II follows\nC]Either I or II follows\nD]Neither I nor II follows\nE]Both I and II follow\n\n",ques+1);
                    break;

                case 1:printf("A man standing at a point P is watching the top of a tower, which makes an angle of elevation of 30deg with the man's eye. The man walks some distance towards the tower to watch its top and the angle of the elevation becomes 60deg. What is the distance between the base of the tower and the point P?\t(Level 2)\n\nA]43 units\nB]8 units\nC]12 units\nD]Data inadequate\nE]None of these\n\n");
                    break;

                case 2:printf("A bag contains 2 red, 3 green and 2 blue balls. Two balls are drawn at random. What is the probability that none of the balls drawn is blue?\t(Level 2)\n\nA]10/21\nB]11/21\nC]2/7\nD]5/7\n\n");
                    break;

                case 3:printf("What is the probability of getting a sum 9 from two throws of a dice?\t(Level 2)\n\nA]1/6\nB]1/8\nC]1/9\nD]1/12\n\n");
                    break;

                case 4:printf("Who is largely responsible for breaking the German Enigma codes, created a test that provided a foundation for artificial intelligence?\t(Level 2)\n\nA]Alan Turing\nB]Jeff Bezos\nC]George Boole\nD]Charles Babbage\n\n");
                    break;

                case 5:printf("Which of the following metals forms an amalgam with other metals?\t(Level 2)\n\nA]Tin\nB]Mercury\nC]Lead\nD]Zinc\n\n");
                    break;

                case 6:printf("The Homolographic projection has the correct representation of\t(Level 2)\n\nA]shape\nB]baring\nC]area\nD]distance\n\n");
                    break;

                case 7:printf("The landmass of which of the following continents is the least?\t(Level 2)\n\nA]Australia\nB]Asia\nC]Africa\nD]North America\n\n");
                    break;

                case 8:printf("How many 4-letter words with or without meaning, can be formed out of the letters of the word, 'LOGARITHMS', if repetition of letters is not allowed?\t(Level 2)\n\nA]40\nB]400\nC]5040\nD]2520\n\n");
                    break;

                case 9:printf("Pick out the most effective word from the given words to fill in the blank to make the sentence meaningfully complete.\nThe miser gazed ...... at the pile of gold coins in front of him.\t(Level 2)\n\nA]avidly\nB]admiringly\nC]thoughtfully\nD]earnestly\n\n");
                    break;
            }
            marks = 20;
            break;

        case 3:
            switch (ques)
            {
                case 0:printf("In this series, you will be looking at both the letter pattern and the number pattern. Fill the blank in the middle of the series or end of the series\nB2CD, B5CD, BC6D _____, BCD4.\t(Level 3)\n\nA]B2C2D\nB]BC3D\nC]B2C3D\nD]BCD7\n\n",ques+1);
                    break;

                case 1:printf("What is laughing gas?\t(Level 3)\n\nA]Nitrous Oxide\nB]Carbon trioxide\nC]Sulphur dioxide\nD]Hydrogen peroxide\n\n");
                    break;

                case 2:printf("David gets on the elevator at the 11th floor of a building and rides up at the rate of 57 floors per minute. At the same time, Albert gets on an elevator at the 51st floor of the same building and rides down at the rate of 63 floors per minute. If they continue travelling at these rates, then at which floor will their paths cross ?\t(Level 3)\n\nA]19\nB]28\nC]30\nD]37\n\n");
                    break;

                case 3:printf("Some proverbs/idioms are given below together with their meanings. Choose the correct meaning of proverb/idiom, If there is no correct meaning given, E (i.e.) 'None of these' will be the answer :\nTo beg the question \t(Level 3)\n\nA]To refer to\nB]To take for granted\nC]To raise objections\nD]To be discussed\n\n");
                    break;

                case 4:printf("What was the day of the week on 28th May, 2006?\t(Level 3)\n\nA]Thursday\nB]Friday\nC]Saturday\nD]Sunday\n\n");
                    break;

                case 5:printf("In the first 10 overs of a cricket game, the run rate was only 3.2. What should be the run rate in the remaining 40 overs to reach the target of 282 runs?\t(Level 3)\n\nA]6.25\nB]6.5\nC]6.75\nD]7\n\n");
                    break;

                case 6:printf("In the following the question choose the word which best expresses the meaning of the given word\nAUGUST\t(Level 3)\n\nA]Common\nB]Ridiculous\nC]Dignified\nD]Petty\n\n");
                    break;

                case 7:printf("In which year was Pulitzer Prize established?\t(Level 3)\n\nA]1917\nB]1919\nC]1922\nD]1928\n\n");
                    break;

                case 8:printf("In which decade was the first solid state integrated circuit demonstrated?\t(Level 3)\n\nA]1950s\nB]1960s\nC]1970s\nD]1940s\n\n");
                    break;

                case 9:printf("A good way to figure out the relationship in a given question is to make up a sentence that describes the relationship between the first two words. Then, try to use the same sentence to find out which of the answer choices completes the same relationship with the third word.\nArtist is to painting as senator is to\t(Level 3)\n\nA]attorney\nB]law\nC]politician\nD]constituents\n\n");
                    break;
            }
            marks = 25;
            break;

        case 4:
            switch (ques)
            {
                case 0:printf("Mycobacterium leprae causes leprosy, Corynebacterium diphtheria causes diphtheria and Vibrio comma causes\t(Level 4)\n\nA]tetanus\nB]influenza\nC]cholera\nD]typhoid\n\n",ques+1);
                    break;

                case 1:printf("A, B, C, D and E are sitting on a bench. A is sitting next to B, C is sitting next to D, D is not sitting with E who is on the left end of the bench. C is on the second position from the right. A is to the right of B and E. A and C are sitting together. In which position A is sitting ?\t(Level 4)\n\nA]Between B and D\nB]Between B and C\nC]Between E and D\nD]Between C and E\n\n");
                    break;

                case 2:printf("What is RISC?\t(Level 4)\n\nA]Remodeled Interface System Computer\nB]Remote Intranet Secured Connection\nC]Runtime Instruction Set Compiler\nD]Reduced Instruction Set Computer\n\n");
                    break;

                case 3:printf("The half life period of an isotope is 2 hours. After 6 hours what fraction of the initial quantity of the isotope will be left behind?\t(Level 4)\n\nA]1/6\nB]1/3\nC]1/8\nD]1/4\n\n");
                    break;

                case 4:printf("The calendar for the year 2007 will be the same for the year\t(Level 4)\n\nA]2014\nB]2016\nC]2017\nD]2018\n\n");
                    break;

                case 5:printf("Which year is observed as Poverty Eradication Year by SAARC?\t(Level 4)\n\nA]1997\nB]1998\nC]1996\nD]1995\n\n");
                    break;

                case 6:printf("One-third of Rahul's savings in National Savings Certificate is equal to one-half of his savings in Public Provident Fund. If he has Rs. 1,50,000 as total savings, how much has he saved in Public Provident Fund ?\t(Level 4)\n\nA]Rs. 30,000\nB]Rs. 50,000\nC]Rs. 60,000\nD]Rs. 90,000\n\n");
                    break;

                case 7:printf("Which pair of numbers comes next : \n42 40 38 35 33 31 28\t(Level 4)\n\nA]25 22\nB]26 23\nC]26 22\nD]25 23\nE]26 24\n\n");
                    break;

                case 8:printf("The rock formations that cannot store groundwater are called : \t(Level 4)\n\nA]aquifers\nB]aquicludes\nC]perched aquifer\nD]spring\n\n");
                    break;

                case 9:printf("Who wrote the line: ' A thing of beauty is a joy forever'?\t(Level 4)\n\nA]John Keats\nB]Robert Browing\nC]P.B.Shelley\nD]William Wordsworth\n\n");
                    break;
            }
            marks = 30;
            break;

    }


    return (marks);

}//End of Level Switch case.
int check(char ans,int d,int q)
{

    char chk[5][10] =
            {
                    {'C','C','B','D','B','A','A','B','A','B'},
                    {'A','C','D','D','B','B','B','D','A','D'},
                    {'C','D','A','C','A','B','C','A','C','A'},
                    {'B','A','C','B','D','A','C','A','A','B'},
                    {'C','B','D','C','D','D','C','E','B','A'}
            };
    if (ans == chk[d][q])
    {
        return (1);
    }
    else
    {
        return(0);
    }
}

