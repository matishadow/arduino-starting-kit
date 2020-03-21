const int tempPin = A0;
const float minTemp = 20.0;

void setup()
{
    Serial.begin(9600);

    for (int i = 3; i < 8; i++)
    {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
}

void loop()
{
    int tempVal = analogRead(tempPin);

    Serial.print("Temp :");
    Serial.print(tempVal);

    float voltage = tempVal / 1024.0 * 5.0;

    Serial.print(", Volts: ");
    Serial.print(voltage);

    Serial.print(", temp: ");
    float temp = (voltage - 0.5) * 100;
    Serial.println(temp);

    if (temp < minTemp + 2)
    {
        digitalWrite(3, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
    }
    else if (temp > minTemp + 2 && temp < minTemp + 4)
    {
        digitalWrite(3, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
    }
    else if (temp >= minTemp + 4 && temp < minTemp + 6)
    {
        digitalWrite(3, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
    }
    else if (temp >= minTemp + 6)
    {
        digitalWrite(3, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
    }

    delay(1);
}