#include <stdio.h>
#include <string.h>

char encryptOperation(int gecerleme);
char deEncryptOperation(int gecerleme); //Fonksiyonları tanımlıyoruz

int main() {
    int operation,gecerleme;
    home:
    printf("Readme De Bahsettigim Uzere Derleyicinize Gore Bir Secim Yapiniz\n0\n3\n");
    if(scanf("%d",&gecerleme)!=1&&(gecerleme!=0&&gecerleme!=3)){
        printf("Lutfen Gecerli Bir Sayi Giriniz");
        fflush(stdin);
        goto home;
    }

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
            encryptOperation(gecerleme);
            printf("Lutfen Diger Operasyonu Seciniz\n");
            goto askAgain;
        case 2:                     //Her operasyon için kullanıcıya işlemi tekrar soruyoruz. Eğer kullanıcı çıkış yapmak istiyorsa 3 sayısını girmeli.
            deEncryptOperation(gecerleme);
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

    for (int i = 0; i < lenght; ++i) {           //Şifreleme Operasyonumuz
        if(password[i] >= 'a' && password[i] <= 'z'){
            password[i]= 'a' + ((password[i] - 'a' + scroll % 26) + 26) % 26;
        }                                               //Küçük harfse yukarıdaki, büyük harfse aşağıdaki satır çalışıyor.
        else if(password[i] >= 'A' && password[i] <= 'Z'){
            password[i]= 'A' + ((password[i] - 'A' + scroll%26) + 26)%26;

        }
    }

}
void deEncrypt(char password[],int scrollToBack){
    encrypt(password,-scrollToBack);    //Şifre çözme algoritması da aslında şifreleme algoritmasının sadece kaydırma değerinin negatif hali.
}
char withFile(char text[]){     //Dosyadan okuma veya dosyaya yazma operasyonu.
    FILE *fp;
    int answer;
    printf("Dosya Olusturup Okutmak Icin : 1\nDosyayi Okutmak Icin : Herhangi Bir Tusa Basin \n");
    scanf("%d",&answer);

    if(answer == 1){                                 //Cevaba göre sadece okuyor veya hem yazıp hem de okuyoruz.
        fp= fopen("dosya.txt","w");   //Yazma işlemi için dosyayı w(write) şeklinde açıyoruz.
                            //Buradaki dosya adını isteğinize göre değiştirebilirsiniz. Aslında dosya adını da kullanıcıdan alan bir program yazmak istemiştim ama henüz nasıl yapacağımı bilmiyorum.
        if(fp==NULL){
            printf("Dosya Acilamadi\n");        //Dosyanın geçerliliğini kontrol ediyoruz.
            return 1;
        }
        printf("Lutfen Dosyanin Icerigini Giriniz\n");
        gets(text);                         //gets fonksiyonlarıyla metnimizi alıyoruz.
        gets(text);                          //Kullanıcıdan metni alıyoruz.
        fputs(text,fp);         	    //Aldığımız metni dosyaya yazıyoruz.
        fclose(fp);                               //Ve dosyayı kapatıyoruz.
    }

    fp=fopen("dosya.txt","r");          //Okuma işlemi için dosyayı r(read) şeklinda açıyoruz.
    if(fp==NULL){
        printf("Dosya Bulunamadi\n");
        return 2;
    }

    fgets(text, 100, fp);   //Dosyayı okuyoruz ve text değişkenine atıyoruz.
    fclose(fp);
    return 0;



}
char deEncryptOperation(int gecerleme) {
    int numberOfScroll,answer;
    char getText[100];
    printf("Islemi Dosya ile Yapacaksaniz 1\nYapmayacaksaniz Herhangi Bir Tusa Basin\n");
    scanf("%d",&answer);        //Kullanıcının dosyayla mı yoksa normal yolla mı ilem yapacağını soruyoruz.
    if(answer == 1){
        withFile(getText);
        if(strlen(getText) ==gecerleme){ //Dosyayla yapılan işlemde dosya bulunamadıysa sonlandırıyoruz.
            return 1;}
    }
    else {
        printf("Lutfen Kirilacak Sifreyi Girin\nSifrenin Max Uzunlugu 100 Karakter Olmalidir\n");  //Normal yol için kullanıcıdan metni alıyoruz.
        takePassword:
        gets(getText);              //gets fonksiyonlarıyla metnimizi alıyoruz.
        gets(getText);

        if (strlen(getText) > 100) {                    //Şifre istenen miktardan uzunsa şifreyi tekrar yazdırıyoruz.
            printf("Sifre 100 Karakterden Buyuk Olamaz\n");
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
    printf("Sifresi Cozulen Metin : ");    //Deşifrelenen metni yazdırıyoruz.
    puts(getText);
    printf("\n\n");
    return 0;

}

char encryptOperation(int gecerleme) {           //Şifreleme operasyonunda ekstra olarak anlatacağım bir şey yok.
    char getText[100];              //Deşifreleme operasyonundaki yaptığımız şeylerden farklı olarak yaptığımız bir şey yok.
    int answer,numberOfScroll;
    printf("Islemi Dosya ile Yapacaksaniz 1\nYapmayacaksaniz Herhangi Bir Tusa Basin\n");
    scanf("%d",&answer);
    if(answer == 1){
        withFile(getText);
        if(strlen(getText) ==gecerleme){
            return 1;}
    }
    if(answer!=1) {
        printf("Lutfen Sifrelenecek Olan Metni Girin\nSifrenin Max Uzunlugu 100 Karakter Olmalidir\n");
        takePassword:
        gets(getText);
        gets(getText);


        if (strlen(getText) > 100) {
            printf("Metin 100 Karakterden Buyuk Olamaz\n");
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
    printf("Sifrelenen Metin : ");
    puts(getText);
    printf("\n\n");


    return 0;
}
