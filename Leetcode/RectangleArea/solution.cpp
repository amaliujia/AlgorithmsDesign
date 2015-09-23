class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
      int area1 = (D-B) * (C-A);
      int area2 = (H-F) * (G-E);

      if(G <= A || C <= E || B >= H || D <= F){
        return area1 + area2;
      }

      int width =  (A<=E)?min(C-E,G-E):min(C-A,G-A);
      int height = (B>=F)?min(D-B,H-B):min(D-F,H-F);

      return area1 + area2 - width * height; 
    }
};
