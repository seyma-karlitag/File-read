/*The program takes the integers in the file one by one and compares them with all the remaining integers.
Since individual comparisons are made here, as the file size increases
as the number of operations to be performed and the complexity of the operation increases,the running time of the program increases*/

#include <stdio.h>


int main ()
 {
 
 
 FILE *fptr;  
                
 fptr  = fopen ("file.txt", "r+");  /*file opening operations are performed*/

 int status;
 int y;
 int i,a,b;
 int index,temp,count=0;
 int endof_file;
 
 if(fptr==NULL)
 {
    printf("error");
 }
 else
 {
        
             fseek(fptr,0,SEEK_END);  /*i've come to the end of the file*/
             endof_file= ftell(fptr);  /*i've located the end of the file.*/
             fseek(fptr,0,SEEK_SET);   /*I've been back to the file.*/
             
     do
     {
                 status= fscanf(fptr,"%d",&y);
                 index=y;   /*i have read and stored the first number from the file*/
                 temp=index;
                 count=0;
                if(temp<0)
                {
                  temp*=(-1);  /*i changed the count to positive to find the number of digits*/
                  count+=1;  /*if the number is negative, I got 1 more for the minus square*/
                }
              
        
               while(temp>0)
                { 
                   temp=temp/10; /*the number of digits of the count*/
                   count++;
                }
               
 
               a=ftell(fptr);  /*after the first issue, I got my position.*/
         
          while(1)
          {
                
               
               b=ftell(fptr); /*i get the cursor position as I get my numbers*/
               status= fscanf(fptr,"%d",&y); /*in the loop, I get the numbers one by one to the end of the file*/
               if(status!=1) break; /*the comparison process continues until the end of the file*/
                if(index==y)  /*I'm comparing my first number to my next number.*/
                {
                    
                    fseek(fptr, -count, SEEK_CUR); /*if it is equal, I take the cursor as the number of digits and delete it below*/
                    for(i=0;i<count;i++)
                    {
                       fputs(" ", fptr);
                    }
                   
                }
               
             
              
           }
           
         fseek(fptr,a,SEEK_SET); /*cursor moves to the position of the first number*/
         /*this continues with the loop, and the number I hold advances one by one*/
        
     
      }while(ftell(fptr)!=endof_file );  /*the comparison continues until the end of the file, the file eventually exits the loop*/
           
     
         
 } 
    
     fclose(fptr);  /*the file is closed*/
     
 
 return 0;
 
 }
