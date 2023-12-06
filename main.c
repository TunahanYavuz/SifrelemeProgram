#include <stdio.h>
#include <string.h>
#include <ctype.h>

char encryptOperation();
char deEncryptOperation(); //Fonksiyonları tanımlıyoruz

int main() {
    int operation;

    printf("Lutfen Yapmak Istediginiz Operasyonu Secin:\n");
    askAgain:           //Kullanıcının yapmak istediği işlemi soruyoruz.
    printf("1=Sifreleme\n"
           "2=Desifreleme\n"
           "3=Programi Sonlandir\n");
    if(scanf("%d", &operation)!=1){         //Girilen değerin sayı olup olmadığını kontrol ediyoruz.
        printf("Lutfen Sadece Sayi Giriniz\n");
        fflush(stdin);
        goto askAgain;
    }
    switch (operation) {            //Seçilen operasyona göre işlemi yapıyoruz.
        case 1:
            encryptOperation();
            printf("Lutfen Diger Operasyonu Seciniz\n");
            goto askAgain;
        case 2:                     //Her operasyon için kullanıcıya işlemi tekrar soruyoruz. Eğer kullanıcı çıkış yapmak istiyorsa 3 sayısını girmeli.
            deEncryptOperation();
            printf("Lutfen Diger Operasyonu Seciniz\n");
            goto askAgain;
        case 3:
            break;
        default:        //Farklı bir değer girilirse kullanıcıya tekrar soruyoruz.
            printf("Bilinmeyen Bir Islem Girdiniz\n\tLutfen Tekrar Deneyiniz\n");
            goto askAgain;

    }


    return 0;
}



