# AlgoritmaSifrelemeOdev
## Önemli Bilgi
- Benim Kullandığım Program CLion. Eğer Başka Bir Derleyici veya Program Kullanıyorsanız Dosya Bulunamadı Hatasından Sonra Da Sizden Öteleme Miktarı İsteyecektir. Bu Durumu Düzeltmek İçin **Programın Başında Size Sorulan Soruyu Kendi Derleyicinize Göre Cevaplamalısınız**. Vereceğiniz Cevap Minimum Dosya Uzunluğunu Verecektir. Ve Program Buna Göre Çalışacaktır.
## Program Hakkında Genel Bilgiler
- Şifreleme Programım Verdiğiniz Tam Sayı Kadar Girdiğiniz Metni İleri ya da Geri Doğru Öteleyebilmektedir.
- Programı Çalıştırdığınızda 3 Seçenek Göreceksiniz Bunlardan 1.si Şifreleme, 2.si Deşifreleme, 3.sü Programı Sonlandırma Fonksiyonlarıdır.
- **Program Sadece İngiliz Alfabesini İçermektedir.**
- Yani Gireceğiniz Türkçe veya Tanımlı Olmayan Bir Karakter Girdiğinizde Hata Alabilir veya Öteleme İşleminin Verdiğiniz Değer İçin Gerçekleşmediğini Görebilirsiniz.
- Eğer Dosyadan Okuma Yapmak veya Dosyaya Yazma İşlemleri Yapmak İsterseniz Program İçinde Yönlendirileceksiniz. Dosyadalar Da Yukarıda Yazdığım Kurallara Tabîdir.


## Operasyonları Kullanma
- Şifreleme Operasyonu Metni Girdiğiniz Sayı Kadar **Alfabe Sınırları** İçerisinde İleri Öteler.
  Yani Eğer "C de kod yaziyorum" Metnini Girerseniz ve Öteleme Miktarı Olarak 10 Sayısını Girerseniz Size Çıktı Olarak "M no uyn ikjsiybew" Metnini Verecektir.
- Bu Çıktı Sizin Girdiğiniz Metnin Her Bir Harfinin 10 Kez İleri Ötelenmiş Halidir.

---

- Deşifreleme Operasyonu Metni Girdiğiniz Sayı Kadar **Alfabe Sınırları** İçerisinde Geri Öteler.
- Yani Yukarıdaki Verdiğim Örneği Kullanırsak ve Şifreyi Tekrar Anlamlı Bir Metne Dönüştürmek İstiyorsak "M no uyn ikjsiybew" Metninin Her Bir Harfini 10 Kez Geri Ötelememiz Gerekir.
- Program İçinde Deşifreleme Operasyonunu Seçtiğimzde, "M no uyn ikjsiybew" Metnini Yazdığımızda ve Öteleme Miktarını 10 Olarak Girdiğimizde Çıktı Olarak "C de kod yazıyorum" Metnini Alırız.



## Dosya Okuma ve Yazma
- Şifreleme ve Deşifreleme Operasyonları İçin Aynı Dosya Okuma ve Yazma Operasyonu Çalışmaktadır.
- Dosyanız Yoksa ve Dosya Oluşturma Seçeneğini Seçerseniz Kod Sizin İçin Bir 'input.txt' Dosyası Oluşturacaktır.
- Kendi Dosyanızı Oluşturmak İçin main.exe' nin Olduğu Klasörde Dosya Oluşturabilirsiniz.
- Kendi Oluşturduğunuz Farklı İsimdeki Bir Dosyayı Okutmak İsterseniz Kod İçindeki **'input.txt'** yi Değiştirebilirsiniz.




