void cv_emit_objname_record(void)

{
  char cVar1;
  char *name;
  uint uVar2;
  char *pcVar3;
  short local_23c [2];
  uint32_t local_238;
  uint8_t local_234 [300];
  char local_108 [264];
  
  name = _fullpath(local_108,g_opt_object_path,0x105);
  if (name == (char *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\emit.c",0x836);
  }
  if (g_opt_brepro != 0) {
    name = g_opt_object_path;
  }
  uVar2 = 0xffffffff;
  pcVar3 = name;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  local_238 = g_pch_signature;
  local_23c[0] = (short)uVar2 + 6;
  local_23c[1] = 9;
  cv_put_name(local_234,name);
  (*g_hook_pad_section)(g_debug_symbols_section);
  (*g_writer_write_bytes_hook)(local_23c,uVar2 + 8);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + uVar2 + 8;
  return;
}

