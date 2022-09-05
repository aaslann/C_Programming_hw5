#include <stdio.h>
void read_file(char *line,char *file_name);

int write_file(char *file_name,char *string,int op_prynths,int cls_prynths,int flag);

void clear_file(char *file_name);


int main(){
    char line[250];
    read_file(line,"input.txt");
    clear_file("output.txt");
    write_file("output.txt",line,0,0,1);
    return 0;
}
void read_file(char *line,char *file_name){
    char ch;
    int index =0;
    FILE *fp = fopen(file_name,"r");
    fscanf(fp,"%c",&ch);
    if(ch == ' '){
        while(ch == ' '){
            fscanf(fp,"%c",&ch);
        }
    }
    line[index] = ch;
    index++;
    while(!feof(fp)){
        fscanf(fp,"%c",&ch);
        line[index] = ch;
        index++;
    }
    line[index-1] = '\0';
    fclose(fp);
}
/*  This function writes file each charachter of the string.If the character is ','
    i call it with flag 1 to write to '-',otherwise it call with flag 0
    if the characther  is '\0' ,  function is finish    */
int write_file(char *file_name,char *string,int op_prynths,int cls_prynths,int flag){
    FILE *fp = fopen(file_name,"a+");
    if(*string == '\0'){
        fclose(fp);
        return 0;
    }
    if(*string == ','){
        fprintf(fp,"\n");
        fclose(fp);
        write_file(file_name,string+1,op_prynths,cls_prynths,1);
        return 0;        
    }
    if(flag == 1){
        if(*string == '('){
            fclose(fp);
            write_file(file_name,string+1,op_prynths+1,cls_prynths,1);
            return 0;
            
        }
        else if(*string == ')'){
            fclose(fp);
            write_file(file_name,string+1,op_prynths,cls_prynths+1,1);
            return 0;
        }
        else{
            for(int i=0;i<op_prynths-cls_prynths;i++){
                fprintf(fp,"-");
            }
            fprintf(fp,"%c",*string);
            fclose(fp);
            write_file(file_name,string+1,op_prynths,cls_prynths,0);    
            return 0;        
        }
    }
    else{
        if(*string == '('){
            fclose(fp);
            write_file(file_name,string+1,op_prynths+1,cls_prynths,0);
            return 0;
        }
        else if(*string == ')'){
            fclose(fp);
            write_file(file_name,string+1,op_prynths,cls_prynths+1,0);
            return 0;
        }
        else{
            fprintf(fp,"%c",*string);
            fclose(fp);
            write_file(file_name,string+1,op_prynths,cls_prynths,0);  
            return 0;          
        }
    }
}
void clear_file(char *file_name){

    FILE *fp = fopen(file_name,"w");
    fclose(fp);

}