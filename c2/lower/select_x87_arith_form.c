void __fastcall select_x87_arith_form(c2_tuple *t,int reverse,int pop)

{
  switch(t->op) {
  case 0x45:
    if (pop != 0) {
      t->op = 0x4b;
      return;
    }
    break;
  case 0x46:
    if (pop != 0) {
      t->op = 0x4c;
      return;
    }
    break;
  case 0x47:
    if (pop == 0) {
      if (reverse != 0) {
        t->op = 0x48;
        return;
      }
    }
    else {
      t->op = 0x4e - (reverse != 0);
    }
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lowerflt.c",0x12d);
  case 0x49:
    if (pop != 0) {
      t->op = 0x50 - (reverse != 0);
      return;
    }
    if (reverse != 0) {
      t->op = 0x4a;
      return;
    }
  }
  return;
}

