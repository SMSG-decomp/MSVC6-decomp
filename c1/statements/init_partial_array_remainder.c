int init_partial_array_remainder(void)

{
  c1_symbol *pcVar1;
  c1_type *type;
  byte *pbVar2;
  c1_type *pcVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  char has_member;
  int *local_4;
  
  pcVar1 = g_init_level->cursor;
  if (g_init_brace_depth < 0) {
    return 0;
  }
  type = pcVar1->type;
  bVar4 = (byte)type->code;
  pcVar3 = type;
  if ((bVar4 & 0x8f) == 0x83) {
    if ((type->extra).count != 0) {
      iVar5 = type_size_derived(type);
      return iVar5 * ((type->extra).count - g_init_level->count);
    }
    return 0;
  }
  while ((char)bVar4 < '\0') {
    bVar4 = (byte)pcVar3->base->code;
    pcVar3 = pcVar3->base;
  }
  if ((pcVar3->code & 0x200) == 0) {
    iVar5 = type_size(type);
    return iVar5;
  }
  if (g_init_bitfield_unit_open != 0) {
    g_constant_value = g_init_bitfield_value;
    g_constant_value_high = g_init_bitfield_value_high;
    init_finish_array(*(int *)((int)pcVar1->tag_members + 4) + -8);
  }
  iVar5 = 0;
  iVar9 = 0;
  if (pcVar1->tag_members == (void *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = *(int **)((int)pcVar1->tag_members + 4);
  }
  has_member = piVar7 != (int *)0x0;
  for (; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[1]) {
    bVar4 = *(byte *)(piVar7 + -2) & 0x1f;
    local_4 = piVar7;
    if (bVar4 == 0) {
LAB_10621b66:
      if (iVar9 < 1) {
        if (bVar4 == 2) {
          for (piVar8 = init_next_member_shares_unit(piVar7[7],(int *)piVar7[1],&has_member);
              piVar8 != (int *)0x0;
              piVar8 = init_next_member_shares_unit(local_4[7],(int *)piVar8[1],&has_member)) {
            if (local_4 != (int *)0x0) {
              local_4 = (int *)local_4[1];
            }
            piVar7 = local_4;
          }
          if (g_init_bitfield_unit_open == 0) {
            pbVar2 = (byte *)piVar7[3];
            bVar4 = *pbVar2;
            while ((char)bVar4 < '\0') {
              pbVar2 = *(byte **)(pbVar2 + 4);
              bVar4 = *pbVar2;
            }
            iVar6 = (int)(char)(&g_type_rank_table)[*pbVar2 & 0xf];
          }
          else {
            g_init_bitfield_unit_open = 0;
            iVar6 = 0;
          }
        }
        else if ((void *)*piVar7 == g_name_alignment_member) {
          iVar6 = piVar7[7];
        }
        else {
          iVar6 = type_size((c1_type *)piVar7[3]);
        }
LAB_10621b8f:
        iVar5 = iVar5 + iVar6;
        piVar7 = local_4;
      }
    }
    else if (((bVar4 < 0xf) && (bVar4 != 5)) && ((*(byte *)(piVar7 + -1) & 8) != 0)) {
      iVar9 = iVar9 + 1;
      if (iVar9 < 2) {
        iVar6 = type_size((c1_type *)piVar7[3]);
        goto LAB_10621b8f;
      }
    }
    else {
      if (((bVar4 == 0) || (0xe < bVar4)) ||
         ((bVar4 == 5 || ((*(byte *)(piVar7 + -1) & 0x10) == 0)))) goto LAB_10621b66;
      iVar9 = iVar9 + -1;
      if (iVar9 < 0) break;
    }
    if (piVar7 == (int *)0x0) break;
  }
  pcVar1->tag_members = (void *)0x0;
  g_init_bitfield_unit_open = 0;
  return iVar5;
}

