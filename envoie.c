if((x!=x2+1 && x!=x2-1 && x!= x2) || (y!=y2+1 && y!=y2-1 && y!= y2)||(x==x2+1 && y==y2+1)||(x==x2-1 && y==y2+1)||(x==x2+1 && y==y2-1)||(x==x2-1 && y==y2-1)){
            printf("Try again to switch caracter's places in 3 secondes.\n");
        sleep(3);
        }
        } while ((x!=x2+1 && x!=x2-1 && x!= x2) || (y!=y2+1 && y!=y2-1 && y!= y2)||(x==x2+1 && y==y2+1)||(x==x2-1 && y==y2+1)||(x==x2+1 && y==y2-1)||(x==x2-1 && y==y2-1));

