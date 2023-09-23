void fwd() {
  motor(sphigh);
  axis.write(m);
}

void bwd() {
  motor(-sphigh);
  axis.write(m);
}

void rt() {
  axis.write(r);
}

void lt() {
  axis.write(l);
}

void ltfwd() {
  axis.write(l);
  motor(sphigh);
}

void rtfwd() {
  axis.write(r);
  motor(sphigh);
}

void ltbwd() {
  axis.write(lb);
  motor(-sphigh);
}

void rtbwd() {
  axis.write(rb);
  motor(-sphigh);
}

void stp() {
  motor(0);
  axis.write(m);
}
