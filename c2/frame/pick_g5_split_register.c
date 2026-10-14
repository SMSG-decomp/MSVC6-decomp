int __fastcall pick_g5_split_register(c2_bitset *busy,int byte_only)

{
  uint32_t *puVar1;
  uint n;
  uint32_t uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint32_t *puVar6;
  int iVar7;
  
  iVar5 = 0;
  uVar3 = g_g5_split_cursor;
  iVar7 = g_local_register_order_len;
  do {
    if (iVar5 == 0) {
      uVar4 = (iVar7 <= (int)(uVar3 + 1)) - 1 & uVar3 + 1;
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 != uVar3) {
      do {
        n = g_local_register_order[uVar4];
        if ((((n != 0) && (((g_reg_symbols[n].flags5 & 0x10) != 0 || (iVar5 != 0)))) &&
            ((byte_only == 0 || (n < 5)))) &&
           (uVar2 = bitset_test(busy,n), uVar3 = g_g5_split_cursor,
           iVar7 = g_local_register_order_len, uVar2 == 0)) {
          g_g5_split_cursor = uVar4;
          return g_local_register_order[uVar4];
        }
        uVar4 = (iVar7 <= (int)(uVar4 + 1)) - 1 & uVar4 + 1;
      } while (uVar4 != uVar3);
    }
    iVar5 = iVar5 + 1;
    if (1 < iVar5) {
      iVar7 = 0;
      if (g_local_register_order[0] == 0) {
        return 0;
      }
      puVar6 = g_local_register_order;
      while (((byte_only != 0 && (4 < *puVar6)) || (uVar2 = bitset_test(busy,*puVar6), uVar2 != 0)))
      {
        puVar1 = puVar6 + 1;
        puVar6 = puVar6 + 1;
        iVar7 = iVar7 + 1;
        if (*puVar1 == 0) {
          return 0;
        }
      }
      g_g5_split_cursor = iVar7;
      return g_local_register_order[iVar7];
    }
  } while( true );
}

