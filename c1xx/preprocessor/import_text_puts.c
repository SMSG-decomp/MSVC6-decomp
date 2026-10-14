void __thiscall import_text_puts(c1_il_buffer *buf,char *s)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  c1_u8 *pcVar6;
  
  uVar3 = 0xffffffff;
  pcVar5 = s;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  if (((s != (char *)0x0) && (-1 < (int)uVar3)) &&
     (((buf->bytes).cur + uVar3 <= (buf->bytes).start + (buf->bytes).size ||
      (iVar2 = il_buffer_grow(&buf->bytes,uVar3), iVar2 != 0)))) {
    pcVar6 = (c1_u8 *)s;
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      pcVar6 = (buf->bytes).cur;
    }
    if ((buf->bytes).start != (c1_u8 *)0x0) {
      (buf->bytes).cur = (buf->bytes).cur + uVar3;
    }
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)s;
      s = s + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *s;
      s = s + 1;
      pcVar6 = pcVar6 + 1;
    }
    return;
  }
  diag_fatal_simple(0x3c);
}

