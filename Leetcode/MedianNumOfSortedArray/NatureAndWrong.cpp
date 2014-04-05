ass Solution {
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
															    }else if(a.second < b.second){
																	        if((int)(a.first * 10) % 10 != 0){
																				            a.first = ceil(a.first);
																							        }
																			        if((int)(b.first * 10) % 10 != 0){
																						            b.first = floor(b.first);
																									        }
																					        return recursiveFinding(A, a.first, rightA, B, leftB, b.first);
																							    }else{
																									        if((int)(a.first * 10) % 10 != 0){
																												            a.first = floor(a.first);
																															        }
																											        if((int)(b.first * 10) % 10 != 0){
																														            b.first = ceil(b.first);
																																	        }
																													        return recursiveFinding(B, b.first, rightB, A, leftA, a.first);
																															    }
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
															        b = a + 1;
																	        result = make_pair((a + b) / 2.0,(C[a] + C[b]) / 2.0);
																			        return result;
																					    }else{
																							        a = (right + left) / 2;
																									        result = make_pair(a, C[a]);
																											        return result;
																													    }
		}
};
