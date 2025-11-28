void solucao(int m, int n, int M[m][n])
{   // solucao meio errada
    if (M[0][0]%4==0) return;
    for (int i=0 ; i<m ; i++) {
        for (int j=0 ; j<n/2 ; j++) {
            int x = M[i][j];
            M[i][j] = M[i][n-1-j];
            M[i][n-1-j] = x;
        }
    }
}