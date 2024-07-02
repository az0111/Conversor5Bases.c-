#include <iostream>
#include <string> 
#include <algorithm>//Biblioteca para enverter  transformação do número binário
#include <cmath>//Biblioteca para usar a função pow

   using namespace std;

    //Criação de uma função denomidada Binario, que recebe como argumento um número inteiro
     string decimalToBinario(int n){
         //O valor será armazeado na string r
         string r ;
         while(n!=0){
             //Aqui o simbolo ?(interrogação), exerce o palpel de um operador condicional(operador ternário)
            r+=(n%2 ==0 ? "0" : "1");
            n/=2;
         }
         //Aplicamos a função reverse para inverter a string r, da biblioteca <algorithm>
         reverse(r.begin(), r.end()); 

    //Retornando o valor final da string r
    return r;
     }


    //Função transforma um número decimal em octal, na base 8
    int decimalToOctal(int n) {
    int i = 1,a; 
    int octal = 0;
    //Verifica se o número é menor que 8
    if(n<=7) {
        octal=n;
    }

    //Se não então a conversão começa
    else {
        while(n>=8) {
            a=n%8;
            n=n/8;
            //calculo do octal, não sendo preciso usar o "revese"
            octal = octal + a * i; 
            //aumento do fator de base 10, incrementando ele e colocando ele na posição certa
            i *= 10; 
        }
            //Pegamos o valor da divisão menor que 8 e colocamos na posição certa, assim não perdendo nenhum valor na conversão.
            n=n%8;
            octal = octal + n * i; 
    }

    //No momento do 'n' ser menor que 8, será retornado o valor final.
    return octal;
}

    //Atura no maxímo até 7FFFFFFF, com o valor máximo de um inteiro sendo 2147483647.
    int hexadecimalToDecimal(string hexadecimal) {
    int decimal = 0;
    int tamanho = hexadecimal.size();

    for (int i = 0; i < tamanho; ++i) {
        char caracter = hexadecimal[i];

        // Se o caractere for um dígito de 0 a 9
        if (caracter >= '0' && caracter <= '9') {
            decimal += (caracter - '0') * pow(16, tamanho - i - 1);
        }
        // Se o caractere for uma letra de A a F (maiúscula)
        else if (caracter >= 'A' && caracter <= 'F') {
            decimal += (caracter - 'A' + 10) * pow(16, tamanho - i - 1);
        }
        // Se o caractere for uma letra de a a f (minúscula)
        else if (caracter >= 'a' && caracter <= 'f') {
            decimal += (caracter - 'a' + 10) * pow(16, tamanho - i - 1);
        }
        else {
            // Caractere inválido
            return -1;
        }
    }

    return decimal;
}
     //Função criada para transformar um número decimal em um número na base 5
    int decimalToQuinto(int n) {
    int i = 1,a; 
    int quin = 0;

    if(n<=5) {
        quin=n;
    }
    else {
        while(n>=5) {
            a=n%5;
            n=n/5;
            //Calculo que isenta da obirgação de usar o "reverse"
            quin = quin + a * i; 
            //aumento do fator de base 10, para obtenção do número com os valores na posição certa
            i *= 10; 
        }
            //Adição do valor inferior a 5, em "quin", o qual será o retorno
            n=n%5;
            quin  = quin + n * i;
}
    //Retorno do valor final, quando o número for menor que 5
    return quin;
}

    //Função que transforma um número na base 8 em decimal
    int OctalToDecimal(string num){
      int power=0;
      int decimal=0;
       //A função length() retorna o tamanho da string num
       for(int i =num.size()- 1;i>=0; --i ){
           //Ao se fazer a subtração do número por uma string '0', o num se transforma em uma string. Com a variavel digite assumindo o valor do vetor de tamanho 'i', sendo igual ao tamanho da string
           int digite = num[i]-'0';
           //começa-se com o primeiro número tido no indice 0
           decimal+= digite *pow(8, power);
           //Aumento do expoente
           ++power;
 }

       return decimal;
}
    //Função que transforma um número na base 5 em decimal
    int QuintoToDecimal(string num){
      int power=0;
      int decimal=0;
       //Função que mede o comprimento do números, para ver quantos caracteres tem. 
       for(int i =num.size()- 1;i>=0; --i ){
              //é salvando cada um em um índece determinado, -1 a causa do índice 0
              int digite=num[i]-'0';
              decimal+= digite *pow(5, power);

           ++power;

       }

       return decimal;

   }
    //Função que transforma números na base decimal para a base hexadecimal.
    string decimalToHexa(int decimal) {
        string hexadecimal = "";
            while (decimal > 0) {
            int resto = decimal % 16;
            char digitoHex = (resto < 10) ? ('0' + resto) : ('A' + resto - 10);
            hexadecimal = digitoHex + hexadecimal;
            decimal /= 16;
    }
    return hexadecimal;
}
     int main(){
        int numero,op1,op2;

         cout<<"Informe o tipo da base do número:(1)-Decimal, (2)-Binário, (3)-Hexadecimal,(4)-octal,(5)-Cinco "<<endl;
         cin>>op1;

         while (op1>5 || op1<1){
             cout<<"Informe o tipo da base do número:(1)-Decimal, (2)-Binário, (3)-Hexadecimal,(4)-octal,(5)-Cinco "<<endl;
             cin>>op1;
         }   
         if(op1==1){
             cout<<"Informe o número:"<<endl;
             cin>>numero;
           cout<<"Informe o tipo de conversão de base:(1)-Binário,(2)-Hexadecimal,(3)-octal,(4)-Cinco"<<endl;
           cin>>op2;
             while (op2>4 || op2<1){
                 cout<<"Informe o tipo de conversão de base:(1)-Binário,(2)-Hexadecimal,(3)-octal,(4)-Cinco"<<endl;
                 cin>>op2;
              }   
            if(op2==1){
              //O programa vai até no maximo "999999999" da base decimal para Binário e Hexadecimal.(nove noves)
              cout<<"conversão do número:"<<numero<<endl;
              //usando a função binario para converter o numero decimal em binario
              cout<<"Para binario:"<<decimalToBinario(numero)<<endl;

          }
         else if(op2==2){

             cout<<"conversão do número:"<<numero<<endl;
             cout<<"conversão:"<<decimalToHexa(numero)<<endl;

         }
         else if(op2==3){
             //Maxímo de Decimal para Octal 199999999 (1 e oito noves)
             cout<<"conversão do número:"<<numero<<endl;
             //Usando tal função transforma-se o número decimal a base 8
             cout<<"conversão:"<<decimalToOctal(numero);
         }

         else if (op2==4){
             //De decimal até a base 5, 3999999 (3 e seis 9)
             cout<<"conversão do número:"<<numero<<endl;
             //Usando a função quinti, transforma-se o número decimal a base 5
             cout<<"conversão:"<<decimalToQuinto(numero);
         }
         }

         if(op1==2){

             cout<<"Informe o tipo de conversão de base:(1)-Decimal,(2)-Hexadecimal,(3)-octal,(4)-Cinco"<<endl;
             cin>>op2;

          while (op2>4 || op2<1){
             cout<<"Informe o tipo de conversão de base:(1)-Decimal,(2)-Hexadecimal,(3)-octal,(4)-Cinco"<<endl;
             cin>>op2;
                } 


          string numero;
            cout<<"Informe o número:"<<endl;
            cin>>numero;
            //tam recebe o tamanho do número, para que seja possível percorrer todos os digitos do número
            int tam = numero.length();
                //novoValor inicializado a 0, armazenara o valor da conversão
                int novoValor = 0;
                   //Função que transforma binário para decimal, percorre todos os digitos do número, e faz a conversão de cada um deles
                    for (int i = tam - 1; i >= 0; i--) {
                     if (numero[i] == '1') {
                        //Armazenamento do digito convertido na variavel novoValor
                        novoValor += pow(2, tam - 1 - i);
                      }
                      }
            if(op2==1){


             cout<<"conversão do número:"<<numero<<endl;
             cout<<"conversão:"<<novoValor;
            }    
             else if(op2==2){ 

             //Do binario para o hexadecimal vai ate 30 números '1'
             cout<<"conversão do número:"<<numero<<endl;
             cout<<"conversão:"<<decimalToHexa(novoValor); 
               } 
              else if(op2==3){

                  cout<<"conversão do número:"<<numero<<endl;
                  //oct, uma manipulação da exibição dos números nesse caso de binário para octal
                  cout<<"conversão:"<<decimalToOctal(novoValor);
              } 

              else if(op2==4){

                cout<<"conversão do número:"<<numero<<endl;
                cout<<"conversão:"<<decimalToQuinto(novoValor);
              }
            }

        if(op1==3){
             string hex;

             cout<<"Informe o tipo de conversão de base:(1)-Decimal,(2)-Binário,(3)-octal,(4)-Cinco"<<endl;
             cin>>op2;

             while(op2>4 || op2<1){
                 cout<<"Informe o tipo de conversão de base:(1)-Decimal,(2)-Binário,(3)-octal,(4)-Cinco"<<endl;
                 cin>>op2;
             }
                cout << "Informe o número hexadecimal: ";
                cin >> hex;
            if(op2==1){
               //Atura no maxímo até 7FFFFFFF, com  o valor máximo de um inteiro sendo "2147483647", e o valor máximo(7 e sete f)
               cout << "A conversão do número " << hex<<endl;
               cout<< " em decimal é: " << hexadecimalToDecimal(hex)<< endl;
           }
           else if(op2==2){
               cout << "A conversão do número " << hex<<endl;
               //Para uma abordagem mais simples, fez-se a conversão primeiramente do número em decimal usando assim duas funções uma vez só
               cout << "O número binário equivalente é: " << decimalToBinario(hexadecimalToDecimal(hex)) << endl;

           }
          else if(op2==3) {


             cout << "A conversão do número " << hex<<endl;  
             cout << "O número decimal equivalente é: " << decimalToOctal(hexadecimalToDecimal(hex)) << endl;


         }
         else if(op2==4) {


            cout << "A conversão do número " << hex<<endl;
            cout << "O número decimal equivalente é: " <<decimalToQuinto(hexadecimalToDecimal(hex)) << endl;


         }
         }

         if (op1==4){
               string numer;
                cout<<"Informe o tipo de conversão de base:(1)-Decimal,(2)-Binário,(3)-Hexadecimal,(4)-Cinco"<<endl;
                cin>>op2;
               while(op2>4 || op2<1){
                   cout<<"Informe o tipo de conversão de base:(1)-Decimal,(2)-Binário,(3)-Hexadecimal,(4)-Cinco"<<endl;
                   cin>>op2;

               }

                cout << "Informe o número na base 8: ";
                cin >> numer;
                //octal para decimal
                if(op2==1){
                   cout << "A conversão do número " <<numer<<endl;
                   cout << "O número decimal equivalente é: " <<OctalToDecimal(numer) << endl;
             } 
             else if(op2==2){

                 cout << "A conversão do número " <<numer<<endl;

                 cout<<"O numero em binario é:"<<decimalToBinario(OctalToDecimal(numer));

             }
             else if(op2==3){
                 cout << "A conversão do número " <<numer<<endl;
                 cout<<"O numero em hexadecimal é:"<<decimalToHexa(OctalToDecimal(numer));

             }
             else if(op2==4){
                 cout << "A conversão do número " <<numer<<endl;
                 cout<<"O numero na base 5 é:"<<decimalToQuinto(OctalToDecimal(numer));

             }
           }
         if(op1==5){
               string num;
               //Base cinco
               cout<<"Informe o tipo de conversão de base:(1)-Decimal,(2)- "
               << "Binário,(3)-Hexadecimal,(4)-octal"<<endl;
               cin>>op2;
               while(op2>4 || op2<1){
                  cout<<"Informe o tipo de conversão de base:(1)-Decimal,(2)- "
                 << "Binário,(3)-Hexadecimal,(4)-octal"<<endl;
                 cin>>op2;
               }
               cout<<"informe o número:"<<endl;
               cin>>numero;
               if(op2==1){

                   cout << "A conversão do número " <<num<<endl;
                   cout<<"O numero na base 5 é:"<<QuintoToDecimal(num);

               }
               if(op2==2){
                   cout << "A conversão do número " <<num<<endl;
                   cout<<"O numero na base 5 é:"<<decimalToBinario(QuintoToDecimal(num));
               }
               if(op2==3){
                   cout << "A conversão do número " <<num<<endl;
                   cout<<"O numero na base 5 é:"<<decimalToHexa(QuintoToDecimal(num));
               }
              if(op2==4){
                  cout << "A conversão do número " <<num<<endl;
                  cout<<"O numero na base 5 é:"<<decimalToOctal(QuintoToDecimal(num));
              }

           }
    return 0;
}
       