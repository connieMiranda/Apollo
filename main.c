/*--------Getting Libraries--------*/
#include<stdio.h>
#include<time.h>

#define PI=3.141592;
#define deg2rad=PI/180;

/*---------------------------------*/

/*--------Global Variables---------*/

double G=6.67408e-11;
double mM=7.34767309e22;
double mE=5.97219e24;
double mS=28833;
double rM=1737100;
double rE=6371000;


double dEM=384403000;
double thetaM=42.5;

double dES=338000000;
double thetaS=50;

double locM[2]={dEM*cos(thetaM*deg2rad),dEM*sin(thetaM*deg2rad)};
double locS[2]={dES*cos(thetaS*deg2rad),dEM*sin(thetaS*deg2rad)};
double locE[2]={0,0};

double vM=(G*mE*mE)/((mE+mM)+dEM);
double velM[2]={-vM*sin(thetaM*deg2rad),vM*cos(thetaM*deg2rad)};

/*---------------------------------*/

/*--------Sub Functions------------*/
double calcF() /*Calculates forces between all three bodies*/




/*---------------------------------*/

/*--------Main Function------------*/
double main()
{

return 0;
}
/*---------------------------------*/