// week01_5_google_gamini_mouse_wheel_void_mouseWheel_MouseEvent_getCount
// google gemini:Processing 怎麼用 mouse wheel
float circleSize = 50; // 宣告全域變數控制圓的大小

void setup() {
  size(400, 400);
}

void draw() {
  background(220);
  // 繪製圓形，尺寸隨 circleSize 改變
  ellipse(width / 2, height / 2, circleSize, circleSize);
}

void mouseWheel(MouseEvent event) {
  // 取得滾輪數值
  float e = event.getCount();
  
  // 依據滾動方向改變數值（向下滾大、向上滾小）
  circleSize -= e * 5; 
  
  // 限制圓形大小的範圍，避免小於 0 或過大
  circleSize = constrain(circleSize, 10, 300);
}
