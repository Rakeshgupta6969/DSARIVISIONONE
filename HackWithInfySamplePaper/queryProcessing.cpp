#include<iostream>
#include<vector>

using namespace std;

int main(){
    

    int n;
    cout<<"enter the size of the array:"<<endl;
    cin>>n;
     
    cout<<endl;


    vector<int>element(n);
    cout<<"enter the element of the array"<<endl;
    
    

    int M;
    cout<<"enter the total Number of the query:"<<endl;
    cin>>M;
    cout<<endl;


    vector<vector<int>>query(M);
    cout<<"enter the value of the l,r,x and y of the each query"<<endl;

    for(int i = 0;i<M; i++){

      for(int j = 0; j<4; j++){
        cin>>query[i][j];
      }
      cout<<endl;

    }


    
    // now update the element of the array using the query;

    for(int i = 0; i<M; i++){
        int l = query[i][0];
        int r = query[i][1];
        int x = query[i][2];
        int y = query[i][3];



        // now update the element;

        for(int j = l; j<=r; j++){
          
            element[j] =  x  +  (j-l)*y;

        }
    }



    int totalSum = 0;
    for(auto & num : element){
        totalSum += num;
    }

    return totalSum;


   



       return 0;
}