char readhexpad(){
 int value = analogRead(pad);
 Serial.println(value);
 int t[16] = {1077,832,334,190,1974,1828,1535, 1265, 2559, 2404,2224,2065,2915,2857,2701,3603};
 char k[16] = {'1','2','3','A','4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0','#','D'};
 char ans;
 Serial.println("reading hexpad");
 Serial.println(value);
23
 for(int i=0; i<16; i++){
 if(abs(value
-t[i])<60){
 ans=k[i];

}
 Serial.println(ans);

}
 return ans;

}
