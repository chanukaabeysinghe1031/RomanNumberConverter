#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int one_integer_number(char arr[10]){
    int i=0;
    int number;
    if(arr[0]=='A'){
     number = 0;
    }else if(arr[0]=='I' && arr[1]=='A'){
        number=1;
    }else if(arr[0]=='I' && arr[1]=='I' && arr[2]=='A'){
        number=2;
    }else if(arr[0]=='I' && arr[1]=='I' && arr[2]=='I' && arr[3]=='A'){
        number=3;
    }else if(arr[0]=='I' && arr[1]=='V' && arr[2]=='A'){
        number=4;
    }else if(arr[0]=='V' && arr[1]=='A'){
        number=5;
    }else if(arr[0]=='V' && arr[1]=='I' && arr[2]=='A'){
        number=6;
    }else if(arr[0]=='V' && arr[1]=='I' && arr[2]=='I' && arr[3]=='A'){
        number=7;
    }else if(arr[0]=='V' && arr[1]=='I' && arr[2]=='I' && arr[3]=='I' && arr[4]=='A'){
        number=8;
    }else if(arr[0]=='I' && arr[1]=='X' && arr[2]=='A'){
        number=9;
    }else{
        number = -1;
    }

    return number;
}

void convert_roman(char arr[10]){
    int result;
    bool is_error=true;

    if(!(one_integer_number(arr)==-1)){
        //if number is 1 to 9
        cout<<one_integer_number(arr);
        is_error=false;
    }else if(arr[0]=='X'&&arr[1]!='L'&& arr[1]!='C'){
        //if number is 10-39
        int count=0;
        while(arr[count]=='X'){
            if(arr[count]!='X'){
                break;
            }else{
                count++;
            }
        }

        if(count>3){
            is_error = true;
        }else{
            char arr2[10];
            int count_of_10_digits = count;
            int count2=0;
            while(arr[count] != 'A'){
                arr2[count2]=arr[count];
                count++;
                count2++;
            }
            arr2[count2]='A';

            result = one_integer_number(arr2);
            if( result!= -1){
                result = result + 10*count_of_10_digits;
                cout<<result;
                is_error=false;
            }else{
                is_error= true;
            }
        }
    }else if(arr[0]=='X' && arr[1]=='L'){
        //if number is between 40-49
        char arr2[10];
        int count=2;
        int i=0;
        while(arr[count]!='A'){
            arr2[i] =arr[count];
            count++;i++;
        }

        arr2[i] = 'A';
        result = one_integer_number(arr2);
        if(result!=-1){
            cout<<40+result;
            is_error= false;
        }else{
            is_error=true;
        }

    }else if(arr[0]=='L'){
        //if number is 50-89
        int count=1;
        while(arr[count]=='X'){
            if(arr[count]!='X'){
                break;
            }else{
                count++;
            }
        }

        if(count>4){
            is_error=true;
        }else{
            char arr2[10];
            int count_of_10_digits = count;
            int count2=0;
            while(arr[count] != 'A'){
                arr2[count2]=arr[count];
                count++;
                count2++;
            }
            arr2[count2]='A';

            result = one_integer_number(arr2);
            if( result!= -1){
                result = 50+result + 10*(count_of_10_digits-1);
                cout<<result;
                is_error= false;
            }else{
                is_error=true;
            }
        }
    }else if(arr[0]=='X' && arr[1]=='C'){
        char arr2[10];
        int count=2;
        int i=0;
        while(arr[count]!='A'){
            arr2[i] =arr[count];
            count++;i++;
        }

        arr2[i] = 'A';
        result = one_integer_number(arr2);
        if(result!=-1){
            cout<<90+result;
            is_error= false;
        }else{
            is_error=true;
        }

    }

    if(is_error)cout<<"Error";
    cout<<endl;
}
int main() {

    char arr[10] = {'X','C','V','I','I','A'};
    char arr2[10];
    fstream newfile;
    int length;
    string tp;

    newfile.open("/Users/chanukaabeysinghe/CLionProjects/RomanHinduConverter/numbers",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            length = tp.length();
            strcpy(arr2, tp.c_str());
            char arr3[length+1];
            for(int i=0;i<length;i++){
                arr3[i]=arr2[i];
            }
            arr3[length]='A';
            cout<<tp<<" : ";
            convert_roman(arr3);

        }
        newfile.close(); //close the file object.
    }else{
        cout<<"Not Open";
    }


    return 0;
}
