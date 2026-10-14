int __thiscall il_buffer_put_pch_reference(fe_il_buffer *buf,int *unused)

{
  PB *ppuVar1;
  char cVar2;
  uchar uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uchar *puVar8;
  uchar *puVar9;
  PB puVar10;
  char *pcVar11;
  
  uVar3 = buf->ilstore_space;
  if ((buf->bytes).pbStart + (buf->bytes).cbAlloc < (buf->bytes).pbEnd + 2) {
    iVar4 = il_buffer_grow(&buf->bytes,2);
    bVar5 = 0;
    if (iVar4 != 0) goto LAB_10644a4a;
  }
  else {
LAB_10644a4a:
    bVar5 = 1;
  }
  bVar5 = buf->open & bVar5;
  buf->open = bVar5;
  if (bVar5 != 0) {
    *(buf->bytes).pbEnd = (-(uVar3 != '\x01') & 0xf7U) + 0x17;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
  }
  puVar8 = (uchar *)buf->ilstore_stream_name;
  uVar6 = 0xffffffff;
  puVar9 = puVar8;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    uVar3 = *puVar9;
    puVar9 = puVar9 + 1;
  } while (uVar3 != '\0');
  uVar6 = ~uVar6;
  iVar4 = uVar6 + 1;
  if (iVar4 < 0) {
    bVar5 = 0;
  }
  else {
    if ((buf->bytes).pbStart + (buf->bytes).cbAlloc < (buf->bytes).pbEnd + iVar4) {
      iVar4 = il_buffer_grow(&buf->bytes,iVar4);
      bVar5 = 0;
      if (iVar4 == 0) goto LAB_10644a85;
    }
    bVar5 = 1;
  }
LAB_10644a85:
  bVar5 = buf->open & bVar5;
  buf->open = bVar5;
  if (bVar5 != 0) {
    puVar10 = (buf->bytes).pbEnd;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)puVar10 = *(undefined4 *)puVar8;
      puVar8 = puVar8 + 4;
      puVar10 = puVar10 + 4;
    }
    for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    ppuVar1 = &(buf->bytes).pbEnd;
    *ppuVar1 = *ppuVar1 + uVar6;
  }
  uVar6 = 0xffffffff;
  pcVar11 = buf->ilstore_stream_name;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar2 != '\0');
  *unused = ~uVar6 + 1;
  return (int)(buf->bytes).pbEnd - (~uVar6 + 1);
}

