/*--------Getting Libraries--------*/
#include<stdio.h>
#include<math.h>

#define PI 3.141592;
#define deg2rad PI/180;

/*---------------------------------*/

/*--------Global Variables---------*/
/*All variables are in SI units*/
double G=6.67408e-11; /*Gravity constant*/
double mM=7.34767309e22;/*Mass of moon*/
double mE=5.97219e24;/*Mass of earth*/
int mS=28833;/*Mass of sat*/
int rM=1737100;/*Radius of moon*/
int rE=6371000;/*Radius of earth*/

/*---------------------------------*/

/*--------Sub Functions------------*/
void calcF(xS,yS,xM,yM) /*Calculates forces between all three bodies*/
{
double dSE=sqrt(xS*xS+yS*yS);/*Distance from sat to Earth*/
double dME=sqrt(xM*xM+yM*yM);
double dSM=sqrt(pow(xS-xM,2)+pow(yS-yM,2));
double xFSE=-G*mS*mE*xS/pow(dSE,3);
double yFSE=-G*mS*mE*yS/pow(dSE,3);
double xFME=-G*mM*mE*xM/pow(dME,3);
double yFME=-G*mM*mE*yM/pow(dME,3);
double xFsM=-G*mS*mM*(xS-xM)/pow(dSM,3);
double yFsM=-G*mS*mM*(yS-yM)/pow(dSM,3);
}

int checkImpact(xS,yS,xM,yM) /*Checks if any of the bodies have impacted*/
{
sM=sqrt(xM*xM+yM*yM);
sS=sqrt(xS*xS+yS*yS);
sS2M=sS-sM;
int impact=0;
if (sS<=rE)
{
	impact=1;
}
if (sS2M<rM)
{
	impact=2;
}
if sM<=(rE+rM)
{
	impact=3;
}
return impact;
}

void RK4() /*4th order Runge-Kutta Integration*/
{

}
/*---------------------------------*/

/*--------Main Function------------*/
double main()
{
int dEM=384403000;
double thetaM=42.5;

int dES=338000000;
int thetaS=50;

double locM[2]={dEM*cos(thetaM*deg2rad),dEM*sin(thetaM*deg2rad)};
double locS[2]={dES*cos(thetaS*deg2rad),dEM*sin(thetaS*deg2rad)};
double locE[2]={0,0};

double vM=(G*mE*mE)/((mE+mM)+dEM);
double velM[2]={-vM*sin(thetaM*deg2rad),vM*cos(thetaM*deg2rad)};
int vS=1000;
double velS[2]={vS*cos(thetaS*deg2rad),vS*sin(thetaS*deg2rad)};
int velE[2]={0,0};

printf("------------------------\nGive an initial velocity magnitude (m/s): ");
float vMag
scanf("%f",&vMag);

printf("------------------------\nSet an angle (degrees): ");
float vAng
scanf("%f",&vAng);

return 0;
}
/*---------------------------------*/
