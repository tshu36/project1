#include<cstdio>
#include<cstdlib>
#include "Sudoku.h"
using namespace std;

void Sudoku::giveQuestion()
{
printf("8 0 0 0 0 0 0 0 0\n0 0 3 6 0 0 0 0 0\n0 7 0 0 9 0 2 0 0\n0 5 0 0 0 7 0 0 0\n0 0 0 0 4 5 7 0 0\n0 0 0 1 0 0 0 3 0\n0 0 1 0 0 0 0 6 8\n0 0 8 5 0 0 0 1 0\n0 9 0 0 0 0 4 0 0\n");
}
void Sudoku::readIn()
{
	int i,j;
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			scanf("%d",&thesudoku[i][j]);
		}
	}
}
void Sudoku::solve()
{
	int num[9],i,j,k,sol,lin,str,blol,blos,les,thesudokusol[9][9],nosol[9][9];
	int nop=0,nop1=0,allfull=0;
	int noso=0;
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			thesudokusol[i][j]=thesudoku[i][j];
		}
	}
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			if(thesudoku[i][j]!=0){
				for(lin=j+1;lin<9;++lin){
					if(thesudoku[i][j]==thesudoku[i][lin]){
						nop=nop+1;
						break;
					}
				}
				
				if(nop!=0)break;
				for(str=i+1;str<9;++str){
					if(thesudoku[i][j]==thesudoku[str][j]){
						nop=nop+1;
						break;
					}
				}
				if(nop!=0)break;
				if(i>=0&&i<=2){
					if(j>=0&&j<=2){
						for(blos=i;blos<3;++blos){
							for(blol=0;blol<3;++blol){
								if(thesudoku[i][j]==thesudoku[blos][blol]&&i!=blos&&j!=blol){
									nop=nop+1;
									break;
								}
							}
						}
					}
					if(j>=3&&j<=5){
                        	                for(blos=i;blos<3;++blos){
                                	                for(blol=3;blol<6;++blol){
                       		                                if(thesudoku[i][j]==thesudoku[blos][blol]&&i!=blos&&j!=blol){
                                                                	nop=nop+1;
                                                                	break;
                                                        	}
                                                	}
                                        	}
					}
					if(j>=6&&j<=8){
                                	        for(blos=i;blos<3;++blos){
                                                	for(blol=6;blol<9;++blol){
                                                        	if(thesudoku[i][j]==thesudoku[blos][blol]&&i!=blos&&j!=blol){
                                                                	nop=nop+1;
                                                                	break;
                                                       		}
                                                	}
                                        	}
					}
				}
                        	if(i>=3&&i<=5){
                                	if(j>=0&&j<=2){
                                        	for(blos=i;blos<6;++blos){
                                                	for(blol=0;blol<3;++blol){
                                                        	if(thesudoku[i][j]==thesudoku[blos][blol]&&i!=blos&&j!=blol){
                                                                	nop=nop+1;
                                                                	break;
                                                        	}
                                                	}
                                        	}
                                	}
                                	if(j>=3&&j<=5){
                                        	for(blos=i;blos<6;++blos){
                                                	for(blol=3;blol<6;++blol){
                                                        	if(thesudoku[i][j]==thesudoku[blos][blol]&&i!=blos&&j!=blol){
                                                                	nop=nop+1;
                                                                	break;
                                                        	}
                                                	}
                                        	}
                                	}
                                	if(j>=6&&j<=8){
                                        	for(blos=i;blos<6;++blos){
                                                	for(blol=6;blol<9;++blol){
                                                        	if(thesudoku[i][j]==thesudoku[blos][blol]&&i!=blos&&j!=blol){
                                                                	nop=nop+1;
                                                                	break;
                                                        	}
                                                	}
                                        	}
                                	}
                        	}
                        	if(i>=6&&i<=8){
                                	if(j>=0&&j<=2){
                                        	for(blos=i;blos<9;++blos){
                                                	for(blol=0;blol<3;++blol){
                                                        	if(thesudoku[i][j]==thesudoku[blos][blol]&&i!=blos&&j!=blol){
                                                                	nop=nop+1;
                                                                	break;
                                                        	}
                                                	}
                                        	}
                                	}
                                	if(j>=3&&j<=5){
                                        	for(blos=i;blos<9;++blos){
                                                	for(blol=3;blol<6;++blol){
                                                        	if(thesudoku[i][j]==thesudoku[blos][blol]&&i!=blos&&j!=blol){
                                                                	nop=nop+1;
                                                                	break;
                                                        	}
                                                	}
                                        	}
                                	}
                                	if(j>=6&&j<=8){
                                        	for(blos=i;blos<9;++blos){
                                                	for(blol=6;blol<9;++blol){
                                                        	if(thesudoku[i][j]==thesudoku[blos][blol]&&i!=blos&&j!=blol){
                                                                	nop=nop+1;
                                                                	break;
                                                        	}
                                                	}
                                        	}
                                	}
                        	}
			}
		}
		if(nop==1)break;
	}
	if(nop==1)printf("0");
	if(nop==0){
		for(;;){
		sol=0;
		for(i=0;i<9;++i){
			for(j=0;j<9;++j){
				if(thesudokusol[i][j]==0){
					for(k=0;k<9;++k){
						num[k]=k+1;
					}
					les=9;
					for(lin=0;lin<9;++lin){
						if(thesudokusol[i][lin]!=0&&num[thesudokusol[i][lin]-1]!=0){
							num[thesudokusol[i][lin]-1]=0;
							les=les-1;
						}
					}
					for(str=0;str<9;++str){
						if(thesudokusol[str][j]!=0&&num[thesudokusol[str][j]-1]!=0){
							num[thesudokusol[str][j]-1]=0;
							les=les-1;
						}
					}
					if(i>=0&&i<=2){
						if(j>=0&&j<=2){
		                                        for(blos=0;blos<3;++blos){
                		                                for(blol=0;blol<3;++blol){
                                		                        if(thesudokusol[blos][blol]!=0&&num[thesudokusol[blos][blol]-1]!=0){
                                                		                num[thesudokusol[blos][blol]-1]=0;
                                                                		les=les-1;
                                                        		}
                                                		}
                                        		}
						}
						if(j>=3&&j<=5){
	                               		        for(blos=0;blos<3;++blos){
                                                                for(blol=3;blol<6;++blol){
                                                                        if(thesudokusol[blos][blol]!=0&&num[thesudokusol[blos][blol]-1]!=0){
                                                                                num[thesudokusol[blos][blol]-1]=0;
                                                                                les=les-1;
                                                                        }
                                                                }
                                                        }
						}
						if(j>=6&&j<=8){
                                                        for(blos=0;blos<3;++blos){
                                                                for(blol=6;blol<9;++blol){
                                                                        if(thesudokusol[blos][blol]!=0&&num[thesudokusol[blos][blol]-1]!=0){
                                                                                num[thesudokusol[blos][blol]-1]=0;
                                                                                les=les-1;
                                                                        }
                                                                }
                                                        }
						}
					}
                                        if(i>=3&&i<=5){
                                                if(j>=0&&j<=2){
                                                        for(blos=3;blos<6;++blos){
                                                                for(blol=0;blol<3;++blol){
                                                                        if(thesudokusol[blos][blol]!=0&&num[thesudokusol[blos][blol]-1]!=0){
                                                                                num[thesudokusol[blos][blol]-1]=0;
                                                                                les=les-1;
                                                                        }
                                                                }
                                                        }
                                                }
                                                if(j>=3&&j<=5){
                                                        for(blos=3;blos<6;++blos){
                                                                for(blol=3;blol<6;++blol){
                                                                        if(thesudokusol[blos][blol]!=0&&num[thesudokusol[blos][blol]-1]!=0){
                                                                                num[thesudokusol[blos][blol]-1]=0;
                                                                                les=les-1;
                                                                        }
                                                                }
                                                        }
                                                }
                                                if(j>=6&&j<=8){
                                                        for(blos=3;blos<6;++blos){
                                                                for(blol=6;blol<9;++blol){
                                                                        if(thesudokusol[blos][blol]!=0&&num[thesudokusol[blos][blol]-1]!=0){
                                                                                num[thesudokusol[blos][blol]-1]=0;
                                                                                les=les-1;
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                        if(i>=6&&i<=8){
                                                if(j>=0&&j<=2){
                                                        for(blos=6;blos<9;++blos){
                                                                for(blol=0;blol<3;++blol){
                                                                        if(thesudokusol[blos][blol]!=0&&num[thesudokusol[blos][blol]-1]!=0){
                                                                                num[thesudokusol[blos][blol]-1]=0;
                                                                                les=les-1;
                                                                        }
                                                                }
                                                        }
                                                }
                                                if(j>=3&&j<=5){
                                                        for(blos=6;blos<9;++blos){
                                                                for(blol=3;blol<6;++blol){
                                                                        if(thesudokusol[blos][blol]!=0&&num[thesudokusol[blos][blol]-1]!=0){
                                                                                num[thesudokusol[blos][blol]-1]=0;
                                                                                les=les-1;
                                                                        }
                                                                }
                                                        }
                                                }
                                                if(j>=6&&j<=8){
                                                        for(blos=6;blos<9;++blos){
                                                                for(blol=6;blol<9;++blol){
                                                                        if(thesudokusol[blos][blol]!=0&&num[thesudokusol[blos][blol]-1]!=0){
                                                                                num[thesudokusol[blos][blol]-1]=0;
                                                                                les=les-1;
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
					if(les==1){
						for(k=0;k<9;++k){
							if(num[k]!=0){
								thesudokusol[i][j]=num[k];
								break;
							}
						}
						sol=1;
					}
					if(les==0){
						printf("0");
						exit(0);
					}
				}
			}
		}
		if(sol==0)break;
		}	
	}
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			if(thesudokusol[i][j]==0){
				noso=1;
				break;
			}
		}
		if(noso==1){
			break;
		}
	}
	int thenum[9]={0,0,0,0,0,0,0,0,0};
	if(nop==0&&noso==0){
		printf("1\n");
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				printf("%d%c",thesudokusol[i][j],j==8?'\n':' ');
			}
		}
	}
	else if(nop==0&&noso==1){
		for(i=0;i<9;++i){
			for(j=0;j<9;++j){
				thenum[thesudokusol[i][j]-1]=thenum[thesudokusol[i][j]]+1;
			}
		}
		if(thenum[0]==1||thenum[1]==1||thenum[2]==1||thenum[3]==1||thenum[4]==1||thenum[5]==1||thenum[6]==1||thenum[7]==1||thenum[8]==1){
			printf("0");
		}
		else{
			printf("2");
		}
	}
}
void Sudoku::changeNum(int a,int b)
{
if(a<1||a>9||b<1||b>9){return;}
int i,j;
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			if(thesudoku[i][j]==a){
				thesudoku[i][j]=b;
			}
			else if(thesudoku[i][j]==b){
				thesudoku[i][j]=a;
			}
		}
	}
}
void Sudoku::changeRow(int a,int b)
{
if(a<0||a>2||b<0||b>2){return;}
int i,j,A,B,comp;
A=3*a;
B=3*b;
	for(j=0;j<3;++j){
		for(i=0;i<9;++i){
			comp=thesudoku[A][i];
			thesudoku[A][i]=thesudoku[B][i];
			thesudoku[B][i]=comp;
		}
		A++;
		B++;
	}
}
void Sudoku::changeCol(int a,int b)
{
if(a<0||a>2||b<0||b>2){return;}
int i,j,cemp,A,B;
	A=3*a;
	B=3*b;
	for(j=0;j<3;++j){
        	for(i=0;i<9;++i){
                	cemp=thesudoku[i][A];
                	thesudoku[i][A]=thesudoku[i][B];
                	thesudoku[i][B]=cemp;
        	}
		A++;
		B++;
		
	}
}
void Sudoku::rotate(int n)
{
if(n<0||n>100){return;}
int new1[9][9],i,j,a,b;
if(n%4==0){
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			new1[i][j]=thesudoku[i][j];
		}
	}
        for(i=0;i<9;++i){
                for(j=0;j<9;++j){
                        thesudoku[i][j]=new1[i][j];
                }
        }
}
if(n%4==1){
	b=8;
	for(i=0;i<9;++i){
		a=0;
		for(j=0;j<9;++j){
			new1[a][b]=thesudoku[i][j];
			a++;
		}
		b=b-1;
	}
        for(i=0;i<9;++i){
                for(j=0;j<9;++j){
                        thesudoku[i][j]=new1[i][j];
                }
        }
}
if(n%4==2){
	a=8;
	for(i=0;i<9;++j){
		b=8;
		for(j=0;j<9;++i){
			new1[a][b]=thesudoku[i][j];
			b=b-1;
		}
		a=a-1;
	}
        for(i=0;i<9;++i){
                for(j=0;j<9;++j){
			thesudoku[i][j]=new1[i][j];
                }
        }
}
if(n%4==3){
	b=0;
        for(i=0;i<9;++i){
		a=8;
                for(j=0;j<9;++j){
			new1[a][b]=thesudoku[i][j];
			a=a-1;
                }
		b++;
        }
        for(i=0;i<9;++i){
                for(j=0;j<9;++j){
			thesudoku[i][j]=new1[i][j];
                }
        }
}
}
void Sudoku::flip(int n)
{
if(n<0||n>1){return;}
int new2[9][9],i,j;
if(n%2==0){
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			new2[8-i][j]=thesudoku[i][j];
		}
	}
        for(i=0;i<9;++i){
                for(j=0;j<9;++j){
			thesudoku[i][j]=new2[i][j];
                }
        }
}
if(n%2==1){
        for(j=0;j<9;++j){
                for(i=0;i<9;++i){
			new2[i][8-j]=thesudoku[i][j];
                }
        }
        for(i=0;i<9;++i){
                for(j=0;j<9;++j){
			thesudoku[i][j]=new2[i][j];
                }
        }

}
}
void Sudoku::transform()
{
	change();
	int i,j;
	printf("\n");
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			printf("%d%c",thesudoku[i][j],j==8?'\n':' ');
		}
	}
}
void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}


