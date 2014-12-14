/* ***********************************************
Author        :kuangbin
Created Time  :2014/12/14 18:58:29
File Name     :hihoCoder6\A.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
char str[100010];
bool check(int i){
	if(str[i] != 'm' && str[i] != 'M')return false;
	if(str[i+1] != 'a' && str[i+1] != 'A')return false;
	if(str[i+2] != 'r' && str[i+2] != 'R')return false;
	if(str[i+3] != 's' && str[i+3] != 'S')return false;
	if(str[i+4] != 'h' && str[i+4] != 'H')return false;
	if(str[i+5] != 't' && str[i+5] != 'T')return false;
	if(str[i+6] != 'o' && str[i+6] != 'O')return false;
	if(str[i+7] != 'm' && str[i+7] != 'M')return false;
	if(str[i+8] != 'p' && str[i+8] != 'P')return false;
	return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(gets(str)){
		int len = strlen(str);
		for(int i = 0;i < len;i++){
			if(i + 9 <= len && check(i)){
				printf("fjxmlhx");
				i += 8;
			}
			else printf("%c",str[i]);
		}
		printf("\n");
	}
    return 0;
}
