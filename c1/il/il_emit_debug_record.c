void __cdecl il_emit_debug_record(int kind,...)

{
  uint *puVar1;
  ushort value;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  char cVar5;
  byte bVar6;
  c1_u8 cVar7;
  int iVar8;
  c1_symbol *sym;
  uint uVar9;
  char *format;
  uchar uVar10;
  uint *args;
  
  format = g_debug_record_formats[kind].codes;
  if ((format != (char *)0x0) && (cVar5 = *format, cVar5 != '\0')) {
    args = (uint *)&kind;
    do {
      uVar9 = g_cv_type_stream_size;
      uVar10 = (uchar)kind;
      format = format + 1;
      switch(cVar5) {
      case 'b':
        puVar1 = args + 1;
        args = args + 1;
        il_buffer_put_counted_bytes(&g_il_db,*(ushort *)*puVar1,(ushort *)*puVar1 + 1);
        break;
      case 'f':
        iVar8 = il_buffer_reserve(&g_il_db.bytes,6);
        g_il_db.open = g_il_db.open & (byte)iVar8 & 1;
        if ((g_il_db.open != 0) && (iVar8 = il_buffer_put_byte7(&g_il_db,0), (char)iVar8 == '\0')) {
          *g_il_db.bytes.pbEnd = 0x80;
          g_il_db.bytes.pbEnd = g_il_db.bytes.pbEnd + 1;
          puVar2 = g_il_db.bytes.pbEnd + 1;
          puVar3 = g_il_db.bytes.pbEnd + 2;
          puVar4 = g_il_db.bytes.pbEnd + 3;
          g_il_db.bytes.pbEnd[0] = '\0';
          *puVar2 = '\0';
          *puVar3 = '\0';
          *puVar4 = '\0';
          g_il_db.bytes.pbEnd = g_il_db.bytes.pbEnd + 4;
        }
        break;
      case 'g':
        cVar7 = '\0';
        goto LAB_10624586;
      case 'l':
        value = (ushort)args[1];
        args = args + 2;
        iVar8 = il_buffer_reserve(&g_il_db.bytes,value + 4);
        g_il_db.open = g_il_db.open & (byte)iVar8 & 1;
        if (g_il_db.open != 0) {
          il_buffer_put_compact_u16_unchecked(&g_il_db,value);
          il_buffer_put_bytes(&g_il_db,(uint *)*args,(uint)value);
        }
        break;
      case 'm':
        iVar8 = il_buffer_reserve(&g_il_db.bytes,2);
        g_il_db.open = g_il_db.open & (byte)iVar8 & 1;
        bVar6 = g_il_db.open;
        goto joined_r0x10624541;
      case 'o':
        iVar8 = il_buffer_reserve(&g_il_db.bytes,6);
        g_il_db.open = g_il_db.open & (byte)iVar8 & 1;
        if ((g_il_db.open != 0) &&
           (iVar8 = il_buffer_put_byte7(&g_il_db,uVar9), (char)iVar8 == '\0')) {
          il_emit_debug_record_body(uVar9,args,format,kind);
          return;
        }
        break;
      case 'r':
        cVar7 = il_buffer_reserve_ok(&g_il_db,5);
        if (cVar7 != '\0') {
          *g_il_db.bytes.pbEnd = '\x01';
          g_il_db.bytes.pbEnd = g_il_db.bytes.pbEnd + 1;
        }
        break;
      case 's':
        sym = (c1_symbol *)args[1];
        args = args + 1;
        if ((sym->flags3 & 0x40) != 0) {
          sym = decl_lookup_file_scope_twin(sym);
        }
        if (g_c9il_mode == '\0') {
          if ((sym->key_ref & 0xfffffff8) == 0) {
            uVar9 = il_symbol_key_assign(sym);
            goto LAB_1062fc19;
          }
          uVar9 = sym->key_ref >> 3;
        }
        else {
          uVar9 = sym->entity & 0xffffff;
LAB_1062fc19:
          if (g_c9il_mode != '\0') {
            il_buffer_put_id(&g_il_db,uVar9);
            break;
          }
        }
        cVar7 = il_buffer_reserve_ok(&g_il_db,3);
        if (cVar7 == '\0') break;
        bVar6 = (byte)uVar9;
        if (uVar9 < 0x3fff80) {
          if (uVar9 < 0x4000) {
            *g_il_db.bytes.pbEnd = bVar6 & 0x3f | 0x80;
            g_il_db.bytes.pbEnd = g_il_db.bytes.pbEnd + 1;
            *g_il_db.bytes.pbEnd = (uchar)(uVar9 >> 6);
            g_il_db.bytes.pbEnd = g_il_db.bytes.pbEnd + 1;
          }
          else {
            *g_il_db.bytes.pbEnd = bVar6 | 0xc0;
            g_il_db.bytes.pbEnd = g_il_db.bytes.pbEnd + 1;
            *g_il_db.bytes.pbEnd = (uchar)(uVar9 >> 6);
            g_il_db.bytes.pbEnd = g_il_db.bytes.pbEnd + 1;
            *g_il_db.bytes.pbEnd = (uchar)(uVar9 >> 0xe);
            g_il_db.bytes.pbEnd = g_il_db.bytes.pbEnd + 1;
          }
          break;
        }
        uVar10 = bVar6 + 0x80;
        goto LAB_10624543;
      case 't':
        bVar6 = il_buffer_reserve_ok(&g_il_db,1);
joined_r0x10624541:
        if (bVar6 != 0) {
LAB_10624543:
          *g_il_db.bytes.pbEnd = uVar10;
          g_il_db.bytes.pbEnd = g_il_db.bytes.pbEnd + 1;
        }
        break;
      case 'z':
        cVar7 = (c1_u8)args[1];
        args = args + 1;
LAB_10624586:
        il_buffer_put_byte(&g_il_db,cVar7);
      }
      cVar5 = *format;
    } while (cVar5 != '\0');
  }
  return;
}

