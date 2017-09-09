class Solution {
public:
  //一开始审题审错了，不应该排序的
  int Binary_sort(vector<int>& nums,int p,int r,int v){     //缩小寻找区间后，寻找插入位置
    for(int j=p;j<r+1;j++){
    if(nums[j]>v)
      return j;
    }
    return -1;
  }
    
  int BinarySearch_sort(vector<int>& nums,int p,int r,int v){
    int q=0;
    if(p==0&&r==0&&nums[0]>v)
      return 0;
    if(p<r){
      q=(p+r)/2;
      if(nums[q]>v){
        BinarySearch_sort(nums,p,q,v);
        return Binary_sort(nums,p,q,v);
      }
      else{
        BinarySearch_sort(nums,q+1,r,v);
        return Binary_sort(nums,q+1,r,v);
      }
    }
    return -1;
  }

  int BinaryInsertionSort(vector<int>& nums,vector<int >& numsIndex){
    int size=nums.size();
    int key=0,i=0,k=0,keyIndex=0;
    for(int j=1;j<size;j++){
      key=nums[j];
      keyIndex = numsIndex[j];
      i=j-1;
      k=BinarySearch_sort(nums,0,i,key);
      if(k!=-1){
        for (int m = i; m >= k; m--) {
          nums[m + 1] = nums[m];
          numsIndex[m + 1] = numsIndex[m];
        }
        numsIndex[k] = keyIndex;
        nums[k]=key;
      }
    }
    /*int m = numsIndex[0];
    int n = numsIndex[1];
    int y = numsIndex[2];
    int z = numsIndex[3];*/
    return 0;
  }
  
  int Binary_find(vector<int>& nums, int p, int r, int v) {     //最终寻找
    for (int j = p; j<r+1 ; j++) {
      if (nums[j] == v)
        return j;
    }
    return -1;
  }

  int BinarySearch_find(vector<int >& nums, int p, int r, int v) {    //二分查找
    int q = 0;
    if (p == 0 && r == 0 && nums[0] == v)
      return 0;
    if (p == r)
      return Binary_find(nums, p, p, v);
    if (p<r) {
      q = (p + r) / 2;
      if (nums[q]>=v) {
        BinarySearch_find(nums, p, q, v);
        return Binary_find(nums, p, q, v);
      }
      else {
        BinarySearch_find(nums, q + 1, r, v);
        return Binary_find(nums, q + 1, r, v);
      }
    }
    return -1;
  }

  vector<int> isExistSum(vector<int>& nums, int target,vector<int>& numsIndex) {
    vector<int > outVec;
    int k = 0;
    BinaryInsertionSort(nums,numsIndex);
    /*for (int i = 0; i<4; i++)
      cout << nums[i] << endl;*/
    int n = nums.size();
    for (int j = 0; j<n-1 ; j++) {
      k = BinarySearch_find(nums, j+1 , n - 1, target - nums[j]);
      if (k != -1) {
        /*int m = numsIndex[0];
        int n = numsIndex[1];
        int y = numsIndex[2];
        int z = numsIndex[3];*/
        outVec.push_back(numsIndex[j]);
        outVec.push_back(numsIndex[k]);
        return outVec;
      }
    }
    return outVec;
  }
  vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    vector<int > numsIndex(size);
    for (int i = 0; i < size; i++)
      numsIndex[i] = i;
    return isExistSum(nums, target,numsIndex);
  }
};
