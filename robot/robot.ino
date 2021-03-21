short solDCMotor = 9;
short sagDCMotor = 10;
short trigPin = 2;
short echoPin = 3;
short ledPin = 4;
short sure;
short uzaklik = 0;
int mevcutKonum[2];
short sonKalanYon = 1;
short randomSayi;
short kaliciRandom;
short geciciUzaklik = 0;

void setup() {
  pinMode(solDCMotor, OUTPUT);
  pinMode(sagDCMotor, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4, OUTPUT);
  pinMode(ledPin, OUTPUT);
  mevcutKonum[0] = 0;
  mevcutKonum[1] = 0;
  delay(1000);
}

/*
 * 90 DERECE = 2200 MS
 * 180 DERECE = 4400 MS
 * 270 DERECE = 6600 MS
 */
void ilerlet(short yon, int milisaniye) {
  // +Y EKSENİ İLERLETME
  if (yon == 1) {
    if (sonKalanYon == 1) {
      digitalWrite(solDCMotor, 1);
      digitalWrite(sagDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 2) {
      digitalWrite(solDCMotor, 1);
      delay(2200);
      digitalWrite(sagDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 3){
      digitalWrite(sagDCMotor, 1);
      delay(2200);
      digitalWrite(solDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 4) {
      digitalWrite(solDCMotor, 1);
      delay(4400);
      digitalWrite(sagDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    sonKalanYon = 1;
    mevcutKonum[1] += milisaniye;
  }

  // -X EKSENİ İLERLETME
  if (yon == 2) {
    if (sonKalanYon == 1) {
      digitalWrite(sagDCMotor, 1);
      delay(2200);
      digitalWrite(solDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 2) {
      digitalWrite(solDCMotor, 1);
      digitalWrite(sagDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 3){
      digitalWrite(solDCMotor, 1);
      delay(4400);
      digitalWrite(sagDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 4) {
      digitalWrite(solDCMotor, 1);
      delay(2200);
      digitalWrite(sagDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    sonKalanYon = 2;
    mevcutKonum[0] -= milisaniye;
  }

  // +X EKSENİ İLERLETME
  if (yon == 3) {
    if (sonKalanYon == 1) {
      digitalWrite(solDCMotor, 1);
      delay(2200);
      digitalWrite(sagDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 2) {
      digitalWrite(sagDCMotor, 1);
      delay(4400);
      digitalWrite(solDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 3){
      digitalWrite(solDCMotor, 1);
      digitalWrite(sagDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 4) {
      digitalWrite(sagDCMotor, 1);
      delay(2200);
      digitalWrite(solDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    sonKalanYon = 3;
    mevcutKonum[0] += milisaniye;
  }

  // -Y EKSENİ İLERLETME
  if (yon == 4) {
    if (sonKalanYon == 1) {
      digitalWrite(solDCMotor, 1);
      delay(4400);
      digitalWrite(sagDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 2) {
      digitalWrite(sagDCMotor, 1);
      delay(2200);
      digitalWrite(solDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 3){
      digitalWrite(solDCMotor, 1);
      delay(2200);
      digitalWrite(sagDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    if (sonKalanYon == 4) {
      digitalWrite(sagDCMotor, 1);
      digitalWrite(solDCMotor, 1);
      delay(milisaniye);
      digitalWrite(solDCMotor, 0);
      digitalWrite(sagDCMotor, 0);
    }
    sonKalanYon = 4;
    mevcutKonum[1] -= milisaniye;
  }
  if (yon == 5) {
    digitalWrite(solDCMotor, 1);
    delay(6600);
    digitalWrite(solDCMotor, 0);
    digitalWrite(sagDCMotor, 1);
    delay(2200);
    digitalWrite(sagDCMotor, 0);
    mevcutKonum[0] = mevcutKonum[0] * (-1);
    mevcutKonum[1] = mevcutKonum[1] * (-1);
  }
}

void uzaklikBul() {
  digitalWrite(trigPin,0);
  delayMicroseconds(5);
  digitalWrite(trigPin,1);
  delayMicroseconds(10);
  digitalWrite(trigPin,0);
  sure = pulseIn(echoPin,1);
  uzaklik = sure/29.1/2;
  if (uzaklik >= 100) {
    uzaklik = 0;
  }
  delay(50);
}

void copAra(int rando) {
  if (geciciUzaklik <= uzaklik) { // Engel yoksa buraya girer
    if (sonKalanYon != rando) {
      ilerlet(rando,0);
      uzaklikBul();
      geciciUzaklik = uzaklik;
      ilerlet(rando,2200);
      uzaklikBul();
    } else {
      uzaklikBul();
      geciciUzaklik = uzaklik;
      ilerlet(rando,2200);
      uzaklikBul();
    }
    if (geciciUzaklik > uzaklik) {
      kaliciRandom = rando;
    }
  } else { // Engele yaklaşıyorsa buraya girer
    uzaklikBul(); // Bura gereksiz gibime geldi sonra bi bak
    geciciUzaklik = uzaklik;
    ilerlet(kaliciRandom,2200);
    uzaklikBul();
    if (uzaklik <= 4) {
      ilerlet(sonKalanYon,1000);
      ilerlet(5,1); // 1 i kafadan attım ihtiyaç yok zaten
      if (mevcutKonum[0] > 0) {
        if (mevcutKonum[1] > 0) {
          ilerlet(1,mevcutKonum[1]);
          ilerlet(3,mevcutKonum[0]);
        }
        if (mevcutKonum[1] < 0) {
          ilerlet(4,mevcutKonum[1]);
          ilerlet(3,mevcutKonum[0]);
        }
      }
      if (mevcutKonum[0] < 0) {
        if (mevcutKonum[1] > 0) {
          ilerlet(1,mevcutKonum[1]);
          ilerlet(2,mevcutKonum[0]);
        }
        if (mevcutKonum[1] < 0) {
          ilerlet(4,mevcutKonum[1]);
          ilerlet(2,mevcutKonum[0]);
        }
      }
      digitalWrite(ledPin, 1);
      sonKalanYon = 1;
      geciciUzaklik = 0;
      uzaklik = 0;
      mevcutKonum[0] = 0;
      mevcutKonum[1] = 0;
      delay(10000);
      digitalWrite(ledPin, 0);
    }
  }
}

void loop() {
  randomSayi = random(1,5);
  copAra(randomSayi);
}
