#include<iostream>
#include<string>
#include<cmath>
#include<array>
using namespace std;
//double mode(double arr[],int sizearr);

double ungroup_mean(double arr[],int sizarr);//ungroup data mean
double median(double arr[],int sizearr);//ungrouped median
double range(double arr[],int sizearr);//range
double un_pop_vari(double arr[],int sizearr,double meaan);//ungrouped population variance
double un_pop_sd(double arr[],int sizearr,double meaan);//ungroup population standard deviation
double un_sam_vari(double arr[],int sizearr,double meaan);//ungroup sample variance
double un_sam_sd(double arr[],int sizearr,double meaan);//ungroup sample standard deviation
double un_first_quart(double arr[],int sizearr);// 1st quartile
double un_third_quart(double arr[],int sizearr);//3 rd quartile
double in_quar_range(double arr[],int sizearr);//IQR
double un_up_outlier(double arr[],int sizarr);//upper limit for outlier
double un_lo_outlier(double arr[],int sizarr);//lower limit for outlier

int main(){
int ele,sel;
cout<<"Your calculation is regarding?"<<endl;
cout<<"(1) Population"<<endl;
cout<<"(2) Sample"<<endl;
cout<<" "<<endl;
cout<<"Select the number"<<endl;
cin>>sel;

if(sel==1){
cout<<" "<<endl;
cout<<"Enter the number of elements"<<endl;
cin>>ele;
cout<<"-------------------"<<endl;
double arr1[ele];
for(int i=0;i<ele;i++){
    cout<<"Enter the "<<(i+1)<<" element"<<endl;
    cin>>arr1[i];
}
cout<<" "<<endl;
double mean=ungroup_mean(arr1,ele);
cout<<"Median value :"<<median(arr1,ele)<<endl;
cout<<"Mean value :"<<ungroup_mean(arr1,ele)<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"Range value :"<<range(arr1,ele)<<endl;
cout<<"Variance value :"<<un_pop_vari(arr1,ele,mean)<<endl;
cout<<"Standard deviation value :"<<un_pop_sd(arr1,ele,mean)<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"First quartile (Q1) :"<<un_first_quart(arr1,ele)<<endl;
cout<<"Second quartile (Q2) :"<<median(arr1,ele)<<endl;
cout<<"Third quartile (Q3) :"<<un_third_quart(arr1,ele)<<endl;
cout<<"Inter Quartile Range (IQR) :"<<in_quar_range(arr1,ele)<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"Upper limit for outlier :"<<un_up_outlier(arr1,ele)<<endl;
cout<<"Lower limit for outlier :"<<un_lo_outlier(arr1,ele)<<endl;
cout<<" "<<endl;//line space

}else if(sel==2){
cout<<" "<<endl;
cout<<"Enter the number of elements"<<endl;
cin>>ele;
cout<<"-------------------"<<endl;
double arr1[ele];
for(int i=0;i<ele;i++){
    cout<<"Enter the "<<(i+1)<<" element"<<endl;
    cin>>arr1[i];
}
cout<<" "<<endl;
double mean=ungroup_mean(arr1,ele);
cout<<"Median value :"<<median(arr1,ele)<<endl;
cout<<"Mean value :"<<ungroup_mean(arr1,ele)<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"Range value :"<<range(arr1,ele)<<endl;
cout<<"Variance value :"<<un_sam_vari(arr1,ele,mean)<<endl;
cout<<"Standard deviation value :"<<un_sam_sd(arr1,ele,mean)<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"First quartile (Q1) :"<<un_first_quart(arr1,ele)<<endl;
cout<<"Second quartile (Q2) :"<<median(arr1,ele)<<endl;
cout<<"Third quartile (Q3) :"<<un_third_quart(arr1,ele)<<endl;
cout<<"Inter Quartile Range (IQR) :"<<in_quar_range(arr1,ele)<<endl;
cout<<"-------------------------------------"<<endl;
cout<<"Upper limit for outlier :"<<un_up_outlier(arr1,ele)<<endl;
cout<<"Lower limit for outlier :"<<un_lo_outlier(arr1,ele)<<endl;
cout<<" "<<endl;//line space
}
else{
    cout<<"Invalid option....Please try again"<<endl;
}
return 0;
}

