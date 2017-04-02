long long res = x % 10;
while(x /= 10) res = res*10 + x%10;
return (res<INT_MIN || res>INT_MAX) ? 0 : res;
