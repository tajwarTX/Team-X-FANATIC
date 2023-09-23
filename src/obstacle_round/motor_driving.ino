void motor(int a) {
  if (a >= 0) {
    digitalWrite(right_motor_forward, 1);
    digitalWrite(right_motor_backward, 0);
  }
  else {
    a = -a;
    digitalWrite(right_motor_forward, 0);
    digitalWrite(right_motor_backward, 1);
  }
  analogWrite(right_motor_speed, a);
}
