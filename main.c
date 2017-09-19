
unsigned char* operation(unsigned char* text){
 int i,j;
 int len = strlen(text);
 for (i = 0; i < len; i++) {
  if (text[i] < '0' || text[i] > '9'){
    unsigned char sign = text[i];
    int firstI;
    int secondI;
    unsigned char buff[50];

    unsigned char first[15];
    unsigned char second[15];
    for (j=0; j<i; j++){
     first[j] = text[j];
    }
     first[i] = '\0';

    for (j=i+1; j<=len; j++){
     second[j-i-1] = text[j];

    firstI = atoi(first);
    secondI = atoi(second);

    switch (sign){

    case '+' :
        {
          itoa(firstI + secondI, buff, 10);
          return  buff;
        }

    case '-' :
        {
          itoa(firstI - secondI, buff, 10);
          return  buff;
        }

     case '*' :
        {
           itoa(firstI * secondI, buff, 10);
           return  buff;
        }

    case '/' :
        {
           itoa(firstI / secondI, buff, 10);
           return  buff;
        }

    default :
        {
           return "Sign does not exist!";
        }
    }

}
