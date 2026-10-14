void __cdecl crc16_tables_init(void)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  byte bVar5;
  uint uVar6;
  int *piVar7;
  byte local_1;
  int iVar4;
  
  uVar1 = 0;
  do {
    uVar6 = 0;
    (&g_crc16_table_lo)[uVar1] = 0;
    (&g_crc16_table_hi)[uVar1] = 0;
    do {
      bVar5 = 0;
      local_1 = 0;
      piVar7 = g_crc16_feedback_bits;
      iVar4 = 0;
      while( true ) {
        while (uVar3 = iVar4 + uVar6, uVar3 < 8) {
          local_1 = local_1 ^ (byte)(uVar1 >> ((byte)uVar3 & 0x1f));
          piVar7 = piVar7 + 1;
          iVar4 = *piVar7;
        }
        if (0xf < uVar3) break;
        iVar4 = piVar7[1];
        bVar5 = bVar5 ^ (byte)(uVar1 >> ((byte)uVar3 - 8 & 0x1f));
        piVar7 = piVar7 + 1;
      }
      bVar2 = (byte)uVar6;
      (&g_crc16_table_hi)[uVar1] = (&g_crc16_table_hi)[uVar1] | (local_1 & 1) << (bVar2 & 0x1f);
      uVar6 = uVar6 + 1;
      (&g_crc16_table_lo)[uVar1] = (&g_crc16_table_lo)[uVar1] | (bVar5 & 1) << (bVar2 & 0x1f);
    } while (uVar6 < 8);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  uVar1 = 0;
  do {
    bVar5 = (byte)uVar1;
    uVar6 = 1;
    bVar2 = 2;
    do {
      bVar5 = bVar5 ^ bVar5 << 1 & bVar2;
      if (2 < uVar6) {
        bVar5 = bVar5 ^ bVar5 << 3 & bVar2;
      }
      uVar6 = uVar6 + 1;
      bVar2 = bVar2 << 1;
    } while (uVar6 < 8);
    (&g_crc16_byte_table)[uVar1] = bVar5;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  return;
}

