void setupMultithreading(){
  xTaskCreatePinnedToCore(
      OtherThreadCode, /* Function to implement the task */
      "TaskOtherThread", /* Name of the task */
      10000,  /* Stack size in words */
      NULL,  /* Task input parameter */
      0,  /* Priority of the task */
      &TaskOtherThread,  /* Task handle. */
      0);
}

void OtherThreadCode(void * pvParameters){
  while(true){
    sensors.requestTemperatures(); 
  
    //Serial.print("Celsius temperature: ");
    
    //Serial.print(sensors.getTempCByIndex(0)); 
    //Serial.print(" - Fahrenheit temperature: ");
    //Serial.println(sensors.getTempFByIndex(0));
    delay(1000);
  }
}