void __thiscall
decl_check_linkage_consistency(c1_type *new_type,byte flags5_mask,c1_declarator *d,c1_symbol *sym)

{
  byte bVar1;
  uint uVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  c1_symbol *pcVar6;
  byte bVar7;
  char changed;
  c1_type *pcVar8;
  byte bVar9;
  byte bStack00000016;
  
  sym->type = new_type;
  sym->flags5 = sym->flags5 & flags5_mask;
  if ((-1 < g_class_depth) || ((g_compile_flags_c4 & 0x200) != 0)) goto LAB_1041056c;
  bVar7 = sym->flags1;
  bVar1 = d->flags54;
  if ((bVar7 & 2) == 0) {
    if ((bVar1 & 2) == 0) {
      if (((bVar7 & 1) == 0) && ((bVar1 & 1) != 0)) {
        diag_warning(4,0x1fb);
      }
      goto LAB_1041056c;
    }
    bVar9 = sym->kind & 0x1f;
    if (((bVar9 == 7) || (bVar9 == 8)) && ((sym->tail).fn.special_kind == '\0')) {
      pcVar6 = d->sym;
      if (pcVar6 == (c1_symbol *)0x0) {
        pcVar6 = sym_new_from_declarator(d,5);
      }
      diag_error(0x2dc,pcVar6);
      goto LAB_1041056c;
    }
  }
  else if ((bVar1 & 1) != 0) {
    pcVar6 = d->sym;
    if (pcVar6 == (c1_symbol *)0x0) {
      pcVar6 = sym_new_from_declarator(d,5);
    }
    diag_error(0x2dc,pcVar6);
    goto LAB_1041056c;
  }
  d->flags54 = (bVar1 ^ bVar7) & 3 ^ bVar1;
LAB_1041056c:
  if (((sym->flags22 & 4) == 0) || ((d->spec[2] & 8) == 0)) {
    if (((sym->flags22 & 8) != 0) &&
       ((((d->spec[2] & 8) == 0 && ((d->spec[0] & 7) != 3)) && ((d->spec[1] & 1) == 0)))) {
      decl_merge_attributes_fragment(d,sym,0x200);
      return;
    }
  }
  else {
    diag_warning(1,0x111,sym);
    if ((sym->flags1 & 4) == 0) {
      sym->storage = sym->storage & 0xf8 ^ 1;
    }
    bVar7 = sym->flags22 & 0xf7;
    sym->flags22 = bVar7;
    sym->flags22 = bVar7 | 4;
  }
  if (((sym->storage & 7) == 1) && ((d->spec[0] & 7) != 1)) {
    if ((sym->flags21 & 0x10) != 0) {
      d->spec[1] = d->spec[1] | 0x10;
    }
    bVar7 = (sym->flags22 ^ d->spec[2]) & 4 ^ d->spec[2];
    d->spec[2] = bVar7;
    d->spec[2] = (sym->flags22 ^ bVar7) & 8 ^ bVar7;
    pcVar8 = d->type;
    while ((bVar7 = (byte)pcVar8->code, (bVar7 & 0x8f) == 0x83 || ((bVar7 & 0x83) == 0x81))) {
      pcVar8 = pcVar8->base;
    }
    if (((byte)pcVar8->flags >> 5 & 1) != 0) {
      d->spec[0] = d->spec[0] & 0xfa | 2;
      bVar7 = d->spec[0];
      d->spec[1] = d->spec[1] | 0x10;
      d->spec[0] = bVar7 & 0xdf;
    }
    cVar3 = d->spec[1];
    cVar4 = d->spec[2];
    cVar5 = d->spec[3];
    sym->storage = d->spec[0];
    sym->flags21 = cVar3;
    sym->flags22 = cVar4;
    sym->flags23 = cVar5;
  }
  if ((d->flags54 & 8) != 0) {
    sym->flags2 = sym->flags2 | 4;
  }
  if ((d->flags54 & 4) != 0) {
    sym->flags4 = sym->flags4 | 4;
  }
  uVar2 = *(uint *)d->spec;
  changed = '\0';
  if (((uVar2 & 0x100) != 0) && ((sym->flags21 & 1) == 0)) {
    changed = '\x01';
    sym->flags21 = sym->flags21 | 1;
  }
  if (((uVar2 & 0x40) != 0) && ((sym->storage & 0x40) == 0)) {
    changed = '\x01';
    sym->storage = sym->storage | 0x40;
  }
  if (((uVar2 & 0x8000) != 0) && ((sym->flags21 & 0x80) == 0)) {
    changed = '\x01';
    sym->flags21 = sym->flags21 | 0x80;
  }
  bStack00000016 = (byte)(uVar2 >> 0x10);
  if (((uVar2 & 0x400000) != 0) && ((sym->flags22 & 0x40) == 0)) {
    changed = '\x01';
    sym->flags22 = sym->flags22 | 0x40;
  }
  if (((uVar2 & 0x1000) != 0) && ((sym->flags21 & 0x10) == 0)) {
    changed = '\x01';
    sym->flags21 = sym->flags21 | 0x10;
  }
  if (((uVar2 & 0x200) != 0) && ((sym->flags21 & 2) == 0)) {
    changed = '\x01';
    sym->flags21 = sym->flags21 | 2;
  }
  if (((uVar2 & 0x10000) != 0) && ((sym->flags22 & 1) == 0)) {
    changed = '\x01';
    sym->flags22 = sym->flags22 | 1;
  }
  bVar7 = sym->flags22;
  if (((bStack00000016 ^ bVar7) & 0xc) != 0) {
    if ((uVar2 & 0x40000) == 0) {
      if ((uVar2 & 0x80000) != 0) {
        decl_merge_attributes_fragment2(bVar7,changed,sym,(byte)(uVar2 >> 0x18));
        return;
      }
    }
    else {
      sym->flags22 = bVar7 & 0xf7 | 4;
      changed = '\x01';
    }
  }
  if (((uVar2 & 0x10000000) != 0) && ((sym->flags23 & 0x10) == 0)) {
    decl_merge_attributes_tail_thread(sym->flags23,sym);
    return;
  }
  if (changed != '\0') {
    sym->flags2 = sym->flags2 & 0xf7;
  }
  return;
}

