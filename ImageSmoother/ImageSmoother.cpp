class Solution{
public:
  vector<vector<int> > imageSmoother(vector<vector<int> >& M){
    int rows=M.size();
    int cols=M[0].size();
    int temp=0;
    vector<vector<int> > mOut(rows,vector<int > (cols));
    if(rows==1&&cols==1){
      mOut[0][0]=M[0][0];
      return mOut;
    }
    else if(rows==1){
      mOut[0][0]=(M[0][0]+M[0][1])/2;
      mOut[0][cols-1]=(M[0][cols-2]+M[0][cols-1])/2;
      for(int k=1;k<cols-1;k++)
        mOut[0][k]=(M[0][k-1]+M[0][k]+M[0][k+1])/3;
      return mOut;
    }
    else if(cols==1){
      mOut[0][0]=(M[0][0]+M[1][0])/2;
      mOut[rows-1][0]=(M[rows-1][0]+M[rows-2][0])/2;
      for(int k=1;k<rows-1;k++)
        mOut[k][0]=(M[k-1][0]+M[k][0]+M[k+1][0])/3;
      return mOut;
    }
    else{
      mOut[0][0]=(M[0][0]+M[0][1]+M[1][0]+M[1][1])/4;
      mOut[0][cols-1]=(M[0][cols-2]+M[0][cols-1]+M[1][cols-2]+M[1][cols-1])/4;
      mOut[rows-1][0]=(M[rows-2][0]+M[rows-2][1]+M[rows-1][0]+M[rows-1][1])/4;
      mOut[rows-1][cols-1]=(M[rows-2][cols-2]+M[rows-2][cols-1]+M[rows-1][cols-2]+M[rows-1][cols-1])/4;
      for(int k=1;k<cols-1;k++){
        mOut[0][k]=(M[0][k-1]+M[0][k]+M[0][k+1]+M[1][k-1]+M[1][k]+M[1][k+1])/6;
        mOut[rows-1][k]=(M[rows-2][k-1]+M[rows-2][k]+M[rows-2][k+1]+M[rows-1][k-1]+M[rows-1][k]+M[rows-1][k+1])/6;
      }
      for(int k=1;k<rows-1;k++){
        mOut[k][0]=(M[k-1][0]+M[k][0]+M[k+1][0]+M[k-1][1]+M[k][1]+M[k+1][1])/6;
        mOut[k][cols-1]=(M[k-1][cols-2]+M[k][cols-2]+M[k+1][cols-2]+M[k-1][cols-1]+M[k][cols-1]+M[k+1][cols-1])/6;
      }
      for(int i=1;i<rows-1;i++)
        for(int j=1;j<cols-1;j++){
          mOut[i][j]=(M[i-1][j-1]+M[i-1][j]+M[i-1][j+1]+M[i][j-1]+M[i][j]+M[i][j+1]+M[i+1][j-1]+M[i+1][j]+M[i+1][j+1])/9;
        }
      return mOut;
    }
  }
};