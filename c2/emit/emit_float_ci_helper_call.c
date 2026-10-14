c2_tuple * __fastcall emit_float_ci_helper_call(c2_tuple *t)

{
  char cVar1;
  ushort uVar2;
  char *pcVar3;
  c2_fe_symbol *fs;
  c2_operand *fn;
  c2_tuple *pcVar4;
  uint uVar5;
  uint uVar6;
  uint16_t uVar7;
  char *pcVar8;
  char *pcVar9;
  uint8_t flag;
  
  uVar2 = (t->u20).intrinsic.id;
  g_float_helper_name[0] = '_';
  g_float_helper_name[1] = '_';
  pcVar9 = g_intrinsic_desc[uVar2].helper_name;
  g_float_helper_name[3] = 'I';
  g_float_helper_name[2] = (-(g_opt_fortran_frontend != 0) & 3U) + 0x43;
  pcVar8 = g_float_helper_name + 4;
  pcVar3 = strchr(pcVar9,0xff);
  if (pcVar3 == (char *)0x0) {
    uVar5 = 0xffffffff;
    do {
      pcVar8 = pcVar9;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar9 = g_float_helper_name;
    pcVar8 = pcVar8 + -uVar5;
    for (uVar6 = uVar5 >> 2; pcVar9 = pcVar9 + 4, uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
    }
  }
  else {
    cVar1 = *pcVar9;
    if (g_opt_fortran_frontend != 0) {
      while (cVar1 != -1) {
        *pcVar8 = cVar1;
        pcVar3 = pcVar9 + 1;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
        cVar1 = *pcVar3;
      }
      *pcVar8 = '\0';
      goto LAB_1077184b;
    }
    while (cVar1 != -1) {
      pcVar8 = pcVar9 + 1;
      pcVar9 = pcVar9 + 1;
      cVar1 = *pcVar8;
    }
    uVar5 = 0xffffffff;
    pcVar9 = pcVar9 + 1;
    do {
      pcVar8 = pcVar9;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar9 = g_float_helper_name;
    pcVar8 = pcVar8 + -uVar5;
    for (uVar6 = uVar5 >> 2; pcVar9 = pcVar9 + 4, uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
    }
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  }
LAB_1077184b:
  uVar7 = 0;
  if (((t->type & 0xf000) == 0x4000) &&
     (uVar7 = (uint16_t)((g_intrinsic_desc[uVar2].x87_flags & 8) != 0),
     (g_intrinsic_desc[uVar2].x87_flags & 0x10) != 0)) {
    uVar7 = 2;
  }
  flag = '\x10';
  fs = fe_symbol_lookup_name(g_float_helper_name);
  fn = operand_for_symbol_ref(fs);
  pcVar4 = build_helper_call((c2_node *)t,0xe,fn,flag);
  (pcVar4->u24).call.x87_pops = uVar7;
  return pcVar4;
}

