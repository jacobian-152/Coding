#include<bits/stdc++.h>

using namespace std;


class SegmentTree{
private:
    vector<int> tree;
    int N;
    void buildTree(){
        for(int i=N - 1; i>0;i--){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }
public:
    SegmentTree(){}
    SegmentTree(vector<int> nums){
        N = nums.size();
        tree = vector<int>(N<<1);
        for(int i=0; i<N; i++){
            tree[i+N] = nums[i];
        }
        buildTree();
    }
    
    void updateTree(int pos, int value){
        tree[N+pos] = value;
        
        for(int i=N+pos; i>1;i>>=1){
            if (i&1){
                // if pos is odd
                tree[i>>1] = tree[i] + tree[i-1];
            }else{
                // pos is even
                tree[i>>1] = tree[i] + tree[i+1];
            }
        }
    }
    
    int query(int left, int right){
        int res = 0;
        // half-open interval to closed interval
        for(int l = left+N, r = right-1+N; l<=r; l>>=1, r>>=1){
            if (l&1){
                res+=tree[l++];
            }
            
            if (!(r&1)){
                res+=tree[r--];
            }
        }
        
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6};
    SegmentTree st(nums);
    cout<<st.query(1, 4)<<"\n";
    cout<<st.query(0, 4)<<"\n";
    cout<<st.query(2, 5)<<"\n";
    cout<<st.query(2, 6)<<"\n";
    st.updateTree(3, 14);
    cout<<st.query(1, 4)<<"\n";
    cout<<st.query(0, 4)<<"\n";
    cout<<st.query(2, 5)<<"\n";
    cout<<st.query(2, 6)<<"\n";
    st.updateTree(4, 15);
    cout<<st.query(1, 4)<<"\n";
    cout<<st.query(0, 4)<<"\n";
    cout<<st.query(2, 5)<<"\n";
    cout<<st.query(2, 6)<<"\n";
    return 0;
}
