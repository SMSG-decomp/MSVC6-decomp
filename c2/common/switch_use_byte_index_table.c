int __fastcall switch_use_byte_index_table(c2_node *node)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)node[2].op;
  iVar3 = 0;
  piVar2 = piVar1;
  if (piVar1 != (int *)0x0) {
    do {
      node = (c2_node *)piVar2[4];
      piVar2 = (int *)*piVar2;
      iVar3 = iVar3 + 1;
    } while (piVar2 != (int *)0x0);
    if (0xff < iVar3) {
      return 0;
    }
  }
  if (((int)node + (1 - piVar1[3])) * 3 <= (int)((g_opt_favor_speed != 0) + 0xb + iVar3 * 4)) {
    return 0;
  }
  return 1;
}

