// Q link: https://cses.fi/problemset/task/1649/
#include<bits/stdc++.h>
using namespace std;

class SegTree{
private:
	vector<int> sgt,arr;
	int n;
public:
	SegTree(vector<int> arr){
       this->arr=arr;
       n=arr.size();
       sgt.resize(4*n);
       build(0,0,n-1);
	}

	void build(int i,int l,int r){
		if(l==r){
			sgt[i]=arr[l];return;
		}
        int mid=(l+r)/2;
		build(2*i+1,l,mid);
		build(2*i+2,mid+1,r);

		sgt[i]=min(sgt[2*i+1], sgt[2*i+2]);
	}

	int query(int start,int end,int i,int l,int r){
		if(l>end || r<start){
			return INT_MAX;
		}
		else if(l>=start && r<=end){
			return sgt[i];
		}
		else{
			int mid=(l+r)/2;
			return min(query(start,end,2*i+1,l,mid) , query(start,end,2*i+2,mid+1,r));
		}
	}

	void update(int i,int val,int j,int l,int r){
		if(l==r){
			sgt[j]=val;
			arr[i]=val;
			return;
		}
		int mid=(l+r)/2;
		if(i<=mid){
			update(i,val,2*j+1,l,mid);
		}
		else{
			update(i,val,2*j+2,mid+1,r);
		}
		sgt[j]=min(sgt[2*j+1], sgt[2*j+2]);
	}
};

int main(){
    int n,q;cin >> n >> q;
    vector<int> nums(n);

    for(auto &x: nums) cin >> x;

    SegTree sgt(nums);
    
    while(q--){
    	int type;cin >> type;
    	if(type==1){
    		int pos,val;cin >> pos >> val;
    		pos--;
    		sgt.update(pos,val,0,0,n-1);
    	}
    	else{
    	    int l,r;cin >> l >> r;
    		l--;r--;
    	    cout << sgt.query(l,r,0,0,n-1) << '\n';	
    	}
    	
    }
}
