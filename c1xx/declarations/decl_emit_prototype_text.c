void __cdecl decl_emit_prototype_text(c1_symbol *fn,FILE *out)

{
  c1_symbol_attrs attrs;
  byte bVar1;
  byte bVar2;
  char cVar3;
  size_t _Size;
  char *_Str;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint in_stack_ffffffbc;
  undefined4 in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  char *pcVar8;
  c1_symbol *pcVar9;
  FILE *out_00;
  uint local_18;
  c1_symbol *local_14;
  void *local_10;
  void *local_c;
  int local_8;
  byte local_4;
  
  if (fn == (c1_symbol *)0x0) {
    return;
  }
  g_prototype_unnamed_tag_keyword = (char *)0x0;
  bVar1 = fn->kind & 0x1f;
  if ((bVar1 == 7) || (bVar1 == 8)) {
    g_format_params_with_names = 1;
  }
  else {
    g_format_params_with_names = 0;
  }
  pcVar9 = fn;
  _Size = format_symbol_declaration_text(fn,(c1_type *)0x0);
  pcVar8 = (char *)0x10483e2c;
  _Str = format_buffer_text(_Size);
  if (g_prototype_unnamed_tag_keyword != (char *)0x0) {
    fwrite("/* ",3,1,(FILE *)out);
    uVar4 = 0xffffffff;
    pcVar8 = _Str;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar3 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar3 != '\0');
    fwrite(_Str,~uVar4 - 1,1,(FILE *)out);
    fwrite("; */\n",5,1,(FILE *)out);
    diag_warning(1,0x24,g_prototype_unnamed_tag_keyword);
    return;
  }
  if ((fn->flags1 & 2) != 0) {
    uVar4 = 0xffffffff;
    pcVar9 = (c1_symbol *)0x1;
    pcVar8 = "extern \"C\" ";
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar3 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar3 != '\0');
    _Size = ~uVar4 - 1;
    pcVar8 = "extern \"C\" ";
    in_stack_ffffffc4 = 0x10483eb9;
    fwrite("extern \"C\" ",_Size,1,(FILE *)out);
  }
  bVar1 = fn->kind & 0x1f;
  if ((((bVar1 == 7) || (bVar1 == 8)) || (bVar1 == 6)) &&
     (((bVar1 = fn->flags1, (bVar1 & 0x10) == 0x10 || ((bVar1 & 0x20) == 0x20)) ||
      ((bVar1 & 0x40) != 0)))) goto LAB_10484012;
  local_18._0_1_ = fn->storage;
  local_18._1_1_ = fn->flags21;
  local_18._2_1_ = fn->flags22;
  local_18._3_1_ = fn->flags23;
  if ((fn->flags23 & 1) == 0) {
LAB_10484052:
    local_14 = (c1_symbol *)0x0;
    local_18 = local_18 & 0xfeffffff;
  }
  else {
    pcVar9 = (c1_symbol *)0x10483f0d;
    local_14 = sym_segment_record(fn);
    if (local_14 == (c1_symbol *)0x0) goto LAB_10484052;
    local_18 = local_18 | 0x1000000;
  }
  if ((fn->flags21 & 0x40) == 0) {
LAB_10484065:
    local_c = (void *)0x0;
    local_18 = local_18 & 0xffffbfff;
  }
  else {
    pcVar9 = (c1_symbol *)0x10483f37;
    local_c = sym_extra_record(fn);
    if (local_c == (void *)0x0) goto LAB_10484065;
    local_18 = local_18 | 0x4000;
  }
  bVar1 = fn->kind & 0x1f;
  if (((bVar1 == 7) || (bVar1 == 8)) && ((*(byte *)((int)&fn->tail + 10) & 0x80) != 0)) {
    pcVar9 = (c1_symbol *)0x10483f71;
    local_8 = sym_list_1b58_value(fn);
    if (local_8 == 0) goto LAB_1048407c;
    bVar1 = local_4 | 1;
  }
  else {
LAB_1048407c:
    bVar1 = local_4 & 0xfe;
    local_8 = 0;
  }
  bVar2 = fn->kind & 0x1f;
  if ((((bVar2 == 7) || (bVar2 == 8)) || (bVar2 == 6)) &&
     ((*(byte *)((int)&fn->tail + 0xb) & 1) != 0)) {
    cVar3 = '\x01';
  }
  else {
    cVar3 = '\0';
  }
  if ((fn->flags23 & 0x80) == 0) {
    local_10 = (void *)0x0;
  }
  else {
    pcVar9 = (c1_symbol *)0x10483fc7;
    local_10 = symtab_1b40_lookup(fn);
  }
  if (((fn->kind & 0x1f) == 4) && ((((fn->detail).cls)->layout_flags3c & 0x80) != 0)) {
    bVar1 = cVar3 << 3 | bVar1 & 0xf7 | 2;
  }
  else {
    bVar1 = cVar3 << 3 | bVar1 & 0xf5;
  }
  local_4 = bVar1 & 0xfb;
  puVar6 = &local_18;
  puVar7 = (uint *)&stack0xffffffbc;
  out_00 = out;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  attrs.segment = (c1_symbol *)in_stack_ffffffc0;
  attrs.storage = (char)in_stack_ffffffbc;
  attrs.flags21 = (char)(in_stack_ffffffbc >> 8);
  attrs.flags22 = (char)(in_stack_ffffffbc >> 0x10);
  attrs.flags23 = (char)(in_stack_ffffffbc >> 0x18);
  attrs.declarator_record = (void *)in_stack_ffffffc4;
  attrs.declspec = pcVar8;
  attrs.earlier_entity = _Size;
  attrs._20_4_ = pcVar9;
  decl_emit_prototype_specifiers(attrs,out_00);
LAB_10484012:
  uVar4 = 0xffffffff;
  pcVar8 = _Str;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar3 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar3 != '\0');
  fwrite(_Str,~uVar4 - 1,1,(FILE *)out);
  if (out == (FILE *)(_iob_exref + 0x20)) {
    fwrite(";\n",2,1,(FILE *)out);
  }
  return;
}

