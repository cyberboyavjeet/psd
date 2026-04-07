 #include<stdio.h>
 void main()
 {
    int A,B[2],C,D,E;
    A=1;
    C=1;
    D=1;
    E=1;
    B[1]=2;
    B[2]=2;
    B[3]=2;
    B[4]=2;
    printf("%d%d%d%d",A,C,D,E);
    printf("\n");
   printf("%u\t%u\t%u",&A,&D,&E);
   printf("\n");
    printf("%u\t%u\t%u",&B[1],&B[2],&B[3],B[4]);

 }