void read_global_il_header(void)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = false;
  g_il_stream = g_glo_il_file;
  iVar3 = il_read_byte();
  if ((char)iVar3 != '\x11') {
    fatal_error(900,"P1",0,"P2",0x130ba96);
  }
  uVar2 = il_read_u16();
  if ((uVar2 != 0x2386) && (uVar2 != 0x386)) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x3da);
  }
  uVar4 = il_read_u32();
  if ((int)uVar4 < 0x130937e) {
    if (uVar4 != 0x130937d) {
      if (0x1309260 < (int)uVar4) {
        if (uVar4 != 0x1309261) goto LAB_107835cb;
        goto LAB_107835ec;
      }
      if (uVar4 == 0x1309260) goto LAB_1078362e;
      if (uVar4 != 0x1302051) {
        if (uVar4 != 0x13045cb) goto LAB_107835cb;
        goto LAB_1078361d;
      }
    }
    g_pdb_il_mode = 0;
    g_il_wide_type_index = 0;
  }
  else {
    if (0x1309380 < (int)uVar4) {
      if (uVar4 != 0x130ba96) {
LAB_107835cb:
        fatal_error(900,"P1",uVar4,"P2",0x130ba96);
      }
      g_pdb_il_mode = 0;
      g_il_wide_type_index = 0;
      bVar1 = true;
      g_inasm_wide_opcodes = 1;
      goto LAB_10757dbd;
    }
    if (uVar4 != 0x1309380) {
      if (uVar4 != 0x130937e) {
        if (uVar4 != 0x130937f) goto LAB_107835cb;
LAB_1078361d:
        g_pdb_il_mode = 1;
        g_il_wide_type_index = 0;
        goto LAB_10757dbd;
      }
LAB_1078362e:
      g_pdb_il_mode = 0;
      g_il_wide_type_index = 1;
      goto LAB_10757dbd;
    }
LAB_107835ec:
    g_pdb_il_mode = 1;
    g_il_wide_type_index = 1;
  }
LAB_10757dbd:
  g_frontend_id_limit = il_read_u32();
  g_next_fe_id = g_frontend_id_limit;
  iVar3 = il_read_byte();
  g_il_language = (int)(char)iVar3;
  if (bVar1) {
    uVar4 = il_read_u32();
    if ((uVar4 & 1) != 0) {
      g_pdb_il_mode = 1;
    }
    if ((uVar4 & 2) != 0) {
      g_il_wide_type_index = 1;
    }
    if ((uVar4 & 4) != 0) {
      g_il_has_cormeta = 1;
    }
    if ((uVar4 & 8) != 0) {
      g_opt_dlp = 1;
    }
    g_il_fe_version_major = il_read_short();
    g_il_fe_version_minor = il_read_short();
    g_il_fe_version_build = il_read_short();
  }
  else {
    g_il_language = -(uint)(g_opt_basic != 0) & 5;
  }
  if (g_pdb_il_mode != 0) {
    iVar3 = pdb_open(g_opt_pdb_path,g_opt_object_path);
    if (iVar3 == 0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x443);
    }
  }
  return;
}

