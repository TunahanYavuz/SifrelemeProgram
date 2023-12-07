# AlgoritmaSifrelemeOdev

## Program Hakkında Genel Bilgiler
- Şifreleme Programım Verdiğiniz Tam Sayı Kadar Girdiğiniz Metni İleri ya da Geri Doğru Öteleyebilmektedir.
- Programı Çalıştırdığınızda 3 Seçenek Göreceksiniz Bunlardan 1.si Şifreleme, 2.si Deşifreleme, 3.sü Programı Sonlandırma Fonksiyonlarıdır.
- **Program Sadece İngiliz Alfabesini İçermektedir.**
- Yani Gireceğiniz Türkçe veya Tanımlı Olmayan Bir Karakter Girdiğinizde Hata Alabilir veya Öteleme İşleminin Verdiğiniz Değer İçin Gerçekleşmediğini Görebilirsiniz.
- Eğer Dosyadan Okuma Yapmak veya Dosyaya Yazma İşlemleri Yapmak İsterseniz Program İçinde Yönlendirileceksiniz. Dosyadalar Da Yukarıda Yazdığım Kurallara Tabîdir.


## Operasyonları Kullanma
### Şifereleme Operasyonu
- Şifreleme Operasyonu Metni Girdiğiniz Sayı Kadar **Alfabe Sınırları** İçerisinde İleri Öteler.
  Yani Eğer "C de kod yaziyorum" Metnini Girerseniz ve Öteleme Miktarı Olarak 10 Sayısını Girerseniz Size Çıktı Olarak "M no uyn ikjsiybew" Metnini Verecektir.
- Bu Çıktı Sizin Girdiğiniz Metnin Her Bir Harfinin 10 Kez İleri Ötelenmiş Halidir.

---

### Deşifreleme Operasyonu
- Deşifreleme Operasyonu Metni Girdiğiniz Sayı Kadar **Alfabe Sınırları** İçerisinde Geri Öteler.
- Yani Yukarıdaki Verdiğim Örneği Kullanırsak ve Şifreyi Tekrar Anlamlı Bir Metne Dönüştürmek İstiyorsak "M no uyn ikjsiybew" Metninin Her Bir Harfini 10 Kez Geri Ötelememiz Gerekir.
- Program İçinde Deşifreleme Operasyonunu Seçtiğimzde, "M no uyn ikjsiybew" Metnini Yazdığımızda ve Öteleme Miktarını 10 Olarak Girdiğimizde Çıktı Olarak "C de kod yazıyorum" Metnini Alırız.



## Dosya Okuma ve Yazma
- Şifreleme ve Deşifreleme Operasyonları İçin Aynı Dosya Okuma ve Yazma Operasyonu Çalışmaktadır.
- Dosyanız Yoksa ve Dosya Oluşturma Seçeneğini Seçerseniz Kod Sizin İçin Bir 'input.txt' Dosyası Oluşturacaktır.
- Kendi Dosyanızı Oluşturmak İçin SifrelemeProgram.exe' nin Olduğu Klasörde Dosya Oluşturabilirsiniz.
- Kendi Oluşturduğunuz Farklı İsimdeki Bir Dosyayı Okutmak İsterseniz Kod İçindeki **'input.txt'** yi Değiştirebilirsiniz.




