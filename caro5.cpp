//#define toi 1
//#define ban 2
#include <iostream>
#include <fstream>
#include <windows.h>
int dem=0,ban,toi;
struct toado{
	int x=-1,y=-1;
	void reset(){
        x=-1;
        y=-1;
	}
};
using namespace std;
int luot_di(){
    fstream f("luotchoi.txt",ios::in);
    int x;
    f>>x;
    return x;
}
void step(int banco[30][30]);
void doc_file(int banco[30][30]){
	fstream f("caro.txt",ios::in);
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			f>>banco[i][j];
		}
	}
	f.close();
}
void hien_thi(int banco[30][30]){
	fstream f("luotchoi.txt",ios::in);
	int x,y,z;
	f>>z>>x>>y;
	system("cls");// xoa man hinh
	cout<<"nguoi choi: "<<z<<"_____vua di o ("<<x<<" "<<y<<")"<<endl;
	cout<<"\t"<<dem*2;
	doc_file(banco);
	for(int i=0;i<30;i++){
		cout<<endl;
		for(int j=0;j<30;j++){
			if(banco[i][j]==0) cout<<" ";
			if(banco[i][j]==1) cout<<"x";
			if(banco[i][j]==2) cout<<"o";
		}
	}
	Sleep(50);
}
void luu_file(int a[30][30],int x,int y){
	fstream f("caro.txt",ios::out);//luu ban co
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			f<<a[i][j]<<" ";
		}
		f<<endl;
	}
	f.close();
	fstream fluot("luotchoi.txt",ios::out);//luu luot choi
	fluot<<toi<<" "<<x<<" "<<y;
	fluot.close();
}
void di(int banco[30][30],toado da){
	if(da.x>=0&& da.y>=0){
        banco[da.x][da.y]=toi;
        luu_file(banco,da.x,da.y);
	}
	dem++;
	return;
}
int kiem_tra(int banco[30][30]){
	// hang ngang
	for(int i=0;i<30;i++){// nguoi 1
		for(int j=0;j<30;j++){
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && y<30){
				dem++;
				y++;
			}
			if(dem==6) return toi;
		}

	}
	for(int i=0;i<30;i++){// nguoi 2
		for(int j=0;j<30;j++){
			int x=i,y=j,dem=0;
			while(banco[x][y]==ban && j<30){
				dem++;
				y++;
			}
			if(dem==6) return ban;
		}
	}
	//hang doc
	for(int i=0;i<30;i++){// nguoi 1
		for(int j=0;j<30;j++){
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && i<30){
				dem++;
				x++;
			}
			if(dem==6) return toi;
		}
	}
	for(int i=0;i<30;i++){// nguoi 2
		for(int j=0;j<30;j++){
			int x=i,y=j,dem=0;
			while(banco[x][y]==ban && i<30){
				dem++;
				x++;
			}
			if(dem==6) return ban;
		}
	}
	//cheo chinh
	for(int i=29;i>=0;i--){// nguoi 1
		for(int j=29;j>=0;j--){
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi &&x<30&&y<30){
				dem++;
				x++;
				y++;
			}
			if(dem==6) return toi;
		}
	}
	for(int i=29;i>=0;i--){// nguoi 2
		for(int j=29;j>=0;j--){
			int x=i,y=j,dem=0;
			while(banco[x][y]==ban &&x<30&&y<30){
				dem++;
				x++;
				y++;
			}
			if(dem==6) return ban;
		}
	}
	//cheo phu
	for(int i=0;i<30;i++){// nguoi 1
		for(int j=0;j<30;j++){
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi &&x>=0&y<30){
				dem++;
				x--;
				y++;
			}
			if(dem>=6) return toi;
		}
	}
	for(int i=0;i<30;i++){// nguoi 2
		for(int j=0;j<30;j++){
			int x=i,y=j,dem=0;
			while(banco[x][y]==ban&&x>=0&y<30){
				dem++;
				x--;
				y++;
			}
			if(dem==6) return ban;
		}
	}
	return 0;
}
toado uu_tien_5(int banco[30][30]){
	toado da;
	//hang ngang
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && y<30){
				dem++;
				y++;
			}
			if(dem==5) {
				da.x=i;
				da.y=j;
				if(banco[da.x][da.y-1]==0) {
					if(da.y-1>=0){
						da.y-=1;
						return da;
					}
				}
				if(banco[da.x][da.y+5]==0){
					if(da.y+5<30){
						da.y+=5;
						return da;
					}
				}
			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban && y<30){
				dem++;
				y++;
			}
			if(dem==5) {
				da.x=i;
				da.y=j;
				if(banco[da.x][da.y-1]==0) {
					if(da.y-1>=0){
						da.y-=1;
						return da;
					}
				}
				if(banco[da.x][da.y+4]==0){
					if(da.y+4<30){
						da.y+=4;
						return da;
					}
				}
			}
		}
	}
	// hang doc
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && i<30){
				dem++;
				x++;
			}
			if(dem==5) {
				da.x=i;
				da.y=j;
				if(banco[da.x-1][da.y]==0) {
					if(da.x-1>=0){
						da.x-=1;
						return da;
					}
				}
				if(banco[da.x+5][da.y]==0){
					if(da.x+5<30){
						da.x+=5;
						return da;
					}
				}
			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban && i<30){
				dem++;
				x++;
			}
			if(dem==5) {
				da.x=i;
				da.y=j;
				if(banco[da.x-1][da.y]==0) {
					if(da.x-1>=0){
						da.x-=1;
						return da;
					}
				}
				if(banco[da.x+5][da.y]==0){
					if(da.x+5<30){
						da.x+=5;
						return da;
					}
				}
			}
		}
	}
	// cheo chinh
	for(int i=29;i>=0;i--){
		for(int j=29;j>=0;j--){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi &&x<30&&y<30){
				dem++;
				x++;
				y++;
			}
			if(dem==5) {
				da.x=i;
				da.y=j;
				if(banco[da.x-1][da.y-1]==0) {
					if(da.x-1>=0&&da.y-1>=0){
						da.x-=1;
						da.y-=1;
						return da;
					}
				}
				if(banco[da.x+5][da.y+=5]==0){
					if(da.x+5<30&&da.y+5<30){
						da.x+=5;
						da.y+=5;
						return da;
					}
				}
			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==toi &&x<30&&y<30){
				dem++;
				x++;
				y++;
			}
			if(dem==5) {
				da.x=i;
				da.y=j;
				if(banco[da.x-1][da.y-1]==0) {
					if(da.x-1>=0&&da.y-1>=0){
						da.x-=1;
						da.y-=1;
						return da;
					}
				}
				if(banco[da.x+5][da.y+=5]==0){
					if(da.x+5<30&&da.y+5<30){
						da.x+=5;
						da.y+=5;
						return da;
					}
				}
			}
		}
	}
	//cheo phu
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi &&x>=0&y<30){
				dem++;
				x--;
				y++;
			}
			if(dem==5) {
				da.x=i;
				da.y=j;
				if(banco[da.x-5][da.y+5]==0) {
					if(da.x-5>=0&&da.y+5<30){
						da.x-=5;
						da.y+=5;
						return da;
					}
				}
				if(banco[da.x+1][da.y-1]==0){
					if(da.x=1<30&&da.y-1>=0){
						da.x+=1;
						da.y-=1;
						return da;
					}
				}
			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban &&x>=0&y<30){
				dem++;
				x--;
				y++;
			}
			if(dem==5) {
				da.x=i;
				da.y=j;
				if(banco[da.x-5][da.y+5]==0) {
					if(da.x-5>=0&&da.y+5<30){
						da.x-=5;
						da.y+=5;
						return da;
					}
				}
				if(banco[da.x+1][da.y-1]==0){
					if(da.x+1<30&&da.y-1>=0){
						da.x+=1;
						da.y-=1;
						return da;
					}
				}
			}
		}
	}
	da.reset();
	return da;
}

