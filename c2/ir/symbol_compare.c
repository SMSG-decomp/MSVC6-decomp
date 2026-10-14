int __fastcall symbol_compare(c2_symbol *a,c2_symbol *b)

{
  uint8_t uVar1;
  uint16_t b_00;
  uint16_t a_00;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (a == b) {
    return 0;
  }
  if (a != (c2_symbol *)0x0) {
    if (b == (c2_symbol *)0x0) {
      return 1;
    }
    uVar1 = b->cls;
    if (a->cls == '\x03') {
      if (uVar1 == '\x03') {
        return (-(uint)(a->id < b->id) & 0xfffffffe) + 1;
      }
    }
    else {
      if (uVar1 == '\x03') {
        return 1;
      }
      if ((a->cls != '\x06') && (uVar1 != '\x06')) {
        if (a->offset != b->offset) {
          return ((b->offset <= a->offset) - 1 & 0xfffffffe) + 1;
        }
        if (a->size != b->size) {
          return ((b->size <= a->size) - 1 & 0xfffffffe) + 1;
        }
        b_00 = b->type;
        a_00 = a->type;
        iVar4 = types_compatible(a_00,b_00);
        if (iVar4 == 0) {
          return (-(uint)(a_00 < b_00) & 0xfffffffe) + 1;
        }
        uVar2 = a->storage->fe->id;
        uVar3 = b->storage->fe->id;
        if (uVar2 == uVar3) {
          return 0;
        }
        return (-(uint)(uVar2 < uVar3) & 0xfffffffe) + 1;
      }
    }
  }
  return -1;
}

