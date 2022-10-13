class Solution
{
public int rotatedDigits(int N)
{
int ans=0;
for(int i=1;i<=N;i++)
{
ans+=check(i);
}
return ans;
}
int check(int n)
{
boolean flag=false;
while(n!=0)
{
int a=n%10;
if(a==2 || a==5 || a==6 || a==9) flag=true;
if(a==3 || a==4 || a==7) return 0;
n=n/10;
}
return flag?1:0;
}
