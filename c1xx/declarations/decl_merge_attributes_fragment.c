void __thiscall decl_merge_attributes_fragment(c1_declarator *d,c1_symbol *sym,uint c4_bit_200)

{
  uint uVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  byte bVar5;
  char changed;
  c1_type *pcVar6;
  byte bStack00000016;
  
  if ((((g_compile_flags_c4 & c4_bit_200) == 0) && ((d->flags54 & 0x40) == 0)) &&
     ((sym->flags3 & 4) == 0)) {
    diag_warning(1,0x111,sym);
    if ((sym->flags1 & 4) == 0) {
      sym->storage = sym->storage & 0xf8 ^ 1;
    }
    bVar5 = sym->flags22 & 0xf7;
    sym->flags22 = bVar5;
    sym->flags22 = bVar5 | 4;
  }
  if (((sym->storage & 7) == 1) && ((d->spec[0] & 7) != 1)) {
    if ((sym->flags21 & 0x10) != 0) {
      d->spec[1] = d->spec[1] | 0x10;
    }
    bVar5 = (sym->flags22 ^ d->spec[2]) & 4 ^ d->spec[2];
    d->spec[2] = bVar5;
    d->spec[2] = (sym->flags22 ^ bVar5) & 8 ^ bVar5;
    pcVar6 = d->type;
    while ((bVar5 = (byte)pcVar6->code, (bVar5 & 0x8f) == 0x83 || ((bVar5 & 0x83) == 0x81))) {
      pcVar6 = pcVar6->base;
    }
    if (((byte)pcVar6->flags >> 5 & 1) != 0) {
      d->spec[0] = d->spec[0] & 0xfa | 2;
      bVar5 = d->spec[0];
      d->spec[1] = d->spec[1] | 0x10;
      d->spec[0] = bVar5 & 0xdf;
    }
    cVar2 = d->spec[1];
    cVar3 = d->spec[2];
    cVar4 = d->spec[3];
    sym->storage = d->spec[0];
    sym->flags21 = cVar2;
    sym->flags22 = cVar3;
    sym->flags23 = cVar4;
  }
  if ((d->flags54 & 8) != 0) {
    sym->flags2 = sym->flags2 | 4;
  }
  if ((d->flags54 & 4) != 0) {
    sym->flags4 = sym->flags4 | 4;
  }
  uVar1 = *(uint *)d->spec;
  changed = '\0';
  if (((uVar1 & 0x100) != 0) && ((sym->flags21 & 1) == 0)) {
    changed = '\x01';
    sym->flags21 = sym->flags21 | 1;
  }
  if (((uVar1 & 0x40) != 0) && ((sym->storage & 0x40) == 0)) {
    changed = '\x01';
    sym->storage = sym->storage | 0x40;
  }
  if (((uVar1 & 0x8000) != 0) && ((sym->flags21 & 0x80) == 0)) {
    changed = '\x01';
    sym->flags21 = sym->flags21 | 0x80;
  }
  bStack00000016 = (byte)(uVar1 >> 0x10);
  if (((uVar1 & 0x400000) != 0) && ((sym->flags22 & 0x40) == 0)) {
    changed = '\x01';
    sym->flags22 = sym->flags22 | 0x40;
  }
  if (((uVar1 & 0x1000) != 0) && ((sym->flags21 & 0x10) == 0)) {
    changed = '\x01';
    sym->flags21 = sym->flags21 | 0x10;
  }
  if (((uVar1 & 0x200) != 0) && ((sym->flags21 & 2) == 0)) {
    changed = '\x01';
    sym->flags21 = sym->flags21 | 2;
  }
  if (((uVar1 & 0x10000) != 0) && ((sym->flags22 & 1) == 0)) {
    changed = '\x01';
    sym->flags22 = sym->flags22 | 1;
  }
  bVar5 = sym->flags22;
  if (((bStack00000016 ^ bVar5) & 0xc) != 0) {
    if ((uVar1 & 0x40000) == 0) {
      if ((uVar1 & 0x80000) != 0) {
        decl_merge_attributes_fragment2(bVar5,changed,sym,(byte)(uVar1 >> 0x18));
        return;
      }
    }
    else {
      sym->flags22 = bVar5 & 0xf7 | 4;
      changed = '\x01';
    }
  }
  if (((uVar1 & 0x10000000) != 0) && ((sym->flags23 & 0x10) == 0)) {
    decl_merge_attributes_tail_thread(sym->flags23,sym);
    return;
  }
  if (changed != '\0') {
    sym->flags2 = sym->flags2 & 0xf7;
  }
  return;
}

