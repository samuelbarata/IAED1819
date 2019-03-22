#include <stdio.h>
#define ALUNOS 10
#define DISCIPLINAS 5

int max(int valores[]){
    int i,max=0,k=0;
    for(i=0;i<ALUNOS;i++){
        if(valores[i]>max){max=valores[i];k=i}
    }
    return k;
}


long score_disciplinas(int disciplina, int valores[][]){

}

long score_aluno(int aluno, int valores[][]){
    int i, int som = 0;
    for(i=0;i<DISCIPLINAS;i++){
        som += valores[aluno][i];
    }
    return som
}

int main(){
    int valores[ALUNOS][DISCIPLINAS], N,maxim=0 ,i,k,a,d,v, scores_a[ALUNOS], score_d[DISCIPLINAS];
    scanf("%d", &N);
    for(i=0; i<ALUNOS; i++){
        for(k=0; k<DISCIPLINAS; k++){
            valores[i][k]=0;
        }
    }
    for(i = 0; i < N; i++){
        scanf("%d %d %d", &a, &d, &v);
        valores[a][d] = v;
    }
    /*score alunos*/
    for(i=0; i<N; i++){
        scores_a[i] = score_aluno(i, valores[][]);
    }
    maxim = max(scores_a);
    printf("%s", valores[maxim])
    
    /*score disciplinas*/
    
    return 0;
}