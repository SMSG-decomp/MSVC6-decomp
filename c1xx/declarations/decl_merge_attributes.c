void __thiscall decl_merge_attributes(c1_declarator *d,c1_symbol *sym)

{
  byte bVar1;
  uint uVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  c1_symbol *sym_00;
  c1_symbol *pcVar6;
  void *value;
  c1_symbol *pcVar7;
  byte bVar8;
  char changed;
  c1_type *pcVar9;
  byte bVar10;
  
  sym_00 = sym;
  bVar8 = d->spec[3] & 1;
  if ((sym->flags23 & 1) == 0) {
    if (bVar8 != 0) {
      value = *(void **)(d->spec + 4);
      if (value == (void *)0x0) {
        sym->flags23 = sym->flags23 & 0xfe;
      }
      else {
LAB_10479e2b:
        sym_set_segment(sym,value);
      }
    }
  }
  else if ((bVar8 != 0) &&
          (pcVar7 = *(c1_symbol **)(d->spec + 4), pcVar6 = sym_segment_record(sym), pcVar6 != pcVar7
          )) {
    value = *(void **)(d->spec + 4);
    if (value != (void *)0x0) goto LAB_10479e2b;
    sym->flags23 = sym->flags23 & 0xfe;
  }
  pcVar9 = d->type;
  if ((char)pcVar9->code < '\0') {
    switch(pcVar9->code & 0x8f) {
    case 0x81:
    case 0x85:
      if ((((sym->flags1 & 4) != 0) && (-1 < g_class_depth)) &&
         (g_scope_vector->entries[(short)sym->scope_index] == g_class_def_stack[g_class_depth].cls))
      {
        diag_error(0x217,sym);
      }
      if ((d->flags54 & 8) != 0) {
        if ((sym->flags2 & 4) == 0) {
          sym->flags2 = sym->flags2 | 4;
        }
        else if ((sym->flags3 & 4) == 0) {
          diag_error(0x54,sym);
          sym->flags3 = sym->flags3 | 4;
        }
      }
      break;
    case 0x83:
      if (((pcVar9->extra).cls != (c1_symbol *)0x0) && ((sym->type->extra).cls == (c1_symbol *)0x0))
      {
        decl_check_linkage_consistency(pcVar9,0xfe,d,sym);
        return;
      }
      break;
    case 0x84:
    case 0x86:
    case 0x8e:
      decl_check_default_argument_redefinition
                ((pcVar9->base->extra).params,(sym->type->base->extra).params,sym,1);
    }
  }
  if ((-1 < g_class_depth) || ((g_compile_flags_c4 & 0x200) != 0)) goto LAB_1041056c;
  bVar8 = sym->flags1;
  bVar1 = d->flags54;
  if ((bVar8 & 2) == 0) {
    if ((bVar1 & 2) == 0) {
      if (((bVar8 & 1) == 0) && ((bVar1 & 1) != 0)) {
        diag_warning(4,0x1fb);
      }
      goto LAB_1041056c;
    }
    bVar10 = sym->kind & 0x1f;
    if (((bVar10 == 7) || (bVar10 == 8)) && ((sym->tail).fn.special_kind == '\0')) {
      pcVar7 = d->sym;
      if (pcVar7 == (c1_symbol *)0x0) {
        pcVar7 = sym_new_from_declarator(d,5);
      }
      diag_error(0x2dc,pcVar7);
      goto LAB_1041056c;
    }
  }
  else if ((bVar1 & 1) != 0) {
    pcVar7 = d->sym;
    if (pcVar7 == (c1_symbol *)0x0) {
      pcVar7 = sym_new_from_declarator(d,5);
    }
    diag_error(0x2dc,pcVar7);
    goto LAB_1041056c;
  }
  d->flags54 = (bVar1 ^ bVar8) & 3 ^ bVar1;
LAB_1041056c:
  if (((sym->flags22 & 4) == 0) || ((d->spec[2] & 8) == 0)) {
    if ((((sym->flags22 & 8) != 0) && (((d->spec[2] & 8) == 0 && ((d->spec[0] & 7) != 3)))) &&
       ((d->spec[1] & 1) == 0)) {
      decl_merge_attributes_fragment(d,sym,0x200);
      return;
    }
  }
  else {
    diag_warning(1,0x111,sym);
    if ((sym->flags1 & 4) == 0) {
      sym->storage = sym->storage & 0xf8 ^ 1;
    }
    bVar8 = sym->flags22 & 0xf7;
    sym->flags22 = bVar8;
    sym->flags22 = bVar8 | 4;
  }
  if (((sym->storage & 7) == 1) && ((d->spec[0] & 7) != 1)) {
    if ((sym->flags21 & 0x10) != 0) {
      d->spec[1] = d->spec[1] | 0x10;
    }
    bVar8 = (sym->flags22 ^ d->spec[2]) & 4 ^ d->spec[2];
    d->spec[2] = bVar8;
    d->spec[2] = (sym->flags22 ^ bVar8) & 8 ^ bVar8;
    pcVar9 = d->type;
    while ((bVar8 = (byte)pcVar9->code, (bVar8 & 0x8f) == 0x83 || ((bVar8 & 0x83) == 0x81))) {
      pcVar9 = pcVar9->base;
    }
    if (((byte)pcVar9->flags >> 5 & 1) != 0) {
      d->spec[0] = d->spec[0] & 0xfa | 2;
      bVar8 = d->spec[0];
      d->spec[1] = d->spec[1] | 0x10;
      d->spec[0] = bVar8 & 0xdf;
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
  sym._2_1_ = (byte)(uVar2 >> 0x10);
  if (((uVar2 & 0x400000) != 0) && ((sym_00->flags22 & 0x40) == 0)) {
    changed = '\x01';
    sym_00->flags22 = sym_00->flags22 | 0x40;
  }
  if (((uVar2 & 0x1000) != 0) && ((sym_00->flags21 & 0x10) == 0)) {
    changed = '\x01';
    sym_00->flags21 = sym_00->flags21 | 0x10;
  }
  if (((uVar2 & 0x200) != 0) && ((sym_00->flags21 & 2) == 0)) {
    changed = '\x01';
    sym_00->flags21 = sym_00->flags21 | 2;
  }
  if (((uVar2 & 0x10000) != 0) && ((sym_00->flags22 & 1) == 0)) {
    changed = '\x01';
    sym_00->flags22 = sym_00->flags22 | 1;
  }
  bVar8 = sym_00->flags22;
  sym._3_1_ = (byte)(uVar2 >> 0x18);
  if (((sym._2_1_ ^ bVar8) & 0xc) != 0) {
    if ((uVar2 & 0x40000) == 0) {
      if ((uVar2 & 0x80000) != 0) {
        decl_merge_attributes_fragment2(bVar8,changed,sym_00,sym._3_1_);
        return;
      }
    }
    else {
      sym_00->flags22 = bVar8 & 0xf7 | 4;
      changed = '\x01';
    }
  }
  if (((uVar2 & 0x10000000) != 0) && ((sym_00->flags23 & 0x10) == 0)) {
    decl_merge_attributes_tail_thread(sym_00->flags23,sym_00);
    return;
  }
  if (changed != '\0') {
    sym_00->flags2 = sym_00->flags2 & 0xf7;
  }
  return;
}

