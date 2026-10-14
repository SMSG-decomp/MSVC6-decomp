uint8_t __fastcall x86_fixed_reg_class(c2_tuple *t)

{
  uint uVar1;
  
  uVar1 = t->op;
  if (uVar1 < 0x124) {
    if (uVar1 == 0x123) {
      return '\b';
    }
    if (uVar1 < 0x121) {
      if (uVar1 == 0x120) {
        return '\x01';
      }
      if (uVar1 == 0xf) goto switchD_107136a7_caseD_185;
      if (uVar1 == 0x11e) {
        return '\a';
      }
      if (uVar1 == 0x11f) {
        return '\n';
      }
    }
    else {
      if (uVar1 == 0x121) {
        return '\x02';
      }
      if (uVar1 == 0x122) {
        return '\t';
      }
    }
  }
  else {
    switch(uVar1) {
    case 0x128:
      return '\x03';
    case 0x129:
      return '\x06';
    case 0x12a:
      return '\x05';
    case 299:
      return '\x04';
    case 0x185:
switchD_107136a7_caseD_185:
      return (uint8_t)t->type;
    case 399:
      return (t->u20).cc;
    }
  }
  return '\0';
}

