#include<stdio.h>
#include<math.h>

double tfun(char a, double f);
int sqr(int sq);
int cange(void);

int main(void){
  int b = 1, w = 1, sq;
  double f, s, ans, ans2, k;
  char a, c, d, e, fun;
  /*eはエンター読み取り専用*/
 
  /*平方根*/
  printf("平方根を求めたい場合は's'を、電卓機能を使いたい場合はそれ以外をを入力してください。\n");
  scanf("%c", &fun);
  if(fun == '\n'){
    scanf("%c", &fun);
  }
  if(fun == 's'){
    printf("平方根を求めたい数を整数で入力してください。\n");
    scanf("%d", &sq);
    sqr(sq);
    return 0;
  }
  
  /*電卓*/
  printf("１つめの数を入力してください。三角関数を使用したい場合は使いたい関数の頭文字を入力したい角度の先頭につけて入力してください。\n使わない場合は数の先頭に　n　をつけてください。\n");
  scanf("%1c", &e);
  scanf("%1c", &a);
  scanf("%lf", &f);
  for(;a == '\n';){
    printf("もう一度入力してください。\n");
    scanf("%1c", &a);
    scanf("%lf", &f);
  }
  for(;a != 's' && a != 'c' && a != 't' && a != 'n';){
    printf("s c t n のどれかを入力してください。\n");
    scanf("%1c", &e);
    scanf("%1c", &a);
    scanf("%lf", &f);
  }
  /*一文字目*/
  f = tfun(a, f);
  /*二文字目（繰り返し開始）*/
  for(s = 0 ; b == 1;){
    printf("演算子を入力してください。（+ - * /）\n");
    scanf("%1c", &c);
    for(;c != '+'&& c != '-' && c != '*' && c != '/';){
      printf("+ - * /のどれかを入力してください。\n");
      scanf("%1c", &c);
    }
    
    
    
    /*二文字目（読み取り）*/
    printf("１つ目と同様にして2つ目の数を入力してください。\n");
    scanf("%1c", &e);
    scanf("%1c", &d);
    scanf("%lf", &s);
    for(;d == '\n';){
      printf("qwertyuiop\n");
      scanf("%1c", &d);
      scanf("%lf", &s); 
      scanf("%c", &e);
    }
    for(;d != 's' && d != 'c' && d != 't' && d != 'n';){
      printf("もう一度入力してください。\ns c t n のどれかを入力してください。\n");
      scanf("%1c", &d);
      scanf("%lf", &s);
      scanf("%c", &e);
    }
    
    
    s = tfun(d, s);
    /*演算*/
    switch(c){
      case'+':{
        ans = f + s;
        break;
      }
      case'-':{
        ans = f - s;
        break;
      }
      case'*':{
        ans = f * s;
        break;
      }
      case'/':{
        if(s == 0){
          printf("0で割り算はできません。もう一度始めからやり直してください。\n");
          b = 0;
          w = 0;
          break;
        }
        ans = f / s;
        break;
      }
    }
    if(w != 0){
      printf("%lf %c %lf =%lf\n平方根を求めたい場合は2を\n計算を続ける場合は１を\nやめる場合は０を入力してください。\n", f, c, s, ans);
      scanf("%1d", &b);
      if(b == 1){
        f = ans;
      }
      if(b == 2){
        cange();
      }
    }
  }
  
  
  return 0;
}




/*三角関数処理*/
double tfun(char a, double f){
  switch(a){
    case 's':{
      f = f * M_PI / 180;
      f = sin(f);
      break;
    }
    case'c':{
      f = f * M_PI / 180;
      f = cos(f);
      break;
    }
    case't':{
      f = f * M_PI / 180;
      f = tan(f);
      break;
    }
  }
  return f;
}


/*平方根*/
int sqr(int sq){
  double k;
  int a;
  k = sqrt(sq);
  printf("%dの平方根は%lfです。\n", sq, k);
  printf("電卓を使用したい場合は１を、終了する場合は０を入力してください。\n");
  scanf("%d", &a);
  if(a == 1){
    main();
  }
  return 0;
}


/*メインに乗り換え*/
int cange(void){
  main();
  return 0;
}
