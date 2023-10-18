#include <stdio.h>

// Hello World
int main() {
    printf("Hello World!");
    return 0;
}

// 四則演算
#include <stdio.h>
int main(void){
    int a = 2;
    int b = 3;
    
    int plus = a + b;
    int minus = a - b;
    int times = a * b;
    double divide = (double)a / b; // 結果を小数で得られるようにdouble型でcast
    
    return 0;
}

// ポインタ
#include <stdio.h>
int main(void){
    int a=3;
    printf("aの値は%dです。\n", a);
    
    // 変数の前に「&」を付けるとアドレスを取得できる。
    printf("aのアドレス(&a)は%pです。\n", &a);
    
    // アドレスの前に「*」を付けると、そのアドレスにある値を取得できる。
    printf("&aの値は%dです。\n", *&a);

    // ポインタ型変数（int型）の利用
    int* a_ptr;
    /*
    int *a_ptr;  // こちらは紛らわしいので使わない
    */
    a_ptr = &a;                                   // アドレスをポインタ型変数に代入
    printf("a_ptrのアドレスは%pです。\n", a_ptr);   // ポインタ型変数のアドレスを表示
    printf("a_ptrの値は%dです。\n", *a_ptr);       // ポインタ型変数のアドレスが指す場所にある値を表示
    
    *a_ptr = 5;                                   // ポインタ型変数を「通常変数モード」にして値を代入
    printf("a_ptrのアドレスは%pです。\n", a_ptr);   // ポインタ型変数のアドレスを表示
    printf("a_ptrの値は%dです。\n", *a_ptr);       // ポインタ型変数のアドレスが指す場所にある値を表示

    return 0;
}

// 構造体
#include <stdio.h>
struct employee {   /* タグ名：社員型 */
    int id;         /* 整数型のメンバ変数：社員番号 */
    char* name;     /* 文字列型（char型のポインタ）のメンバ変数：社員名 */
};

int main(void){
    struct employee emp;
    emp.id = 1;
    emp.name = "Sato";
    
    printf("社員番号%dの社員名は%sです。", emp.id, emp.name);
}

// 関数
#include <stdio.h>
int test(void) {
    printf("This is test.");
    return 0;
}

int main(void){
    test();
    return 0;
}

// 配列
#include <stdio.h>
int main(void){
    // 配列の宣言のみ
    int int_ary[3];
    
    int_ary[0] = 1;
    int_ary[1] = 3;
    int_ary[2] = 5;
    
    printf("0番目の要素は%dです。\n", int_ary[0]);
    printf("1番目の要素は%dです。\n", int_ary[1]);
    printf("2番目の要素は%dです。\n", int_ary[2]);
}

// if文
#include <stdio.h>
int main(void) {
    int seisu;
    printf("何か整数を入力して下さい--->¥n");
    scanf("%d", &seisu);

    if (seisu % 2 == 0 && seisu % 3 == 0) 
        printf("入力された倍数は2の倍数でかつ3の倍数です¥n");
    else if (seisu % 2 == 0 || seisu % 3 == 0)
        printf("入力された倍数は2の倍数でまたは3の倍数です¥n");
    else
        printf("入力された倍数は2の倍数でも3の倍数でもありません¥n");
}

// for文
#include <stdio.h>
int main(void){
    for (int i=0; i<5; i++) {
        printf("%d回目のループです。\n", i+1);
    }
}

// While文
#include <stdio.h>
int main(void){
    int num = 50;
    int i = 1;
    printf("数値=%dの約数を求めます\n", num);

    while (i <= num) {
        if (num % i == 0){
            printf("約数=%d\n", i);
        }
        i++;
    }
    return 0;
}

// 2次元配列
#include <stdio.h>
int main(void){
    // 3行2列の2次元配列の宣言
    int ary2D [3][2];
    
    ary2D[0][0] = 0;
    ary2D[0][1] = 1;
    ary2D[1][0] = 1;
    ary2D[1][1] = 2;
    ary2D[2][0] = 3;
    ary2D[2][1] = 5;
    
    int rowCount = 3;   // 行数
    int colCount = 2;   // 列数
    
    for (int i=0; i<rowCount; i++) {
        for (int j=0; j<colCount; j++) {
            printf("%d行目の%d列目の値は%dです。\n", i+1, j+1, ary2D[i][j]);    
        }
    }
}

// 関数のプロトタイプ宣言
#include <stdio.h>

// 関数のプロトタイプ宣言
void test(void);

int main(void){
    test();
    return 0;
}

// test関数の呼び出し箇所より後ろでtest関数を宣言できる！
void test(void) {
    printf("This is test.");
}

// 構造体配列
#include <stdio.h>

// 構造体：社員型
typedef struct employee {
    int id;             // 社員番号
    const char* name;   // 社員名
    char* deptName;     // 部署名
} Employee;

int main(void){
    // 社員リストの作成
    Employee empList[3];

    empList[0].id = 1;
    empList[0].name = "Sato";
    empList[0].deptName = "Sales";

    empList[1].id = 2;
    empList[1].name = "Suzuki";
    empList[1].deptName = "Development";
    
    empList[2].id = 3;
    empList[2].name = "Takahashi";
    empList[2].deptName = "Sales";
    
    // 社員リストの表示
    int arySize = sizeof(empList) / sizeof(Employee);
    
    for (int i=0; i<arySize; i++) {
        printf("社員番号：%d、社員名：%s、部署名：%s\n",
            empList[i].id,
            empList[i].name,
            empList[i].deptName);
    }
    return 0;
}