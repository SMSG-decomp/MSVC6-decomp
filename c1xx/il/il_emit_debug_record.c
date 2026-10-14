void __cdecl il_emit_debug_record(uint kind)

{
  ushort uVar1;
  ushort *puVar2;
  c1_u8 *pcVar3;
  c1_u8 *pcVar4;
  c1_u8 *pcVar5;
  char cVar6;
  c1_u8 cVar7;
  int iVar8;
  c1_symbol *key;
  uint uVar9;
  byte bVar10;
  char *fmt;
  c1_u32 value;
  uint *args;
  
  fmt = (&g_debug_record_formats)[kind * 2];
  if ((fmt != (char *)0x0) && (cVar6 = *fmt, cVar6 != '\0')) {
    args = &kind;
    do {
      uVar9 = kind;
      value = g_cv_type_stream_size;
      fmt = fmt + 1;
      switch(cVar6) {
      case 'b':
        puVar2 = (ushort *)args[1];
        args = args + 1;
        uVar1 = *puVar2;
        cVar7 = il_buffer_reserve_ok(&g_il_db,uVar1 + 3);
        if (cVar7 != '\0') {
          il_buffer_put_compact_u16_unchecked(&g_il_db,uVar1);
          il_buffer_put_bytes(&g_il_db,(uint *)(puVar2 + 1),(uint)uVar1);
        }
        break;
      case 'f':
        iVar8 = il_buffer_reserve(&g_il_db.bytes,6);
        g_il_db.open = g_il_db.open & (byte)iVar8 & 1;
        if ((g_il_db.open != 0) && (iVar8 = il_buffer_put_byte7(&g_il_db,0), (char)iVar8 == '\0')) {
          *g_il_db.bytes.cur = 0x80;
          g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
          pcVar3 = g_il_db.bytes.cur + 1;
          pcVar4 = g_il_db.bytes.cur + 2;
          pcVar5 = g_il_db.bytes.cur + 3;
          g_il_db.bytes.cur[0] = '\0';
          *pcVar3 = '\0';
          *pcVar4 = '\0';
          *pcVar5 = '\0';
          g_il_db.bytes.cur = g_il_db.bytes.cur + 4;
        }
        break;
      case 'g':
        cVar7 = '\x01';
        goto LAB_1043f6be;
      case 'l':
        uVar1 = (ushort)args[1];
        args = args + 2;
        iVar8 = il_buffer_reserve(&g_il_db.bytes,uVar1 + 4);
        g_il_db.open = g_il_db.open & (byte)iVar8 & 1;
        if (g_il_db.open != 0) {
          il_buffer_put_compact_u16_unchecked(&g_il_db,uVar1);
          il_buffer_put_bytes(&g_il_db,(uint *)*args,(uint)uVar1);
        }
        break;
      case 'm':
        iVar8 = il_buffer_reserve(&g_il_db.bytes,2);
        g_il_db.open = g_il_db.open & (byte)iVar8 & 1;
        if (g_il_db.open != 0) {
          *g_il_db.bytes.cur = (c1_u8)uVar9;
          g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
        }
        break;
      case 'o':
        cVar7 = il_buffer_reserve_ok(&g_il_db,5);
        if (cVar7 != '\0') {
          if ((value & 0xffffff80) != 0) {
            il_emit_debug_record_fragment(value,(int *)args,fmt,kind);
            return;
          }
LAB_1043f657:
          *g_il_db.bytes.cur = (c1_u8)value;
          g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
        }
        break;
      case 'r':
        cVar7 = il_buffer_reserve_ok(&g_il_db,5);
        if ((cVar7 != '\0') && (iVar8 = il_buffer_put_byte7(&g_il_db,1), (char)iVar8 == '\0')) {
          *g_il_db.bytes.cur = 0x80;
          g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
          pcVar3 = g_il_db.bytes.cur + 1;
          pcVar4 = g_il_db.bytes.cur + 2;
          pcVar5 = g_il_db.bytes.cur + 3;
          g_il_db.bytes.cur[0] = '\x01';
          *pcVar3 = '\0';
          *pcVar4 = '\0';
          *pcVar5 = '\0';
          g_il_db.bytes.cur = g_il_db.bytes.cur + 4;
        }
        break;
      case 's':
        key = (c1_symbol *)args[1];
        args = args + 1;
        if ((key->flags4 & 0x40) != 0) {
          bVar10 = key->kind & 0x1f;
          if (bVar10 == 3) {
            key = sym_static_member_stand_in(key);
          }
          else if (bVar10 == 10) {
            key = sym_inline_instance_of(key);
          }
          else {
            key = (c1_symbol *)0x0;
          }
        }
        if (g_c9il_mode == '\0') {
          if ((key->key_ref & 0xfffffff8) == 0) {
            uVar9 = il_symbol_key_assign(key);
            goto LAB_1046487b;
          }
          uVar9 = key->key_ref >> 3;
        }
        else {
          uVar9 = key->entity & 0xffffff;
LAB_1046487b:
          if (g_c9il_mode != '\0') {
            il_buffer_put_id(&g_il_db,uVar9);
            break;
          }
        }
        cVar7 = il_buffer_reserve_ok(&g_il_db,3);
        if (cVar7 != '\0') {
          bVar10 = (byte)uVar9;
          if (0x3fff7f < uVar9) {
            value = (c1_u32)(byte)(bVar10 + 0x80);
            goto LAB_1043f657;
          }
          if (uVar9 < 0x4000) {
            *g_il_db.bytes.cur = bVar10 & 0x3f | 0x80;
            g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
            *g_il_db.bytes.cur = (c1_u8)(uVar9 >> 6);
            g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
          }
          else {
            *g_il_db.bytes.cur = bVar10 | 0xc0;
            g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
            *g_il_db.bytes.cur = (c1_u8)(uVar9 >> 6);
            g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
            *g_il_db.bytes.cur = (c1_u8)(uVar9 >> 0xe);
            g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
          }
        }
        break;
      case 't':
        cVar7 = il_buffer_reserve_ok(&g_il_db,1);
        value = uVar9;
        if (cVar7 != '\0') goto LAB_1043f657;
        break;
      case 'z':
        cVar7 = (c1_u8)args[1];
        args = args + 1;
LAB_1043f6be:
        il_buffer_put_byte(&g_il_db,cVar7);
      }
      cVar6 = *fmt;
    } while (cVar6 != '\0');
  }
  return;
}

