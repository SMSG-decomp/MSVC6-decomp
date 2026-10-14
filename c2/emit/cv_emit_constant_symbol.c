void __fastcall cv_emit_constant_symbol(c2_fe_symbol *s)

{
  char cVar1;
  uint16_t uVar2;
  int32_t *piVar3;
  char *name;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint8_t *out;
  char *pcVar7;
  int32_t value;
  uint16_t reclen;
  uint16_t rectyp;
  uint32_t typind;
  uint8_t leaf_and_name [300];
  
  uVar2 = (s->u44).length;
  piVar3 = *(int32_t **)((int)&(s->u3e).label_flags + 2);
  if (uVar2 == 1) {
    value = (int32_t)(char)*piVar3;
  }
  else if (uVar2 == 2) {
    value = (int32_t)(short)*piVar3;
  }
  else {
    if (uVar2 != 4) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\emit.c",0x72c);
    }
    value = *piVar3;
  }
  name = fe_symbol_name(s,0);
  uVar5 = 0xffffffff;
  pcVar7 = name;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  reclen = 0;
  iVar6 = ~uVar5 - 1;
  rectyp = (-(ushort)(g_il_wide_type_index != 0) & 0xfff) + 3;
  if (g_il_wide_type_index == 0) {
    out = (uint8_t *)((int)&typind + 2);
    typind = CONCAT22(typind._2_2_,(short)s->cv_type_index);
  }
  else {
    typind = s->cv_type_index;
    out = leaf_and_name;
  }
  iVar4 = cv_put_numeric_leaf(out,value);
  cv_put_name(out + iVar4,name);
  if (0xff < iVar6) {
    iVar6 = 0xff;
  }
  iVar4 = (-(uint)(g_il_wide_type_index != 0) & 2) + iVar6 + 5 + iVar4;
  reclen = (uint16_t)iVar4;
  (*g_hook_pad_section)(g_debug_symbols_section);
  (*g_writer_write_bytes_hook)(&reclen,iVar4 + 2);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + iVar4 + 2;
  return;
}

