class Solution {
	public:
		double findMedianSortedArrays(int A[], int m, int B[], int n) {
		    if(n != 0 && m != 0){
				 return recursiveFinding(A, 0, m-1, B, 0, n-1);
		    }else if(m != 0 && n == 0){
				return findMedian(A, 0, m-1).second;
			}else if (m == 0 && n != 0){
				return findMedian(B, 0, n-1).second;
			}else{
				return 0;
			}
		}

		double recursiveFinding(int A[], int leftA, int rightA, int B[], int leftB, int rightB)
		{
			pair<double,double> a, b;
			if(rightB < leftB){
				return findMedian(A, leftA, rightA).second;
			}else if(rightA < leftA){
				return findMedian(B, leftB, rightB).second;
			}
					    
			a = findMedian(A, leftA, rightA);
			b = findMedian(B, leftB, rightB);
			if(a.second == b.second){
				return a.second;
			}else if((a.first == rightA && b.first == leftB) || (b.first == rightB && leftA == a.first)){
				return (a.second + b.second) / 2.0;
			return 0;
			}

		pair<double,double> findMedian(int C[], int left, int right)
		{
			pair<double,double> result;
			int a, b;
			if(left == right){
				result = make_pair(left, C[left]);
				return result;
			}else if((right - left + 1) % 2 == 0){
				a = (right + left) / 2;
		}
};
