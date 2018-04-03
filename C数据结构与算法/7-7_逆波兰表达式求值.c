#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MAXSIZE = 1000;
int t; 
int S[1000];

void pushin(int x)
{
    S[++t] = x;
}

int get()
{
    return S[t--];
}


int main(void)
{
    int a1, a2;
    int last;
    t = 0;
    char input[100];
     
    while(scanf("%s", input) != EOF)
    {
    	
    	if (input[0] != '+' && input[0] != '-' && input[0] != '*' )
            pushin(atoi(input));
    	else 
		{
	        a1 = get();
	        a2 = get();
	        switch (input[0])
	        {
	        	case '+':
	        		last = a1 + a2;
	        		break;
	        	case '-':
	        		last = a2 - a1;
	        		break;
	        	case '*':
	        		last = a1 * a2;
	        		break;        		
	        }
			pushin(last);
		}
	}
	printf("%d\n", get());
    return 0;
}
