//项目函数， 使用时在全局脚本周期调用， str是变量名；
#define COUNT 30 //预设的变量的数量

BOOL TestPulse(const char* str) 
{
static char tags[COUNT][100] = {
0
};
static BOOL lastTV[COUNT] = {
0
};
static int len = 0;
BOOL result = FALSE;
int index = 0;
{
int i = 0;
for(i = 0; i != len; ++i)
{
if(!strcmp(tags[i], str))
{
index = i; 
break;
}
}
if(len == i)
{
index = -1;
}
}
if(-1 == index)
     {
          if(len == COUNT)
         {
               printf("Too many tags.\r\n");
               return FALSE;
         }
     	strcpy(tags[len], str);
   	   lastTV[len] = (BOOL)GetTagBit(str);
          ++len;
     	return FALSE;
     }
     
     if(GetTagBit(str) && !lastTV[index])
     {
     	result = TRUE;
     }
     lastTV[index] = GetTagBit(str);
     
     return result;
     
}
