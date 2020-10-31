
    int sub2(int l, int r)  { // [l, r]
        int v = suf2[l] - suf2[r + 1] * b2[r - l + 1];
        v %= MOD;
        v += MOD;
        v %= MOD;
        return v;
    }



    bool check(int value)
    {
      
      if(present(M1,sub(st,st+value-1)))
      {
        return true;
      }

     return false;
    }
    
