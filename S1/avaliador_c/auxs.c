int randint(int low, int high) {
    return low + rand()%(high-low);
}

int number_of_digits(int n) {
    if (n==0) return 1;
    int c = 0;
    if (n<0) c++;
    while (n) {
        c++;
        n/=10;
    }
    return c;
}

void show_matrix(int m, int n, int M[m][n]) {
    int max_digits = 0;
    
    // Calcula a quantidade máxima de dígitos
    for (int i=0 ; i<m ; i++) {
        for (int j=0 ; j<n ; j++) {
            int curr_digits = number_of_digits(M[i][j]);
            if (curr_digits>max_digits) {
                max_digits = curr_digits; 
            }
        }
    }
    
    // Imprime linha-a-linha
    for (int i=0 ; i<m ; i++) {
        // Imprime o começo
        printf("[ ");
        // Imprime as entradas
        for (int j=0 ; j<n ; j++) {
            // Imprime os espaços à esquerda
            for (int p=0 ; p<max_digits-number_of_digits(M[i][j]); p++)
                printf(" ");
            // Imprime o número e um espaço;
            printf("%d ", M[i][j]);
        }
        // Fecha a linha
        printf("]\n");
    }
}

unsigned long long pot(unsigned long long m, unsigned long long k) {
    if (!k) return 1;
    if (k%2) return (pot(m,k/2)*pot(m,k/2)*m);
    return pot(m,k/2)*pot(m,k/2);
}