toado uu_tien_4(int banco[30][30]){
	toado da;
	//hang ngang
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			int x=i,y=j,dem=0;
			//toi
			while(banco[x][y]==toi && y<30){
				dem++;
				y++;
			}
			if(dem==4) {
				da.x=i;
				da.y=j;
				if(banco[da.x][da.y-1]!=ban &&banco[da.x][da.y-2]!=ban){//sau khi danh van co the thang
					if(banco[da.x][da.y-1]==0){
						if(banco[da.x][da.y-2]==0){
							if(da.y-2>=0){
								da.y-=2;
								return da;
							}
						}
						if(da.y-1>=0){
							da.y-=1;
							return da;
						}
					}
				}
				if(banco[da.x][da.y+4]!=ban&& banco[da.x][da.y+5]!=ban){//sau khi danh van co the thang
					if(banco[da.x][da.y+5]==0){
						if(banco[da.x][da.y+4]==0){
							if(da.y+5<30){
								da.y+=5;
								return da;
							}
						}
						if(da.y+4<30){
							da.y+=4;
							return da;
						}
					}
				}
			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban && y<30){
				dem++;
				y++;
			}
			if(dem==4) {
				da.x=i;
				da.y=j;
				if(banco[da.x][da.y-1]==0&&(banco[da.x][da.y-2==0||banco[da.x][da.y-2]==ban]==0)){//sau khi danh van co the thang
					if(da.y-1>=0){
						da.y-=1;
						return da;
					}
				}
				if(banco[da.x][da.y+4]==0&&(banco[da.x][da.y+5]==0||banco[da.x][da.y+5]==ban)){//sau khi danh van co the thang
					if(da.y+4<30){
						da.y+=4;
						return da;
					}
				}
			}
		}
	}
	// hang doc
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && i<30){
				dem++;
				x++;
			}
			if(dem==4) {
				da.x=i;
				da.y=j;
				if(banco[da.x-1][da.y]!=ban && banco[da.x-2][da.y]!= ban) {
					if(banco[da.x-1][da.y]==0){
						if(banco[da.x-2][da.y] ==0){
							if(da.x-2>=0){
								da.x-=2;
								return da;
							}
						}
						if(da.x-1>=0){
							da.x-=1;
							return da;
						}
					}
				}
				if(banco[da.x+4][da.y]!= ban && banco[da.x+5][da.y]!=ban){
					if(banco[da.x+4][da.y]==0){
						if(banco[da.x+5][da.y]==0){
							if(da.x+5<30){
								da.x+=5;
								return da;
							}
						}
						if(da.x+4<30){
							da.x+=4;
							return da;
						}
					}
				}
			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban && i<30){
				dem++;
				x++;
			}
			if(dem==4) {
				da.x=i;
				da.y=j;
				if(banco[da.x-1][da.y]==0 && da.x-1>=0) {
						da.x-=1;
						return da;
				}
				if(banco[da.x+4][da.y]==0&& da.x+4<30){
						da.x+=4;
						return da;
				}
			}
		}
	}
	// cheo chinh
	for(int i=29;i>=0;i--){
		for(int j=29;j>=0;j--){
            //toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi &&x<30&&y<30){
				dem++;
				x++;
				y++;
			}
			if(dem==4) {
				da.x=i;
				da.y=j;
				//return da;
				if(banco[da.x-1][da.y-1]!=ban && banco[da.x-2][da.y-2]!=ban) {
					if(banco[da.x-1][da.y-1]==0){
						if(banco[da.x-2][da.y-2]==0){
							da.x-=2;
							da.y-=2;
							return da;
						}
						da.x-=1;
						da.y-=1;
						return da;
					}
				}
				if(banco[da.x+4][da.y+=4]!=ban && banco[da.x+5][da.y+=5]!=ban){
					if(banco[da.x+4][da.y+=4]==0){
						if(banco[da.x+5][da.y+=5]){
							if(da.x+5<30&&da.y+5<30){
								da.x+=5;
								da.y+=5;
								return da;
							}
						}
						if(da.x+4<30&&da.y+4<30){
							da.x+=4;
							da.y+=4;
							return da;
						}
					}
				}
			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban &&x<30 &&y<30){
				dem++;
				x++;
				y++;
			}
			if(dem==4) {
				da.x=i;
				da.y=j;
				if(banco[da.x-1][da.y-1]==0 && da.x-1>=0 && da.y-1>=0) {
					da.x-=1;
					da.y-=1;
					return da;
				}
				if(banco[da.x+4][da.y+4]==0 && da.x+4<30 && da.y+4<30){
					da.x+=4;
					da.y+=4;
					return da;
				}
			}
		}
	}
	//cheo phu
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi &&x>=0&y<30){
				dem++;
				x--;
				y++;
			}
			if(dem==4) {
				da.x=i;
				da.y=j;
				if(banco[da.x-4][da.y+4]!=ban && banco[da.x-5][da.y+5]!=ban) {
					if(banco[da.x-4][da.y+4]==0){
						if(banco[da.x-5][da.y+5]==0){
							if(da.x-5>=0&&da.y+5<30){
								da.x-=5;
								da.y+=5;
								return da;
							}
						}
						if(da.x-4>=0&&da.y+4<30){
							da.x-=4;
							da.y+=4;
							return da;
						}
					}
				}
				if(banco[da.x+1][da.y-1]!=ban && banco[da.x+2][da.y-2]!=ban){
					if(banco[da.x+1][da.y-1]==0){
						if(banco[da.x+2][da.y-2]==0){
							if(da.x+2<30&&da.y-2>=0){
								da.x+=2;
								da.y-=2;
								return da;
							}
						}
						if(da.x+1<30&&da.y-1>=0){
							da.x+=1;
							da.y-=1;
							return da;
						}
					}
				}
			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban &&x>=0&y<30){
				dem++;
				x--;
				y++;
			}
			if(dem==4) {
				da.x=i;
				da.y=j;
				if(banco[da.x-4][da.y+4]==0&& da.x-4>=0 && da.y+4<30) {
						da.x-=4;
						da.y+=4;
						return da;
				}
				if(banco[da.x+1][da.y-1]==0 && da.x+1<30 && da.y-1>=0){
						da.x+=1;
						da.y-=1;
						return da;
				}
			}
		}
	}
    da.reset();
    return da;
}

