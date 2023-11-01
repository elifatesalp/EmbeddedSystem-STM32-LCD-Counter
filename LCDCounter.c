 #define BUTON Button(&GPIOA_IDR,0,150,1) //Kullanici butonu tanimlandi
 //LCD baglantilari tanimlaniyor
 sbit LCD_RS at GPIOE_ODR.B8;
 sbit LCD_EN at GPIOE_ODR.B10;
 sbit LCD_D4 at GPIOE_ODR.B4;
 sbit Lcd_D5 at GPIOE_ODR.B5;
 sbit LCD_D6 at GPIOE_ODR.B6;
 sbit LCD_D7 at GPIOE_ODR.B7;
 
//LCD baglantilari yapildi

char txt[6];
int sayi=0;

void main() {
    GPIO_Digital_Output(GPIOE_BASE, _GPIO_PINMASK_9); //R/W pini saseye cekiliyor
    GPIOE_ODR.B9=0;
    GPIO_Digital_Input(&GPIOA_IDR,_GPIO_PINMASK_0); //BUTON giris olarak set edildi
    Lcd_Init();     //LCD kuruldu
    Lcd_Cmd(_LCD_CURSOR_OFF); //imlec kapatildi
    Lcd_Out(1,1, "LCD Sayici");  //1. satir 1. sutuna LCD sayici yaz
    
    do
    {
       if(BUTON)      //butona basildiysa
        {
          sayi++;     //sayi degiskeni 1 arttir
          IntToStr(sayi,txt); //karaktere cevir
          Lcd_Out(2,1,txt);   //LCD 2. satir 1. sutuna yaz
          while(BUTON);       //Butondan elini cekene kadar bekle
          }
        }while(1);
}