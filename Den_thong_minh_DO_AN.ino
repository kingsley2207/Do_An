#define Analog 5
int giatricambienas, chuyendong, giatriDigitalas;
void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(3, INPUT);
  pinMode(2, OUTPUT); 
}
void loop() {
//giatricambienas=analogRead(Analog);
chuyendong=digitalRead(3);
delay(200);
giatriDigitalas=digitalRead(8);
//Serial.print("Giá trị Analog: ");
//Serial.println(giatricambienas); 
Serial.print("Giá trị Digital chuyển động: ");
Serial.println(chuyendong); delay(300);
Serial.print("Giá trị logic ánh sáng: ");
Serial.println(giatriDigitalas); delay(200); //Có ánh sáng là 0, tối là 1
if (giatriDigitalas==0) //có ánh sáng, ko bật đèn
{
  digitalWrite(2,0);
  Serial.println("Đủ sáng rồi"); //tat den 
}
else if (giatriDigitalas==1 && chuyendong==1) 
{
  digitalWrite(2,1);
  Serial.println("Có người đi qua, Bật đèn lên");
  delay(8000);   //bat den 8s
  digitalWrite(2,0); Serial.println("Tắt đèn đi ngủ"); delay(200);
}
if (giatriDigitalas==1 && chuyendong==0) {
    //delay(200);
    giatricambienas=analogRead(Analog); delay(200); //troi toi nhưng ko co nguoi di ngang
    digitalWrite(2,0);
    Serial.println("Tắt đèn");                
                    } //ko co nguoi di qua, tat den */
                    //digitalWrite(13,0); delay(1000);digitalWrite(13,1); delay(500);
}

void fadeOn(unsigned int time,int increament){
       //change the brightness by FOR statement
  for (byte value = 255 ; value >0; value-=increament){ 
                // print out the value:
          Serial.println(value);
                // set the brightness of pin 10:
    analogWrite(2, value);
    delay(3000/(5));
        } 
}