### Ekran Görüntüleri
![Şifreleme Görüntüsü](https://private-user-images.githubusercontent.com/143287857/287723912-18f87ce8-038b-4a96-be55-d37d833275e6.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTEiLCJleHAiOjE3MDE2OTkzMDEsIm5iZiI6MTcwMTY5OTAwMSwicGF0aCI6Ii8xNDMyODc4NTcvMjg3NzIzOTEyLTE4Zjg3Y2U4LTAzOGItNGE5Ni1iZTU1LWQzN2Q4MzMyNzVlNi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBSVdOSllBWDRDU1ZFSDUzQSUyRjIwMjMxMjA0JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDIzMTIwNFQxNDEwMDFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0xYzIxYzQzNTJmZWEwZjNkMWVlYzE0YzkyMmQzZjdjMjgyMWQ4ZjRmNWZiOTNlNTkzMTU0MDJmODgwYWE0ZWZkJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.9PX452rK0we8YYCXjIpOJ-cmbSzYqOyTSz7bkaw59tI)


![Deşifreleme Görüntüsü](https://private-user-images.githubusercontent.com/143287857/287723917-3f9afc4a-e5bc-4826-b6fa-5b0489089ebd.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTEiLCJleHAiOjE3MDE2OTkzMDEsIm5iZiI6MTcwMTY5OTAwMSwicGF0aCI6Ii8xNDMyODc4NTcvMjg3NzIzOTE3LTNmOWFmYzRhLWU1YmMtNDgyNi1iNmZhLTViMDQ4OTA4OWViZC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBSVdOSllBWDRDU1ZFSDUzQSUyRjIwMjMxMjA0JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDIzMTIwNFQxNDEwMDFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT05Mjk3YmIyMmUyM2RmN2IyNmI5MzdjMjBiMWQ0OGMyZmRhYTFiNDIwNDA2MmY0ZDM2NWFjMWQyMWQ1MjQ5MmY3JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.KKiJYdHSemiyW54laUPMwhYjPBg-9fBFsxeAgsDL29o)


### Kod İçeriği
---

```
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char encryptOperation(int gecerleme);
char deEncryptOperation(int gecerleme); //Fonksiyonları tanımlıyoruz

int main() {
    int operation,control;
    home:                   //Kullanıcının derleyicisine göre mininmum bir dosya uzunluğu alıyoruz.
    printf("Readme De Bahsettigim Uzere Derleyicinize Gore Bir Sayi Giriniz.\n\tBu Sayi Dosyanizin Minimum Uzunluğunu Belirtecektir\n");
    if(scanf("%d",&control) != 1){
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
            encryptOperation(control);
            printf("Lutfen Diger Operasyonu Seciniz\n");
            goto askAgain;
        case 2:                     //Her operasyon için kullanıcıya işlemi tekrar soruyoruz. Eğer kullanıcı çıkış yapmak istiyorsa 3 sayısını girmeli.
            deEncryptOperation(control);
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
        if(isalpha(password[i])){                   //isalpha fonksiyonuyla girilen harfin alfabede olup olmadığını kontrol ediyoruz.
            char character = islower(password[i])? 'a':'A';         //islower fonksiyonuyla harfin büyük ya da küçük olduğunu kontrol ediyoruz. Eğer küçükse a harfini değilse A harfini character değişkenine atıyoruz.
            password[i]= character+(-character+ password[i] +scroll%26)%26;  //Önce a harfini çıkarıyoruz sonra öteleme miktarını buluyoruz ve a harfine ekliyoruz.
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
    printf("Dosya Olusturup Okutmak Icin : 1\nDosyayi Okutmak Icin : Herhangi Bir Tusa Basin \n");
    scanf("%d",&answer);

    if(answer == 1){                                 //Cevaba göre sadece okuyor veya hem yazıp hem de okuyoruz.
        fp= fopen("input.txt","w");   //Yazma işlemi için dosyayı w(write) şeklinde açıyoruz.
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

    fp=fopen("input.txt","r");          //Okuma işlemi için dosyayı r(read) şeklinda açıyoruz.
    if(fp==NULL){
        printf("Dosya Bulunamadi\n");
        return 2;
    }


    while((c= fgetc(fp))!=EOF){  //Dosya bitene kadar her bir harfi text değişkenine atıyoruz.
        text[i]=c;
        ++i;
    }
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

char encryptOperation(int gecerleme) {
    char getText[100];                  //Deşifreleme operasyonundaki yaptığımız şeylerden farklı olarak yaptığımız bir şey yok.
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

```
