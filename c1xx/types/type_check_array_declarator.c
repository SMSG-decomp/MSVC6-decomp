void __thiscall type_check_array_declarator(c1_decl_record *rec,c1_type *layer)

{
  ushort uVar1;
  c1xx_decl_specifiers *pcVar2;
  short n;
  uint name;
  
  if (rec->chain_head == (c1_type *)0x0) {
    return;
  }
  if ((layer->extra).cls != (c1_symbol *)0x0) goto LAB_1040b05a;
  uVar1 = rec->chain_tail->code & 0x8f;
  if (uVar1 == 0x83) {
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar2 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar2 = g_paren_level_declspecs + g_paren_depth;
    }
    if ((pcVar2->spec[3] & 0x80) != 0) {
      return;
    }
    if ((g_compile_flags_cc & 0x100000) == 0) {
      name = (uint)rec->sym;
      n = 0x57;
      goto LAB_104837b6;
    }
  }
  else {
    if (uVar1 != 0x80) goto LAB_1040b05a;
    name = (uint)rec->sym;
    n = 0x109;
LAB_104837b6:
    diag_error(n,name);
  }
  rec->flags = rec->flags | 1;
  (layer->extra).count = 1;
LAB_1040b05a:
  if ((rec->chain_tail->code & 0x83) == 0x81) {
    diag_error(0x5a,rec->sym);
    rec->flags = rec->flags | 1;
    layer->code = 0x82;
    (layer->extra).cls = (c1_symbol *)0x0;
  }
  if (((rec->chain_tail->code & 0x8f) == 0x80) && (layer->code == 0x4083)) {
    diag_error(0x10a,rec->sym);
    rec->flags = rec->flags | 1;
  }
  return;
}

