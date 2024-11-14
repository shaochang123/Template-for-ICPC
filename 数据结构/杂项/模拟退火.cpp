#define down 0.996//徐徐降温 
double ansx,answ;//最终答案 
double energy(double x){}//根据实际情况定制
void sa()//模拟退火 
{
   double t=3000;//温度要足够高 
   while (t>1e-15)//略大于0 
   {
      double ex=ansx+(rand()*2-RAND_MAX)*t;//随机产生新的答案 
      double ew=energy(ex);
      double de=ew-answ;
      if (de<0)//如果此答案更优，就接受 
      {
         ansx=ex;
         answ=ew;
      }
      else if(exp(-de/t)*RAND_MAX>rand())//否则根据多项式概率接受 
      {
         ansx=ex;
      }
      t*=down;
   }
}
void solve() 
{
   ansx=//根据实际题目情况选择初始解
   answ=energy(ansx);
   for(int i=1;i<=6;i++)sa();//多跑几遍退火,增加得到最优解的概率
}
