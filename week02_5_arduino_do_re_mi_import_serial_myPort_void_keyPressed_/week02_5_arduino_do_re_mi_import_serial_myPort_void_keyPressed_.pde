// week02_5_arduino_do_re_mi_import_serial_myPort_void_keyPressed_write
// google: 我想要把Arduino 跟Processing結合
// 在Processing 按下 key 1 2 3 對應 Arduino 的 Do Re Mi 使用USB Serial
// 因為只有一條USB Serial線, 要記得按下「方塊」停止占用執行
import processing.serial.*; // 使用USB Serial 外掛
Serial myPort; // 將用 myPort 來傳 USB Serial 資料
void setup(){
  size(300, 200); // 隨便的視窗
  myPort = new Serial(this, "COM3", 9600); // 中間 "COM4" or "COM3" 自己查
}
void draw(){
  
}
void keyPressed(){//按數字鍵時，會利用USB Serial傳資料到電路板 
  if(key=='1') myPort.write('1');
  if(key=='2') myPort.write('2');
  if(key=='3') myPort.write('3');
}
