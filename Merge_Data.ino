void setup() {
  Serial.begin(9600);
  Serial3.begin(9600); // Ensure this matches your hardware setup
}

void loop() {
  if (Serial3.available()) {
    String receivedData = Serial3.readStringUntil('\n');
    Serial.println(receivedData);

    // Merge data into a single string
    String mergedData = mergeData(receivedData);
    Serial.println("Merged Data: " + mergedData);

    // Find the indices of the first three occurrences of '1'
    findFirstThreeOnes(mergedData);
  }
}

String mergeData(String data) {
  String mergedData = "";

  int physicsIndex = data.indexOf("Physics: ");
  int engineeringIndex = data.indexOf("Engineering: ");
  int mathematicsIndex = data.indexOf("Mathematics: ");

  if (physicsIndex != -1 && engineeringIndex != -1 && mathematicsIndex != -1) {
    String physicsData = data.substring(physicsIndex + 9, physicsIndex + 14);
    String engineeringData = data.substring(engineeringIndex + 13, engineeringIndex + 18);
    String mathematicsData = data.substring(mathematicsIndex + 13, mathematicsIndex + 18);

    mergedData = physicsData + engineeringData + mathematicsData;
  }

  return mergedData;
}

void findFirstThreeOnes(String data) {
  int count = 0;
  for (int i = 0; i < data.length(); i++) {
    if (data.charAt(i) == '1') {
      Serial.print("Index of '1' #");
      Serial.print(count + 1);
      Serial.print(": ");
      Serial.println(i);
      
      count++;
      if (count == 3) break;
    }
  }
  
  if (count < 3) {
    Serial.println("Less than 3 occurrences of '1' found.");
  }
}
