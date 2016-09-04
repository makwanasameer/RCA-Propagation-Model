
/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
struct full_adder
{
	int a:2;
	int b:2;
	int sum:2;
	int carry_out:2;
	int temp:2;
};
int count=0,j=0;
void clear_full_adder(struct full_adder *temp);
void print_full_adder(struct full_adder *temp);
void initialize_a_b(struct full_adder * temp);
void initial_addition_step(struct full_adder * temp);
void second_addition_step(struct full_adder * temp);
void main()
{
	struct full_adder adder[31];
	FILE *stream;
	int i=0;
	int mydelay[10000];
	int sam1[64],sam2[64],flag=0,rem=0,temp1=0,temp2=0,sum=0,avg=0;
	//j=0;
	clrscr();
	flushall();
	randomize();



/* open a file for update */

	stream = fopen("sameerrca.txt", "w+");
/* write some data to the file */

	for(j=0;j<10000;j++)
	{

/* close the file */
	count=0;


	printf("%d",j+1);
	fprintf(stream,"%d",j+1);
	fprintf(stream," ");
	clear_full_adder(&adder[0]);

	initialize_a_b(&adder[0]);

	for(i=0;i<32;i++)
	{

		fprintf(stream,"%d", adder[i].a);

	}
	fprintf(stream," ");
	for(i=0;i<32;i++)
	{

		fprintf(stream,"%d", adder[i].b);

	}
	fprintf(stream," ");

	initial_addition_step(&adder[0]);

      //	print_full_adder(&adder[0]);

	second_addition_step(&adder[0]);

      //	printf("\n");
      //	print_full_adder(&adder[0]);
      //	printf("\nThe value of count is :%d",count);

	fprintf(stream,"%d\n",count);
	mydelay[j]=count;
	printf(" %d \n",mydelay[j]);

	}//close for loop


	for(j=0;j<10000;j++)
	{       flag=0;
		for(i=0;i<=64;i++)
		{
			if(sam1[i]==mydelay[j])
			{
				flag=1;
				rem=i;
			}

		}
		if(flag==1)
		{
			sam2[rem]=sam2[rem]+1;
		}
		else{
			sam1[temp1]=mydelay[j];
			temp1++;
			sam2[temp2]=sam2[temp2]+1;
			temp2++;


		}
	}

	for(j=0;j<temp1;j++)
	{
		sum=sum+sam1[j];
	}

	avg=sum/temp1;
	fprintf(stream,"\n Average delay of 10,000 pairs of random a and b= %d",avg);
	printf("\n Average delay of 10,000 pairs of random a and b= %d",avg);

	fclose(stream);


}
void clear_full_adder(struct full_adder *temp)
{       int i;
	for(i=0;i<32;i++)
	{
		(temp+i)->a=0;
		(temp+i)->b=0;
		(temp+i)->sum=0;
		(temp+i)->carry_out=0;
		(temp+i)->temp=0;
	}
}
void print_full_adder(struct full_adder *temp)
{       int i;
	for(i=31;i>=0;i--)
	{
		printf(" %d",(temp+i)->a);
	}
	printf(" a\n");
	for(i=31;i>=0;i--)
	{
		printf(" %d",(temp+i)->b);
	}
	printf(" b\n");
	for(i=31;i>=0;i--)
	{
		printf(" %d",(temp+i)->sum);
	}
	printf(" sum\n");
	for(i=31;i>=0;i--)
	{
		printf(" %d",(temp+i)->carry_out);
	}
	printf(" cout\n");
}
void initialize_a_b(struct full_adder * temp)
{       int i,j;
	for(j=0;j<1000;j++)
	{


	}
	for(i=0;i<32;i++){
	    if(i==31)
		(temp+i)->a=random(2);
	    else
		(temp+i)->a=random(2);
	}
//value of B
	for(i=0;i<32;i++){
	    if(i==0)
		(temp+i)->b=random(2);
	    else
		(temp+i)->b=random(2);
	}

}
void initial_addition_step(struct full_adder * temp)
{       int i;
	for(i=0;i<32;i++)
	{
		if((temp+i)->a==1&&(temp+i)->b==1)
		{
			(temp+i)->sum=0;
			(temp+i)->carry_out=1;
		}
		if(((temp+i)->a==0&&(temp+i)->b==1)||((temp+i)->a==1&&(temp+i)->b==0))
		{
			(temp+i)->sum=1;
			(temp+i)->carry_out=0;
		}
		if((temp+i)->a==0&&(temp+i)->b==0)
		{
			(temp+i)->sum=0;
			(temp+i)->carry_out=0;
		}
	}
	count=count+2;
}
void second_addition_step(struct full_adder * temp)
{
	int i;
	int flag=1;
while(flag==1)
{
	flag=0;
	for(i=0;i<32;i++)
	{
		(temp+i)->temp=0;

	}
	for(i=0;i<32;i++)
	{

		if((temp+i)->carry_out==1)
		{
			if(((temp+i+1)->a==0&&(temp+i+1)->b==1)||((temp+i+1)->a==1&&(temp+i+1)->b==0))
			{
				(temp+i)->carry_out=0;
				(temp+i+1)->sum=0;
				(temp+i+1)->temp=1;
			}
			if((temp+i+1)->a==0&&(temp+i+1)->b==0)
			{       flag=1;
				(temp+i)->carry_out=0;
				(temp+i+1)->sum=1;
				(temp+i+1)->temp=0;
			}
			if((temp+i+1)->a==1&&(temp+i+1)->b==1)
			{       flag=1;
				(temp+i)->carry_out=0;
				(temp+i+1)->sum=1;
				(temp+i+1)->temp=0;
			}
		}

	}//end of for loop
     //	printf("\n ");

	for(i=31;i>=0;i--)
	{
		(temp+i)->carry_out=(temp+i)->temp;

	  //	printf("%d ",(temp+i)->temp);

		if((temp+i)->temp==1)
		{
			flag=1;
		}

	}
      //	printf("cout \n ");
   //	for(i=31;i>=0;i--)
     //		printf("%d ",adder[i].sum);
		if(flag==1)
		{
			count=count+2;
		       //	printf(" sum  %d",count);
		}

}//end of the while loopf

}// end of the function