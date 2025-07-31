//Qlink : https://cses.fi/problemset/task/1648/

#include<bits/stdc++.h>
using namespace std;
#define int long long
// parent i has left child 2i+1 and right child 2i+2
// Segment tree is Balanced Binary Tree i.e., height difference at most 1 btw left and right subtree

class SegTree{
private:
	vector<int> sgt,arr;
    int n;
public:
	// SegTree contructor
	SegTree(vector<int> arr){
        this->arr=arr;
        n=arr.size();
        sgt.resize(4*n);
        build(0,0,n-1);
	}

	void build(int i,int l,int r){
		if(l==r){
			// leaf node reached
			sgt[i]=arr[l];
			return;
		}
		int mid=(l+r)/2;
		build(2*i+1, l ,mid);
		build(2*i+2, mid+1, r);

		sgt[i]=sgt[2*i+1] + sgt[2*i+2];
	}

	void update(int i,int val,int j,int l,int r){
		if(l==r){
			sgt[j]=val;
			arr[i]=val;
			return;
		}
        int mid=(l+r)/2;
		if(i<=mid){
			// i in left
			update(i,val,2*j+1,l,mid);
		}
		else{
			//i in right
			update(i,val,2*j+2,mid+1,r);
		}
		sgt[j] = sgt[2*j+1] + sgt[2*j+2];
	}

	int query(int start,int end,int i,int l,int r){
		if(r<start || l>end){
			return 0; // out of bound
		}
		else if(l>=start && r<=end){
			return sgt[i]; // range contained
		}
		else{
			int mid=(l+r)/2; // contribution in both left and right so find from left and right
			return query(start,end,2*i+1,l,mid) + query(start,end,2*i+2,mid+1,r);
		}
	}
	// TC:
	// build -> O(n), update->O(logn), query-> O(logn)
};

signed main(){
	int n,q;cin >> n >> q;
	vector<int> nums(n);
	for(auto &x : nums) cin >> x;

	SegTree sgt(nums);

    while(q--){
    	int type;cin >> type;
    	if(type==1){
    		int pos,val;cin >> pos>> val;
    		pos--; // 1based to 0base
            sgt.update(pos,val,0,0,n-1);
    	}
    	else{
    		int start,end;cin >> start >> end;
    		start--;end--; // 1based to 0base
            cout << sgt.query(start,end,0,0,n-1) << '\n';
    	}
    }
}
