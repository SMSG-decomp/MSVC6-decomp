void __cdecl init_emit_symbol_data(c1_symbol *key,c1_node *node,c1_il_buffer *buf)

{
  char cVar1;
  c1_u8 *pcVar2;
  void *pvVar3;
  c1_symbol *sym;
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
        sym = key;
        if ((key->flags4 & 0x40) != 0) {
          bVar5 = key->kind & 0x1f;
          if (bVar5 == 3) {
            pvVar3 = sym_static_member_stand_in(key);
          }
          else if (bVar5 == 10) {
            pvVar3 = sym_inline_instance_of(key);
          }
          else {
            pvVar3 = (void *)0x0;
          }
          *(byte *)((int)pvVar3 + 4) = *(byte *)((int)pvVar3 + 4) | 4;
          bVar5 = key->kind & 0x1f;
          if (bVar5 == 3) {
            sym = sym_static_member_stand_in(key);
          }
          else if (((key->flags4 & 0x40) == 0) || (bVar5 != 10)) {
            sym = (c1_symbol *)0x0;
          }
          else {
            sym = sym_inline_instance_of(key);
          }
        }
        if (g_c9il_mode == '\0') {
          if ((sym->key_ref & 0xfffffff8) == 0) {
            uVar6 = il_symbol_key_assign(sym);
            goto LAB_104404a4;
          }
          uVar6 = sym->key_ref >> 3;
LAB_1047ea50:
          iVar4 = il_buffer_reserve(&buf->bytes,4);
          bVar5 = buf->open & (byte)iVar4 & 1;
          buf->open = bVar5;
          if (bVar5 != 0) {
            bVar5 = (byte)uVar6;
            if (uVar6 < 0x3fff80) {
              if (uVar6 < 0x4000) {
                *(buf->bytes).cur = bVar5 & 0x3f | 0x80;
                pcVar2 = (buf->bytes).cur + 1;
                (buf->bytes).cur = pcVar2;
                *pcVar2 = (c1_u8)(uVar6 >> 6);
                pcVar2 = (buf->bytes).cur + 1;
              }
              else {
                *(buf->bytes).cur = bVar5 | 0xc0;
                pcVar2 = (buf->bytes).cur + 1;
                (buf->bytes).cur = pcVar2;
                *pcVar2 = (c1_u8)(uVar6 >> 6);
                pcVar2 = (buf->bytes).cur + 1;
                (buf->bytes).cur = pcVar2;
                *pcVar2 = (c1_u8)(uVar6 >> 0xe);
                pcVar2 = (buf->bytes).cur + 1;
              }
            }
            else {
              *(buf->bytes).cur = bVar5 + 0x80;
              pcVar2 = (buf->bytes).cur + 1;
            }
LAB_104404f1:
            (buf->bytes).cur = pcVar2;
          }
        }
        else {
          uVar6 = sym->entity & 0xffffff;
LAB_104404a4:
          if (g_c9il_mode == '\0') goto LAB_1047ea50;
          iVar4 = il_buffer_reserve(&buf->bytes,5);
          bVar5 = buf->open & (byte)iVar4 & 1;
          buf->open = bVar5;
          if (bVar5 != 0) {
            if ((int)uVar6 < 0x8000) {
              *(short *)(buf->bytes).cur = (short)uVar6;
              pcVar2 = (buf->bytes).cur + 2;
            }
            else {
              *(uint *)(buf->bytes).cur =
                   (uint)((uint3)(uVar6 >> 8) & 0xffffc0 | 0x40) << 9 | uVar6 & 0x7fff;
              pcVar2 = (buf->bytes).cur + 4;
            }
            goto LAB_104404f1;
          }
        }
        key->flags4 = key->flags4 | 4;
        key->flags5 = key->flags5 | 0x80;
        break;
      case 'm':
        if (((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + 2) &&
           (iVar4 = il_buffer_grow(&buf->bytes,2), iVar4 == 0)) {
          bVar5 = 0;
        }
        else {
          bVar5 = 1;
        }
        bVar5 = buf->open & bVar5;
        buf->open = bVar5;
        if (bVar5 != 0) {
          *(buf->bytes).cur = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 1;
        }
        break;
      case 'o':
        iVar4 = il_buffer_reserve(&buf->bytes,6);
        bVar5 = buf->open & (byte)iVar4 & 1;
        buf->open = bVar5;
        if (bVar5 != 0) {
          *(buf->bytes).cur = '\0';
          (buf->bytes).cur = (buf->bytes).cur + 1;
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