### Ekran Görüntüleri
![Şifreleme Görüntüsü](https://github.com/TunahanYavuz/SifrelemeProgram/assets/143287857/e1b91dd3-e044-40f8-87ef-5e755aec5b26)


![Deşifreleme Görüntüsü](https://github.com/TunahanYavuz/SifrelemeProgram/assets/143287857/856035f0-c055-4fec-a9ee-fefda1e77f8a)


![Şifreleme Görüntüsü](https://github.com/TunahanYavuz/SifrelemeProgram/assets/143287857/241ea010-7c10-4f5c-8762-698028083544)


![Deşifreleme Görüntüsü](https://github.com/TunahanYavuz/SifrelemeProgram/assets/143287857/0c5390fb-1ad7-4555-b2ed-6e684ff132c7)


### Kod İçeriği
---

```
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

char encryptOperation();
char deEncryptOperation(); //Fonksiyonları tanımlıyoruz

int main() {
    int operation;
    setlocale(LC_ALL,"Turkish");    //Türkçe karakter ekleme. Mesajları Türkçe vermek için.
    wprintf(L"Lütfen Yapmak İstediğiniz Operasyonu Seçin:\n");
    askAgain:           //Kullanıcının yapmak istediği işlemi soruyoruz.
    wprintf(L"1=Şifreleme\n"
           "2=Deşifreleme\n"
           "3=Programı Sonlandırma\n");
    if(scanf("%d", &operation)!=1){         //Girilen değerin sayı olup olmadığını kontrol ediyoruz.
        wprintf(L"Lütfen Sadece Sayı Giriniz\n");
        fflush(stdin);
        goto askAgain;
    }
    switch (operation) {            //Seçilen operasyona göre işlemi yapıyoruz.
        case 1:
            encryptOperation();
            wprintf(L"Lütfen Diğer Operasyonu Seçiniz\n");
            goto askAgain;
        case 2:                     //Her operasyon için kullanıcıya işlemi tekrar soruyoruz. Eğer kullanıcı çıkış yapmak istiyorsa 3 sayısını girmeli.
            deEncryptOperation();
            wprintf(L"Lütfen Diğer Operasyonu Seçiniz\n");
            goto askAgain;
        case 3:
            break;
        default:        //Farklı bir değer girilirse kullanıcıya tekrar soruyoruz.
            wprintf(L"Bilinmeyen Bir İşlem Girdiniz\n\tLütfen Tekrar Deneyiniz\n");
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
    wprintf(L"Dosya Oluşturup Okutmak İçin : 1\nSadece Dosyayı Okutmak İçin : Herhangi Bir Tuş Basın \n");
    scanf("%d",&answer);

    if(answer == 1){                                 //Cevaba göre sadece okuyor veya hem yazıp hem de okuyoruz.
        fp= fopen("input.txt","w");   //Yazma işlemi için dosyayı w(write) şeklinde açıyoruz.
                            //Buradaki dosya adını isteğinize göre değiştirebilirsiniz. Aslında dosya adını da kullanıcıdan alan bir program yazmak istemiştim ama henüz nasıl yapacağımı bilmiyorum.
        if(fp==NULL){
            wprintf(L"Dosya Açılamadı\n");        //Dosyanın geçerliliğini kontrol ediyoruz.
            return 0;
        }
        wprintf(L"Lütfen Dosyanın İçeriğini Giriniz\n");
        gets(text);                         //gets fonksiyonlarıyla metnimizi alıyoruz.
        gets(text);                          //Kullanıcıdan metni alıyoruz.
        fputs(text,fp);         	    //Aldığımız metni dosyaya yazıyoruz.
        fclose(fp);                               //Ve dosyayı kapatıyoruz.
    }
    fflush(stdin);
    fp=fopen("input.txt","r");          //Okuma işlemi için dosyayı r(read) şeklinda açıyoruz.
    if(fp==NULL){
        wprintf(L"Dosya Bulunamaı\n");
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
    wprintf(L"İşlemi Dosya ile Yapacaksanız : 1\nYapmayacaksanız Herhangi Bir Tuşa Basın\n");
    scanf("%d",&answer);
    //Kullanıcının dosyayla mı yoksa normal yolla mı ilem yapacağını soruyoruz.
    if(answer == 1){

        if(!withFile(getText)){ //Dosyayla yapılan işlemde dosya bulunamadıysa sonlandırıyoruz.
            return 0;}
    }
    else {
        wprintf(L"Lütfen Kırılacak Şifreyi Girin\nŞifrenin Max Uzunlugu 1000 Karakter Olmalıdır\n");  //Normal yol için kullanıcıdan metni alıyoruz.
        takePassword:
        gets(getText);              //gets fonksiyonlarıyla metnimizi alıyoruz.
        gets(getText);

        if (strlen(getText) > 1000) {                    //Metin istenen miktardan uzunsa şifreyi tekrar yazdırıyoruz.
            wprintf(L"Şifre 1000 Karakterden Büyük Olamaz\n");
            goto takePassword;
        }
    }
    wprintf(L"Lütfen Geri Öteleme Miktarını Giriniz\n");
    takeNumber:
    if (scanf("%d", &numberOfScroll) != 1) { //Öteleme miktarını alıyoruz ve sayı olup olmadığını kontrol ediyoruz.
        fflush(stdin);
        wprintf(L"Lütfen Sayı Giriniz\n");
        goto takeNumber;
    }

    deEncrypt(getText, numberOfScroll); //Aldığımız verileri deşifreleme operasyonuna gönderiyoruz.
    wprintf(L"Şifresi Çözulen Metin :\n");    //Deşifrelenen metni yazdırıyoruz.
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
    wprintf(L"İşlemi Dosya ile Yapacaksanız : 1\nYapmayacaksanız Herhangi Bir Tuşa Basın\n");
    scanf("%d",&answer);
    if(answer == 1){

        if(!withFile(getText)){
            return 0;}
    }
    if(answer!=1) {
        wprintf(L"Lütfen Kırılacak Şifreyi Girin\nŞifrenin Max Uzunlugu 1000 Karakter Olmalıdır\n");
        takePassword:
        gets(getText);
        gets(getText);


        if (strlen(getText) > 1000) {
            wprintf(L"Metin 1000 Karakterden Büyük Olamaz\n");
            fflush(stdin);
            goto takePassword;
        }
    }
    wprintf(L"Lütfen Öteleme Miktarını Giriniz\n");
    takeNumber:
    if (scanf("%d", &numberOfScroll) != 1) {
        fflush(stdin);
        wprintf(L"Lütfen Sayı Giriniz\n");
        goto takeNumber;
    }

    encrypt(getText, numberOfScroll);
    wprintf(L"Şifrelenen Metin :\n");
    while(i< strlen(getText)){
        putchar(getText[i]);
        ++i;
    }
    printf("\n\n");


    return 1;
}


```
