uint crc16_update(byte *data,int length,uint crc)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  byte *pbVar6;
  uint local_4;
  
  pbVar6 = data + length;
  bVar5 = (byte)(crc >> 8);
  uVar4 = crc >> 8;
  uVar3 = crc;
  for (; uVar2 = uVar4, data < pbVar6; data = data + 1) {
    local_4 = (uint)bVar5;
    crc = uVar3 & 0xff;
    pbVar1 = &g_crc16_table_hi + crc;
    crc = uVar2 & 0xff;
    bVar5 = (&g_crc16_byte_table)[(byte)(*data ^ *pbVar1 ^ (&g_crc16_table_lo)[local_4])];
    uVar4 = (uint)bVar5;
    uVar3 = uVar2;
  }
  return (uint)CONCAT11(bVar5,(char)crc);
}

