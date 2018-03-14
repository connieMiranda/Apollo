/*--------Getting Libraries--------*/
#include<stdio.h>
#include<math.h>

#define PI 3.1415926536;
#define deg2rad PI/180;

/*---------------------------------*/

/*--------Global Variables---------*/
/*All variables are in SI units*/
double G=6.67408e-11; //Gravity constant
double mM=7.34767309e22;*//Mass of moon
double mE=5.97219e24;//Mass of earth
int mS=28833;//Mass of sat
int rM=1737100;//Radius of moon
int rE=6371000;//Radius of earth

/*---------------------------------*/

/*--------Sub Functions------------*/
double calcA(double xS,double yS,double xM,double yM) //Calculates forces between all three bodies
{
  //forces
  double dSE=sqrt(xS*xS+yS*yS);//Distance from sat to Earth
  double dME=sqrt(xM*xM+yM*yM);//Distance from moon to earth
  double dSM=sqrt(pow(xS-xM,2)+pow(yS-yM,2));//Distance from sat to moon
  double xFSE=-G*mS*mE*xS/pow(dSE,3);// x component of sat-earth force
  double yFSE=-G*mS*mE*yS/pow(dSE,3);// y component of sat-earth force
  double xFME=-G*mM*mE*xM/pow(dME,3);// x component of moon-earth force
  double yFME=-G*mM*mE*yM/pow(dME,3);// y component of moon-earth force
  double xFSM=-G*mS*mM*(xS-xM)/pow(dSM,3);// x component of sat-moon force
  double yFSM=-G*mS*mM*(yS-yM)/pow(dSM,3);// y component of sat-moon force

  //accelerations
  xAS=(xFSE+xFSM)/mS;//x component of sat acceleration
  yAS=(yFSE+yFSM)/mS;//y component of sat acceleration
  xAM=(xFME+xFSM)/mM;//x component of moon acceleration
  yAM=(yFME+yFSM)/mM;//y component of moon acceleration
  /*There is no earth acceleration*/
  double accel[4]={xAS,yAS,xAM,yAM};//acelleration vector
  return accel;
  

int checkImpact(double xS,double yS,double xM,double yM) //Checks if any of the bodies have impacted
{
  sM=sqrt(xM*xM+yM*yM);//Distance from moon to earth
  sS=sqrt(xS*xS+yS*yS);//Distance from sat to earth
  sS2M=sS-sM; //Distance from sat to moon
  int impact=0; //default, no impact
  if (sS<=rE) //if sat his earth
    {
      impact=1;
    }
  if (sS2M<rM)//if sat hits moon
    {
      impact=2;
    }
  if sM<=(rE+rM)//if moon hits earth
    {
      impact=3;
    }
  return impact;
}

double RK4(double initial[],double delt) //4th order Runge-Kutta Integration
{
  
}
/*---------------------------------*/

/*--------Main Function------------*/
double main()
{
  /*Initial configuration*/
  int dEM=384403000;//Distance of moon to earth
  double thetaM=42.5;//Inertial angle

  int dES=338000000;//Distance of sat to earth
  int thetaS=50;//Intertial angle

  double locM[2]={dEM*cos(thetaM*deg2rad),dEM*sin(thetaM*deg2rad)};//moon position vector
  double locS[2]={dES*cos(thetaS*deg2rad),dEM*sin(thetaS*deg2rad)};//sat position vector
  double locE[2]={0,0};//earth position vector, always

  double vM=(G*mE*mE)/((mE+mM)+dEM);//moon speed
  double velM[2]={-vM*sin(thetaM*deg2rad),vM*cos(thetaM*deg2rad)};//moon velocity
  int vS=1000;//sat speed
  double velS[2]={vS*cos(thetaS*deg2rad),vS*sin(thetaS*deg2rad)};//sat velocity
  int velE[2]={0,0};//earth velocity, always
  
  /*Guess*/
  printf("------------------------\nGive an initial velocity magnitude (m/s): ");
  double vMag
    scanf("%lf",&vMag); //asks for delta v magnitude
  printf("------------------------\nSet an angle (degrees): ");
  double vAng
    scanf("%lf",&vAng);//asks for delta v inertial angle
  velS[0]=velS[0]+vMag*cos(vAng*deg2rad);//adjust initial sat x velocity
  vels[1]=velS[1]+vMag*sin(vAng*deg2rad);//adjust initial sat y velocity
  
  /*Integration*/
  double X[8]={locS[0],locS[1],locM[0],locM[1],velS[0],velS[1],velM[0],velM[1]}; //initial conditions vector
  double delt=10*60; //delta t between divisions. Example: 30*60 = 10 minutes.
  double ti=0; //start time
  double tf=7*86400; //end time. Example: 7*86400 = 7 days
  for (int i=ti; i<=tf; i+=delt) //integration loop
    {
      
    }
  return 0;
}
/*---------------------------------*/