toado uu_tien_3(int banco[30][30]){
	toado da;
		//cheo chinh
	for(int i=29;i>=0;i--){
		for(int j=29;j>=0;j--){
            //toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && x<30 && y<30){
				dem++;
				x++;
				y++;
			}
			if(dem==3) {
				da.x=i;
				da.y=j;
				if(banco[da.x+3][da.y+3]!=ban &&banco[da.x+4][da.y+4]!=ban &&banco[da.x+5][da.y+5]!=ban){//ktra 0 treo phai xuong
					if(banco[da.x+3][da.y+3]==0){
						if(banco[da.x+4][da.y+4]==0){
							if(banco[da.x+5][da.y+4]==0){
								if(da.x+5<30&& da.y+5<30){
									da.x+=5;
									da.y+=5;
									return da;
								}
							}
							if(da.x+4<30&&da.y+4<30){
								da.x+=4;
								da.y+=4;
								return da;
							}
						}
						if(da.x+3<30&&da.y+3<30){
							da.x+=3;
							da.y+=3;
							return da;
						}
					}
				}
				if(banco[da.x-1][da.y-1]!=ban&&banco[da.x-2][da.y-2]!=ban&&banco[da.x-3][da.y-3]!=ban){//ktra 3 o cheo len trai
					if(banco[da.x-1][da.y-1]==0){
						if(banco[da.x-2][da.y-2]==0){
							if(banco[da.x-3][da.y-3]==0){
								if(da.x-3>=0 && da.y-3>=0){
									da.x-=3;
									da.y-=3;
									return da;
								}
							}
							if(da.x-2>=0 && da.y-2>=0){
								da.x-=2;
								da.y-=2;
								return da;
							}
						}
						if(da.x-1>=0&&da.y-1>=0){
							da.x-=1;
							da.y-=1;
							return da;
						}
					}
				}
			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban &&x<30&&y<30){
				dem++;
				x++;
				y++;
			}
			if(dem==3) {
				da.x=i;
				da.y=j;
				if(banco[da.x+3][da.y+3]==0){//ktra 0 treo phai xuong
                    if(da.x+3<30&&da.y+3<30){
                    	da.x+=3;
                    	da.y+=3;
                    	return da;
					}
				}
				if(banco[da.x-1][da.y-1]==0){//chan 3 o cheo len trai
                    if(da.x-1>=0 && da.y-1>=0){
                    	da.x-=1;
                    	da.y-=1;
                    	return da;
					}
				}
			}
		}
	}
	//cheo phu
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi &&x>=0&y<30){
				dem++;
				x--;
				y++;
			}
			if(dem==3) {
				da.x=i;
				da.y=j;
				if(banco[da.x-3][da.y+3]!=ban && banco[da.x-4][da.y+4]!=ban && banco[da.x-5][da.y+5]!=ban){
                    if(banco[da.x-3][da.y+3]==0){
                        if(banco[da.x-4][da.y+4]==0){
                            if(banco[da.x-5][da.y+5]==0){
                                if(da.x-5>=0 && da.y+5<30){
                                	da.x-=5;
                                	da.y+=5;
                                	return da;
								}
                            }
                            if(da.x-4>=0&&da.y+4<30){
                            	da.x-=4;
                            	da.y+=4;
                            	return da;
							}
                        }
                        if(da.x-3>=0 && da.y+3<30){
                        	da.x-=3;
                        	da.y+=3;
                        	return da;
						}
                    }
				}
				if(banco[da.x+1][da.y-1]!=ban && banco[da.x+2][da.y-2]!=ban &&banco[da.x+3][da.y-3]!=ban){
                    if(banco[da.x+1][da.y-1]==0){
                        if(banco[da.x+2][da.y-2]==0){
                            if(banco[da.x+3][da.y-3]==0){
                                if(da.x+3<30&&da.y-3>=0){
                                	da.x+=3;
                                	da.y-=3;
                                	return da;
								}
                            }
                            if(da.x+2<30&&da.y-2>=0){
                            	da.x+=2;
                            	da.y-=2;
                            	return da;
							}
                        }
                        if(da.x+1<30&&da.y-1>=0){
                        	da.x+=1;
                        	da.y-=1;
                        	return da;
						}
                    }
				}
			}
			//ban
            x=i,y=j,dem=0;
			while(banco[x][y]==ban &&x>=0&y<30){
				dem++;
				x--;
				y++;
			}
			if(dem==3) {
				da.x=i;
				da.y=j;
				if(banco[da.x-3][da.y+3]==0){
                    if(da.x-3>=0 && da.y+3<30){
                    	da.x-=3;
                    	da.y+=3;
                    	return da;
					}
				}
				if(banco[da.x+1][da.y-1]==0){
                    if(da.x+1<30 && da.y-1>=0){
                    	da.x+=1;
                    	da.y-=1;
                    	return da;
					}
				}
			}
		}
	}
	//hang ngang
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && y<30){
				dem++;
				y++;
			}
			if(dem==3) {
				da.x=i;
				da.y=j;
				if(banco[da.x][da.y-1]!= ban && banco[da.x][da.y-2]!= ban && banco[da.x][da.y-3]!= ban ){// co the thang dc
					if(banco[da.x][da.y-1]==0){//ktra lui sau 3o
						if(banco[da.x][da.y-2]==0){
							if(banco[da.x][da.y-3]==0){
								if(da.y>=3){
									da.y-=3;
									return da;
								}
							}
							if(da.y>=2){
								da.y-=2;
								return da;
							}
						}
						if(da.y>=1){
							da.y-=1;
							return da;
						}
					}
				}
				if(banco[da.x][da.y+3]!=ban&&banco[da.x][da.y+4]!=ban&&banco[da.x][da.y+5]!=ban){//dk co the thang
					if(banco[da.x][da.y+3]==0){// ktra tien truoc 3 o
						if(banco[da.x][da.y+4]==0){
							if(banco[da.x][da.y+5]==0){
								if(da.y+5<30){// ko bi vuot bien
									da.y+=5;
									return da;
								}
							}
							if(da.y+4<30){// kvb
								da.y+=4;
								return da;
							}
						}
						if(da.y+3<30){// kvb
							da.y+=3;
							return da;
						}
					}
				}

			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban && y<30){
				dem++;
				y++;
			}
			if(dem==3) {
				da.x=i;
				da.y=j;
				if(banco[da.x][da.y-1]==0){//chan ngay 3 quan
					if(da.y-1>=0){//kvb
						da.y-=1;
						return da;
					}
				}
				if(banco[da.x][da.y+3]==0){//chan ngay
					if(da.y+3<30){//kvb
						da.y+=3;
						return da;
					}
				}
			}
		}
	}
	//hang doc
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && i<30){
				dem++;
				x++;
			}
			if(dem==3) {
				da.x=i;
				da.y=j;
				if(banco[da.x-1][y]!=ban && banco[da.x-2][y]!=ban && banco[da.x-3][y]!=ban){// ktra c3 o phia tren
					if(banco[da.x-3][y]==0){
						if(banco[da.x-2][y]==0){
							if(banco[da.x-1][y]==0){
								if(da.x-1>=0){//kvb
									da.x-=1;
									return da;
								}
							}
							if(da.x-2>=0){//kvb
								da.x-=2;
								return da;
							}
						}
						if(da.x-3>=0){
							da.x-=3;
							return da;
						}
					}
				}
				if(banco[da.x+3][da.y]!=ban&&banco[da.x+4][da.y]!=ban&&banco[da.x+5][da.y]!=ban){//ktra 3 o ben duoi
					if(banco[da.x+3][da.y]==0){
						if(banco[da.x+4][da.y]==0){
							if(banco[da.x+5][da.y]==0){
								if(da.x+5<30){
									da.x+=5;
									return da;
								}
							}
							if(da.x+4<30){
								da.x+=4;
								return da;
							}
						}
						if(da.x+3<30){
							da.x+=3;
							return da;
						}
					}
				}

			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban && i<30){
				dem++;
				x++;
			}
			if(dem==3) {
				da.x=i;
				da.y=j;
				if(banco[da.x-1][y]==0){// chan 3 doc
					if(da.x-1>=0){
						da.x-=1;
						return da;
					}
				}
				if(banco[da.x+3][da.y]==0){//ktra 3 o ben duoi
					if(da.x+3<30){
						da.x+=3;
						return da;
					}
				}
			}
		}
	}

	da.reset();
	return da;
}
toado uu_tien_2(int banco[30][30]){
	toado da;
		//cheo chinh
	for(int i=29;i>=0;i--){
		for(int j=29;j>=0;j--){
            //toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && x<30 && y<30){
				dem++;
				x++;
				y++;
			}
			if(dem==2) {
				da.x=i;
				da.y=j;
				if(banco[da.x+2][da.y+2]!=ban &&banco[da.x+3][da.y+3]!=ban &&banco[da.x+4][da.y+4]!=ban){//ktra 0 treo phai xuong
					if(banco[da.x+3][da.y+3]==0){
						if(banco[da.x+4][da.y+4]==0){
							if(banco[da.x+2][da.y+2]==0){
								if(da.x+2<30&& da.y+2<30){
									da.x+=2;
									da.y+=2;
									return da;
								}
							}
							if(da.x+4<30&&da.y+4<30){
								da.x+=4;
								da.y+=4;
								return da;
							}
						}
						if(da.x+3<30&&da.y+3<30){
							da.x+=3;
							da.y+=3;
							return da;
						}
					}
				}
				if(banco[da.x-1][da.y-1]!=ban&&banco[da.x-2][da.y-2]!=ban&&banco[da.x-3][da.y-3]!=ban){//ktra 3 o cheo len trai
					if(banco[da.x-1][da.y-1]==0){
						if(banco[da.x-2][da.y-2]==0){
							if(banco[da.x-3][da.y-3]==0){
								if(da.x-2>=0 && da.y-2>=0){
									da.x-=2;
									da.y-=2;
									return da;
								}
							}
							if(da.x-3>=0 && da.y-3>=0){
								da.x-=3;
								da.y-=3;
								return da;
							}
						}
						if(da.x-1>=0&&da.y-1>=0){
							da.x-=1;
							da.y-=1;
							return da;
						}
					}
				}
			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban &&x<30&&y<30){
				dem++;
				x++;
				y++;
			}
			if(dem==2) {
				da.x=i;
				da.y=j;
				if(banco[da.x+2][da.y+2]==0){//ktra 0 treo phai xuong
                    if(da.x+2<30&&da.y+2<30){
                    	da.x+=2;
                    	da.y+=2;
                    	return da;
					}
				}
				if(banco[da.x-1][da.y-1]==0){//chan 2 o cheo len trai
                    if(da.x-1>=0 && da.y-1>=0){
                    	da.x-=1;
                    	da.y-=1;
                    	return da;
					}
				}
			}
		}
	}
	//cheo phu
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi &&x>=0&y<30){
				dem++;
				x--;
				y++;
			}
			if(dem==2) {
				da.x=i;
				da.y=j;
				if(banco[da.x-3][da.y+3]!=ban && banco[da.x-4][da.y+4]!=ban && banco[da.x-2][da.y+2]!=ban){
                    if(banco[da.x-3][da.y+3]==0){
                        if(banco[da.x-4][da.y+4]==0){
                            if(banco[da.x-2][da.y+2]==0){
                                if(da.x-2>=0 && da.y+2<30){
                                	da.x-=2;
                                	da.y+=2;
                                	return da;
								}
                            }
                            if(da.x-4>=0&&da.y+4<30){
                            	da.x-=4;
                            	da.y+=4;
                            	return da;
							}
                        }
                        if(da.x-3>=0 && da.y+3<30){
                        	da.x-=3;
                        	da.y+=3;
                        	return da;
						}
                    }
				}
				if(banco[da.x+1][da.y-1]!=ban && banco[da.x+2][da.y-2]!=ban &&banco[da.x+3][da.y-3]!=ban){
                    if(banco[da.x+1][da.y-1]==0){
                        if(banco[da.x+2][da.y-2]==0){
                            if(banco[da.x+3][da.y-3]==0){
                                if(da.x+3<30&&da.y-3>=0){
                                	da.x+=3;
                                	da.y-=3;
                                	return da;
								}
                            }
                            if(da.x+2<30&&da.y-2>=0){
                            	da.x+=2;
                            	da.y-=2;
                            	return da;
							}
                        }
                        if(da.x+1<30&&da.y-1>=0){
                        	da.x+=1;
                        	da.y-=1;
                        	return da;
						}
                    }
				}
			}
			//ban
            x=i,y=j,dem=0;
			while(banco[x][y]==ban &&x>=0&y<30){
				dem++;
				x--;
				y++;
			}
			if(dem==2) {
				da.x=i;
				da.y=j;
				if(banco[da.x-2][da.y+2]==0){
                    if(da.x-2>=0 && da.y+2<30){
                    	da.x-=2;
                    	da.y+=2;
                    	return da;
					}
				}
				if(banco[da.x+1][da.y-1]==0){
                    if(da.x+1<30 && da.y-1>=0){
                    	da.x+=1;
                    	da.y-=1;
                    	return da;
					}
				}
			}
		}
	}
	//hang ngang
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && y<30){
				dem++;
				y++;
			}
			if(dem==2) {
				da.x=i;
				da.y=j;
				if(banco[da.x][da.y-1]!= ban && banco[da.x][da.y-2]!= ban && banco[da.x][da.y-3]!= ban ){// co the thang dc
					if(banco[da.x][da.y-1]==0){//ktra lui sau 3o
						if(banco[da.x][da.y-2]==0){
							if(da.y>=2){
								da.y-=2;
								return da;
							}
						}
						if(da.y>=1){
							da.y-=1;
							return da;
						}
					}
				}
				if(banco[da.x][da.y+3]!=ban&&banco[da.x][da.y+4]!=ban&&banco[da.x][da.y+5]!=ban){//dk co the thang
					if(banco[da.x][da.y+4]==0){// ktra tien truoc 3 o
						if(banco[da.x][da.y+3]==0){
							if(da.y+3<30){// kvb
								da.y+=3;
								return da;
							}
						}
						if(da.y+4<30){// kvb
							da.y+=4;
							return da;
						}
					}
				}

			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban && y<30){
				dem++;
				y++;
			}
			if(dem==2) {
				da.x=i;
				da.y=j;
				if(banco[da.x][da.y-1]==0){//chan ngay 3 quan
					if(da.y-1>=0){//kvb
						da.y-=1;
						return da;
					}
				}
				if(banco[da.x][da.y+2]==0){//chan ngay
					if(da.y+2<30){//kvb
						da.y+=2;
						return da;
					}
				}
			}
		}
	}
	//hang doc
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			//toi
			int x=i,y=j,dem=0;
			while(banco[x][y]==toi && i<30){
				dem++;
				x++;
			}
			if(dem==2) {
				da.x=i;
				da.y=j;
				return da;
				if(banco[da.x-1][y]!=ban && banco[da.x-2][y]!=ban && banco[da.x-3][y]!=ban){// ktra c3 o phia tren
					if(banco[da.x-3][y]==0){
						if(banco[da.x-2][y]==0){
							if(banco[da.x-1][y]==0){
								if(da.x-1>=0){//kvb
									da.x-=1;
									return da;
								}
							}
							if(da.x-2>=0){//kvb
								da.x-=2;
								return da;
							}
						}
						if(da.x-3>=0){
							da.x-=3;
							return da;
						}
					}
				}
				if(banco[da.x+3][da.y]!=ban&&banco[da.x+4][da.y]!=ban&&banco[da.x+5][da.y]!=ban){//ktra 3 o ben duoi
					if(banco[da.x+3][da.y]==0){
						if(banco[da.x+4][da.y]==0){
							if(da.x+4<30){
								da.x+=4;
								return da;
							}
						}
						if(da.x+3<30){
							da.x+=3;
							return da;
						}
					}
				}

			}
			//ban
			x=i,y=j,dem=0;
			while(banco[x][y]==ban && i<30){
				dem++;
				x++;
			}
			if(dem==2) {
				da.x=i;
				da.y=j;
				if(banco[da.x-1][y]==0){// chan 3 doc
					if(da.x-1>=0){
						da.x-=1;
						return da;
					}
				}
				if(banco[da.x+2][da.y]==0){//ktra 3 o ben duoi
					if(da.x+2<30){
						da.x+=2;
						return da;
					}
				}
			}
		}
	}

	da.reset();
	return da;
}
toado uu_tien_1(int banco[30][30]){
	toado da;
	int x,y;
	fstream f("luotchoi.txt",ios::in);
	f>>x>>x>>y;
	for(int i=x-1;i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++){//ktra xung quanh 1o
			if(banco[i+2][j+2]==toi && banco[i+2][j+2]==toi &&i+2<30 && x-1>=0 ){// neu== toi
				if(banco[i][j+2]==0){// danh sang phai
					da.y=j+2;
					da.x=i;
					return da;
				}
				if(banco[i+2][j]==0){
					//danh xuong duoi
					da.x=i+2;
					da.y=j;
					return da;
				}
			}
			if(banco[i][j]==toi && banco[i][j+2]==toi ){//danh vao giua 2 o

			}
		}
	}
	da.reset();
	return da;
}
toado uu_tien_0(int banco[30][30]){
	toado da;
	int x,y;
	fstream f("luotchoi.txt",ios::in);
	f>>x>>x>>y;
	for(int n=1;n<=10;n++){
		for(int j=y-n;j<=y+n;j++){
		for(int i=x-n;i<=x+n;i++){
			if(banco[i][j]==0 && i>=0 && j>=0 &&i<30 && j<30){
				da.x=i;
				da.y=j;
				return da;
			}
		}
		}
	}
}
toado dac_biet(int banco[30][30]){
    toado da;

}
void step(int banco[30][30]){
        if(luot_di()==ban){
            hien_thi(banco);//hien thi ban vua di
            toado da=uu_tien_5(banco);
            if(da.x>=0&& da.y>=0){
                di(banco,da);
                return;
            }
            da=uu_tien_4(banco);
            if(da.x>=0&& da.y>=0){
                di(banco,da);
                return;
            }
            da=uu_tien_3(banco);
            if(da.x>=0 && da.y>=0){
                di(banco,da);
                return;
            }
            da=uu_tien_2(banco);
            if(da.x>=0 && da.y>=0){
                di(banco,da);
                return;
            }
            da=uu_tien_1(banco);
            if(da.x>=0 && da.y>=0){
                di(banco,da);
                return;
            }
            da=uu_tien_0(banco);
            if(da.x>=0&& da.y>=0){
                di(banco,da);
                return;
			}
        }

	hien_thi(banco);
    return;
}
void kq(int banco[30][30]){
	int win=kiem_tra(banco);
	if(win==toi){
		cout<<"toi thang";
	}
	if(win==ban){
		cout<<"doi thu thang";
	}
	if(win==0){
		cout<<"hoa";
	}
}
void khoi_dong(int banco[30][30]){
	cout<<"minh chon: ";
	cin>>toi;
	toi==2 ? ban=1: ban=2;
	toado da;
	doc_file(banco);
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			if(banco[i][j]!=0) return;
		}
	}
	da.x=14;
	da.y=14;
	di(banco,da);
	return;
}
main(){
	int banco[30][30];
	khoi_dong(banco);
	hien_thi(banco);
//	while(kiem_tra(banco)==0){
//		step(banco);
//	}
//	kq(banco);
//	Sleep(10000);
}

