// #include<bits/stdc++.h>
// using namespace std;

// // 0 1 1 2 3 5 8

// int fib_rec(int n){
//     if(n == 1)return 0;
//     if(n == 2)return 1;
//     else return fib_rec(n-1)+fib_rec(n-2);
// }

// int fib_ite(int n){
//     if(n == 1)return 0;
//     else if(n == 2)return 1;
//     int pre1 = 0;
//     int pre2 = 1;
//     int curr = 1;
//     for(int i=3; i<n; i++){
//         pre1 = pre2;
//         pre2 = curr;
//         curr = pre1 + pre2;

        
//     }
//     return curr;

// }

// int main(){
//     cout<<fib_rec(10);
//     cout<<fib_ite(10);
//     return 0;
// }
/*
 * Problem Statement :- Write a program non-recursive and recursive program to calculate
 *                      Fibonacci numbers and analyze their time and space complexity.
 *
 * Recursive
 * Time Complexity  : O(2^n)
 * Space Complexity : O(n)
 *
 * Non-Recursive
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

#include<bits/stdc++.h>
using namespace std;

int recursive_fibonacci(int n)
{
	if(n==1 || n==0) return n;
	return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
}

int non_recursive_fibonacci(int n)
{
	if(n==1 || n==0) return n;
	int a=0, b=1, c;

	for(int i=2; i<=n; i++)
	{
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	int n, choice;

	while(true)
	{
		cout<<"\n\n Main-Menu \n\t 1. Recursive \n\t 2. Non-Recursive \n\t 3. Exit \n"<<endl;
		cout<<"\n\t Enter choice: ";
		cin>>choice;

		if(choice == 1)
		{
			cout<<"\n\t Enter value of n to find nth fibonacci number(Fn) : ";
			cin>>n;
			int Fn = recursive_fibonacci(n);
			cout<<"\n\t Value of F"<<n<<" = "<<Fn<<endl;
		}
		else if(choice == 2)
		{
			cout<<"\n\t Enter value of n to find nth fibonacci number(Fn) : ";
			cin>>n;
			int Fn = non_recursive_fibonacci(n);
			cout<<"\n\t Value of F"<<n<<" = "<<Fn<<endl;
		}
		else if(choice == 3)
		{
			cout<<"\n\t Thank You!!"<<endl;
			exit(0);
		}
		else
		{
			cout<<"\n\t Enter valid choice"<<endl;
		}
	}

}
