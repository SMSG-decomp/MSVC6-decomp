void __cdecl zg_write_function_prototype(c1_symbol *sym,FILE *out)

{
  byte bVar1;
  char cVar2;
  int handle;
  char *_Str;
  void *spec1;
  uint uVar3;
  char *pcVar4;
  uint local_c;
  uint local_4;
  
  if (sym == (c1_symbol *)0x0) {
    return;
  }
  g_zg_unnamed_tag_keyword = (char *)0x0;
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 == 7) || (bVar1 == 8)) {
    g_format_parameter_names = 1;
  }
  else {
    g_format_parameter_names = 0;
  }
  handle = format_declaration_text(sym,(c1_type *)0x0);
  _Str = format_buffer_text(handle);
  if (g_zg_unnamed_tag_keyword != (char *)0x0) {
    fwrite("/* ",3,1,out);
    uVar3 = 0xffffffff;
    pcVar4 = _Str;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    fwrite(_Str,~uVar3 - 1,1,out);
    fwrite("; */\n",5,1,out);
    diag_warning(1,0x24,g_zg_unnamed_tag_keyword);
    return;
  }
  local_c._0_1_ = sym->storage;
  local_c._1_1_ = sym->flags21;
  local_c._2_1_ = sym->flags22;
  local_c._3_1_ = sym->flags23;
  if (((sym->flags23 & 1) == 0) || (spec1 = sym_segment_record(sym), spec1 == (void *)0x0)) {
    spec1 = (void *)0x0;
    local_c = local_c & 0xfeffffff;
  }
  else {
    local_c = local_c | 0x1000000;
  }
  bVar1 = sym->kind & 0x1f;
  if ((((bVar1 == 7) || (bVar1 == 8)) || (bVar1 == 6)) && (((sym->x2c).function_flags & 1) != 0)) {
    cVar2 = '\x01';
  }
  else {
    cVar2 = '\0';
  }
  local_4 = CONCAT31(local_4._1_3_,cVar2 << 1 | (byte)local_4 & 0xfc);
  format_storage_class_to_file(local_c,(uint)spec1,local_4,out);
  uVar3 = 0xffffffff;
  pcVar4 = _Str;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  fwrite(_Str,~uVar3 - 1,1,out);
  fwrite(";\n",2,1,out);
  return;
}