double ungroup_mean(double arr[],int sizarr){
double coun=0;
for(int i=0;i<sizarr;i++){
    coun=coun+arr[i];
}
double mean=coun/sizarr;
return mean;
}
double median(double arr[],int sizearr){
double x;
for(int i=0;i<sizearr;i++){
    for(int j=(i+1);j<sizearr;j++){
        if(arr[i]>arr[j]){
            x=arr[i];
            arr[i]=arr[j];
            arr[j]=x;
        }
    }
}
int new_coun1,new_coun2;
double mediann;
if(sizearr%2!=0){
    new_coun1=(sizearr+1)/2;
    mediann=arr[new_coun1-1];

}
else{
    new_coun1=(sizearr+1)/2;
    double new_coun2=(arr[new_coun1-1]+arr[new_coun1])/2;
    mediann=new_coun2;
}
return mediann;
}
double range(double arr[],int sizearr){
double large=arr[0];
for(int i=0;i<sizearr;i++){
    if(large<arr[i]){
        large=arr[i];
    }
}
double small=arr[0];
for(int i=0;i<sizearr;i++){
    if(small>arr[i]){
        small=arr[i];
    }
}
double rang=large-small;
return rang;
}
double un_pop_vari(double arr[],int sizearr,double meaan){
double add;
for(int i=0;i<sizearr;i++){
    add=add+pow((arr[i]-meaan),2);
}
double un_popu_vari=(add/sizearr);
return un_popu_vari;
}
double un_pop_sd(double arr[],int sizearr,double meaan){
//double un_pop_vari(double arr[],int sizearr,double meaan);
double sdunpop=sqrt(un_pop_vari(arr,sizearr,meaan));
return sdunpop;
}
double un_sam_vari(double arr[],int sizearr,double meaan){
double varunsam=(un_pop_vari(arr,sizearr,meaan)*sizearr)/(sizearr-1);
return varunsam;
}
double un_sam_sd(double arr[],int sizearr,double meaan){
double sdunsam=sqrt(un_sam_vari(arr,sizearr,meaan));
return sdunsam;
}
double un_first_quart(double arr[],int sizearr){
double x;
for(int i=0;i<sizearr;i++){
    for(int j=(i+1);j<sizearr;j++){
        if(arr[i]>arr[j]){
            x=arr[i];
            arr[i]=arr[j];
            arr[j]=x;
        }
    }
}
int var1;
double var_1,var2;
if(sizearr%2!=0){
   var1=(sizearr+1)/4;
   var2=arr[var1-1];
}else{
    var1=(sizearr+1)/4;
    var_1=(arr[var1]-arr[var1-1])*0.25;
    var2=var_1+arr[var1-1];
}
return var2;
}
double un_third_quart(double arr[],int sizearr){
double x;
for(int i=0;i<sizearr;i++){
    for(int j=(i+1);j<sizearr;j++){
        if(arr[i]>arr[j]){
            x=arr[i];
            arr[i]=arr[j];
            arr[j]=x;
        }
    }
}
int var1;
double var_1,var2;
if(sizearr%2!=0){
   var1=3*(sizearr+1)/4;
   var2=arr[var1-1];
}else{
    var1=3*(sizearr+1)/4;
    var_1=(arr[var1]-arr[var1-1])*0.75;
    var2=var_1+arr[var1-1];
}
return var2;
}
double in_quar_range(double arr[],int sizearr){
double iqr=un_third_quart(arr,sizearr)-un_first_quart(arr,sizearr);
return iqr;
}
double un_up_outlier(double arr[],int sizarr){
double uplimout=un_third_quart(arr,sizarr)+(1.5*in_quar_range(arr,sizarr));
return uplimout;
}
double un_lo_outlier(double arr[],int sizarr){
double lolimout=un_first_quart(arr,sizarr)-(1.5*in_quar_range(arr,sizarr));
return lolimout;
}


