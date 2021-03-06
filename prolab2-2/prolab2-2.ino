#include <Arduino.h>
#line 1 "C:\\Users\\Axcly\\AppData\\Local\\Temp\\arduino_modified_sketch_310649\\ReadWrite.ino"
#include <EEPROM.h>
// #include <LiquidCrystal.h>

struct hizmet {
  int hizmetID;
  String hizmetAd;
  int kalanHizmetAdet;
  int hizmetFiyat;
};

int beslikSayisi = 20;
int onlukSayisi = 20;
int yirmilikSayisi = 10;
int ellilikSayisi = 30;
int yuzlukSayisi = 5;


struct hizmet kopukleme;
struct hizmet yikama;


struct hizmet kurulama;

struct hizmet cilalama;


const int buton = 2 ;
int butondurumu = 0;
int deger = 0;

const int buton2 = 3 ;
int butondurumu2 = 0;
int deger2 = 0;

const int buton3 = 4 ;
int butondurumu3 = 0;
int deger3 = 0;

const int buton4 = 5 ;
int butondurumu4 = 0;
int deger4 = 0;

const int buton5 = 6 ;
int butondurumu5 = 0;
int deger5 = 0;

const int buton6 = 7 ;
int butondurumu6 = 0;
int deger6 = 0;

const int kopuklemeButon = 8 ;
int kopuklemebutondurumu = 0;
int deger7 = 0;

const int yikamaButon = 9 ;
int yikamabutondurumu = 0;
int deger8 = 0;

const int kurulamaButon = 10 ;
int kurulamabutondurumu = 0;
int deger9 = 0;

const int cilalamaButon = 11 ;
int  cilalamabutondurumu = 0;
int deger10 = 0;

const int bitisButon = 12 ;
int bitisbutondurumu = 0;
int deger11 = 0;

const int resetButon = 13 ;
int resetbutondurumu = 0;
int deger12 = 0;


String kalanHizmet = "";
int kasadakiPara = 0;
int yuklenenPara = 0;
int harcananPara = 0;
int kalanPara = 0;
//LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
boolean islemBasariliMi = false;
int randomSayi = 0;
int kirmiziLed = 14;  // A0 numarali pin
int yesilLed = 15;    // A1 numarali pin
int verilecekYuz = 0 ;
int verilecekElli = 0;
int verilecekYirmi = 0;
int verilecekOn = 0;
int verilecekBes = 0 ;
int paraUstu = 0;
int verilecekBanknotAdet[5];
String output = "";

void setup() {
  Serial.begin(9600);
  // lcd.begin(40,2);



  kopukleme.hizmetID = 1;
  kopukleme.hizmetAd = "kopukleme";
  kopukleme.kalanHizmetAdet = 30;
  kopukleme.hizmetFiyat = 15;

  yikama.hizmetID = 2;
  yikama.hizmetAd = "yikama";
  yikama.kalanHizmetAdet = 50;
  yikama.hizmetFiyat = 10;

  kurulama.hizmetID = 3;
  kurulama.hizmetAd = "kurulama";
  kurulama.kalanHizmetAdet = 100;
  kurulama.hizmetFiyat = 5;

  cilalama.hizmetID = 4;
  cilalama.hizmetAd = "cilalama";
  cilalama.kalanHizmetAdet = 20;
  cilalama.hizmetFiyat = 50;

  int verilecekElli = kalanPara / 50;
  int verilecekYirmi = kalanPara / 20;
  int verilecekOn = kalanPara / 10;
  int verilecekBes = kalanPara / 5;


  Serial.println('\n');
  // lcd.println(">>>>>>>> LUTFEN MAKINEYE PARA YUKLEYINIZ <<<<<<<<");
  Serial.println(">>>>>>>> LUTFEN MAKINEYE PARA YUKLEYINIZ <<<<<<<<");

  pinMode(buton, INPUT);
  pinMode(buton2, INPUT);
  pinMode(buton3, INPUT);
  pinMode(buton4, INPUT);
  pinMode(buton5, INPUT);
  pinMode(buton6, INPUT);
  pinMode(kopuklemeButon, INPUT);
  pinMode(yikamaButon, INPUT);
  pinMode(kurulamaButon, INPUT);
  pinMode(cilalamaButon, INPUT);
  pinMode(bitisButon, INPUT);
  pinMode(resetButon, INPUT);
  pinMode(yesilLed, INPUT);
  pinMode(kirmiziLed, INPUT);


}

