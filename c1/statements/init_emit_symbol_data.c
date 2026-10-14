void __cdecl init_emit_symbol_data(c1_symbol *key,c1_node *node,fe_il_buffer *buf)

{
  char cVar1;
  PB puVar2;
  c1_symbol *pcVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  char *pcVar7;
  
  if ((g_compile_flags_cc & 0x800) == 0) {
    pcVar7 = "mdox";
    cVar1 = 'm';
    do {
      pcVar7 = pcVar7 + 1;
      switch(cVar1) {
      case 'd':
        pcVar3 = key;
        if ((key->flags3 & 0x40) != 0) {
          pcVar3 = decl_lookup_file_scope_twin(key);
          pcVar3->flags3 = pcVar3->flags3 | 4;
          pcVar3 = decl_lookup_file_scope_twin(key);
        }
        if (g_c9il_mode == '\0') {
          if ((pcVar3->key_ref & 0xfffffff8) == 0) {
            uVar6 = il_symbol_key_assign(pcVar3);
            goto LAB_1061ec7b;
          }
          uVar6 = pcVar3->key_ref >> 3;
LAB_1063ab57:
          iVar4 = il_buffer_reserve(&buf->bytes,4);
          bVar5 = buf->open & (byte)iVar4 & 1;
          buf->open = bVar5;
          if (bVar5 != 0) {
            bVar5 = (byte)uVar6;
            if (uVar6 < 0x3fff80) {
              if (uVar6 < 0x4000) {
                *(buf->bytes).pbEnd = bVar5 & 0x3f | 0x80;
                puVar2 = (buf->bytes).pbEnd + 1;
                (buf->bytes).pbEnd = puVar2;
                *puVar2 = (uchar)(uVar6 >> 6);
                puVar2 = (buf->bytes).pbEnd + 1;
              }
              else {
                *(buf->bytes).pbEnd = bVar5 | 0xc0;
                puVar2 = (buf->bytes).pbEnd + 1;
                (buf->bytes).pbEnd = puVar2;
                *puVar2 = (uchar)(uVar6 >> 6);
                puVar2 = (buf->bytes).pbEnd + 1;
                (buf->bytes).pbEnd = puVar2;
                *puVar2 = (uchar)(uVar6 >> 0xe);
                puVar2 = (buf->bytes).pbEnd + 1;
              }
            }
            else {
              *(buf->bytes).pbEnd = bVar5 + 0x80;
              puVar2 = (buf->bytes).pbEnd + 1;
            }
LAB_1061ecb1:
            (buf->bytes).pbEnd = puVar2;
          }
        }
        else {
          uVar6 = pcVar3->entity & 0xffffff;
LAB_1061ec7b:
          if (g_c9il_mode == '\0') goto LAB_1063ab57;
          iVar4 = il_buffer_reserve(&buf->bytes,5);
          bVar5 = buf->open & (byte)iVar4 & 1;
          buf->open = bVar5;
          if (bVar5 != 0) {
            if ((int)uVar6 < 0x8000) {
              *(short *)(buf->bytes).pbEnd = (short)uVar6;
              puVar2 = (buf->bytes).pbEnd + 2;
            }
            else {
              *(uint *)(buf->bytes).pbEnd =
                   (uint)((uint3)(uVar6 >> 8) & 0xffffc0 | 0x40) << 9 | uVar6 & 0x7fff;
              puVar2 = (buf->bytes).pbEnd + 4;
            }
            goto LAB_1061ecb1;
          }
        }
        key->flags3 = key->flags3 | 4;
        key->flags4 = key->flags4 | 0x80;
        break;
      case 'm':
        if (((buf->bytes).pbStart + (buf->bytes).cbAlloc < (buf->bytes).pbEnd + 2) &&
           (iVar4 = il_buffer_grow(&buf->bytes,2), iVar4 == 0)) {
          bVar5 = 0;
        }
        else {
          bVar5 = 1;
        }
        bVar5 = buf->open & bVar5;
        buf->open = bVar5;
        if (bVar5 != 0) {
          *(buf->bytes).pbEnd = '\0';
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        break;
      case 'o':
        iVar4 = il_buffer_reserve(&buf->bytes,6);
        bVar5 = buf->open & (byte)iVar4 & 1;
        buf->open = bVar5;
        if (bVar5 != 0) {
          *(buf->bytes).pbEnd = '\0';
          (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
        }
        break;
      case 'x':
        init_emit_initializer(key,node,buf);
      }
      cVar1 = *pcVar7;
    } while (cVar1 != '\0');
  }
  return;
}

