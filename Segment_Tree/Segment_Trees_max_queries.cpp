// Q link: https://leetcode.com/problems/fruits-into-baskets-iii/description/
// compare with root then update the left most child (>=val)  possible to -1 in update query 
class Solution {
public:
class SegmentTree{
public:
   vector<int> sgt,arr;
   int n;
   SegmentTree(vector<int> arr){
      this->arr=arr;
      n=arr.size();
      sgt.resize(4*n,0);
      build(0,n-1,0);
   }

   void build(int l,int r,int i){
    if(l==r){
        sgt[i]=arr[l];return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*i+1);
    build(mid+1,r,2*i+2);
    sgt[i]=max(sgt[2*i+1],sgt[2*i+2]);
   }

   void update(int val,int l,int r,int i){
     if(l==r){
        sgt[i]=-1;return;
     }
     int mid=(l+r)/2;
     if(sgt[2*i+1]>=val){
        update(val,l,mid,2*i+1);
     }
     else{
        update(val,mid+1,r,2*i+2);
     }
     sgt[i]=max(sgt[2*i+1], sgt[2*i+2]);
   }
};
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0,n=fruits.size();
        SegmentTree segTree(baskets);
        vector<int> v=segTree.sgt;

        for(int i=0;i<n;++i){
            if(fruits[i]<=segTree.sgt[0]){
                segTree.update(fruits[i],0,n-1,0);
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};
