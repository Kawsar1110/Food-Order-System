#include<stdio.h>
#include<string.h>
#define beef_burger_small 150
#define beef_burger_big 250
#define chicken_burger_small 100
#define chicken_burger_big 150
#define fried_chicken_small 130
#define fried_chicken_big 180
#define french_fry_small 60
#define french_fry_big 100
int order_no=0,order_served=0;
struct quantity_size
{
	int quantity;
	int size;
};
struct food_order
{
	char consumer_name[20];
	int food_list[4];
	struct quantity_size food[4];
	int number_of_food=0;
	int price=0;
	int status;
};
`       struct food_order list[30];
void ordering_system(void)
{
	printf("Our items................\n1.Beef Burger 2.Chicken Burger 3.Fried Chicken 4.French Fry\n");
	scanf("%d",&list[order_no].food_list[list[order_no].number_of_food]);
	printf("Enter size of food: 1.small 2.big\n");
	scanf("%d",&list[order_no].food[list[order_no].number_of_food].size);
	printf("Enter quantity of food:\n");
	scanf("%d",&list[order_no].food[list[order_no].number_of_food].quantity);
	if(list[order_no].food_list[list[order_no].number_of_food]==1)
	{
		if(list[order_no].food[list[order_no].number_of_food].size==1)
		{
			list[order_no].price+=(list[order_no].food[list[order_no].number_of_food].quantity*150);
		}
		else
		{
			list[order_no].price+=(list[order_no].food[list[order_no].number_of_food].quantity*250);
		}
	}
	else if(list[order_no].food_list[list[order_no].number_of_food]==2)
	{
		if(list[order_no].food[list[order_no].number_of_food].size==1)
		{
			list[order_no].price+=(list[order_no].food[list[order_no].number_of_food].quantity*100);
		}
		else
		{
			list[order_no].price+=(list[order_no].food[list[order_no].number_of_food].quantity*150);
		}
	}
	else if(list[order_no].food_list[list[order_no].number_of_food]==3)
	{
		if(list[order_no].food[list[order_no].number_of_food].size==1)
		{
			list[order_no].price+=(list[order_no].food[list[order_no].number_of_food].quantity*130);
		}
		else
		{
			list[order_no].price+=(list[order_no].food[list[order_no].number_of_food].quantity*180);
		}
	}
	else if(list[order_no].food_list[list[order_no].number_of_food]==4)
	{
		if(list[order_no].food[list[order_no].number_of_food].size==1)
		{
			list[order_no].price+=(list[order_no].food[list[order_no].number_of_food].quantity*60);
		}
		else
		{
			list[order_no].price+=(list[order_no].food[list[order_no].number_of_food].quantity*100);
		}
	}
	list[order_no].number_of_food++;
}
void display(void)
{
	int i,j;
	printf("Number of orders received: %d\n",order_no);
	printf("Number of orders served: %d\n",order_served);
	printf("Number of orders are pending: %d\n\n",order_no-order_served);
	for(i=0;i<order_no;i++)
	{
		printf("Consumer: %s\n",list[i].consumer_name);
		for(j=0;j<list[i].number_of_food;j++)
		{
			if(list[i].food_list[j]==1)
			{
				printf("Beef Burger ");
			}
			else if(list[i].food_list[j]==2)
			{
				printf("Chicken Burger ");
			}
			else if(list[i].food_list[j]==3)
			{
				printf("Fried Chicken ");
			}
			else if(list[i].food_list[j]==4)
			{
				printf("French Fry ");
			}
			if(list[i].food[j].size==1)
		{
			printf("small ");
		}
		else
		{
			printf("big ");
		}
		printf("%dpieces\n",list[i].food[j].quantity);
		}
		printf("Total price=%dTk.\n",list[i].price);
		if(list[i].status==1)
		{
			printf("Status: served\n");
		}
		else
		{
			printf("Status: pending\n");
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int i=0,j=0;
	while(i!=3)
	{
		printf("\n1.Order your food\n2.Display the ordered list\n3.exit\n");
		scanf("%d",&i);
		if(i==1)
		{
		char name[20];
		printf("Enter consumer name:\n");
		scanf("%s",name);
		strcpy(list[order_no].consumer_name,name);
		while(j!=2)
		{
			printf("\n1.Select items\n2.Finish\n");
			scanf("%d",&j);
			if(j==1)
			ordering_system();
		}
		printf("Total= %dTk\n",list[order_no].price);
		printf("Do you want to pay for this: 1.Yes 2.No\n");
		scanf("%d",&list[order_no].status);
		if(list[order_no].status==1)
		{
			order_served++;
		}
		j=0;
		order_no++;
		}
		else if(i==2)
		{
			display();
		}
	}
}

