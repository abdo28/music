// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>


#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if (strlen(fraction)==3){
         return(((((int)fraction[0]-48)*1.0)/(((int)fraction[2]-48)*1.0))*8);
    }
    else
    return (((int)fraction[0]-48));
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{float base=0;
    if(note[0]=='A'&&strlen(note)==2){
        if(((int)note[1]-48)>4)
        base=(pow(2.0,(((int)note[1]-48)-4.0))*440);
        else if(((int)note[1]-48)<4)
        base=((1.0/pow(2.0,(4-((int)note[1]-48))))*440);
        else
        base= 440;
    }
     else if(note[0]=='A'&&strlen(note)==3){
        if(((int)note[2]-48)>4)
        base=(pow(2.0,((int)(note[2]-48)-4))*440);
        else if(((int)note[2]-48)<4)
        base=((1.0/pow(2.0,(4-((int)note[2]-48))))*440.0);
        else
        base= 440;
    }

    else if(note[0]=='B'&&strlen(note)==2){
        if(((int)note[1]-48)>4)
        base=(pow(2.0,(((int)note[1]-48)-4))*(pow(2,2.0/12)*440));
         else if(((int)note[1]-48)==3)
        base=((1.0/pow(2.0,(4-((int)note[1]-48))))*(pow(2,2.0/12)*440));
        else if(((int)note[1]-48)<4)
        base=((1.0/pow(2.0,(4-((int)note[1]-48))))*(pow(2,2.0/12)*440));
        else
        base= (pow(2,2.0/12)*440);
    }
     else if(note[0]=='B'&&strlen(note)==3){
        if(((int)note[2]-48)>4)
        base=(pow(2.0,(((int)note[2]-48)-4))*(pow(2,2.0/12)*440));
        else if(((int)note[2]-48)==3)
        base=((1.0/(pow(2.0,(4-((int)note[2]-48)))))*(pow(2,2.0/12)*440));
        else if(((int)note[2]-48)<4)
        base=((1.0/(pow(2.0,(4-((int)note[2]-48)))))*(pow(2,2.0/12)*440));
        else
        base= (pow(2,2.0/12)*440);
    }
     else if(note[0]=='C'&&strlen(note)==2){
        if(((int)note[1]-48)>5)
        base=(pow(2.0,(((int)note[1]-48)-5))*(pow(2,3.0/12)*440));
         else if(((int)note[1]-48)==3)
        base=((1.0/(pow(2.0,(5-((int)note[1]-48)))))*(pow(2,3.0/12)*440.0));
        else if(((int)note[1]-48)<5)
        base=((1.0/(pow(2.0,(5-((int)note[1]-48)))))*(pow(2,3.0/12)*440.0));
        else
        base= (pow(2.0,3.0/12)*440);
    }
    else  if(note[0]=='C'&&strlen(note)==3){
        if(((int)note[2]-48)>5)
        base=(pow(2.0,((int)(note[2]-48)-5))*(pow(2,3.0/12)*440));
         else if(((int)note[2]-48)==3)
        base=((1.0/(pow(2.0,(5-((int)note[2]-48)))))*(pow(2,3.0/12)*440.0));

        else if(((int)note[2]-48)<5)
        base=((1.0/(pow(2.0,(5-((int)note[2]-48)))))*(pow(2,3.0/12)*440.0));
        else
        base= (pow(2,3.0/12)*440);
    }
    else if(note[0]=='D'&&strlen(note)==2){
        if(((int)note[1]-48)>5)
        base=(pow(2.0,(((int)note[1]-48)-5))*(pow(2,5.0/12)*440));
        else if(((int)note[1]-48)==3)
        base=((1.0/pow(2.0,(5-((int)note[1]-48))))*(pow(2,5.0/12)*440));
        else if(((int)note[1]-48)<5)
        base=((1.0/pow(2.0,(5-((int)note[1]-48))))*(pow(2,5.0/12)*440));
        else
        base= (pow(2,5.0/12)*440);
    }
     else if(note[0]=='D'&&strlen(note)==3){
        if(((int)note[2]-48)>5)
        base=(pow(2.0,((int)(note[2]-48)-5))*(pow(2,5.0/12)*440));
 else if(((int)note[2]-48)==3)
        base=((1.0/(pow(2.0,(5-((int)note[2]-48)))))*(pow(2,5.0/12)*440));
        else if(((int)note[2]-48)<5)
        base=((1.0/(pow(2.0,(5-((int)note[2]-48)))))*(pow(2,5.0/12)*440));
        else
        base= (pow(2,5.0/12)*440);
    }
    else if(note[0]=='E'&&strlen(note)==2){
        if(((int)note[1]-48)>5)
        base=(pow(2.0,(((int)note[1]-48)-5))*(pow(2,7.0/12)*440));
        else if(((int)note[1]-48)==3)
        base=((1.0/pow(2,(5-((int)note[1]-48))))*(pow(2,7.0/12)*440));
        else if(((int)note[1]-48)<5)
        base=((1.0/pow(2,(5-((int)note[1]-48))))*(pow(2,7.0/12)*440));
        else
        base= (pow(2,7.0/12)*440);
    }
     else if(note[0]=='E'&&strlen(note)==3){
        if(((int)note[2]-48)>5)
        base=(pow(2.0,((int)(note[2]-48)-5))*(pow(2,7.0/12)*440));
        else if(((int)note[2]-48)==3)
        base=((1.0/(pow(2,(5-((int)note[2]-48)))))*(pow(2,7.0/12)*440));
        else if(((int)note[2]-48)<5)
        base=((1.0/(pow(2,(5-((int)note[2]-48)))))*(pow(2,7.0/12)*440));
        else
        base= (pow(2,7.0/12)*440);
    }
   else  if(note[0]=='F'&&strlen(note)==2){
        if(((int)note[1]-48)>5)
        base=(pow(2,(((int)note[1]-48)-5))*(pow(2,8.0/12)*440));
         else if(((int)note[1]-48)==3)
        base=((1.0/pow(2.0,(5-((int)note[1]-48))))*(pow(2,8.0/12)*440));
        else if(((int)note[1]-48)<5)
        base=((1.0/pow(2.0,(5-((int)note[1]-48))))*(pow(2,8.0/12)*440));
        else
        base= (pow(2.0,8.0/12)*440);
    }
     else if(note[0]=='F'&&strlen(note)==3){
        if(((int)note[2]-48)>5)
        base=(pow(2,((int)(note[2]-48)-5))*(pow(2,8.0/12)*440));
        else if(((int)note[2]-48)==3)
        base=((1.0/(pow(2.0,(5-((int)note[2]-48)))))*(pow(2,8.0/12)*440));
        else if(((int)note[2]-48)<5)
        base=((1.0/(pow(2.0,(5-((int)note[2]-48)))))*(pow(2,8.0/12)*440));
        else
        base= (pow(2,8.0/12)*440);
    }
    else if(note[0]=='G'&&strlen(note)==2){
        if(((int)note[1]-48)>5)
        base=(pow(2,(((int)note[1]-48)-5))*(pow(2,10.0/12)*440));
         else if(((int)note[1]-48)==3)
        base=((1.0/pow(2.0,(5-((int)note[1]-48))))*(pow(2,10.0/12)*440));
        else if(((int)note[1]-48)<5)
        base=((1.0/pow(2.0,(5-((int)note[1]-48))))*(pow(2,10.0/12)*440));
        else
        base= (pow(2,10.0/12)*440);
    }
     else if(note[0]=='G'&&strlen(note)==3){
        if(((int)note[2]-48)>5)
        base=(pow(2,((int)(note[2]-48)-5))*(pow(2,10.0/12)*440));
        else if(((int)note[2]-48)==3)
        base=((1.0/(pow(2.0,(5-((int)note[2]-48)))))*(pow(2,10.0/12)*440));
        else if(((int)note[2]-48)<5)
        base=((1.0/(pow(2.0,(5-((int)note[2]-48)))))*(pow(2,10.0/12)*440));
        else
        base= (pow(2,10.0/12)*440);
    }
      if (strlen(note)==2){
         //if(base-(int)base>0.5)
         //return ((int)base+1);
        //else  if(base-(int)base<0.5)
         return round(base);

     }

    if (strlen(note)==3){
        if(note[1]=='#'&&((int)note[2]-47)%2==0)
        base=base*pow(2,1.0/12)*1.0;
        else if(note[1]=='#')
        base=(base*pow(2,1.0/12)*1.0);

        else if(note[1]=='b')
        base=(base/pow(2,1.0/12)*1.0);}
        if (strlen(note)==3){

        // if(base-(int)base>0.5)cd pset3
        //else  if(base-(int)base<0.5)
         return round(base);

    }



    return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(s[0]=='\n'||strncmp(s,"",1)==0)
    return true;
    else
    return false;

}