void encrypt(char password[], int scroll){
    unsigned int lenght = strlen(password);  //Dizinin uzunluğunu tuttuğumuz değer.
    char character;
    for (int i = 0; i < lenght; ++i) {           //Şifreleme Operasyonumuz
        if(isalpha(password[i])){                   //isalpha fonksiyonuyla girilen harfin alfabede olup olmadığını kontrol ediyoruz.
            character = islower(password[i])? 'a':'A';         //islower fonksiyonuyla harfin büyük ya da küçük olduğunu kontrol ediyoruz. Eğer küçükse a harfini değilse A harfini character değişkenine atıyoruz.
            password[i]= character+(password[i]-character +scroll%26+26)%26;                     //Önce a harfini çıkarıyoruz sonra öteleme miktarını buluyoruz ve a harfine ekliyoruz.
        }

    }

}
void deEncrypt(char password[],int scrollToBack){
    encrypt(password,-scrollToBack);    //Şifre çözme algoritması da aslında şifreleme algoritmasının sadece kaydırma değerinin negatif hali.
}
char withFile(char text[]){     //Dosyadan okuma veya dosyaya yazma operasyonu.
    FILE *fp;
    char c;
    int i=0,answer;
    printf("Dosya Olusturup Okutmak Icin : 1\nSadece Dosyayi Okutmak Icin : Herhangi Bir Tusa Basin \n");
    scanf("%d",&answer);

    if(answer == 1){                                 //Cevaba göre sadece okuyor veya hem yazıp hem de okuyoruz.
        fp= fopen("input.txt","w");   //Yazma işlemi için dosyayı w(write) şeklinde açıyoruz.
                            //Buradaki dosya adını isteğinize göre değiştirebilirsiniz. Aslında dosya adını da kullanıcıdan alan bir program yazmak istemiştim ama henüz nasıl yapacağımı bilmiyorum.
        if(fp==NULL){
            printf("Dosya Acilamadi\n");        //Dosyanın geçerliliğini kontrol ediyoruz.
            return 0;
        }
        printf("Lutfen Dosyanin Icerigini Giriniz\n");
        gets(text);                         //gets fonksiyonlarıyla metnimizi alıyoruz.
        gets(text);                          //Kullanıcıdan metni alıyoruz.
        fputs(text,fp);         	    //Aldığımız metni dosyaya yazıyoruz.
        fclose(fp);                               //Ve dosyayı kapatıyoruz.
    }
    fflush(stdin);
    fp=fopen("input.txt","r");          //Okuma işlemi için dosyayı r(read) şeklinda açıyoruz.
    if(fp==NULL){
        printf("Dosya Bulunamadi\n");
        return 0;
    }


    while((c= fgetc(fp))!=EOF){  //Dosya bitene kadar her bir harfi text değişkenine atıyoruz.
        text[i]=c;
        ++i;
    }
    fclose(fp);
    return 1;



}
char deEncryptOperation() {
    int i=0,numberOfScroll,answer;
    char getText[1000];
    printf("Islemi Dosya ile Yapacaksaniz 1\nYapmayacaksaniz Herhangi Bir Tusa Basin\n");
    scanf("%d",&answer);
    //Kullanıcının dosyayla mı yoksa normal yolla mı ilem yapacağını soruyoruz.
    if(answer == 1){

        if(!withFile(getText)){ //Dosyayla yapılan işlemde dosya bulunamadıysa sonlandırıyoruz.
            return 0;}
    }
    else {
        printf("Lutfen Kirilacak Sifreyi Girin\nSifrenin Max Uzunlugu 1000 Karakter Olmalidir\n");  //Normal yol için kullanıcıdan metni alıyoruz.
        takePassword:
        gets(getText);              //gets fonksiyonlarıyla metnimizi alıyoruz.
        gets(getText);

        if (strlen(getText) > 1000) {                    //Metin istenen miktardan uzunsa şifreyi tekrar yazdırıyoruz.
            printf("Sifre 1000 Karakterden Buyuk Olamaz\n");
            goto takePassword;
        }
    }
    printf("Lutfen Geri Oteleme Miktarini Giriniz\n");
    takeNumber:
    if (scanf("%d", &numberOfScroll) != 1) { //Öteleme miktarını alıyoruz ve sayı olup olmadığını kontrol ediyoruz.
        fflush(stdin);
        printf("Lutfen Sayi Giriniz\n");
        goto takeNumber;
    }

    deEncrypt(getText, numberOfScroll); //Aldığımız verileri deşifreleme operasyonuna gönderiyoruz.
    printf("Sifresi Cozulen Metin :\n");    //Deşifrelenen metni yazdırıyoruz.
    while(i<= strlen(getText)){
        putchar(getText[i]);
        ++i;
    }
    printf("\n\n");
    return 1;

}

char encryptOperation() {
    char getText[1000];                  //Mesajları ve fonksiyonları şifrelemeye göre uyarlıyoruz.
    int i=0,answer,numberOfScroll;
    printf("Islemi Dosya ile Yapacaksaniz 1\nYapmayacaksaniz Herhangi Bir Tusa Basin\n");
    scanf("%d",&answer);
    if(answer == 1){

        if(!withFile(getText)){
            return 0;}
    }
    if(answer!=1) {
        printf("Lutfen Sifrelenecek Olan Metni Girin\nSifrenin Max Uzunlugu 1000 Karakter Olmalidir\n");
        takePassword:
        gets(getText);
        gets(getText);


        if (strlen(getText) > 1000) {
            printf("Metin 1000 Karakterden Buyuk Olamaz\n");
            fflush(stdin);
            goto takePassword;
        }
    }
    printf("Lutfen Oteleme Miktarini Giriniz\n");
    takeNumber:
    if (scanf("%d", &numberOfScroll) != 1) {
        fflush(stdin);
        printf("Lutfen Sayi Giriniz\n");
        goto takeNumber;
    }

    encrypt(getText, numberOfScroll);
    printf("Sifrelenen Metin :\n");
    while(i< strlen(getText)){
        putchar(getText[i]);
        ++i;
    }
    printf("\n\n");


    return 1;
}
