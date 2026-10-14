uint16_t * __fastcall intrinsic_param_types(uint32_t id)

{
  uint16_t uVar1;
  c2_intrinsic_param_row *pcVar2;
  int iVar3;
  
  if ((g_intrinsic_desc[id].flags & 0x10) == 0) {
    uVar1 = g_intrinsic_desc[id].param_type;
    if (uVar1 != g_intrinsic_uniform_param_types[0]) {
      g_intrinsic_uniform_param_types[1] = uVar1;
      g_intrinsic_uniform_param_types[0] = uVar1;
      g_intrinsic_uniform_param_types._4_4_ = g_intrinsic_uniform_param_types._0_4_;
      g_intrinsic_uniform_param_types[4] = uVar1;
    }
    return g_intrinsic_uniform_param_types;
  }
  uVar1 = 0xa9;
  iVar3 = 0;
  pcVar2 = g_intrinsic_param_type_table;
  do {
    if ((int)(short)uVar1 == id) break;
    uVar1 = pcVar2[1].id;
    pcVar2 = pcVar2 + 1;
    iVar3 = iVar3 + 1;
  } while (uVar1 != 0);
  if ((int)(short)g_intrinsic_param_type_table[iVar3].id == id) {
    return g_intrinsic_param_type_table[iVar3].types;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\misc.c",0x27d);
}

