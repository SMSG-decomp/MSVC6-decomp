c1_u8 * __thiscall il_buffer_put_pch_reference(c1_il_buffer *buf,int *out_length)

{
  c1_u8 **ppcVar1;
  char cVar2;
  c1_u8 cVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  c1_u8 *pcVar8;
  c1_u8 *pcVar9;
  char *pcVar10;
  
  cVar3 = buf->ilstore_space;
  if ((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + 2) {
    iVar4 = il_buffer_grow(&buf->bytes,2);
    bVar5 = 0;
    if (iVar4 != 0) goto LAB_1048c283;
  }
  else {
LAB_1048c283:
    bVar5 = 1;
  }
  bVar5 = buf->open & bVar5;
  buf->open = bVar5;
  if (bVar5 != 0) {
    *(buf->bytes).cur = (-(cVar3 != '\x01') & 0xf7U) + 0x17;
    (buf->bytes).cur = (buf->bytes).cur + 1;
  }
  pcVar8 = (c1_u8 *)buf->ilstore_stream_name;
  uVar6 = 0xffffffff;
  pcVar9 = pcVar8;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar3 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar3 != '\0');
  uVar6 = ~uVar6;
  iVar4 = uVar6 + 1;
  if (iVar4 < 0) {
    bVar5 = 0;
  }
  else {
    if ((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + iVar4) {
      iVar4 = il_buffer_grow(&buf->bytes,iVar4);
      bVar5 = 0;
      if (iVar4 == 0) goto LAB_1048c2be;
    }
    bVar5 = 1;
  }
LAB_1048c2be:
  bVar5 = buf->open & bVar5;
  buf->open = bVar5;
  if (bVar5 != 0) {
    pcVar9 = (buf->bytes).cur;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    ppcVar1 = &(buf->bytes).cur;
    *ppcVar1 = *ppcVar1 + uVar6;
  }
  uVar6 = 0xffffffff;
  pcVar10 = buf->ilstore_stream_name;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar2 != '\0');
  *out_length = ~uVar6 + 1;
  return (buf->bytes).cur + -(~uVar6 + 1);
}

