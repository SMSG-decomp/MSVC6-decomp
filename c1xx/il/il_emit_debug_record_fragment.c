void __cdecl il_emit_debug_record_fragment(uint value,int *args,char *fmt,uint kind)

{
  char cVar1;
  ushort uVar2;
  ushort *puVar3;
  c1_u8 *pcVar4;
  c1_u8 *pcVar5;
  c1_u8 *pcVar6;
  c1_u8 cVar7;
  int iVar8;
  c1_symbol *key;
  uint id;
  byte bVar9;
  c1_u32 value_00;
  
  *g_il_db.bytes.cur = 0x80;
  g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
  *(uint *)g_il_db.bytes.cur = value;
  g_il_db.bytes.cur = g_il_db.bytes.cur + 4;
switchD_1043f592_caseD_63:
  value_00 = g_cv_type_stream_size;
  cVar1 = *fmt;
  if (cVar1 == '\0') {
    return;
  }
  fmt = fmt + 1;
  switch(cVar1) {
  case 'b':
    puVar3 = (ushort *)args[1];
    args = args + 1;
    uVar2 = *puVar3;
    cVar7 = il_buffer_reserve_ok(&g_il_db,uVar2 + 3);
    if (cVar7 != '\0') {
      il_buffer_put_compact_u16_unchecked(&g_il_db,uVar2);
      il_buffer_put_bytes(&g_il_db,(uint *)(puVar3 + 1),(uint)uVar2);
    }
  default:
    goto switchD_1043f592_caseD_63;
  case 'f':
    iVar8 = il_buffer_reserve(&g_il_db.bytes,6);
    g_il_db.open = g_il_db.open & (byte)iVar8 & 1;
    if ((g_il_db.open != 0) && (iVar8 = il_buffer_put_byte7(&g_il_db,0), (char)iVar8 == '\0')) {
      *g_il_db.bytes.cur = 0x80;
      g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
      pcVar4 = g_il_db.bytes.cur + 1;
      pcVar5 = g_il_db.bytes.cur + 2;
      pcVar6 = g_il_db.bytes.cur + 3;
      g_il_db.bytes.cur[0] = '\0';
      *pcVar4 = '\0';
      *pcVar5 = '\0';
      *pcVar6 = '\0';
      g_il_db.bytes.cur = g_il_db.bytes.cur + 4;
    }
    goto switchD_1043f592_caseD_63;
  case 'g':
    cVar7 = '\x01';
    goto LAB_1043f6be;
  case 'l':
    uVar2 = *(ushort *)(args + 1);
    args = args + 2;
    iVar8 = il_buffer_reserve(&g_il_db.bytes,uVar2 + 4);
    g_il_db.open = g_il_db.open & (byte)iVar8 & 1;
    if (g_il_db.open != 0) {
      il_buffer_put_compact_u16_unchecked(&g_il_db,uVar2);
      il_buffer_put_bytes(&g_il_db,(uint *)*args,(uint)uVar2);
    }
    goto switchD_1043f592_caseD_63;
  case 'm':
    iVar8 = il_buffer_reserve(&g_il_db.bytes,2);
    g_il_db.open = g_il_db.open & (byte)iVar8 & 1;
    if (g_il_db.open != 0) {
      *g_il_db.bytes.cur = (c1_u8)kind;
      g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
    }
    goto switchD_1043f592_caseD_63;
  case 'o':
    cVar7 = il_buffer_reserve_ok(&g_il_db,5);
    if (cVar7 == '\0') goto switchD_1043f592_caseD_63;
    if ((value_00 & 0xffffff80) != 0) {
      il_emit_debug_record_fragment(value_00,args,fmt,kind);
      return;
    }
    break;
  case 'r':
    cVar7 = il_buffer_reserve_ok(&g_il_db,5);
    if ((cVar7 != '\0') && (iVar8 = il_buffer_put_byte7(&g_il_db,1), (char)iVar8 == '\0')) {
      *g_il_db.bytes.cur = 0x80;
      g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
      pcVar4 = g_il_db.bytes.cur + 1;
      pcVar5 = g_il_db.bytes.cur + 2;
      pcVar6 = g_il_db.bytes.cur + 3;
      g_il_db.bytes.cur[0] = '\x01';
      *pcVar4 = '\0';
      *pcVar5 = '\0';
      *pcVar6 = '\0';
      g_il_db.bytes.cur = g_il_db.bytes.cur + 4;
    }
    goto switchD_1043f592_caseD_63;
  case 's':
    key = (c1_symbol *)args[1];
    args = args + 1;
    if ((key->flags4 & 0x40) != 0) {
      bVar9 = key->kind & 0x1f;
      if (bVar9 == 3) {
        key = sym_static_member_stand_in(key);
      }
      else if (bVar9 == 10) {
        key = sym_inline_instance_of(key);
      }
      else {
        key = (c1_symbol *)0x0;
      }
    }
    if (g_c9il_mode == '\0') {
      if ((key->key_ref & 0xfffffff8) == 0) {
        id = il_symbol_key_assign(key);
        goto LAB_1046487b;
      }
      id = key->key_ref >> 3;
    }
    else {
      id = key->entity & 0xffffff;
LAB_1046487b:
      if (g_c9il_mode != '\0') {
        il_buffer_put_id(&g_il_db,id);
        goto switchD_1043f592_caseD_63;
      }
    }
    cVar7 = il_buffer_reserve_ok(&g_il_db,3);
    if (cVar7 == '\0') goto switchD_1043f592_caseD_63;
    bVar9 = (byte)id;
    if (id < 0x3fff80) {
      if (id < 0x4000) {
        *g_il_db.bytes.cur = bVar9 & 0x3f | 0x80;
        g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
        *g_il_db.bytes.cur = (c1_u8)(id >> 6);
        g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
      }
      else {
        *g_il_db.bytes.cur = bVar9 | 0xc0;
        g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
        *g_il_db.bytes.cur = (c1_u8)(id >> 6);
        g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
        *g_il_db.bytes.cur = (c1_u8)(id >> 0xe);
        g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
      }
      goto switchD_1043f592_caseD_63;
    }
    value_00 = (c1_u32)(byte)(bVar9 + 0x80);
    break;
  case 't':
    cVar7 = il_buffer_reserve_ok(&g_il_db,1);
    value_00 = kind;
    if (cVar7 == '\0') goto switchD_1043f592_caseD_63;
    break;
  case 'z':
    cVar7 = (c1_u8)args[1];
    args = args + 1;
LAB_1043f6be:
    il_buffer_put_byte(&g_il_db,cVar7);
    goto switchD_1043f592_caseD_63;
  }
  *g_il_db.bytes.cur = (c1_u8)value_00;
  g_il_db.bytes.cur = g_il_db.bytes.cur + 1;
  goto switchD_1043f592_caseD_63;
}

