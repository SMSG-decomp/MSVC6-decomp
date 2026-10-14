c1_symbol * __cdecl decl_new_compiler_variable_hoisted(byte storage,c1_type *type)

{
  uint uVar1;
  uint uVar2;
  c1_u8 cVar3;
  void *pvVar4;
  c1_decl_record *pcVar5;
  c1_symbol *pcVar6;
  int iVar7;
  byte bVar8;
  c1_declarator *d;
  byte *pbVar9;
  c1_u8 *pcVar10;
  c1_type local_80;
  byte local_70 [24];
  c1_type *local_58;
  c1_decl_record local_4c;
  
  d = (c1_declarator *)g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x58;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (d == (c1_declarator *)0x0) {
    d = (c1_declarator *)0x0;
  }
  else {
    pvVar4 = name_new_S();
    d->name = pvVar4;
    *(c1_u8 *)((int)d + 0x28) = '\0';
    *(c1_u8 *)((int)d + 0x29) = '\0';
    *(c1_u8 *)((int)d + 0x2a) = '\0';
    *(c1_u8 *)((int)d + 0x2b) = '\0';
    *(c1_u8 *)((int)d + 0x30) = '\x01';
    *(c1_u8 *)((int)d + 0x4c) = '\0';
    *(c1_u8 *)((int)d + 0x4d) = '\0';
    *(c1_u8 *)((int)d + 0x4e) = '\0';
    *(c1_u8 *)((int)d + 0x4f) = '\0';
    pcVar5 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar5 == (c1_decl_record *)0x0) {
      *(c1_u8 *)((int)d + 4) = '\0';
      *(c1_u8 *)((int)d + 5) = '\0';
      *(c1_u8 *)((int)d + 6) = '\0';
      *(c1_u8 *)((int)d + 7) = '\0';
      *(int *)((int)d + 0x24) = g_token_position;
    }
    else {
      pcVar5 = decl_record_init_default(pcVar5,d->name,*(c1_overload_set **)((int)d + 0x28));
      *(c1_decl_record **)((int)d + 4) = pcVar5;
      *(int *)((int)d + 0x24) = g_token_position;
    }
  }
  cVar3 = g_block_depth;
  if ((type->flags & 0x20) != 0) {
    uVar1._0_2_ = type->code;
    uVar1._2_2_ = type->flags;
    local_80._0_4_ = uVar1 & 0xffdfffff;
    local_80.base = type->base;
    local_80.extra = type->extra;
    local_80.debug_index = type->debug_index;
    type_intern(&local_80);
  }
  if ((type->flags & 0x18) != 0) {
    uVar2._0_2_ = type->code;
    uVar2._2_2_ = type->flags;
    local_80._0_4_ = uVar2 & 0x18ffff;
    local_80.base = type->base;
    local_80.extra = type->extra;
    local_80.debug_index = type->debug_index;
    type_intern(&local_80);
  }
  if (storage != 3) {
    if ((((byte)g_compile_flags_c4 & 0x20) == 0) && (g_block_depth != '\0')) goto LAB_104738f1;
    storage = 3;
  }
  g_block_depth = '\0';
LAB_104738f1:
  d->flags54 = d->flags54 | 0x20;
  local_70[0] = local_70[0] ^ (local_70[0] ^ storage) & 7;
  bVar8 = local_70[0] & 7;
  pbVar9 = local_70;
  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
    pbVar9[0] = 0;
    pbVar9[1] = 0;
    pbVar9[2] = 0;
    pbVar9[3] = 0;
    pbVar9 = pbVar9 + 4;
  }
  local_58 = type;
  local_70[0] = local_70[0] ^ (local_70[0] ^ bVar8) & 7;
  decl_record_init(&local_4c,type,g_default_decl_specifiers);
  decl_finish_declarator(&local_4c);
  d->decl = &local_4c;
  pbVar9 = local_70;
  pcVar10 = d->spec;
  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pbVar9;
    pbVar9 = pbVar9 + 4;
    pcVar10 = pcVar10 + 4;
  }
  pcVar6 = decl_declare_and_check(d,local_70);
  g_block_depth = cVar3;
  return pcVar6;
}