void loop() {

  butondurumu = digitalRead(2);
  butondurumu2 = digitalRead(3);
  butondurumu3 = digitalRead(4);
  butondurumu4 = digitalRead(5);
  butondurumu5 = digitalRead(6);
  butondurumu6 = digitalRead(7);
  kopuklemebutondurumu = digitalRead(8);
  yikamabutondurumu = digitalRead(9);
  kurulamabutondurumu = digitalRead(10);
  cilalamabutondurumu = digitalRead(11);
  bitisbutondurumu = digitalRead(12);
  resetbutondurumu = digitalRead(13);


  if ( butondurumu == HIGH && deger == 0 )
  {

    yuklenenPara = yuklenenPara + 5;
    beslikSayisi++;
    deger = 1;
    delay(10);
  }

  if (butondurumu == LOW && deger == 1) {

    deger = 0;
    delay(10);
  }

  if ( butondurumu2 == HIGH && deger2 == 0 )
  {

    yuklenenPara = yuklenenPara + 10;
    onlukSayisi++;
    deger2 = 1;
    delay(10);
  }

  if (butondurumu2 == LOW && deger2 == 1) {

    deger2 = 0;
    delay(10);
  }

  if ( butondurumu3 == HIGH && deger3 == 0 )
  {

    yuklenenPara = yuklenenPara + 20;
    yirmilikSayisi++;
    deger3 = 1;
    delay(10);
  }

  if (butondurumu3 == LOW && deger3 == 1) {

    deger3 = 0;
    delay(10);
  }

  if ( butondurumu4 == HIGH && deger4 == 0 )
  {

    yuklenenPara = yuklenenPara + 50;
    ellilikSayisi++;
    deger4 = 1;
    delay(10);
  }

  if (butondurumu4 == LOW && deger4 == 1) {

    deger4 = 0;
    delay(10);
  }

  if ( butondurumu5 == HIGH && deger5 == 0 )
  {

    yuklenenPara = yuklenenPara + 100;
    yuzlukSayisi++;
    deger5 = 1;
    delay(10);
  }

  if (butondurumu5 == LOW && deger5 == 1) {

    deger5 = 0;
    delay(10);
  }


  if ( butondurumu6 == HIGH && deger6 == 0 )
  {

    // lcd.print(yuklenenPara);
    Serial.print(yuklenenPara);
    Serial.println("TL yuklediniz.");
    Serial.println('\n');
    Serial.println(">>>>>>>> LUTFEN HIZMET SECIMI YAPINIZ <<<<<<<<<");

    deger6 = 1;
    delay(10);
  }

  if (butondurumu6 == LOW && deger6 == 1) {

    deger6 = 0;
    delay(10);
  }


  if ( kopuklemebutondurumu == HIGH && deger7 == 0 )
  {
    Serial.println("Kopukleme servisi secilmistir. (15TL)");
    kopukleme.kalanHizmetAdet--;   // hizmetler[0] = kopukleme hizmeti
    harcananPara = harcananPara + kopukleme.hizmetFiyat;

    deger7 = 1;
    delay(10);
  }

  if (kopuklemebutondurumu == LOW && deger7 == 1)
  {
    deger7 = 0;
    delay(10);
  }

  if ( yikamabutondurumu == HIGH && deger8 == 0 )
  {
    Serial.println("Yikama servisi secilmistir. (10TL)");
    yikama.kalanHizmetAdet--;   // hizmetler[1] = y??kama hizmeti
    harcananPara = harcananPara + yikama.hizmetFiyat;

    deger8 = 1;
    delay(10);
  }

  if (yikamabutondurumu == LOW && deger8 == 1)
  {
    deger8 = 0;
    delay(10);
  }

  if ( kurulamabutondurumu == HIGH && deger9 == 0 )
  {
    Serial.println("Kurulama servisi secilmistir. (5TL)");
    kurulama.kalanHizmetAdet--;   // hizmetler[2] = kurulama hizmeti
    harcananPara = harcananPara + kurulama.hizmetFiyat;

    deger9 = 1;
    delay(10);
  }

  if (kurulamabutondurumu == LOW && deger9 == 1)
  {
    deger9 = 0;
    delay(10);
  }

  if ( cilalamabutondurumu == HIGH && deger10 == 0 )
  {
    Serial.println("Cilalama servisi secilmistir. (50TL)");
    cilalama.kalanHizmetAdet--;   // hizmetler[3] = cilalama hizmeti
    harcananPara = harcananPara + cilalama.hizmetFiyat;

    deger10 = 1;
    delay(10);
  }

  if (cilalamabutondurumu == LOW && deger10 == 1)
  {
    deger10 = 0;
    delay(10);
  }

  if ( bitisbutondurumu == HIGH && deger11 == 0 )
  {
    if (kopukleme.kalanHizmetAdet < 0 || yikama.kalanHizmetAdet < 0 || kurulama.kalanHizmetAdet < 0 || cilalama.kalanHizmetAdet < 0 )
      Serial.println("Hatali secim yaptiniz!! Lutfen RESET butonuna basiniz.");
    else if (harcananPara > yuklenenPara ) {
      Serial.println("Bakiyeniz yetersiz!");
      Serial.println("Isleminize devam etmek istiyorsaniz para ilavesi yapiniz.");
      Serial.println("Isleminizi iptal etmek istiyorsaniz RESET butonuna basiniz.");
    }
    else {
      Serial.println("Secim basarili! Lutfen bekleyin...");
      islemBasariliMi = true;
    }
    deger11 = 1;
    delay(10);
  }

  if (bitisbutondurumu == LOW && deger11 == 1)
  {
    deger11 = 0;
    delay(10);
  }


  randomSayi = random(1, 5);  // 1 ile 4 arasinda random sayi uretiliyor

  if (islemBasariliMi == true )
  {
    Serial.println("//random sayi: "+(String)randomSayi);
    if (randomSayi == 2) {
      Serial.println("Para sikismasi olmustur...");
      digitalWrite(kirmiziLed, HIGH);
      delay(5000);
      digitalWrite(kirmiziLed, LOW);
      delay(100);
      Serial.println((String)yuklenenPara + " TL paraniz iade edilmistir.");
      Serial.println("Lutfen RESET butonuna basiniz.");
      islemBasariliMi = false;
    }

    else if (randomSayi != 2)
    {
      digitalWrite(yesilLed, HIGH);
      delay(5000);
      digitalWrite(yesilLed, LOW);
      delay(100);

      if (harcananPara == yuklenenPara) {
        Serial.println("??sleminiz basariyla gerceklesmistir. Iyi gunler...");
        Serial.println('\n');
        Serial.println('\n');
        Serial.println('\n');
        Serial.println(">>>>>>>> LUTFEN MAKINEYE PARA YUKLEYINIZ <<<<<<<<");
      }

      else if (harcananPara < yuklenenPara) {
        Serial.println("Para ustu hazirlaniyor...");
        Serial.println((String)harcananPara + "TL Harcanan Para");
        
        kalanPara = yuklenenPara - harcananPara;

      Serial.println((String)kalanPara + "TL toplam Para ustunuz");
          verilecekYuz = kalanPara / 100;
          if (kalanPara >= 100 && yuzlukSayisi > 0 && verilecekYuz >= yuzlukSayisi) {
            verilecekBanknotAdet[0] = yuzlukSayisi;
            output = output+(String)yuzlukSayisi + "adet 100TL, ";
            kalanPara = kalanPara - yuzlukSayisi * 100;
            paraUstu = paraUstu + yuzlukSayisi*100;
            yuzlukSayisi = 0;
          }
          else if ( kalanPara >= 100 && yuzlukSayisi > 0 && verilecekYuz < yuzlukSayisi) {
            verilecekBanknotAdet[0] = verilecekYuz;
            output = output + (String)verilecekYuz + "adet 100TL, ";
            kalanPara = kalanPara - verilecekYuz * 100;
            paraUstu = paraUstu + verilecekYuz * 100;
            yuzlukSayisi = yuzlukSayisi - verilecekYuz;
          }

          verilecekElli = kalanPara / 50;
          if (kalanPara >= 50 && ellilikSayisi > 0 && verilecekElli >= ellilikSayisi) {
            verilecekBanknotAdet[1] = ellilikSayisi;
            output = output + (String)ellilikSayisi + "adet 50TL, ";
            kalanPara = kalanPara - ellilikSayisi * 50;
            paraUstu = paraUstu + ellilikSayisi * 50;
            ellilikSayisi = 0;
          }
          else if ( kalanPara >= 50 && ellilikSayisi > 0 && verilecekElli < ellilikSayisi) {

            verilecekBanknotAdet[1] = verilecekElli;
            output = output + (String)verilecekElli + "adet 50TL, ";
            kalanPara = kalanPara - verilecekElli * 50;
            paraUstu = paraUstu + verilecekElli * 50; 
            ellilikSayisi = ellilikSayisi - verilecekElli;
          }

          verilecekYirmi = kalanPara / 20;
          if (kalanPara >= 20 && yirmilikSayisi > 0 && verilecekYirmi >= yirmilikSayisi) {
            verilecekBanknotAdet[2] = yirmilikSayisi;
            output = output + (String)yirmilikSayisi + "adet 20TL, ";
            kalanPara = kalanPara - yirmilikSayisi * 20;
            paraUstu = paraUstu + yirmilikSayisi * 20;
            yirmilikSayisi = 0;
          }
          else if ( kalanPara >= 20 && yirmilikSayisi > 0 && verilecekYirmi < yirmilikSayisi) {
            verilecekBanknotAdet[2] = verilecekYirmi;
            output = output + (String)verilecekYirmi + "adet 20TL, ";
            kalanPara = kalanPara - verilecekYirmi * 20;
            paraUstu = paraUstu + verilecekYirmi * 20;
            yirmilikSayisi = yirmilikSayisi - verilecekYirmi;
          }

          verilecekOn = kalanPara / 10;
          if (kalanPara >= 10 && onlukSayisi > 0 && verilecekOn >= onlukSayisi) {
            verilecekBanknotAdet[3] = onlukSayisi;
            output = output + (String)onlukSayisi + "adet 10TL, ";
            kalanPara = kalanPara - onlukSayisi * 10;
            paraUstu = paraUstu + onlukSayisi * 10;
            onlukSayisi = 0;
          }
          else if ( kalanPara >= 10 && onlukSayisi > 0 && verilecekOn < onlukSayisi) {
            verilecekBanknotAdet[3] = verilecekOn;
            output = output + (String)verilecekOn + "adet 10TL, ";
            kalanPara = kalanPara - verilecekOn * 10;
            paraUstu = paraUstu + verilecekOn * 10;
            onlukSayisi = onlukSayisi - verilecekOn;
          }

          verilecekBes = kalanPara / 5;
          if (kalanPara >= 5 && beslikSayisi > 0 && verilecekBes >= beslikSayisi) {
            verilecekBanknotAdet[4] = beslikSayisi;
            output = output + (String)beslikSayisi + "adet 5TL, ";
            kalanPara = kalanPara - beslikSayisi * 5;
            paraUstu = paraUstu + beslikSayisi * 5;
            beslikSayisi = 0;
          }
          else if ( kalanPara >= 5 && beslikSayisi > 0 && verilecekBes < beslikSayisi) {
            verilecekBanknotAdet[4] = verilecekBes;
            output = output + (String)verilecekBes + "adet 5TL, ";
            kalanPara = kalanPara - verilecekBes * 5;
            paraUstu = paraUstu + verilecekBes * 5;
            beslikSayisi = beslikSayisi - verilecekBes;
           }
          
        if (paraUstu != yuklenenPara-harcananPara) {
          Serial.println("Kasada yeterli para yoktur.");
          Serial.println((String)yuklenenPara + " TL paraniz iade edilmistir.");
          Serial.println("Lutfen RESET butonuna basiniz.");
        }
        else{
          Serial.print(output);
          Serial.println(" para ustunuzu alabilirsiniz. Iyi gunler...");
          Serial.println('\n');
          Serial.println('\n');
          Serial.println('\n');
          Serial.println(">>>>>>>> LUTFEN MAKINEYE PARA YUKLEYINIZ <<<<<<<<");
        
        }
          yuklenenPara = 0;
          harcananPara = 0;
          paraUstu = 0;
          output = "";
  
      }
    }
    islemBasariliMi = false;
  }










  /* if ( resetbutondurumu == HIGH && deger12 == 0 )
    {

    Serial.println("Paraniz iade edilmistir.");
    deger12 = 1;
    delay(10);
    }

    if (bitisbutondurumu == LOW && deger12 == 1)
    {
    deger12 = 0;
    delay(10);
    }*/


}
