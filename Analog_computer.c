    #include <stdio.h>
    #include <stdlib.h>

    #define MAX 100

    int Input_equation(int figure[],char symbol[]); //  输入算式
    int Compute_two_figure(int a,int b,char symbol);    //  对两个数字进行运算
    int Compute_equation(int figure[],char symbol[]);   //  计算算式并返回结果
    int main()
    {
        int figure[MAX] = {0};
        char symbol[MAX] = {0};
        int result = 0;
        if(Input_equation(figure, symbol)){
            result = Compute_equation(figure, symbol);
            printf("%d",result);
        }
        return 0;
    }

    int Input_equation(int figure[],char symbol[]){
       int figure_num = 0;
       int symbol_num = 0;
       int figure_input = 0;
       char symbol_input = 0;
       while(1){
            if(scanf("%d",&figure_input) == 1){
                figure[figure_num] = figure_input;
                figure_num++;
            }else{
                char wrong_symbol = getchar();
                printf("错误的运算符:%c",wrong_symbol);
                return 0;
            }

            if(scanf("%c",&symbol_input) == 1){
                if(symbol_input == '='){
                    symbol[symbol_num] = symbol_input;
                    return 1;
                }else if(symbol_input == '+'||symbol_input == '-'||symbol_input == '*'||symbol_input == '/'){
                    symbol[symbol_num] = symbol_input;
                    symbol_num++;
                }else{
                    printf("错误的运算符:%c",symbol_input);
                    return 0;
                }
            }else{
                printf("Input error!");
                exit(0);
            }
       }
    }

    int Compute_two_figure(int a,int b,char symbol){
        int result = 0;
        switch(symbol){
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
        }
        return result;
    }


    int Compute_equation(int figure[],char symbol[]){
        int index = 0;
        int result = 0;
        result = figure[index];
        while(symbol[index] != '='){
            index++;
            result = Compute_two_figure(result, figure[index], symbol[index-1]);
        }
        return result;
    }